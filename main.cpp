
///=================================================================================
/// include
///=================================================================================

// c++
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int current = 1;

/// <summary>
/// スレッドごとに呼び出す
/// </summary>
void PrintThread(int id, const std::string& message) {

	std::unique_lock<std::mutex> lock(mtx);

	cv.wait(lock, [id]() { return current == id; });

	// 文字出力
	std::cout << message << std::endl;

	current++;
	cv.notify_all();
}

///=================================================================================
/// main
///=================================================================================
int main() {

	std::thread t1(PrintThread, 1, "thread 1");
	std::thread t2(PrintThread, 2, "thread 2");
	std::thread t3(PrintThread, 3, "thread 3");

	t1.join();
	t2.join();
	t3.join();

	return 0;
}