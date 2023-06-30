#include<iostream>
#include<string>


using namespace std;

template<typename T>
struct Node {
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
    T data;
    Node(T data) : data(data) {}
};

template<typename T>
class Iterator {
public:
    Iterator(Node<T>* head) : head(head) {}

    Iterator<T> next() const {
        Iterator<T> temp = *this;
        if (temp.head != nullptr) {
            ++temp;
        }
        return temp;
    }

    Iterator<T> prev() const {
        Iterator<T> temp = *this;
        if (temp.head != nullptr && temp.head->prev != nullptr) {
            --temp;
        }
        return temp;
    }


    Iterator<T> operator++(int var) {
        if (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;

            return temp;
        }

        return nullptr;
    }

    Iterator<T> operator++() {
        if (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            return temp;
        }

        return nullptr;
    }

    Iterator<T> operator--() {
        if (head->prev != nullptr) {
            head = head->prev;

            return head;
        }
    }

    T operator*() {
        return head->data;
    }

    bool operator!=(const Iterator<T>& it) {
        return head != it.head;
    }

private:
    Node<T>* head;
};

template<typename T>
class Deque {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
public:
    // Додає елемент у початок черги
    void push_front(T data) {
        if (head == nullptr) {
            head = new Node<T>(data);
            tail = head;
            return;
        }

        Node<T>* newNode = new Node<T>(data);
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
        current->next->prev = current;
        tail = current->next;
    }
    // Додає елемент у кінець черги
    void push_back(T data) {
        if (head == nullptr) {
            head = new Node<T>(data);
            tail = head;
            return;
        }

        Node<T>* newNode = new Node<T>(data);
        Node<T>* temp = head;
        head = newNode;
        head->next = temp;
        temp->prev = head;
    }
    // Видаляє останній елемент з черги
    void pop_back() {
        if (head == nullptr || head == tail) return;
        Node<T>* temp = head;
        head = temp->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    }
    // Видаляє перший елемент з черги
    void pop_front() {
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node<T>* temp = tail;
            tail = temp->prev;
            tail->next = nullptr;
            delete temp;
        }
    }
    // Очищає чергу
    void clear() {
        Node<T>* current = head;
        Node<T>* temp = nullptr;
        while (current != nullptr) {
            temp = current;
            current = current->next;
            delete temp;
        }

        head = nullptr;
        tail = nullptr;
    }
    // Виводить елементи черги на екран
    void print() const {
        Iterator<T> it = begin();
        while (it != end()) {
            cout << *it << " ";
            ++it;
        }

        cout << std::endl;
    }
    // Виводить на екран поточний елемент, попередній і наступний елементи за заданим індексом
    void printElement(int index) {
        if (index < 0) {
            cout << "Invalid index." << std::endl;
            return;
        }

        Iterator<T> first = begin();
        Iterator<T> last = end();

        int count = 0;
        for (Iterator<T> it = first; it != last; ++it) {
            if (count == index) {
                cout << "Current Element: " << *it << endl;

                if (it != first) {
                    cout << "Previous Element: " << *(it.prev()) << endl;
                }
                else {
                    cout << "Previous Element not exist" << endl;
                }

                Iterator<T> next = it.next();
                if (next != last) {
                    cout << "Next Element: " << *next << endl;
                }
                else {
                    cout << "Next Element not exist" << endl;
                }

                cout << "First Element: " << *begin() << endl;
                cout << "Last Element: " << *rbegin() << endl;

                return;
            }
            count++;
        }
    }

    // Перевіряє, чи черга порожня
    bool empty() const {
        return head == nullptr;
    }
    // Повертає ітератор на перший елемент черги
    Iterator<T> begin() const {
        return Iterator<T>(head);
    }
    // Повертає ітератор, що вказує на кінець черги
    Iterator<T> end() const {
        return Iterator<T>(nullptr);
    }
    // Повертає ітератор на останній елемент черги
    Iterator<T> rbegin() const {
        return Iterator<T>(tail);
    }

    ~Deque() {
        Node<T>* current = head;
        Node<T>* temp = nullptr;
        while (current != nullptr) {
            temp = current;
            current = current->next;
            delete temp;
        }

        head = nullptr;
        tail = nullptr;
    }
};
// Функція для тестування черги з різними типами даних
void test_cases(const string& type) {
    if (type == "int") {
        Deque<int> deque;
        int size;
        cout << "Enter size (up to 20): ";
        cin >> size;
        cout << "Enter " << size << " integer values: ";
        for (int i = 0; i < size; i++) {
            int value;
            cin >> value;
            deque.push_back(value);
        }

        cout << "Deque: ";
        deque.print();
        deque.pop_back();
        cout << "Deque after pop back: ";
        deque.print();
        deque.pop_front();
        std::cout << "Deque after pop front: ";
        deque.print();

        std::cout << "Enter an integer value to push back: ";
        int value;
        std::cin >> value;
        deque.push_back(value);
        std::cout << "Deque after pushing back: ";
        deque.print();
        std::cout << "Enter an integer value to push front: ";
        int value1;
        std::cin >> value1;
        deque.push_front(value1);
        std::cout << "Deque after pushing front: ";
        deque.print();

        int index;
        std::cout << "Enter an index: ";
        std::cin >> index;
        deque.printElement(index);


        std::cout << "Clear called" << std::endl;
        deque.clear();
        std::cout << "Is deque empty? " << deque.empty() << std::endl;
    }
    else if (type == "double") {
        Deque<double> deque;
        int size;
        std::cout << "Enter size (up to 20): ";
        std::cin >> size;
        std::cout << "Enter " << size << " double values: ";
        for (int i = 0; i < size; i++) {
            double value;
            std::cin >> value;
            deque.push_back(value);
        }

        std::cout << "Deque: ";
        deque.print();
        deque.pop_back();
        std::cout << "Deque after pop back: ";
        deque.print();
        deque.pop_front();
        std::cout << "Deque after pop front: ";
        deque.print();

        std::cout << "Enter an double value to push back: ";
        double value;
        std::cin >> value;
        deque.push_back(value);
        std::cout << "Deque after pushing back: ";
        deque.print();
        std::cout << "Enter an double value to push front: ";
        double value1;
        std::cin >> value1;
        deque.push_front(value1);
        std::cout << "Deque after pushing front: ";
        deque.print();

        int index;
        std::cout << "Enter an index: ";
        std::cin >> index;
        deque.printElement(index);

        std::cout << "Clear called" << std::endl;
        deque.clear();
        std::cout << "Is deque empty? " << deque.empty() << std::endl;
    }
    else if (type == "string") {
        Deque<std::string> deque;
        int size;
        std::cout << "Enter size (up to 20): ";
        std::cin >> size;
        std::cout << "Enter " << size << " string values: ";
        for (int i = 0; i < size; i++) {
            std::string value;
            std::cin >> value;
            deque.push_back(value);
        }

        std::cout << "Deque: ";
        deque.print();
        deque.pop_back();
        std::cout << "Deque after pop back: ";
        deque.print();
        deque.pop_front();
        std::cout << "Deque after pop front: ";
        deque.print();

        std::cout << "Enter an string value to push back: ";
        std::string value;
        std::cin >> value;
        deque.push_back(value);
        std::cout << "Deque after pushing back: ";
        deque.print();
        std::cout << "Enter an string value to push front: ";
        std::string value1;
        std::cin >> value1;
        deque.push_front(value1);
        std::cout << "Deque after pushing front: ";
        deque.print();

        int index;
        std::cout << "Enter an index: ";
        std::cin >> index;
        deque.printElement(index);

        std::cout << "Clear called" << std::endl;
        deque.clear();
        std::cout << "Is deque empty? " << deque.empty() << std::endl;
    }
}

