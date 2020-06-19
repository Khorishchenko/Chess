#include "Chess.h"

int  info(int max_y, int max_x) 
{
	initscr();
	start_color();
	cbreak();
	noecho();
	curs_set(0);

	init_pair(1, COLOR_RED, COLOR_BLACK);

	char str[23][1440] = {"***  CHESS  ***",
	"How to play:",
	"Type in your move as a single four character string. Use x-coordinates first in each pair.",
	"example: 0102",

	"PAUSE <<Q>>",
	"\n",
	"\n",
    "-> Press <<R>> to return to main menu"};
     
	attron(COLOR_PAIR(1));
	attron(A_BOLD | A_BOLD);
	for (int j = 0; j < 23; j++) 
	{
		mvprintw(max_y /2 + j - 12, max_x /2  - 39, str[j]);
		ddelay(100);
		refresh();
	} 
	attroff(COLOR_PAIR(1));
	attroff(A_BOLD | A_BOLD);
    
    
	int count = getch();
	//if (count == 114)
		return 114;


	endwin();
	refresh();
	return count;
}

