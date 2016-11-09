#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include <windows.h>
#include <conio.h>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto

void gotoXY(int,int); //function defined below

int main () {

	int menu_YN=1, aKey=0, x = 12;

	string str; 

	bool running = true;

	struct attributes {
		string name;
		int level;
	} player;

	player.level = 1;

	gotoXY(30,7); cout << "Welcome to Custability Fighter v0.1";
	while(menu_YN) {
		Sleep(1000);
		gotoXY(30,8); cout << "What would you like to name your character?";
		gotoXY(30,9); cout << "Name: ";
		getline(cin,player.name);
		gotoXY(30,10); cout << "Your character will be named " << player.name << ".";
		gotoXY(30,11); cout << "Is this correct?";
		gotoXY(30,12); cout << "->Y";
		gotoXY(32,13); cout << "N";
		while(running){
			aKey=getch();
			if (aKey==0 || aKey ==224)
				aKey=getch();
			if(aKey == KEY_UP && x!=12) {
				gotoXY(30,x); cout << "  ";
				x--;
				gotoXY(30,x); cout << "->";
				menu_YN=0;
				continue;
			}
			if(aKey == KEY_DOWN && x!=13) {
				gotoXY(30,x); cout << "  ";
				x++;
				gotoXY(30,x); cout << "->";
				menu_YN=1;
				continue;
			}
			if(aKey =='\r') {
				break;
			}
		}
	}
	cout << "Hi " << player.name << ".\n";
	Sleep(1000);
	cout << "You are currently level: " << player.level <<".\n";
	Sleep(2000);
	cout << "Welcome to the world.\nExciting adventures await you once I update this program more.\n";
	Sleep(2000);
	system("pause");
	return 0;
}

void gotoXY(int x, int y) {
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console,CursorPosition);
}