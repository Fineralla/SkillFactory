#pragma once
#include "snack_slot.h"

class VendingMachine {

	unsigned short slotCount;//���������� ������ ��� ������
	SnackSlot* sl;

public:

	VendingMachine(short slotCountMachine); //���������� ������ ��� ������
	~VendingMachine();

	void addSlot(SnackSlot* sl);

	short getSlotCount() const;
	void setSlotCount(short value);

	std::string getEmptySlotsCount();
};