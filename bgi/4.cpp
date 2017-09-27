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
#include<stdio.h>
#include<time.h>
#include"stdlib.h"
#include"math.h"
#include<Windows.h>
int width=400;
int height=560;
int counter=0;
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
}marble[25];
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
void initialize()
{
	mouse_marble.color_blue=255;
	mouse_marble.color_red=255;
	mouse_marble.color_green=255;
	mouse_marble.old_radius=0;
	mouse_marble.new_radius=mouse_marble.old_radius;
	mouse_marble.rise=true;
	srand(time(NULL));
	for(int i=0;i<25;i++){
		marble[i].old_radius=7;
		marble[i].old_x=rand()%300+15;
		marble[i].old_y=rand()%500+25;
		marble[i].velocity_x=(rand()%8+2)*power(-1,rand()%2);//in 8 second go right
		marble[i].velocity_y=(rand()%4+2)*power(-1,rand()%2);//in 8 second go up
		marble[i].color_red=rand()%255;
		marble[i].color_green=rand()%255;
		marble[i].color_blue=rand()%255;
		marble[i].existance=true;
		marble[i].rise=false;
		marble[i].new_radius=marble[i].old_radius;
	}
}
void move_marble()
{
	for(int i=0;i<25;i++){
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
		if ( marble[i].new_y - marble[i].old_radius< 0 ){
			marble[i].velocity_y = -marble[i].velocity_y; // Reflect From Top
		}
		if ( marble[i].new_y + marble[i].old_radius> 560 ){
			marble[i].velocity_y = -marble[i].velocity_y; // Reflect From Bottom
		}
		if ( marble[i].new_x - marble[i].old_radius< 0 ){
			marble[i].velocity_x = -marble[i].velocity_x; // Reflect From left
		}
		if ( marble[i].new_x + marble[i].old_radius> 400 ){
			marble[i].velocity_x = -marble[i].velocity_x; // Reflect From right
		}
		marble[i].old_x=marble[i].new_x;
		marble[i].old_y=marble[i].new_y;
	}
}
void Draw_marble(void){
	for(int i=0;i<25;i++){
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
void colision_detected(void){
	for(int i=0;i<25;i++){
		int velocity=square(power(marble[i].velocity_x,2)+power(marble[i].velocity_y,2));
		if(square((power((marble[i].new_x-mouse_marble.x),2))+(power((marble[i].new_y-mouse_marble.y),2)))<=marble[i].new_radius+mouse_marble.new_radius+velocity&&(marble[i].rise==true||mouse_marble.rise==true)){
			mouse_marble.rise=true;
			marble[i].rise=true;
		}
		for(int j=0;j<25;j++){
			if(i!=j){
				int velocity2=square(power(marble[j].velocity_x,2)+power(marble[j].velocity_y,2));
				if(square((power((marble[i].new_x-marble[j].new_x),2))+(power((marble[i].new_y-marble[j].new_y),2)))<=marble[i].new_radius+marble[j].new_radius+velocity2&&(marble[i].rise==true||marble[j].rise==true)){
					marble[i].rise=true;
					marble[j].rise=true;
				}
			}
		}
	}
}
int main(void){
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,":..\\bgi");
	char counter1=48;
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
		else{
			cleardevice();
			setcolor(RED);
			settextstyle(4,HORIZ_DIR,4);
			settextjustify(CENTER_TEXT,TOP_TEXT);
			outtextxy(100,200,"wrong!! good bye");
			Sleep(750);
			return 0;
		}
		bool rise=true;
		while(rise){
			setbkcolor(BLACK);
		setfillstyle( SOLID_FILL,WHITE );
		setcolor(COLOR(mouse_marble.color_red,mouse_marble.color_green,mouse_marble.color_blue));
		fillellipse(mouse_marble.x,mouse_marble.y, mouse_marble.new_radius, mouse_marble.new_radius);
		colision_detected();
		mouse_marble.new_radius++;
		move_marble();
		for(int i=0;i<25;i++){
			if(marble[i].rise){aaaa
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
		Sleep(70);
		for(int i=0;i<25;i++){
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
			if(!(marble[0].rise)){
				if(!(marble[1].rise)){
					if(!(marble[2].rise)){
						if(!(marble[3].rise)){
							if(!(marble[4].rise)){
								if(!(marble[5].rise))
									if(!(marble[6].rise))
										if(!(marble[7].rise))
											if(!(marble[8].rise))
												if(!(marble[9].rise))
													if(!(marble[10].rise))
														if(!(marble[11].rise))
															if(!(marble[12].rise))
																if(!(marble[13].rise))
																	if(!(marble[14].rise))
																		if(!(marble[15].rise))
																			if(!(marble[16].rise))
																				if(!(marble[17].rise))
																					if(!(marble[18].rise))
																						if(!(marble[19].rise))
																							if(!(marble[20].rise))
																								if(!(marble[21].rise))
																									if(!(marble[22].rise))
																										if(!(marble[23].rise))
																											if(!(marble[24].rise))
			rise=false;
							}//az shekle pele manandesh khosham omad vaella karesh ye while ke age dorost nabood yeki ezafe age dorost bood brak;
						}
					}
				}
			}
		}
		if(!(mouse_marble.rise)){
			int m=0;
			while(m<=24){
				if(!(marble[m].rise)){
					m++;
				if(m==25){
					rise=false;
				}
			}
				else 
					break;
			}
		}
		Sleep(20);
	}
		cleardevice();
		Draw_marble();
	for(int i=0;i<25;i++){
		if(marble[i].existance==false){
			counter++;
			counter1++;
		}
	}
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
	printf("%d is your point!!",counter);
	Sleep(4500);
	return 0;
}*/