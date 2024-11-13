
///=================================================================================
/// include
///=================================================================================
// objects
#include <Classes/Comparator.h>

// c++
#include <stdio.h>
#include <iostream>
#include <memory>
#include <chrono>
#include <thread> 

///=================================================================================
/// main
///=================================================================================
int main() {

	std::cout << "int and int: " << Comparator<int, int>::Min(5, 10) << std::endl;
	std::cout << "int and float: " << Comparator<int, float>::Min(5, 10.5f) << std::endl;
	std::cout << "int and double: " << Comparator<int, double>::Min(5, 10.5) << std::endl;
	std::cout << "float and float: " << Comparator<float, float>::Min(5.5f, 10.5f) << std::endl;
	std::cout << "float and double: " << Comparator<float, double>::Min(5.5f, 10.5) << std::endl;
	std::cout << "double and double: " << Comparator<double, double>::Min(5.5, 10.5) << std::endl;

	return 0;
}