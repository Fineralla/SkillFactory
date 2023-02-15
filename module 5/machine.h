#pragma once
#include "snack_slot.h"

class VendingMachine {

	unsigned short slotCount;//Количество слотов для снеков
	SnackSlot* sl;

public:

	VendingMachine(short slotCountMachine); //Количество слотов для снеков
	~VendingMachine();

	void addSlot(SnackSlot* sl);

	short getSlotCount() const;
	void setSlotCount(short value);

	std::string getEmptySlotsCount();
};