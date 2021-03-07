#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <memory>
#include <cstddef>
#include <limits>
#include <stdexcept>
#include "util.hpp"
#include "DequeNode.hpp"
// deque iterator
#include "../List/List.hpp"

namespace ft
{

	template <typename T, typename Alloc = std::allocator<T> >
	class deque
	{
	public :
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef value_type* pointer;
		typedef const value_type* const_pointer;
		// iterators ...
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;
		typedef DequeNode<value_type> node;

	private :
		ft::list<node>  _data;
		size_type       _size;


	};

}

#endif
