
///=================================================================================
/// include
///=================================================================================
// classes
#include <Classes/Shape.h>

// c++
#include <stdio.h>
#include <iostream>
#include <memory>

///=================================================================================
/// main
///=================================================================================
int main() {

	std::vector<std::unique_ptr<IShape>> shapes;

	shapes.push_back(std::make_unique<Circle>(5.0));
	shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));

	for (const auto& shape : shapes) {

		shape->Size();
		shape->Draw();
	}

	return 0;

}