#include "CustomModel.h"
class MapEdit
{
public:
	MapEdit() :x(0), y(0) {};  //x,y  位格子地图左上角
	/*void update(reference poniter p，reference poniter s)
	{
		map=p;
		//接下来对shape的位置进行读取，然后存入map中
		//for(m=0;m<4;m++)
		//for(i=0;i<4;i++)
		//map.block[m][i]=s->block[m][i];
	} 
	void drawsingle()
	{
		initgraph( 640, 480 );
		for(int i=0;i<N;i++)
		{
			switch(map.block[i].color)
			{
				case 1:
					setfillcolor(EGEARGB(0xff, 0xff, 0x0, 0xff));
					break;
				case 2:
					setfillcolor(EGEARGB(0xff, 0xff, 0x0, 0xff));
					break;
					//so on
			}
			bar(x+i*width,y+i*height,x+i*width+width,y+i*height+height,pigmage);
		}
		//接下来画信息板

	}*/
	void drawsingle(BaseShape & cusshape)   //这里还需要一个参数，用于viewmodel传参（鼠标点击参数）
	{
		setfont(15,8,"Times New Roman");
		outtextrect(150,100,400,100,"set block for yourself");
		outtextrect(150, 130, 400, 200, "choose four square as your blockst, press space for sure");
		outtextrect(150, 160, 400, 100, "(left for sure, right for cancel)");
		setcolor(EGERGB(80, 80, 80));
		int BY = 200;
		int BX = 200;
		for (y = BY; y <= 400; y += 50) {           //横线
			line(BX, y, BX + 200, y);
		}
		for (x = BX; x <= 400; x += 50) {           //竖线
			line(x, BY, x, BY + 200);
		}
		//setfillcolor();
		
		setfillcolor(EGERGB(0xFF, 0x0, 0x80));
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				if(cusshape.get_matrix(i,j))
					bar(200+i*50, 200+j*50, 250+i*50, 250+j*50);
		

	}
	void initial_single(CustomShape & cusshape)
	{
		int count = 0;
		int flag = 0;
		while (1) 
		{
			
			drawsingle(cusshape);
			cusshape.getCustomShape(count);
			
		}
	}
	void draw()
	{
		
		PIMAGE img;
		img = newimage();
		getimage(img,"e:\\dog.jpg");
		putimage(220, 10,img);
		setfont(15, 8, "Times New Roman");
		outtextrect(230, 160, 400, 100, "choose one mode");
		outtextrect(250, 220, 400, 100, "single");
		outtextrect(250, 240, 400, 100, "double");
		outtextrect(260, 260, 400, 100, "bot");
		rectangle(245,220,300,240);
	}
	void drawmain()
	{

	}
private:
	
	int x, y;
};