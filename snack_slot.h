#pragma once
#include <string>
#include "snack.h"

class SnackSlot {

	unsigned short snack_count_in_slot;
	std::string name_snack_in_slot;
	Snack* snk;

public:

	SnackSlot(short snack_count); //*количество батончиков, которые помещаются в слот
	
	void addSnack(Snack* snk);

	//увеличиваем количесвтво батончиков в слоте на 1 или уменьшаем на 1
	SnackSlot& operator++();
	SnackSlot& operator--();
};