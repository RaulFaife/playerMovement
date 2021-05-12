#include <iostream>
#include <stdlib.h>
#include <Windows.h>

using namespace std;

//my variables
int plot[9][9] = {{1,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0}};
int posX = 0;
int posY = 0;

void loadPlot(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << plot[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

//Will move the 1 to the down
void moveDown(){
    plot[posY][posX] = 0; //Make current place 0
    plot[posY+1][posX] = 1; //Make the new location into 1
    posY++; //Increase the base variable for location
}

//Will move the 1 to the up
void moveUp(){
    plot[posY][posX] = 0; //Make current place 0
    plot[posY-1][posX] = 1; //Make the new location into 1
    posY--; //Increase the base variable for location
}

//Will move the 1 to the right
void moveRight(){
    plot[posY][posX] = 0; //Make current place 0
    plot[posY][posX+1] = 1; //Make the new location into 1
    posX++; //Increase the base variable for location
}

//Will move the 1 to the left
void moveLeft(){
    plot[posY][posX] = 0; //Make current place 0
    plot[posY][posX-1] = 1; //Make the new location into 1
    posX--; //Increase the base variable for location
}

int main() {
    system("cls");
    loadPlot();

    //Below is to get the keystates continuously until the while is broken by hitting Q
    while(!(GetKeyState('Q') & 0x8000)){
        if((GetKeyState('A') & 0x8000)){
            system("cls");
            moveLeft();
            loadPlot();
            Sleep(100);
        }
        if((GetKeyState('D') & 0x8000)){
            system("cls");
            moveRight();
            loadPlot();
            Sleep(100);
        }
        if((GetKeyState('W') & 0x8000)){
            system("cls");
            moveUp();
            loadPlot();
            Sleep(100);
        }
        if((GetKeyState('S') & 0x8000)){
            system("cls");
            moveDown();
            loadPlot();
            Sleep(100);
        }
    }
    return 0;
}
