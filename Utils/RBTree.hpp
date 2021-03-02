#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <cstddef>
#include <iostream>
#include "../Utils/util.hpp"
#include "RBTreeNode.hpp"
#include "RBTreeIterator.hpp"

namespace ft
{

	template <typename T, typename Compare, bool isMulti>
	class Tree
	{
	public :
		typedef T										value_type;
		typedef TreeNode<value_type>					node;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef value_type*								pointer;
		typedef const value_type*						const_pointer;
		typedef TreeIterator<value_type>				iterator;
		typedef TreeReverseIterator<value_type>			reverse_iterator;
		typedef TreeConstIterator<value_type>			const_iterator;
		typedef TreeConstReverseIterator<value_type>	const_reverse_iterator;
		typedef size_t									size_type;
		typedef Compare									key_compare;

	private :
		node*		_root;
		node*		_first;
		node*		_last;
		key_compare	_cmp;
		size_type	_size;

		void remove(node* x)
		{
			if (x == NULL)
				return ;
			remove(x->_left);
			remove(x->_right);
			if (x != this->_first && x != this->_last) {
				this->_size--;
				delete x;
			}
		}

		void rotateLeft(node* x)
		{
			node* y = x->_right;
			x->_right = y->_left; // set right as left grandson(left son of right son)
			if (y->_left != NULL)
				y->_left->_parent = x;
			if (y != NULL)
				y->_parent = x->_parent;
			if (x->_parent) { // make x child of y
				if (x == x->_parent->_left)
					x->_parent->_left = y;
				else
					x->_parent->_right = y;
			}
			else
				this->_root = y;
			y->_left = x;
			if (x != NULL) // set links(x is left y child)
				x->_parent = y;
		}

		void rotateRight(node* x)
		{
			node* y = x->_left;
			x->_left = y->_right;  // set right as right grandson(right son of left son)
			if (y->_right != NULL)
				y->_right->_parent = x;
			if (y != NULL)
				y->_parent = x->_parent;
			if (x->_parent) { // make x child of y
				if (x == x->_parent->_right)
					x->_parent->_right = y;
				else
					x->_parent->_left = y;
			}
			else
				this->_root = y;
			y->_right = x;
			if (x != NULL) // set links(x is right y child)
				x->_parent = y;
		}

		void insertFixup(node* x)
		{
			if (x == NULL)
				return ;
			while (x != this->_root && x->_parent->_color == RED) {
				node* parent = x->_parent;
				node* grandParent = parent->_parent;
				if (parent == grandParent->_left) {
					node* uncle = grandParent->_right;
					if (uncle != NULL && uncle != this->_first &&
						uncle != this->_last && uncle->_color == RED) {
						parent->_color = BLACK;
						uncle->_color = BLACK;
						grandParent->_color = RED;
						x = grandParent;
					}
					else {
						if (x == parent->_right) {
							x = parent;
							rotateLeft(x);
						}
						x->_parent->_color = BLACK;
						x->_parent->_parent->_color = RED;
						rotateRight(x->_parent->_parent);
					}
				}
				else if (parent == grandParent->_right) {
					node* uncle = grandParent->_left;
					if (uncle != NULL && uncle != this->_first &&
					    uncle != this->_last && uncle->_color == RED) {
						parent->_color = BLACK;
						uncle->_color = BLACK;
						grandParent->_color = RED;
						x = grandParent;
					}
					else {
						if (x == parent->_left) {
							x = parent;
							rotateRight(x);
						}
						x->_parent->_color = BLACK;
						x->_parent->_parent->_color = RED;
						rotateLeft(x->_parent->_parent);
					}
				}
			}
			this->_root->_color = BLACK;
		}








		void transplant(node* x, node* y)
		{
			if (x != NULL && x->_parent == NULL)
				this->_root = y;
			else if (x == x->_parent->_left)
				x->_parent->_left = y;
			else
				x->_parent->_right = y;
			if (y != NULL)
				y->_parent = x->_parent;
		}

		void eraseFixup(node* x)
		{
			if (x == NULL)
				return ;
			while (x != this->_root && x->_color == BLACK) {
				if (x == x->_parent->_left) {
					node* w = x->_parent->_right;
					if (w->_color == RED) {
						w->_color = BLACK;
						x->_parent->_color = RED;
						rotateLeft(x->_parent);
						w = x->_parent->_right;
					}
					if (w->_left->_color == BLACK && w->_right->_color == BLACK) {
						w->_color = RED;
						x = x->_parent;
					}
					else {
						if (w->_right->_color == BLACK) {
							w->_left->_color = BLACK;
							w->_color = RED;
							rotateRight(w);
							w = x->_parent->_right;
						}
						w->_color = x->_parent->_color;
						x->_parent->_color = BLACK;
						w->_right->_color = BLACK;
						rotateLeft(x->_parent);
						x = this->_root;
					}
				}
				else {
					node* w = x->_parent->_left;
					if (w->_color == RED) {
						w->_color = BLACK;
						x->_parent->_color = RED;
						rotateRight(x->_parent);
						w = x->_parent->_left;
					}
					if (w->_right->_color == BLACK && w->_left->_color == BLACK) {
						w->_color = RED;
						x = x->_parent;
					}
					else {
						if (w->_left->_color == BLACK) {
							w->_right->_color = BLACK;
							w->_color = RED;
							rotateLeft(w);
							w = x->_parent->_left;
						}
						w->_color = x->_parent->_color;
						x->_parent->_color = BLACK;
						w->_left->_color = BLACK;
						rotateRight(x->_parent);
						x = this->_root;
					}
				}
			}
			x->_color = BLACK;
		}









		void print(node* root, int deep)
		{
			if (root != NULL) {
				print(root->_right, deep + 1);
				if (root->_color == BLACK)
					std::cout << "\e[34m";
				else if (root->_color == RED)
					std::cout << "\e[33m";
				if (root != this->_last)
					for (int i = 0; i < deep; i++)
						std::cout << "    ";
				if (root != this->_first && root != this->_last)
					std::cout << root->_data << "\e[0m" << "\n";
				print(root->_left, deep + 1);
			}
			std::cout << "\e[0m";
		}

		void traversal(node* x) const
		{
			if (x == NULL)
				return ;
			traversal(x->_left);
			traversal(x->_right);
			std::string color = x->_color == RED ? "\e[33m" : "\e[34m";
			if (x != this->_first && x != this->_last)
				std::cout << "node: " << color << "[" << x->_data << "]" << "\e[0m" << "    addr: " << x << ", left: "
					<< x->_left << ", right: " << x->_right << ", parent: " << x->_parent << std::endl;
			else
				std::cout << "found limit node, with addr: " << x << std::endl;
		}

	public :
		explicit Tree(const key_compare& cmp = key_compare())
			: _root(NULL), _cmp(cmp), _size(0)
		{
			this->_first = new node(0, NULL, NULL, NULL, BLACK);
			this->_last = new node(0, NULL, NULL, NULL, BLACK);
			this->_first->_parent = this->_last;
			this->_last->_parent = this->_first;
		}

		Tree(const Tree& tree)
			: _root(NULL), _cmp(tree._cmp), _size(0)
		{
			this->_first = new node(0, NULL, NULL, NULL, BLACK);
			this->_last = new node(0, NULL, NULL, NULL, BLACK);
			this->_first->_parent = this->_last;
			this->_last->_parent = this->_first;
			insert(tree.begin(), tree.end());
		}

		Tree& operator= (const Tree& tree)
		{
			clear();
			delete this->_first;
			delete this->_last;
			this->_first = new node(0, NULL, NULL, NULL, BLACK);
			this->_last = new node(0, NULL, NULL, NULL, BLACK);
			this->_first->_parent = this->_last;
			this->_last->_parent = this->_first;
			this->_root = NULL;
			this->_cmp = tree._cmp;
			this->_size = 0;
			insert(tree.begin(), tree.end());
			return (*this);
		}

		virtual ~Tree()
		{
			clear();
			delete this->_first;
			delete this->_last;
		}

		iterator begin()
		{ return (iterator(this->_first->_parent)); }

		iterator end()
		{ return (iterator(this->_last)); }

		const_iterator begin() const
		{ return (const_iterator(this->_first->_parent)); }

		const_iterator end() const
		{ return (const_iterator(this->_last)); }

		reverse_iterator rbegin()
		{ return (reverse_iterator(this->_last->_parent)); }

		reverse_iterator rend()
		{ return (reverse_iterator(this->_first)); }

		const_reverse_iterator rbegin() const
		{ return (const_reverse_iterator(this->_last->_parent)); }

		const_reverse_iterator rend() const
		{ return (const_reverse_iterator(this->_first)); }

		void clear()
		{
			remove(this->_root);
			this->_first->_parent = this->_last;
			this->_last->_parent = this->_first;
		}

		size_type size() const
		{ return (this->_size); }

		std::pair<iterator, bool> insert(const value_type& val)
		{
			if (this->_size == 0) {
				this->_root = new node(val, NULL, this->_first, this->_last, BLACK);
				this->_first->_parent = this->_root;
				this->_last->_parent = this->_root;
				this->_size++;
				return (std::pair<iterator, bool>(iterator(this->_root), true));
			}

			node* x = this->_root;
			while (x != NULL) {
				if (this->_cmp(val, x->_data)) {
					if (x->_left != NULL && x->_left != this->_first)
						x = x->_left;
					else {
						node* item = new node(val, x, x->_left, NULL, RED);
						if (x->_left != NULL)
							x->_left->_parent = item;
						x->_left = item;
						this->_size++;
						insertFixup(item);
						return (std::pair<iterator, bool>(iterator(item), true));
					}
				}
				else if (this->_cmp(x->_data, val) || (isMulti && !this->_cmp(x->_data, val))) {
					if (x->_right != NULL && x->_right != this->_last)
						x = x->_right;
					else {
						node* item = new node(val, x, NULL, x->_right, RED);
						if (x->_right != NULL)
							x->_right->_parent = item;
						x->_right = item;
						this->_size++;
						insertFixup(item);
						return (std::pair<iterator, bool>(iterator(item), true));
					}
				}
				else
					return (std::pair<iterator, bool>(iterator(x), false));
			}
			return (std::pair<iterator, bool>(iterator(x), false));
		}

		template <typename InputIterator>
		void insert(InputIterator first, InputIterator last,
					typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0)
		{
			while (first != last) {
				insert(*first);
				first++;
			}
		}





		void erase(node* x)
		{
			if (x == NULL || x == this->_first || x == this->_last)
				return ;
			node* y = x;
			node* z;
			bool color = y->_color;

			if (x->_left == NULL) {
				z = x->_right;
				transplant(x, x->_right);
			}
			else if (x->_right == NULL) {
				z = x->_left;
				transplant(x, x->_left);
			}
			else {
				y = x->_right;
				while (y->_left != NULL)
					y = y->_left;
				color = y->_color;
				z = y->_right;
				if (y->_parent == x)
					z->_parent = x;
				else {
					transplant(y, y->_right);
					y->_right = x->_right;
					y->_right->_parent = y;
				}
				transplant(x, y);
				y->_left = x->_left;
				y->_left->_parent = y;
				y->_color = x->_color;
			}

			if (color == BLACK)
				eraseFixup(z);

			delete x;
			this->_size--;
		}






		node* find(const value_type& data) const
		{
			node* item = this->_root;
			while (item != NULL && item != this->_first && item != this->_last) {
				if (this->_cmp(data, item->_data))
					item = item->_left;
				else if (this->_cmp(item->_data, data))
					item = item->_right;
				else
					return (item);
			}
			return (this->_last);
		}

		size_type count(const value_type& data) const
		{
			size_type result = 0;
			for (iterator it = begin(); it != end(); it++) {
				if (!this->_cmp(data, *it) && !this->_cmp(*it, data))
					result++;
			}
			return (result);
		}

		void swap(Tree& tree)
		{
			ft::swap(this->_root, tree._root);
			ft::swap(this->_first, tree._first);
			ft::swap(this->_last, tree._last);
			ft::swap(this->_cmp, tree._cmp);
			ft::swap(this->_size, tree._size);
		}

		void traversal() const
		{
			std::cout << "tree with size: " << this->_size << std::endl;
			traversal(this->_root);
		}

		void print()
		{ print(this->_root, 20); }
	};

}

#endif
