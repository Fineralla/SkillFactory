#include "machine.h"

VendingMachine::VendingMachine(short slotCount) {
	slotCountMachine = slotCount;
}

void VendingMachine::addSlot(SnackSlot* sl) {

}

short VendingMachine::getSlotCount() const {
	return slotCountMachine;
}
void VendingMachine::setSlotCount(short value) {
	slotCountMachine = value;
}


short VendingMachine::getEmptySlotsCount(unsigned short slotCountMachine) {
	
}