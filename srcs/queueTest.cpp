#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include "../Queue/Queue.hpp"

void	queueTest()
{
	getchar();
	system("clear");

	{
		std::queue<int> std_queue;
		ft::queue<int> ft_queue;

		std::cout << "empty queue" << std::endl;
		std::cout << "[std] size: " << std_queue.size() << std::endl;
		std::cout << "[ft] size: " << ft_queue.size() << std::endl;
		std::cout << "[std] empty: " << std_queue.empty() << std::endl;
		std::cout << "[ft] empty: " << ft_queue.empty() << std::endl;
	}

	getchar();
	system("clear");

	{
		std::queue<int> std_queue;
		ft::queue<int> ft_queue;

		std_queue.push(1); std_queue.push(2); std_queue.push(3);
		ft_queue.push(1); ft_queue.push(2); ft_queue.push(3);
		std::cout << "1 2 3 queue" << std::endl;
		std::cout << "[std] size: " << std_queue.size() << std::endl;
		std::cout << "[ft] size: " << ft_queue.size() << std::endl;
		std::cout << "[std] empty: " << std_queue.empty() << std::endl;
		std::cout << "[ft] empty: " << ft_queue.empty() << std::endl;
		std::cout << "[std] front: " << std_queue.front() << std::endl;
		std::cout << "[ft] front: " << ft_queue.front() << std::endl;
		std::cout << "[std] back: " << std_queue.back() << std::endl;
		std::cout << "[ft] back: " << ft_queue.back() << std::endl;
		std::cout << "[std] queue: ";
		while (!std_queue.empty()) {
			std::cout << std_queue.front() << " ";
			std_queue.pop();
		}
		std::cout << std::endl << "[ft] queue: ";
		while (!ft_queue.empty()) {
			std::cout << ft_queue.front() << " ";
			ft_queue.pop();
		}
		std::cout << std::endl << "[std] empty: " << std_queue.empty() << std::endl;
		std::cout << "[ft] empty: " << ft_queue.empty() << std::endl;
	}

	getchar();
	system("clear");

	{
		std::queue<int> std_queue;
		ft::queue<int> ft_queue;

		std::cout << "100 elements queue" << std::endl;
		srand(time(NULL));
		for (size_t i = 0; i < 100; i++) {
			int val = rand() % 2000 - 1000;
			std_queue.push(val);
			ft_queue.push(val);
		}
		std::cout << "[std] size: " << std_queue.size() << std::endl;
		std::cout << "[ft] size: " << ft_queue.size() << std::endl;
		std::cout << "decrease by 3 elements" << std::endl;
		std_queue.pop(); std_queue.pop(); std_queue.pop();
		ft_queue.pop(); ft_queue.pop(); ft_queue.pop();
		std::cout << "[std] size: " << std_queue.size() << std::endl;
		std::cout << "[ft] size: " << ft_queue.size() << std::endl;
		std::cout << "[std] queue: ";
		size_t i = 0;
		while (!std_queue.empty()) {
			std::cout << std_queue.front() << " ";
			std_queue.pop();
			if ((i + 1) % 10 == 0)
				std::cout << std::endl;
			i++;
		}
		std::cout << std::endl << "[ft] queue: ";
		i = 0;
		while (!ft_queue.empty()) {
			std::cout << ft_queue.front() << " ";
			ft_queue.pop();
			if ((i + 1) % 10 == 0)
				std::cout << std::endl;
			i++;
		}
		std::cout << std::endl;
	}

	getchar();
	system("clear");

	{
		std::cout << "compare operators test" << std::endl;
		std::queue<int> std_queue1;
		std::queue<int> std_queue2;
		std::queue<int> std_queue3;
		ft::queue<int> ft_queue1;
		ft::queue<int> ft_queue2;
		ft::queue<int> ft_queue3;

		std_queue1.push(1); std_queue1.push(2); std_queue1.push(3);
		std_queue2.push(1); std_queue2.push(2);
		std_queue3.push(1); std_queue3.push(2); std_queue3.push(4);

		ft_queue1.push(1); ft_queue1.push(2); ft_queue1.push(3);
		ft_queue2.push(1); ft_queue2.push(2);
		ft_queue3.push(1); ft_queue3.push(2); ft_queue3.push(4);

		std::cout << "[std] compare 1 2 3 with 1 2" << std::endl;
		std::cout << "== : " << (std_queue1 == std_queue2) << std::endl;
		std::cout << "!= : " << (std_queue1 != std_queue2) << std::endl;
		std::cout << "< : " << (std_queue1 < std_queue2) << std::endl;
		std::cout << "> : " << (std_queue1 > std_queue2) << std::endl;
		std::cout << "<= : " << (std_queue1 <= std_queue2) << std::endl;
		std::cout << ">= : " << (std_queue1 >= std_queue2) << std::endl;
		std::cout << "[std] compare 1 2 3 with 1 2 4" << std::endl;
		std::cout << "== : " << (std_queue1 == std_queue3) << std::endl;
		std::cout << "!= : " << (std_queue1 != std_queue3) << std::endl;
		std::cout << "< : " << (std_queue1 < std_queue3) << std::endl;
		std::cout << "> : " << (std_queue1 > std_queue3) << std::endl;
		std::cout << "<= : " << (std_queue1 <= std_queue3) << std::endl;
		std::cout << ">= : " << (std_queue1 >= std_queue3) << std::endl;
		std::cout << "[ft] compare 1 2 3 with 1 2" << std::endl;
		std::cout << "== : " << (ft_queue1 == ft_queue2) << std::endl;
		std::cout << "!= : " << (ft_queue1 != ft_queue2) << std::endl;
		std::cout << "< : " << (ft_queue1 < ft_queue2) << std::endl;
		std::cout << "> : " << (ft_queue1 > ft_queue2) << std::endl;
		std::cout << "<= : " << (ft_queue1 <= ft_queue2) << std::endl;
		std::cout << ">= : " << (ft_queue1 >= ft_queue2) << std::endl;
		std::cout << "[ft] compare 1 2 3 with 1 2 4" << std::endl;
		std::cout << "== : " << (ft_queue1 == ft_queue3) << std::endl;
		std::cout << "!= : " << (ft_queue1 != ft_queue3) << std::endl;
		std::cout << "< : " << (ft_queue1 < ft_queue3) << std::endl;
		std::cout << "> : " << (ft_queue1 > ft_queue3) << std::endl;
		std::cout << "<= : " << (ft_queue1 <= ft_queue3) << std::endl;
		std::cout << ">= : " << (ft_queue1 >= ft_queue3) << std::endl;

		std::queue<int> std_queue_copy(std_queue1);
		ft::queue<int> ft_queue_copy(ft_queue1);

		std::cout << "compare equal queues" << std::endl;
		std::cout << "[std]" << std::endl;
		std::cout << "== : " << (std_queue1 == std_queue_copy) << std::endl;
		std::cout << "!= : " << (std_queue1 != std_queue_copy) << std::endl;
		std::cout << "< : " << (std_queue1 < std_queue_copy) << std::endl;
		std::cout << "> : " << (std_queue1 > std_queue_copy) << std::endl;
		std::cout << "<= : " << (std_queue1 <= std_queue_copy) << std::endl;
		std::cout << ">= : " << (std_queue1 >= std_queue_copy) << std::endl;
		std::cout << "[ft]" << std::endl;
		std::cout << "== : " << (ft_queue1 == ft_queue_copy) << std::endl;
		std::cout << "!= : " << (ft_queue1 != ft_queue_copy) << std::endl;
		std::cout << "< : " << (ft_queue1 < ft_queue_copy) << std::endl;
		std::cout << "> : " << (ft_queue1 > ft_queue_copy) << std::endl;
		std::cout << "<= : " << (ft_queue1 <= ft_queue_copy) << std::endl;
		std::cout << ">= : " << (ft_queue1 >= ft_queue_copy) << std::endl;
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
