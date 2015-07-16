#pragma once

#include <string>
#include <vector>
/*
class Block
{
public:
	Block() throw() : m_x(0), m_y(0), m_color(0)
	{	
	}
	Block(const Block& b)
	{
		m_x = b.m_x;
		m_y = b.m_y;
		m_color = b.m_color;
	}
	Block(Block&& b)
	{
		m_x = b.m_x;
		m_y = b.m_y;
		m_color = b.m_color;
	}

	void set_x(int x) throw()
	{
		this->m_x = x;
	}
	void set_y(int y) throw()
	{
		this->m_y = y;
	}
	void set_color(int color) throw()
	{
		this->m_color = color;
	}
	int get_x() const throw()
	{
		return m_x;
	}
	int get_y() const throw()
	{
		return  m_y;
	}
	int get_color() const throw()
	{
		return m_color;
	}
	Block& operator=(const Block& b)
	{
		if(this != &b){
			m_x = b.m_x;
			m_y = b.m_y;
			m_color = b.m_color;
		}

		return *this;
	} 
	Block& operator=(Block&& b)
	{
		if(this != &b){
			m_x = s.m_x;
			m_y = s.m_y;
			m_color = b.m_color;
		}

		return *this;
	}
private:
	int m_x;
	int m_y;
	int m_color;
};
*/
class BaseShape
{
public:

	BaseShape(int matrix[4][4]={0},int color=0) 
	{	
		m_x = 4;
		m_y = 0;
		m_dir = 0;
		m_color = color;
		for(int i=0 ;i<4 ;i++)
			for(int j=0 ;j<4 ;j++)
				m_matrix[i][j] = matrix[i][j];
	}
	BaseShape(const BaseShape& b)
	{
		m_dir = b.m_dir;
		m_x = b.m_x;
		m_y = b.m_y;
		m_color = b.m_color;

		for(int i=0 ;i<4 ;i++)
			for(int j=0 ;j<4 ;j++)
				m_matrix[i][j] = b.m_matrix[i][j];
	}
	BaseShape(BaseShape&& b)
	{
		m_dir = b.m_dir;
		m_x = b.m_x;
		m_y = b.m_y;
		m_color = b.m_color;

		for(int i=0 ;i<4 ;i++)
			for(int j=0 ;j<4 ;j++)
				m_matrix[i][j] = b.m_matrix[i][j];
	}
	BaseShape& operator=(BaseShape&& b)
	{
		if (this != &b)
		{	
			m_dir = b.m_dir;
			m_x = b.m_x;
			m_y = b.m_y;
			m_color = b.m_color;
			for(int i=0 ;i<4 ;i++)
			for(int j=0 ;j<4 ;j++)
				m_matrix[i][j] = b.m_matrix[i][j];
		}
		return *this;
	}
	BaseShape& operator=(const BaseShape& b)
	{
		if (this != &b)
		{	
			m_dir = b.m_dir;
			m_x = b.m_x;
			m_y = b.m_y;
			m_color = b.m_color;
			for(int i=0 ;i<4 ;i++)
			for(int j=0 ;j<4 ;j++)
				m_matrix[i][j] = b.m_matrix[i][j];
		}
		return *this;
	}

	void set_y(int y) throw()
	{
		this->m_y = y;
	}
	void set_color(int color) throw()
	{
		this->m_color = color;
	}
	int get_x() const throw()
	{
		return m_x;
	}
	int get_y() const throw()
	{
		return m_y;
	}
	int get_color() const throw()
	{
		return m_color;
	}
	void Rotate()
	{
		m_dir = (++m_dir) % 4;
	}

protected:
	void Switch(int x,int y)			//用于自定义形状
	{
		m_matrix[x][y] = !m_matrix[x][y];
	}

private:
	int m_matrix[4][4];
	int m_dir;
	int m_x , m_y;
	int m_color;
};

class Map
{
public:
	Map() throw()
	{
	}
	Map(const Map& p)
	{
		for(int i=0 ;i<10 ;i++)
			for(int j=0 ;j<20 ;j++)
			{
				m_color[i][j] = p.m_color[i][j];
				m_exist[i][j] = p.m_exist[i][j];
			}
	}
	Map(Map &&p)
	{
		for(int i=0 ;i<10 ;i++)
			for(int j=0 ;j<20 ;j++)
			{
				m_color[i][j] = p.m_color[i][j];
				m_exist[i][j] = p.m_exist[i][j];
			}
	}

	void Merge(BaseShape& shape)		//shape触底后合并
	{
		int x = shape.get_x();
		int y = shape.get_y();
		int color = shape.get_color();
		
		for(int i=0 ;i<4 ;i++)
			for(int j=0 ;j<4 ;j++)
			{
				m_color[x+i][y+j] = color;
				m_exist[x+i][y+j] = 1;
			}

	}
	void Eliminate(int y){			//消除单行y
		int i, j;
		for (j=y;j>0;j++)
			for (i=0;i<10;i++)
			{
				m_color[i][j] = m_color[i][j-1];
				m_exist[i][j] = m_exist[i][j-1];		
			}
		for (i=0;i<10;i++)
		{
			m_color[i][0] = 0;
			m_exist[i][0] = 0;		
		}	
	}

private:
	int m_color[10][20];
	int m_exist[10][20];
};

class Board
{
public:
	Board() throw() : m_points(0)
	{
	}
	Board(const Board& b)
	{
		m_points = b.m_points;
		m_next = b.m_next;
	}
	Board(Board &&b)
	{
		m_points = b.m_points;
		m_next = static_cast<BaseShape&&>(b.m_next);
	}
private:
	int m_points;
	BaseShape m_next;
};