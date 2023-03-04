#pragma once
#include "Device.h"
#include "HouseholdAppliances.h"

class HandSteamer final : public Device, HouseholdAppliances {
public:
	HandSteamer(int batteryLife, int power—onsumption);
	void Show() override;
};

