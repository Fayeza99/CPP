#include "iter.hpp"


int main() {
	int arr[] = {1, 2, 3, 4, 5};
	size_t arrLength = sizeof(arr) / sizeof(arr[0]);
	
	std::cout << "Original array:" << std::endl;
	iter(arr, arrLength, print);
	
	iter(arr, arrLength, increment);
	
	std::cout << "Array after incrementing each element:" << std::endl;
	iter(arr, arrLength, print);
	
	char charArr[] = "hello world!";
	size_t charArrLength = sizeof(charArr) / sizeof(charArr[0]) - 1;
	
	std::cout << "\nOriginal char array:" << std::endl;
	iter(charArr, charArrLength, print);
	
	iter(charArr, charArrLength, toUppercase);
	
	std::cout << "Char array after converting to uppercase:" << std::endl;
	iter(charArr, charArrLength, print);
	
	return 0;
}
