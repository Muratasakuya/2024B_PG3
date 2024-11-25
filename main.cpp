
///=================================================================================
/// include
///=================================================================================

// c++
#include <iostream>
#include <list>

//* 駅
struct Station {

	const char* name;
	int yearOpened;
};

//* 駅名表示
void PrintStations(const std::list<Station>& stations, int year) {

	std::cout << year << "年の駅一覧:" << std::endl;
	for (const auto& station : stations) {

		if (station.yearOpened <= year) {
			std::cout << "- " << station.name << std::endl;
		}
	}
}

///=================================================================================
/// main
///=================================================================================
int main() {

	// 駅名リスト
	std::list<Station> stations = {
		{"Tokyo", 1872}, {"Kanda", 1919}, {"Akihabara", 1925}, {"Okachimachi", 1925},
		{"Ueno", 1883}, {"Uguisudani", 1912}, {"Nippori", 1905}, {"Nishi-Nippori", 1971},
		{"Tabata", 1896}, {"Komagome", 1910}, {"Sugamo", 1903}, {"Otsuka", 1903},
		{"Ikebukuro", 1903}, {"Mejiro", 1910}, {"Takadanobaba", 1910}, {"Shin-Okubo", 1914},
		{"Shinjuku", 1885}, {"Yoyogi", 1906}, {"Harajuku", 1906}, {"Shibuya", 1885},
		{"Ebisu", 1906}, {"Meguro", 1906}, {"Gotanda", 1911}, {"Osaki", 1901},
		{"Shinagawa", 1872}, {"Tamachi", 1909}, {"Hamamatsucho", 1909}, {"Shimbashi", 1909},
		{"Yurakucho", 1910}, {"Takanawa Gateway", 2020}
	};

	// 1970年の駅一覧
	std::cout << "------------------" << std::endl;
	PrintStations(stations, 1970);

	// 2019年の駅一覧
	std::cout << "------------------" << std::endl;
	PrintStations(stations, 2019);

	// 2022年の駅一覧
	std::cout << "------------------" << std::endl;
	PrintStations(stations, 2022);

	return 0;

}