#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include <windows.h>

using namespace std;

int main () {

char confirmKey = 'N';

string str; 

struct attributes {
	string name;
	int level;
} player;

player.level = 1;

cout << "Welcome to RPG v0.1\n";
while(confirmKey != 'Y') {
Sleep(2);
cout << "What would you like to name your character?\n";
cout << "Name: ";
getline(cin,player.name);
cout << "Your character will be named " << player.name << ".\n";
cout << "Is this correct? (Y/N): ";
getline(cin, str);
confirmKey = str[0];
}
cout << "Hi " << player.name << ".\n";
cout << "You are currently level: " << player.level <<".\n";
cout << "Welcome to the world.\nExciting adventures await you once I update this program more.\n";

system("pause");
return 0;
}