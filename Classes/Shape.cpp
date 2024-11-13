#include "Shape.h"

///=================================================================================
/// Circle classMethods
///=================================================================================

void Circle::Size() {

	area_ = std::numbers::pi_v<float> *radius_ * radius_;
}

void Circle::Draw() {

	std::cout << "CircleSize: " << area_ << std::endl;
}

void Rectangle::Size() {

	area_ = width_ * height_;
}

void Rectangle::Draw() {

	std::cout << "RectangleSize: " << area_ << std::endl;
}