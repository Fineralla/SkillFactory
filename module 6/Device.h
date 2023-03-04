#pragma once
#include "IElectronics.h"
#include <string>

class Device : virtual public IElectronics {
protected:
	int _batteryLife;
	//std::string _powerConnector;
public:
	Device(int batteryLife);
	void Show() override;

};


class Phone final : public Device {
protected:
	std::string _phone_powerConnector;
	//std::string _phone_company;
public:
	Phone(int batteryLife, std::string powerConnector);
	void Show() override;
};

class Player final : public Device {
	//int _player_batteryLife;
	std::string _musicDuration;
public:
	Player(int batteryLife, std::string musicDuration);
	void Show() override;
};

class Tablet final : public Device {
	//int _tablet_batteryLife;
	std::string _screenDiagonal;
public:
	Tablet(int batteryLife, std::string screenDiagonal);
	void Show() override;
};
