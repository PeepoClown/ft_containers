#include <iostream>
#include <vector>
#include "Vector/Vector.hpp"

class A
		{
private :
	int a;
public :
	explicit A(int a = 0) : a(a) { std::cout << "a create\n"; }
	~A(){ std::cout << "a delete\n"; }
	A(const A& _a) : a(_a.a) { std::cout << "a copy\n"; }
	A& operator= (const A& _a) { a = _a.a; std::cout << "a copy\n"; return (*this); }
	int operator* () const { return a; }
};

int 	main()
{
	ft::vector<int> ft_vec;

	ft_vec.insert(ft_vec.begin(), 333333);

	for (size_t i = 0; i < 10; i++)
		ft_vec.push_back(i);

	ft_vec.erase(ft_vec.end() - 1);
	ft_vec.erase(ft_vec.end() - 1);
	ft_vec.erase(++ft_vec.begin());
	ft_vec.erase(--ft_vec.end());
	for (ft::vector<int>::iterator it = ft_vec.begin(); it != ft_vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	ft_vec.erase(ft_vec.begin() + 3, ft_vec.end() - 2);
	ft_vec.erase(ft_vec.begin(), ft_vec.end() - 2);

	for (ft::vector<int>::iterator it = ft_vec.begin(); it != ft_vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

	std::vector<int> v;

	v.insert(v.begin(), 333333);

	for (size_t i = 0; i < 10; i++)
		v.push_back(i);

	v.erase(v.end() - 1);
	v.erase(v.end() - 1);
	v.erase(++v.begin());
	v.erase(--v.end());
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	v.erase(v.begin() + 3, v.end() - 2);
	v.erase(v.begin(), v.end() - 2);

	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	return (0);
}
