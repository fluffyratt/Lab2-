#ifndef LAB2_ANIMAL_H
#define LAB2_ANIMAL_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Animal {
public:
    Animal();

    Animal(string name, string species, int age, string diet, string habitat) :
        name(std::move(name)), species(std::move(species)), age(age), diet(std::move(diet)), habitat(std::move(habitat)) {};

    string getName() const { return name; }

    string getSpecies() const { return species; }

    string getDiet() const { return diet; }

    string getHabitat() const { return habitat; }

    int getAge() const { return age; }

    bool operator<(const Animal& other) const {
        return age < other.age;
    };

    virtual ~Animal() = default;

protected:
    string name;
    string species;
    int age;
    string diet;
    string habitat;
};


class Mammal : public Animal {
public:

    Mammal(string name, string species, int age, string diet, string habitat, string furType) :
        Animal(std::move(name), std::move(species), age, std::move(diet), std::move(habitat)), furType(std::move(furType)) {};

    string getFurType() const { return furType; }

    ~Mammal() override = default;

private:
    string furType;
};


class Reptile : public Animal {
public:

    Reptile(string name, string species, int age, string diet, string habitat, string scaleType) :
        Animal(std::move(name), std::move(species), age, std::move(diet), std::move(habitat)), scaleType(std::move(scaleType)) {};

    string getScaleType() const { return scaleType; }

    ~Reptile() override = default;

private:
    string scaleType;
};

#endif

