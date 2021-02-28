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
		const static node _nullLeaf = node();

	public :
		explicit Tree(const key_compare& compare = key_compare())
			: _root(NULL), _compare(compare), _size(0)
		{ _root = &this->_nullLeaf; }

		void rotateLeft(node* x)
		{
			node* y = x->_right;
			x->_right = y->_left;
			if (y->_left != &this->_nullLeaf)
				y->_left->_parent = x;

			if (y != &this->_nullLeaf)
				y->_parent = x->_parent;
			if (x->_parent) {
				if (x == x->_parent->_left)
					x->_parent->_left = y;
				else
					x->_parent->_right = y;
			}
			else
				this->_root = y;

			y->_left = x;
			if (x != &this->_nullLeaf)
				x->_parent = y;
		}

		void rotateRight(node* x)
		{
			node* y = x->_left;

			x->_left = y->_right;
			if (y->_right != &this->_nullLeaf)
				y->_right->_parent = x;

			if (y != &this->_nullLeaf)
				y->_parent = x->_parent;
			if (x->_parent) {
				if (x == x->_parent->_right)
					x->_parent->_right = y;
				else
					x->_parent->_left = y;
			}
			else
				this->_root = y;

			y->_right = x;
			if (x != &this->_nullLeaf)
				x->_parent = y;
		}

		void insertFixup(node* x)
		{
			while (x != this->_root && x->_parent->_color == YELLOW) {
				if (x->_parent == x->_parent->_parent->_left) {
					node* y = x->_parent->_parent->_right;
					if (y->_color == YELLOW) {
						x->parent->color = BLUE;
						y->color = BLUE;
						x->parent->parent->color = YELLOW;
						x = x->parent->parent;
					}
					else {

						/* uncle is BLACK */
						if (x == x->parent->right) {
							/* make x a left child */
							x = x->parent;
							rotateLeft(x);
						}

						/* recolor and rotate */
						x->parent->color = BLUE;
						x->parent->parent->color = YELLOW;
						rotateRight(x->parent->parent);
					}
				} else {

					/* mirror image of above code */
					Node *y = x->parent->parent->left;
					if (y->color == YELLOW) {

						/* uncle is RED */
						x->parent->color = BLUE;
						y->color = BLUE;
						x->parent->parent->color = YELLOW;
						x = x->parent->parent;
					} else {

						/* uncle is BLACK */
						if (x == x->parent->left) {
							x = x->parent;
							rotateRight(x);
						}
						x->parent->color = BLUE;
						x->parent->parent->color = YELLOW;
						rotateLeft(x->parent->parent);
					}
				}
			}
			root->color = BLUE;
		}

		Node *insertNode(T data) {
			Node *current, *parent, *x;

			/***********************************************
			 *  allocate node for data and insert in tree  *
			 ***********************************************/

			/* find where node belongs */
			current = root;
			parent = 0;
			while (current != NIL) {
				if (compEQ(data, current->data)) return (current);
				parent = current;
				current = compLT(data, current->data) ?
						  current->left : current->right;
			}

			/* setup new node */
			if ((x = (Node*)malloc (sizeof(*x))) == 0) {
				printf ("insufficient memory (insertNode)\n");
				exit(1);
			}
			x->data = data;
			x->parent = parent;
			x->left = NIL;
			x->right = NIL;
			x->color = YELLOW;

			/* insert node in tree */
			if(parent) {
				if(compLT(data, parent->data))
					parent->left = x;
				else
					parent->right = x;
			} else {
				root = x;
			}

			insertFixup(x);
			return(x);
		}

//		void deleteFixup(Node *x) {
//
//			/*************************************
//			 *  maintain Red-Black tree balance  *
//			 *  after deleting node x            *
//			 *************************************/
//
//			while (x != root && x->color == BLACK) {
//				if (x == x->parent->left) {
//					Node *w = x->parent->right;
//					if (w->color == RED) {
//						w->color = BLACK;
//						x->parent->color = RED;
//						rotateLeft (x->parent);
//						w = x->parent->right;
//					}
//					if (w->left->color == BLACK && w->right->color == BLACK) {
//						w->color = RED;
//						x = x->parent;
//					} else {
//						if (w->right->color == BLACK) {
//							w->left->color = BLACK;
//							w->color = RED;
//							rotateRight (w);
//							w = x->parent->right;
//						}
//						w->color = x->parent->color;
//						x->parent->color = BLACK;
//						w->right->color = BLACK;
//						rotateLeft (x->parent);
//						x = root;
//					}
//				} else {
//					Node *w = x->parent->left;
//					if (w->color == RED) {
//						w->color = BLACK;
//						x->parent->color = RED;
//						rotateRight (x->parent);
//						w = x->parent->left;
//					}
//					if (w->right->color == BLACK && w->left->color == BLACK) {
//						w->color = RED;
//						x = x->parent;
//					} else {
//						if (w->left->color == BLACK) {
//							w->right->color = BLACK;
//							w->color = RED;
//							rotateLeft (w);
//							w = x->parent->left;
//						}
//						w->color = x->parent->color;
//						x->parent->color = BLACK;
//						w->left->color = BLACK;
//						rotateRight (x->parent);
//						x = root;
//					}
//				}
//			}
//			x->color = BLACK;
//		}
//
//		void deleteNode(Node *z) {
//			Node *x, *y;
//
//			/*****************************
//			 *  delete node z from tree  *
//			 *****************************/
//
//			if (!z || z == NIL) return;
//
//
//			if (z->left == NIL || z->right == NIL) {
//				/* y has a NIL node as a child */
//				y = z;
//			} else {
//				/* find tree successor with a NIL node as a child */
//				y = z->right;
//				while (y->left != NIL) y = y->left;
//			}
//
//			/* x is y's only child */
//			if (y->left != NIL)
//				x = y->left;
//			else
//				x = y->right;
//
//			/* remove y from the parent chain */
//			x->parent = y->parent;
//			if (y->parent)
//				if (y == y->parent->left)
//					y->parent->left = x;
//				else
//					y->parent->right = x;
//			else
//				root = x;
//
//			if (y != z) z->data = y->data;
//
//
//			if (y->color == BLACK)
//				deleteFixup (x);
//
//			free (y);
//		}
//
//		Node *findNode(T data) {
//
//			/*******************************
//			 *  find node containing data  *
//			 *******************************/
//
//			Node *current = root;
//			while(current != NIL)
//				if(compEQ(data, current->data))
//					return (current);
//				else
//					current = compLT (data, current->data) ?
//							  current->left : current->right;
//			return(0);
//		}

		void traversal(Node* root)
		{
			if (root == NIL)
				return ;
			traversal(root->left);
			std::cout << "node: " << root->data << " color: " << root->color << std::endl;
			traversal(root->right);
		}
	};

}

#endif
