#pragma once
#include <string>
#include "snack.h"

class SnackSlot {

	unsigned short snack_count_in_slot;
	std::string name_snack_in_slot;
	Snack* snk;

public:

	SnackSlot(short snack_count); //*���������� ����������, ������� ���������� � ����
	
	void addSnack(Snack* snk);

	//����������� ����������� ���������� � ����� �� 1 ��� ��������� �� 1
	SnackSlot& operator++();
	SnackSlot& operator--();
};