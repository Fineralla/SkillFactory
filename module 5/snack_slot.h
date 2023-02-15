#pragma once
#include <string>
#include "snack.h"

class SnackSlot {

	unsigned short snack_count_in_slot;
	Snack* snk;

public:

	SnackSlot(short snack_count); //*количество батончиков, которые помещаются в слот
	~SnackSlot();

	void addSnack(Snack* snk);

	short getSnack_count_in_slot() const;
	void setSnack_count_in_slot(short value);


	//увеличиваем количесвтво батончиков в слоте на 1 или уменьшаем на 1
	SnackSlot& operator++();
	SnackSlot& operator--();
};