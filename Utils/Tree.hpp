#ifndef TREE_HPP
#define TREE_HPP

#include <cstddef>
#include <iostream>
#include "Utils/TreeNode.hpp"


namespace ft
{

	template <typename T, typename Compare, bool isUnique>
	class Tree
	{
	public :
		typedef T value_type;
		typedef TreeNode<value_type> node;
		typedef value_type& reference;
		typedef const value_type* const_reference;
		typedef value_type* pointer;
		typedef const value_type* const_pointer;
		// iterators ...
		typedef Compare key_compare;
		typedef size_t size_type;

	private :
		node* _root;
		// first, last
		key_compare _compare;
		size_type _size;

	public :
		explicit Tree(const key_compare& compare = key_compare())
			: _root(NULL), _compare(compare), _size(0)
		{ _root = new node(); }

		void rotateLeft(node *x) {

			/**************************
			 *  rotate node x to left *
			 **************************/

			node *y = x->_right;

			/* establish x->right link */
			x->_right = y->_left;
			if (y->_left != NULL) y->_left->_parent = x;

			/* establish y->parent link */
			if (y != NULL) y->_parent = x->_parent;
			if (x->_parent) {
				if (x == x->_parent->_left)
					x->_parent->_left = y;
				else
					x->_parent->_right = y;
			} else {
				this->_root = y;
			}

			/* link x and y */
			y->_left = x;
			if (x != NULL) x->_parent = y;
		}

		void rotateRight(node *x) {

			/****************************
			 *  rotate node x to right  *
			 ****************************/

			node *y = x->_left;

			/* establish x->left link */
			x->_left = y->_right;
			if (y->_right != NULL) y->_right->_parent = x;

			/* establish y->parent link */
			if (y != NULL) y->_parent = x->_parent;
			if (x->_parent) {
				if (x == x->_parent->_right)
					x->_parent->_right = y;
				else
					x->_parent->_left = y;
			} else {
				this->_root = y;
			}

			/* link x and y */
			y->_right = x;
			if (x != NULL) x->_parent = y;
		}

		void insertFixup(node* x) {

			while (x != this->_root && x->_parent->_color == BLUE) {

				if (x->_parent == x->_parent->_parent->_left) {
					node* y = x->_parent->_parent->_right;
					if (y->_color == BLUE) {
						x->_parent->_color = YELLOW;
						y->_color = YELLOW;
						x->_parent->_parent->_color = BLUE;
						x = x->_parent->_parent;
					}
					else {
						if (x == x->_parent->_right) {
							x = x->_parent;
							rotateLeft(x);
						}

						x->_parent->_color = YELLOW;
						x->_parent->_parent->_color = BLUE;
						rotateRight(x->_parent->_parent);
					}
				}
				else {
					node* y = x->_parent->_parent->_left;
					if (y->_color == BLUE) {
						x->_parent->_color = YELLOW;
						y->_color = YELLOW;
						x->_parent->_parent->_color = BLUE;
						x = x->_parent->_parent;
					}
					else {
						if (x == x->_parent->_left) {
							x = x->_parent;
							rotateRight(x);
						}
						x->_parent->_color = YELLOW;
						x->_parent->_parent->_color = BLUE;
						rotateLeft(x->_parent->_parent);
					}
				}
			}
			this->_root->_color = YELLOW;
		}

		node* insert(const value_type& data)
		{
			node* current = this->_root;
			node* parent = NULL;
			node* x;

			while (current != NULL) {
				if (data == current->_data)
					return (current);
				parent = current;
				if (data < current->_data)
					current = current->_left;
				else
					current = current->_right;
			}

			x = new node(data);
			x->_parent = parent;

			if (parent != NULL) {
				if (data < parent->_data)
					parent->_left = x;
				else
					parent->_right = x;
			}
			else
				this->_root = x;
			insertFixup(x);
			this->_size++;
			return (x);
		}

		void traversal(node* root)
		{
			if (root == NULL)
				return ;
			traversal(root->_left);
			std::cout << root->_data << " : " << (root->_color == YELLOW) << std::endl;
			traversal(root->_right);
		}

		void traversal()
		{
			std::cout << "tree with size: " << this->_size << std::endl;
			traversal(this->_root);
		}
	};

}

#endif
