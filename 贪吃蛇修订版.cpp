#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<time.h>
struct Snake 
{
	int x,y;//每个结点中心的横纵坐标 
	Snake*next;
};
int site_s[100][2];
int dw;
void drawpicture1()
{
	setfillcolor(EGERGB(0xFE,0x49,0x50));
	fillellipse(680,300,80,80); 
	bar(680,220,800,380);
	setfillcolor(WHITE);
	setcolor(EGERGB(0xFE,0x49,0x50));
	fillellipse(660,260,35,35);
	fillellipse(660,340,35,35);
	setfillcolor(BLACK);
	setcolor(WHITE);
	fillellipse(660,260,20,20);
	fillellipse(660,340,20,20);
	setfillcolor(WHITE);
	fillellipse(650,246,8,8);
	fillellipse(650,326,8,8);
}
void drawpicture2()
{
	setfillcolor(EGERGB(0x5C,0xAA,0x3E));
	fillellipse(170,120,80,80); 
	bar(90,0,250,120);
	setfillcolor(WHITE);
	setcolor(EGERGB(0x5C,0xAA,0x3E));
	fillellipse(130,140,35,35);
	fillellipse(210,140,35,35);
	setfillcolor(BLACK);
	setcolor(WHITE);
	fillellipse(130,140,20,20);
	fillellipse(210,140,20,20);
	setfillcolor(WHITE);
	fillellipse(116,150,8,8);
	fillellipse(196,150,8,8);
}
void drawpicture()
{
	for(int i=20;i<800;i+=40)
	{
		setcolor(EGERGB(0x5C,0xAA,0x3E));
		line(i,520,i-20,600);
        line(i,520,i+20,600);
	    line(i-20,600,i+20,600);
	    setfillcolor(EGERGB(0x5C,0xAA,0x3E));
	    floodfill(i,540,EGERGB(0x5C,0xAA,0x3E));
	}
}
void drawwall()
{
	PIMAGE img_wall=newimage(); 
    getimage(img_wall, "D:/private_software/wall.png"); 
	for(int i=30;i<530;i+=20)
	{                        // 声明一个图片对象
        putimage(i, 30, img_wall);
    }
    for(int i=30;i<530;i+=20)
	{                        // 声明一个图片对象
        putimage(i, 490, img_wall);
    }
    for(int j=30;j<480;j+=20)
	{                        // 声明一个图片对象
        putimage(30,j, img_wall);
    }
    for(int j=30;j<480;j+=20)
	{                        // 声明一个图片对象
        putimage(510,j, img_wall);
    }
    
}
void drawwu()
{
		PIMAGE img_wuya=newimage(); 
        getimage(img_wuya, "D:/private_software/wuya.png"); 
        for(int i=550;i>-400;i-=50)
        {
        	putimage(i,250, img_wuya);
            Sleep(150);	
		}    
}
void drawfood(int xfood,int yfood)
{
	PIMAGE img=newimage(); 
    getimage(img, "D:/private_software/china.png");                         // 声明一个图片对象
    putimage(xfood, yfood, img);  
}
void drawhead(int x,int y)
{
	PIMAGE img_head=newimage(); 
    getimage(img_head, "D:/private_software/snakeHead.jpg"); 
    putimage(x, y, img_head);
}
void drawbody(int x,int y)
{
	PIMAGE img_body=newimage(); 
    getimage(img_body, "D:/private_software/snakeTail.png"); 
    putimage(x, y, img_body);
}
void drawline()
{
	setcolor(BLUE);
	for(int i=54;i<500;i+=18)
	{
		line(48,i,510,i);
	}
	for(int j=54;j<510;j+=18)
	{
		line(j,48,j,490);
	}
}
//void drawwu();
void drawchoose()
{
	setfillcolor(EGERGB(0xE4,0xDD,0xA0));
	setcolor(WHITE);
	bar(300,50,500,150);
	bar(300,250,500,350);
	bar(300,450,500,550);
	outtextxy(320,75,"简单模式");
	outtextxy(320,275,"困难模式");
	outtextxy(320,475,"地狱模式"); 
}
void background ()       		//背景
{
	setbkcolor(EGERGB(0x9D, 0xE1, 0x83));
	setfillcolor(BLACK);
	bar(30,30,520,500);
	bar(30,30,530,480);
	drawwall();
	drawline();
    setcolor(WHITE); 
	setfont(30,0,"宋体");
	outtextxy(600,250,"得分：");
	outtextxy(600,50,"按空格键暂停");
	outtextxy(600,100,"按回车键继续");
	drawpicture(); 
}
int score=0;
Snake*head,*end,*p,*q;
void creat()
{
	end=(Snake*)malloc(sizeof(Snake));
	end->x=90;
	end->y=90;
	end->next=NULL;
	drawhead(end->x,end->y);
	drawline();
	for(int i=0;i<3;i++)
	{
		head=(Snake*)malloc(sizeof(Snake));
	    head->x=end->x+18;
	    head->y=end->y;
	    head->next=end;
	    drawhead(head->x,head->y);
	    drawbody(end->x,end->y);
	    drawline();
	    end=head;
	}	
}
void freeend(Snake*head)
{
	q=head;
	while(q->next==NULL)
	{
		setfillcolor(BLACK);
		bar(q->x-1,q->y-1,q->x+18,q->y+18);
		free(q);
	}
}
int xfood,yfood;
void endgame(int x)
{
	cleardevice();
	setcolor(WHITE);
	setbkcolor(BLACK);
	switch(x)
	{
		case 1:
		setfont(50,0,"宋体");
		outtextxy(100,150,"游戏结束，撞到墙了T_T");
		drawwu();
		setfont(30,0,"宋体");
		outtextxy(300,350,"按任意键继续···");
		getch();
		//goto chongxin;
		cleardevice();
		break;
		case 2:
		setfont(50,0,"宋体");
		outtextxy(100,150,"游戏结束，撞到自己了T_T");
		drawwu();
		setfont(30,0,"宋体");
		outtextxy(300,350,"按任意键继续···");
		getch();
		//goto chongxin;
		cleardevice();
		break;
		case 3:
		setfont(50,0,"宋体");
		outtextxy(100,150,"游戏结束，撞到障碍物了T_T");
		drawwu();
		setfont(30,0,"宋体");
		outtextxy(300,350,"按任意键继续···");
		getch();
		//goto chongxin;
		cleardevice();
		break;	
	}
	setfont(100,0,"华文彩云");
    outtextxy(100,150,"GAME OVER!");
	setfont(50,0,"宋体");
	outtextxy(200,300,"最终的得分为：");
	char a[10];
    itoa(score,a,10);
	outtextxy(550,300,a);
	setfont(30,0,"宋体");
	outtextxy(300,400,"按任意键继续···");
}
int move(PIMAGE img,int dif)
{
	while(1)
	{
		//delay_fps(10);
		int dir;
		if(keystate(key_down)&&dir!=key_up)
     	{
		    dir=key_down;	
		}
	    else if(keystate(key_right)&&dir!=key_left)
    	{
	        dir=key_right;
    	}
    	else if(keystate(key_up)&&dir!=key_down)
     	{
	        dir=key_up;
    	}
    	else if(keystate(key_left)&&dir!=key_right)
     	{
	        dir=key_left;
    	}
    	delay_fps(80);
    	p=(Snake*)malloc(sizeof(Snake));
	    p->next=head;
	    switch(dir)
	    {
	    	case key_down:
	    		p->x=head->x;
     	        p->y=head->y+18;
     	        break;
     	    case key_up:
     	    	p->x=head->x;
     	        p->y=head->y-18;
     	        break;
     	    case key_right:
     	    	p->x=head->x+18;
     	        p->y=head->y;
     	        break;
     	    case key_left:
     	    	p->x=head->x-18;
     	        p->y=head->y;
     	        break;
		}
	    drawhead(p->x,p->y);
	    drawbody(p->next->x,p->next->y);
	    drawline();
    	head=p;
	    if((head->x==xfood&&head->y==yfood))//吃到食物 
    	{   
    	    int xf,yf;
        	score+=10;
        	setcolor(WHITE);
        	setfont(30,0,"宋体");
        	char a[10];
        	itoa(score,a,10);
        	setfillcolor(EGERGB(0x9D, 0xE1, 0x83));
        	bar(690,240,780,285);
	        outtextxy(700,250,a);
	        /*setcolor(YELLOW);
	        setfont(50,0,"幼圆");
	        outtextxy(600,50,"GREAT");
	        Sleep(300);
	        setfillcolor(BLACK);
	        bar(590,40,800,200);*/
    		//food();
    		flag:
    		srand(time(0));
        	xf = rand()%(25+1-3)+3;	//随机rand()%100  ~~  [0~99]
	        yf = rand()%(22+1-3)+3;
	        xfood=xf*18;
	        yfood=yf*18;
	        q=head;
	        while(q->next!=NULL)
	        {
	        	if(q->x==xfood&&q->y==yfood)
	        	{
	        		goto flag;
				}
				q=q->next;
			}
			for(int i=0;i<100;i++)
			{
				if(xfood==site_s[i][0]&&yfood==site_s[i][1])goto flag;
			}
			if((xfood>=90&&xfood<=180)&&yfood==90)goto flag;
	        drawfood(xfood,yfood);
	        drawline();
	    }
	    else{
			while(p->next->next!=NULL) p=p->next;	
		    setfillcolor(EGERGB(0,0,0));
	   	    bar(p->next->x,p->next->y,p->next->x+18,p->next->y+18);
		    free(p->next);				//释放蛇尾
	   	    p->next=NULL;
	   	    p=head;
			}
	   	    delay_fps(dif);
	   	if (head->x<=50 || head->x>=500 || head->y<=50 || head->y>=470) 
		   {
		   	    endgame(1);
		   	    return 0;
		   }
		for(int i=0;i<20;i++)
		{
			if(head->x==site_s[i][0]&&head->y==site_s[i][1])
			{
				endgame(3);
				return 0;
			}
		}
		q=head;
		while(q->next!=NULL)
		{
			q=q->next;
			if(head->x==q->x&&head->y==q->y)
			{
				endgame(2);
				return 0;
			}	
		} 
		if(keystate(32))
		{
			while(1)
			{
				if(keystate(key_enter))
				{
					delay_fps(15);
					break;
				}
			}
		}  
    }
}
int main()
{
	int xf,yf;
	initgraph(800,600);
	
	chongxin:
	score=0;
	for(int i=0;i<100;i++)
	{
		site_s[i][0]=0;
		site_s[i][1]=0;
	}
	setbkcolor(EGERGB(0x9D, 0xE1, 0x83));
	setfont(100,0,"华文彩云");
	outtextxy(250,150,"贪吃蛇");
	drawpicture();
	drawpicture1();
	drawpicture2();
	setfont(40,0,"宋体");
	setfillcolor(EGERGB(0xE4,0xDD,0xA0));
	bar(300,300,500,400);
	setcolor(WHITE) ;
	setbkmode(TRANSPARENT);
	outtextxy(320,320,"开始游戏") ; 
	                       // 获取鼠标消息当前坐标点
    mouse_msg msg = {0};                            // 声明一个保存鼠标消息的结构体
    for ( ; is_run(); delay_fps(60))                // 判断窗口是否存在,delay_fps（60）动画播放帧
    {   while (mousemsg())                          // 等到鼠标消息
        {   msg = getmouse();                    // 获取鼠标消息信息
            if((msg.is_down() && msg.is_left())&&(msg.x>=300&&msg.x<=500&&msg.y>=300&&msg.y<=400))goto start;      // 左键按下
        }                                   
    }
	getch();
	start:
	cleardevice();
	drawpicture();
	drawpicture1();
	setfont(50,0,"宋体");
	outtextxy(50,100,"游戏规则：");
	setfont(30,0,"宋体");
	outtextxy(70,200,"1、通过方向键控制蛇的运动方向");
	outtextxy(70,300,"2、蛇头碰到身体或墙壁则游戏结束");
	outtextxy(70,400,"3、每个食物吃到得10分");
	setfont(40,0,"宋体");
	setfillcolor(EGERGB(0xE4,0xDD,0xA0));
	bar(500,400,650,500);
	setcolor(WHITE) ;
	setbkmode(TRANSPARENT);
	outtextxy(530,430,"PLAY"); 
	for ( ; is_run(); delay_fps(60))                // 判断窗口是否存在,delay_fps（60）动画播放帧
    {   while (mousemsg())                          // 等到鼠标消息
        {   msg = getmouse();                       // 获取鼠标消息信息
            if((msg.is_down() && msg.is_left())&&(msg.x>=500&&msg.x<=650&&msg.y>=400&&msg.y<=500))goto start1;      // 左键按下
        } 
    }
    start1:
    cleardevice();
    drawpicture();
    drawpicture1();
    drawpicture2();
    drawchoose();
	int dif;
	int nums;
	for ( ; is_run(); delay_fps(60))                // 判断窗口是否存在,delay_fps（60）动画播放帧
    {   while (mousemsg())                          // 等到鼠标消息
        {   msg = getmouse();  
		                     // 获取鼠标消息信息
            if((msg.is_down() && msg.is_left())&&(msg.x>=300&&msg.x<=500&&msg.y>=50&&msg.y<=150))
			{
				nums=1;
			    dif=8;
				goto start2; 
			}
			else if((msg.is_down() && msg.is_left())&&(msg.x>=300&&msg.x<=500&&msg.y>=250&&msg.y<=350)) 
			{
				nums=3;
				dif=10;
				goto start2;
			}
			else if((msg.is_down() && msg.is_left())&&(msg.x>=300&&msg.x<=500&&msg.y>=450&&msg.y<=550))    // 左键按下
            {
            	dif=15;
            	nums=5;
            	goto start2;
			}
		} 
    }
    
    start2:
    cleardevice();
	background();
	creat(); 
	flag:
	srand(time(0));
	xf = rand()%(25+1-3)+3;	//随机rand()%100  ~~  [0~99]
	yf = rand()%(22+1-3)+3;
	xfood=xf*18;
	yfood=yf*18;
	PIMAGE img=newimage(); 
    getimage(img, "D:/private_software/china.png");                         // 声明一个图片对象
    putimage(xfood, yfood, img); 
	int a,b,astone,bstone;
	PIMAGE img_wall=newimage(); 
    getimage(img_wall, "D:/private_software/wall.png");
    int d=0;
	for(int j=0;j<nums;j++)
	{
		re:
		a=rand()%(25+1-3)+3;
	    b=rand()%(22+1-3)+3;
	    int t=rand()%(10+1-3)+3;
	    astone=a*18;
	    bstone=b*18;
	    for(int i=0;i<t;i++)
	    {
	    	if(astone<30||astone>500||bstone<30||bstone>480||((astone>=80&&astone<=150)&&(bstone>=80&&bstone<=100)))
	    	{
	    		goto re;
			}
	    	putimage(astone, bstone, img_wall);
	    	site_s[d][0]=astone;
	    	site_s[d][1]=bstone;
	    	d++;
	    	astone+=18;
	    }     
	}
	getch();
	move(img,dif);
    getch();
    cleardevice();
	goto chongxin;
	closegraph();	
}
