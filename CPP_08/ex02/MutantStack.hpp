#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
	typedef typename Container::iterator iterator;
	typedef typename Container::reverse_iterator reverse_iterator;

	MutantStack();
	MutantStack(const MutantStack<T, Container>& other);
	~MutantStack();

	MutantStack<T, Container>& operator=(const MutantStack<T, Container>& other);

	iterator begin();
	reverse_iterator rbegin();
	iterator end();
	reverse_iterator rend();
};

#include "MutantStack.tpp"

#endif
