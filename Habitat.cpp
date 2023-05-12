#include "Animal.h"
#include "Zookeeper.h"

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Habitat {
private:
    string m_name;
    int m_size{};
    string m_location;
    int m_animalCapacity = 0;
    vector<Animal*> m_animals;
    Zookeeper* m_zookeeper{};

public:
    Habitat() = default;

    Habitat(string name, int size, string location) :
        m_name(std::move(name)), m_size(size), m_location(std::move(location)) {};

    string getName() const { return m_name; }

    int getSize() const { return m_size; }

    string getLocation() const { return m_location; }

    int getAnimalCapacity() const { return m_animalCapacity; }

    Zookeeper* getZookeeper() const { return m_zookeeper; }

    bool addAnimal(Animal* animal) {
        // Check if the habitat is already at capacity
        if (m_animals.size() >= m_animalCapacity) {
            return false;
        }

        // Add the animal to the vector
        m_animals.push_back(animal);
        m_animalCapacity++;
        return true;
    }

    bool assignZookeeper(Zookeeper* zookeeper) {
        // Check if the habitat already has a zookeeper assigned
        if (m_zookeeper != nullptr) {
            return false;
        }

        // Assign the zookeeper to the habitat
        m_zookeeper = zookeeper;
        return true;
    }

    ~Habitat() {
        for (auto& i : m_animals) {
            delete i;
            i = nullptr;
        }
        delete m_zookeeper;
        m_zookeeper = nullptr;
    };
};
