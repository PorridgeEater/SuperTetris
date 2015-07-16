#pragma once

#include <string>
#include <vector>

#define LENGTH	10
#define WIDTH	20

class BaseShape
{
public:

	BaseShape(int color=0) 
	{	
		m_x = 4;
		m_y = 0;
		m_dir = 0;
		m_color = color;
		for(int i=0 ;i<4 ;i++)
			for(int j=0 ;j<4 ;j++)
				m_matrix[i][j] = false;
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
	void move_left()
	{
		m_x--;
	}
	void move_right()
	{
		m_x++;
	}
	void move_down()
	{
		m_y++;
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
	bool get_matrix(int x, int y)
	{
		if((x>=0)&&(x<4)&&(y>=0)&&(y<4))
			return m_matrix[x][y];
		throw();
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
	bool m_matrix[4][4];
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
		for(int i=0 ;i<LENGTH ;i++)
			for(int j=0 ;j<WIDTH ;j++)
			{
				m_color[i][j] = p.m_color[i][j];
				m_exist[i][j] = p.m_exist[i][j];
			}
	}
	Map(Map &&p)
	{
		for(int i=0 ;i<LENGTH ;i++)
			for(int j=0 ;j<WIDTH ;j++)
			{
				m_color[i][j] = p.m_color[i][j];
				m_exist[i][j] = p.m_exist[i][j];
			}
	}

	bool get_color(int x, int y)
	{
		if((x>=0)&&(x<LENGTH)&&(y>=0)&&(y<WIDTH))
			return m_color[x][y];
		throw();
	}
	int get_exist(int x, int y)
	{
		if((x>=0)&&(x<LENGTH)&&(y>=0)&&(y<WIDTH))
			return m_exist[x][y];
		throw();
	}
	void Merge(BaseShape& shape)		//shape触底后合并
	{
		int x = shape.get_x();
		int y = shape.get_y();
		int color = shape.get_color();
		
		for(int i=0 ;i<4 ;i++)
			for(int j=0 ;j<4 ;j++)
			if (shape.get_matrix(i,j))
			{
				m_color[x+i][y+j] = color;
				m_exist[x+i][y+j] = 1;
			}

	}
	void Eliminate(int y){			//消除单行y
		int i, j;
		for (j=y;j>0;j++)
			for (i=0;i<LENGTH;i++)
			{
				m_color[i][j] = m_color[i][j-1];
				m_exist[i][j] = m_exist[i][j-1];		
			}
		for (i=0;i<LENGTH;i++)
		{
			m_color[i][0] = 0;
			m_exist[i][0] = 0;		
		}	
	}
	Map& operator= (const Map& m)
	{
		if(this != &m){
			for(int i=0 ;i<LENGTH ;i++)
				for(int j=0 ;j<WIDTH ;j++)
				{
					m_color[i][j] = m.m_color[i][j];
					m_exist[i][j] = m.m_exist[i][j];
				}
		}
		
		return *this;
	} 
	Map& operator= (Map&& m)
	{
		if(this != &m){
			for(int i=0 ;i<LENGTH ;i++)
				for(int j=0 ;j<WIDTH ;j++)
				{
					m_color[i][j] = m.m_color[i][j];
					m_exist[i][j] = m.m_exist[i][j];
				}
		}
		
		return *this;
	} 
	

private:
	int m_color[LENGTH][WIDTH];
	bool m_exist[LENGTH][WIDTH];
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

	int get_points() const throw()
	{
		return m_points;
	}
	BaseShape& get_next() throw()
	{
		return m_next;
	}
	Board& operator= (const Board& b)
	{
		if(this != &b){
			m_points = b.m_points;
			m_next = b.m_next;
		}
		
		return *this;
	} 
	Board& operator= (Board&& b)
	{
		if(this != &b){
			m_points = b.m_points;
			m_next = static_cast<BaseShape&&>(b.m_next);
		}
		
		return *this;
	} 

private:
	int m_points;
	BaseShape m_next;
};