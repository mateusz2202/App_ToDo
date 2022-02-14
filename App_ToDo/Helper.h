#pragma once
#include<iostream>
static class Helper
{
public:	
	static std::vector<std::string> split(std::string s, char sep) {
		std::vector<std::string>data = {};
		std::string bufor = std::string();
		for (int i = 0; i <= s.length(); i++) {
			if (s[i] != sep && s[i] != '\0') {
				bufor += s[i];
			}
			else {
				data.push_back(bufor);
				bufor = std::string();
			}
		}
		return data;
	}

	static void save_to_file(std::vector<Activity> activities, std::string path) {
		std::ofstream file{ path };
		file.clear();
		for (auto& e : activities)
			file << e.id << "," << e.name << "," << e.date << "," << e.date_activity << ","<< e.is_done << "\n";
		file.close();
	}
	static std::vector<Activity> read_from_file(std::string path) {
		std::ifstream file{ path };
		std::vector<Activity>data = {};
		if (!std::filesystem::exists(path)) {
			return std::vector<Activity>();
		}
		std::string line = std::string();
		while (!file.eof()) {
			getline(file, line);
			if (line != "") {				
				try {
					auto lineSplit = split(line, ',');
					Activity e = { stoi(lineSplit.at(0)),lineSplit.at(1),lineSplit.at(2),lineSplit.at(3),(bool)stoi(lineSplit.at(4)) };
					data.push_back(e);
				}
				catch (std::exception& e) {
					return std::vector<Activity>();
				}			
			}
		}
		file.close();
		return data;
	}
};

