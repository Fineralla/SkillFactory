#include "machine.h"
#include <string>


VendingMachine::VendingMachine(short slotCountMachine) {
	slotCount = slotCountMachine;
}

void VendingMachine::addSlot(SnackSlot* sl) {

}

short VendingMachine::getSlotCount() const {
	return slotCount;
}
void VendingMachine::setSlotCount(short value) {
	value = 35;
	slotCount = value;
}

std::string VendingMachine::getEmptySlotsCount() {
	short emptySlotsCount;
	int noSlotsCount = slotCount;
	emptySlotsCount -= noSlotsCount;
	
	return "���������� ������ ������ " + std::to_string(emptySlotsCount) + "����������� " + std::to_string(noSlotsCount) + " ������";
}

VendingMachine::~VendingMachine() {

}