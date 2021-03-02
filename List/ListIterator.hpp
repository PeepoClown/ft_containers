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

		typedef T						value_type;
		typedef value_type*				pointer;
		typedef value_type&				reference;
		typedef ListNode<value_type>	node;

	protected :
		node*	_ptr;

	public :
		explicit ListIterator(node* ptr = NULL)
			: _ptr(ptr)
		{ }

		ListIterator(const ListIterator& it)
			: _ptr(it._ptr)
		{ }

		ListIterator& operator= (const ListIterator& it)
		{
			this->_ptr = it._ptr;
			return (*this);
		}

		virtual ~ListIterator()
		{ }

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

		typedef T						value_type;
		typedef value_type*				pointer;
		typedef value_type&				reference;
		typedef ListNode<value_type>	node;

	protected :
		node*	_ptr;

	public :
		explicit ListReverseIterator(node* ptr = NULL)
			: _ptr(ptr)
		{ }

		ListReverseIterator(const ListReverseIterator& it)
			: _ptr(it._ptr)
		{ }

		ListReverseIterator& operator= (const ListReverseIterator& it)
		{
			this->_ptr = it._ptr;
			return (*this);
		}

		virtual ~ListReverseIterator()
		{ }

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

		typedef T						value_type;
		typedef const value_type*		const_pointer;
		typedef const value_type&		const_reference;
		typedef ListNode<value_type>	node;

		explicit ListConstIterator(node* ptr = NULL)
		{ this->_ptr = ptr; }

		ListConstIterator(const ListConstIterator& it)
		{ this->_ptr = it._ptr; }

		ListConstIterator& operator= (const ListConstIterator& it)
		{
			this->_ptr = it._ptr;
			return (*this);
		}

		~ListConstIterator()
		{ }

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

		typedef T						value_type;
		typedef const value_type*		const_pointer;
		typedef const value_type&		const_reference;
		typedef ListNode<value_type>	node;

		explicit ListConstReverseIterator(node* ptr = NULL)
		{ this->_ptr = ptr; }

		ListConstReverseIterator(const ListConstReverseIterator& it)
		{ this->_ptr = it._ptr; }

		ListConstReverseIterator& operator= (const ListConstReverseIterator& it)
		{
			this->_ptr = it._ptr;
			return (*this);
		}

		~ListConstReverseIterator()
		{ }

		const_reference operator* () const
		{ return (this->_ptr->_data); }

		const_pointer operator-> () const
		{ return (&(this->_ptr->_data)); }
	};

}

#endif
