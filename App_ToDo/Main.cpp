#include "Main.h"
#include<iostream>
#include<string>
#include<chrono>

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
			a = load_data_from_console();
			activityService->create_activity(a);
			break;
		case 4:write_activities(activityService->get_activities_in_progress());
			if (!activityService->change_status_activity(load_id_from_console())) std::cout << "Not found activity\n";
			break;
		case -1: std::system("cls"); 
			break;
		case -2: std::system("cls");
			activityService->delete_all_activity();
			activityService->create_activities(get_test_data());
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
		{0,"bieganie","13-02-2022","15-02-2022",false},
		{1,"plywanie","11-02-2022","16-02-2022",false},
		{2,"skakanie","12-02-2022","17-02-2022",true},
		{3,"pompki","14-02-2022","15-02-2022",false}
	};
	return activities;
}
void Main::write_menu()
{
	std::cout << "MENU\n";
	std::cout << "-----------------------------------------\n";
	std::cout << "1 List activities in progress\n";
	std::cout << "2 List activities done\n";
	std::cout << "3 Add activity\n";
	std::cout << "4 Complete the task\n";
	std::cout << "-1 Clear\n";
	std::cout << "-2 Reset(Load defult data)\n";
	std::cout << "0 EXIT\n";
	std::cout << "-----------------------------------------\n";
}

void Main::write_activities(std::vector<Activity> activities)
{
	for (auto& e : activities) {
		std::cout << "-----------------------------------------\n";
		std::cout << "Id: " << e.id << "\n";
		std::cout << "Name: " << e.name << "\n";
		std::cout << "Date added: " << e.date << "\n";
		std::cout << "Date activity: " << e.date_activity << "\n";
		std::cout << "Is_done: " << (e.is_done?"done":"not done") << "\n";
		std::cout << "-----------------------------------------\n";
	}
}

Activity Main::load_data_from_console()
{
	Activity a;
	std::cout << "Enter a name for your activity: ";
	std::getline(std::cin >> std::ws, a.name);
	auto const time = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());
	a.date = std::format("{:%d-%m-%Y %X}", time);
	std::cout << "Enter the date of activity: [dd-mm-yyyy]: ";
	std::getline(std::cin >> std::ws, a.date_activity);
	a.is_done = false;
	return a;
}

int Main::load_id_from_console()
{
	std::cout << "Enter the task id: ";
	int id;
	std::cin >> id;
	return id;
}
