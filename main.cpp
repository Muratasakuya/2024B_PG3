
///=================================================================================
/// include
///=================================================================================

// c++
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <cassert>

///=================================================================================
/// global variables
///=================================================================================
std::vector<std::vector<int>> mapData; // 読み込んだマップデータ
std::mutex mtx;                        // スレッド間の同期用
bool isDataLoaded = false;             // データが読み込まれたかどうかのフラグ

///=================================================================================
/// functions
///=================================================================================
void LoadCSV(const std::string& filename) {

	std::ifstream file(filename);
	if (!file.is_open()) {
		assert(false);
		return;
	}

	std::string line;
	while (std::getline(file, line)) {

		std::vector<int> row;
		std::istringstream iss(line);
		std::string value;

		while (std::getline(iss, value, ',')) {

			row.push_back(std::stoi(value));
		}

		// スレッドセーフにデータを追加
		std::lock_guard<std::mutex> lock(mtx);
		mapData.push_back(row);
	}

	// 読み込み完了
	isDataLoaded = true;
	file.close();
}

void DisplayMap() {

	while (!isDataLoaded) {
		// データ読み込みが完了するまで待機
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	// データアクセス保護
	std::lock_guard<std::mutex> lock(mtx);
	for (const auto& row : mapData) {
		for (const auto& cell : row) {

			std::cout << cell << " ";
		}
		std::cout << std::endl;
	}
}

///=================================================================================
/// main
///=================================================================================
int main() {

	// CSVファイル名
	const std::string filename = "map.csv";

	// CSVの読み込み
	std::thread loader(LoadCSV, filename);
	// マップの表示
	DisplayMap();

	// スレッド終了待機
	loader.join();

	return 0;
}