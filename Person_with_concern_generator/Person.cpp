// Person.cpp

#include "Person.h"

Person::Person(std::string n, int f, int h, int s, int fi) : name(n), famSit(f), skep(s), finanSit(fi) {}

std::string Person::getName() const { return name; }
int Person::getFamSit() const { return famSit; }
int Person::getHealth() const { return health; }
int Person::getSkep() const { return skep; }
int Person::getFinanSit() const { return finanSit; }

void Person::setName(std::string n) { name = n; }
void Person::setFamSit(int f) { famSit = f; }
void Person::setHealth(int h) { health = h; }
void Person::setSkep(int s) { skep = s; }
void Person::setFinanSit(int fi) { finanSit = fi; }

