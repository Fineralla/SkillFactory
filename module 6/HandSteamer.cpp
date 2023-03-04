#include "HandSteamer.h"
#include <iostream>

HandSteamer::HandSteamer(int batteryLife, int power—onsumption) : Device(batteryLife), HouseholdAppliances(power—onsumption) {

}

void HandSteamer::Show() {
	std::cout << "HandSteamer characteristics: " << std::endl << "Battery Life in minutes: " << _batteryLife << std::endl << "Power —onsumption: " << _power—onsumption << " Vt" <<  std::endl;
}