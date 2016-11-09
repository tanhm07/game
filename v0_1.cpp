#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include <windows.h>
#include <conio.h>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto

void gotoXY(int,int); //function defined below

int main () {

char confirmKey = 'N';

string str; 

bool running = true;

struct attributes {
	string name;
	int level;
} player;

player.level = 1;

cout << "Welcome to Custability Fighter v0.1\n";
while(confirmKey != 'Y') {
Sleep(1000);
cout << "What would you like to name your character?\n";
cout << "Name: ";
getline(cin,player.name);
cout << "Your character will be named " << player.name << ".\n";
cout << "Is this correct? (Y/N): ";
getline(cin, str);
confirmKey = str[0];
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