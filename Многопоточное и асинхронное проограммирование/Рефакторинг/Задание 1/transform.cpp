#include "transform.h"
#include <stdexcept>

Scale::Scale(const int& divider) : divider(divider) {
	if (divider <= 0) {
		throw std::invalid_argument("divider <= 0");
	}
}

void Scale::apply(Shape& shape) const { shape.scale(divider); };

ScaleX::ScaleX(int x) : x(x) {}

void ScaleX::apply(Shape& shape) const {
	if (shape.getType() == ShapeType::_2D) {
		static_cast<Shape2D&>(shape).scaleX(x);
	}
	if (shape.getType() == ShapeType::_3D) {
		static_cast<Shape2D&>(shape).scaleX(x);
	}
};

ScaleY::ScaleY(int y) : y(y) {}

void ScaleY::apply(Shape& shape) const {
	
	if (shape.getType() == ShapeType::_2D) {
		static_cast<Shape2D&>(shape).scaleY(y);
	}
	else {
		static_cast<Shape3D&>(shape).scaleY(y);
	}
};

ScaleZ::ScaleZ(int z) : z(z) {}

void ScaleZ::apply(Shape& shape) const {
	if (shape.getType() == ShapeType::_3D) {
		static_cast<Shape2D&>(shape).scaleY(z);
	}
};
