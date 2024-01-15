
// main.cpp

#include <iostream>
#include <cstdlib> // for std::rand and std::srand
#include <ctime> // for std::time
#include "Person.h"
#include <string>
#include <random>

using namespace std;
// Function to generate a random number between 1 and 10
int fillValues() {
    return std::rand() % 10 + 1;
}

void fillNameArray(std::string nameArray[100]) {
    // The 100 most common names
    std::string commonNames[120] = {
        "James", "Mary", "Robert", "Patricia", "John", "Jennifer", "Michael", "Linda", "David", "Elizabeth",
        "William", "Barbara", "Richard", "Susan", "Joseph", "Jessica", "Thomas", "Sarah", "Christopher", "Karen",
        "Charles", "Lisa", "Daniel", "Nancy", "Matthew", "Betty", "Anthony", "Sandra", "Mark", "Margaret",
        "Donald", "Ashley", "Steven", "Kimberly", "Andrew", "Emily", "Paul", "Donna", "Joshua", "Michelle",
        "Kenneth", "Carol", "Kevin", "Amanda", "Brian", "Melissa", "George", "Deborah", "Timothy", "Stephanie",
        "Ronald", "Dorothy", "Jason", "Rebecca", "Edward", "Sharon", "Jeffrey", "Laura", "Ryan", "Cynthia",
        "Jacob", "Amy", "Gary", "Kathleen", "Nicholas", "Angela", "Eric", "Shirley", "Jonathan", "Brenda",
        "Stephen", "Emma", "Larry", "Anna", "Justin", "Pamela", "Scott", "Nicole", "Brandon", "Samantha",
        "Benjamin", "Katherine", "Samuel", "Christine", "Gregory", "Helen", "Alexander", "Debra", "Patrick", "Rachel",
        "Frank", "Carolyn", "Raymond", "Janet", "Jack", "Maria", "Dennis", "Catherine", "Jerry", "Heather",
        "Tyler", "Diane", "Aaron", "Olivia", "Thomas", "Julie", "Nolan", "Joyce", "Hudson", "Victoria",
        "Alastair", "Ruth", "Jacob", "Virginia", "Tobias", "Lauren", "Simon", "Kelly", "Nathaniel", "Christina"
    };

    // Fill nameArray with the common names
    for (int i = 0; i < 100; i++) {
        nameArray[i] = commonNames[i];
    }
}

std::string getRandomElement(std::string nameArray[100]) {
    // Create a random device
    std::random_device rd;

    // Initialize Mersenne Twister pseudo-random number generator
    std::mt19937 gen(rd());

    // Uniform distribution between 0 and 99
    std::uniform_int_distribution<> dis(0, 99);

    // Generate a random index
    int random_index = dis(gen);

    // Return the string at the random index
    return nameArray[random_index];
}

int main() {
    // Initialize random seed
    std::srand(std::time(0));
    std::string nameArray[100];
    fillNameArray(nameArray);
    std::string name = getRandomElement(nameArray);
    // Create a Person object
    Person person(name, fillValues(), fillValues(), fillValues(), fillValues(), fillValues());

    // Display the information
    //std::cout << "Name: " << person.getName() << std::endl;
    //std::cout << "famSit: " << person.getFamSit() << std::endl;
    //std::cout << "Health :" << person.getHealth() << std::endl;
    //std::cout << "Time Spent:" << person.getTimeSpent() << std::endl;
    //std::cout << "skep: " << person.getSkep() << std::endl;
    //std::cout << "finanSit: " << person.getFinanSit() << std::endl;

    cout << person.getName() << " is an investigator to the church.";




    return 0;
}