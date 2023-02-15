#pragma once
#include "snack_slot.h"

class VendingMachine {

	unsigned short slotCountMachine;//Количество слотов для снеков
	SnackSlot* sl;

public:
	
	VendingMachine(short slotCount); //Количество слотов для снеков

	void addSlot(SnackSlot* sl);

	short getSlotCount() const;
	void setSlotCount(short value);

	short getEmptySlotsCount(unsigned short slotCountMachine);

};