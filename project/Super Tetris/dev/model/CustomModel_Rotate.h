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
	
	void Roatate() 
	{
		bool a,b;
		a = get_matrix(0, 0);
		if (b = get_matrix(3, 0) ^ a) Switch(3, 0);  a = b;
		if (b = get_matrix(3, 3) ^ a) Switch(3, 3);  a = b;
		if (b = get_matrix(0, 3) ^ a) Switch(0, 3);  a = b;
		if (get_matrix(0, 0) ^ a) Switch(0, 0); 
		a = get_matrix(1, 0);
		if (b = get_matrix(3, 1) ^ a) Switch(3, 1);  a = b;
		if (b = get_matrix(2, 3) ^ a) Switch(2, 3);  a = b;
		if (b = get_matrix(0, 2) ^ a) Switch(0, 2);  a = b;
		if (get_matrix(1, 0) ^ a) Switch(1, 0);
		a = get_matrix(2, 0);
		if (b = get_matrix(3, 2) ^ a) Switch(3, 2);  a = b;
		if (b = get_matrix(1, 3) ^ a) Switch(1, 3);  a = b;
		if (b = get_matrix(0, 1) ^ a) Switch(0, 1);  a = b;
		if (get_matrix(2, 0) ^ a) Switch(2, 0);
		a = get_matrix(1, 1);
		if (b = get_matrix(2, 1) ^ a) Switch(2, 1);  a = b;
		if (b = get_matrix(2, 2) ^ a) Switch(2, 2);  a = b;
		if (b = get_matrix(1, 2) ^ a) Switch(1, 2);  a = b;
		if (get_matrix(1, 1) ^ a) Switch(1, 1);
	}
	void Change(int x) 
	{
		Switch(x % 4, x / 4);
	}

private:

};

