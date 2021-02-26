#ifndef LISTNODE_HPP
#define LISTNODE_HPP

#include <cstddef>

namespace ft
{

	template <typename T>
	class ListNode
	{
	public :
		template <typename K, typename Alloc>
		friend class list;

		template <typename N1>
		friend class ListIterator;
		template <typename N2>
		friend class ListReverseIterator;

		typedef T					value_type;
		typedef ListNode*			node_pointer;
		typedef const value_type&	const_reference;

	private :
		value_type		_data;
		node_pointer	_next;
		node_pointer	_prev;

	public :
		explicit ListNode(const_reference data = value_type(), node_pointer next = NULL,
		   		 node_pointer prev = NULL)
			: _data(data), _next(next), _prev(prev)
		{ }

		ListNode(const ListNode& node)
			: _data(node._data), _next(node._next), _prev(node._prev)
		{ }

		~ListNode()
		{ }

		ListNode& operator= (const ListNode& node)
		{
			this->_data = node._data;
			this->_next = node._next;
			this->_prev = node._prev;
			return (*this);
		}
	};

}

#endif
