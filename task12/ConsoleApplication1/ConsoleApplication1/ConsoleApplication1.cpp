//УПРАЖНЕНИЕ №1

#include <iostream>
#include <fstream>
#include <string>

int main() {
	setlocale(LC_ALL, "ru");
	std::string path = "123.txt";
	std::ofstream foth;

	foth.open(path);

	if (!foth.is_open()) {
		std::cout << "Ошибка открытия файла" << std::endl;
	}
	else {
		foth << "Мои данные";
	}
	foth.close();

	return 0;
}

//УПРАЖНЕНИЕ №2

#include <vector>
#include <iostream>
#include <fstream>

struct Operation {
	double sum;
	double rate;
	Operation(double s, double r) :sum(r), rate(r){}
};

int main() {
	std::vector<Operation> operations = {
		Operation(100, 57.7),
		Operation(120, 57.5),
		Operation(150, 57.9),
		Operation(110, 57.8)
	};
	setlocale(LC_ALL, "ru");
	std::ofstream out("MyOperations.txt");
	if (out.is_open()) {
		for (int i = 0; i < operations.size(); i++) {
			out << operations[i].sum << " " << operations[i].rate << std::endl;
		}
	}
	out.close();
	std::vector<Operation> new_operations;
	double rate1, sum1;
	std::ifstream in("MyOperations.txt");
	if (in.is_open()) {
		while (!in.eof()) {
			sum1 = 0;
			rate1 = 0;
			in >> sum1 >> rate1;
			new_operations.push_back(Operation(sum1, rate1));
		}
	}
	in.close();

	double total_expenses = 0;
	for (int i = 0; i < new_operations.size(); i++) {
		std::cout << new_operations[i].sum << "__" << new_operations[i].rate << std::endl;
		total_expenses += new_operations[i].sum * new_operations[i].rate;
	}
	std::cout << "Общие расходы " << total_expenses << std::endl;

	return 0;
}

//УПРАЖНЕНИЕ №3

#include <iostream>
#include <vector>
#include <fstream>


struct PERSON {
	std::string name;
	std::string surname;
	int age;
};


std::vector<PERSON> createFriends(){
	return{
		{"Dmitry", "Sokolov", 20},
		{"Alexey", "Volkov", 19},
		{"Ivan", "Morozov", 21}
	};
}

void displayPersonInfo(const PERSON &p) {
	std::cout << "Имя: " << p.name << "\n"
		<< "Фамилия: " << p.surname << "\n"
		<< "Возраст: " << p.age << "\n\n";
}

int main() {
	setlocale(LC_ALL, "ru");
	std::ofstream in("Sokolov.txt");
	std::vector<PERSON> people = createFriends();
	if (!in.is_open()) {
		std::cout << "Ошибка: файл не создан!" << std::endl;
	}
	else {
		for (const auto &person : people) {
			in << person.name << " " << person.surname << " " << person.age << "\n";
		}
	}
	in.close();
	
	std::vector<PERSON> new_freinds;
	std::ofstream out("Sokolov.txt", std::ios::app);
	if (!out.is_open()) {
		std::cout << "Ошибка: файл не создан!";
	}
	else {
		for (int i = 0; i < 3; i++) {
			PERSON p;
			std::cout << i + 1 << " друг" << std::endl;
			std::cout << "Введите имя: ";
			std::cin >> p.name;
			std::cout << "Введите фамилию: ";
			std::cin >> p.surname;
			std::cout << "Введите возраст: ";
			std::cin >> p.age;
			std::cout << std::endl;
			new_freinds.push_back(p);
		}
		for (const auto &person : new_freinds) {
			out << person.name << " " << person.surname << " " << person.age << "\n";
		}

		for (const auto &person : new_freinds) {
			people.push_back(person);
		}
	}

	std::ifstream fin("Sokolov.txt");
	if (!fin.is_open()) {
		std::cout << "Ошибка: файл не создан!";
	}
	else {
		std::string str;
		PERSON p;
		while (fin >> p.name >> p.surname >> p.age) {
			displayPersonInfo(p);
		}
	}

	int total = 0;
	for (const auto& person : people) {
		total += person.age;
	}
	double avr = total / (double)people.size();

	std::cout << "Средний возраст: " << avr << std::endl;

	return 0;
}

//УПРАЖНЕНИЕ №4

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>


struct CINEMA {
	std::string name;
	std::string street;
	int numberOfSeats;
	double price;
};


int main() {
    setlocale(LC_ALL, "ru");
    std::vector<CINEMA> cinemas = {
        {"Cinema A", "Street_1", 150, 5.0},
        {"Cinema B", "Street_2", 200, 3.5},
        {"Cinema C", "Street_1", 100, 7.0},
        {"Cinema D", "Street_3", 250, 4.0},
        {"Cinema E", "Street_2", 180, 6.0},
        {"Cinema F", "Street_3", 220, 2.5},
        {"Cinema G", "Street_1", 300, 8.0},
        {"Cinema H", "Street_2", 120, 4.5}
    };
	std::ofstream out("cinemas.txt");
    if (!out.is_open()) {
        std::cout << "Ошибка: файл не создан!" << std::endl;
    }
    else {
        for (const auto &cinema : cinemas) {
            out << cinema.name << " " << cinema.street << " " << cinema.numberOfSeats << " " << cinema.price << "\n";
        }
    }
    out.close();

    std::vector<CINEMA> cinemasFromFile;
    std::ifstream in("cinemas.txt");
    if (!in.is_open()) {
        std::cout << "Ошибка: файл не создан!" << std::endl;
    }
    else {
        CINEMA c;
        while (in >> c.name >> c.street >> c.numberOfSeats >> c.price) {
            cinemasFromFile.push_back(c);
        }
    }
    in.close();

    std::ofstream results("cinemas.txt", std::ios::app);
    if (!results.is_open()) {
        std::cout << "Ошибка: файл не создан!" << std::endl;
    }
    else {
        for (const auto& cinema : cinemas) {
            results << cinema.name << " " << cinema.street << " " << cinema.numberOfSeats << " " << cinema.price << "\n";
        }
    }
    return 0;
}