#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <deque>
#include "../Deque/Deque.hpp"

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

void	print_std_deq(std::deque<int>& deq)
{
	std::cout << "[std]" << std::endl;
	size_t i = 0;
	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++) {
		std::cout << *it << " ";
		if ((i + 1) % 10 == 0 && i != deq.size() - 1)
			std::cout << std::endl;
		i++;
	}
	std::cout << std::endl;
	std::cout << "size: " << deq.size() << std::endl;
}

void	print_ft_deq(ft::deque<int>& deq)
{
	std::cout << "[ft]" << std::endl;
	size_t i = 0;
	for (ft::deque<int>::iterator it = deq.begin(); it != deq.end(); it++) {
		std::cout << *it << " ";
		if ((i + 1) % 10 == 0 && i != deq.size() - 1)
			std::cout << std::endl;
		i++;
	}
	std::cout << std::endl;
	std::cout << "size: " << deq.size() << std::endl;
}

void	dequeTest()
{
	srand(time(NULL));

	getchar();
	system("clear");

	{
		std::cout << "empty container test" << std::endl;
		std::deque<int> std_deq;
		ft::deque<int> ft_deq;
		print_std_deq(std_deq);
		print_ft_deq(ft_deq);
		std::cout << "[std] empty: " << std_deq.empty() << std::endl;
		std::cout << "[ft] empty: " << ft_deq.empty() << std::endl;
	}

	getchar();
	system("clear");

	{
		std::cout << "fill constructor and iterators test" << std::endl;
		std::deque<int> std_deq(10, 3);
		ft::deque<int> ft_deq(10, 3);
		print_std_deq(std_deq);
		print_ft_deq(ft_deq);
		std::cout << "pushing elements" << std::endl;
		for (size_t i = 0; i < 20; i++) {
			int val = rand() % 200 - 100;
			std_deq.push_back(val);
			ft_deq.push_back(val);
		}
		size_t i;
		std::cout << "iterator" << std::endl;
		std::cout << "[std]" << std::endl;
		i = 0;
		for (std::deque<int>::iterator it = std_deq.begin(); it != std_deq.end(); it++) {
			std::cout << *it << " ";
			if ((i + 1) % 10 == 0 && i != std_deq.size())
				std::cout << std::endl;
			i++;
		}
		std::cout << "[ft]" << std::endl;
		i = 0;
		for (ft::deque<int>::iterator it = ft_deq.begin(); it != ft_deq.end(); it++) {
			std::cout << *it << " ";
			if ((i + 1) % 10 == 0 && i != ft_deq.size())
				std::cout << std::endl;
			i++;
		}
		std::cout << "reverse iterator" << std::endl;
		std::cout << "[std]" << std::endl;
		i = 0;
		for (std::deque<int>::reverse_iterator it = std_deq.rbegin(); it != std_deq.rend(); it++) {
			std::cout << *it << " ";
			if ((i + 1) % 10 == 0 && i != std_deq.size())
				std::cout << std::endl;
			i++;
		}
		std::cout << "[ft]" << std::endl;
		i = 0;
		for (ft::deque<int>::reverse_iterator it = ft_deq.rbegin(); it != ft_deq.rend(); it++) {
			std::cout << *it << " ";
			if ((i + 1) % 10 == 0 && i != ft_deq.size())
				std::cout << std::endl;
			i++;
		}
		std::deque<int> std_deq_const(std_deq);
		ft::deque<int> ft_deq_const(ft_deq);
		std::cout << "const iterator" << std::endl;
		std::cout << "[std]" << std::endl;
		i = 0;
		for (std::deque<int>::const_iterator it = std_deq_const.begin(); it != std_deq_const.end(); it++) {
			std::cout << *it << " ";
			if ((i + 1) % 10 == 0 && i != std_deq_const.size())
				std::cout << std::endl;
			i++;
		}
		std::cout << "[ft]" << std::endl;
		i = 0;
		for (ft::deque<int>::const_iterator it = ft_deq_const.begin(); it != ft_deq_const.end(); it++) {
			std::cout << *it << " ";
			if ((i + 1) % 10 == 0 && i != ft_deq_const.size())
				std::cout << std::endl;
			i++;
		}
		std::cout << "const reverse iterator" << std::endl;
		std::cout << "[std]" << std::endl;
		i = 0;
		for (std::deque<int>::const_reverse_iterator it = std_deq_const.rbegin(); it != std_deq_const.rend(); it++) {
			std::cout << *it << " ";
			if ((i + 1) % 10 == 0 && i != std_deq_const.size())
				std::cout << std::endl;
			i++;
		}
		std::cout << "[ft]" << std::endl;
		i = 0;
		for (ft::deque<int>::const_reverse_iterator it = ft_deq_const.rbegin(); it != ft_deq_const.rend(); it++) {
			std::cout << *it << " ";
			if ((i + 1) % 10 == 0 && i != ft_deq_const.size())
				std::cout << std::endl;
			i++;
		}
	}

	getchar();
	system("clear");

	{
		std::cout << "range constructor test" << std::endl;
		std::deque<int> std_deq_base;
		ft::deque<int> ft_deq_base;
		for (size_t i = 0; i < 20; i++) {
			int val = rand() % 200 - 100;
			std_deq_base.push_back(val);
			ft_deq_base.push_back(val);
		}
		std::cout << "base deque" << std::endl;
		print_std_deq(std_deq_base);
		print_ft_deq(ft_deq_base);
		std::deque<int> std_deq(std_deq_base.begin() + 3, std_deq_base.end() - 3);
		ft::deque<int> ft_deq(ft_deq_base.begin() + 3, ft_deq_base.end() - 3);
		std::cout << "base deque in range [3, 17)" << std::endl;
		print_std_deq(std_deq);
		print_ft_deq(ft_deq);
	}

	getchar();
	system("clear");

	{
		std::cout << "copy constructor and assignation operator" << std::endl;
		std::deque<int> std_deq;
		ft::deque<int> ft_deq;
		std_deq.push_back(123); std_deq.push_back(456); std_deq.push_back(789); std_deq.push_back(234); std_deq.push_back(876);
		ft_deq.push_back(123); ft_deq.push_back(456); ft_deq.push_back(789); ft_deq.push_back(234); ft_deq.push_back(876);
		std::cout << "original" << std::endl;
		print_std_deq(std_deq);
		print_ft_deq(ft_deq);
		std::deque<int> std_deq_copy1(std_deq);
		ft::deque<int> ft_deq_copy1(ft_deq);
		std::cout << "created by copy constructor" << std::endl;
		print_std_deq(std_deq_copy1);
		print_ft_deq(ft_deq_copy1);
		std::deque<int> std_deq_copy2;
		ft::deque<int> ft_deq_copy2;
		std::cout << "assignation operator work" << std::endl;
		std_deq_copy2 = std_deq;
		ft_deq_copy2 = ft_deq;
		print_std_deq(std_deq_copy2);
		print_ft_deq(ft_deq_copy2);
		std::cout << "compare iterators to show that there are different containers" << std::endl;
		std::cout << "[std]: orig and copy-construcor created " << (std_deq.begin() == std_deq_copy1.begin())
				  << ", copy-construcor created and assignated " << (std_deq_copy1.begin() == std_deq_copy2.begin())
				  << ", orig and assignated " << (std_deq.begin() == std_deq_copy2.begin()) << std::endl;
		std::cout << "[ft]: orig and copy-construcor created " << (ft_deq.begin() == ft_deq_copy1.begin())
				  << ", copy-construcor created and assignated " << (ft_deq_copy1.begin() == ft_deq_copy2.begin())
				  << ", orig and assignated " << (ft_deq.begin() == ft_deq_copy2.begin()) << std::endl;
	}

	getchar();
	system("clear");

	{
		std::cout << "size, empty and max_size test" << std::endl;
		std::deque<int> std_deq;
		ft::deque<int> ft_deq;
		for (size_t i = 0; i < 16; i++) {
			int val = rand() % 200 - 100;
			std_deq.push_back(val);
			ft_deq.push_back(val);
		}
		print_std_deq(std_deq);
		print_ft_deq(ft_deq);
		std::cout << "[std] empty: " << std_deq.empty() << std::endl;
		std::cout << "[ft] empty: " << ft_deq.empty() << std::endl;
		std::cout << "after pushing 3 and pop 1 elements" << std::endl;
		std_deq.push_back(11); std_deq.push_back(22); std_deq.push_back(33); std_deq.pop_back();
		ft_deq.push_back(11); ft_deq.push_back(22); ft_deq.push_back(33); ft_deq.pop_back();
		print_std_deq(std_deq);
		print_ft_deq(ft_deq);
		std::cout << "deque of integers store max" << std::endl;
		std::cout << "[std] " << std_deq.max_size() << " , [ft] " << ft_deq.max_size() << std::endl;
		std::deque<double> std_deq_double;
		ft::deque<double> ft_deq_double;
		std::cout << "deque of doubles store max" << std::endl;
		std::cout << "[std] " << std_deq_double.max_size() << " , [ft] " << ft_deq_double.max_size() << std::endl;
		std::deque<Test> std_deq_obj;
		ft::deque<Test> ft_deq_obj;
		std::cout << "deque of custom objects store max" << std::endl;
		std::cout << "[std] " << std_deq_obj.max_size() << " , [ft] " << ft_deq_obj.max_size() << std::endl;
	}

	getchar();
	system("clear");

	{
		std::cout << "resize test" << std::endl;
		std::cout << "resize with empty deque" << std::endl;
		std::deque<int> std_deq1;
		ft::deque<int> ft_deq1;
		std::cout << "[std] size: " << std_deq1.size() << std::endl;
		std::cout << "[ft] size: " << ft_deq1.size() << std::endl;
		std_deq1.resize(10, 44);
		ft_deq1.resize(10, 44);
		print_std_deq(std_deq1);
		print_ft_deq(ft_deq1);
		std::cout << "resize with non empty deque by decreasing" << std::endl;
		std_deq1.resize(5);
		ft_deq1.resize(5);
		print_std_deq(std_deq1);
		print_ft_deq(ft_deq1);
		std::cout << "resize with non empty deque by increasing" << std::endl;
		std_deq1.resize(15, 33);
		ft_deq1.resize(15, 33);
		print_std_deq(std_deq1);
		print_ft_deq(ft_deq1);
	}

	getchar();
	system("clear");

	{
		std::cout << "random access methods test" << std::endl;
		std::deque<int> std_deq;
		ft::deque<int> ft_deq;
		for (size_t i = 0; i < 20; i++) {
			int val = rand() % 200 - 100;
			std_deq.push_back(val);
			ft_deq.push_back(val);
		}
		std::cout << "original deque" << std::endl;
		print_std_deq(std_deq);
		print_ft_deq(ft_deq);
		std::cout << "[std] front: " << std_deq.front() << ", back: " << std_deq.back() << std::endl;
		std::cout << "[ft]  front: " << ft_deq.front() << ", back: " << ft_deq.back() << std::endl;
		std::cout << "output by [] operator overload" << std::endl;
		std::cout << "[std]: ";
		for (size_t i = 0; i < std_deq.size(); i++)
			std::cout << std_deq[i] << " ";
		std::cout << std::endl;
		std::cout << "[ft]:  ";
		for (size_t i = 0; i < ft_deq.size(); i++)
			std::cout << ft_deq[i] << " ";
		std::cout << std::endl;
		std::cout << "trying access elem with incorrect index" << std::endl;
		try {
			std::cout << "[std]: " << std_deq.at(std_deq.size()) << std::endl;
		} catch (const std::exception &ex) {
			std::cout << "cathed exception : " << ex.what() << std::endl;
		}
		try {
			std::cout << "[ft]:  " << ft_deq.at(ft_deq.size()) << std::endl;
		} catch (const std::exception &ex) {
			std::cout << "cathed exception : " << ex.what() << std::endl;
		}
	}

	getchar();
	system("clear");

	{
		std::cout << "push/pop and clear test" << std::endl;
		std::cout << "with empty deque" << std::endl;
		std::deque<int> std_deq;
		ft::deque<int> ft_deq;
		std_deq.push_back(11); std_deq.push_front(22); std_deq.push_back(33); std_deq.push_back(44); std_deq.push_front(55);
		ft_deq.push_back(11); ft_deq.push_front(22); ft_deq.push_back(33); ft_deq.push_back(44); ft_deq.push_front(55);
		print_std_deq(std_deq);
		print_ft_deq(ft_deq);
		std::cout << "deelte 2 eleemts" << std::endl;
		std_deq.pop_back(); std_deq.pop_front();
		ft_deq.pop_back(); ft_deq.pop_front();
		print_std_deq(std_deq);
		print_ft_deq(ft_deq);
		std::cout << "with non empty deque" << std::endl;
		std::deque<int> std_deq1(3, 5);
		ft::deque<int> ft_deq1(3, 5);
		print_std_deq(std_deq1);
		print_ft_deq(ft_deq1);
		std_deq1.push_back(11); std_deq1.push_front(22); std_deq1.push_back(33); std_deq1.push_back(44); std_deq1.push_front(55);
		ft_deq1.push_back(11); ft_deq1.push_front(22); ft_deq1.push_back(33); ft_deq1.push_back(44); ft_deq1.push_front(55);
		print_std_deq(std_deq1);
		print_ft_deq(ft_deq1);
		std::cout << "delete 3 eleemts" << std::endl;
		std_deq1.pop_front(); std_deq1.pop_back(); std_deq1.pop_back();
		ft_deq1.pop_front(); ft_deq1.pop_back(); ft_deq1.pop_back();
		print_std_deq(std_deq1);
		print_ft_deq(ft_deq1);
		std::cout << "after clearing" << std::endl;
		std_deq1.clear();
		ft_deq1.clear();
		print_std_deq(std_deq1);
		print_ft_deq(ft_deq1);
	}

	getchar();
	system("clear");

	{
		std::cout << "insert test" << std::endl;
		std::cout << "insert in empty deque" << std::endl;
		std::deque<int> std_deq_base(6, 100); std_deq_base.push_back(500);
		ft::deque<int> ft_deq_base(6, 100); ft_deq_base.push_back(500);
		std::deque<int> std_deq;
		ft::deque<int> ft_deq;
		std_deq.insert(std_deq.begin(), std_deq_base.begin() + 2, std_deq_base.end());
		ft_deq.insert(ft_deq.begin(), ft_deq_base.begin() + 2, ft_deq_base.end());
		print_std_deq(std_deq);
		print_ft_deq(ft_deq);
		std::cout << "insertion in non deque list" << std::endl;
		std::deque<int> std_deq1;
		ft::deque<int> ft_deq1;
		std_deq1.push_back(222); std_deq1.push_back(444);
		ft_deq1.push_back(222); ft_deq1.push_back(444);
		print_std_deq(std_deq1);
		print_ft_deq(ft_deq1);
		std_deq1.insert(std_deq1.begin() + 1, 777); // single
		ft_deq1.insert(ft_deq1.begin() + 1, 777);
		print_std_deq(std_deq1);
		print_ft_deq(ft_deq1);
		std_deq1.insert(std_deq1.begin(), 2, 77); // fill
		ft_deq1.insert(ft_deq1.begin(), 2, 77);
		print_std_deq(std_deq1);
		print_ft_deq(ft_deq1);
		std_deq1.insert(std_deq1.end(), std_deq_base.begin(), std_deq_base.end() - 1); // range
		ft_deq1.insert(ft_deq1.end(), ft_deq_base.begin(), ft_deq_base.end() - 1);
		print_std_deq(std_deq1);
		print_ft_deq(ft_deq1);
	}

	getchar();
	system("clear");

	{
		std::cout << "erase test" << std::endl;
		std::deque<int> std_deq;
		ft::deque<int> ft_deq;
		std_deq.push_back(100); std_deq.push_back(200); std_deq.push_back(300); std_deq.push_back(400); std_deq.push_back(500); std_deq.push_back(600);
		ft_deq.push_back(100); ft_deq.push_back(200); ft_deq.push_back(300); ft_deq.push_back(400); ft_deq.push_back(500); ft_deq.push_back(600);
		std::cout << "current deque content" << std::endl;
		print_std_deq(std_deq);
		print_ft_deq(ft_deq);
		std::cout << "after erase begin and end" << std::endl;
		std_deq.erase(std_deq.begin()); std_deq.erase(--std_deq.end());
		ft_deq.erase(ft_deq.begin()); ft_deq.erase(--ft_deq.end());
		print_std_deq(std_deq);
		print_ft_deq(ft_deq);
		std::cout << "after erase all elements" << std::endl;
		std_deq.erase(std_deq.begin(), std_deq.end());
		ft_deq.erase(ft_deq.begin(), ft_deq.end());
		print_std_deq(std_deq);
		print_ft_deq(ft_deq);
	}

	getchar();
	system("clear");

	{
		std::cout << "assing test" << std::endl;
		std::cout << "assign to empty deque" << std::endl;
		std::deque<int> std_deq_base(4, 100); std_deq_base.push_back(500);
		ft::deque<int> ft_deq_base(4, 100); ft_deq_base.push_back(500);
		std::deque<int> std_deq1;
		ft::deque<int> ft_deq1;
		std_deq1.assign(5, 29);
		ft_deq1.assign(5, 29);
		print_std_deq(std_deq1);
		print_ft_deq(ft_deq1);
		std::deque<int> std_deq2(23, 4);
		ft::deque<int> ft_deq2(23, 4);
		std::cout << "assign to non empty deque" << std::endl;
		std::cout << "before assign" << std::endl;
		print_std_deq(std_deq2);
		print_ft_deq(ft_deq2);
		std_deq2.assign(std_deq_base.begin(), std_deq_base.end());
		ft_deq2.assign(ft_deq_base.begin(), ft_deq_base.end());
		print_std_deq(std_deq2);
		print_ft_deq(ft_deq2);
	}

	getchar();
	system("clear");

	{
		std::cout << "swap test" << std::endl;
		std::deque<int> std_deq1, std_deq2;
		ft::deque<int> ft_deq1, ft_deq2;
		std_deq1.push_back(100); std_deq1.push_back(200); std_deq1.push_back(300);
		std_deq2.push_back(77); std_deq2.push_back(88); std_deq2.push_back(99); std_deq2.push_back(789);
		ft_deq1.push_back(100); ft_deq1.push_back(200); ft_deq1.push_back(300);
		ft_deq2.push_back(77); ft_deq2.push_back(88); ft_deq2.push_back(99); ft_deq2.push_back(789);
		std::deque<int>::iterator std_it1 = std_deq1.begin(), std_it2 = std_deq2.begin();
		ft::deque<int>::iterator ft_it1 = ft_deq1.begin(), ft_it2 = ft_deq2.begin();
		std::cout << "iterators before swap" << std::endl;
		std::cout << "[std1] " << *std_it1 << " [ft1] " << *ft_it1 << std::endl;
		std::cout << "[std2] " << *std_it2 << " [ft2] " << *ft_it2 << std::endl;
		print_std_deq(std_deq1);
		print_ft_deq(ft_deq1);
		print_std_deq(std_deq2);
		print_ft_deq(ft_deq2);
		std_deq1.swap(std_deq2);
		ft_deq1.swap(ft_deq2);
		std::cout << "iterators after swap(the same but points to another container)" << std::endl;
		std::cout << "[std1] " << *std_it1 << " [ft1] " << *ft_it1 << std::endl;
		std::cout << "[std2] " << *std_it2 << " [ft2] " << *ft_it2 << std::endl;
		print_std_deq(std_deq1);
		print_ft_deq(ft_deq1);
		print_std_deq(std_deq2);
		print_ft_deq(ft_deq2);
	}

	getchar();
	system("clear");

	{
		std::cout << "compare operators test" << std::endl;
		std::deque<int> std_deq1, std_deq2, std_deq3;
		ft::deque<int> ft_deq1, ft_deq2, ft_deq3;
		std_deq1.push_back(1); std_deq1.push_back(2); std_deq1.push_back(3);
		std_deq2.push_back(1); std_deq2.push_back(2);
		std_deq3.push_back(1); std_deq3.push_back(2); std_deq3.push_back(4);
		ft_deq1.push_back(1); ft_deq1.push_back(2); ft_deq1.push_back(3);
		ft_deq2.push_back(1); ft_deq2.push_back(2);
		ft_deq3.push_back(1); ft_deq3.push_back(2); ft_deq3.push_back(4);
		std::cout << "[std] compare 1 2 3 with 1 2" << std::endl;
		std::cout << "== : " << (std_deq1 == std_deq2) << std::endl;
		std::cout << "!= : " << (std_deq1 != std_deq2) << std::endl;
		std::cout << "< : " << (std_deq1 < std_deq2) << std::endl;
		std::cout << "> : " << (std_deq1 > std_deq2) << std::endl;
		std::cout << "<= : " << (std_deq1 <= std_deq2) << std::endl;
		std::cout << ">= : " << (std_deq1 >= std_deq2) << std::endl;
		std::cout << "[std] compare 1 2 3 with 1 2 4" << std::endl;
		std::cout << "== : " << (std_deq1 == std_deq3) << std::endl;
		std::cout << "!= : " << (std_deq1 != std_deq3) << std::endl;
		std::cout << "< : " << (std_deq1 < std_deq3) << std::endl;
		std::cout << "> : " << (std_deq1 > std_deq3) << std::endl;
		std::cout << "<= : " << (std_deq1 <= std_deq3) << std::endl;
		std::cout << ">= : " << (std_deq1 >= std_deq3) << std::endl;
		std::cout << "[ft] compare 1 2 3 with 1 2" << std::endl;
		std::cout << "== : " << (ft_deq1 == ft_deq2) << std::endl;
		std::cout << "!= : " << (ft_deq1 != ft_deq2) << std::endl;
		std::cout << "< : " << (ft_deq1 < ft_deq2) << std::endl;
		std::cout << "> : " << (ft_deq1 > ft_deq2) << std::endl;
		std::cout << "<= : " << (ft_deq1 <= ft_deq2) << std::endl;
		std::cout << ">= : " << (ft_deq1 >= ft_deq2) << std::endl;
		std::cout << "[ft] compare 1 2 3 with 1 2 4" << std::endl;
		std::cout << "== : " << (ft_deq1 == ft_deq3) << std::endl;
		std::cout << "!= : " << (ft_deq1 != ft_deq3) << std::endl;
		std::cout << "< : " << (ft_deq1 < ft_deq3) << std::endl;
		std::cout << "> : " << (ft_deq1 > ft_deq3) << std::endl;
		std::cout << "<= : " << (ft_deq1 <= ft_deq3) << std::endl;
		std::cout << ">= : " << (ft_deq1 >= ft_deq3) << std::endl;
		std::deque<int> std_deq_copy(std_deq1);
		ft::deque<int> ft_deq_copy(ft_deq1);
		std::cout << "compare equal deques" << std::endl;
		std::cout << "[std]" << std::endl;
		std::cout << "== : " << (std_deq1 == std_deq_copy) << std::endl;
		std::cout << "!= : " << (std_deq1 != std_deq_copy) << std::endl;
		std::cout << "< : " << (std_deq1 < std_deq_copy) << std::endl;
		std::cout << "> : " << (std_deq1 > std_deq_copy) << std::endl;
		std::cout << "<= : " << (std_deq1 <= std_deq_copy) << std::endl;
		std::cout << ">= : " << (std_deq1 >= std_deq_copy) << std::endl;
		std::cout << "[ft]" << std::endl;
		std::cout << "== : " << (ft_deq1 == ft_deq_copy) << std::endl;
		std::cout << "!= : " << (ft_deq1 != ft_deq_copy) << std::endl;
		std::cout << "< : " << (ft_deq1 < ft_deq_copy) << std::endl;
		std::cout << "> : " << (ft_deq1 > ft_deq_copy) << std::endl;
		std::cout << "<= : " << (ft_deq1 <= ft_deq_copy) << std::endl;
		std::cout << ">= : " << (ft_deq1 >= ft_deq_copy) << std::endl;
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
