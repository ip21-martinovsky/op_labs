#include <iostream>
#include "pointer.h"
#include "stream.h"
#include "util.h"

/*
	16. �������� ��������� ����. ����� � ����� ������ ��������, ������, ��������.
	� ������� ����� ������ ������ ��������� �������� ����������� ����� ������ ��������� �������.
	����������� �����, �� ������ ������� �����������, �� ������� ���������� �����.
	���� ����� ��� � ����� �������, �� ����������� �� ����� �� ������� � ������� ������� ��������� � �����.
	�� ����� ����� �������� ����� ���������� � ����� ��������� ����.
	�������� � ������ ������ ���������� ����� �� �������-��������, ��������� ��������� ������� ������, �� ������������.
	���������, ����� abccccd ������� ���� ������ �� ����� ab{c} d. ������� ���� �������� � ���������� �����.
*/

using namespace std;

int main(int argc, char* argv[]) {
	// ���������� ����� �� ����� ��������� ���������� �����
	int mode = set_mode(argc, argv);

	if (mode == -1) {
		cout << "The mode is incorrect" << endl; // ����������� ������� �����
		return 1;
	}

	if (mode == 1) {
		cout << "Pointers mode" << endl; // ����� � ������������� ��������� �� �����
		// ������ ����� �������� �� ��������� �����
		char* filein = FP_enter_name();
		FP_write_to_file(filein);
		char* fileout = FP_enter_name();

		// ������� ���� �������� �����
		FP_print_file(filein);

		// ������� ����� � �������� �����
		char* str1 = FP_read_text(filein);

		// �������� ������ �������� ��� ������
		FP_work_file(str1, fileout);

		// ������� ���� ��������� �����
		FP_print_file(fileout);

		// ������� ������� ����� � ��������� �����
		char* str = FP_read_text(fileout);

		// ������� ���������� ������� � ������ �������
		FP_replaceDuplicatesWithBrackets(str, fileout);

		// ������� ������� ���� ��������� �����
		FP_print_file(fileout);
	}
	else if (mode == 2) {
		cout << "Stream mode" << endl; // ����� � ������������� ������
		// ������ ����� �������� �� ��������� �����
		string file1 = enter_name();
		write_to_file(file1);

		string fileout = enter_name();

		// ������� ���� �������� �����
		print_file(file1);

		// ������� ����� � �������� �����
		string str = read_file(file1);
		// �������� ������ �������� ��� ������
		work_file(str, fileout);
		// ������� ���� ��������� �����
		print_file(fileout);

		// ������� ������� ����� � ��������� �����
		string interm = read_file(fileout);
		// ������� ���������� ������� � ������ �������
		string result = replaceDuplicatesWithBrackets(interm);
		// ������ ������� ����� �� ��������� �����
		add_data_to_file(fileout, result);
		// ������� ������� ���� ��������� �����
		print_file(fileout);
	}

	return 0;
}
