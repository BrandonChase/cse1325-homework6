#ifndef FILEIO_H
#define FILEIO_H 2016

#include "view.h"
#include "part_type.h"
#include "robot_parts.h"
#include "robot_models.h"
#include <iostream>
#include <fstream>

class Fileio
{
public:
	void loadfile();
	void savefile();
}

#endif