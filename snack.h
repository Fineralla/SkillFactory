#pragma once
#include <string>

class Snack {

	std::string snack_name;
	short snack_cost;
	short snack_calories;

public:

    Snack(std::string name, short cost, short calories);
    Snack(std::string name);
    ~Snack();
    void displaySnack();

    //геттеры и сеттеры
    std::string getName() const;
    void setName(std::string value);

    short getCost() const;
    void setCost(short value);

    short getCalories() const;
    void setCalorie(short value);

};