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
	
	return "Количество пустых слотов " + std::to_string(emptySlotsCount) + "Отсутствует " + std::to_string(noSlotsCount) + " слотов";
}

VendingMachine::~VendingMachine() {

}