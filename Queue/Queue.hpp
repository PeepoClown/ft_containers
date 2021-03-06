#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <cstddef>
#include "util.hpp"
#include "../List/List.hpp"

namespace ft
{

	template <typename T, typename Container = ft::list<T> >
	class queue
	{
	public :
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

	private :
		container_type _ctnr;

	public :
		explicit queue(const container_type& ctnr = container_type())
				: _ctnr(ctnr)
		{ }

		queue(const queue& x)
				: _ctnr(x._ctnr)
		{ }

		queue& operator= (const queue& x)
		{
			this->_ctnr = x._ctnr;
			return (*this);
		}

		~queue()
		{ }

		bool empty() const
		{ return (this->_ctnr.empty()); }

		size_type size() const
		{ return (this->_ctnr.size()); }

		value_type& front()
		{ return (this->_ctnr.front()); }

		const value_type& front() const
		{ return (this->_ctnr.front()); }

		value_type& back()
		{ return (this->_ctnr.back()); }

		const value_type& back() const
		{ return (this->_ctnr.back()); }

		void push(const value_type& val)
		{ this->_ctnr.push_back(val); }

		void pop()
		{ this->_ctnr.pop_front(); }

		template <typename K, typename C>
		friend bool operator== (const queue<K, C>& lhs, const queue<K, C>& rhs);
		template <typename K, typename C>
		friend bool operator!= (const queue<K, C>& lhs, const queue<K, C>& rhs);
		template <typename K, typename C>
		friend bool operator<  (const queue<K, C>& lhs, const queue<K, C>& rhs);
		template <typename K, typename C>
		friend bool operator<= (const queue<K, C>& lhs, const queue<K, C>& rhs);
		template <typename K, typename C>
		friend bool operator>  (const queue<K, C>& lhs, const queue<K, C>& rhs);
		template <typename K, typename C>
		friend bool operator>= (const queue<K, C>& lhs, const queue<K, C>& rhs);
	};

	template <typename T, typename Container>
	bool operator== (const queue<T, Container>& lhs, const queue<T, Container>& rhs)
	{ return (lhs._ctnr == rhs._ctnr); }

	template <typename T, typename Container>
	bool operator!= (const queue<T, Container>& lhs, const queue<T, Container>& rhs)
	{ return (!(lhs == rhs)); }

	template <typename T, typename Container>
	bool operator<  (const queue<T, Container>& lhs, const queue<T, Container>& rhs)
	{ return (lhs._ctnr < rhs._ctnr); }

	template <typename T, typename Container>
	bool operator<= (const queue<T, Container>& lhs, const queue<T, Container>& rhs)
	{ return (!(rhs < lhs)); }

	template <typename T, typename Container>
	bool operator>  (const queue<T, Container>& lhs, const queue<T, Container>& rhs)
	{ return (rhs < lhs); }

	template <typename T, typename Container>
	bool operator>= (const queue<T, Container>& lhs, const queue<T, Container>& rhs)
	{ return (!(lhs < rhs)); }

}

#endif
