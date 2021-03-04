#ifndef MULTIMAP_HPP
#define MULTIMAP_HPP

#include <memory>
#include <cstddef>
#include <limits>
#include "../Utils/util.hpp"
#include "../Utils/RBTree.hpp"

namespace ft
{

	template <typename Key, typename T, typename Compare = std::less<Key>,
			typename Alloc = std::allocator<std::pair<const Key, T> > >
	class multimap : public Tree<std::pair<const Key, T>, value_compare<std::pair<const Key, T>, Compare>, true>
	{
	public :
		typedef Key																			key_type;
		typedef T																			mapped_type;
		typedef std::pair<const Key, T>														value_type;
		typedef Compare																		key_compare;
		typedef value_compare<value_type, key_compare>										value_compare;
		typedef Alloc																		allocator_type;
		typedef value_type&						 											reference;
		typedef const value_type&															const_reference;
		typedef value_type*																	pointer;
		typedef const value_type*															const_pointer;
		typedef typename Tree<value_type, value_compare, true>::iterator					iterator;
		typedef typename Tree<value_type, value_compare, true>::reverse_iterator			reverse_iterator;
		typedef typename Tree<value_type, value_compare, true>::const_iterator				const_iterator;
		typedef typename Tree<value_type, value_compare, true>::const_reverse_iterator		const_reverse_iterator;
		typedef ptrdiff_t																	difference_type;
		typedef size_t																		size_type;
		typedef Tree<std::pair<const Key, T>, value_compare, true>							tree;
		typedef TreeNode<value_type>														node;

	private :
		key_compare		_cmp;
		allocator_type	_alloc;

	public :
		explicit multimap(const key_compare& cmp = key_compare(),
						  const allocator_type& alloc = allocator_type())
			: tree(value_compare(cmp)), _cmp(cmp), _alloc(alloc)
		{ }

		template <typename InputIterator>
		multimap(InputIterator first, InputIterator last, const key_compare& cmp = key_compare(),
				 const allocator_type& alloc = allocator_type())
			: tree(value_compare(cmp)), _cmp(cmp), _alloc(alloc)
		{ this->insert(first, last); }

		multimap(const multimap& x)
			: tree(value_compare(x._cmp)), _cmp(x._cmp), _alloc(x._alloc)
		{ this->insert(x.begin(), x.end()); }

		multimap& operator= (const multimap& x)
		{
			this->_cmp = x._cmp;
			tree::clear();
			this->insert(x.begin(), x.end());
			return (*this);
		}

		virtual ~multimap()
		{ }

		bool empty() const
		{ return (!this->size()); }

		size_type max_size() const
		{ return(std::numeric_limits<size_type>::max() / sizeof(node)); }

		iterator insert(const value_type& val)
		{ return (tree::insert(val).first); }

		iterator insert(iterator position, const value_type& val)
		{
			static_cast<void>(position);
			return (tree::insert(val).first);
		}

		template <typename InputIterator>
		void insert(InputIterator first, InputIterator last,
					typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0)
		{
			while (first != last) {
				tree::insert(*first);
				first++;
			}
		}

		void erase(iterator position)
		{ tree::erase(position); }

		size_type erase(const key_type& key)
		{
			value_type val = value_type(key, mapped_type());
			size_type result = tree::count(val);
			size_type i = result;
			while (i > 0) {
				tree::erase(tree::find(val));
				i--;
			}
			return (result);
		}

		void erase(iterator first, iterator last)
		{
			iterator curr = first, next;
			while (curr != last) {
				next = ++curr;
				--curr;
				tree::erase(curr);
				curr = next;
			}
		}

		void swap(multimap& x)
		{
			tree::swap(x.getTree());
			ft::swap(this->_cmp, x._cmp);
		}

		void clear()
		{ tree::clear(); }

		key_compare key_comp() const
		{ return (this->_cmp); }

		value_compare value_comp() const
		{ return (value_compare(this->_cmp)); }

		iterator find(const key_type& key)
		{
			value_type val = value_type(key, mapped_type());
			return (tree::find(val));
		}

		const_iterator find(const key_type& key) const
		{
			value_type val = value_type(key, mapped_type());
			return (tree::find(val));
		}

		size_type count(const key_type& key) const
		{
			value_type val = value_type(key, mapped_type());
			return (tree::count(val));
		}

		iterator lower_bound(const key_type& key)
		{
			for (iterator it = tree::begin(); it != tree::end(); it++) {
				if (!this->_cmp(it->first, key))
					return (it);
			}
			return (tree::end());
		}
		const_iterator lower_bound(const key_type& key) const
		{
			for (const_iterator it = tree::begin(); it != tree::end(); it++) {
				if (!this->_cmp(it->first, key))
					return (it);
			}
			return (tree::end());
		}

		iterator upper_bound(const key_type& key)
		{
			for (iterator it = tree::begin(); it != tree::end(); it++) {
				if (this->_cmp(key, it->first))
					return (it);
			}
			return (tree::end());
		}
		const_iterator upper_bound(const key_type& key) const
		{
			for (const_iterator it = tree::begin(); it != tree::end(); it++) {
				if (this->_cmp(key, it->first))
					return (it);
			}
			return (tree::end());
		}

		std::pair<iterator, iterator> equal_range(const key_type& key)
		{ return (std::pair<iterator, iterator>(lower_bound(key), upper_bound(key))); }

		std::pair<const_iterator, const_iterator> equal_range(const key_type& key) const
		{ return (std::pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key))); }
	};

}

#endif
