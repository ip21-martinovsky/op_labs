#include "equation.h" 

/*
    ��������� ���� "��������� �������"(��������� ���� ax^2 + bx + c = 0),
    ���� ������� ����� �������������. �������� ����� ��'���� ������ �����.
    ��������� ������(�� ������), �� �� ����� ������ ����'����.
*/

int main() {
    Equation all_equations_list[256];

    int equations_length = input_equations(all_equations_list);  // ������ ������� ��� ���������� ������ �� ��������� ���� �������

    filter_by_disc(all_equations_list, equations_length);  // ������ ������� ��� ���������� ������
}
