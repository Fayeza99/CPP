#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <sstream>
#include <chrono>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <deque>
#include <iostream>

class PmergeMe
{
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe& operator=(const PmergeMe& other);
	PmergeMe(const PmergeMe &other);

	void recursiveMergeSortVector(std::vector<int>& container);
	void recursiveMergeSortDeque(std::deque<int>& container);

	double sortAndTimeVector(std::vector<int>& container);
	double sortAndTimeDeque(std::deque<int>& container);

	void sortAndDisplayResults();
	void parseInput(int argc, char** argv);


private:
	std::vector<int> dataVec;
	std::deque<int> dataDeq;


	void mergeSortHelper(std::vector<int>& container, int left, int right);
	void mergeSortHelperDeque(std::deque<int>& container, int left, int right);
	void merge(std::vector<int>& container, int left, int mid, int right);
	void mergeDeque(std::deque<int>& container, int left, int mid, int right);

	void insertionSort(std::deque<int>& container);
	void displayContainer(const std::vector<int>& container) const;

};


#endif