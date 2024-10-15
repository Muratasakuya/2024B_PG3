
///============================================================
/// include
///============================================================

// c++
#include <stdio.h>
#include <iostream>
#include <thread>
#include <chrono>

///============================================================
/// function
///============================================================
typedef void (*ResultCallback)(bool);

// サイコロの値をランダムで返す
int RollDice() {

	return rand() % 6 + 1;
}

// ユーザー入力
void UserGuessProcess(int dice, int guess, ResultCallback callBack) {

	bool even = (dice % 2 == 0);
	bool userEven = (guess == 2);

	// 3秒待機する
	std::this_thread::sleep_for(std::chrono::seconds(3));

	// コールバック関数で結果表示
	callBack(even == userEven);
}

// 結果表示
void Result(bool isCorrect) {

	if (isCorrect) {

		std::cout << "正解" << std::endl;
	} else {

		std::cout << "不正解" << std::endl;
	}
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

	// 1か2以外だったらもう一回入力させる
	if (guess != 1 && guess != 2) {

		std::cout << "無効な入力です。1: 奇数, 2: 偶数" << std::endl;
		return 1;
	}

	// 結果処理
	UserGuessProcess(dice, guess, Result);

	return 0;
}