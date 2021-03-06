#include <ranges>
#include "ActivityService.h"
#include "Exercise.h"
namespace views = std::ranges::views;
std::vector<Activity> ActivityService::get_activities()
{
	return data->exercises->activity;
}

std::vector<Activity> ActivityService::get_activities_in_progress()
{
	auto filtr = [](Activity& a) {return a.is_done == false; };
	auto r = data->exercises->activity | views::filter(filtr);
	std::vector<Activity> result = {};
	for (auto &x : r) result.push_back(x);
	return result;
}

std::vector<Activity> ActivityService::get_activities_done()
{
	auto filtr = [](Activity& a) {return a.is_done == true; };
	auto r = data->exercises->activity | views::filter(filtr);
	std::vector<Activity> result = {};
	for (auto& x : r) result.push_back(x);
	return result;
}

bool ActivityService::change_status_activity(int id)
{
	auto filtr = [x = id](Activity& a) {return a.id == x; };
	auto r = data->exercises->activity | views::filter(filtr);
	if (r.empty())
		return false;	
	r.front().is_done = !r.front().is_done;
	data->exercises->save_changes();
	return true;
}

Activity* ActivityService::get_activity(int id)
{
	auto filtr = [x = id](Activity& a) {return a.id == x; };
	auto r = data->exercises->activity | views::filter(filtr);
	if (r.empty())
		return NULL;
	else 
		return new Activity(r.front());	
}

void ActivityService::create_activity(Activity a)
{
	a.id = ++data->exercises->id;
	data->exercises->activity.push_back(a);
	data->exercises->save_changes();
}

bool ActivityService::update_activity(int id, Activity a)
{
	auto filtr = [x = id](Activity& a) {return a.id == x; };
	auto r = data->exercises->activity | views::filter(filtr);
	if (r.empty())
		return false;
	r.front().id = id;
	r.front().name = a.name;
	r.front().date = a.date;
	r.front().date_activity = a.date_activity;
	r.front().is_done = a.is_done;
	data->exercises->save_changes();
	return true;
}

bool ActivityService::delete_activity(int id)
{
	auto filtr = [x = id](Activity& a) {return a.id == x; };
	auto r = data->exercises->activity | views::filter(filtr);
	if (r.empty())
		return false;
	auto filtr_del=[x = id](Activity& a) { return a.id != x; };
	auto l = data->exercises->activity | views::filter(filtr_del);
	data->exercises->activity.clear();
	for (auto &x : l) data->exercises->activity.push_back(x);
	data->exercises->save_changes();
	return true;
}

void ActivityService::delete_all_activity()
{
	data->exercises->activity.clear();
}

void ActivityService::create_activities(std::vector<Activity>activities)
{
	for (auto& x : activities) create_activity(x);
}



