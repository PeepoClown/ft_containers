#ifndef DEQUENODE_HPP
#define DEQUENODE_HPP

#include <cstddef>

#define DEQUE_NODE_SIZE 8

namespace ft
{

	template <typename T>
	class DequeNode
	{
	public :
		typedef T               value_type;
		typedef value_type&     reference;
		typedef value_type*     pointer;
		typedef size_t          size_type;

	private :
		pointer     _data;
		size_type   _size;

	public :
		explicit DequeNode(size_type size = 0)
			: _size(size)
		{ this->_data = new value_type[DEQUE_NODE_SIZE]; }

		DequeNode(const DequeNode& x)
			: _size(x._size)
		{
			this->_data = new value_type[DEQUE_NODE_SIZE];
			for (size_type i = 0; i < this->_size; i++)
				this->_data[i] = x._data[i];
		}

		DequeNode& operator= (const DequeNode& x)
		{
			if (this->_data != NULL)
				delete[] this->_data;
			this->_size = x._size;
			this->_data = new value_type[DEQUE_NODE_SIZE];
			for (size_type i = 0; i < this->_size; i++)
				this->_data[i] = x._data[i];
			return (*this);
		}

		~DequeNode()
		{
			if (this->_data != NULL)
				delete[] this->_data;
		}

	    size_type size() const
		{ return (this->_size); }

		bool empty() const
		{ return (!this->_size); }

		bool isFull()
		{ return (this->_size >= DEQUE_NODE_SIZE); }

		reference front()
		{ return (this->_data[0]); }

		reference back()
		{ return (this->_data[this->_size - 1]); }
		                                    
		void push(const value_type& val)
		{
			if (isFull())
				return ;
			this->_data[this->_size] = val;
			this->_size++;
		}

		void pop()
		{
			if (empty())
				return ;
			this->_size--;
		}

		reference at(size_type n)
		{ return (this->_data[n]); }
	};

}

#endif
