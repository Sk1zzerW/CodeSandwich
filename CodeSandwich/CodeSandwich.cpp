#include <iostream>
#include <cstring>

class Person {
private:
    char* name;
    int age;

public:
    Person() : name(nullptr), age(0) {}

    Person(const char* nameValue, int ageValue) : age(ageValue) {
        name = new char[std::strlen(nameValue) + 1];
        std::strcpy(name, nameValue);
    }

    Person(const Person& other) : age(other.age) {
        name = new char[std::strlen(other.name) + 1];
        std::strcpy(name, other.name);
    }

    Person& operator=(const Person& other) {
        if (this == &other) {
            return *this;
        }

        delete[] name;

        age = other.age;
        name = new char[std::strlen(other.name) + 1];
        std::strcpy(name, other.name);

        return *this;
    }

    ~Person() {
        delete[] name;
    }

    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

class Apartment {
private:
    Person* residents;
    int numResidents;  

public:
    Apartment() : residents(nullptr), numResidents(0) {}

    Apartment(int num) : numResidents(num) {
        residents = new Person[numResidents];
    }

    Apartment(const Apartment& other) : numResidents(other.numResidents) {
        residents = new Person[numResidents];
        for (int i = 0; i < numResidents; i++) {
            residents[i] = other.residents[i];
        }
    }

    Apartment& operator=(const Apartment& other) {
        if (this == &other) {
            return *this;
        }

        delete[] residents;

        numResidents = other.numResidents;
        residents = new Person[numResidents];
        for (int i = 0; i < numResidents; i++) {
            residents[i] = other.residents[i];
        }

        return *this;
    }

    ~Apartment() {
        delete[] residents;
    }

    void addResident(const Person& person, int index) {
        if (index >= 0 && index < numResidents) {
            residents[index] = person;
        }
    }
    void display() const {
        std::cout << "Flat w " << numResidents << " People:" << std::endl;
        for (int i = 0; i < numResidents; i++) {
            residents[i].display();
        }
    }
};
class House {
private:
    Apartment* apartments;
    int numApartments;

public:
    House() : apartments(nullptr), numApartments(0) {}

    House(int num) : numApartments(num) {
        apartments = new Apartment[numApartments];
    }

    House(const House& other) : numApartments(other.numApartments) {
        apartments = new Apartment[numApartments];
        for (int i = 0; i < numApartments; i++) {
            apartments[i] = other.apartments[i];
        }
    }

    House& operator=(const House& other) {
        if (this == &other) {
            return *this;
        }

        delete[] apartments;

        numApartments = other.numApartments;
        apartments = new Apartment[numApartments];
        for (int i = 0; i < numApartments; i++) {
            apartments[i] = other.apartments[i];
        }

        return *this;
    }

    ~House() {
        delete[] apartments;
    }

    void addApartment(const Apartment& apartment, int index) {
        if (index >= 0 && index < numApartments) {
            apartments[index] = apartment;
        }
    }

    void display() const {
        std::cout << "House w " << numApartments << " flats:" << std::endl;
        for (int i = 0; i < numApartments; i++) {
            apartments[i].display();
        }
    }
};

int main() {
    Person p1("Kostya Bryzhenyuk", 30);
    Person p2("Nikita Buryan", 25);
    Person p3("Misha Shulika", 40);

    Apartment apt1(2);
    apt1.addResident(p1, 0);
    apt1.addResident(p2, 1);

    Apartment apt2(1);
    apt2.addResident(p3, 0);

    House house(2);
    house.addApartment(apt1, 0);
    house.addApartment(apt2, 1);

    house.display();

    return 0;
}

//P.S: возможно не правильно понял задание. Часть класификаций объектов взял из интернета.
