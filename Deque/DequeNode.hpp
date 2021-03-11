#ifndef DEQUENODE_HPP
#define DEQUENODE_HPP

#include <cstddef>

namespace ft
{

	template <typename T, typename Alloc>
	class DequeNode
	{
	public :
		typedef T                                   value_type;
		typedef Alloc                               allocator_type;
		typedef typename allocator_type::reference  reference;
		typedef typename allocator_type::pointer    pointer;
		typedef size_t                              size_type;

	private :
		pointer                 _data;
		size_type               _size;
		allocator_type          _alloc;
		static const size_type  _nodeSize = 8;

	public :
		explicit DequeNode(const allocator_type& alloc = allocator_type())
			: _data(NULL), _size(0), _alloc(alloc)
		{ this->_data = this->_alloc.allocate(this->_nodeSize); }

		DequeNode(const DequeNode& x)
			: _data(NULL), _size(x._size), _alloc(x._alloc)
		{
			this->_data = this->_alloc.allocate(this->_nodeSize);
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.construct(this->_data + i, x._data[i]);
		}

		DequeNode& operator= (const DequeNode& x)
		{
			clear();
			if (this->_data != NULL)
				this->_alloc.deallocate(this->_data, this->_nodeSize);
			this->_size = x._size;
			this->_data = this->_alloc.allocate(this->_nodeSize);
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.construct(this->_data + i, x._data[i]);
			return (*this);
		}

		~DequeNode()
		{
			clear();
			if (this->_data != NULL)
				this->_alloc.deallocate(this->_data, this->_nodeSize);
		}

		void clear()
		{
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.destroy(this->_data + i);
			this->_size = 0;
		}

	    size_type size() const
		{ return (this->_size); }

		bool empty() const
		{ return (!this->_size); }

		bool isFull() const
		{ return (this->_size >= this->_nodeSize); }

		reference front()
		{ return (this->_data[0]); }

		reference back()
		{ return (this->_data[this->_size - 1]); }
		                                    
		reference operator[] (size_type n)
		{ return (this->_data[n]); }

		void push(const value_type& val)
		{
			if (isFull())
				return ;
			this->_alloc.construct(this->_data + this->_size, val);
			this->_size++;
		}

		void pop()
		{
			if (empty())
				return ;
			this->_alloc.destroy(this->_data + this->_size - 1);
			this->_size--;
		}

		void reverse()
		{
			for (size_type i = 0; i < this->_size / 2; i++) {
				value_type tmpDest = this->_data[this->_size - 1 - i];
				value_type tmpSrc = this->_data[i];
				this->_alloc.destroy(this->_data + this->_size - 1 - i);
				this->_alloc.construct(this->_data + this->_size - 1 - i, tmpSrc);
				this->_alloc.destroy(this->_data + i);
				this->_alloc.construct(this->_data + i, tmpDest);
			}
		}
	};

}

#endif
