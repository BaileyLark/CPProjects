#include <iostream>
#include <conio.h> // console input / output
#include <Windows.h>

bool gameOver;
const int width = 20; 
const int height = 20; 
int x, y, fruitx, fruity, score; 
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir; 
int tailx[100], taily[100];
int nTail;

void Setup()
{
    gameOver = false; 
    dir = STOP; 
    x = width / 2;
    y = height / 2; 
    fruitx = 5; //rand() % width; 
    fruity = 5; //rand() % height; 
    score = 0;
}

void Draw() 
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });  // clears the screen

    // first row
    for (int i = 0; i < width; i++)
        std::cout << "#";
    std::cout << std::endl;

    // middle rows
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (j == 0 || j == width - 1)
                std::cout << "#";
            if (i == y && j == x)
                std::cout << "0";
            else if (i == fruitx and j == fruity)
                std::cout << "F";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailx[k] == j && taily[k] == i)
                    {
                        std::cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    std::cout << " ";
            }
         
        }
        std::cout << std::endl;
    }

    // final row 
    for (int i = 0; i < width; i++)
        std::cout << "#";
    std::cout << std::endl;
    std::cout << "Score: " << score << std::endl; 
    std::cout << "pX: " << x << " pY: " << y << std::endl;
    std::cout << "fX: " << fruitx << " fY: " << fruity << std::endl;
}

void Input()
{
    if (_kbhit()) // returns bool if the keyboard char is pressed
    {
        switch (_getch()) // returns char of keypressed at given moment
        {
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
        case 'x':
            gameOver = true; 
            break; 
        }
    }
    if (x > width || x < 0 || y > height || y < 0)
        gameOver = true; 

    if (x == fruitx && y == fruity)
    {
        score += 10; 
        fruitx = rand() % width;
        fruity = rand() % height;
        nTail++;
    }
}

void Logic()
{
    int prevx = tailx[0];
    int prevy = taily[0];
    int prev2x, prev2y; 
    tailx[0] = x;
    taily[0] = y;


    for (int i = 1; i < nTail; i++)
    {
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }

    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }
}

int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
    }
}

