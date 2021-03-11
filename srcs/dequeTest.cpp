#include <iostream>
#include "../Deque/Deque.hpp"

void	dequeTest()
{
	ft::deque<int> ft_deq;
	for (size_t i = 0; i < 11; i++) {
		if ((i + 1) <= 11)
			ft_deq.push_back(i + 1);
		else
			ft_deq.push_front(i + 1);
	}
	ft_deq.push_front(100);
	ft_deq.print();
	std::cout << "============================================================================\n";
	size_t sizePrev = ft_deq.size();
	for (size_t i = 0; i < sizePrev; i++) {
		ft_deq.pop_front();
		ft_deq.print();
		std::cout << "============================================================================\n";
	}
}
