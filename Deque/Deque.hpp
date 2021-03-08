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


#include <iostream>


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
		node*			_head;
		// first end that was set on creation
		node*			_tail;
		size_type       _size;
		size_type		_chunks;
		allocator_type	_alloc;

	public :
		explicit deque(const allocator_type& alloc = allocator_type())
			: _size(0), _chunks(2), _alloc(alloc)
		{
			this->_data.push_front(node());
			this->_data.push_back(node());
			this->_head = &this->_data.front();
			this->_tail = &this->_data.back();
		}

		explicit deque(size_type n, const value_type& val = value_type(),
				       const allocator_type& alloc = allocator_type())
			: _size(0), _alloc(alloc)
		{
			this->_data.push_front(node());
			this->_data.push_back(node());
			this->_head = &this->_data.front();
			this->_tail = &this->_data.back();
			this->_chunks += 2;
			assign(n, val);
		}



		void assign(size_type n, const value_type& val)
		{
			clear();
			while (n > 0) {
				push_back(val);
				n--;
			}
		}

		void push_back(const value_type& val)
		{
			if (this->_tail->isFull()) {
				this->_data.push_back(node());
				this->_tail = &this->_data.back();
				this->_chunks++;
			}
			this->_tail->push(val);
			this->_size++;
		}

		void push_front(const value_type& val)
		{
			if (this->_head->isFull()) {
				this->_data.push_front(node());
				this->_head = &this->_data.front();
				this->_chunks++;
			}
			this->_head->push(val);
			this->_size++;
		}

		void clear()
		{
			this->_data.clear();
			this->_data.push_front(node());
			this->_data.push_back(node());
			this->_head = &this->_data.front();
			this->_tail = &this->_data.back();
			this->_size = 0;
			this->_chunks = 2;
		}

		void print() const
		{
			std::cout << "total chunks: " << this->_data.size() << std::endl;
			size_t i = 1;
			for (typename ft::list<node>::iterator it = this->_data.begin(); it != this->_data.end(); it++) {
				std::cout << i << " chunk, with size: " << it->size() << std::endl;
				node n(*it);
				while (!n.empty()) {
					std::cout << n.back() << " ";
					n.pop();
				}
				std::cout << std::endl;
				i++;
			}
		}


	};

}

#endif
