
///=================================================================================
/// include
///=================================================================================

// c++
#include <iostream>
#include <string>
#include <chrono>

///=================================================================================
/// main
///=================================================================================
int main() {

	std::string a(1000000, 'a');

	// コピーにかかる時間
	auto startCopy = std::chrono::high_resolution_clock::now();
	std::string b = a;
	auto endCopy = std::chrono::high_resolution_clock::now();

	// 移動にかかる時間
	auto startMove = std::chrono::high_resolution_clock::now();
	std::string c = std::move(a); 
	auto endMove = std::chrono::high_resolution_clock::now();

	// 結果出力
	auto copyDuration = std::chrono::duration_cast<std::chrono::microseconds>(endCopy - startCopy).count();
	auto moveDuration = std::chrono::duration_cast<std::chrono::microseconds>(endMove - startMove).count();

	std::cout << "コピーにかかった時間: " << copyDuration << " μs" << std::endl;
	std::cout << "移動にかかった時間: " << moveDuration << " μs" << std::endl;

	return 0;
}