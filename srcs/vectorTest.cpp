#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include "../Vector/Vector.hpp"

class Test
{
private :
	std::string i;
public :
	Test(std::string i = 0) : i(i) { std::cout << i << " created" << std::endl; }
	Test(const Test& test) : i(test.i) { }
	Test& operator= (const Test& test) { i = test.i; return (*this); }
	~Test() { std::cout << i << " removed" << std::endl; }
	friend std::ostream& operator<< (std::ostream& out, const Test& test);
};

std::ostream& operator<< (std::ostream& out, const Test& test)
{
	out << test.i;
	return (out);
}

void	print_std_vec(std::vector<int>& vec)
{
	std::cout << "[std]" << std::endl;
	size_t i = 0;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		std::cout << *it << " ";
		if ((i + 1) % 10 == 0 && i != vec.size() - 1)
			std::cout << std::endl;
		i++;
	}
	std::cout << std::endl;
	std::cout << "size: " << vec.size() << ", capacity: " << vec.capacity() << std::endl;
}

void	print_ft_vec(ft::vector<int>& vec)
{
	std::cout << "[ft]" << std::endl;
	size_t i = 0;
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		std::cout << *it << " ";
		if ((i + 1) % 10 == 0 && i != vec.size() - 1)
			std::cout << std::endl;
		i++;
	}
	std::cout << std::endl;
	std::cout << "size: " << vec.size() << ", capacity: " << vec.capacity() << std::endl;
}

void	vectorTest()
{
	srand(time(NULL));

	getchar();
	system("clear");

	{
		std::cout << "empty container test" << std::endl;
		std::vector<int> std_vec;
		ft::vector<int> ft_vec;
		print_std_vec(std_vec);
		print_ft_vec(ft_vec);
		std::cout << "[std] empty: " << std_vec.empty() << std::endl;
		std::cout << "[ft] empty: " << ft_vec.empty() << std::endl;
	}

	getchar();
	system("clear");

	{
		std::cout << "fill constructor and iterators test" << std::endl;
		std::vector<int> std_vec(10, 3);
		ft::vector<int> ft_vec(10, 3);
		print_std_vec(std_vec);
		print_ft_vec(ft_vec);
		std::cout << "pushing elements" << std::endl;
		for (size_t i = 0; i < 20; i++) {
			int val = rand() % 200 - 100;
			std_vec.push_back(val);
			ft_vec.push_back(val);
		}
		size_t i;
		std::cout << "iterator" << std::endl;
		std::cout << "[std]" << std::endl;
		i = 0;
		for (std::vector<int>::iterator it = std_vec.begin(); it != std_vec.end(); it++) {
			std::cout << *it << " ";
			if ((i + 1) % 10 == 0 && i != std_vec.size())
				std::cout << std::endl;
			i++;
		}
		std::cout << "[ft]" << std::endl;
		i = 0;
		for (ft::vector<int>::iterator it = ft_vec.begin(); it != ft_vec.end(); it++) {
			std::cout << *it << " ";
			if ((i + 1) % 10 == 0 && i != ft_vec.size())
				std::cout << std::endl;
			i++;
		}
		std::cout << "reverse iterator" << std::endl;
		std::cout << "[std]" << std::endl;
		i = 0;
		for (std::vector<int>::reverse_iterator it = std_vec.rbegin(); it != std_vec.rend(); it++) {
			std::cout << *it << " ";
			if ((i + 1) % 10 == 0 && i != std_vec.size())
				std::cout << std::endl;
			i++;
		}
		std::cout << "[ft]" << std::endl;
		i = 0;
		for (ft::vector<int>::reverse_iterator it = ft_vec.rbegin(); it != ft_vec.rend(); it++) {
			std::cout << *it << " ";
			if ((i + 1) % 10 == 0 && i != ft_vec.size())
				std::cout << std::endl;
			i++;
		}
		std::vector<int> std_vec_const(std_vec);
		ft::vector<int> ft_vec_const(ft_vec);
		std::cout << "const iterator" << std::endl;
		std::cout << "[std]" << std::endl;
		i = 0;
		for (std::vector<int>::const_iterator it = std_vec_const.begin(); it != std_vec_const.end(); it++) {
			std::cout << *it << " ";
			if ((i + 1) % 10 == 0 && i != std_vec_const.size())
				std::cout << std::endl;
			i++;
		}
		std::cout << "[ft]" << std::endl;
		i = 0;
		for (ft::vector<int>::const_iterator it = ft_vec_const.begin(); it != ft_vec_const.end(); it++) {
			std::cout << *it << " ";
			if ((i + 1) % 10 == 0 && i != ft_vec_const.size())
				std::cout << std::endl;
			i++;
		}
		std::cout << "const reverse iterator" << std::endl;
		std::cout << "[std]" << std::endl;
		i = 0;
		for (std::vector<int>::const_reverse_iterator it = std_vec_const.rbegin(); it != std_vec_const.rend(); it++) {
			std::cout << *it << " ";
			if ((i + 1) % 10 == 0 && i != std_vec_const.size())
				std::cout << std::endl;
			i++;
		}
		std::cout << "[ft]" << std::endl;
		i = 0;
		for (ft::vector<int>::const_reverse_iterator it = ft_vec_const.rbegin(); it != ft_vec_const.rend(); it++) {
			std::cout << *it << " ";
			if ((i + 1) % 10 == 0 && i != ft_vec_const.size())
				std::cout << std::endl;
			i++;
		}
	}

	getchar();
	system("clear");

	{
		std::cout << "range constructor test" << std::endl;
		std::vector<int> std_vec_base;
		ft::vector<int> ft_vec_base;
		for (size_t i = 0; i < 20; i++) {
			int val = rand() % 200 - 100;
			std_vec_base.push_back(val);
			ft_vec_base.push_back(val);
		}
		std::cout << "base vector" << std::endl;
		print_std_vec(std_vec_base);
		print_ft_vec(ft_vec_base);
		std::vector<int> std_vec(std_vec_base.begin() + 3, std_vec_base.end() - 3);
		ft::vector<int> ft_vec(ft_vec_base.begin() + 3, ft_vec_base.end() - 3);
		std::cout << "base vector in range [3, 17)" << std::endl;
		print_std_vec(std_vec);
		print_ft_vec(ft_vec);
	}

	getchar();
	system("clear");

	{
		std::cout << "copy constructor and assignation operator" << std::endl;
		std::vector<int> std_vec;
		ft::vector<int> ft_vec;
		std_vec.push_back(123); std_vec.push_back(456); std_vec.push_back(789); std_vec.push_back(234); std_vec.push_back(876);
		ft_vec.push_back(123); ft_vec.push_back(456); ft_vec.push_back(789); ft_vec.push_back(234); ft_vec.push_back(876);
		std::cout << "original" << std::endl;
		print_std_vec(std_vec);
		print_ft_vec(ft_vec);
		std::vector<int> std_vec_copy1(std_vec);
		ft::vector<int> ft_vec_copy1(ft_vec);
		std::cout << "created by copy constructor" << std::endl;
		print_std_vec(std_vec_copy1);
		print_ft_vec(ft_vec_copy1);
		std::vector<int> std_vec_copy2;
		ft::vector<int> ft_vec_copy2;
		std::cout << "assignation operator work" << std::endl;
		std_vec_copy2 = std_vec;
		ft_vec_copy2 = ft_vec;
		print_std_vec(std_vec_copy2);
		print_ft_vec(ft_vec_copy2);
		std::cout << "compare iterators to show that there are different containers" << std::endl;
		std::cout << "[std]: orig and copy-construcor created " << (std_vec.begin() == std_vec_copy1.begin())
				  << ", copy-construcor created and assignated " << (std_vec_copy1.begin() == std_vec_copy2.begin())
				  << ", orig and assignated " << (std_vec.begin() == std_vec_copy2.begin()) << std::endl;
		std::cout << "[ft]: orig and copy-construcor created " << (ft_vec.begin() == ft_vec_copy1.begin())
				  << ", copy-construcor created and assignated " << (ft_vec_copy1.begin() == ft_vec_copy2.begin())
				  << ", orig and assignated " << (ft_vec.begin() == ft_vec_copy2.begin()) << std::endl;
	}

	getchar();
	system("clear");

	{
		std::cout << "size, capacity, empty and max_size test" << std::endl;
		std::vector<int> std_vec;
		ft::vector<int> ft_vec;
		for (size_t i = 0; i < 16; i++) {
			int val = rand() % 200 - 100;
			std_vec.push_back(val);
			ft_vec.push_back(val);
		}
		print_std_vec(std_vec);
		print_ft_vec(ft_vec);
		std::cout << "[std] empty: " << std_vec.empty() << std::endl;
		std::cout << "[ft] empty: " << ft_vec.empty() << std::endl;
		std::cout << "after pushing 3 and pop 1 elements" << std::endl;
		std_vec.push_back(11); std_vec.push_back(22); std_vec.push_back(33); std_vec.pop_back();
		ft_vec.push_back(11); ft_vec.push_back(22); ft_vec.push_back(33); ft_vec.pop_back();
		print_std_vec(std_vec);
		print_ft_vec(ft_vec);
		std::cout << "vector of integers store max" << std::endl;
		std::cout << "[std] " << std_vec.max_size() << " , [ft] " << ft_vec.max_size() << std::endl;
		std::vector<double> std_vec_double;
		ft::vector<double> ft_vec_double;
		std::cout << "vector of doubles store max" << std::endl;
		std::cout << "[std] " << std_vec_double.max_size() << " , [ft] " << ft_vec_double.max_size() << std::endl;
		std::vector<Test> std_vec_obj;
		ft::vector<Test> ft_vec_obj;
		std::cout << "vector of custom objects store max" << std::endl;
		std::cout << "[std] " << std_vec_obj.max_size() << " , [ft] " << ft_vec_obj.max_size() << std::endl;
	}

	getchar();
	system("clear");

	{
		std::cout << "reserve resize test" << std::endl;
		std::vector<int> std_vec(10, 3);
		ft::vector<int> ft_vec(10, 3);
		std::cout << "[std] size: " << std_vec.size() << ", capacity: " << std_vec.capacity() << std::endl;
		std::cout << "[ft] size: " << ft_vec.size() << ", capacity: " << ft_vec.capacity() << std::endl;
		std::cout << "reserving less or equal than current capacity" << std::endl;
		std_vec.reserve(6);
		ft_vec.reserve(6);
		std::cout << "[std] size: " << std_vec.size() << ", capacity: " << std_vec.capacity() << std::endl;
		std::cout << "[ft] size: " << ft_vec.size() << ", capacity: " << ft_vec.capacity() << std::endl;
		std::cout << "reserving more space than current capacity" << std::endl;
		std_vec.reserve(68);
		ft_vec.reserve(68);
		std::cout << "[std] size: " << std_vec.size() << ", capacity: " << std_vec.capacity() << std::endl;
		std::cout << "[ft] size: " << ft_vec.size() << ", capacity: " << ft_vec.capacity() << std::endl;
		std::cout << "resize with empty vector" << std::endl;
		std::vector<int> std_vec1;
		ft::vector<int> ft_vec1;
		std::cout << "[std] size: " << std_vec1.size() << ", capacity: " << std_vec1.capacity() << std::endl;
		std::cout << "[ft] size: " << ft_vec1.size() << ", capacity: " << ft_vec1.capacity() << std::endl;
		std_vec1.resize(10, 44);
		ft_vec1.resize(10, 44);
		print_std_vec(std_vec1);
		print_ft_vec(ft_vec1);
		std::cout << "resize with non empty vector by decreasing" << std::endl;
		std_vec1.resize(5);
		ft_vec1.resize(5);
		print_std_vec(std_vec1);
		print_ft_vec(ft_vec1);
		std::cout << "resize with non empty vector by increasing" << std::endl;
		std_vec1.resize(15, 33);
		ft_vec1.resize(15, 33);
		print_std_vec(std_vec1);
		print_ft_vec(ft_vec1);
	}

	getchar();
	system("clear");

	{
		std::cout << "random access methods test" << std::endl;
		std::vector<int> std_vec;
		ft::vector<int> ft_vec;
		for (size_t i = 0; i < 20; i++) {
			int val = rand() % 200 - 100;
			std_vec.push_back(val);
			ft_vec.push_back(val);
		}
		std::cout << "original vector" << std::endl;
		print_std_vec(std_vec);
		print_ft_vec(ft_vec);
		std::cout << "[std] front: " << std_vec.front() << ", back: " << std_vec.back() << std::endl;
		std::cout << "[ft]  front: " << ft_vec.front() << ", back: " << ft_vec.back() << std::endl;
		std::cout << "output by [] operator overload" << std::endl;
		std::cout << "[std]: ";
		for (size_t i = 0; i < std_vec.size(); i++)
			std::cout << std_vec[i] << " ";
		std::cout << std::endl;
		std::cout << "[ft]:  ";
		for (size_t i = 0; i < ft_vec.size(); i++)
			std::cout << ft_vec[i] << " ";
		std::cout << std::endl;
		std::cout << "trying access elem with incorrect index" << std::endl;
		try {
			std::cout << "[std]: " << std_vec.at(std_vec.size()) << std::endl;
		} catch (const std::exception &ex) {
			std::cout << "cathed exception : " << ex.what() << std::endl;
		}
		try {
			std::cout << "[ft]:  " << ft_vec.at(ft_vec.size()) << std::endl;
		} catch (const std::exception &ex) {
			std::cout << "cathed exception : " << ex.what() << std::endl;
		}
	}

	getchar();
	system("clear");

	{
		std::cout << "push_back/pop_back and clear test" << std::endl;
		std::cout << "with empty vector" << std::endl;
		std::vector<int> std_vec;
		ft::vector<int> ft_vec;
		std_vec.push_back(11); std_vec.push_back(22); std_vec.push_back(33); std_vec.push_back(44); std_vec.push_back(55);
		ft_vec.push_back(11); ft_vec.push_back(22); ft_vec.push_back(33); ft_vec.push_back(44); ft_vec.push_back(55);
		print_std_vec(std_vec);
		print_ft_vec(ft_vec);
		std::cout << "deelte 2 eleemts" << std::endl;
		std_vec.pop_back(); std_vec.pop_back();
		ft_vec.pop_back(); ft_vec.pop_back();
		print_std_vec(std_vec);
		print_ft_vec(ft_vec);
		std::cout << "with non empty vector" << std::endl;
		std::vector<int> std_vec1(3, 5);
		ft::vector<int> ft_vec1(3, 5);
		print_std_vec(std_vec1);
		print_ft_vec(ft_vec1);
		std_vec1.push_back(11); std_vec1.push_back(22); std_vec1.push_back(33); std_vec1.push_back(44); std_vec1.push_back(55);
		ft_vec1.push_back(11); ft_vec1.push_back(22); ft_vec1.push_back(33); ft_vec1.push_back(44); ft_vec1.push_back(55);
		print_std_vec(std_vec1);
		print_ft_vec(ft_vec1);
		std::cout << "deelte 3 eleemts" << std::endl;
		std_vec1.pop_back(); std_vec1.pop_back(); std_vec1.pop_back();
		ft_vec1.pop_back(); ft_vec1.pop_back(); ft_vec1.pop_back();
		print_std_vec(std_vec1);
		print_ft_vec(ft_vec1);
		std::cout << "after clearing" << std::endl;
		std_vec1.clear();
		ft_vec1.clear();
		print_std_vec(std_vec1);
		print_ft_vec(ft_vec1);
		std::cout << "with custom objects vector" << std::endl;
		std::vector<Test> std_vec_obj;
		ft::vector<Test> ft_vec_obj;
		std_vec_obj.push_back(Test("std_asd")); std_vec_obj.push_back(Test("std_zxc")); std_vec_obj.push_back(Test("std_qwe"));
		ft_vec_obj.push_back(Test("ft_asd")); ft_vec_obj.push_back(Test("ft_zxc")); ft_vec_obj.push_back(Test("ft_qwe"));
		std::cout << "[std] vec: ";
		for (std::vector<Test>::iterator it = std_vec_obj.begin(); it != std_vec_obj.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		std::cout << "[ft] vec: ";
		for (ft::vector<Test>::iterator it = ft_vec_obj.begin(); it != ft_vec_obj.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		std::cout << "pop + push + pop test" << std::endl;
		std_vec_obj.pop_back(); std_vec_obj.push_back(Test("std_nhk")); std_vec_obj.pop_back();
		ft_vec_obj.pop_back(); ft_vec_obj.push_back(Test("ft_nhk")); ft_vec_obj.pop_back();
		std::cout << "[std] vec: ";
		for (std::vector<Test>::iterator it = std_vec_obj.begin(); it != std_vec_obj.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		std::cout << "[ft] vec: ";
		for (ft::vector<Test>::iterator it = ft_vec_obj.begin(); it != ft_vec_obj.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	getchar();
	system("clear");

	{
		std::cout << "insert test" << std::endl;
		std::cout << "insert in empty vector" << std::endl;
		std::vector<int> std_vec_base(6, 100); std_vec_base.push_back(500);
		ft::vector<int> ft_vec_base(6, 100); ft_vec_base.push_back(500);
		std::vector<int> std_vec;
		ft::vector<int> ft_vec;
		std_vec.insert(std_vec.begin(), std_vec_base.begin() + 2, std_vec_base.end());
		ft_vec.insert(ft_vec.begin(), ft_vec_base.begin() + 2, ft_vec_base.end());
		print_std_vec(std_vec);
		print_ft_vec(ft_vec);
		std::cout << "insertion in non vector list" << std::endl;
		std::vector<int> std_vec1;
		ft::vector<int> ft_vec1;
		std_vec1.push_back(222); std_vec1.push_back(444);
		ft_vec1.push_back(222); ft_vec1.push_back(444);
		print_std_vec(std_vec1);
		print_ft_vec(ft_vec1);
		std_vec1.insert(std_vec1.begin() + 1, 777); // single
		ft_vec1.insert(ft_vec1.begin() + 1, 777);
		print_std_vec(std_vec1);
		print_ft_vec(ft_vec1);
		std_vec1.insert(std_vec1.begin(), 2, 77); // fill
		ft_vec1.insert(ft_vec1.begin(), 2, 77);
		print_std_vec(std_vec1);
		print_ft_vec(ft_vec1);
		std_vec1.insert(std_vec1.end(), std_vec_base.begin(), std_vec_base.end() - 1); // range
		ft_vec1.insert(ft_vec1.end(), ft_vec_base.begin(), ft_vec_base.end() - 1);
		print_std_vec(std_vec1);
		print_ft_vec(ft_vec1);
	}

	getchar();
	system("clear");

	{
		std::cout << "erase test" << std::endl;
		std::vector<int> std_vec;
		ft::vector<int> ft_vec;
		std_vec.push_back(100); std_vec.push_back(200); std_vec.push_back(300); std_vec.push_back(400); std_vec.push_back(500); std_vec.push_back(600);
		ft_vec.push_back(100); ft_vec.push_back(200); ft_vec.push_back(300); ft_vec.push_back(400); ft_vec.push_back(500); ft_vec.push_back(600);
		std::cout << "current vector content" << std::endl;
		print_std_vec(std_vec);
		print_ft_vec(ft_vec);
		std::cout << "after erase begin and end" << std::endl;
		std_vec.erase(std_vec.begin()); std_vec.erase(--std_vec.end());
		ft_vec.erase(ft_vec.begin()); ft_vec.erase(--ft_vec.end());
		print_std_vec(std_vec);
		print_ft_vec(ft_vec);
		std::cout << "after erase all elements" << std::endl;
		std_vec.erase(std_vec.begin(), std_vec.end());
		ft_vec.erase(ft_vec.begin(), ft_vec.end());
		print_std_vec(std_vec);
		print_ft_vec(ft_vec);
	}

	getchar();
	system("clear");

	{
		std::cout << "assing test" << std::endl;
		std::cout << "assign to empty vector" << std::endl;
		std::vector<int> std_vec_base(4, 100); std_vec_base.push_back(500);
		ft::vector<int> ft_vec_base(4, 100); ft_vec_base.push_back(500);
		std::vector<int> std_vec1;
		ft::vector<int> ft_vec1;
		std_vec1.assign(5, 29);
		ft_vec1.assign(5, 29);
		print_std_vec(std_vec1);
		print_ft_vec(ft_vec1);
		std::vector<int> std_vec2(23, 4);
		ft::vector<int> ft_vec2(23, 4);
		std::cout << "assign to non empty vector" << std::endl;
		std::cout << "before assign" << std::endl;
		print_std_vec(std_vec2);
		print_ft_vec(ft_vec2);
		std_vec2.assign(std_vec_base.begin(), std_vec_base.end());
		ft_vec2.assign(ft_vec_base.begin(), ft_vec_base.end());
		print_std_vec(std_vec2);
		print_ft_vec(ft_vec2);
	}

	getchar();
	system("clear");

	{
		std::cout << "swap test" << std::endl;
		std::vector<int> std_vec1, std_vec2;
		ft::vector<int> ft_vec1, ft_vec2;
		std_vec1.push_back(100); std_vec1.push_back(200); std_vec1.push_back(300);
		std_vec2.push_back(77); std_vec2.push_back(88); std_vec2.push_back(99); std_vec2.push_back(789);
		ft_vec1.push_back(100); ft_vec1.push_back(200); ft_vec1.push_back(300);
		ft_vec2.push_back(77); ft_vec2.push_back(88); ft_vec2.push_back(99); ft_vec2.push_back(789);
		std::vector<int>::iterator std_it1 = std_vec1.begin(), std_it2 = std_vec2.begin();
		ft::vector<int>::iterator ft_it1 = ft_vec1.begin(), ft_it2 = ft_vec2.begin();
		std::cout << "iterators before swap" << std::endl;
		std::cout << "[std1] " << *std_it1 << " [ft1] " << *ft_it1 << std::endl;
		std::cout << "[std2] " << *std_it2 << " [ft2] " << *ft_it2 << std::endl;
		print_std_vec(std_vec1);
		print_ft_vec(ft_vec1);
		print_std_vec(std_vec2);
		print_ft_vec(ft_vec2);
		std_vec1.swap(std_vec2);
		ft_vec1.swap(ft_vec2);
		std::cout << "iterators after swap(the same but points to another container)" << std::endl;
		std::cout << "[std1] " << *std_it1 << " [ft1] " << *ft_it1 << std::endl;
		std::cout << "[std2] " << *std_it2 << " [ft2] " << *ft_it2 << std::endl;
		print_std_vec(std_vec1);
		print_ft_vec(ft_vec1);
		print_std_vec(std_vec2);
		print_ft_vec(ft_vec2);
	}

	getchar();
	system("clear");

	{
		std::cout << "compare operators test" << std::endl;
		std::vector<int> std_vec1, std_vec2, std_vec3;
		ft::vector<int> ft_vec1, ft_vec2, ft_vec3;
		std_vec1.push_back(1); std_vec1.push_back(2); std_vec1.push_back(3);
		std_vec2.push_back(1); std_vec2.push_back(2);
		std_vec3.push_back(1); std_vec3.push_back(2); std_vec3.push_back(4);
		ft_vec1.push_back(1); ft_vec1.push_back(2); ft_vec1.push_back(3);
		ft_vec2.push_back(1); ft_vec2.push_back(2);
		ft_vec3.push_back(1); ft_vec3.push_back(2); ft_vec3.push_back(4);
		std::cout << "[std] compare 1 2 3 with 1 2" << std::endl;
		std::cout << "== : " << (std_vec1 == std_vec2) << std::endl;
		std::cout << "!= : " << (std_vec1 != std_vec2) << std::endl;
		std::cout << "< : " << (std_vec1 < std_vec2) << std::endl;
		std::cout << "> : " << (std_vec1 > std_vec2) << std::endl;
		std::cout << "<= : " << (std_vec1 <= std_vec2) << std::endl;
		std::cout << ">= : " << (std_vec1 >= std_vec2) << std::endl;
		std::cout << "[std] compare 1 2 3 with 1 2 4" << std::endl;
		std::cout << "== : " << (std_vec1 == std_vec3) << std::endl;
		std::cout << "!= : " << (std_vec1 != std_vec3) << std::endl;
		std::cout << "< : " << (std_vec1 < std_vec3) << std::endl;
		std::cout << "> : " << (std_vec1 > std_vec3) << std::endl;
		std::cout << "<= : " << (std_vec1 <= std_vec3) << std::endl;
		std::cout << ">= : " << (std_vec1 >= std_vec3) << std::endl;
		std::cout << "[ft] compare 1 2 3 with 1 2" << std::endl;
		std::cout << "== : " << (ft_vec1 == ft_vec2) << std::endl;
		std::cout << "!= : " << (ft_vec1 != ft_vec2) << std::endl;
		std::cout << "< : " << (ft_vec1 < ft_vec2) << std::endl;
		std::cout << "> : " << (ft_vec1 > ft_vec2) << std::endl;
		std::cout << "<= : " << (ft_vec1 <= ft_vec2) << std::endl;
		std::cout << ">= : " << (ft_vec1 >= ft_vec2) << std::endl;
		std::cout << "[ft] compare 1 2 3 with 1 2 4" << std::endl;
		std::cout << "== : " << (ft_vec1 == ft_vec3) << std::endl;
		std::cout << "!= : " << (ft_vec1 != ft_vec3) << std::endl;
		std::cout << "< : " << (ft_vec1 < ft_vec3) << std::endl;
		std::cout << "> : " << (ft_vec1 > ft_vec3) << std::endl;
		std::cout << "<= : " << (ft_vec1 <= ft_vec3) << std::endl;
		std::cout << ">= : " << (ft_vec1 >= ft_vec3) << std::endl;
		std::vector<int> std_vec_copy(std_vec1);
		ft::vector<int> ft_vec_copy(ft_vec1);
		std::cout << "compare equal vectors" << std::endl;
		std::cout << "[std]" << std::endl;
		std::cout << "== : " << (std_vec1 == std_vec_copy) << std::endl;
		std::cout << "!= : " << (std_vec1 != std_vec_copy) << std::endl;
		std::cout << "< : " << (std_vec1 < std_vec_copy) << std::endl;
		std::cout << "> : " << (std_vec1 > std_vec_copy) << std::endl;
		std::cout << "<= : " << (std_vec1 <= std_vec_copy) << std::endl;
		std::cout << ">= : " << (std_vec1 >= std_vec_copy) << std::endl;
		std::cout << "[ft]" << std::endl;
		std::cout << "== : " << (ft_vec1 == ft_vec_copy) << std::endl;
		std::cout << "!= : " << (ft_vec1 != ft_vec_copy) << std::endl;
		std::cout << "< : " << (ft_vec1 < ft_vec_copy) << std::endl;
		std::cout << "> : " << (ft_vec1 > ft_vec_copy) << std::endl;
		std::cout << "<= : " << (ft_vec1 <= ft_vec_copy) << std::endl;
		std::cout << ">= : " << (ft_vec1 >= ft_vec_copy) << std::endl;
	}

	getchar();
	system("clear");

	std::cout <<	"\n\n\n\
					⢸⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⡷⡄\n\
					⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⠀⡇  ⠢⣀\n\
					⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀ ⠈⠑⢦⡀\n\
					⢸⠀⠀⠀⠀⢀⠖⠒⠒⠒⢤⠀⠀⠀⠀⠀ ⡇⠀⠀⠀⠀ ⠀⠙⢦⡀\n\
					⢸⠀⠀⣀⢤⣼⣀⡠⠤⠤⠼⠤⡄⠀⠀  ⡇⠀⠀⠀⠀⠀⠀ ⠀⠙⢄\n\
					⢸⠀⠀⠑⡤⠤⡒⠒⠒⡊⠙⡏⠀⢀⠀  ⡇⠀⠀⠀⠀⠀⠀⠀ ⠀⠀⠑⠢⡄\n\
					⢸⠀⠀⠀⠇⠀⣀⣀⣀⣀⢀⠧⠟⠁  ⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⡇\n\
					⢸⠀⠀⠀⠸⣀⠀⠀⠈⢉⠟⠓⠀⠀⠀ ⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⢸\n\
					⢸⠀⠀⠀⠀⠈⢱⡖⠋⠁⠀⠀⠀⠀⠀ ⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⢸\n\
					⢸⠀⠀⠀⠀⣠⢺⠧⢄⣀⠀⠀⣀⣀⠀ ⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⢸\n\
					⢸⠀⠀⠀⣠⠃⢸⠀⠀⠈⠉⡽⠿⠯⡆⠀ ⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⢸\n\
					⢸⠀⠀⣰⠁⠀⢸⠀⠀⠀⠀⠉⠉⠉⠀⠀ ⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⢸\n\
					⢸⠀⠀⠣⠀⠀⢸⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⢸\n\
					⢸⠀⠀⠀⠀⠀⢸⠀⢇⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⢸\n\
					⢸⠀⠀⠀⠀⠀⡌⠀⠈⡆⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⢸\n\
					⢸⠀⠀⠀⠀⢠⠃⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⢸\n\
					⢸⠀⠀⠀⠀⢸⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⢸\n\n\n";

	getchar();
	system("clear");

}
