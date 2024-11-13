
///=================================================================================
/// include
///=================================================================================
// objects
#include <Classes/Enemy.h>

// c++
#include <stdio.h>
#include <memory>
#include <chrono>
#include <thread> 

///=================================================================================
/// main
///=================================================================================
int main() {

	std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>();

	auto startTime = std::chrono::steady_clock::now();
	auto lastTime = startTime;
	const std::chrono::seconds phaseDuration(2); // 2秒おき
	const std::chrono::seconds maxDuration(8);   // 8秒後閉じる

	while (true) {

		auto currentTime = std::chrono::steady_clock::now();

		if (currentTime - startTime >= maxDuration) {
			break;
		}

		// 時間経過で切り替え
		if (currentTime - lastTime >= phaseDuration) {

			enemy->Update();
			lastTime = currentTime;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(50));

	}

	return 0;
}