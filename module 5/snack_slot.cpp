#include "snack_slot.h"

SnackSlot::SnackSlot(short snack_count) {
    snack_count_in_slot = snack_count;
}

void SnackSlot::addSnack(Snack* snk)
{
}

short SnackSlot::getSnack_count_in_slot() const {
    return snack_count_in_slot;
}
void SnackSlot::setSnack_count_in_slot(short value) {
    snack_count_in_slot = value;
}

SnackSlot& SnackSlot::operator++() {
    ++snack_count_in_slot;
    return *this;  //Возвращаем текущий уже измененный выше объект
}
SnackSlot& SnackSlot::operator--() {
    --snack_count_in_slot;
    return *this;
}


SnackSlot::~SnackSlot() {

}