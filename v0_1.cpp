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
	int level=1,STR=1,AGI=1,INT=1,VIT=1,LUK=1;
	int HP=10*VIT, SP=20, EXP=0, MAX_EXP=20;
	bool LVL_UP=false;
} player;

struct monsterInfo {
	string name;
	int level,STR,AGI,INT,VIT,LUK,HP;
} monster;

void printPlayerInfo(playerInfo pInfo);
void printMonsterInfo(monsterInfo mInfo);
void setMonsterInfo(monsterInfo& mInfo, string mName, int LVL);
void Fight_PlayerMonster(playerInfo& pInfo, monsterInfo& mInfo);

void ClearScreen();
void hClrScr();

int main () {

	srand (time(NULL));
	
	int menu_key=1, aKey=0, y = 12;

	string str; 

	bool running = true;

	gotoXY(0,7); cout << "Welcome to Custability Fighter v0.1";
	Sleep(1000);
	while(menu_key) {
	gotoXY(0,8); cout << "What would you like to name your Fighter?\n";
		cout << "Name: ";
		getline(cin,player.name);
		cout << "Your Fighter will be named " << player.name << ".\n";
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
	cout << "->Assign Fighter SP\n";
	gotoXY(2,10); cout << "FIND Monster";
	gotoXY(2,11); cout << "FIGHT Monster!";
	gotoXY(2,12); cout <<  "EXIT";
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
		if (aKey==KEY_DOWN && y!=12) {
			gotoXY(0,y); cout << "  ";
			y++;
			gotoXY(0,y); cout << "->";
			menu_key++;
			continue;
		}
		if (aKey=='\r') {
			switch(menu_key) { 
				case 1: {
					hClrScr();
					printPlayerInfo(player);
					cout << "  DONE";
					gotoXY(0,16); cout << "->";
					int SP_menukey=1, SP_y=16;
					bool SP_running =true;
					while (SP_running){
						aKey=getch();
						if (aKey==0 || aKey ==224)
							aKey=getch();
						if (aKey==KEY_UP && SP_y!=16) {
							gotoXY(0,SP_y); cout << "  ";
							SP_y--;
							gotoXY(0,SP_y); cout << "->";
							SP_menukey--;
							continue;
						}
						if (aKey==KEY_DOWN && SP_y!=21) {
							gotoXY(0,SP_y); cout << "  ";
							SP_y++;
							gotoXY(0,SP_y); cout << "->";
							SP_menukey++;
							continue;
						}
						if (aKey=='\r') {
							switch(SP_menukey) {
								case 1: {
									if (player.SP >0){
										player.STR++;
										player.SP--;
										printPlayerInfo(player);
									}
									break;
								}
								case 2: {
									if (player.SP >0){
										player.AGI++;
										player.SP--;
										printPlayerInfo(player);
									}
									break;
								}
								case 3: {
									if (player.SP >0){
										player.INT++;
										player.SP--;
										printPlayerInfo(player);
									}
									break;
								}
								case 4: {
									if (player.SP >0){
										player.VIT++;
										player.SP--;
										player.HP = 10*player.VIT;
										printPlayerInfo(player);
									}
									break;
								}
								case 5: {
									if (player.SP >0){
										player.LUK++;
										player.SP--;
										printPlayerInfo(player);
									}
									break;
								}
								case 6: {
									hClrScr();
									SP_running=false;
								}
							}
						}
					}
					break;
				}
				case 2: {
					hClrScr();
					player.HP=10*player.VIT;
					player.LVL_UP=false;
					setMonsterInfo(monster,"slime",player.level);
					gotoXY(0,13); printMonsterInfo(monster);
					break;
				}
				case 3: {
					hClrScr();
					gotoXY(0,13); Fight_PlayerMonster(player,monster);
					break;
				}
				case 4: {
					running = false;
					hClrScr();
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
	gotoXY(0,13); cout << "Name: " << pInfo.name << "\n";
	cout << "Level: " << pInfo.level << " EXP: " << pInfo.EXP << "/" << pInfo.MAX_EXP <<"\n";
	cout << "HP: " << pInfo.HP << " SP: " << pInfo.SP << "     \n";
	gotoXY(2,16); cout << "STR: " << pInfo.STR << "\n";
	gotoXY(2,17); cout << "AGI: " << pInfo.AGI << "\n";
	gotoXY(2,18); cout << "INT: " << pInfo.INT << "\n";
	gotoXY(2,19); cout << "VIT: " << pInfo.VIT << "\n";
	gotoXY(2,20); cout << "LUK: " << pInfo.LUK << "\n"; 
	
}

void printMonsterInfo(monsterInfo mInfo) {
	cout << "Name: " << mInfo.name << "\n";
	cout << "Level: " << mInfo.level << "\n";
	cout << "HP: " << mInfo.HP << "\n";
	cout << "STR: " << mInfo.STR << "\n";
	cout << "AGI: " << mInfo.AGI << "\n";
	cout << "INT: " << mInfo.INT << "\n";
	cout << "VIT: " << mInfo.VIT << "\n";
	cout << "LUK: " << mInfo.LUK << "\n"; 
}

void setMonsterInfo(monsterInfo& mInfo, string mName, int LVL){
	mInfo.name = mName;
	mInfo.level = rand()%LVL+1;
	mInfo.STR = mInfo.level*(rand()%5+1);
	mInfo.AGI = mInfo.level*(rand()%5+1);
	mInfo.INT = mInfo.level*(rand()%5+1);
	mInfo.VIT = mInfo.level*(rand()%5+1);
	mInfo.LUK = mInfo.level*(rand()%5+1);
	mInfo.HP = 10*mInfo.VIT;
}

void Fight_PlayerMonster(playerInfo& pInfo, monsterInfo& mInfo) {
	int player_DMG=0, monster_DMG=0, EXP_EARN = (mInfo.STR + mInfo.INT + mInfo.AGI + mInfo.VIT + mInfo.LUK)/5;
	
	player_DMG=(rand()%pInfo.STR+rand()%pInfo.INT+2)/(rand()%(mInfo.STR+mInfo.INT)+1)*pInfo.AGI/mInfo.AGI;
	monster_DMG=(rand()%mInfo.STR+rand()%mInfo.INT+2)/(rand()%(pInfo.STR+pInfo.INT)+1)*mInfo.AGI/pInfo.AGI;
	
	if (pInfo.HP <=0 ) {
		cout << pInfo.name << " has lost!\n";
	}
	else if (mInfo.HP <= 0) { 
		cout << mInfo.name << " has been defeated!\n";
		cout << pInfo.name << " earned " << EXP_EARN << " EXP.\n"; 
		if (pInfo.LVL_UP == true) {
			cout << pInfo.name << " LEVEL UP!";
		}
	}
	else {
		pInfo.HP=pInfo.HP-monster_DMG;
		mInfo.HP=mInfo.HP-player_DMG;
		
		cout << pInfo.name << " did " << player_DMG << " DMG to " << mInfo.name << ".\n";
		cout << mInfo.name << " did " << monster_DMG << " DMG to " << pInfo.name << ".\n";
		cout << pInfo.name << " has " << pInfo.HP << " HP left.\n";
		cout << mInfo.name << " has " << mInfo.HP << " HP left.\n";

		if (pInfo.HP <= 0) {
			pInfo.HP = 0;
			cout << pInfo.name << " has lost!\n";
		}

		if (mInfo.HP <= 0) {
			mInfo.HP =0;
			cout << mInfo.name << " has been defeated!\n";
			pInfo.EXP = pInfo.EXP + EXP_EARN;
			cout << pInfo.name << " earned " << EXP_EARN << " EXP.\n"; 
			if (pInfo.EXP >= pInfo.MAX_EXP) {
				pInfo.EXP = pInfo.EXP - pInfo.MAX_EXP;
				pInfo.level++;
				pInfo.SP = pInfo.SP + 20;
				pInfo.LVL_UP = true;
			}
			if (pInfo.LVL_UP == true) {
				cout << pInfo.name << " LEVEL UP!";
			}
		}
	}
}

void hClrScr() {
	gotoXY(0,13); 
	for (int i=1;i<10;i++) {
	cout << "						\n";
	}
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