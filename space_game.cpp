#include<stdio.h>
#include <GL/glut.h>
#include "zeelubha.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>

void processKeyformenu(unsigned char key, int x, int y);
void exitmenu();
void menu();
void draw();
void timer(int value);
void game();
void player();
void astron();
void destroy(float x,float y);
void enemy();
void intro();
void bosslevel();
void boss();
void gaemover();
void gamewin();

// game_panel 0 for main menu
// game_panel 1 for exit menu
// game_panel 2 for main game
// game_panle 3 for boss level intro
// game_panel 4 for boss level
// game_panel 5 for game over menu
// game_panel 6 for win game menu

static int game_panel = 0;
static int select_menu = 1;
static int select_exit = 1;
static int is_gun_fired = 0;

static int score = 0; // score

static int player_x_range = 20; // range of player player movement

static int player_x = 0; // player movement;

//static int player_x_boss_gun = 0; // player gun for boss gun

static int gun_x = 400; // gun x position

static int gun_y = 0; // gun y position

static int gun_range=10; // gun range

static int enemy_move1 = 0; // enemy lower level movement

static int enemy_move_flag1 = 0; // enemy lower level movement flag

static int enemy_move2 = 0; // enemy upper level movement

static int enemy_move_flag2 = 0; // enemy upper level movement flag

static int enemy1_speed = 10; // speed of enemy group 1

static int enemy2_speed = 10; // speed of enemy group 2

static int enemyno[10]={0}; // number of enemy

static int enemy_death_range = 10; // range of blast

static int intro_speed_val = 0; // speed triger for intro

static int intro_speed = 10; // speed value for intro

static int boss_move_triger = 0; // boss movement trigger

static int boss_move = 0; // boss right l;eft movement trigger

static int boss_speed = 20; // boss speed
  
static int boss_fire_triger = 0; // boss gun for trigger

static int boss_fire_speed = 20; // boss gun fire speed

static int boss_x = 0; // x position of boss

static int boss_y = 0; // y position of boss

static int fire_y = 500; // y position of boss gun

static int fire_x = 0; // x position of boss gun

static int boss_death_counter = 0; // counter of boss death

static int boss_health = 5;

void processKeyformenu(unsigned char key, int x, int y)
{
	if(key=='s' && (game_panel==0 || game_panel==5 || game_panel==6) ) // main menu up down
	{
		select_menu++;
	}
	else if(key=='w' && (game_panel==0 || game_panel==5 || game_panel==6) ) // main menu up down
	{
		select_menu++;
		
	}
	else if(key==13 && select_menu%2==0 && (game_panel==0 || game_panel==5 || game_panel==6) ) // main menu exit option select
	{
		game_panel = 1;
	}
	else if(key==13 && select_menu%2!=0 && (game_panel==0 || game_panel==5 || game_panel==6) ) // main menu play option select
	{
		game_panel = 2;
	}
	else if(key=='a' && game_panel==1) // exit meny right left
	{
		select_exit++;
	}
	else if(key=='d' && game_panel==1) // exit menu right left
	{
		select_exit++;
	}
	else if(key==13 && select_exit%2==0 && game_panel==1) // game exit -- exit menu yes
	{
		exit(0);
	}
	else if(key==13 && select_exit%2!=0 && game_panel==1) // game not exit -- exit menu no
	{
		game_panel = 0;
		
	}
	else if(key=='d' && (game_panel==2 || game_panel==4) ) // player movement right
	{
		if(player_x<380)
		{
			player_x += player_x_range;	
		}
	}
	else if(key=='a' && (game_panel==2 || game_panel==4) ) // player movement left
	{
		if(player_x>-380)
		{
			player_x -= player_x_range;	
		}	
	}
	else if(key==27 && (game_panel==2 || game_panel==4) ) // back to the main menu
	{
 		game_panel = 0;
	}
	else if(key==32 && (game_panel==2 || game_panel==4) ) // gun fire
	{
		if(is_gun_fired == 0)
		{
			is_gun_fired = 1;	
			gun_x = 400 + player_x;
		}
	}
	
}

void gamewin()
{
	astron();
	
	glColor3f(1.0,1.0,1.0);
	zeelFontDisplay(330,600,"YOU WON THE GAME");	
	
	glColor3f(1.0,0.0,1.0);
	zeelFontDisplay(380,400,"REPLAY");
	
	glColor3f(0.0,1.0,1.0);
	zeelFontDisplay(380,300,"EXIT");
	
	//select area - rectangle
	
	if(select_menu % 2 == 0 )
	{
		glColor3f(0.0,1.0,1.0);
		zeelRectDisplay(300,280,330,500);	
	}
	else
	{	
		glColor3f(1.0,0.0,1.0);
		zeelRectDisplay(300,380,430,500);
	}
	
	glColor3f(1.0,1.0,1.0);
	zeelFontDisplay(50,50,"FOR UP = W");
	
	glColor3f(1.0,1.0,1.0);
	zeelFontDisplay(300,50,"FOR DOWN = S");
	
	glColor3f(1.0,1.0,1.0);
	zeelFontDisplay(550,50,"FOR SELECT = ENTER");
	
		
	glEnd();
	glFlush();
}

void gameover()
{
	astron();
	
	glColor3f(1.0,1.0,1.0);
	zeelFontDisplay(330,600,"GAME OVER");	
	
	glColor3f(1.0,0.0,1.0);
	zeelFontDisplay(380,400,"RETRY");
	
	glColor3f(0.0,1.0,1.0);
	zeelFontDisplay(380,300,"EXIT");
	
	//select area - rectangle
	
	if(select_menu % 2 == 0 )
	{
		glColor3f(0.0,1.0,1.0);
		zeelRectDisplay(300,280,330,500);	
	}
	else
	{	
		glColor3f(1.0,0.0,1.0);
		zeelRectDisplay(300,380,430,500);
	}
	
	glColor3f(1.0,1.0,1.0);
	zeelFontDisplay(50,50,"FOR UP = W");
	
	glColor3f(1.0,1.0,1.0);
	zeelFontDisplay(300,50,"FOR DOWN = S");
	
	glColor3f(1.0,1.0,1.0);
	zeelFontDisplay(550,50,"FOR SELECT = ENTER");
	
		
	glEnd();
	glFlush();
}

void boss()
{
	if(boss_move_triger==0)
	{
		glColor3f(1.0,0.0,1.0);
		zeelRectDisplay(300+boss_move,500,550,350+boss_move);
		
		boss_x = 300+boss_move;
		
		boss_y = 500;
		
		boss_move += boss_speed;
		
		if(boss_move > 400)
		{
			boss_move_triger=1;
		}
	}
	
	if(boss_move_triger==1)
	{
		glColor3f(0.0,1.0,0.0);
		zeelRectDisplay(300+boss_move,500,550,350+boss_move);
		
		boss_x = 300+boss_move;
		
		boss_y = 500;
		
		boss_move -= boss_speed;
		
		if(boss_move < -250)
		{
			boss_move_triger=0;
		}
	}
	
	if(boss_fire_triger == 1)
	{
			glColor3f(1.0,1.0,0.0);
			zeelRectDisplay(boss_x+20,fire_y,fire_y-20,boss_x+30);
			fire_y -= boss_fire_speed;
			fire_x = boss_x+30;
			
			if(fire_y < 0)
			{
				fire_y = 500;
				boss_fire_triger = 0;
			}
			
			if(fire_x>400+player_x-20 && fire_x<400+player_x+20 && fire_y < 100 && fire_y >50)
			{
				game_panel = 5;
				destroy(400+player_x,70);
			}
			
			if(gun_x > 300+boss_move && gun_x < 350+boss_move && gun_y>500 && gun_y<550)
			{
				boss_death_counter++;
				boss_health-=1;
			}
	}
	

		boss_fire_triger = 1;
		
		if(boss_death_counter == 5)
		{
			game_panel = 6;
			destroy(310+boss_move,510);
			destroy(340+boss_move,510);
			destroy(310+boss_move,540);
			destroy(340+boss_move,540);
		}
		
		char point = boss_health+'0';
	
		glColor3f(1.0,1.0,1.0);
		zeelFontDisplay(50,750,"BOSS HEALTH (0 TO 5 ) : ");
		glColor3f(1.0,1.0,1.0);
		zeelFontDisplay(275,750,&point);
		
		glColor3f(1.0,1.0,1.0);
		zeelFontDisplay(550,750,"FOR PAUSE PESS : ESC");

	
}

void bosslevel()
{
	astron();
	player();
	boss();
}

void intro()
{
	
	glColor3f(1.0,0.0,0.0);
	
	zeelFontDisplay(-200+intro_speed_val,750,": WECOME TO BOSS LEVEL :");
	zeelFontDisplay(-180+intro_speed_val,700,": WECOME TO BOSS LEVEL :");
	zeelFontDisplay(-150+intro_speed_val,650,": WECOME TO BOSS LEVEL :");
	zeelFontDisplay(-130+intro_speed_val,600,": WECOME TO BOSS LEVEL :");
	zeelFontDisplay(-100+intro_speed_val,550,": WECOME TO BOSS LEVEL :");
	zeelFontDisplay(-80+intro_speed_val,500,": WECOME TO BOSS LEVEL :");
	zeelFontDisplay(-50+intro_speed_val,400,": WECOME TO BOSS LEVEL :");
	zeelFontDisplay(-80+intro_speed_val,300,": WECOME TO BOSS LEVEL :");
	zeelFontDisplay(-100+intro_speed_val,250,": WECOME TO BOSS LEVEL :");
	zeelFontDisplay(-130+intro_speed_val,200,": WECOME TO BOSS LEVEL :");
	zeelFontDisplay(-150+intro_speed_val,150,": WECOME TO BOSS LEVEL :");
	zeelFontDisplay(-180+intro_speed_val,100,": WECOME TO BOSS LEVEL :");
	zeelFontDisplay(-200+intro_speed_val,50,": WECOME TO BOSS LEVEL :");
	
	intro_speed_val += intro_speed;
	
	if(intro_speed_val > 1000)
	{
		game_panel = 4;
	}
	
}

void enemy()
{
	if(enemy_move_flag1 == 0)
	{
	glColor3f(1.0,0.0,0.0);
	
	if(enemyno[0]==0)
	{
		zeelTriangleDisplay(100+enemy_move1,600,80+enemy_move1,650,120+enemy_move1,650);
		if(gun_x > 100+enemy_move1-enemy_death_range && gun_x < 100+enemy_move1+enemy_death_range && gun_y >= 600 && gun_y<=650 )
		{
			score++;
			is_gun_fired = 0;
			gun_range = 0;
			gun_y = 100+gun_range;
			enemyno[0] = 1;
			destroy(100+enemy_move1,600+20);			
		}
	}
	
	if(enemyno[1]==0)
	{
		zeelTriangleDisplay(200+enemy_move1,600,180+enemy_move1,650,220+enemy_move1,650);
		if(gun_x > 200+enemy_move1-enemy_death_range && gun_x < 200+enemy_move1+enemy_death_range && gun_y >= 600 && gun_y<=650 )
		{
			
			score++;
			is_gun_fired = 0;
			gun_range = 0;
			gun_y = 100+gun_range;
			enemyno[1] = 1;
			destroy(200+enemy_move1,600+20);
		}
	}
	
	if(enemyno[2]==0)
	{
		zeelTriangleDisplay(300+enemy_move1,600,280+enemy_move1,650,320+enemy_move1,650);
		if(gun_x > 300+enemy_move1-enemy_death_range && gun_x < 300+enemy_move1+enemy_death_range && gun_y >= 600 && gun_y<=650 )
		{
			
			score++;
			is_gun_fired = 0;
			gun_range = 0;
			gun_y = 100+gun_range;
			enemyno[2] = 1;
			destroy(300+enemy_move1,600+20);
		}
	}
	
	if(enemyno[3]==0)
	{
		zeelTriangleDisplay(400+enemy_move1,600,380+enemy_move1,650,420+enemy_move1,650);
		if(gun_x > 400+enemy_move1-enemy_death_range && gun_x < 400+enemy_move1+enemy_death_range && gun_y >= 600 && gun_y<=650 )
		{
			
			score++;
			is_gun_fired = 0;
			gun_range = 0;
			gun_y = 100+gun_range;
			enemyno[3] = 1;
			destroy(400+enemy_move1,600+20);
		}
	}
	
	if(enemyno[4]==0)
	{
		zeelTriangleDisplay(500+enemy_move1,600,480+enemy_move1,650,520+enemy_move1,650);
		if(gun_x > 500+enemy_move1-enemy_death_range && gun_x < 500+enemy_move1+enemy_death_range && gun_y >= 600 && gun_y<=650 )
		{
			
			score++;
			is_gun_fired = 0;
			gun_range = 0;
			gun_y = 100+gun_range;
			enemyno[4] = 1;
			destroy(500+enemy_move1,600+20);
		}
	}
	
	enemy_move1 += enemy1_speed;
	
	if(enemy_move1 > 270)
	{
		enemy_move_flag1 = 1;
	}
	
	}
	else if(enemy_move_flag1 == 1)
	{
	glColor3f(1.0,0.0,0.0);
	
	if(enemyno[0]==0)
	{
		zeelTriangleDisplay(100+enemy_move1,600,80+enemy_move1,650,120+enemy_move1,650);
		if(gun_x > 100+enemy_move1-enemy_death_range && gun_x < 100+enemy_move1+enemy_death_range && gun_y >= 600 && gun_y<=650 )
		{
			
			score++;
			is_gun_fired = 0;
			gun_range = 0;
			gun_y = 100+gun_range;
			enemyno[0] = 1;
			destroy(100+enemy_move1,600+20);
		}
	}
	
	if(enemyno[1]==0)
	{
		zeelTriangleDisplay(200+enemy_move1,600,180+enemy_move1,650,220+enemy_move1,650);
		if(gun_x > 200+enemy_move1-enemy_death_range && gun_x < 200+enemy_move1+enemy_death_range && gun_y >= 600 && gun_y<=650 )
		{
			
			score++;
			is_gun_fired = 0;
			gun_range = 0;
			gun_y = 100+gun_range;
			enemyno[1] = 1;
			destroy(200+enemy_move1,600+20);
		}
	}
	
	if(enemyno[2]==0)
	{
		zeelTriangleDisplay(300+enemy_move1,600,280+enemy_move1,650,320+enemy_move1,650);
		if(gun_x > 300+enemy_move1-enemy_death_range && gun_x < 300+enemy_move1+enemy_death_range && gun_y >= 600 && gun_y<=650 )
		{
			
			score++;
			is_gun_fired = 0;
			gun_range = 0;
			gun_y = 100+gun_range;
			enemyno[2] = 1;
			destroy(300+enemy_move1,600+20);
		}
	}
	
	if(enemyno[3]==0)
	{
		zeelTriangleDisplay(400+enemy_move1,600,380+enemy_move1,650,420+enemy_move1,650);
		if(gun_x > 400+enemy_move1-enemy_death_range && gun_x < 400+enemy_move1+enemy_death_range && gun_y >= 600 && gun_y<=650 )
		{
			
			score++;
			is_gun_fired = 0;
			gun_range = 0;
			gun_y = 100+gun_range;
			enemyno[3] = 1;
			destroy(400+enemy_move1,600+20);
		}
	}
	
	if(enemyno[4]==0)
	{
		zeelTriangleDisplay(500+enemy_move1,600,480+enemy_move1,650,520+enemy_move1,650);
		if(gun_x > 500+enemy_move1-enemy_death_range && gun_x < 500+enemy_move1+enemy_death_range && gun_y >= 600 && gun_y<=650 )
		{
			
			score++;
			is_gun_fired = 0;
			gun_range = 0;
			gun_y = 100+gun_range;
			enemyno[4] = 1;
			destroy(500+enemy_move1,600+20);
		}
	}
	
	enemy_move1 -= enemy1_speed;
	
	if(enemy_move1 < -70)
	{
		enemy_move_flag1 = 0;
	}
	
	}
	
	
	if(enemy_move_flag2 == 1)
	{
	glColor3f(1.0,0.0,0.0);
	
	if(enemyno[5]==0)
	{
		zeelTriangleDisplay(100+enemy_move2,500,80+enemy_move2,550,120+enemy_move2,550);
		if(gun_x > 100+enemy_move2-enemy_death_range && gun_x < 100+enemy_move2+enemy_death_range && gun_y >= 500 && gun_y<=550 )
		{
			
			score++;
			is_gun_fired = 0;
			gun_range = 0;
			enemyno[5] = 1;
			destroy(100+enemy_move2,500+20);
		}
	}
	
	if(enemyno[6]==0)
	{
		zeelTriangleDisplay(200+enemy_move2,500,180+enemy_move2,550,220+enemy_move2,550);
		if(gun_x > 200+enemy_move2-enemy_death_range && gun_x < 200+enemy_move2+enemy_death_range && gun_y >= 500 && gun_y<=550  )
		{
			
			score++;
			is_gun_fired = 0;
			gun_range = 0;
			enemyno[6] = 1;
			destroy(200+enemy_move2,500+20);
		}
	}
	
	if(enemyno[7]==0)
	{
		zeelTriangleDisplay(300+enemy_move2,500,280+enemy_move2,550,320+enemy_move2,550);
		if(gun_x > 300+enemy_move2-enemy_death_range && gun_x < 300+enemy_move2+enemy_death_range && gun_y >= 500 && gun_y<=550  )
		{
			destroy(300+enemy_move2,500+20);
			score++;
			is_gun_fired = 0;
			gun_range = 0;
			enemyno[7] = 1;
			destroy(300+enemy_move2,500+20);
		}
	}
	
	if(enemyno[8]==0)
	{
		zeelTriangleDisplay(400+enemy_move2,500,380+enemy_move2,550,420+enemy_move2,550);
		if(gun_x > 400+enemy_move2-enemy_death_range && gun_x < 400+enemy_move2+enemy_death_range && gun_y >= 500 && gun_y<=550  )
		{
			
			score++;
			is_gun_fired = 0;
			gun_range = 0;
			enemyno[8] = 1;
			destroy(400+enemy_move2,500+20);
		}
	}
	
	if(enemyno[9]==0)
	{
		zeelTriangleDisplay(500+enemy_move2,500,480+enemy_move2,550,520+enemy_move2,550);
		if(gun_x > 500+enemy_move2-enemy_death_range && gun_x < 500+enemy_move2+enemy_death_range && gun_y >= 500 && gun_y<=550  )
		{
			
			score++;
			is_gun_fired = 0;
			gun_range = 0;
			enemyno[9] = 1;
			destroy(500+enemy_move2,500+20);
		}
	}
	
	enemy_move2 += enemy2_speed;
	
	if(enemy_move2 > 270)
	{
		enemy_move_flag2 = 0;
	}
	
	}
	else if(enemy_move_flag2 == 0)
	{
	glColor3f(1.0,0.0,0.0);
	
	if(enemyno[5]==0)
	{
		zeelTriangleDisplay(100+enemy_move2,500,80+enemy_move2,550,120+enemy_move2,550);
		if(gun_x > 100+enemy_move2-enemy_death_range && gun_x < 100+enemy_move2+enemy_death_range && gun_y >= 500 && gun_y<=550  )
		{
			
			score++;
			is_gun_fired = 0;
			gun_range = 0;
			enemyno[5] = 1;
			destroy(100+enemy_move2,500+20);
		}
	}
	
	if(enemyno[6]==0)
	{
		zeelTriangleDisplay(200+enemy_move2,500,180+enemy_move2,550,220+enemy_move2,550);
		if(gun_x > 200+enemy_move2-enemy_death_range && gun_x < 200+enemy_move2+enemy_death_range && gun_y >= 500 && gun_y<=550  )
		{
			
			score++;
			is_gun_fired = 0;
			gun_range = 0;
			enemyno[6] = 1;
			destroy(200+enemy_move2,500+20);
		}
	}
	
	if(enemyno[7]==0)
	{
		zeelTriangleDisplay(300+enemy_move2,500,280+enemy_move2,550,320+enemy_move2,550);
		if(gun_x > 300+enemy_move2-enemy_death_range && gun_x < 300+enemy_move2+enemy_death_range && gun_y >= 500 && gun_y<=550  )
		{
			
			score++;
			is_gun_fired = 0;
			gun_range = 0;
			enemyno[7] = 1;
			destroy(300+enemy_move2,500+20);
		}
	}
	
	if(enemyno[8]==0)
	{
		zeelTriangleDisplay(400+enemy_move2,500,380+enemy_move2,550,420+enemy_move2,550);
		if(gun_x > 400+enemy_move2-enemy_death_range && gun_x < 400+enemy_move2+enemy_death_range && gun_y >= 500 && gun_y<=550  )
		{
			
			score++;
			is_gun_fired = 0;
			gun_range = 0;
			enemyno[8] = 1;
			destroy(400+enemy_move2,500+20);
		}
	}
	
	if(enemyno[9]==0)
	{
		zeelTriangleDisplay(500+enemy_move2,500,480+enemy_move2,550,520+enemy_move2,550);
		if(gun_x > 500+enemy_move2-enemy_death_range && gun_x < 500+enemy_move2+enemy_death_range && gun_y >= 500 && gun_y<=550  )
		{
			score++;
			is_gun_fired = 0;
			gun_range = 0;
			enemyno[9] = 1;
			destroy(500+enemy_move2,500+20);
		}
	}
	
	enemy_move2 -= enemy2_speed;
	
	if(enemy_move2 < -70)
	{
		enemy_move_flag2 = 1;
	}
	
	}
	
	if(score>=10)
	{
		game_panel = 3;
	}
	
}

void player()
{
	glColor3f(0.0,1.0,1.0);
	zeelTriangleDisplay(380+player_x,50,400+player_x,100,420+player_x,50);
	
	if(is_gun_fired == 1) // gun fire
	{
		
		glColor3f(1.0,0.0,0.0);
		zeelFixedBoltLineDisplay(gun_x,100+gun_range,gun_x,100+gun_range+20,10);
		gun_range += 15;
		
		gun_y = 100+gun_range;
		
		if(gun_y >800)
		{
			is_gun_fired = 0;
			gun_range = 0;
		}
		
	} 
	
}

void destroy(float x,float y)
{
	int blast;
	
	glColor3f(1.0,0.0,0.0);
	
	for(blast=0;blast<10 ;blast++)
	{
		zeelCircleDisplay(x,y,blast);
		zeelCircleDisplay(x,y,blast+4);
		zeelCircleDisplay(x,y,blast+8);
		zeelCircleDisplay(x,y,blast+12);
		zeelCircleDisplay(x+20,y,blast);
		zeelCircleDisplay(x+20,y,blast+4);
		zeelCircleDisplay(x+20,y,blast+8);
		zeelCircleDisplay(x+20,y,blast+12);
		zeelCircleDisplay(x+20,y+20,blast);
		zeelCircleDisplay(x+20,y+20,blast+4);
		zeelCircleDisplay(x+20,y+20,blast+8);
		zeelCircleDisplay(x+20,y+20,blast+12);
		zeelCircleDisplay(x-20,y+20,blast);
		zeelCircleDisplay(x-20,y+20,blast+4);
		zeelCircleDisplay(x-20,y+20,blast+8);
		zeelCircleDisplay(x-20,y+20,blast+12);
		zeelCircleDisplay(x-20,y-20,blast);
		zeelCircleDisplay(x-20,y-20,blast+4);
		zeelCircleDisplay(x-20,y-20,blast+8);
		zeelCircleDisplay(x-20,y-20,blast+12);
	}
	
}

void game()
{
	astron();
	
	char point = score+'0';
	
	glColor3f(1.0,1.0,1.0);
	zeelFontDisplay(50,750,"YOUR SCORE : ");
	glColor3f(1.0,1.0,1.0);
	zeelFontDisplay(190,750,&point);
	
	glColor3f(1.0,1.0,1.0);
	zeelFontDisplay(550,750,"FOR PAUSE PESS : ESC");
	
	player();
	
	enemy();
	
	
	glEnd();
	glFlush();
}

void exitmenu() // exit menu
{
	astron();
	
	zeelFixedBoltLineDisplay(250,300,250,600,10);
	zeelFixedBoltLineDisplay(600,300,600,600,10);
	zeelFixedBoltLineDisplay(250,600,600,600,10);
	zeelFixedBoltLineDisplay(250,300,600,300,10);
	
	glColor3f(1.0,1.0,1.0);
	zeelFontDisplay(370,550,"EXIT MENU");
	
	glColor3f(1.0,1.0,1.0);
	zeelFontDisplay(320,400,"YES");
	
	glColor3f(1.0,1.0,1.0);
	zeelFontDisplay(500,400,"NO");
	
	if(select_exit % 2 == 0 )
	{
		glColor3f(0.0,1.0,1.0);
		zeelRectDisplay(300,380,430,380);	
	}
	else
	{	
		glColor3f(1.0,0.0,1.0);
		zeelRectDisplay(480,380,430,550);
	}
	
	glColor3f(1.0,1.0,1.0);
	zeelFontDisplay(50,50,"FOR right = D");
	
	glColor3f(1.0,1.0,1.0);
	zeelFontDisplay(300,50,"FOR LEFT = A");
	
	glColor3f(1.0,1.0,1.0);
	zeelFontDisplay(550,50,"FOR SELECT = ENTER");
	
	glEnd();
	glFlush();
}

void menu() // main menu
{
	astron();
	
	glColor3f(1.0,1.0,1.0);
	zeelFontDisplay(330,600,"ZEEL'S COSMOS ");	
	
	glColor3f(1.0,0.0,1.0);
	zeelFontDisplay(380,400,"PLAY");
	
	glColor3f(0.0,1.0,1.0);
	zeelFontDisplay(380,300,"EXIT");
	
	//select area - rectangle
	
	if(select_menu % 2 == 0 )
	{
		glColor3f(0.0,1.0,1.0);
		zeelRectDisplay(300,280,330,500);	
	}
	else
	{	
		glColor3f(1.0,0.0,1.0);
		zeelRectDisplay(300,380,430,500);
	}
	
	glColor3f(1.0,1.0,1.0);
	zeelFontDisplay(50,50,"FOR UP = W");
	
	glColor3f(1.0,1.0,1.0);
	zeelFontDisplay(300,50,"FOR DOWN = S");
	
	glColor3f(1.0,1.0,1.0);
	zeelFontDisplay(550,50,"FOR SELECT = ENTER");
	
		
	glEnd();
	glFlush();
}

void astron()
{
	int astron;
	
	
	for(astron=0; astron<10; astron++)
	{	
		float x = rand()%800;
		float y = rand()%800;
		glColor3f(1.0,1.0,0.0);
		zeelCircleDisplay(x,y-10,2);	
	}
}

void draw()
{
	glColor3f(1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void timer(int value)
{
	
	glutPostRedisplay();
	
	if(game_panel==0)
	{
		menu();
	}
	
	if(game_panel==1)
	{
		exitmenu();
	}
	
	if(game_panel==2)
	{
		game();
	}
	
	if(game_panel==3)
	{
		intro();
	}
	
	if(game_panel==4)
	{
		bosslevel();
	}
	
	if(game_panel==5)
	{
		gameover();
	}
	
	if(game_panel==6)
	{
		gamewin();
	}
	
	glutTimerFunc(50,timer,0);
}

int main(int argc, char **argv) 
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(800, 800);
glutInitWindowPosition(0, 0);
glutCreateWindow("Zeel's Space Fighter");
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.0, 0.0, 0.0, 1.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0, 800, 0, 800);
glutDisplayFunc(draw);
glutTimerFunc(50,timer,0);

// here are the new entries
glutKeyboardFunc(processKeyformenu);

glutMainLoop();
}
