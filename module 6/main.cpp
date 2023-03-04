#include <iostream>
#include "Device.h"
#include "HouseholdAppliances.h"
#include "HandSteamer.h"

int main(){

	setlocale(LC_ALL,"");

	IElectronics* technique[10];

	technique[0] = new Tablet(58, "15'");
	technique[1] = new Phone(52, "Type-C");
	technique[2] = new Phone(48, "Lightning");
	technique[3] = new Player(84, "5 minutes");
	technique[4] = new Fridge(184, 200);
	technique[5] = new WashingMachine(90, 250);
	technique[6] = new TV("HDMI, ЦТВ, АТВ", 300);
	technique[7] = new Tablet(42, "24'");
	technique[8] = new HandSteamer(12, 60);

	bool open = true;

	while (open)
	{
		std::cout << "Выберите технику из предложенных:\n 1 - Ноутбук 15 диагоналей \n 2 - Телефон с большим зарядом \n 3- Телефон с меньшим зарядом \n 4 - Плеер \n 5 - Холодильник \n 6 - Стиральная машина \n 7 - Телевизор \n 8 - Ноутбук 24 диагоналя \n 9 - Ручной отпариватель \n или 0 чтобы выйти" << std::endl;
		int choice;
		std::cin >> choice;

		switch (choice)
		{

		case 1:
			technique[0]->Show();
			break;
		case 2:
			technique[1]->Show();
			break;
		case 3:
			technique[2]->Show();
			break;
		case 4:
			technique[3]->Show();
			break;
		case 5:
			technique[4]->Show();
			break;
		case 6:
			technique[5]->Show();
			break;
		case 7:
			technique[6]->Show();
			break;
		case 8:
			technique[7]->Show();
			break;
		case 9:
			technique[8]->Show();
			break;
		default:
			std::cout << "Выберите ткхнику из преложенных от 1 до 8 или 0, чтобы выйти" << std::endl;
			break;
		}
	}

	delete technique[0];
	delete technique[1];
	delete technique[2];
	delete technique[3];
	delete technique[4];
	delete technique[5];
	delete technique[6];
	delete technique[7];
	delete technique[8];

	return 0;
}
