// SPACE SHOOTER GAME  
// Hassan Ameen (21L-1781)  l211781@lhr.nu.edu.pk
// Syed Muhammad Hassaan Ali (21L-5297)  l215297@lhr.nu.edu.pk
// Jawaria Asim (21L-5157)  l215157@lhr.nu.edu.pk
// Ifra Ejaz (21l_7508)   l217508@lhr.nu.edu.pk 
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<fstream>
using namespace std;
int highscore;
int s1 = 30; //rows
int s2 = 90; //columns
int cl = 56; //center line
int ml = 0; // Main loop
int spc1 = s1;
int spc2 = s2;
int spccl = cl;
char game[30][90];
int aln1row = 1;
int aln2row = 1;
int aln3row = 1;
int aln4row = 1;
int aln5row = 1;
int frame = 0;
int enemy1;
int enemy2;
int enemy3;
int enemy4;
int enemy5;
int flag = 0;
int fire;
int bulletx = 26;  //Bullet row
int score = 48;
int lives = 51;
int level = 49;
int s;
int gift;
int giftrow = 1;
int n = 30;
//FUNCTION FOR CLEARING SCREEN
void clearscreen()
{
    COORD cursorPosition; cursorPosition.X = 0; cursorPosition.Y = 0; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void Shipmoveleft(int& cl)
{
    game[28][cl / 2] = ' ';
    game[28][(cl / 2) - 2] = char(207);
    cl = cl - 2;
}



void Shipmoveright(int& cl)
{
    game[28][cl / 2] = ' ';
    game[28][(cl / 2) + 2] = char(207);
    cl = cl + 2;
}


// GENERATING ALIENS
void Alien1()
{
    if (flag == 1)
    {
        aln1row = 1;
        flag = 0;
    }
    if (aln1row < 29)
    {
        game[aln1row][enemy1] = char(12);
    }
    else
    {
        enemy1 = rand() % 55;
        aln1row = 1;
    }
}
void Alien2()
{
    if (flag == 1)
    {
        aln2row = 1;
        flag = 0;
    }
    if (aln2row < 29)
    {
        game[aln2row][enemy2] = char(12);
    }
    else
    {
        enemy2 = rand()% 55;
        aln2row = 1;
    }
}
void Alien3()
{
    if (flag == 1)
    {
        aln3row = 1;
        flag = 0;
    }
    if (aln3row < 29)
    {
        game[aln3row][enemy3] = char(12);
    }
    else
    {
        enemy3 = rand() % 55;
        aln3row = 1;
    }
}
void Alien4()
{
    if (flag == 1)
    {
        aln4row = 1;
        flag = 0;
    }
    if (aln4row < 29)
    {
        game[aln4row][enemy4] = char(12);
    }
    else
    {
        enemy4 = rand() % 55;
        aln4row = 1;
    }
}
void Alien5()
{
    if (flag == 1)
    {
        aln5row = 1;
        flag = 0;
    }
    if (aln5row < 29)
    {
        game[aln5row][enemy5] = char(12);
    }
    else
    {
        enemy5 = rand() % 55;
        aln5row = 1;
    }
}
// GENERATING GIFTS FOR EXTRA LIVES
void Gift(int& giftcol)
{
    if (giftrow < 29)
    {
        game[giftrow][giftcol] = char(254);
    }
    else 
    {
        if (giftrow>75)
        {
            giftcol = rand() % 55;
            giftrow = 1;
        }
    }
}

void StartingWindow()
{
    cout << "                      ==================================================" << endl;
    cout << "                      ==================================================" << endl;
    cout << "                      : :      " << char(254) << "                                     : :" << endl;
    cout << "                      : :                                            : :" << endl;
    cout << "                      : :                               " << char(248) << "            : :" << endl;
    cout << "                      : :                                            : :" << endl;
    cout << "                      : :                Space Shooter               : :" << endl;
    cout << "                      : :   " << char(248) << "                                        : :" << endl;
    cout << "                      : :                             " << char(207) << "              : :" << endl;
    cout << "                      : :                  LOADING...                : :" << endl;
    cout << "                      ==================================================" << endl;
    cout << "                      ==================================================" << endl;
    cout << endl << endl << endl;
    Sleep(4000);
    system("cls");
}


void credits()
{
    cout << "DEVELOPED BY : " << endl;
    cout << "            " << "1.Hassan Ameen (21L-1781)" << endl << "            " << "2.Syed Muhammad Hassaan Ali (21L-5297)" << endl << "            " << "3.Jawaria Asim (21L-5157)" << endl << "            " << "4.Ifra Ejaz (21L-7508)" << endl;
    system("pause");
    system("cls");
}

void highscoreshow()
{
    cout << "THE CURRENT HIGHSCORE IS : " << highscore << endl;
}

void controls()
{
    cout << "           " << "Please Read The Instructions Carefully Before You Play" << endl << endl;
    cout << "                    I N S T R U C T I O N S" << endl << endl;

    cout << "            1.Use ( arrow keys / A or D ) to move around  " << endl << endl;
    cout << "            2.Press space to fire bullets         " << endl << endl;
    cout << "            3.Avoid hitting space debris          " << endl << endl;
    cout << "            4.There are a total of 5 levels.          " << endl << endl;
    cout << "            5.Difficulty in form of number of aliens and speed of game increases with each level.                 " << endl << endl;
    cout << "            6.Ocassional gifts increases your lives                 " << endl << endl;
    cout << "            7.You must complete all 5 levels to win.        " << endl << endl << endl;
    system("pause");
    system("cls");
}
// BULLET FIRE AND MOVE
void Bulletfire(int spccl, int bulletx)
{
    game[bulletx][spccl / 2] = '^';
}
void Bulletmove(int spccl, int bulletx)
{
    game[bulletx][spccl / 2] = '^';
}


void play()
{
    spc1 = s1;
    spc2 = s2;
    spccl = cl;
    lives = 51;
    score = 48;
    level = 49;
    ml = 0;
    aln1row = 1;
    aln2row = 1;
    aln3row = 1;
    aln4row = 1;
    aln5row = 1;
    frame = 0;
    flag = 0;
    fire;
    bulletx = 26;
    s = 0;
    Bulletfire(spccl, bulletx);

    while (ml == 0)
    {
        for (int rows = 0; rows != s1; rows++)
        {
            for (int cols = 0; cols != s2; cols++)
            {
                if (rows == 0 || rows == s1 - 1 || cols == 0 || cols == s2 - 1 || cols == cl)
                {
                    game[rows][cols] = char(178);
                }
                else
                {
                    game[rows][cols] = char(255);
                }
            }
        }
        game[28][spccl / 2] = char(207);  //spaceship position
        game[8][63] = 'S';
        game[8][64] = 'C';
        game[8][65] = 'O';
        game[8][66] = 'R';
        game[8][67] = 'E';
        game[8][68] = ':';
        game[8][69] = score;
        game[12][63] = 'L';
        game[12][64] = 'I';
        game[12][65] = 'V';
        game[12][66] = 'E';
        game[12][67] = 'S';
        game[12][68] = ':';
        game[12][69] = lives;
        game[16][63] = 'L';
        game[16][64] = 'E';
        game[16][65] = 'V';
        game[16][66] = 'E';
        game[16][67] = 'L';
        game[16][68] = ':';
        game[16][69] = level;
        char move;
        // GENRATING RANDOM VALUES FOR ENEMIES
        if (frame == 0)
        {
            enemy1 = rand() % cl;
        }
        if (frame == 1)
        {
            enemy2 = rand() % cl / 2;
        }
        if (frame == 2)
        {
            enemy3 = rand() % cl / 4;
        }
        if (frame == 4)
        {
            enemy4 = rand() % 58;
        }
        if (frame == 5)
        {
            enemy5 = rand() % 25;
        }
        if (frame==6)
        {
            gift = rand() % cl;
        }
        frame++;
        // CALLING GIFT
        Gift(gift);
        giftrow++;
        // INCREASING DIFFICULTY WITH LEVELS
        if (level == 49)  //level 1
        {
            Alien1();
            aln1row++;
        }
        else if (level == 50)  //level 2
        {
            Alien1();
            Alien2();
            aln1row++;
            aln2row++;
        }
        else if (level == 51)   //level 3
        {
            Alien1();
            Alien2();
            Alien3();
            aln1row = aln1row + 2;   // INCREASING SPEED OF ALIENS
            aln2row = aln2row + 2;
            aln3row = aln3row + 2;
        }
        else if (level == 52)   //level 4
        {
            Alien1();
            Alien2();
            Alien3();
            Alien4();
            aln1row = aln1row + 2;
            aln2row = aln2row + 2;
            aln3row = aln3row + 2;
            aln4row = aln4row + 2;
        }
        else if (level == 53)  //level 5
        {
            Alien1();
            Alien2();
            Alien3();
            Alien4();
            Alien5();
            aln1row = aln1row + 2;
            aln2row = aln2row + 2;
            aln3row = aln3row + 2;
            aln4row = aln4row + 2;
            aln5row = aln5row + 2;
        }
        // BULLET FIRE
        if (bulletx > 2)
        {
            Bulletmove(spccl, bulletx);
            bulletx--;
        }
        else
        {
            if (_kbhit())
            {
                fire = _getch();
                if (fire == char(119) || fire == char(32))
                {
                    bulletx = 26;
                    Bulletfire(spccl, bulletx);
                }
            }
        }
        // PRINTING FRAME
        for (int rows = 0; rows != s1; rows++)
        {
            for (int cols = 0; cols != s2; cols++)
            {
                cout << game[rows][cols];
            }
            cout << endl;
        }
        // WINNING LAYOUT
        if (level >= 54)
        {
            system("cls");
            cout << " ___________________________________________________________ " << endl;
            cout << "|  ______________________________________________________   |" << endl;
            cout << "|  |                                                     |  |" << endl;
            cout << "|  |                                                     |  |" << endl;
            cout << "|  |                                                     |  |" << endl;
            cout << "|  |                                                     |  |" << endl;
            cout << "|  |                                                     |  |" << endl;
            cout << "|  |                  Y O U  W I N  ! !                  |  |" << endl;
            cout << "|  |                                                     |  |" << endl;
            cout << "|  |                      (^ o ^)                        |  |" << endl;
            cout << "|  |                                                     |  |" << endl;
            cout << "|  |                                                     |  |" << endl;
            cout << "|  |                                                     |  |" << endl;
            cout << "|  |                                                     |  |" << endl;
            cout << "|  |                                                     |  |" << endl;
            cout << "|  |_____________________________________________________|  |" << endl;
            cout << "|___________________________________________________________|" << endl;
            cout << "                    TOTAL POINTS : " << s << "               " << endl;
            cout << "                                                             " << endl;
            Sleep(10000);
            system("pause");
            system("cls");
            ml = 1;
        }
        // LOOSING LIVES ACCORDING TO SPEED
        if (level < 51)
        {
            if (game[28][spccl / 2] == char(12))
            {
                lives--;
            }
        }
        else
        {
            if (game[28][spccl / 2] == char(12) || game[27][spccl / 2] == char(12))
            {
                lives--;
            }
        }
        // INCREASIG LIVES BY GIFTS
        if (game[28][spccl / 2] == char(254))
        {
            lives++;
        }
        // INCREASING SCORE WHEN BULLET HIT THE ALIEN
        if (game[bulletx][spccl / 2] == char(12) || game[bulletx-1][spccl / 2] == char(12) || game[bulletx - 1][(spccl / 2)-1] == char(12) || game[bulletx - 1][(spccl / 2)+1] == char(12))
        {
            s = s + 10;
            score++;
            flag = 1;
        }
        // INCREASING LEVEL ON SCORE 5
        if (score >= 53)
        {
            score = 48;
            level++;
        }
        // LOOSING LAYOUT
        if (lives == 48)
        {
            system("cls");
            cout << " ___________________________________________________________ " << endl;
            cout << "|  ______________________________________________________   |" << endl;
            cout << "|  |                                                     |  |" << endl;
            cout << "|  |                                                     |  |" << endl;
            cout << "|  |                                                     |  |" << endl;
            cout << "|  |                                                     |  |" << endl;
            cout << "|  |                                                     |  |" << endl;
            cout << "|  |                                                     |  |" << endl;
            cout << "|  |                 G A M E  O V E R  ! !               |  |" << endl;
            cout << "|  |                                                     |  |" << endl;
            cout << "|  |                       ( T T )                       |  |" << endl;
            cout << "|  |                                                     |  |" << endl;
            cout << "|  |                                                     |  |" << endl;
            cout << "|  |                                                     |  |" << endl;
            cout << "|  |                                                     |  |" << endl;
            cout << "|  |_____________________________________________________|  |" << endl;
            cout << "|___________________________________________________________|" << endl;
            cout << "                    TOTAL POINTS : " << s << "               " << endl;
            cout << "                                                             " << endl;
            Sleep(5000);
            system("pause");
            system("cls");
            ml = 1;
        }

        // SHIP MOVEMENT
        if (_kbhit())
        {
            move = _getch();
            if (move == 'a' || move == 'A')
            {
                if (spccl > 2)
                    Shipmoveleft(spccl);
            }
            else if (move == 'd' || move == 'D')
            {
                if (spccl < 110)
                    Shipmoveright(spccl);
            }
        }
        // CLEARING FRAME
        clearscreen();

    }
}

int menu(int a)
{
    cout << "           " << "Please Choose Any One Of The Following: " << endl << endl << "           " << "A.Play" << endl << "           " << "B.Controls" << endl << "           " << "C.Credits" << endl << "           " << "D.Highscore" << endl << "           " << "E.Exit" << endl << endl;

    int Enter;
    Enter = _getch();
    if (Enter == 97)
    {
        system("cls");
        play();
    }
    else if (Enter == 98)
    {
        system("cls");
        controls();
    }
    else if (Enter == 99)
    {
        system("cls");
        credits();
    }
    else if (Enter == 100)
    {
        system("cls");
        highscoreshow();
    }
    else if (Enter == 101)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "                               THANK YOU FOR PLAYING SPACE SHOOTER GAME";
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
        system("pause");
        a = -1;
    }
    cout << endl << endl << endl;
    return a;
}

int main()
{
    int Enter, ml = 0;
    fstream file;
    cout << "\t" << "\t" << "HELLO PLAYER! WELCOME TO SPACE SHOOTER" << endl << endl << endl;
    StartingWindow();
    for (int i = 1; i > 0; i++)
    {
        file.open("highscore.txt", ios::in);
        if (file)
        {
            file >> highscore;
            if (s > highscore)
            {
                highscore = s;
                file.close();
                file.open("highscore.txt", ios::out);
                {
                    file << s;
                }
            }
            file.close();
        }

        i = menu(i);
    }
    system("cls"); 
}