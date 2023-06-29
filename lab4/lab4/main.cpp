#include "boolvector.h"

int main()
{
	// Створення об'єктів класу BoolVector і використання їх методів
	BoolVector v1;
	v1.setXYZ(true, true, true);
	cout << "Vector 1 cordinates: ";
	v1.printCord();

	BoolVector v2(true, false, true);
	cout << "Vector 2 cordinates: ";
	v2.printCord();

	BoolVector v3 = v1 | v2; // Диз'юнкція
	cout << "Vector 3 cordinates: ";
	v3.printCord();

	BoolVector v4 = v3 ^ v1; // Виключаюче АБО
	cout << "Vector 4 cordinates: ";
	v4.printCord();

	cout << "Vector 4 is precursor of Vector 3? " << v4.is_predecessor(v3) << endl;

	return 0;
}