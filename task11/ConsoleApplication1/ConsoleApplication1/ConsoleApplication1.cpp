#include <iostream>
#include <vector>
#include <algorithm>

struct CINEMA {
	std::string name;
	std::string street;
	int numberOfSeats;
	double price;
};

bool compareByName(const CINEMA &a, const CINEMA &b) {
	return a.name < b.name;
}

std::vector<CINEMA> createCinemas() {
    return {
        {"Cinema A", "Street 1", 150, 5.0},
        {"Cinema B", "Street 2", 200, 3.5},
        {"Cinema C", "Street 1", 100, 7.0},
        {"Cinema D", "Street 3", 250, 4.0},
        {"Cinema E", "Street 2", 180, 6.0},
        {"Cinema F", "Street 3", 220, 2.5},
        {"Cinema G", "Street 1", 300, 8.0},
        {"Cinema H", "Street 2", 120, 4.5}
    };
}

void sortCinemas(std::vector<CINEMA>& cinemas) {
    std::sort(cinemas.begin(), cinemas.end(), compareByName);
}

CINEMA findMaxSeatsCinema(const std::vector<CINEMA> &cinemas) {
    CINEMA maxSeatsCinema = cinemas[0];
    for (const auto &cinema : cinemas) {
        if (cinema.numberOfSeats > maxSeatsCinema.numberOfSeats) {
            maxSeatsCinema = cinema;
        }
    }
    return maxSeatsCinema;
}


CINEMA findMinPriceCinema(const std::vector<CINEMA> &cinemas) {
    CINEMA minPriceCinema = cinemas[0];
    for (const auto& cinema : cinemas) {
        if (cinema.price < minPriceCinema.price) {
            minPriceCinema = cinema;
        }
    }
    return minPriceCinema;
}

void displayCinemaInfo(const CINEMA &cinema) {
    std::cout << "Название: " << cinema.name
        << ", Район: " << cinema.street
        << ", Мест: " << cinema.numberOfSeats
        << ", Цена билета: " << cinema.price << "\n";
}

int main() {
    std::vector<CINEMA> cinemas = createCinemas();

    sortCinemas(cinemas);

    CINEMA maxSeatsCinema = findMaxSeatsCinema(cinemas);
    std::cout << "Кинотеатр с большим кол-во мест:\n";
    displayCinemaInfo(maxSeatsCinema);

    CINEMA minPriceCinema = findMinPriceCinema(cinemas);
    std::cout << "Кинотеатр с дешевой ценой билета:\n";
    displayCinemaInfo(minPriceCinema);

    return 0;
}