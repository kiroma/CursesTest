#include <ncurses.h>
#include <string>
#include <cstdint>
extern "C"{
#include <libavcodec/avcodec.h>
#include <libavdevice/avdevice.h>
}

void colours(){
	init_pair(1, 0, 1);
	init_pair(2, 0, 2);
	init_pair(3, 0 ,3);
	init_pair(4, 0, 4);
	init_pair(5, 0, 5);
	init_pair(6, 0, 6);
	init_pair(7, 0, 7);
}

int main(int argc, char** argv)
{
	char ch;
	initscr();
	if(!has_colors())
	{
		printw("Your terminal does not support colour!\n Press any key to exit.");
		endwin();
		return 1;
	}
	start_color();
	colours();
	cbreak();
	keypad(stdscr, true);
	noecho();
	short colour=0;
	int x = getmaxx(stdscr);
	int y = getmaxy(stdscr);
	while(ch != 'a')
	{
		if(colour > 7){
			colour=0;
		}
		attron(COLOR_PAIR(colour));
		for(int i=0; i<y; i++)
		{
			for(int j=0; j<x; j++)
			{
				mvaddch(i, j, 'x');
			}
		}
		refresh();
		attroff(COLOR_PAIR(colour));
		colour++;
		ch = getch();
	}
	endwin();
	return 0;
}

