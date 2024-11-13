
///=================================================================================
/// include
///=================================================================================
// classes
#include <Classes/Car.h>

// c++
#include <stdio.h>
#include <iostream>
#include <memory>

///=================================================================================
/// main
///=================================================================================
int main() {

	std::unique_ptr<ICar> gasolineCar = std::make_unique<GasolineCar>();
	std::unique_ptr<ICar> electricCar = std::make_unique<ElectricCar>();
	std::unique_ptr<ICar> hybridCar = std::make_unique<HybridCar>();

	std::cout << "ガソリン車: ";
	gasolineCar->DriveSound();

	std::cout << "電気自動車: ";
	electricCar->DriveSound();

	std::cout << "ハイブリッド車: ";
	hybridCar->DriveSound();

	return 0;
}