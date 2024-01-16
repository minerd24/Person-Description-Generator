
// main.cpp

#include <iostream>
#include <cstdlib> // for std::rand and std::srand
#include <ctime> // for std::time
#include "Person.h"
#include <string>
#include <random>
#include <cmath>

using namespace std;
// Function to generate a random number between 1 and 10
int fillValues() {
    return std::rand() % 10 + 1;
}

int weighted_concerns(int f, int h, int finance, int s) {
    // weights for the numbers 0-3
    std::vector<int> weights = { 11 - f, 11 - h, 11 - finance, 11 - s};

    // random device
    std::random_device rd;

    // generator
    std::default_random_engine generator(rd());

    // distribution
    std::discrete_distribution<int> distribution(weights.begin(), weights.end());

    // generate a random number
    int number = distribution(generator);

    return number;
}

string familySituation(int fnum) {
    string familyType[10] = {"as a single parent, after escaping a dangerous home situation, and the leaving of a spouse.", "as a single parent.","alone, and have been for many years.", "alone.", "with a spouse with some tension in the home.", "alone, but they are dating.", "married.", "happily married with no children.", "happily married with children.", "happily married with children and supportive parents and friends."};
    string famSit;
    famSit.append("They live ");
    famSit.append(familyType[fnum - 1]);
    famSit.append("\n");




    return famSit;
}

int randomZeroTwo() {
    return rand() % 3;
}

string healthSituation(int hnum) {
    string healthType[4][3] = {
        {"They recently were involved in an extreme car crash, and is in intensive care on life support.", "They are bedridden from sickness and likely to die soon.", "They were recently involved in a workplace accident and are now hospitalized and on life support."}, // immediately terminal injury or illness
        {"They recently were diagnosed with advanced cancer.", "They recently were involved in a major car crash and are currently on life support.", "They have recently been diagnosed with a form of heart disease."}, // lifespan affecting injury or illness
        {"They were involved in a workplace accident that left them blind.", "They are a veteran and have lost limbs.", "They have been diagnosed with having relatively early stages of cancer."}, // impairing injury or illness, not neccesarily life-threatening
        {"They had a bad allergic reaction and are currently in the hospital.", "They were in a minor car accident and had some minor injuries.", "They were badly sick recently, and are now in recovery."} // bad sickness, things that someone could possibly recover from but could in some cases be dangerous
    };
    return healthType[hnum - 1][randomZeroTwo()];
}


int weighted_random() {
    // weights for the numbers 0-10
    std::vector<int> weights = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1 };

    // random device
    std::random_device rd;

    // generator
    std::default_random_engine generator(rd());

    // distribution
    std::discrete_distribution<int> distribution(weights.begin(), weights.end());

    // generate a random number
    int number = distribution(generator);

    return number;
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

    string concernList[4][10];


    std::string nameArray[100];
    fillNameArray(nameArray);
    std::string name = getRandomElement(nameArray);
    // Create a Person object
    Person person(name, fillValues(), fillValues(), weighted_random(), fillValues(), fillValues());

    // Display the information
    //std::cout << "Name: " << person.getName() << std::endl;
    //std::cout << "famSit: " << person.getFamSit() << std::endl;
    //std::cout << "Health :" << person.getHealth() << std::endl;
    //std::cout << "Time Spent:" << person.getTimeSpent() << std::endl;
    //std::cout << "skep: " << person.getSkep() << std::endl;
    //std::cout << "finanSit: " << person.getFinanSit() << std::endl;

    cout << person.getName() << " is an investigator to the church." << endl;
    if (person.getTimeSpent() > 0)
        cout << "They have been having missionary visits for " << person.getTimeSpent() << " months." << endl;
    else
        cout << "They have not yet met with the missionaries." << endl;
    if (person.getTimeSpent() <= 2)
        cout << "We do not yet know " << person.getName() <<  "'s family situation." << endl;
    else {
        cout << familySituation(person.getFamSit());
    }
    if (person.getHealth() <= 4) {
        cout << healthSituation(person.getHealth());
    }


    // concern generator (the exciting part from the code perspective)
    // it uses a weighted random based on the inverse of the Person values

    cout << concernList[weighted_concerns(person.getFamSit(), person.getHealth(), person.getFinanSit(), person.getSkep())][fillValues()];


        

    return 0;
}