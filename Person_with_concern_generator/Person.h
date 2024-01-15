#pragma once
// Person.h

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <cstdlib> // for std::rand and std::srand
#include <ctime> // for std::time

class Person {
private:
    std::string name;
    int famSit;
    int health;
    int timeSpent;
    int skep;
    int finanSit;

public:
    // Constructor
    Person(std::string n, int f, int h, int t, int s, int fi);

    // Getters
    std::string getName() const;
    int getFamSit() const;
    int getHealth() const;
    int getTimeSpent() const;
    int getSkep() const;
    int getFinanSit() const;

    // Setters
    void setName(std::string n);
    void setFamSit(int f);
    void setHealth(int h);
    void setTimeSpent(int t);
    void setSkep(int s);
    void setFinanSit(int fi);


    // Call this function to generate a random number between 1 and 100
    int isPTSD() {
        // Initialize random seed
        std::srand(std::time(0));

        // Generate random number between 1 and 100
        int randomNumber = std::rand() % 100 + 1;

        return randomNumber;
    }
};

#endif // PERSON_H