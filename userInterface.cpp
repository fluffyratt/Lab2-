#include "ZooManager.cpp"
#include "Animal.h"
#include "Zookeeper.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class userInterface {
private:
    ZooManager zm;
    string _name;
    string _species;
    int _age{};
    string _diet;
    string _habitat;
    string _furType;
    string _scaleType;
    string _gender;
    int _size{};
    string _location;

public:
    static void printIntro() {
        cout << "Welcome to our Zoo! Here you can contemplate a lot of interesting species." << endl;
        cout << "Do not hesitate to walk and enjoy the elegance of our animals!" << endl;
        cout << "But remember: do not feed them until you see the allowing sign!" << endl;
        cout << "Here what you can do in the ZOO:" << endl;
        cout << "0. Display all the habitats." << endl;
        cout << "1. Add an animal to the ZOO." << endl;
        cout << "2. Add a zookeeper to the ZOO." << endl;
        cout << "3. Create a habitat" << endl;
        cout << "4. Assign an animal to a habitat." << endl;
        cout << "5. Assign a zookeeper to a habitat." << endl;
        cout << "6. Removing operations." << endl;
        cout << "7. Leave the ZOO" << endl;
        cout << endl;
    }

    bool displayHabitats() {
        vector<Habitat*> habitats = zm.getHabitats();
        if (!habitats.empty()) {
            for (auto& habitat : habitats) {
                cout << "Name: " << habitat->getName() << endl;
                cout << "Located in " << habitat->getLocation() << endl;
                cout << "It contains " << habitat->getAnimalCapacity() << " animals." << endl;
                cout << "Habitat size: " << habitat->getSize() << endl;
                cout << "Current zookeeper: " << habitat->getZookeeper() << endl << endl;
            }
            return true;
        }
        else
            return false;
    }

    void addAnimalInterface() {
        cout << "Is the animal mammal or reptile?" << endl;
        cin.clear();
        cin.sync();
        string answer;
        cin >> answer;
        auto askCommon = [&]() {
            cin.clear();
            cin.sync();
            cout << "What is the name?" << endl;
            getline(cin, _name);
            cout << "What is its age?" << endl;
            cin >> _age;
            cin.ignore();
            cout << "What is its diet?" << endl;
            getline(cin, _diet);
            cout << "What is its habitat?" << endl;
            getline(cin, _habitat);
        };
        if (answer == "Mammal" || answer == "mammal") {
            askCommon();
            _species = "mammal";
            cout << "Fur type?" << endl;
            getline(cin, _furType);
            Mammal mammal = { _name, _species, _age, _diet, _habitat, _furType };
            if (!zm.addAnimal(&mammal))
                cout << "These is an animal with the same name in the ZOO already!" << endl;
            else
                cout << "The animal has been added to the ZOO successfully!" << endl;

        }
        else if (answer == "Reptile" || answer == "reptile") {
            askCommon();
            _species = "reptile";
            cout << "Scale type?" << endl;
            getline(cin, _scaleType);
            Reptile reptile = { _name, _species, _age, _diet, _habitat, _scaleType };
            if (!zm.addAnimal(&reptile))
                cout << "These is an animal with the same name in the ZOO already!" << endl;
            else
                cout << "The animal has been added to the ZOO successfully!" << endl;

        }
        else
            cout << "The ZOO does not provide the preservation of such a specie(" << endl;

    }

    void addZookeeperInterface() {
        cin.clear();
        cin.sync();
        cout << "What is the zookeeper's name?" << endl;
        getline(cin, _name);
        cout << "What is their age?" << endl;
        cin >> _age;
        cin.ignore();
        cout << "What is their gender?" << endl;
        getline(cin, _gender);
        Zookeeper zookeeper = { _name, _age, _gender };
        if (!zm.addZookeeper(&zookeeper))
            cout << "There is a zookeeper with the same name in the ZOO already!" << endl;
        else
            cout << "The zookeeper has been added to the ZOO successfully!" << endl;
    }

    void assigningAnimalInterface() {
        cin.clear();
        cin.sync();
        string animalName, habitatName;
        cout << "What is the name of animal you want to assign?" << endl;
        getline(cin, animalName);
        cout << "What is the name of the habitat you want to assign the animal to?" << endl;
        getline(cin, habitatName);
        if (!zm.assignAnimalToHabitat(animalName, habitatName))
            cout << "There is no such an animal/habitat in the ZOO or the habitat is already full." << endl;
        else
            cout << "The animal has been assigned successfully!" << endl;

    }

    void assigningZookeeperInterface() {
        cin.clear();
        cin.sync();
        string zookeeper, habitatName;
        cout << "What is the name of zookeeper you want to assign?" << endl;
        getline(cin, zookeeper);
        cout << "What is the name of the habitat you want to assign the animal to?" << endl;
        getline(cin, habitatName);
        if (!zm.assignZookeeperToHabitat(zookeeper, habitatName))
            cout << "There is no such a zookeeper/habitat in the ZOO." << endl;
        else
            cout << "The zookeeper has been assigned successfully!" << endl;
    }

    void removingInterface(int option) {
        cin.clear();
        cin.sync();
        switch (option) {
            //remove animal
        case 1:
            cout << "What's the name of the animal you want to remove?" << endl;
            getline(cin, _name);
            if (!zm.removeAnimal(_name))
                cout << "There is no such an animal in the ZOO :/" << endl;
            else
                cout << "The animal has been deported successfully!" << endl;
            break;
            //remove zookeeper
        case 2:
            cout << "What's the name of the zookeeper you want to remove?" << endl;
            getline(cin, _name);
            if (!zm.removeZookeeper(_name))
                cout << "There is no zookeeper with the name in the ZOO :/" << endl;
            else
                cout << "The zookeeper has been dismissed successfully!" << endl;
            break;
            //remove habitat
        case 3:
            cout << "What's the caption of the habitat you want to remove?" << endl;
            getline(cin, _name);
            if (!zm.removeHabitat(_name))
                cout << "There is no habitat with the caption in the ZOO :/" << endl;
            else
                cout << "The habitat has been closed successfully!" << endl;
            break;
        case 4:
            cout << "Nothing has been changed." << endl;
            break;
        default:
            cout << "Please enter a valid option number from the given (1-3)." << endl;
        }
    }

    void createHabitatInterface() {
        cin.clear();
        cin.sync();
        cout << "What is the caption of your habitat?" << endl;
        getline(cin, _name);
        cout << "How many animals can your habitat contain?" << endl;
        cin >> _size;
        cin.ignore();
        cout << "Where is your habitat located?" << endl;
        getline(cin, _location);
        Habitat habitat = { _name,_size,_location };
        if (!zm.addHabitat(&habitat))
            cout << "There is already a habitat with the same caption in the ZOO!" << endl;
        else
            cout << "The habitat have been created successfully!" << endl;
    }

    void interplay() {
        int num = -1;
        printIntro();
        while (num != 7) {
            cout << "Enter the number of the option you want to execute:";
            cin.clear();
            cin.sync();
            if (cin >> num) {
                switch (num) {
                case 0:
                    cout << "Here are the habitats and their properties:" << endl;
                    if (!displayHabitats())
                        cout << "It seems that there are no habitats in the ZOO yet :/" << endl;
                    break;
                case 1:
                    addAnimalInterface();
                    break;
                case 2:
                    addZookeeperInterface();
                    break;
                case 3:
                    createHabitatInterface();
                    break;
                case 4:
                    assigningAnimalInterface();
                    break;
                case 5:
                    assigningZookeeperInterface();
                    break;
                case 6:
                    cout << "Please choose the removing option:" << endl;
                    cout << "1. Remove an animal." << endl;
                    cout << "2. Remove a zookeeper." << endl;
                    cout << "3. Remove a habitat." << endl;
                    cout << "4. Change nothing." << endl;
                    cin.ignore();
                    int option;
                    cin >> option;
                    removingInterface(option);
                    break;
                case 7:
                    cout << "Thank you for using our ZOO <3" << endl;
                    cout << "See you!" << endl;
                    break;
                default:
                    cout << "There is no option with the number you entered :/" << endl;
                    break;
                }
            }
            else
                cout << "Please enter a valid option number." << endl;
        }

    }
};

int main() {
    userInterface uI;
    uI.interplay();
    return 0;
}
