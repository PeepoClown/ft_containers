#ifndef TREENODE_HPP
#define TREENODE_HPP

#include <cstddef>

namespace ft
{

	enum Color
	{
		BLUE = 0,
		YELLOW = 1
	};

	template <typename T>
	class TreeNode
	{
	public :
		template <typename K, typename Compare, bool isUnique>
		friend class Tree;

		typedef T			value_type;
		typedef TreeNode*	node_pointer;

	private :
		value_type		_data;
		node_pointer	_parent;
		node_pointer	_left;
		node_pointer	_right;
		ft::Color 		_color;

	public :
		explicit TreeNode(const value_type& val = value_type(), node_pointer parent = NULL,
						  node_pointer left = NULL, node_pointer right = NULL, ft::Color color = BLUE)
			: _data(val), _parent(parent), _left(left), _right(right), _color(color)
		{ }

		~TreeNode()
		{ }

		TreeNode(const TreeNode& node)
			: _data(node._data), _parent(node._parent), _left(node._left),
			  _right(node._right), _color(node._color)
		{ }

		TreeNode& operator= (const TreeNode& node)
		{
			this->_data = node._data;
			this->_parent = node._parent;
			this->_left = node._left;
			this->_right = node._right;
			this->_color = node._color;
			return (*this);
		}
	};

}

#endif
