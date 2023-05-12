## Animal.h

These are the definitions of three classes: Animal, Mammal (which inherits from Animal), and Reptile (also inherits from Animal).

Animal class has a constructor with parameters for name, species, age, diet, and habitat. It also defines accessor functions for each of these attributes. Additionally, it defines the < operator, which compares two animals based on their age.

Mammal class has a constructor with parameters for name, species, age, diet, habitat, and furType. It also defines an accessor function for furType. It inherits the Animal class and does not add any additional member variables or functions.

Reptile class has a constructor with parameters for name, species, age, diet, habitat, and scaleType. It also defines an accessor function for scaleType. It inherits the Animal class and does not add any additional member variables or functions.

## Habitat.cpp
This file describes the Habitat class, which represents the habitat of the animals in the zoo. The class contains the following private variables and  has the following public methods: :

``` m_name: a line containing the name of the place of residence of animals;

m_size: an integer that reflects the size of the place of residence;

m_location: a string that contains the location of the place of residence;

m_animalCapacity: an integer that represents the maximum number of animals that can live in this location;

m_animals: a vector of pointers to Animal type objects that live in this place;

m_zookeeper: pointer to the Zookeeper object that is responsible for this animal habitat.

Default constructor;

Designer with parameters that determine the name of the animal habitat, its size and location;

The getName method, which returns the name of the animal's habitat;

The getSize method, which returns the size of the animal habitat;

The getLocation method, which returns the location of the animal's habitat;

The getAnimalCapacity method, which returns the maximum number of animals that can live in this location;

The getZookeeper method, which returns a pointer to the Zookeeper object that is responsible for this animal habitat;

The addAnimal method, which adds an animal to the m_animals vector if the animal habitat has not yet reached the maximum number of animals;

The assignZookeeper method, which assigns a keeper to an animal habitat if the habitat does not already have an assigned keeper. 
```

## Zookeeper.h

In this file the definition of a Zookeeper class, which has a name, age, and gender as private member variables. It has a default constructor and another constructor that takes three arguments to initialize the member variables. It also has getter functions for each of the member variables. Finally, it has a default destructor.
```
    Zookeeper();

    Zookeeper(string name, int age, string gender) :
        name(std::move(name)), age(age), gender(std::move(gender)) {};

    string getName() const { return name; }

    int getAge() const { return age; }

    string getGender() const { return gender; }

    ~Zookeeper() = default;
```
## ZooManager.h

The ZooManager class is responsible for managing the zoo and its components, such as animals, habitats, and zookeepers. It has private data members m_animals, m_habitats, and m_zookeepers, which are vectors that store pointers to instances of Animal, Habitat, and Zookeeper, respectively.

The class provides several public member functions for managing the zoo:

``` 
addAnimal: adds a new animal to the zoo.

removeAnimal: removes an animal from the zoo.

findAnimal: finds an animal in the zoo by name.

addHabitat: adds a new habitat to the zoo.

removeHabitat: removes a habitat from the zoo.

findHabitat: finds a habitat in the zoo by name.

addZookeeper: adds a new zookeeper to the zoo.

removeZookeeper: removes a zookeeper from the zoo.

findZookeeper: finds a zookeeper in the zoo by name.

assignZookeeperToHabitat: assigns a zookeeper to a habitat.

assignAnimalToHabitat: assigns an animal to a habitat.

getAnimals: returns a vector of all the animals in the zoo.

getHabitats: returns a vector of all the habitats in the zoo.

getZookeepers: returns a vector of all the zookeepers in the zoo.
The class also has a destructor that deletes all the instances of Animal, Habitat, and Zookeeper that were allocated dynamically.
```

## ZooManager.cpp
This file contains the implementation of all the methods listed in the header file ( ZooManager.h )

## userInterface.cpp
As an additional task in this code is a zoo management program. It contains a userInterface class with several methods that allow the user to interact with the zoo.

For example, some of the methods :

The printIntro() method prints a welcome message and shows what operations can be performed in the zoo.

The displayHabitats() method prints information about all available enclosures in the zoo: their names, location, capacity, size, and information about the zookeeper currently assigned to the enclosure. If there are no enclosures, the method will return false, otherwise - true.

The addAnimalInterface() method asks the user for information about a new animal they want to add to the zoo. It first asks if it is a mammal or a reptile, then asks for general information about the animal, such as its name, age, diet, and enclosure where it will live. For mammals it also asks for the type of fur, and for reptiles - the type of scales. Then it creates an animal object (a Mammal object if it is a mammal, or a Reptile object if it is a reptile) and adds it to the zoo. If an animal with that name already exists in the zoo, the method informs the user about it.

The addZookeeperInterface() method asks the user for information about the new zookeeper they want to add to the zoo. Asks his name, age and gender. Then it creates a zookermaker object and adds it to the zoo. If a zookeeper with this name already exists in the zoo, the method informs the user about it.

