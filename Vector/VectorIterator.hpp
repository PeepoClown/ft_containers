#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP

#include <cstddef>

namespace ft
{
	template <typename T>
	class VectorIterator
	{
	public :
		typedef T*		pointer;
		typedef T&		reference;
		typedef size_t	size_type;

	protected :
		pointer _ptr;

	public :
		explicit VectorIterator(pointer ptr = NULL)
			: _ptr(ptr) { }

		VectorIterator(const VectorIterator& it)
			: _ptr(it._ptr) { }

		virtual ~VectorIterator() { }

		VectorIterator& operator= (const VectorIterator& it)
		{
			this->_ptr = it._ptr;
			return (*this);
		}

		bool operator== (const VectorIterator& it) const
		{ return (this->_ptr == it._ptr); }

		bool operator!= (const VectorIterator& it) const
		{ return (!(*this == it)); }

		reference operator* ()
		{ return (*this->_ptr); }

		pointer operator-> ()
		{ return (this->_ptr); }

		VectorIterator& operator++ ()
		{
			this->_ptr++;
			return (*this);
		}

		VectorIterator operator++ (int)
		{
			VectorIterator it(*this);
			this->_ptr++;
			return (it);
		}

		VectorIterator& operator-- ()
		{
			this->_ptr--;
			return (*this);
		}

		VectorIterator operator-- (int)
		{
			VectorIterator it(*this);
			this->_ptr--;
			return (it);
		}

		VectorIterator operator+ (size_type n) const
		{ return (VectorIterator(this->_ptr + n));}

		VectorIterator operator- (size_type n) const
		{ return (VectorIterator(this->_ptr - n));}

		bool operator< (const VectorIterator& it) const
		{ return (this->_ptr < it._ptr); }

		bool operator> (const VectorIterator& it) const
		{ return (it < *this); }

		bool operator<= (const VectorIterator& it) const
		{ return (!(it < *this)); }

		bool operator>= (const VectorIterator& it) const
		{ return (!(*this < it)); }

		VectorIterator& operator+= (size_type n)
		{
			this->_ptr += n;
			return (*this);
		}

		VectorIterator& operator-= (size_type n)
		{
			this->_ptr -= n;
			return (*this);
		}

		reference operator[] (size_type n)
		{ return (*(this->_ptr + n)); }

	};
}

#endif
