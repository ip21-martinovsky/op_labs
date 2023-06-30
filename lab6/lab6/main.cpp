#include <iostream>
#include "deque.h"

using namespace std;

int main() {
    string type;
    cout << "Enter type (int, double, string): ";
    cin >> type;
    test_cases(type);

    return 0;
}