#ifndef LAB2_ZOOMANAGER_H
#define LAB2_ZOOMANAGER_H

#include "Animal.h"
#include "Habitat.cpp"
#include "Zookeeper.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class ZooManager {
private:
    vector<Animal*> m_animals;
    vector<Habitat*> m_habitats;
    vector<Zookeeper*> m_zookeepers;

public:
    ZooManager() = default;

    // Animal operations
    bool addAnimal(Animal* animal);

    bool removeAnimal(const string& name);

    Animal* findAnimal(const string& name) const;

    // Habitat operations
    bool addHabitat(Habitat* habitat);

    bool removeHabitat(const string& name);

    Habitat* findHabitat(const string& name) const;

    // Zookeeper operations
    bool addZookeeper(Zookeeper* zookeeper);

    bool removeZookeeper(const string& name);

    Zookeeper* findZookeeper(const string& name) const;

    // assigning operations
    bool assignZookeeperToHabitat(const string& zookeeperName, const string& habitatName);

    bool assignAnimalToHabitat(const string& animalName, const string& habitatName);

    //getting Zoo data
    vector<Animal*> getAnimals() const { return m_animals; }

    vector<Habitat*> getHabitats() const { return m_habitats; }

    vector<Zookeeper*> getZookeepers() const { return m_zookeepers; }

    ~ZooManager() {
        for (auto& i : m_animals) {
            delete i;
            i = nullptr;
        }
        for (auto& i : m_habitats) {
            delete i;
            i = nullptr;
        }
        for (auto& i : m_zookeepers) {
            delete i;
            i = nullptr;
        }
    }
};


#endif

