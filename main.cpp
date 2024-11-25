
///=================================================================================
/// include
///=================================================================================

// c++
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

///=================================================================================
/// main
///=================================================================================
int main() {

	// txtファイルパス
	const std::string filePath = "PG3_2024_03_02.txt";
	std::ifstream inputFile(filePath);

	std::vector<std::string> emails;

	std::string line;
	while (std::getline(inputFile, line)) {

		// コンマ区切りで追加
		std::stringstream ss(line);
		std::string email;
		while (std::getline(ss, email, ',')) {

			emails.push_back(email);
		}
	}
	inputFile.close();

	// 若い順
	std::sort(emails.begin(), emails.end());

	std::cout << "学籍番号順: " << std::endl;
	for (const auto& email : emails) {

		std::cout << email << std::endl;
	}

	return 0;

}