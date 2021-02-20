#include <iostream>
#include <vector>
#include "Vector/Vector.hpp"

class A{
private :
	int a;
public :
	A() : a(0) { std::cout << "a create\n"; }
	~A(){ std::cout << "a delete\n"; }
	A(const A& _a) : a(_a.a) { std::cout << "a copy\n"; }
	A& operator= (const A& _a) { a = _a.a; std::cout << "a copy\n"; return (*this); }
};

int 	main()
{
	ft::vector<int> ft_vec;

	for (size_t i = 0; i < 10; i++)
		ft_vec.push_back(i);

	std::cout << *(ft_vec.insert(ft_vec.end(), 111)) << std::endl;
	ft_vec.insert(ft_vec.end(), 555);
	std::cout << *(ft_vec.insert(ft_vec.begin(), 222)) << std::endl;
	ft_vec.insert(--ft_vec.end(), 444);
	ft_vec.insert(++ft_vec.begin(), 333);

	ft_vec.insert(++ft_vec.begin(), 4, 5);

	for (ft::vector<int>::iterator it = ft_vec.begin(); it != ft_vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	ft::vector<int> ft_vec1(1, 10);

	ft_vec1.insert(ft_vec1.begin(), ft_vec.begin(), ft_vec.end());

	for (ft::vector<int>::iterator it = ft_vec1.begin(); it != ft_vec1.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	return (0);
}
