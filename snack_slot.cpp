#include "snack_slot.h"

SnackSlot::SnackSlot(short snack_count) {
    snack_count_in_slot = snack_count;
}


void SnackSlot::addSnack(Snack* snk)
{
}

SnackSlot& SnackSlot::operator++() {
    ++snack_count_in_slot;
    return *this;  //���������� ������� ��� ���������� ���� ������
}
SnackSlot& SnackSlot::operator--() {
    --snack_count_in_slot;
    return *this;
}


