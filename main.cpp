
///============================================================
/// include
///============================================================

// c++
#include <stdio.h>
#include <iostream>
#include <functional>
#include <thread>
#include <chrono>
#include <future> 

///============================================================
/// function
///============================================================

// サイコロの値をランダムで返す
int RollDice() {

	return rand() % 6 + 1;
}

void SetTimeout(int second) {

	std::this_thread::sleep_for(std::chrono::seconds(second));
}

///============================================================
/// main
///============================================================
int main() {

	// 乱数初期化
	srand(static_cast<uint32_t>(time(0)));

	// サイコロ
	int dice = RollDice();

	// ユーザーに入力させる
	std::cout << "サイコロの出目は偶数か奇数どっちでしょうか？？ 1: 奇数, 2: 偶数";
	int guess;
	std::cin >> guess;

	// ラムダ式で入力された値をキャプチャして使う
	auto isOdd = [](int number) -> bool { return number % 2 != 0; };
	bool userGuessedOdd = (guess == 1);

	// 3秒待機
	SetTimeout(3);

	// boolラムダ関数で判別
	bool actualOdd = isOdd(dice);

	// 結果表示
	if ((userGuessedOdd && actualOdd) || (!userGuessedOdd && !actualOdd)) {

		std::cout << "正解" << std::endl;
	} else {

		std::cout << "不正解" << std::endl;
	}
	std::cout << "サイコロの出目: " << dice << std::endl;

	return 0;
}