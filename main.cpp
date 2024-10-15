
///============================================================
/// include
///============================================================

// c++
#include <stdio.h>
#include <iostream>

///============================================================
/// function
///============================================================
int CalRecursiveWage(int h, int currentWage, int baseWage) {

	if (h == 1) {

		return currentWage;
	}

	return CalRecursiveWage(h - 1, currentWage, baseWage) * 2 - baseWage;
}

int CalTotalRecursiveWage(int h, int initWage, int baseWage) {

	if (h == 1) {

		return initWage;
	}

	return CalTotalRecursiveWage(h - 1, initWage, baseWage) + CalRecursiveWage(h, initWage, baseWage);
}

///============================================================
/// main
///============================================================
int main() {

	// 一般的な賃金体系の時給
	const int normalWage = 1072;

	// 再帰的な賃金体系の初期時給と増加係数
	const int initRecursiveWage = 100;
	const int baseWage = 50;

	int totalNormalWage = 0;
	int totalRecursiveWage = 0;

	// 再帰的な賃金が一般的な賃金よりも多くなるまで
	int hour = 0;
	while (true) {

		hour++;

		// 一般的な賃金体系の累計
		totalNormalWage += normalWage;

		// 再帰的な賃金体系の累計
		totalRecursiveWage = CalTotalRecursiveWage(hour, initRecursiveWage, baseWage);

		// 再帰的な賃金が一般的な賃金を超えたら
		if (totalRecursiveWage > totalNormalWage) {

			std::cout << " 再帰的な賃金が一般的な賃金を超えた " << hour << " hours" << std::endl;
			break;
		}
	}

	return 0;
}