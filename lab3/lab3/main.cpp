#include "equation.h" 

/*
    Розробити клас "квадратне рівняння"(многочлен виду ax^2 + bx + c = 0),
    який заданий своїми коефіцієнтами. Створити масив об'єктів даного класу.
    Визначити рівяння(їх номери), які не мають дійсних розв'язків.
*/

int main() {
    Equation all_equations_list[256];

    int equations_length = input_equations(all_equations_list);  // Виклик функції для заповнення масиву та отримання його довжини

    filter_by_disc(all_equations_list, equations_length);  // Виклик функції для фільтрації масиву
}
