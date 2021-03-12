#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <memory>
#include <cstddef>
#include <limits>
#include <stdexcept>
#include "util.hpp"
#include "DequeIterator.hpp"

#include <iostream>

namespace ft
{

	template <typename T, typename Alloc = std::allocator<T> >
	class deque
	{
	public :
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef DequeIterator<value_type>					iterator;
		typedef DequeReverseIterator<value_type>			reverse_iterator;
		typedef DequeConstIterator<value_type>				const_iterator;
		typedef DequeConstReverseIterator<value_type>		const_reverse_iterator;
		typedef ptrdiff_t									difference_type;
		typedef size_t										size_type;

	private :
		pointer			_data;
		size_type       _size;
		allocator_type	_alloc;

		void reallocateData(size_type n, size_type m)
		{
			if (m)
				this->_alloc.deallocate(this->_data, m);
			this->_size = n;
			this->_data = this->_alloc.allocate(this->_size);
		}

		size_type iteratorPos(iterator i)
		{
			if (i == iterator(NULL))
				return (0);
			size_type pos = 0;
			iterator it = begin();
			while (it != end()) {
				if (it == i)
					return (pos);
				pos++;
				it++;
			}
			return (pos);
		}

	public :
		explicit deque(const allocator_type& alloc = allocator_type())
			: _data(NULL), _size(0), _alloc(alloc)
		{ }

		explicit deque(size_type n, const value_type& val = value_type(),
				       const allocator_type& alloc = allocator_type())
			: _data(NULL), _size(0), _alloc(alloc)
		{ assign(n, val); }

		template <class InputIterator>
		deque(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			  typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0)
			: _data(NULL), _size(0), _alloc(alloc)
		{ assign(first, last); }

		deque(const deque& x)
			: _data(NULL), _size(0), _alloc(x._alloc)
		{ assign(x.begin(), x.end()); }

		deque &operator=(const deque &x)
		{
			assign(x.begin(), x.end());
			return (*this);
		}

		~deque()
		{
			clear();
			this->_alloc.deallocate(this->_data, this->_size);
		}

		iterator begin()
		{ return (iterator(this->_data)); }

		const_iterator begin() const
		{ return (const_iterator(this->_data)); }

		iterator end()
		{ return (iterator(this->_data + this->_size)); }

		const_iterator end() const
		{ return (const_iterator(this->_data + this->_size)); }

		reverse_iterator rbegin()
		{ return (reverse_iterator(this->_data + this->_size - 1)); }

		const_reverse_iterator rbegin() const
		{ return (const_reverse_iterator(this->_data + this->_size - 1)); }

		reverse_iterator rend()
		{ return (reverse_iterator(this->_data - 1)); }

		const_reverse_iterator rend() const
		{ return (const_reverse_iterator(this->_data - 1)); }

		size_type size() const
		{ return (this->_size); }

		size_type max_size() const
		{ return (std::numeric_limits<size_type>::max() / sizeof(value_type)); }

		void resize(size_type n, value_type val = value_type())
		{
			if (n <= this->_size) {
				for (size_type i = n; i < this->_size; i++)
					this->_alloc.destroy(this->_data + i);
			}
			else {
				if (n > this->_size) {
					value_type* oldData = new value_type[this->_size];
					for (size_type i = 0; i < this->_size; i++)
						oldData[i] = this->_data[i];
					size_type oldSize = this->_size;
					clear();
					reallocateData(n, oldSize);
					for (size_type i = 0; i < oldSize; i++)
						this->_alloc.construct(this->_data + i, oldData[i]);
					this->_size = oldSize;
					delete[] oldData;
				}
				for (size_type i = this->_size; i < n; i++)
					this->_alloc.construct(this->_data + i, val);
			}
			this->_size = n;
		}

		bool empty() const
		{ return (!this->_size); }

		reference operator[] (size_type n)
		{ return (this->_data[n]); }

		const_reference operator[] (size_type n) const
		{ return (this->_data[n]); }

		reference at(size_type n)
		{
			if (n > this->_size - 1)
				throw std::out_of_range("deque");
			return (this->_data[n]);
		}

		const_reference at(size_type n) const
		{
			if (n > this->_size - 1)
				throw std::out_of_range("deque");
			return (this->_data[n]);
		}

		reference front()
		{ return (this->_data[0]); }

		const_reference front() const
		{ return (this->_data[0]); }

		reference back()
		{ return (this->_data[this->_size - 1]); }

		const_reference back() const
		{ return (this->_data[this->_size - 1]); }

		template<typename InputIterator>
		void assign(InputIterator first, InputIterator last,
					typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0)
		{
			size_type oldSize = this->_size;
			clear();
			size_type n = ft::distance(first, last);
			if (n > this->_size)
				reallocateData(n, oldSize);
			this->_size = n;
			n = 0;
			while (first != last) {
				this->_alloc.construct(this->_data + n, *first);
				n++;
				first++;
			}
		}

		void assign(size_type n, const value_type &val)
		{
			size_type oldSize = this->_size;
			clear();
			if (n > this->_size)
				reallocateData(n, oldSize);
			this->_size = n;
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.construct(this->_data + i, val);
		}

		void push_back(const value_type& val)
		{
			value_type* oldData = new value_type[this->_size];
			for (size_type i = 0; i < this->_size; i++)
				oldData[i] = this->_data[i];
			size_type oldSize = this->_size;
			clear();
			reallocateData(oldSize + 1, oldSize);
			for (size_type i = 0; i < oldSize; i++)
				this->_alloc.construct(this->_data + i, oldData[i]);
			this->_alloc.construct(this->_data + oldSize, val);
			this->_size = oldSize + 1;
			delete[] oldData;
		}

		void push_front(const value_type& val)
		{
			value_type* oldData = new value_type[this->_size];
			for (size_type i = 0; i < this->_size; i++)
				oldData[i] = this->_data[i];
			size_type oldSize = this->_size;
			clear();
			reallocateData(oldSize + 1, oldSize);
			this->_alloc.construct(this->_data, val);
			for (size_type i = 1; i < oldSize + 1; i++)
				this->_alloc.construct(this->_data + i, oldData[i - 1]);
			this->_size = oldSize + 1;
			delete[] oldData;
		}

		void pop_back()
		{
			if (!this->_size)
				return ;
			this->_alloc.destroy(this->_data + this->_size - 1);
			this->_size--;
		}

		void pop_front()
		{
			if (!this->_size)
				return ;
			value_type* oldData = new value_type[this->_size - 1];
			for (size_type i = 1; i < this->_size; i++)
				oldData[i - 1] = this->_data[i];
			size_type oldSize = this->_size;
			clear();
			reallocateData(oldSize - 1, oldSize);
			for (size_type i = 0; i < oldSize - 1; i++)
				this->_alloc.construct(this->_data + i, oldData[i]);
			this->_size = oldSize - 1;
			delete[] oldData;
		}

		iterator insert(iterator position, const value_type &val)
		{
			size_type pos = iteratorPos(position);
			value_type* oldData = new value_type[this->_size];
			for (size_type i = 0; i < this->_size; i++)
				oldData[i] = this->_data[i];
			size_type oldSize = this->_size;
			clear();
			reallocateData(oldSize + 1, oldSize);
			for (size_type i = 0; i < pos; i++)
				this->_alloc.construct(this->_data + i, oldData[i]);
			this->_alloc.construct(this->_data + pos, val);
			for (size_type i = pos; i < oldSize; i++)
				this->_alloc.construct(this->_data + i + 1, oldData[i]);
			this->_size = oldSize + 1;
			delete[] oldData;
			return (iterator(this->_data + pos));
		}

		void insert(iterator position, size_type n, const value_type &val)
		{
			size_type pos = iteratorPos(position);
			value_type* oldData = new value_type[this->_size];
			for (size_type i = 0; i < this->_size; i++)
				oldData[i] = this->_data[i];
			size_type oldSize = this->_size;
			clear();
			reallocateData(oldSize + n, oldSize);
			for (size_type i = 0; i < pos; i++)
				this->_alloc.construct(this->_data + i, oldData[i]);
			for (size_type i = 0; i < n; i++)
				this->_alloc.construct(this->_data + pos + i, val);
			for (size_type i = pos + n; i < oldSize + n; i++)
				this->_alloc.construct(this->_data + i, oldData[i - n]);
			this->_size = oldSize + n;
			delete[] oldData;
		}

		template<typename InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last,
					typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0)
		{
			size_type pos = iteratorPos(position);
			size_type n = ft::distance(first, last);
			value_type* oldData = new value_type[this->_size];
			for (size_type i = 0; i < this->_size; i++)
				oldData[i] = this->_data[i];
			size_type oldSize = this->_size;
			clear();
			reallocateData(oldSize + n, oldSize);
			for (size_type i = 0; i < pos; i++)
				this->_alloc.construct(this->_data + i, oldData[i]);
			for (size_type i = 0; i < n; i++) {
				this->_alloc.construct(this->_data + pos + i, *first);
				first++;
			}
			for (size_type i = pos + n; i < oldSize + n; i++)
				this->_alloc.construct(this->_data + i, oldData[i - n]);
			this->_size = oldSize + n;
			delete[] oldData;
		}

		iterator erase(iterator position)
		{
			size_type pos = iteratorPos(position);
			if (pos == this->_size)
				return (end());
			value_type* oldData = new value_type[this->_size];
			for (size_type i = 0; i < this->_size; i++)
				oldData[i] = this->_data[i];
			size_type oldSize = this->_size;
			clear();
			reallocateData(oldSize - 1, oldSize);
			for (size_type i = 0; i < pos; i++)
				this->_alloc.construct(this->_data + i, oldData[i]);
			for (size_type i = pos + 1; i < oldSize; i++)
				this->_alloc.construct(this->_data + i - 1, oldData[i]);
			this->_size = oldSize - 1;
			return (iterator(this->_data + pos));
		}

		iterator erase(iterator first, iterator last)
		{
			size_type pos = iteratorPos(first);
			size_type n = ft::distance(first, last);
			if (pos == this->_size)
				return (end());
			value_type* oldData = new value_type[this->_size];
			for (size_type i = 0; i < this->_size; i++)
				oldData[i] = this->_data[i];
			size_type oldSize = this->_size;
			clear();
			reallocateData(oldSize - n, oldSize);
			for (size_type i = 0; i < pos; i++)
				this->_alloc.construct(this->_data + i, oldData[i]);
			for (size_type i = pos + n; i < oldSize; i++)
				this->_alloc.construct(this->_data + i - n, oldData[i]);
			this->_size = oldSize - n;
			return (iterator(this->_data + pos));
		}

		void swap(deque &x)
		{
			ft::swap(this->_data, x._data);
			ft::swap(this->_size, x._size);
		}

		void clear()
		{
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.destroy(this->_data + i);
			this->_size = 0;
		}
	};

	template <typename T, typename Alloc>
	bool operator== (const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		for (size_t i = 0; i < lhs.size(); i++) {
			if (lhs[i] != rhs[i])
				return (false);
		}
		return (true);
	}

	template <typename T, typename Alloc>
	bool operator!= (const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
	{ return (!(lhs == rhs)); }

	template <typename T, typename Alloc>
	bool operator<  (const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
	{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

	template <typename T, typename Alloc>
	bool operator<= (const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
	{ return (!(rhs < lhs)); }

	template <typename T, typename Alloc>
	bool operator>  (const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
	{ return (rhs < lhs); }

	template <typename T, typename Alloc>
	bool operator>= (const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
	{ return (!(lhs < rhs)); }

	template<typename T, typename Alloc>
	void swap(deque<T, Alloc> &x, deque<T, Alloc> &y)
	{ x.swap(y); }

}

#endif
