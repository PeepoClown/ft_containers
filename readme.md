# Std-containers
My implementation of stl containers from c++98 standard, for a better understanding of basic data structures and the
algorithms that apply to them.

## Summary
The multiple available containers in C++ all have a very different usage.
To make sure you understand them all, let’s re-implement them!

## Build
Run `make` and start binary of containers

## Content
- [x] Vector ([std::vector]) - sequence container representing dynamic sized array
- [x] List ([std::list]) - sequence container representing double linked list
- [x] Stack ([std::stack]) - lifo, based on list
- [x] Queue ([std::queue]) - fifo, based on list
- [x] Map ([std::map]) - associative container that store elements formed by a combination of a key value and
a mapped value, based on Red-Black Tree
- [x] Set ([std::set]) - container that store unique elements following a specific order, based on Red-Black Tree
- [x] Multimap ([std::multimap]) - map that can store multiple unique keys, based on Red-Black Tree
- [x] Multiset ([std::multiset]) - set that can store multiple unique elements, based on Red-Black Tree
- [x] Deque ([std::deque]) - double ended queue, in base is dynamic array

[std::vector]: http://www.cplusplus.com/reference/vector/vector
[std::list]: http://www.cplusplus.com/reference/list/list
[std::stack]: http://www.cplusplus.com/reference/stack/stack
[std::queue]: http://www.cplusplus.com/reference/queue/queue
[std::map]: http://www.cplusplus.com/reference/map/map
[std::set]: http://www.cplusplus.com/reference/set/set
[std::multimap]: http://www.cplusplus.com/reference/map/multimap
[std::multiset]: http://www.cplusplus.com/reference/set/multiset
[std::deque]: http://www.cplusplus.com/reference/deque/deque

## Constraints
* Implement the following containers, and turn in the necessary files <container>.hpp
* You must also provide a main.cpp which tests everything for your evaluations.
* The member function get_allocator is not expected here, the remaining member
functions are. Non-member overloads are expected aswell.
* If the container has an iterator system, you must reimplent it.
* You can use https://www.cplusplus.com/ as a reference of what to implement.
* You cannot implement more public functions than the ones offered in the standard
containers. Everything else must be private or protected. Each public function/-
variable must be justified.
* For non-member overloads, the keyword friend is allowed. Each use of friend
must be justified and will be checked during evaluation.

You must turn in the following containers and their associated functions:
* List
* Vector
* Map
* Stack
* Queue

Of course, STL is forbidden. You are however allowed to use the STD library
If you completely finished the mandatory part, you can try and turn in the bonuses.

As a bonus, you can turn in the following containers and their associated functions:
* Deque
* Set
* Multiset
* Multimap
