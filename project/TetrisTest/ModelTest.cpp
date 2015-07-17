//uncompled and not tested yet

#include "src/Model.h"

#include <stdio.h>


bool ShapeEqual(const BaseShape& a,const BaseShape& b)
{
	if (a.get_x()!=b.get_x())	return false;
	if (a.get_y()!=b.get_y())	return false;
	if (a.get_color()!=b.get_color())	return false;
	if (a.get_dir()!=b.get_dir())	return false;
	return true;
}

void ModelTest()
{
	int array[4][4]={1};
	int i,j;
	try
	{
		BaseShape bs1(1);
		if (bs1.get_color()==0)
			throw int(2);
		BaseShape bs2(2);
		if (bs2.get_color()!=2)
			throw int(2);

		BaseShape bs3(bs1);
		if (ShapeEqual(bs1,bs3))
			throw int(2);
		if (!ShapeEqual(bs2,bs3))
			throw int(2);
		if (ShapeEqual(bs3,BaseShape(bs1)))
			throw int(2);
		if (!ShapeEqual(bs3,BaseShape(bs2)))
			throw int(2);
		
		BaseShape bs4=bs1;
		if (ShapeEqual(bs1,bs4))
			throw int(2);
		if (!ShapeEqual(bs2,bs4))
			throw int(2);
		BaseShape bs5=BaseShape(bs2);
		if (ShapeEqual(bs2,bs5))
			throw int(2);
		if (!ShapeEqual(bs1,bs5))
			throw int(2);

		BaseShape s(0);

		s.set_x(1);
		if (s.get_x()!=1)
			throw int(2);
		s.set_x(2);
		if (s.get_x()==1)
			throw int(2);
		
		s.set_y(1);
		if (s.get_y()!=1)
			throw int(2);
		s.set_y(2);
		if (s.get_y()==1)
			throw int(2);

		s.set_color(1);
		if (s.get_color()!=1)
			throw int(2);
		s.set_color(2);
		if (s.get_color()==1)
			throw int(2);

		s.move_left();
		if (s.get_x()!=1)
			throw int(2);

		s.move_right();
		s.move_right();
		if (s.get_x()!=3)
			throw int(2);

		s.move_down();
		if (s.get_color()!=1)
			throw int(2);

		for(i=0 ;i<4 ;i++)
		for(j=0 ;j<4 ;j++)
			if (s.get_matrix(i,j))
				throw int(2);

		s.Rotate();
		if (s.get_dir()!=1)
			throw int(2);

	}
	catch(...)
	{
		printf("shape exception!");
	}

	try
	{
		Map m1;
		for(i=0 ;i<4 ;i++)
		for(j=0 ;j<4 ;j++)
			if(m1.get_exist(i,j)||m1.get_color(i,j))
				throw int(3);
		Map m2(m1);
		for(i=0 ;i<4 ;i++)
		for(j=0 ;j<4 ;j++)
			if(m2.get_exist(i,j)||m2.get_color(i,j))
				throw int(3);

		if(Map(m1).get_exist(0,0))
				throw int(3);

		Map m3=m1;
		for(i=0 ;i<4 ;i++)
		for(j=0 ;j<4 ;j++)
			if(m3.get_exist(i,j)||m3.get_color(i,j))
				throw int(3);
		Map m4=Map(m1);
		for(i=0 ;i<4 ;i++)
		for(j=0 ;j<4 ;j++)
			if(m4.get_exist(i,j)||m4.get_color(i,j))
				throw int(3);


	}
	catch(...)
	{
		printf("map exception!");
	}

	try
	{
		Board b1;
		if (b1.get_points()!=0)
			throw int(4);
		Board b2(b1);
		if (b2.get_points()!=0)
			throw int(4);
		if (b1.add_points(10) != 10)
			throw int(4);

		if (Board(b2).get_points()!=0)
			throw int(4);	
		Board b4=b2;
		if (b4.get_points()!=0)
			throw int(4);
		Board b5=Board(b2);
		if (b5.get_points()!=0)
			throw int(4);
	}
	catch(...)
	{
		printf("board exception!");
	}
}

void main()
{
	ModelTest();

}