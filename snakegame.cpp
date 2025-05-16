#include <iostream>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include <thread>
using namespace std;


char start;
enum  Direction{STOP=0 , LEFT, RIGHT, UP, DOWN};
Direction dir;
bool gameOver;
const int height = 20;
const int width = 20;
int headX, headY, fruitX, fruitY;
int score = 0;
int tailLength;
int tailX[100], tailY[100];


void setup();
void draw();
void userInput();
void logics();



int main(){
    cout << "--------------------------" << endl;
    cout << "\t Snake.io \t\n";
    cout << "--------------------------" << endl;
    cout << "Press 's' to start the game! ";
    cin >> start;
    if(start == 's' || start == 'S'){
        cout << "\n" << "\tloading...\t" << "\n" << endl;
        // this_thread::sleep_for(chrono::seconds(2));
        Sleep(1500); 
        setup();
        while(!gameOver){
            draw();
            userInput();
            logics();
            system("cls");
            Sleep(30);
        }
    }


    return 0;
}

void setup(){
    gameOver = false;
    dir = STOP;
    headX = width/2;
    headY =  height/2;
    fruitX = rand()%width;
    fruitY = rand()%height;

}


void draw(){
    system("cls");
    
    //upper border
    cout << "\t\t";
    for(int i = 0; i < width -8; i++){
        cout << "||";

    }
    cout << endl;

    //  head and fruit position
    for(int i = 0 ; i < height; i++){
        for(int j =0; j < width; j++){
            // left border 
            if(j==0){
                cout << "\t\t||";
            }
            // head
            if(i == headY && j == headX){
                cout << "O";
            }
            // fruit
            else if(i == fruitY && j == fruitX){
                cout << "*";
            }
            else{
                bool print = false;
                // tail
                for(int k = 0; k < tailLength; k++){
                    if(tailX[k] == j && tailY[k] == i){
                        cout << "o";
                        print = true; 
                    }
                }

                // space
                if(!print){
                    cout << " ";
                }
            }
            // right border 
            if(j == width -1){
                cout << "||";
            }
        }
        cout << endl;
    }



    //lower border
    cout << "\t\t";
    for(int i = 0; i < width -8; i++){
        cout << "||";
    }

    cout << endl;
    cout << "\t\t\tScore: " << score << endl;

}


void userInput(){
    if(_kbhit())
    switch(getch()){

        case 'a':
            dir = LEFT;
            break;

        case 'd':
            dir = RIGHT;
            break;

        case 'w':
            dir = UP;
            break;

        case 's':
            dir = DOWN;
            break;

        default:
            cout << "defualt again!" << endl;
            Sleep(2000);
            break;
    }
}

void logics(){
    int prevx = tailX[0];
    int prevy = tailY[0];
    int prev2x, prev2y;
    tailX[0] = headX;
    tailY[0] = headY;
    for(int i=1; i< tailLength; i++){
        prev2x = tailX[i];
        prev2y = tailY[i];
        tailX[i] = prevx;
        tailY[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }

    // direction logic
    switch (dir){
        case LEFT:
            headX--;
            break;

        case RIGHT:
            headX++;
            break;

        case UP:
            headY--;
            break;

        case DOWN:
            headY++;
            break;

        // default:
        //     cout << "defualt exit!" << endl;
        //     Sleep(2000);
        //     break;
    }

    // walls 
    if(headX >= width){
        headX=0;
    }

    else if(headX < 0){
        headX = width -1;
    }

    if(headY >= height){
        headY = 0;
    }

    else if(headY < 0){
        headY = height -1;
    }

    // snake bite itself
    for(int i = 0; i < tailLength; i++){
        if(tailX[i] == headX && tailY[i] == headY){
            cout << "Game Over!!!" << endl;
            Sleep(2000);
            gameOver = true;
        }
    }

    // snake eats the fruit
    if(headX == fruitX && headY == fruitY){
        score =  score +10;
        fruitX = rand()%width;
        fruitY = rand()%height;
        tailLength++;
    }
}