
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
        {"They have had a bad allergic reaction and are currently in the hospital.", "They were in a minor car accident and sustained some injuries.", "They were badly sick recently, and are now in recovery."} // bad sickness, things that someone could possibly recover from but could in some cases be dangerous
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

    string concernList[4][10] = {
        {" is wondering why marriage in the temple is so important."," is concerned that their late father did not get baptized, and is wondering about their salvation."," is wondering if the Church still practices polygamy."," is wondering if the Church accepts people of other cultures, sexualities and beliefs."," is wondering why the church prohibits premarital sex."," is concerned that their young child has not yet been baptized to a church."," is wondering has to be done so that they can be married in the temple."," is having trouble understanding why little children don't need to be baptized."," is having trouble understanding why marriage is so important."," is having trouble figuring out how to help a relative through a tough loss of a family member."}, // family questions
        {" is wondering why coffee and tea are against the Word of Wisdom."," is wondering why smoking and drinking are against the Word of Wisdom."," is wondering what the Word of Wisdom is, and why it is important."," is wondering why the Word of Wisdom is so important."," is having trouble understanding why eating healthy and exercising is so important."," is wondering what is going to happen to them when they die."," is concerned with what will happen if they die without being baptized."," is having trouble understanding what happens after this life in the plan of salvation."," is having trouble understanding why being a good person in this life is so important."," is wondering where they were before they were born."}, // afterlife / word of wisdom questions
        {" is wondering why members have to pay tithing."," is wondering what tithing goes to."," is wondering why tithing is so important."," is wondering who decides how the tithing is used."," is wondering why tithing is ten percent."," is wondering why being a full tithe payer is one of the temple recommend questions."," is concerned that they may not be able to afford accessing the scriptures."," is wondering about addiction recovery services that the church offers, and what they can do to learn about them."," is unsure about how they will be able to stay self reliant in the future."," has no specific concern, but you notice that they may need financial help."}, // money questions
        {" is wondering what the purpose of the Book of Mormon is."," is wondering why we need prophets and apostles."," is wondering why we require temple recommends to enter the temple."," is wondering if we pay the church leaders."," is wondering if we still use the Bible."," is concerned that previous sins may make them ineligible for baptism."," is having trouble understanding that we believe in the Godhead as 3 seperate beings."," is having trouble understanding that God has a body."," is concerned that their parents were not the most righteous people, and that they might be punished because of them."," is wondering if the church allows people of different races to be baptized and enter the temple."}  // general belief questions
    };


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
        cout << healthSituation(person.getHealth()) << endl;
    }


    // concern generator (the exciting part from the code perspective)
    // it uses a weighted random based on the inverse of the Person values

    cout << person.getName() << concernList[weighted_concerns(person.getFamSit(), person.getHealth(), person.getFinanSit(), person.getSkep())][fillValues()] << endl;


        

    return 0;
}