//unfinished
#pragma once

#include <graphics.h>
#include <vector>

#include "../common/common.h"
#include "../model/Model.h"

class CustomShape :public BaseShape
{
public:
	CustomShape::CustomShape()
	{
	}
	
	void Change(int x) 
	{
		Switch(x % 4, x / 4);
	}

private:

};

