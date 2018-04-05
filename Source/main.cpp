#include <ncurses.h>
#include <string>
#include <cstdint>

#include <libavcodec/avcodec.h>

int main(int argc, char** argv)
{
	avcodec_register_all();
	char ch;
	initscr();
	cbreak();
	keypad(stdscr, true);
	noecho();
	refresh();
	printw("Press a to quit!\n");
	ch = getch();
	int i=0;
	while(ch != 'a')
	{
		mvprintw(1, 0, "Failed attempts at pressing a: ");
		printw(std::to_string(++i).c_str());
		if(i >= 5 && i < 10)
		{
			attron(A_BOLD);
			printw(" Amazing!");
			attroff(A_BOLD);
		}else if(i >= 10 && i < 20)
		{
			attron(A_BOLD);
			printw(" WOMBO COMBO!!!");
			attroff(A_BOLD);
		} if(i >= 20)
		{
			printw(" Sorry, nothing");
		}
		refresh();
		ch = getch();
	}
	endwin();
	return 0;
}

