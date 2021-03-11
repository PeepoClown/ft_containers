#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <memory>
#include <cstddef>
#include <limits>
#include <stdexcept>
#include "util.hpp"
#include "DequeNode.hpp"
#include "DequeIterator.hpp"
#include "../List/List.hpp"


#include <iostream>
#include <iomanip>


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
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;
		typedef DequeNode<value_type, allocator_type> node;

	private :
		ft::list<node>  _data;
		node*			_head;
		node*			_tail;
		size_type       _size;
		allocator_type	_alloc;

	public :
		explicit deque(const allocator_type& alloc = allocator_type())
			: _size(0), _alloc(alloc)
		{
			this->_head = new node();
			this->_tail = new node();
		}

		explicit deque(size_type n, const value_type& val = value_type(),
				       const allocator_type& alloc = allocator_type())
			: _size(0), _alloc(alloc)
		{
			this->_head = new node();
			this->_tail = new node();
			assign(n, val);
		}

		size_type size() const
		{ return (this->_size); }

		size_type max_size() const
		{ return (std::numeric_limits<size_type>::max() / sizeof(value_type)); }

		void resize(size_type n, value_type val = value_type())
		{
			if (n <= this->_size) {
				size_type prevSize = this->_size;
				for (size_type i = n; i < prevSize; i++)
					pop_back();
			}
			else {
				for (size_type i = this->_size; i < n; i++)
					push_back(val);
			}
			this->_size = n;
		}

		size_type empty() const
		{ return (!this->_size); }



		void assign(size_type n, const value_type& val)
		{
			// clear();
			while (n > 0) {
				push_back(val);
				n--;
			}
		}

		void push_back(const value_type& val)
		{
			if (this->_size == 0)
				this->_head->push(val);
			else {
				if (this->_tail->isFull()) {
					this->_data.push_back(*(this->_tail));
					this->_tail = new node();
				}
				this->_tail->push(val);
			}
			this->_size++;
		}

		void push_front(const value_type& val)
		{
			if (this->_head->isFull()) {
				this->_head->reverse();
				this->_data.push_front(*(this->_head));
				this->_head = new node();
			}
			this->_head->push(val);
			this->_size++;
		}

		void pop_back()
		{
			if (empty())
				return ;
			if (this->_tail->size() == 0 && this->_data.size() == 0) {
				this->_head->reverse();
				this->_head->pop();
				this->_head->reverse();
			}
			else if (this->_tail->size() == 1) {
				this->_tail->pop();
				if (this->_data.size() != 0) {
					this->_tail = new node(this->_data.back());
					this->_data.pop_back();
				}
				else
					this->_tail = new node();
			}
			else
				this->_tail->pop();
			this->_size--;
		}

		void pop_front()
		{
			if (empty())
				return ;
			if (this->_head->size() == 0 && this->_data.size() == 0) {
				this->_tail->reverse();
				this->_tail->pop();
				this->_tail->reverse();
			}
			else if (this->_head->size() == 1) {
				this->_head->pop();
				if (this->_data.size() != 0) {
					this->_head = new node(this->_data.front());
					this->_head->reverse();
					this->_data.pop_back();
				}
				else
					this->_head = new node();
				this->_data.pop_front();
			}
			else
				this->_head->pop();
			this->_size--;
		}

		void print() const
		{
			std::cout << "size: " << this->_size << std::endl;
			std::cout << "total chunks(/(head,tail)): " << this->_data.size() << std::endl;
			std::cout << "head chunk, with size: " << this->_head->size() << std::endl;
			std::cout << "content:";
			for (size_type j = 0; j < this->_head->size(); j++)
				std::cout << std::setw(4) << (*this->_head)[j];
			std::cout << std::endl;
			size_t i = 1;
			for (typename ft::list<node>::iterator it = this->_data.begin(); it != this->_data.end(); it++) {
				std::cout << i << " chunk, with size: " << it->size() << std::endl;
				std::cout << "content:";
				for (size_type j = 0; j < it->size(); j++)
					std::cout << std::setw(4) << (*it)[j];
				std::cout << std::endl;
				i++;
			}
			std::cout << "tail chunk, with size: " << this->_tail->size() << std::endl;
			std::cout << "content:";
			for (size_type j = 0; j < this->_tail->size(); j++)
				std::cout << std::setw(4) << (*this->_tail)[j];
			std::cout << std::endl;
		}


	};

}

#endif
