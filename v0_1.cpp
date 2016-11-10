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

struct playerInfo {
	string name;
	int level=1,STR=5,AGI=5,INT=5,VIT=5,LUK=5;
} player;

void printPlayerInfo(playerInfo pInfo);

void ClearScreen();


int main () {

	int menu_key=1, aKey=0, y = 12;

	string str; 

	bool running = true;

	gotoXY(0,7); cout << "Welcome to Custability Fighter v0.1";
	Sleep(1000);
	while(menu_key) {
	gotoXY(0,8); cout << "What would you like to name your character?\n";
		cout << "Name: ";
		getline(cin,player.name);
		cout << "Your character will be named " << player.name << ".\n";
		gotoXY(0,11); cout << "Is this correct?";
		gotoXY(0,12); cout << "->Y";
		gotoXY(2,13); cout << "N";
		menu_key=0;
		while(running){
			aKey=getch();
			if (aKey==0 || aKey ==224)
				aKey=getch();
			if(aKey == KEY_UP && y!=12) {
				gotoXY(0,y); cout << "  ";
				y--;
				gotoXY(0,y); cout << "->";
				menu_key=0;
				continue;
			}
			if(aKey == KEY_DOWN && y!=13) {
				gotoXY(0,y); cout << "  ";
				y++;
				gotoXY(0,y); cout << "->";
				menu_key=1;
				continue;
			}
			if(aKey =='\r') {
				ClearScreen();
				break;
			}
		}
	}
	gotoXY(0,7); cout << "Hi " << player.name << ".\n";
	Sleep(1000);
	y=9;
	cout << "What would you like to do?\n";
	cout << "->Character INFO\n";
	gotoXY(2,10); cout <<  "EXIT";
	menu_key=1;
	while(running) {
		aKey=getch();
		if (aKey==0 || aKey ==224)
				aKey=getch();
		if (aKey==KEY_UP && y!=9) {
			gotoXY(0,y); cout << "  ";
			y--;
			gotoXY(0,y); cout << "->";
			menu_key--;
			continue;
		}
		if (aKey==KEY_DOWN && y!=10) {
			gotoXY(0,y); cout << "  ";
			y++;
			gotoXY(0,y); cout << "->";
			menu_key++;
			continue;
		}
		if (aKey=='\r') {
			switch(menu_key) { 
				case 1: {
					gotoXY(0,13); printPlayerInfo(player);
					break;
				}
				case 2: {
					running = false;
					gotoXY(0,13); 
					for (int i=1;i<8;i++) {
						cout << "						\n";
					}
				}
			}
		}
	}
	
	gotoXY(0,13); cout << "Welcome to the world.\nExciting adventures await you once I update this program more.\n";
	system("pause");
	return 0;
}

void gotoXY(int x, int y) {
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console,CursorPosition);
}

void printPlayerInfo(playerInfo pInfo) {
	cout << "Name: " << pInfo.name << "\n";
	cout << "Level: " << pInfo.level << "\n";
	cout << "STR: " << pInfo.STR << "\n";
	cout << "AGI: " << pInfo.AGI << "\n";
	cout << "INT: " << pInfo.INT << "\n";
	cout << "VIT: " << pInfo.VIT << "\n";
	cout << "LUK: " << pInfo.LUK << "\n"; 
}

void ClearScreen()
  {
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
  }