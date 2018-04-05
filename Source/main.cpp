#include <ncurses.h>
#include <string>

int main()
{
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
		mvprintw(1, 0, std::to_string(i++).c_str());
		refresh();
		ch = getch();
	}
	endwin();
	return 0;
}
