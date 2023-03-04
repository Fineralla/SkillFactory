#include "HouseholdAppliances.h"
#include <iostream>


HouseholdAppliances::HouseholdAppliances(int power—onsumption) : _power—onsumption(power—onsumption) {

}

void HouseholdAppliances::Show() {
	std::cout << "Basic characteristics of Household Appliances: " << std::endl << "Power —onsumption: " << _power—onsumption << std::endl;
}


//------------------------------------------------- fridge
Fridge::Fridge(int weight, int power—onsumption) : _weight(weight), HouseholdAppliances(power—onsumption) {

}

void Fridge::Show() {
	std::cout << "Characteristics of fridge: " << std::endl << "Weight: " << _weight << " kg" << std::endl << "Power —onsumption: " << _power—onsumption << std::endl;
}
//------------------------------------------------- fridge


//------------------------------------------------- washing machine
WashingMachine::WashingMachine(short washingDuration, int power—onsumption) : _washingDuration(washingDuration), HouseholdAppliances(power—onsumption) {

}

void WashingMachine::Show() {
	std::cout << "Characteristics of washing machine: " << std::endl << "Washing Duration: " << _washingDuration << std::endl << "Power —onsumption: " << _power—onsumption << std::endl;
}
//------------------------------------------------- washing machine


//------------------------------------------------- tv
TV::TV(std::string dataExchange, int power—onsumption) : _dataExchange(dataExchange), HouseholdAppliances(power—onsumption) {

}

void TV::Show() {
	std::cout << "Characteristics of tablet: " << std::endl << "Data Exchange: " << _dataExchange << std::endl << "Power —onsumption: " << _power—onsumption << std::endl;
}
//------------------------------------------------- tv