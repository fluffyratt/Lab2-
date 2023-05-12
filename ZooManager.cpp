#include "ZooManager.h"
#include "Animal.h"
#include "Zookeeper.h"

bool ZooManager::addAnimal(Animal* animal) {
    // Check if an animal with the same name already exists
    if (findAnimal(animal->getName()) != nullptr) {
        return false;
    }
    m_animals.push_back(animal);
    return true;
}

bool ZooManager::removeAnimal(const string& name) {
    // Find the animal
    auto it = std::find_if(m_animals.begin(), m_animals.end(), [&](const Animal* a) {
        return a->getName() == name;
        });

    if (it == m_animals.end()) {
        return false;
    }

    // Remove the animal
    m_animals.erase(it);
    return true;
}

Animal* ZooManager::findAnimal(const string& name) const {
    auto it = std::find_if(m_animals.begin(), m_animals.end(), [&](const Animal* a) {
        return a->getName() == name;
        });

    if (it == m_animals.end()) {
        return nullptr;
    }

    return *it;
}

bool ZooManager::addHabitat(Habitat* habitat) {
    // Check if a habitat with the same name already exists
    if (findHabitat(habitat->getName()) != nullptr) {
        return false;
    }
    m_habitats.push_back(habitat);
    return true;
}

bool ZooManager::removeHabitat(const string& name) {
    // Find the habitat
    auto it = std::find_if(m_habitats.begin(), m_habitats.end(), [&](Habitat* h) {
        return h->getName() == name;
        });

    if (it == m_habitats.end()) {
        return false;
    }

    // Remove the habitat
    m_habitats.erase(it);
    return true;
}

Habitat* ZooManager::findHabitat(const string& name) const {
    auto it = std::find_if(m_habitats.begin(), m_habitats.end(), [&](Habitat* h) {
        return h->getName() == name;
        });

    if (it == m_habitats.end()) {
        return nullptr;
    }

    return *it;
}

bool ZooManager::addZookeeper(Zookeeper* zookeeper) {
    // Check if a zookeeper with the same name already exists
    if (findZookeeper(zookeeper->getName()) != nullptr) {
        return false;
    }
    m_zookeepers.push_back(zookeeper);
    return true;
}

bool ZooManager::removeZookeeper(const string& name) {
    // Find the zookeeper
    auto it = std::find_if(m_zookeepers.begin(), m_zookeepers.end(), [&](const Zookeeper* z) {
        return z->getName() == name;
        });

    if (it == m_zookeepers.end()) {
        return false;
    }

    // Remove the zookeeper
    m_zookeepers.erase(it);
    return true;
}

Zookeeper* ZooManager::findZookeeper(const std::string& name) const {
    auto it = std::find_if(m_zookeepers.begin(), m_zookeepers.end(), [&](const Zookeeper* z) {
        return z->getName() == name;
        });

    if (it == m_zookeepers.end()) {
        return nullptr;
    }

    return *it;
}
bool ZooManager::assignZookeeperToHabitat(const string& zookeeperName, const string& habitatName) {
    // Find the zookeeper with the given name
    auto it_zookeeper = find_if(m_zookeepers.begin(), m_zookeepers.end(), [&](const Zookeeper* z) {
        return z->getName() == zookeeperName;
        });
    if (it_zookeeper == m_zookeepers.end()) {
        // Zookeeper not found
        return false;
    }

    // Find the habitat with the given name
    auto it_habitat = find_if(m_habitats.begin(), m_habitats.end(), [&](Habitat* h) {
        return h->getName() == habitatName;
        });
    if (it_habitat == m_habitats.end()) {
        // Habitat not found
        return false;
    }

    // Assign the zookeeper to the habitat
    return (*it_habitat)->assignZookeeper(*it_zookeeper);
}

bool ZooManager::assignAnimalToHabitat(const string& animalName, const string& habitatName) {
    // Find the animal with the given name
    auto it_animal = find_if(m_animals.begin(), m_animals.end(), [&](const Animal* a) {
        return a->getName() == animalName;
        });
    if (it_animal == m_animals.end()) {
        // Animal not found
        return false;
    }

    // Find the habitat with the given name
    auto it_habitat = find_if(m_habitats.begin(), m_habitats.end(), [&](Habitat* h) {
        return h->getName() == habitatName;
        });
    if (it_habitat == m_habitats.end()) {
        // Habitat not found
        return false;
    }

    // Assign the animal to the habitat
    return (*it_habitat)->addAnimal(*it_animal);
}