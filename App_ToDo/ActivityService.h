#pragma once
#include<iostream>
#include <vector>
#include "Data.h"
#include "Exercise.h"

class ActivityService
{
private:
	Data* data;
public:
	ActivityService(Data* data) {
		this->data = data;
	}
	std::vector<Activity> get_activities();
	std::vector<Activity> get_activities_in_progress();
	std::vector<Activity> get_activities_done();
	Activity* get_activity(int id);
	void create_activity(Activity a);
	bool update_activity(int id, Activity a);
	bool delete_activity(int id);

};

