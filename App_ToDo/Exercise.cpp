#include "Exercise.h"
#include "Helper.h"
void Exercise::read_data_from_file()
{
	Helper h;
	this->activity = h.read_from_file(this->path_file);
}

void Exercise::save_changes()
{
	Helper h;
	h.save_to_file(this->activity, this->path_file);
}
