#include <iostream>
#include <vector>
#include <Windows.h>
#include "Snake.h"
#include "Apple.h"
#include "Sharp.h"
#define WIDTH 16
#define HEIGHT 10
using namespace std;
int drawFrame(int height, int width, int delayTime, Snake snake, Apple apple, Sharp sharp){
    system("cls");
    for (int i = 0; i < width + 2; i++){
        cout<<"-";
    }
    vector<vector<char>> matrix;
    for(int i = 0; i < height; i++){
        matrix.push_back({});
        for (int j = 0; j < width; j++){
            matrix[i].push_back(' ');
        }
    }
    for (int i = 1; i < snake.body.size(); i++){
        matrix[snake.body[i][1]][snake.body[i][0]] = snake.pSymbol(i);
    }
    for (auto i : sharp.sharps){
        matrix[i[1]][i[0]] = 'W';
    }
    matrix[snake.body[0][1]][snake.body[0][0]] = '+';
    matrix[apple.apple[1]][apple.apple[0]] = '=';
    cout<<"\n";
    for (auto i : matrix){
        for (auto j : i){
            cout<<j;
        }
        cout<<"\n";
    }

    for (int i = 0; i < width + 2; i++){
        cout<<"-";
    }
    Sleep(delayTime);
    return 0;
}
int main(){
    int speed;
    cout<<"Choose your speed:\n";
    cin>>speed;
    int DELAYTIME = 1000 / speed;
    Snake s = Snake();
    Apple a = Apple();
    Sharp sh = Sharp();
    s.body = {{0, 0}};
    s.direction = {1, 0};
    a.Spawn(s.body, sh.sharps, WIDTH, HEIGHT);
    cout<<"Once in how many apples you wanna get sharps?\n";
    cin>>sh.amountToSharp;
    while (true){
        if (GetAsyncKeyState(VK_UP)){
            s.ChangeDir({0, -1});
        }
        else if (GetAsyncKeyState(VK_DOWN)){
            s.ChangeDir({0, 1});
        }
        else if (GetAsyncKeyState(VK_LEFT)){
            s.ChangeDir({-1, 0});
        }
        else if (GetAsyncKeyState(VK_RIGHT)){
            s.ChangeDir({1, 0});
        }
        if (GetAsyncKeyState(VK_RSHIFT)){
            s.AddSegment();
        }
        s.ChangePos(WIDTH, HEIGHT);
        if (a.IsAppleAte(s.body)){
            s.AddSegment();
            a.Spawn(s.body, sh.sharps, WIDTH, HEIGHT);
            if (sh.amountToSharp != 0){
                if (a.count % sh.amountToSharp == 0 && a.count != 0){
                    sh.Spawn(s.body, a.apple, WIDTH, HEIGHT);
                }
            }
        }
        drawFrame(HEIGHT, WIDTH, DELAYTIME, s, a, sh);  
        if (s.Check(sh.sharps)){
            cout<<"You lost. Your score "<<a.count<<". Do you wanna try again? Y/N\n";
            char ch;
            cin>>ch;
            if (ch == 'Y'){
                cout<<"Choose your speed:\n";
                cin>>speed;
                DELAYTIME = 1000 / speed;
                s.body = {{0, 0}};
                s.direction = {1, 0};
                a.Spawn(s.body, sh.sharps, WIDTH, HEIGHT);
                a.count = 0;
                sh.sharps = {};
                cout<<"Once in how many apples you wanna get sharps?\n";
                cin>>sh.amountToSharp;
            }
            else{
                return 0;
            }
        }
    }
}