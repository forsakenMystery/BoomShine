/*
project boomshine
by: hamed khashechi
email:hkhashechi@yahoo.com
9318953
Copy right! 
all rights reserved!
*/
#include "graphics.h"
#include<stdio.h>
#include<time.h>
#include"stdlib.h"
#include"math.h"
#include<Windows.h>
int width=560;
int height=400;
int goal[12]={1,2,3,5,7,10,15,21,27,33,44,55};
int lvl[12]={5,10,15,20,25,30,35,40,45,50,55,60};
struct Marbles{
	int old_radius;//our old radius
	float new_radius;//for rising
	int old_x;//our old pos. 683=>1366
	int old_y;//our old pos.  384=>768
	int new_x;//our new pos.
	int new_y;//our new pos.
	int velocity_x;//Vx 
	int velocity_y;//Vy
	int color_red;
	int color_green;
	int color_blue;
	bool existance;
	//because of point
	bool rise;
	//without acceleration
}marble[55];
struct Mouse_marble{
	int x;
	int y;
	bool existance;
	int old_radius;
	int new_radius;
	bool rise;//how ever existance=rise i chose to define it
	int color_red;
	int color_green;
	int color_blue;
}mouse_marble;
int power(int x,int y){
	int pow=1;
	while(y>0){
		pow*=x;
		y--;
	}
	return pow;
}
void initialize(int size)
{
	mouse_marble.color_blue=255;
	mouse_marble.color_red=255;
	mouse_marble.color_green=255;
	mouse_marble.old_radius=0;
	mouse_marble.new_radius=mouse_marble.old_radius;
	mouse_marble.rise=true;
	srand(time(NULL));
	for(int i=0;i<size;i++){
		marble[i].old_radius=7;
		marble[i].old_x=rand()%500+25;
		marble[i].old_y=rand()%300+15;
		marble[i].velocity_x=(rand()%3+1)*power(-1,rand()%2);//in 8 second go right
		marble[i].velocity_y=(rand()%6+1)*power(-1,rand()%2);//in 8 second go up
		marble[i].color_red=rand()%255;
		marble[i].color_green=rand()%255;
		marble[i].color_blue=rand()%255;
		marble[i].existance=true;
		marble[i].rise=false;
		marble[i].new_radius=marble[i].old_radius;
	}
}
void move_marble(int size)
{
	for(int i=0;i<size;i++){
		marble[i].new_x=marble[i].old_x;
		marble[i].new_y=marble[i].old_y;
		marble[i].new_x=marble[i].new_x+marble[i].velocity_x;
		marble[i].new_y=marble[i].new_y+marble[i].velocity_y;
		setcolor (0);
		setfillstyle (1,0);// Remove last postion.
		fillellipse (marble[i].old_x,marble[i].old_y,marble[i].new_radius,marble[i].new_radius);
		setfillstyle (1,15); // Display New postion.
		setfillstyle( SOLID_FILL, COLOR(marble[i].color_red,marble[i].color_green,marble[i].color_blue) );
		setcolor(COLOR(marble[i].color_red,marble[i].color_green,marble[i].color_blue));
		fillellipse (marble[i].new_x,marble[i].new_y,marble[i].new_radius,marble[i].new_radius);
		if ( marble[i].new_x - marble[i].old_radius< 0 ){
			marble[i].velocity_x = -marble[i].velocity_x; // Reflect From Top
		}
		if ( marble[i].new_x + marble[i].old_radius> 560 ){
			marble[i].velocity_x = -marble[i].velocity_x; // Reflect From Bottom
		}
		if ( marble[i].new_y - marble[i].old_radius< 0 ){
			marble[i].velocity_y = -marble[i].velocity_y; // Reflect From left
		}
		if ( marble[i].new_y + marble[i].old_radius> 400 ){
			marble[i].velocity_y = -marble[i].velocity_y; // Reflect From right
		}
		marble[i].old_x=marble[i].new_x;
		marble[i].old_y=marble[i].new_y;
	}
}
void Draw_marble(int size){
	for(int i=0;i<size;i++){
		setfillstyle( SOLID_FILL, COLOR(marble[i].color_red,marble[i].color_green,marble[i].color_blue) );
	setcolor(COLOR(marble[i].color_red,marble[i].color_green,marble[i].color_blue));
	fillellipse(marble[i].old_x,marble[i].old_y, marble[i].old_radius, marble[i].old_radius);}
}
float square(unsigned int a){
	float sqr=0;
	int i=1;
	while(power(i,2)<=a)
		i++;
	i--;
	float guess=i;
	int k=8;
	while(k>0){
		sqr=(float)a/guess;
		sqr+=guess;
		guess=sqr/2;
		k--;
	}
	sqr=guess;
	return sqr;
}
void colision_detected(int size){
	for(int i=0;i<size;i++){
		//int velocity=square(power(marble[i].velocity_x,2)+power(marble[i].velocity_y,2));
		if(square((power((marble[i].new_x-mouse_marble.x),2))+(power((marble[i].new_y-mouse_marble.y),2)))<=marble[i].new_radius+mouse_marble.new_radius/*+velocity*5/6*/&&(marble[i].rise==true||mouse_marble.rise==true)){
			mouse_marble.rise=true;
			marble[i].rise=true;
		}
		for(int j=0;j<size;j++){
			if(i!=j){
				//int velocity2=square(power(marble[j].velocity_x,2)+power(marble[j].velocity_y,2));
				if(square((power((marble[i].new_x-marble[j].new_x),2))+(power((marble[i].new_y-marble[j].new_y),2)))<=marble[i].new_radius+marble[j].new_radius/*+velocity2*5/6*/&&(marble[i].rise==true||marble[j].rise==true)){
					marble[i].rise=true;
					marble[j].rise=true;
				}
			}
		}
	}
}
//vase behtar kardan bayad velocity hazf baad sorato biari paeen
void menu(int x,int y){
	cleardevice();
	setcolor(BLACK);
	setbkcolor(BLACK);
	cleardevice();
	setcolor(LIGHTBLUE);
	setbkcolor(MAGENTA);
	settextstyle(4,HORIZ_DIR,2);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	outtextxy(270,50,"BOOMshine");
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,RED);
	bar3d(180,100,360,150,5,1);
	setcolor(BLUE);
	settextstyle(4,HORIZ_DIR,2);
	if(x>180&&x<360&&y<150&&y>100)
	setbkcolor(LIGHTGREEN);
	else
	setbkcolor(RED);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	outtextxy(270,112,"Start");
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,RED);
	bar3d(180,200,360,250,5,1);
	setcolor(BLUE);
	settextstyle(4,HORIZ_DIR,2);
	if(x>180&&x<360&&y<250&&y>200)
	setbkcolor(LIGHTGREEN);
	else
	setbkcolor(RED);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	outtextxy(270,212,"About");
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,RED);
	bar3d(180,300,360,350,5,1);
	setcolor(BLUE);
	settextstyle(4,HORIZ_DIR,2);
	if(x>180&&x<360&&y<350&&y>300)
	setbkcolor(LIGHTGREEN);
	else
	setbkcolor(RED);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	outtextxy(270,312,"Exit");
}
void about(){
	cleardevice();
	setbkcolor(BLACK);
	setcolor(YELLOW);
	settextstyle(0,HORIZ_DIR,0);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	outtextxy(280,30,"Boomshine is an addictive casual game.");
	outtextxy(280,80,"Touch the screen to start a chain");
	outtextxy(280,130," reaction and try to explode as many");
	outtextxy(280,180," dots as neededto pass a level. The game");
	outtextxy(280,230," contains 12 levels ranging from the easy");
	outtextxy(280,280," to the hard(25 tries on average to beat ");
	outtextxy(280,330,"level12).if you're ready to play touch it.");
	outtextxy(280,380,"right click to game and leftclick to menu!");
}
/////////////////////////////////////
void play(int size[]){
	clearmouseclick(WM_LBUTTONUP);
	clearmouseclick(WM_RBUTTONUP);
	int point=0;
	int m=0;
	cleardevice();
	setfillstyle(1,0);
	setbkcolor(BLACK);
	cleardevice();
	setfillstyle(0,0);
	setbkcolor(BLACK);
	Sleep(1000);
	setfillstyle(1,15);
	do{
	int gold;
	do{
	int counter=0;
	cleardevice();
	setfillstyle(1,0);
	setbkcolor(BLACK);
	cleardevice();
	setfillstyle(0,0);
	setbkcolor(BLACK);
	setfillstyle(1,15);
	initialize(size[m]);
	Draw_marble(size[m]);
	do{
	move_marble(size[m]);
	Sleep(37);
	}while(!(ismouseclick(WM_LBUTTONUP)));
		getmouseclick(WM_LBUTTONUP, mouse_marble.x, mouse_marble.y);
		if((mouse_marble.y >= 0) && (mouse_marble.y <= 400) && (mouse_marble.x >=0) && (mouse_marble.x <=560)){ //khareje safhe
			mouse_marble.existance=true;
		}//chera vabaste be on shod?
		bool rise=true;
		while(rise){
		setbkcolor(BLACK);
		setfillstyle( SOLID_FILL,WHITE );
		setcolor(COLOR(mouse_marble.color_red,mouse_marble.color_green,mouse_marble.color_blue));
		fillellipse(mouse_marble.x,mouse_marble.y, mouse_marble.new_radius, mouse_marble.new_radius);
		colision_detected(size[m]);
		mouse_marble.new_radius++;
		move_marble(size[m]);
		for(int i=0;i<size[m];i++){
			if(marble[i].rise){
			marble[i].new_radius++;
			marble[i].velocity_x=0;
			marble[i].velocity_y=0;
			if(marble[i].new_radius>40){
					marble[i].rise=false;
					marble[i].existance=false;
					marble[i].color_blue=0;// Remove last postion.
					marble[i].color_red=0;
					marble[i].color_green=0;//rgb
					setfillstyle( SOLID_FILL, COLOR(marble[i].color_red,marble[i].color_green,marble[i].color_blue) );
					setcolor(COLOR(marble[i].color_red,marble[i].color_green,marble[i].color_blue));
					fillellipse(marble[i].new_x,marble[i].new_y, marble[i].new_radius, marble[i].new_radius);

				}
			}
		}
		Sleep(35);
		for(int i=0;i<size[m];i++){
			if(marble[i].new_radius>40){
				marble[i].rise=marble[i].existance=false;
			}
			if(!(marble[i].existance)){
				marble[i].new_radius=0;
				marble[i].new_x=-100;
				marble[i].new_y=-100;
			}
		}
		if(mouse_marble.new_radius>40){
			mouse_marble.rise=false;
			mouse_marble.existance=false;
			mouse_marble.color_blue=0;
			mouse_marble.color_green=0;
			mouse_marble.color_red=0;

		}
		if(!(mouse_marble.existance)){
			setfillstyle( SOLID_FILL, BLACK );
			setcolor(BLACK);
			fillellipse(mouse_marble.x,mouse_marble.y, mouse_marble.new_radius, mouse_marble.new_radius);
				mouse_marble.new_radius=0;
				mouse_marble.x=-100;
				mouse_marble.y=-100;
		}
		if(!(mouse_marble.rise)){
			int l=0;
			while(l<=size[m]-1){
				if(!(marble[l].rise)){
					l++;
				if(l==size[m]-1){
					rise=false;
				}
			}
				else break;
			}
		}
		Sleep(5);
	}
		cleardevice();
		Draw_marble(size[m]);
	for(int i=0;i<size[m];i++){
		if(marble[i].existance==false){
			counter++;
		}
	}
	gold=counter;
	Draw_marble(size[m]);
	Sleep(1000);
	}while(gold<goal[m]);
	m++;
	point+=gold;
	cleardevice();
	setfillstyle(1,0);
	setbkcolor(BLACK);
	cleardevice();
	setfillstyle(0,0);
	setbkcolor(BLACK);
	setcolor(WHITE);
	outtextxy(280,200,"congrate !wait for next level!");
	Sleep(2000);
	setfillstyle(1,15);
	}while(m<12);
	Sleep(2000);
	cleardevice();
	//int main(int argc, char** argv)
	setcolor(YELLOW);
	settextstyle(4,HORIZ_DIR,2);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	outtextxy(200,200,"Wait for calculating your point");
	outtextxy(200,250,"i will show it in consol");
	Sleep(3000);
	closegraph();
	printf("%d is your point!!",point);
	Sleep(4500);
}
/////////////////////////////////
int main(void){
	int gd,gm,click,x,y;
	bool show_menu=true;
	gd=DETECT;
	initgraph(&gd,&gm,":..\\bgi");
	initwindow(width,height, "BoomShine");
	do{
	getmouseclick(WM_MOUSEMOVE,x,y);
	menu(x,y);
	Sleep(3000);
	clearmouseclick(WM_MOUSEMOVE);
	if(ismouseclick(WM_LBUTTONDOWN))
	getmouseclick(WM_LBUTTONDOWN,x,y);
	int temp;
	if(x>180&&x<360&&y<250&&y>200){
		menu(x,y);
		do{
		Sleep(1500);
		clearmouseclick(WM_RBUTTONUP);
		clearmouseclick(WM_LBUTTONUP);
		cleardevice();
		setbkcolor(BLACK);
		about();
		Sleep(2500);
		}while(!(ismouseclick(WM_RBUTTONUP)||ismouseclick(WM_LBUTTONUP)));
		if(ismouseclick(WM_RBUTTONUP)){
			y=110;
			temp=y;
		}
		else if(ismouseclick(WM_LBUTTONUP)){
			y=4000;
			temp=y;
		}
	clearmouseclick(WM_LBUTTONUP);
	clearmouseclick(WM_RBUTTONUP);
	}
	if(x>180&&x<360&&((y<150&&y>100)||(temp<150&&temp>100))){
	menu(x,y);
	Sleep(1500);
	cleardevice();
	setbkcolor(BLACK);
	play(lvl);
	return 0;
	}
	if(x>180&&x<360&&y<350&&y>300)
		show_menu=false;
	clearmouseclick(WM_MOUSEMOVE);
	clearmouseclick(WM_LBUTTONUP);
	clearmouseclick(WM_RBUTTONUP);
	}while(show_menu);
	menu(200,320);
	Sleep(1500);
}