
///============================================================
/// include
///============================================================

// c++
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <type_traits>

///============================================================
/// function
///============================================================
template <typename T>
T Min(T a, T b) {

	return std::min(a, b);
}

template <>
char Min(char a, char b) {

	std::cout << "数字以外は代入できません" << std::endl;
	return 0;
}

///============================================================
/// main
///============================================================
int main() {

	// <typename int>
	int intA = 2;
	int intB = 4;
	std::cout << "Min(int): " << Min(intA, intB) << std::endl;

	// <typename float>
	float floatA = 8.0f;
	float floatB = 4.0f;
	std::cout << "Min(float): " << Min(floatA, floatB) << std::endl;

	// <typename double>
	double doubleA = 3.9812;
	double doubleB = 3.14159;
	std::cout << "Min(double): " << Min(doubleA, doubleB) << std::endl;

	// <typename char>
	char charA = 'a';
	char charB = 'b';
	Min(charA, charB);

	return 0;
}