#ifndef RBTREEITERATOR_HPP
#define RBTREEITERATOR_HPP

#include <cstddef>
#include "RBTreeNode.hpp"

namespace ft
{

	template <typename T>
	class TreeIterator
	{
	public :
		template <typename K, typename Compare, bool isMulti>
		friend class Tree;

		template <typename K>
		friend class TreeConstIterator;

		typedef T						value_type;
		typedef TreeNode<value_type>	node;
		typedef value_type&				reference;
		typedef value_type*				pointer;

	protected :
		node* _ptr;

		void prev()
		{
			node* item;

			if (this->_ptr == NULL)
				return ;
			if (this->_ptr->_left == NULL) {
				item = this->_ptr;
				while (item->_parent != NULL && item == item->_parent->_left)
					item = item->_parent;
				item = item->_parent;
			}
			else {
				item = this->_ptr->_left;
				while (item->_right != NULL)
					item = item->_right;
			}
			this->_ptr = item;
		}

		void next()
		{
			node* item;

			if (this->_ptr == NULL)
				return ;
			if (this->_ptr->_right == NULL) {
				item = this->_ptr;
				while (item->_parent != NULL && item == item->_parent->_right)
					item = item->_parent;
				item = item->_parent;
			}
			else {
				item = this->_ptr->_right;
				while (item->_left != NULL)
					item = item->_left;
			}
			this->_ptr = item;
		}

	public :
		explicit TreeIterator(node* ptr = NULL)
			: _ptr(ptr)
		{ }

		TreeIterator(const TreeIterator& it)
			: _ptr(it._ptr)
		{ }

		TreeIterator& operator= (const TreeIterator& it)
		{
			this->_ptr = it._ptr;
			return (*this);
		}

		virtual ~TreeIterator()
		{ }

		bool operator== (const TreeIterator& it) const
		{ return (this->_ptr == it._ptr); }

		bool operator!= (const TreeIterator& it) const
		{ return (!(*this == it)); }

		reference operator* ()
		{ return (this->_ptr->_data); }

		pointer operator-> ()
		{ return (&(this->_ptr->_data)); }

		TreeIterator& operator++ ()
		{
			next();
			return (*this);
		}

		TreeIterator operator++ (int)
		{
			TreeIterator it(*this);
			next();
			return (it);
		}

		TreeIterator& operator-- ()
		{
			prev();
			return (*this);
		}

		TreeIterator operator-- (int)
		{
			TreeIterator it(*this);
			prev();
			return (it);
		}
	};

	template <typename T>
	class TreeReverseIterator
	{
	public :
		template <typename K, typename Compare, bool isMulti>
		friend class Tree;

		template <typename K>
		friend class TreeConstReverseIterator;

		typedef T						value_type;
		typedef TreeNode<value_type>	node;
		typedef value_type&				reference;
		typedef value_type*				pointer;

	protected :
		node* _ptr;

		void prev()
		{
			node* item;

			if (this->_ptr == NULL)
				return ;
			if (this->_ptr->_right == NULL) {
				item = this->_ptr;
				while (item->_parent != NULL && item == item->_parent->_right)
					item = item->_parent;
				item = item->_parent;
			}
			else {
				item = this->_ptr->_right;
				while (item->_left != NULL)
					item = item->_left;
			}
			this->_ptr = item;
		}

		void next()
		{
			node* item;

			if (this->_ptr == NULL)
				return ;
			if (this->_ptr->_left == NULL) {
				item = this->_ptr;
				while (item->_parent != NULL && item == item->_parent->_left)
					item = item->_parent;
				item = item->_parent;
			}
			else {
				item = this->_ptr->_left;
				while (item->_right != NULL)
					item = item->_right;
			}
			this->_ptr = item;
		}

	public :
		explicit TreeReverseIterator(node* ptr = NULL)
			: _ptr(ptr)
		{ }

		TreeReverseIterator(const TreeReverseIterator& it)
			: _ptr(it._ptr)
		{ }

		TreeReverseIterator& operator= (const TreeReverseIterator& it)
		{
			this->_ptr = it._ptr;
			return (*this);
		}

		virtual ~TreeReverseIterator()
		{ }

		bool operator== (const TreeReverseIterator& it) const
		{ return (this->_ptr == it._ptr); }

		bool operator!= (const TreeReverseIterator& it) const
		{ return (!(*this == it)); }

		reference operator* ()
		{ return (this->_ptr->_data); }

		pointer operator-> ()
		{ return (&(this->_ptr->_data)); }

		TreeReverseIterator& operator++ ()
		{
			next();
			return (*this);
		}

		TreeReverseIterator operator++ (int)
		{
			TreeReverseIterator it(*this);
			next();
			return (it);
		}

		TreeReverseIterator& operator-- ()
		{
			prev();
			return (*this);
		}

		TreeReverseIterator operator-- (int)
		{
			TreeReverseIterator it(*this);
			prev();
			return (it);
		}
	};

	template <typename T>
	class TreeConstIterator : public TreeIterator<T>
	{
	public :
		template <typename K, typename Compare, bool isMulti>
		friend class Tree;

		typedef T						value_type;
		typedef TreeNode<value_type>	node;
		typedef const value_type&		const_reference;
		typedef const value_type*		const_pointer;

		explicit TreeConstIterator(node* ptr = NULL)
		{ this->_ptr = ptr; }

		TreeConstIterator(const TreeIterator<T>& it)
		{ this->_ptr = it._ptr; }

		TreeConstIterator& operator= (const TreeIterator<T>& it)
		{
			this->_ptr = it._ptr;
			return (*this);
		}

		~TreeConstIterator()
		{ }

		const_reference operator* () const
		{ return (this->_ptr->_data); }

		const_pointer operator-> () const
		{ return (&(this->_ptr->_data)); }
	};

	template <typename T>
	class TreeConstReverseIterator : public TreeReverseIterator<T>
	{
	public :
		template <typename K, typename Compare, bool isMulti>
		friend class Tree;

		typedef T						value_type;
		typedef TreeNode<value_type>	node;
		typedef const value_type&		const_reference;
		typedef const value_type*		const_pointer;

		explicit TreeConstReverseIterator(node* ptr = NULL)
		{ this->_ptr = ptr; }

		TreeConstReverseIterator(const TreeReverseIterator<T>& it)
		{ this->_ptr = it._ptr; }

		TreeConstReverseIterator& operator= (const TreeReverseIterator<T>& it)
		{
			this->_ptr = it._ptr;
			return (*this);
		}

		~TreeConstReverseIterator()
		{ }

		const_reference operator* () const
		{ return (this->_ptr->_data); }

		const_pointer operator-> () const
		{ return (&(this->_ptr->_data)); }
	};

}

#endif
