#include<stdio.h>
#include<windows.h>
#include<conio.h>
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void drawship()
{
	printf(" <-0-> ");
}
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void shot()
{
	printf(" *   * ");
}
void shoot(int x, int y)
{
	gotoxy(x, y);
	shot();
}
void draw_ship(int x, int y)
{
	gotoxy(x, y);
	drawship();
}
void eraseship()
{
	printf("       ");
}
void erase_ship(int x, int y)
{
	gotoxy(x, y);
	eraseship();
}
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void bullet(int x, int y) {
	gotoxy(x, y);
	setcolor(7, 0);
	printf("|");
}
void erase_bullet(int x, int y) {
	gotoxy(x, y);
	setcolor(7, 0);
	printf(" ");
}
int main() {
	setcolor(2, 4);
	setcursor(0);
	char ch = ' ';
	char c = ' ';
	int x = 38, y = 20;
	int r = y - 1;
	draw_ship(x, y);
	erase_ship(x, y);
	setcolor(2, 4);
	draw_ship(x, y);
	int bulletstatus = 0;
	int bulletstatus1 = 0;
	int bulletstatus2 = 0;
	int bulletstatus3 = 0;
	int bulletstatus4 = 0;
	int a1, a2, a3, a4, a5, b1, b2, b3, b4, b5;
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == ' ' && bulletstatus == 0) {
				bulletstatus = 1;
				a1 = x + 2;
				b1 = y;
				bullet(a1, --b1);
			}
			else if (ch == ' ' && bulletstatus1 == 0) {
				bulletstatus1 = 1;
				a2 = x + 2;
				b2 = y;
				bullet(a2, --b2);
			}
			else if (ch == ' ' && bulletstatus2 == 0) {
				bulletstatus2 = 1;
				a3 = x + 2;
				b3 = y;
				bullet(a3, --b3);
			}
			else if (ch == ' ' && bulletstatus3 == 0) {
				bulletstatus3 = 1;
				a4 = x + 2;
				b4 = y;
				bullet(a4, --b4);
			}
			else if (ch == ' ' && bulletstatus4 == 0) {
				bulletstatus4 = 1;
				a5 = x + 2;
				b5 = y;
				bullet(a5, --b5);
			}
			if (ch == ' ') {
				ch = c;
			}
		}
		if (ch == 'a' && x > 0) {
			c = 'a';
			setcolor(7, 0);
			erase_ship(x, y);
			setcolor(2, 4);
			draw_ship(--x, y);
		}
		if (ch == 'd' && x < 75)
		{
			c = 'd';
			setcolor(7, 0);
			erase_ship(x, y);
			setcolor(2, 4);
			draw_ship(++x, y);
		}
		if (ch == 's') {
			erase_ship(x, y);
			draw_ship(x, y);
		}
		if (bulletstatus == 1) {
			erase_bullet(a1, b1);
			if (b1 == 0) bulletstatus = 0;
			if (b1 >= 1) {
				bullet(a1, --b1);
			}
			if (bulletstatus1 == 1) {
				erase_bullet(a2, b2);
				if (b2 == 0) bulletstatus1 = 0;
				if (b2 >= 1) {
					bullet(a2, --b2);
				}
			}
			if (bulletstatus2 == 1) {
				erase_bullet(a3, b3);
				if (b3 == 0) bulletstatus2 = 0;
				if (b3 >= 1) {
					bullet(a3, --b3);
				}
			}
			if (bulletstatus3 == 1) {
				erase_bullet(a4, b4);
				if (b4 == 0) bulletstatus3 = 0;
				if (b4 >= 1) {
					bullet(a4, --b4);
				}
			}
			if (bulletstatus4 == 1) {
				erase_bullet(a5, b5);
				if (b5 == 0) bulletstatus4 = 0;
				if (b5 >= 1) {
					bullet(a5, --b5);
				}
			}
		}
		fflush(stdin);
		Sleep(100);
	} while (ch != 'x');
	return 0;
}