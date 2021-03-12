#ifndef DEQUEITERATOR_HPP
#define DEQUEITERATOR_HPP

#include <cstddef>

namespace ft
{

	template <typename T>
	class DequeIterator
	{
	public :
		template <typename K>
		friend class DequeConstIterator;

		typedef T				value_type;
		typedef value_type&		reference;
		typedef value_type*		pointer;
		typedef size_t			size_type;

	private :
		pointer _ptr;

	public :
		explicit DequeIterator(pointer ptr = NULL)
			: _ptr(ptr)
		{ }

		DequeIterator(const DequeIterator& it)
			: _ptr(it._ptr)
		{ }

		DequeIterator& operator= (const DequeIterator& it)
		{
			this->_ptr = it._ptr;
			return (*this);
		}

		virtual ~DequeIterator()
		{ }

		bool operator== (const DequeIterator& it) const
		{ return (this->_ptr == it._ptr); }

		bool operator!= (const DequeIterator& it) const
		{ return (!(*this == it)); }

		reference operator* ()
		{ return (*this->_ptr); }

		pointer operator-> ()
		{ return (this->_ptr); }

		DequeIterator& operator++ ()
		{
			this->_ptr++;
			return (*this);
		}

		DequeIterator operator++ (int)
		{
			DequeIterator it(*this);
			this->_ptr++;
			return (it);
		}

		DequeIterator& operator-- ()
		{
			this->_ptr--;
			return (*this);
		}

		DequeIterator operator-- (int)
		{
			DequeIterator it(*this);
			this->_ptr--;
			return (it);
		}

		DequeIterator operator+ (size_type n) const
		{ return (DequeIterator(this->_ptr + n));}

		DequeIterator operator- (size_type n) const
		{ return (DequeIterator(this->_ptr - n));}

		bool operator< (const DequeIterator& it) const
		{ return (this->_ptr < it._ptr); }

		bool operator> (const DequeIterator& it) const
		{ return (it < *this); }

		bool operator<= (const DequeIterator& it) const
		{ return (!(it < *this)); }

		bool operator>= (const DequeIterator& it) const
		{ return (!(*this < it)); }

		DequeIterator& operator+= (size_type n)
		{
			this->_ptr += n;
			return (*this);
		}

		DequeIterator& operator-= (size_type n)
		{
			this->_ptr -= n;
			return (*this);
		}

		reference operator[] (size_type n)
		{ return (*(this->_ptr + n)); }
	};

	template <typename T>
	class DequeReverseIterator
	{
	public :
		template <typename K>
		friend class DequeConstReverseIterator;

		typedef T				value_type;
		typedef value_type&		reference;
		typedef value_type*		pointer;
		typedef size_t			size_type;

	private :
		pointer _ptr;

	public :
		explicit DequeReverseIterator(pointer ptr = NULL)
			: _ptr(ptr)
		{ }

		DequeReverseIterator(const DequeReverseIterator& it)
			: _ptr(it._ptr)
		{ }

		DequeReverseIterator& operator= (const DequeReverseIterator& it)
		{
			this->_ptr = it._ptr;
			return (*this);
		}

		virtual ~DequeReverseIterator()
		{ }

		bool operator== (const DequeReverseIterator& it) const
		{ return (this->_ptr == it._ptr); }

		bool operator!= (const DequeReverseIterator& it) const
		{ return (!(*this == it)); }

		reference operator* ()
		{ return (*this->_ptr); }

		pointer operator-> ()
		{ return (this->_ptr); }

		DequeReverseIterator& operator++ ()
		{
			this->_ptr--;
			return (*this);
		}

		DequeReverseIterator operator++ (int)
		{
			DequeReverseIterator it(*this);
			this->_ptr--;
			return (it);
		}

		DequeReverseIterator& operator-- ()
		{
			this->_ptr++;
			return (*this);
		}

		DequeReverseIterator operator-- (int)
		{
			DequeReverseIterator it(*this);
			this->_ptr++;
			return (it);
		}

		DequeReverseIterator operator+ (size_type n) const
		{ return (DequeReverseIterator(this->_ptr - n));}

		DequeReverseIterator operator- (size_type n) const
		{ return (DequeReverseIterator(this->_ptr + n));}

		bool operator< (const DequeReverseIterator& it) const
		{ return (this->_ptr < it._ptr); }

		bool operator> (const DequeReverseIterator& it) const
		{ return (it < *this); }

		bool operator<= (const DequeReverseIterator& it) const
		{ return (!(it < *this)); }

		bool operator>= (const DequeReverseIterator& it) const
		{ return (!(*this < it)); }

		DequeReverseIterator& operator+= (size_type n)
		{
			this->_ptr -= n;
			return (*this);
		}

		DequeReverseIterator& operator-= (size_type n)
		{
			this->_ptr += n;
			return (*this);
		}

		reference operator[] (size_type n)
		{ return (*(this->_ptr + n)); }
	};

	template <typename T>
	class DequeConstIterator : public DequeIterator<T>
	{
	public :
		typedef T					value_type;
		typedef size_t				size_type;
		typedef value_type*			pointer;
		typedef const value_type&	const_reference;

		explicit DequeConstIterator(pointer ptr = NULL)
		{ this->_ptr = ptr; }

		DequeConstIterator(const DequeIterator<T>& it)
		{ this->_ptr = it._ptr; }

		DequeConstIterator& operator= (const DequeIterator<T>& it)
		{
			this->_ptr = it._ptr;
			return (*this);
		}

		virtual ~DequeConstIterator()
		{ }

		const_reference operator* () const
		{ return (*(this->_ptr)); }

		const_reference operator-> () const
		{ return (this->_ptr); }

		const_reference operator[] (size_type index) const
		{ return (*(this->_ptr + index)); }
	};

	template <typename T>
	class DequeConstReverseIterator : public DequeReverseIterator<T>
	{
	public :
		typedef T					value_type;
		typedef size_t				size_type;
		typedef value_type*			pointer;
		typedef const value_type&	const_reference;

		explicit DequeConstReverseIterator(pointer ptr = NULL)
		{ this->_ptr = ptr; }

		DequeConstReverseIterator(const DequeReverseIterator<T>& it)
		{ this->_ptr = it._ptr; }

		DequeConstReverseIterator& operator= (const DequeReverseIterator<T>& it)
		{
			this->_ptr = it._ptr;
			return (*this);
		}

		virtual ~DequeConstReverseIterator()
		{ }

		const_reference operator* () const
		{ return (*(this->_ptr)); }

		const_reference operator-> () const
		{ return (this->_ptr); }

		const_reference operator[] (size_type index) const
		{ return (*(this->_ptr + index)); }
	};

}


#endif
