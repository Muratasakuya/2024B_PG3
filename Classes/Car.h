#pragma once

///=================================================================================
/// include
///=================================================================================
// c++
#include <iostream>
#include <vector>

///=================================================================================
/// ICar interfaceClass
///=================================================================================
class ICar {
public:

	///=================================================================================
	/// public Methods
	///=================================================================================

	virtual ~ICar() {}

	virtual void DriveSound() const = 0;

};

///===============================-==================================================
/// Car derivedClasses
///=================================================================================

class GasolineCar
	: public ICar {
public:

	void DriveSound() const override {
		std::cout << "ゴロゴロゴロ... ブルンブルン！" << std::endl;
	}
};

class ElectricCar
	: public ICar {
public:

	void DriveSound() const override {
		std::cout << "シューン..." << std::endl;
	}
};

class HybridCar
	: public ICar {
public:

	void DriveSound() const override {
		std::cout << "シューン... ブルンブルン！" << std::endl;
	}

};