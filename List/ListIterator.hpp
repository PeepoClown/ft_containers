#ifndef LISTITERATOR_HPP
#define LISTITERATOR_HPP

#include <cstddef>
#include "List/ListNode.hpp"

namespace ft
{

	template <typename T>
	class ListIterator
	{
	public :
		template <typename K, typename Alloc>
		friend class list;

		typedef T* pointer;
		typedef T& reference;
		typedef ListNode<T> node;

	private :
		node*	_ptr;

	public :
		explicit ListIterator(node* ptr = NULL)
			: _ptr(ptr)
		{ }

		ListIterator(const ListIterator& it)
			: _ptr(it._ptr)
		{ }

		virtual ~ListIterator()
		{ }

		ListIterator& operator= (const ListIterator& it)
		{
			this->_ptr = it._ptr;
			return (*this);
		}

		bool operator== (const ListIterator& it) const
		{ return (this->_ptr == it._ptr); }

		bool operator!= (const ListIterator& it) const
		{ return (!(*this == it)); }

		reference operator* ()
		{ return (this->_ptr->_data); }

		pointer operator-> ()
		{ return (&(this->_ptr->_data)); }

		ListIterator& operator++ ()
		{
			this->_ptr = this->_ptr->_next;
			return (*this);
		}

		ListIterator operator++ (int)
		{
			ListIterator(*this);
			this->_ptr = this->_ptr->_next;
			return (*this);
		}

		ListIterator& operator-- ()
		{
			this->_ptr = this->_ptr->_prev;
			return (*this);
		}

		ListIterator operator-- (int)
		{
			ListIterator(*this);
			this->_ptr = this->_ptr->_prev;
			return (*this);
		}
	};

	template <typename T>
	class ListReverseIterator
	{
	public :
		template <typename K, typename Alloc>
		friend class list;

		typedef T* pointer;
		typedef T& reference;
		typedef ListNode<T> node;

	private :
		node*	_ptr;

	public :
		explicit ListReverseIterator(node* ptr = NULL)
			: _ptr(ptr)
		{ }

		ListReverseIterator(const ListReverseIterator& it)
			: _ptr(it._ptr)
		{ }

		virtual ~ListReverseIterator()
		{ }

		ListReverseIterator& operator= (const ListReverseIterator& it)
		{
			this->_ptr = it._ptr;
			return (*this);
		}

		bool operator== (const ListReverseIterator& it) const
		{ return (this->_ptr == it._ptr); }

		bool operator!= (const ListReverseIterator& it) const
		{ return (!(*this == it)); }

		reference operator* ()
		{ return (this->_ptr->_data); }

		pointer operator-> ()
		{ return (&(this->_ptr->_data)); }

		ListReverseIterator& operator++ ()
		{
			this->_ptr = this->_ptr->_prev;
			return (*this);
		}

		ListReverseIterator operator++ (int)
		{
			ListReverseIterator(*this);
			this->_ptr = this->_ptr->_prev;
			return (*this);
		}

		ListReverseIterator& operator-- ()
		{
			this->_ptr = this->_ptr->_next;
			return (*this);
		}

		ListReverseIterator operator-- (int)
		{
			ListReverseIterator(*this);
			this->_ptr = this->_ptr->_next;
			return (*this);
		}
	};

	template <typename T>
	class ListConstIterator : public ListIterator<T>
	{
	public :
		template <typename K, typename Alloc>
		friend class list;

		typedef const T* const_pointer;
		typedef const T& const_reference;
		typedef ListNode<T> node;

	private :
		node*	_ptr;

	public :
		explicit ListConstIterator(node* ptr = NULL)
			: _ptr(ptr)
		{ }

		ListConstIterator(const ListConstIterator& it)
			: _ptr(it._ptr)
		{ }

		virtual ~ListConstIterator()
		{ }

		ListConstIterator& operator= (const ListConstIterator& it)
		{
			this->_ptr = it._ptr;
			return (*this);
		}

		const_reference operator* () const
		{ return (this->_ptr->_data); }

		const_pointer operator-> () const
		{ return (&(this->_ptr->_data)); }
	};

	template <typename T>
	class ListConstReverseIterator : public ListReverseIterator<T>
	{
	public :
		template <typename K, typename Alloc>
		friend class list;

		typedef const T* const_pointer;
		typedef const T& const_reference;
		typedef ListNode<T> node;

	private :
		node*	_ptr;

	public :
		explicit ListConstReverseIterator(node* ptr = NULL)
			: _ptr(ptr)
		{ }

		ListConstReverseIterator(const ListConstReverseIterator& it)
			: _ptr(it._ptr)
		{ }

		virtual ~ListConstReverseIterator()
		{ }

		ListConstReverseIterator& operator= (const ListConstReverseIterator& it)
		{
			this->_ptr = it._ptr;
			return (*this);
		}

		const_reference operator* () const
		{ return (this->_ptr->_data); }

		const_pointer operator-> () const
		{ return (&(this->_ptr->_data)); }
	};

}

#endif
