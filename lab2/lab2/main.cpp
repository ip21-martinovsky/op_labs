#include "ampule.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

/*	�������� ���� �� ������� ��������� ����� : �����, ����� 䳿 ���� ��������(�� �������� - ��:��),
	����� ��������� ������������� ������(� �����).
	�������� ���������� ��� ������, ����� ��������� ���� ��������� ���� ��.
	������ ������������ ��� ��������� ������ ��������� ������ �� 10 ���.
*/

int main() {

	string filename = get_filename();

	append_file(filename);

	read_data(filename);
}
