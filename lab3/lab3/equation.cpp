#include "equation.h"

// ������������ �������� ����������� 'a'
void Equation::setA(int new_a) {
    a = new_a;
}

// ��������� �������� ����������� 'a'
int Equation::getA() {
    return a;
}

// ������������ �������� ����������� 'b'
void Equation::setB(int new_b) {
    b = new_b;
}

// ��������� �������� ����������� 'b'
int Equation::getB() {
    return b;
}

// ������������ �������� ����������� 'c'
void Equation::setC(int new_c) {
    c = new_c;
}

// ��������� �������� ����������� 'c'
int Equation::getC() {
    return c;
}

// ���������� ������������ �������
int Equation::findDisc() {
    return b * b - 4 * a * c;
}

// ��������, �� �� ������� ������ �����
bool Equation::hasRealRoot() {
    return findDisc() >= 0;
}

// ������� ��� �������� ���������� ��� �������
void enter_equation(Equation& equation, int equation_index_now) {
    int new_a, new_b, new_c;
    cout << "Enter information about the equation #" << equation_index_now << ": \n";

    cout << "a = ";
    cin >> new_a;
    equation.setA(new_a);

    cout << "b = ";
    cin >> new_b;
    equation.setB(new_b);

    cout << "c = ";
    cin >> new_c;
    equation.setC(new_c);
}

// ������� ��� �������� �������� ������
int input_equations(Equation* all_equations_list) {
    Equation equation;
    int equation_index_now = 1;

    while (true) {
        enter_equation(equation, equation_index_now);

        all_equations_list[equation_index_now - 1] = equation;

        if (check_continue()) {
            cout << "\nAll equations: \n";
            for (int index = 0; index < equation_index_now; index++) {
                cout << all_equations_list[index].getA() << "x^2 + " << all_equations_list[index].getB() << "x + " << all_equations_list[index].getC() << " = 0\n";
            }
            break;
        }

        equation_index_now++;
    }

    return equation_index_now;
}

// Գ�������� ������ �� �������� ������� ������
void filter_by_disc(Equation* all_equations_list, int equations_length) {

    for (int index = 0; index < equations_length; index++) {
        if (!all_equations_list[index].hasRealRoot()) {
            cout << "\nEquation #" << index + 1 << " has no real root" << endl;
        }
    }
}

// ��������, �� ������������ �������� ������
bool check_continue() {
    char continue_flag;

    cout << "\nWould you like to add another equation [y/n]?: ";
    cin >> continue_flag;

    if (continue_flag != 'y' && continue_flag != 'Y') {
        return true;
    }

    return false;
}
