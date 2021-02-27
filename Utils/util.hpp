#ifndef UTIL_HPP
#define UTIL_HPP

#include <cstddef>

namespace ft
{

	template <typename T>
	const T& max(const T& val1, const T& val2)
	{ return (val1 > val2 ? val1 : val2); }

	template <typename T>
	const T& min(const T& val1, const T& val2)
	{ return (val1 < val2 ? val1 : val2); }

	template <typename T>
	bool more(const T& val1, const T& val2)
	{ return (val1 > val2); }

	template <typename T>
	bool less(const T& val1, const T& val2)
	{ return (val1 < val2); }

	template <typename T>
	struct Less
	{
		bool operator() (const T& val1, const T& val2)
		{ return (val1 < val2); }
	};

	template <typename T>
	void swap(T& val1, T& val2)
	{
		T tmp = val1;
		val1 = val2;
		val2 = tmp;
	}

	template <typename InputIterator>
	size_t distance(InputIterator first, InputIterator last)
	{
		size_t count = 0;
		while (first != last) {
			count++;
			first++;
		}
		return (count);
	}

	template <typename InputIterator1, typename InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								 InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <bool B, typename T = void>
	struct enable_if { };

	template <typename T>
	struct enable_if <true, T> { typedef T type; };

}

#endif
