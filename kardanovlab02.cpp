#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Базовый класс Животное
class Animal {
protected:
    std::string name;

public:
    Animal(const std::string& name) : name(name) {}

    virtual void feed() = 0;
    virtual void pet() = 0;
    virtual void sleep() = 0;
    virtual void makeSound() const = 0;
};

// Подкласс Лев
class Lion : public Animal {
public:
    Lion(const std::string& name) : Animal(name) {}

    void feed() override {
        std::cout << name << " is being fed with meat." << std::endl;
    }

    void pet() override {
        std::cout << name << " is being petted." << std::endl;
    }

    void sleep() override {
        std::cout << name << " is going to sleep." << std::endl;
    }

    void makeSound() const override {
        std::cout << name << " roars." << std::endl;
    }
};

// Подкласс Тигр
class Tiger : public Animal {
public:
    Tiger(const std::string& name) : Animal(name) {}

    void feed() override {
        std::cout << name << " is being fed with meat." << std::endl;
    }

    void pet() override {
        std::cout << name << " is being petted." << std::endl;
    }

    void sleep() override {
        std::cout << name << " is going to sleep." << std::endl;
    }

    void makeSound() const override {
        std::cout << name << " growls." << std::endl;
    }
};

// Подкласс Лягушка
class Frog : public Animal {
public:
    Frog(const std::string& name) : Animal(name) {}

    void feed() override {
        std::cout << name << " is being fed with insects." << std::endl;
    }

    void pet() override {
        std::cout << name << " is being petted." << std::endl;
    }

    void sleep() override {
        std::cout << name << " is going to sleep." << std::endl;
    }

    void makeSound() const override {
        std::cout << name << " croaks." << std::endl;
    }
};

int main() {
    std::srand(std::time(nullptr)); // Инициализация генератора случайных чисел

    Lion lion("Lion");
    Tiger tiger("Tiger");
    Frog frog("Frog");

    int lionAction = std::rand() % 4;
    int tigerAction = std::rand() % 4;
    int frogAction = std::rand() % 4;

    switch (lionAction) {
    case 0:
        lion.feed();
        break;
    case 1:
        lion.pet();
        break;
    case 2:
        lion.sleep();
        break;
    case 3:
        lion.makeSound();
        break;
    }

    switch (tigerAction) {
    case 0:
        tiger.feed();
        break;
    case 1:
        tiger.pet();
        break;
    case 2:
        tiger.sleep();
        break;
    case 3:
        tiger.makeSound();
        break;
    }

    switch (frogAction) {
    case 0:
        frog.feed();
        break;
    case 1:
        frog.pet();
        break;
    case 2:
        frog.sleep();
        break;
    case 3:
        frog.makeSound();
        break;
    }

    return 0;
}