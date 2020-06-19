#include <iostream>
#include <string>
#include "Chess.h"

void game()
{
	initscr();

	int max_y, max_x;

	getmaxyx(stdscr, max_y, max_x);

	start_color();
	cbreak();
	noecho();
	curs_set(0);
	
	init_pair(1, COLOR_RED, COLOR_BLACK);

	Board b;
	string s;
	bool newgame = true;

	char str[11][500] = {
	"   _____ _    _ ______  _____ _____   ",  
	"  / ____| |  | |  ____|/ ____/ ____|  ", 
	" | |    | |__| | |__  | (___| (___    ",
	" | |    |  __  |  __|  \\___ \\___\\  ",
	" | |____| |  | | |____ ____) |___)|  ",  
	" \\_____|_|  |_|______|_____/_____/   ",
	"                                      "};
	
	attron(COLOR_PAIR(1));
	attron(A_BOLD | A_BOLD);
	for (int j = 0; j < 16; j++) 
	{
		mvprintw(max_y /2 + j - 12, max_x /2  - 39, str[j]);
		ddelay(100);
		refresh();
	} 
	attroff(COLOR_PAIR(1));
	attroff(A_BOLD | A_BOLD);


	while(newgame)
	{
		b.setBoard();
		while (b.playGame());
	}

	getch();
	endwin();
}

