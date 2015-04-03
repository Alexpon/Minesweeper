#include<curses.h>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<sstream>
#include"SetMap.h"
#include"Time.h"

using namespace std;

int main()
{
	int i, j, c, x = 1, y = 2;
	int sizeRow, sizeCol, boomNum, width, height;	
        int go_on, choose, FS, expectBoom, lose = 0;
        char select;
        char temparr[100][100];
		
	for(i=0; i<100; i++){
        	for(j=0; j<100; j++)
                	temparr[i][j]=' ';
        }

	cout << "Please select the size:" << endl;
	cout << "1.small  size(9x9)   with 10 boom" << endl;
	cout << "2.medium size(16x16) with 40 boom" << endl;
	cout << "3.max    size(16x30) with 99 boom" << endl;
	cin >> choose;
	
	if(choose==1){sizeRow=9, sizeCol=9, boomNum=10;}
	else if(choose==2){sizeRow=16, sizeCol=16, boomNum=40;}           
	else if(choose==3){sizeRow=16, sizeCol=30, boomNum=99;}
	expectBoom=boomNum;
	First Aclass;
	Aclass.SelectLevel(choose);

	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	getmaxyx(stdscr, height, width);
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_RED);
	init_pair(2, COLOR_BLACK, COLOR_GREEN);

	mvaddstr(0, 0, "Welcome to Minesweeper: ");
	mvaddstr(0, sizeCol+15, "Press Tab to open");
        mvaddstr(1, sizeCol+15, "Press 'f' to put the flag");
	mvaddstr(2, sizeCol+15, "Press 'q' to exit the game");
	mvaddstr(3, sizeCol+15, "Time");
	mvaddstr(3, sizeCol+33, "Boom:");
	mvprintw(3, sizeCol+38, "%2d", expectBoom);

	for(i=2; i<=sizeRow+1;i++){
		mvaddch(i, 0, '|');
		mvaddch(i, sizeCol+1, '|');
	}
	for(j=1; j<=sizeCol;j++){
		mvaddch(1, j, '-');
		mvaddch(sizeRow+2, j, '-');
	}
	mvaddch(1, 0, '*');
	mvaddch(1, sizeCol+1, '*');
	mvaddch(sizeRow+2, 0, '*');
	mvaddch(sizeRow+2, sizeCol+1, '*');


	Time clock;
	clock.InitialTime();

	go_on = TRUE;
	while (go_on) {	
		if(lose==1){
			//print all booms
			for(i=2;i<sizeRow+2;i++){
				for(j=1;j<sizeCol+1;j++){
					select=Aclass.get(i-1,j);
					if(select=='B'){
						attron(COLOR_PAIR(1));
						mvaddch(i, j, select);
						attroff(COLOR_PAIR(1));
					}
				}
			}
			//print "LOSE" photo
			attron(A_REVERSE);
			for(i=4; i<13; i++){
				mvaddstr(i, sizeCol+7, "  ");
				mvaddch(12, sizeCol+i+3, ' ');
				mvaddstr(i, sizeCol+18, "  ");
				mvaddstr(i, sizeCol+27, "  ");
				mvaddch(4, sizeCol+i+16, ' ');
				mvaddch(12, sizeCol+i+16, ' ');
				mvaddch(4, sizeCol+i+29, ' ');
				mvaddch(8, sizeCol+i+29, ' ');
				mvaddch(12, sizeCol+i+29, ' ');	
				mvaddstr(i, sizeCol+44, "  ");
				mvaddch(4, sizeCol+i+42, ' ');
				mvaddch(8, sizeCol+i+42, ' ');
				mvaddch(12, sizeCol+i+42, ' ');
			}
			for(i=4; i<9; i++){
				mvaddstr(i, sizeCol+31, "  ");
				mvaddstr(i+4, sizeCol+40, "  ");
			}
			mvaddstr(12, sizeCol+31, "  ");
			attroff(A_REVERSE);
			
			mvaddstr(14, sizeCol+6, "Press any key to end the game");
			refresh();
			nodelay(stdscr, false);
			go_on = 0;
			
		}//if-lose
		
		//win
		if(FS==boomNum){
			//print "WIN" photo
			attron(A_REVERSE);
			for(i=4; i<13; i++){
                                mvaddstr(i, sizeCol+7, "  ");
                                mvaddstr(i, sizeCol+13, "  ");
                                mvaddstr(i, sizeCol+19, "  ");
                                mvaddstr(i, sizeCol+25, "  ");
                                mvaddstr(i, sizeCol+31, "  ");
                   		mvaddstr(i, sizeCol+i+29, "   ");
				mvaddstr(i, sizeCol+44, "  ");
			}	
			for(i=0;i<11;i++)mvaddch(12, sizeCol+i+8, ' ');
			attroff(A_REVERSE);
			
			mvaddstr(14, sizeCol+6, "Press any key to end the game");
			refresh();
                        nodelay(stdscr, false);
                        go_on = 0;
		}//if-win


                while((c=getch())==ERR){
                        clock.NowTime();
                        int hour = clock.getHour();
                        int min  = clock.getMinute();
                        int sec  = clock.getSecond();
                        mvprintw(3, sizeCol+20 ,"%2d:%2d:%2d", hour, min, sec);
			move(y, x);
                        refresh();
                }//while-time

		
		init_pair(2, COLOR_BLACK, COLOR_GREEN);			
		move(y, x);
		switch (c) {
			case KEY_LEFT: --x; 		if(x<1)		x=x+sizeCol;  break;
			case KEY_RIGHT: ++x; 		if(x>sizeRow)	x=x-sizeCol;  break;
			case KEY_UP: --y;  		if(y<2)		y=y+sizeRow;  break;
			case KEY_DOWN: ++y; 		if(y>sizeCol+1)	y=y-sizeRow;  break;
			case 'f': 			if(temparr[y][x]=='F'){
							mvaddch(y, x, ' ');
							temparr[y][x]=' ';
							expectBoom++;
							mvprintw(3, sizeCol+38, "%2d", expectBoom);break;
							}
							attron(COLOR_PAIR(2));
							mvaddch(y, x, 'F');
							attroff(COLOR_PAIR(2));
							expectBoom--;
							mvprintw(3, sizeCol+38, "%2d", expectBoom);
							temparr[y][x]='F';    break;
			case '\t': 			select = Aclass.get(y-1,x);
							attron(COLOR_PAIR(2));
					   		mvaddch(y, x, select);
							attroff(COLOR_PAIR(2));
							temparr[y][x]=select;
					   		if(select=='B') lose=1;
					   		break;
			case 'q': go_on = FALSE;
		} // switch-press
		
		FS = 0;//initial
		for(i=2; i<sizeCol+2; i++){
                        for(j=1; j<sizeRow+1; j++){
                                if(temparr[i][j]==' '||temparr[i][j]=='F')FS++;
                        }
                }

	} // while-go_on
	endwin();
	return 0;
}

