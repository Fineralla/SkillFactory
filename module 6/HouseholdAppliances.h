#pragma once
#include "IElectronics.h"
#include <string>

class HouseholdAppliances : virtual public IElectronics {
protected:
	//short _weight;
	short _power�onsumption; //������������ �������� �� �������
public:
	//HouseholdAppliances(int weight, int power�onsumption);
	HouseholdAppliances(int power�onsumption);
	void Show() override;
};

class Fridge final : public HouseholdAppliances {
protected:
	short _weight;
public:
	Fridge(int weight, int power�onsumption);
	void Show() override;
};

class WashingMachine final : public HouseholdAppliances {
protected:
	short _washingDuration;
public:
	WashingMachine(short washingDuration, int power�onsumption);
	void Show() override;
};

class TV final : public HouseholdAppliances {
protected:
	std::string _dataExchange; //����� �������, ����� �������� �������������� �� HDMI, ��� ��� ���
public:
	TV(std::string dataExchange, int power�onsumption);
	void Show() override;
};