//unfinished
#pragma once

#include <graphics.h>
#include <vector>

#include "../common/common.h"
#include "../model/Model.h"

class CustomShapeO :public BaseShape
{
public:
	CustomShapeO(int dir = 0)
	{
		bool matrixO[4][4] = 
		{
			0, 0, 0, 0,
      		0, 1, 1, 0,
      		0, 1, 1, 0,
      		0, 0, 0, 0
      	}
      	for(i=0 ;i<4 ;i++)
      		for(j=0 ;j<4 ;j++)
      			m_matrix[i][j] = matrixO[i][j];
      	m_x = LENGTH / 2;
      	m_y = 0;
      	m_dir = dir;
      	m_color = 1;
	}
};

class CustomShapeI :public BaseShape
{
public:
	CustomShapeI(int dir = 0)
	{
		bool matrixI[4][4] = 
		{
			0, 0, 0, 0,
      		1, 1, 1, 1,
      		0, 0, 0, 0,
      		0, 0, 0, 0
      	}
      	for(i=0 ;i<4 ;i++)
      		for(j=0 ;j<4 ;j++)
      			m_matrix[i][j] = matrixI[i][j];
      	m_x = LENGTH / 2;
      	m_y = 0;
      	m_dir = dir;
      	m_color = 2;
	}
};

class CustomShapeS :public BaseShape
{
public:
	CustomShapeS(int dir = 0)
	{
		bool matrixS[4][4] = 
		{
			0, 0, 0, 0,
      		0, 0, 1, 1,
      		0, 1, 1, 0,
      		0, 0, 0, 0
      	}
      	for(i=0 ;i<4 ;i++)
      		for(j=0 ;j<4 ;j++)
      			m_matrix[i][j] = matrixS[i][j];
      	m_x = LENGTH / 2;
      	m_y = 0;
      	m_dir = dir;
      	m_color = 3;
	}
};

class CustomShapeZ :public BaseShape
{
public:
	CustomShapeZ(int dir = 0)
	{
		bool matrixO[4][4] = 
		{
			0, 0, 0, 0,
      		0, 1, 1, 0,
      		0, 0, 1, 1,
      		0, 0, 0, 0
      	}
      	for(i=0 ;i<4 ;i++)
      		for(j=0 ;j<4 ;j++)
      			m_matrix[i][j] = matrixZ[i][j];
      	m_x = LENGTH / 2;
      	m_y = 0;
      	m_dir = dir;
      	m_color = 4;
	}
};

class CustomShapeL :public BaseShape
{
public:
	CustomShapeL(int dir = 0)
	{
		bool matrixL[4][4] = 
		{
			0, 0, 0, 0,
      		0, 1, 1, 1,
      		0, 1, 0, 0,
      		0, 0, 0, 0
      	}
      	for(i=0 ;i<4 ;i++)
      		for(j=0 ;j<4 ;j++)
      			m_matrix[i][j] = matrixL[i][j];
      	m_x = LENGTH / 2;
      	m_y = 0;
      	m_dir = dir;
      	m_color = 5;
	}
};

class CustomShapeJ :public BaseShape
{
public:
	CustomShapeJ(int dir = 0)
	{
		bool matrixJ[4][4] = 
		{
			0, 0, 0, 0,
       		0, 1, 1, 1,
       		0, 0, 0, 1,
       		0, 0, 0, 0
      	}
      	for(i=0 ;i<4 ;i++)
      		for(j=0 ;j<4 ;j++)
      			m_matrix[i][j] = matrixJ[i][j];
      	m_x = LENGTH / 2;
      	m_y = 0;
      	m_dir = dir;
      	m_color = 6;
	}
};

class CustomShapeO :public BaseShape
{
public:
	CustomShapeT(int dir = 0)
	{
		bool matrixO[4][4] = 
		{
			0, 0, 0, 0,
       		0, 1, 1, 1,
       		0, 0, 1, 0,
       		0, 0, 0, 0
      	}
      	for(i=0 ;i<4 ;i++)
      		for(j=0 ;j<4 ;j++)
      			m_matrix[i][j] = matrixT[i][j];
      	m_x = LENGTH / 2;
      	m_y = 0;
      	m_dir = dir;
      	m_color = 7;
	}
};


class DefinedShape :public BaseShape
{
public:
	DefinedShape(bool matrix[4][4] = {false}, int dir = 0)
	{
		for(i=0 ;i<4 ;i++)
			for(j=0 ;j<4 j++)
				m_matrix[i][j] = matrix[i][j];
		m_x = LENGTH / 2;
      	m_y = 0;
      	m_dir = dir;
      	m_color = 8;
	}
};

