#include <iostream>

struct Node {
    double data;
    Node* next;
    Node* prev;

    Node(double value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() : head(nullptr) {}

    // Додавання елементів до списку
    void append(double value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Обчислення середнього значення елементів <= 15
    double calculateAverage() {
        Node* temp = head;
        double sum = 0.0;
        int count = 0;

        while (temp) {
            if (temp->data <= 15) {
                sum += temp->data;
                count++;
            }
            temp = temp->next;
        }

        return (count > 0) ? (sum / count) : 0.0;
    }

    // Видалення елементів > 25
    void removeGreaterThanTwentyFive() {
        Node* temp = head;
        while (temp) {
            if (temp->data > 25) {
                if (temp->prev) {
                    temp->prev->next = temp->next;
                }
                else {
                    head = temp->next; // Якщо видаляємо перший елемент
                }
                if (temp->next) {
                    temp->next->prev = temp->prev;
                }
                Node* toDelete = temp;
                temp = temp->next; // Зберігаємо наступний вузол
                delete toDelete;
                continue; // Повертаємося на попередню позицію
            }
            temp = temp->next;
        }
    }

    // Вивід елементів списку
    void print() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Деструктор для очищення пам'яті
    ~DoublyLinkedList() {
        Node* temp = head;
        while (temp) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    DoublyLinkedList list;
    double arr[] = { 12.5, 20.3, 15.0, 30.1, 10.0, 27.8, 14.5, 35.0 };

    // Додаємо елементи до списку
    for (double value : arr) {
        list.append(value);
    }

    std::cout << "List: ";
    list.print();

    // Обчислення середнього значення
    double average = list.calculateAverage();
    std::cout << "Average eements <= 15: " << average << std::endl;

    // Видалення елементів > 25
    list.removeGreaterThanTwentyFive();
    std::cout << "List after delete numbers that > 25: ";
    list.print();

    return 0;
}
