#pragma once
#include<vector>
#include"Exercise.h"
#include "Data.h"
#include "ActivityService.h"
class Main
{
public:
	Main(Data* data) {
		activityService = new ActivityService(data);
	};
	void write_menu();
	void write_activities(std::vector<Activity> activities);
	Activity load_from_console();
	void program();
private:
	ActivityService* activityService;
	std::vector<Activity> get_test_data();
	
};

