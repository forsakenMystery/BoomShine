/*
buzinga dear bs!!
it is not golow hockey it is: 
boomshine!
*/

/*
project boomshine
by: hamed khashechi
email:hkhashechi@yahoo.com
9318953
Copy right! 
all rights reserved!
*/
/*
#include "graphics.h"
//#include<glut.h>
#include<stdio.h>
#include<time.h>
#include"stdlib.h"
#include<math.h>
#include<Windows.h>

int width=400;
int height=560;

struct Marbles{
	int old_radius;//our old radius
	int new_radius;//for rising
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
	//without acceleration
}marble[5];

int power(int x,int y){
	int pow=1;
	while(y>0){
		pow*=x;
		y--;
	}
	return pow;
}

void initialize()
{
	srand(time(NULL));
	for(int i=0;i<5;i++){
		marble[i].old_radius=7;
		marble[i].old_x=rand()%400+1;
		marble[i].old_y=rand()%560+1;
		marble[i].velocity_x=(rand()%8+1)*power(-1,rand()%2);//in 8 second go right
		marble[i].velocity_y=(rand()%4+1)*power(-1,rand()%2);//in 8 second go up
		marble[i].color_red=rand()%255;
		marble[i].color_green=rand()%255;
		marble[i].color_blue=rand()%255;
	}
}

void move_marble()
{
	
	for(int i=0;i<5;i++){
		marble[i].new_x=marble[i].old_x;
		marble[i].new_y=marble[i].old_y;
		marble[i].new_x=marble[i].new_x+marble[i].velocity_x;
		marble[i].new_y=marble[i].new_y+marble[i].velocity_y;
		setcolor (0);
		setfillstyle (1,0);// Remove last postion.
		fillellipse (marble[i].old_x,marble[i].old_y,marble[i].old_radius,marble[i].old_radius);
		setfillstyle (1,15); // Display New postion.
		setfillstyle( SOLID_FILL, COLOR(marble[i].color_red,marble[i].color_green,marble[i].color_blue) );
		setcolor(COLOR(marble[i].color_red,marble[i].color_green,marble[i].color_blue));
		fillellipse (marble[i].new_x,marble[i].new_y,marble[i].old_radius,marble[i].old_radius);
		if ( marble[i].new_y - marble[i].old_radius< 0 ){
			marble[i].velocity_y = -marble[i].velocity_y; // Reflect From Top
		}
		if ( marble[i].new_y + marble[i].old_radius> 560 ){
			marble[i].velocity_y = -marble[i].velocity_y; // Reflect From Bottom
		}
		if ( marble[i].new_x - marble[i].old_radius< 0 ){
			marble[i].velocity_x = -marble[i].velocity_x; // Reflect From Top
		}
		if ( marble[i].new_x + marble[i].old_radius> 400 ){
			marble[i].velocity_x = -marble[i].velocity_x; // Reflect From Bottom
		}

		marble[i].old_x=marble[i].new_x;
		marble[i].old_y=marble[i].new_y;
	}
	

}

struct Mouse_marble{
	int x;
	int y;
	bool existance;
	int old_radius;
	int new_radius;
	bool rise;//how ever existance=rise i chose to define it
}mouse_marble;


void Draw_marble(void){
	for(int i=0;i<5;i++){
		setfillstyle( SOLID_FILL, COLOR(marble[i].color_red,marble[i].color_green,marble[i].color_blue) );
	setcolor(COLOR(marble[i].color_red,marble[i].color_green,marble[i].color_blue));
	fillellipse(marble[i].old_x,marble[i].old_y, marble[i].old_radius, marble[i].old_radius);}
}

int main(int argc, char** argv){
	initialize();
	initwindow(width,height, "BoomShine");
	Draw_marble();
		do{
	move_marble();
	Sleep(70);
	}while(!(ismouseclick(WM_LBUTTONUP)));
		getmouseclick(WM_LBUTTONUP, mouse_marble.x, mouse_marble.y);
		if((mouse_marble.x >= 0) && (mouse_marble.x <= 400) && (mouse_marble.y >=0) && (mouse_marble.x <=560)){ //khareje safhe
			mouse_marble.existance=true;
		}
			mouse_marble.old_radius=0;
	mouse_marble.new_radius=mouse_marble.old_radius;
	while(1){
	move_marble();
	setfillstyle( SOLID_FILL,WHITE );
		setcolor(WHITE);
		fillellipse(mouse_marble.x,mouse_marble.y, mouse_marble.new_radius, mouse_marble.new_radius);
		mouse_marble.new_radius++;
			if(mouse_marble.new_radius>40){
				break;
			}
			Sleep(70);
	}
	return 0;
}
*/


/*
int main( )
{
    initwindow(400, 300, "First Sample");
	setfillstyle( SOLID_FILL, COLOR(250,0,0) );
	setcolor(COLOR(250,0,0));
	fillellipse(50,50, 7, 7);//lol :D

	/*for(float i=0;i<=8;i+=.001){
		setcolor(COLOR(250,0,0));
    circle(50, 50, i);
	}
    while (!kbhit( ))
    {
        delay(200);
    }
    return 0;
}
*/