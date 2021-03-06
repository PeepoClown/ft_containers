#ifndef STACK_HPP
#define STACK_HPP

#include <cstddef>
#include "util.hpp"
#include "../List/List.hpp"

namespace ft
{

	template <typename T, typename Container = ft::list<T> >
	class stack
	{
	public :
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

	private :
		container_type _ctnr;

	public :
		explicit stack(const container_type& ctnr = container_type())
			: _ctnr(ctnr)
		{ }

		stack(const stack& x)
			: _ctnr(x._ctnr)
		{ }

		stack& operator= (const stack& x)
		{
			this->_ctnr = x._ctnr;
			return (*this);
		}

		~stack()
		{ }

		bool empty() const
		{ return (this->_ctnr.empty()); }

		size_type size() const
		{ return (this->_ctnr.size()); }

		value_type& top()
		{ return (this->_ctnr.front()); }

		const value_type& top() const
		{ return (this->_ctnr.front()); }

		void push(const value_type& val)
		{ this->_ctnr.push_front(val); }

		void pop()
		{ this->_ctnr.pop_front(); }

		template <typename K, typename C>
		friend bool operator== (const stack<K, C>& lhs, const stack<K, C>& rhs);
		template <typename K, typename C>
		friend bool operator!= (const stack<K, C>& lhs, const stack<K, C>& rhs);
		template <typename K, typename C>
		friend bool operator<  (const stack<K, C>& lhs, const stack<K, C>& rhs);
		template <typename K, typename C>
		friend bool operator<= (const stack<K, C>& lhs, const stack<K, C>& rhs);
		template <typename K, typename C>
		friend bool operator>  (const stack<K, C>& lhs, const stack<K, C>& rhs);
		template <typename K, typename C>
		friend bool operator>= (const stack<K, C>& lhs, const stack<K, C>& rhs);
	};

	template <typename T, typename Container>
	bool operator== (const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{ return (lhs._ctnr == rhs._ctnr); }

	template <typename T, typename Container>
	bool operator!= (const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{ return (!(lhs == rhs)); }

	template <typename T, typename Container>
	bool operator<  (const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{ return (lhs._ctnr < rhs._ctnr); }

	template <typename T, typename Container>
	bool operator<= (const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{ return (!(rhs < lhs)); }

	template <typename T, typename Container>
	bool operator>  (const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{ return (rhs < lhs); }

	template <typename T, typename Container>
	bool operator>= (const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{ return (!(lhs < rhs)); }

}

#endif
