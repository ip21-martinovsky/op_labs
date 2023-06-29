#include "boolvector.h"

BoolVector::BoolVector() {
	this->X;
	this->Y;
	this->Z;
}

BoolVector::BoolVector(bool v1, bool v2, bool v3) {
	this->X = v1;
	this->Y = v2;
	this->Z = v3;

	this->cord[0] = X;
	this->cord[1] = Y;
	this->cord[2] = Z;
}

// Перевантаження оператора OR (|) для виконання побітової операції OR над координатами
BoolVector BoolVector::operator|(BoolVector& other) {
	BoolVector temp;

	temp.cord[0] = this->cord[0] || other.cord[0];
	temp.cord[1] = this->cord[1] || other.cord[1];
	temp.cord[2] = this->cord[2] || other.cord[2];

	temp.X = cord[0];
	temp.Y = cord[1];
	temp.Z = cord[2];

	return temp;
}

// Перевантаження оператора XOR (^) для виконання побітової операції XOR над координатами
BoolVector BoolVector::operator^(BoolVector& other) {
	BoolVector temp;

	temp.cord[0] = (this->cord[0] || other.cord[0]) && !(this->cord[0] && other.cord[0]);
	temp.cord[1] = (this->cord[1] || other.cord[1]) && !(this->cord[1] && other.cord[1]);
	temp.cord[2] = (this->cord[2] || other.cord[2]) && !(this->cord[2] && other.cord[2]);

	temp.X = cord[0];
	temp.Y = cord[1];
	temp.Z = cord[2];

	return temp;
}

// Оновлення масиву cord зі значеннями координат
void BoolVector::setCord() {
	this->cord[0] = X;
	this->cord[1] = Y;
	this->cord[2] = Z;
}


// Встановлення значень координат
void BoolVector::setXYZ(bool value1, bool value2, bool value3) {
	this->X = value1;
	this->Y = value2;
	this->Z = value3;
	setCord();
}


// Перевірка, чи є поточний вектор передником іншого вектора
bool BoolVector::is_predecessor(BoolVector& other) {
	if (this->cord[0] >= other.cord[0] || this->cord[1] >= other.cord[1] || this->cord[2] >= other.cord[2]) {
		return false;
	}
	return true;
}

// Виведення значень координат
void BoolVector::printCord() {
	cout << "(" << cord[0] << ";" << cord[1] << ";" << cord[2] << ")" << endl;
}

BoolVector::~BoolVector() {}