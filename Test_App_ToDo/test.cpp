#include "pch.h"
#include "../App_ToDo/Exercise.h"
#include "../App_ToDo/Helper.h"
#include <filesystem>
#include <fstream>
namespace fs = std::filesystem;

TEST(Test1_read_from_file, if_file_not_exist) {	
	auto z = Helper::read_from_file("dataTest.txt");
	EXPECT_EQ(0, z.size());
	fs::remove("dataTest.txt");
}
TEST(Test2_read_from_file, if_file_exist_and_file_is_empty) {
	Helper::save_to_file(std::vector<Activity>(), "dataTest.txt");	
	auto z = Helper::read_from_file("dataTest.txt");
	EXPECT_EQ(0, z.size());
	fs::remove("dataTest.txt");
}
TEST(Test3_read_from_file, if_file_exist_and_data_has_bad_format) {	
	std::ofstream file{ "dataTest.txt" };
	file << "hello" << "\n";
	file.close();
	auto z = Helper::read_from_file("dataTest.txt");
	EXPECT_EQ(0, z.size());
	fs::remove("dataTest.txt");
}
TEST(Test4_read_from_file,positve_if_file_exist_and_data_has_good_format) {
	//create test data
	std::vector<Activity> activities{
		{0,"bieganie","13-02-2022","15-02-2022",false},
		{1,"plywanie","11-02-2022","16-02-2022",false},
		{2,"skakanie","12-02-2022","17-02-2022",true},
		{3,"pompki","14-02-2022","15-02-2022",false}
	};
	Helper::save_to_file(activities, "dataTest.txt");
	auto z = Helper::read_from_file("dataTest.txt");
	EXPECT_EQ(4, z.size());
	fs::remove("dataTest.txt");
}
TEST(Test5_read_from_file, negative_if_file_exist_and_data_has_good_format) {
	//create test data
	std::vector<Activity> activities{
		{0,"bieganie","13-02-2022","15-02-2022",false},
		{1,"plywanie","11-02-2022","16-02-2022",false},
		{2,"skakanie","12-02-2022","17-02-2022",true},
		{3,"pompki","14-02-2022","15-02-2022",false}
	};
	Helper::save_to_file(activities, "dataTest.txt");
	auto z = Helper::read_from_file("dataTest.txt");
	EXPECT_NE(-1, z.size());
	fs::remove("dataTest.txt");
}
TEST(Test6_split, positive_test_split_line) {
	std::string testString = "ala ma kota";
	char sep = ' ';
	auto result = Helper::split(testString,sep);
	EXPECT_EQ(3, result.size());
}
TEST(Test7_split, positive_test_split_line) {
	std::string testString = "ala,ma,kota";
	char sep = ',';
	auto result = Helper::split(testString, sep);
	EXPECT_EQ(3, result.size());
}
TEST(Test8_split, negative_test_split_line) {
	std::string testString = "ala,ma,kota";
	char sep = ',';
	auto result = Helper::split(testString, sep);
	EXPECT_NE(4, result.size());
}
TEST(Test9_split, if_bad_format_test_split_line) {
	std::string testString = "ala ma kota";
	char sep = ',';
	auto result = Helper::split(testString, sep);
	EXPECT_EQ(1, result.size());
}
TEST(Test10_split, if_empty_line) {
	std::string testString = std::string();
	char sep = ',';
	auto result = Helper::split(testString, sep);
	EXPECT_EQ(1, result.size());
}