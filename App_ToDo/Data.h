#pragma once
#include<string>
#include<vector>
#include "Exercise.h"


class Data
{
public:
	Exercise* exercises;
	Data() {
		this->exercises = new Exercise("dane1.txt");
	}

};

