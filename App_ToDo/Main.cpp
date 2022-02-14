#include "Main.h"
#include<iostream>
#include<string>
#include <chrono>
void Main::write_menu()
{
	std::cout << "MENU\n";
	std::cout << "-----------------------------------------\n";
	std::cout << "1 List activities in progress\n";
	std::cout << "2 List activities done\n";
	std::cout << "3 Add activity\n";
	std::cout << "0 EXIT\n";
	std::cout << "-----------------------------------------\n";
}

void Main::write_activities(std::vector<Activity> activities)
{
	for (auto& e : activities) {
		std::cout << "-----------------------------------------\n";
		std::cout << "Id: " << e.id << "\n";
		std::cout << "Name: " << e.name << "\n";
		std::cout << "Date: " << e.date << "\n";
		std::cout << "Is_done: " << e.is_done << "\n";
		std::cout << "-----------------------------------------\n";
	}
}

Activity Main::load_from_console()
{
	Activity a;
	std::cout << "Write a name for your activity:";
	std::getline(std::cin>>std::ws, a.name);
	auto const time = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());
	a.date = std::format("{:%d-%m-%Y %X}", time);
	a.is_done = false;
	return a;
}

void Main::program()
{
	Activity a;
	int option = 0;
	while (true) {
		write_menu();
		std::cin >> option;
		switch (option)
		{
		case 1:write_activities(activityService->get_activities_in_progress());
			break;
		case 2:write_activities(activityService->get_activities_done());
			break;
		case 3:
			a = load_from_console();
			activityService->create_activity(a);
			break;
		case 0: return; break;
		default:
			std::cout << "incorrect option\n";
			break;
		}
	}
}

std::vector<Activity> Main::get_test_data()
{
	//create test data
	std::vector<Activity> activities{
		{0,"bieganie","13-02-2022",false},
		{1,"plywanie","11-02-2022",false},
		{2,"skakanie","12-02-2022",true},
		{3,"pompki","14-02-2022",false}
	};
	return activities;
}
