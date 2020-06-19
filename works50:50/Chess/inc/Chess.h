#ifndef CHESS_H
#define CHESS_H

#include <SDL2/SDL.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <pthread.h>
#include <curses.h>
using namespace std;

enum Piece { KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, EMPTY };
enum Color { WHITE, BLACK, NONE };

void game();
int menu_2(int max_y,int max_x);
int menu(int max_y, int max_x);
int info(int max_y, int max_x);
char start(int max_y, int max_x);
void mx_pause();
void pause_2(int nRezul);
void ddelay(int number_of_seconds);
void namegame(int max_y, int max_x);


class Square
{
	
	Piece piece;
	Color color;
	int x, y;
public:
	void setSpace(Square*);
	void setEmpty();
	void setPieceAndColor(Piece, Color);
	Piece getPiece();
	Color getColor();
	void setX(int ex) { x = ex; }
	void setY(int why) { y = why; }
	int getX() { return x; }
	int getY() { return y; }
	Square();
};

class Board
{
	Square square[8][8];
	Color turn=WHITE;
	bool moveKing(Square* thisKing, Square* thatSpace);
	bool moveQueen(Square* thisQueen, Square* thatSpace);
	bool moveBishop(Square* thisBishop, Square* thatSpace);
	bool moveKnight(Square* thisKnight, Square* thatSpace);
	bool moveRook(Square* thisRook, Square* thatSpace);
	bool movePawn(Square* thisPawn, Square* thatSpace);
	bool makeMove(int x1, int y1, int x2, int y2);
	void printBoard();
public:
	Square* getSquare(int x, int y) 
	{
		return &square[x][y];
	}
	void setSquare(Square * s, int x, int y)
	{
		square[x][y]=*s;
	}
	bool doMove();
	
	void setBoard();
	bool playGame();
};

#endif

