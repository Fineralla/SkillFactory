#include "snack.h"
#include <string>
#include <iostream>

Snack::Snack(std::string name, short cost, short calories) {
	snack_name = name; 
	snack_cost = cost;
	snack_calories = calories;
}
Snack::Snack(std::string name) {
	snack_name = name;
}

void Snack::displaySnack() {
	setlocale(LC_ALL, "");
	std::cout << "Название батончика: " << snack_name << std::endl;
	std::cout << "Стоимость:  " << snack_cost << std::endl;
	std::cout << "Калории " << snack_calories << std::endl;
}


std::string Snack::getName() const {
	return snack_name;
}
void Snack::setName(std::string value) {
	snack_name = value;
}

short Snack::getCost() const {
	return snack_cost;
}
void Snack::setCost(short value) {
	snack_cost = value;
}

short Snack::getCalories() const {
	return snack_calories;
}
void Snack::setCalorie(short value) {
	snack_calories = value;
}


Snack::~Snack() {

}