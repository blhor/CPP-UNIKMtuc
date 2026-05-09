#include <iostream>
#include <string>
#include <algorithm>

class Student {
private:
    std::string surnameInitial;
    int numberGroup;
    int grades[5];

public:
    Student() : numberGroup(0) {
        for (int i = 0; i < 5; i++) grades[i] = 0;
    }

    Student(const std::string& name, int group, const int g[5])
        : surnameInitial(name), numberGroup(group) {
        for (int i = 0; i < 5; i++) grades[i] = g[i];
    }

    // Геттеры
    std::string getSurnameInitial() const { return surnameInitial; }
    int getNumberGroup() const { return numberGroup; }
    int getGrade(int index) const { return grades[index]; }

    // Сеттеры
    void setSurnameInitial(const std::string& name) { surnameInitial = name; }
    void setNumberGroup(int group) { numberGroup = group; }
    void setGrade(int index, int value) { grades[index] = value; }

    double getAverage() const {
        int sum = 0;
        for (int i = 0; i < 5; i++) sum += grades[i];
        return (double)sum / 5;
    }

    bool isExcellent() const {
        for (int i = 0; i < 5; i++)
            if (grades[i] < 4) return false;
        return true;
    }

    void input(int index) {
        std::cout << "Студент " << index + 1 << ":\n";
        std::cout << "Фамилия и инициалы: ";
        std::getline(std::cin, surnameInitial);
        std::cout << "Номер группы: ";
        std::cin >> numberGroup;
        std::cout << "5 оценок: ";
        for (int i = 0; i < 5; i++) std::cin >> grades[i];
        std::cin.ignore();
    }

    void print() const {
        std::cout << surnameInitial << " (гр. " << numberGroup
            << ") — средний балл: " << getAverage() << "\n";
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Student students[10];

    for (int i = 0; i < 10; i++)
        students[i].input(i);

    std::sort(students, students + 10, [](const Student& a, const Student& b) {
        return a.getAverage() < b.getAverage();
        });

    std::cout << "\n--- Список по среднему баллу ---\n";
    for (int i = 0; i < 10; i++)
        students[i].print();

    std::cout << "\n--- Отличники (все оценки >= 4) ---\n";
    for (int i = 0; i < 10; i++)
        if (students[i].isExcellent())
            std::cout << students[i].getSurnameInitial()
            << " гр. " << students[i].getNumberGroup() << "\n";
}