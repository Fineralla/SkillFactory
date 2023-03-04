#pragma once
#include "IElectronics.h"
#include <string>

class HouseholdAppliances : virtual public IElectronics {
protected:
	//short _weight;
	short _powerÑonsumption; //ïîòğåáëÿåìàÿ ìîùíîñòü îò ğàçåòêè
public:
	//HouseholdAppliances(int weight, int powerÑonsumption);
	HouseholdAppliances(int powerÑonsumption);
	void Show() override;
};

class Fridge final : public HouseholdAppliances {
protected:
	short _weight;
public:
	Fridge(int weight, int powerÑonsumption);
	void Show() override;
};

class WashingMachine final : public HouseholdAppliances {
protected:
	short _washingDuration;
public:
	WashingMachine(short washingDuration, int powerÑonsumption);
	void Show() override;
};

class TV final : public HouseholdAppliances {
protected:
	std::string _dataExchange; //îáìåí äàííûìè, êîãäà íàïğèìåğ ïåğåêëş÷àåøüñÿ íà HDMI, ÖÒÂ èëè ÀÒÂ
public:
	TV(std::string dataExchange, int powerÑonsumption);
	void Show() override;
};