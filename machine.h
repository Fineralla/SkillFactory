#pragma once
#include "snack_slot.h"

class VendingMachine {

	unsigned short slotCountMachine;//���������� ������ ��� ������
	SnackSlot* sl;

public:
	
	VendingMachine(short slotCount); //���������� ������ ��� ������

	void addSlot(SnackSlot* sl);

	short getSlotCount() const;
	void setSlotCount(short value);

	short getEmptySlotsCount(unsigned short slotCountMachine);

};