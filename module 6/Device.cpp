#include "Device.h"
#include <iostream>

Device::Device(int batteryLife) : _batteryLife(batteryLife) {

}

void Device::Show() {
	std::cout << "Basic characteristics of device: " << std::endl << "battery life of device: " << _batteryLife << std::endl;
}

//------------------------------------------------- phone
Phone::Phone(int batteryLife, std::string powerConnector) : Device(batteryLife), _phone_powerConnector(powerConnector){

}

void Phone::Show() {
	std::cout << "Characteristics of phone: " << std::endl << "Battery life in hours: " << _batteryLife << std::endl << "Power Connector: " << _phone_powerConnector << std::endl;
}
//-------------------------------------------------phone


//-------------------------------------------------player
Player::Player(int batteryLife, std::string musicDuration) : Device(batteryLife), _musicDuration(musicDuration) {

}

void Player::Show() {
	std::cout << "Characteristics of player: " << std::endl << "Battery life in hours:: " << _batteryLife << std::endl << "Music Duration: " << _musicDuration << std::endl;
}
//-------------------------------------------------player


//-------------------------------------------------tablet
Tablet::Tablet(int batteryLife, std::string screenDiagonal) : Device(batteryLife), _screenDiagonal(screenDiagonal) {

}

void Tablet::Show() {
	std::cout << "Characteristics of tablet: " << std::endl << "Battery life in hours:: " << _batteryLife << std::endl << "Screen Diagonal: " << _screenDiagonal << std::endl;
}
//-------------------------------------------------tablet
