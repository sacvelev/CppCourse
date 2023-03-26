#include <iostream>
#include <string>
using namespace std;

// Структура элемента списка
struct Work {
    string name; //
    int age; //
    double salary; //
    Work* next;
};

// Класс списка
class List {
    private:
        Work* head;
    public:
        List(){
            head = NULL;
        }

        ~List(){
            Work* current = head;
            while (current != NULL){
                Work* next = current->next;
                delete current;
                current = next;
            }
            head = NULL;
        }

        // Добавление в начало
        void addStart(string name, int age, double salary) {
            Work* newWork = new Work;
            newWork->name = name;
            newWork->age = age;
            newWork->salary = salary;
            newWork->next = head;
            head = newWork;
        }

        // Добавление в конец
        void addEnd(string name, int age, double salary) {
            Work* newWork = new Work;
            newWork->name = name;
            newWork->age = age;
            newWork->salary = salary;
            newWork->next = NULL;
            if (head == NULL) {
                head = newWork;
                return;
            }
            Work* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newWork;
        }

        // Добавление после заданного элемента
        void addAfter(string nameAfter, string name, int age, double salary) {
            Work *current = head;
            while (current != NULL) {
                if (current->name == nameAfter) {
                    Work *newWork = new Work;
                    newWork->name = name;
                    newWork->age = age;
                    newWork->salary = salary;
                    newWork->next = current->next;
                    current->next = newWork;
                }
                current = current->next;
            }
            cout << "NOT FOUND" << endl;
        }
        // Добавление перед заданным элементом
        void addBefore(string nameBefore, string name, int age, double salary) {
            if (head == NULL) {
                cout << "EMPTY" << endl;
                return;
            }
            if (head->name == nameBefore) {
                Work *newWork = new Work;
                newWork->name = name;
                newWork->age = age;
                newWork->salary = salary;
                newWork->next = head;
                head = newWork;
            }
            Work* current = head;
            while (current->next != NULL) {
                if (current->next->name == nameBefore) {
                    Work *newWork = new Work;
                    newWork->name = name;
                    newWork->age = age;
                    newWork->salary = salary;
                    newWork->next = current->next;
                    current->next = newWork;
                    return;
                }
                current = current ->next;
            }
            cout << "NOT FOUND" << endl;
        }

        // Удаление элемента
        void remove(string name) {
            if (head == NULL) {
                cout << "EMPTY" << endl;
                return;
            }
            if (head->name == name) {
                Work* current = head;
                head = head->next;
                delete current;
                return;
            }
            Work* current = head;
            while (current->next != NULL) {
                if (current->next->name == name) {
                    Work *removeWork = current->next;
                    current->next = current->next->next;
                    delete removeWork;
                    return;
                }
                current = current->next;
            }
            cout << "NOT FOUND" << endl;
            }

        // Вывод
        void display() {
            if (head == NULL) {
                cout << "EMPTY" << endl;
                return;
            }
            Work* current = head;
            while (current != NULL) {
                cout << "\tName: " << current->name << "\tAge: " << current->age << "\tSalary: " << current->salary << endl;
                current = current->next;
        }
            }

};


int main() {
    List list;
    //Добавление элементов
    list.addStart("Mark", 18, 2000.0);
    list.addStart("Cesar", 20, 2300.0);
    list.addStart("Gabriel", 30, 3000.0);

    list.addEnd("Adam", 24, 2400.0);
    list.addEnd("Jonah", 23, 2600.0);

    list.addAfter("Mark", "Lynn", 36, 3000.0);
    list.addAfter("Adam", "Jude", 39, 3200.0);

    list.addBefore("Jonah", "Thatcher", 25, 2600.0);
    list.addBefore("Jude", "Noah", 45, 3000.0);

    //Вывод элементов
    cout << "Workers:" << endl;
    list.display();

    //Удаление элементов
    list.remove("Gabriel");
    list.remove("Noah");
    list.remove("Cesar");

    //Вывод измененного списка
    cout << "Workers after removal:" << endl;
    list.display();

return 0;
}
