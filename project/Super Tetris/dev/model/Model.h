#pragma once

#include <string>
#include <vector>

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

class BaseShape
{
public:
	BaseShape() throw() : m_dir(0)
	{	
	}
	BaseShape(const BaseShape& b)
	{
		m_dir = b.m_dir;
		for(int i=0 ;i<4 ;i++)
			for(int j=0 ;j<4 ;j++)
				m_matrix[i][j] = b.m_matrix[i][j];
	}
	BaseShape(BaseShape&& b)
	{
		m_dir = b.m_dir;
		for(int i=0 ;i<4 ;i++)
			for(int j=0 ;j<4 ;j++)
				m_matrix[i][j] = static_cast<Block&&>(b.m_matrix[i][j]);
	}

	void Rotate()
	{
		m_dir = (++m_dir) % 4;
	}
private:
	Block m_matrix[4][4];
	int m_dir;
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
				m_map[i][j] = p.m_map[i][j];
				m_exist[i][j] = p.m_exist[i][j];
			}
	}
	Map(Map &&p)
	{
		for(int i=0 ;i<10 ;i++)
			for(int j=0 ;j<20 ;j++)
			{
				m_map[i][j] = static_cast<Block&&>(p.m_map[i][j]);
				m_exist[i][j] = p.m_exist[i][j];
			}
	}

private:
	Block m_map[10][20];
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
		m_next = static_cast<BaseShape&&>(b.m_next)
	}
private:
	int m_points;
	BaseShape m_next;
}