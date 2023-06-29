#include <iostream>
#include "pointer.h"
#include "stream.h"
#include "util.h"

/*
	16. Створити текстовий файл. Слова у тексті відділені пробілами, комами, крапками.
	У кожному рядку даного тексту визначити найдовшу послідовність підряд йдучих однакових символів.
	Переставити слова, що містять знайдені послідовності, на початок відповідного рядка.
	Якщо таких слів у рядку декілька, то переставити ці слова на початок у порядку їхнього слідування у рядку.
	Усі змінені рядки вхідного файлу переписати у новий текстовий файл.
	Видалити у словах нового текстового файлу всі символи-дублікати, обмеживши фігурними дужками символ, що повторюється.
	Наприклад, слово abccccd повинно бути змінене на слово ab{c} d. Вивести вміст вхідного і створеного файлів.
*/

using namespace std;

int main(int argc, char* argv[]) {
	// Встановити режим на основі аргументів командного рядка
	int mode = set_mode(argc, argv);

	if (mode == -1) {
		cout << "The mode is incorrect" << endl; // Неправильно вказано режим
		return 1;
	}

	if (mode == 1) {
		cout << "Pointers mode" << endl; // Режим з використанням вказівників на файли
		// Ввести імена вхідного та вихідного файлів
		char* filein = FP_enter_name();
		FP_write_to_file(filein);
		char* fileout = FP_enter_name();

		// Вивести вміст вхідного файлу
		FP_print_file(filein);

		// Зчитати текст з вхідного файлу
		char* str1 = FP_read_text(filein);

		// Виконати потрібні операції над файлом
		FP_work_file(str1, fileout);

		// Вивести вміст вихідного файлу
		FP_print_file(fileout);

		// Зчитати змінений текст з вихідного файлу
		char* str = FP_read_text(fileout);

		// Замінити повторювані символи у словах дужками
		FP_replaceDuplicatesWithBrackets(str, fileout);

		// Вивести кінцевий вміст вихідного файлу
		FP_print_file(fileout);
	}
	else if (mode == 2) {
		cout << "Stream mode" << endl; // Режим з використанням потоків
		// Ввести імена вхідного та вихідного файлів
		string file1 = enter_name();
		write_to_file(file1);

		string fileout = enter_name();

		// Вивести вміст вхідного файлу
		print_file(file1);

		// Зчитати текст з вхідного файлу
		string str = read_file(file1);
		// Виконати потрібні операції над файлом
		work_file(str, fileout);
		// Вивести вміст вихідного файлу
		print_file(fileout);

		// Зчитати змінений текст з вихідного файлу
		string interm = read_file(fileout);
		// Замінити повторювані символи у словах дужками
		string result = replaceDuplicatesWithBrackets(interm);
		// Додати змінений текст до вихідного файлу
		add_data_to_file(fileout, result);
		// Вивести кінцевий вміст вихідного файлу
		print_file(fileout);
	}

	return 0;
}
