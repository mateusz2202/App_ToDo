#pragma once
#include<string>
#include<vector>
#include<fstream>
#include<filesystem>
struct Activity {
	int id{};
	std::string name;
	std::string date;
	bool is_done = false;
	Activity() = default;
	Activity(int id, std::string name, std::string date, bool is_done) :id{ id }, name{ name }, date{ date }, is_done{ is_done } {}
	Activity(const Activity* a) {
		this->id = a->id;
		this->name = a->name;
		this->date = a->date;
		this->is_done = a->is_done;
	}
};
class Exercise
{
public:	
	std::vector<Activity> activity;
	Exercise(std::string path_file) {
		if (!std::filesystem::exists(path_file)) {
			std::ofstream file{ path_file };
			file.close();
		}
		activity = {};
		this->path_file = path_file;
		read_data_from_file();
	}
	void save_changes();
private:	
	std::string path_file;
	void read_data_from_file();

};

