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

	template <typename T>
	class VectorReverseIterator
	{
	public :
		typedef T*		pointer;
		typedef T&		reference;
		typedef size_t	size_type;

	protected :
		pointer _ptr;

	public :
		explicit VectorReverseIterator(pointer ptr = NULL)
				: _ptr(ptr) { }

		VectorReverseIterator(const VectorReverseIterator& it)
				: _ptr(it._ptr) { }

		virtual ~VectorReverseIterator() { }

		VectorReverseIterator& operator= (const VectorReverseIterator& it)
		{
			this->_ptr = it._ptr;
			return (*this);
		}

		bool operator== (const VectorReverseIterator& it) const
		{ return (this->_ptr == it._ptr); }

		bool operator!= (const VectorReverseIterator& it) const
		{ return (!(*this == it)); }

		reference operator* ()
		{ return (*this->_ptr); }

		pointer operator-> ()
		{ return (this->_ptr); }

		VectorReverseIterator& operator++ ()
		{
			this->_ptr--;
			return (*this);
		}

		VectorReverseIterator operator++ (int)
		{
			VectorReverseIterator it(*this);
			this->_ptr--;
			return (it);
		}

		VectorReverseIterator& operator-- ()
		{
			this->_ptr++;
			return (*this);
		}

		VectorReverseIterator operator-- (int)
		{
			VectorReverseIterator it(*this);
			this->_ptr++;
			return (it);
		}

		VectorReverseIterator operator+ (size_type n) const
		{ return (VectorReverseIterator(this->_ptr - n));}

		VectorReverseIterator operator- (size_type n) const
		{ return (VectorReverseIterator(this->_ptr + n));}

		bool operator< (const VectorReverseIterator& it) const
		{ return (this->_ptr < it._ptr); }

		bool operator> (const VectorReverseIterator& it) const
		{ return (it < *this); }

		bool operator<= (const VectorReverseIterator& it) const
		{ return (!(it < *this)); }

		bool operator>= (const VectorReverseIterator& it) const
		{ return (!(*this < it)); }

		VectorReverseIterator& operator+= (size_type n)
		{
			this->_ptr -= n;
			return (*this);
		}

		VectorReverseIterator& operator-= (size_type n)
		{
			this->_ptr += n;
			return (*this);
		}

		reference operator[] (size_type n)
		{ return (*(this->_ptr + n)); }
	};

	template <typename T>
	class VectorConstIterator : public VectorIterator<T>
	{
	public :
		typedef size_t		size_type;
		typedef T*			pointer;
		typedef const T&	const_reference;

	public :
		explicit VectorConstIterator(pointer ptr = NULL)
		{ this->_ptr = ptr; }

		VectorConstIterator(const VectorConstIterator& it)
		{ this->_ptr = it._ptr; }

		virtual ~VectorConstIterator()
		{ }

		VectorConstIterator& operator= (const VectorConstIterator& it)
		{
			this->_ptr = it._ptr;
			return (*this);
		}

		const_reference operator* () const
		{ return (*(this->_ptr)); }
		const_reference operator-> () const
		{ return (this->_ptr); }
		const_reference operator[] (size_type index) const
		{ return (*(this->_ptr + index)); }
	};

	template <typename T>
	class VectorConstReverseIterator : public VectorReverseIterator<T>
	{
	public :
		typedef size_t		size_type;
		typedef T*			pointer;
		typedef const T&	const_reference;

	public :
		explicit VectorConstReverseIterator(pointer ptr = NULL)
		{ this->_ptr = ptr; }

		VectorConstReverseIterator(const VectorConstReverseIterator& it)
		{ this->_ptr = it._ptr; }

		virtual ~VectorConstReverseIterator()
		{ }

		VectorConstReverseIterator& operator= (const VectorConstReverseIterator& it)
		{
			this->_ptr = it._ptr;
			return (*this);
		}

		const_reference operator* () const
		{ return (*(this->_ptr)); }
		const_reference operator-> () const
		{ return (this->_ptr); }
		const_reference operator[] (size_type index) const
		{ return (*(this->_ptr + index)); }
	};
}

#endif
