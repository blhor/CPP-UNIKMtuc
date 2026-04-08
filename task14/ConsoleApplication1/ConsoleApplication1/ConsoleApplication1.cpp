#include <iostream>
#include <string>
#include <algorithm>
class Student {
public:
    std::string surnameInitional;
    int numberGroup;
    int grades[5];

    double getAverage() {
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += grades[i]; 
        }
        return (double)sum / 5;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Student students[10];

    for (int i = 0; i < 10; i++) {
        std::cout << "Студент " << i + 1 << ":\n";
        std::cout << "Фамилия и инициалы: ";
        std::getline(std::cin, students[i].surnameInitional);
        std::cout << "Номер группы: ";
        std::cin >> students[i].numberGroup;
        std::cout << "5 оценок: ";
        for (int j = 0; j < 5; j++) {
            std::cin >> students[i].grades[j];
        }
        std::cin.ignore();
    }

    std::sort(students, students + 10, [](Student& a, Student& b) {
        return a.getAverage() < b.getAverage();
        });
    for (int i = 0; i < 10; i++) {
        std::cout << students[i].surnameInitional
            << " " << students[i].getAverage() << "\n";
    }

    for (int i = 0; i < 10; i++) {
        bool allGood = true;
        for (int j = 0; j < 5; j++) {
            if (students[i].grades[j] < 4) {
                allGood = false;
            }
        }
        if (allGood) {
            std::cout << students[i].surnameInitional << " " << students[i].numberGroup << "\n";
        }
    }
}