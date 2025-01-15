
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& other) : dataVec(other.dataVec), dataDeq(other.dataDeq)
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other) {
		dataVec = other.dataVec;
		dataDeq = other.dataDeq;
	}
	return *this;
}

void PmergeMe::mergeSortHelper(std::vector<int>& container, int left, int right) {
	if (left >= right) return;

	int mid = left + (right - left) / 2;
	mergeSortHelper(container, left, mid);
	mergeSortHelper(container, mid + 1, right);
	merge(container, left, mid, right);
}
void PmergeMe::mergeSortHelperDeque(std::deque<int>& container, int left, int right) {
	if (left >= right) return;

	int mid = left + (right - left) / 2;
	mergeSortHelperDeque(container, left, mid);
	mergeSortHelperDeque(container, mid + 1, right);
	mergeDeque(container, left, mid, right);
}

void PmergeMe::merge(std::vector<int>& container, int left, int mid, int right) {
	std::vector<int> temp(right - left + 1);
	int i = left, j = mid + 1, k = 0;

	while (i <= mid && j <= right) {
		if (container[i] <= container[j]) {
			temp[k++] = container[i++];
		} else {
			temp[k++] = container[j++];
		}
	}

	while (i <= mid)
		temp[k++] = container[i++];
	while (j <= right)
		temp[k++] = container[j++];
	std::copy(temp.begin(), temp.end(), container.begin() + left);
}

void PmergeMe::mergeDeque(std::deque<int>& container, int left, int mid, int right) {
	std::deque<int> temp(right - left + 1);
	int i = left, j = mid + 1, k = 0;

	while (i <= mid && j <= right) {
		if (container[i] <= container[j]) {
			temp[k++] = container[i++];
		} else {
			temp[k++] = container[j++];
		}
	}

	while (i <= mid)
		temp[k++] = container[i++];
	while (j <= right)
		temp[k++] = container[j++];
	std::copy(temp.begin(), temp.end(), container.begin() + left);
}

void PmergeMe::recursiveMergeSortVector(std::vector<int>& container) {
	if (container.size() < 2) return;
	mergeSortHelper(container, 0, container.size() - 1);
}
void PmergeMe::recursiveMergeSortDeque(std::deque<int>& container) {
	if (container.size() < 2) return;
	mergeSortHelperDeque(container, 0, container.size() - 1);
}


double PmergeMe::sortAndTimeVector(std::vector<int>& container) {
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	recursiveMergeSortVector(container);
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	return std::chrono::duration<double, std::micro>(end - start).count();
}

double PmergeMe::sortAndTimeDeque(std::deque<int>& container) {
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	recursiveMergeSortDeque(container);
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	return std::chrono::duration<double, std::micro>(end - start).count();
}


void PmergeMe::sortAndDisplayResults() {
	std::cout << "Before: ";
	displayContainer(dataVec);

	double timeVec = sortAndTimeVector(dataVec);
	double timeDeq = sortAndTimeDeque(dataDeq);

	std::cout << "After: ";
	displayContainer(dataVec);
	std::cout << "Time to process a range of " << dataVec.size() << " elements with std::vector: " << timeVec << " us\n";
	std::cout << "Time to process a range of " << dataDeq.size() << " elements with std::deque: " << timeDeq << " us\n";
}

void PmergeMe::displayContainer(const std::vector<int>& container) const {
	for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "\n";
}

void PmergeMe::parseInput(int argc, char** argv) {
	for (int i = 1; i < argc; ++i) {
		int value;
		std::istringstream iss(argv[i]);
		if (!(iss >> value) || value < 0) {
			throw std::runtime_error("Error: invalid input");
		}
		dataVec.push_back(value);
		dataDeq.push_back(value);
	}
}
