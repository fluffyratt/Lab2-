#ifndef LAB2_ZOOKEEPER_H
#define LAB2_ZOOKEEPER_H

#include <iostream>
#include <string>

using namespace std;

class Zookeeper {
private:
    string name;
    int age;
    string gender;

public:
    Zookeeper();

    Zookeeper(string name, int age, string gender) :
        name(std::move(name)), age(age), gender(std::move(gender)) {};

    string getName() const { return name; }

    int getAge() const { return age; }

    string getGender() const { return gender; }

    ~Zookeeper() = default;

};
#endif

