// 24 December 2022
// Claudio Hans Figo aka Ryo-senpai
// 22.12.2321

// Simple terminal Based Game using C++
// Mining Game

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <fstream>

using namespace std;

int hp, copper, silver, gold, coin, med, earnings[20], scoreIndex = 0;
int isGameOver, user, isHasPlayed = 'N';
string userName[20], dif;

void mainMenu();
void leaderboard();
void askUsername();
void mine();
void difficultyMenu();
void homeMenu();
void town();
void random();
void sell();
void buyMed();
void saveGame();
void useMedkit();
void gameOver();
void log();
void printASCII(string filename);
void isExit();

int main(int argc, char const *argv[])
{

    copper = 0;
    silver = 0;
    gold = 0;
    hp = 0;
    coin = 0;

    do
    {
        mainMenu();

        scoreIndex += 1;

        gameOver();

    } while (isGameOver != 'N');

    return 0;
}

void mainMenu()
{
    int user = ' ';
    string ascii = "title.txt";
    while (user != 'Q')
    {
        system("cls");
        printASCII(ascii);
        cout << "\nHello!!\nWelcome to our minigames\n\nSelect Menu\n[1]New Game\n[2]Leaderboard";
        cout << "\n\n\nPress Q to Exit Game " << endl;
        user = _getch();
        user = toupper(user);

        if (user == '1')
        {

            askUsername();
            difficultyMenu();
            homeMenu();
            user = 'Q';

            break;
        }
        else if (user == '2')
        {
            leaderboard();
        }

        
    }
}

void askUsername()
{
    system("cls");
    Sleep(600);
    cout << "Please input your name : ";
    getline(cin, userName[scoreIndex]);
    isHasPlayed = 'Y';
}

void leaderboard()
{
    system("cls");

    if (isHasPlayed != 'Y')
    {
        cout << "No Records \n";
        Sleep(1000);
        system("cls");
    }
    else
    {
        cout << "LeaderBoard :\n";
        for (int i = 0; i < scoreIndex; i++)
        {
            cout << i + 1 << " " << userName[i] << " = " << earnings[i] << endl;
        }
        cout << "\n\nPress any key to return\n";
        _getch();
    }
}

void difficultyMenu()
{
    system("cls");
    Sleep(400);

    cout << "Select Dificulty\n[1]Normal\n[2]Hard" << endl;
    user = _getch();

    if (user == '1')
    {
        hp = 5, coin = 5, med = 2;
        dif = "Normal";
    }

    if (user == '2')
    {
        hp = 3, coin = 0, med = 0;
        dif = "Hard";
    }
}

void homeMenu()
{

    while (user != 'Q')
    {
        system("cls");
        Sleep(200);
        user = ' ';
        system("cls");
        cout << "Difficulty : " << dif << "    Earning :" << earnings[scoreIndex];
        cout << "\n\nWelcome Home " << userName[scoreIndex] << "\n\nSelect Actions\n[1]Mine\n[2]Town" << endl;
        cout << "\n\n\n\n\n"
             << "Copper :" << copper << "  Silver :" << silver << "  Gold :" << gold << "  Coin : " << coin << "\n\nHP : " << hp << "  Medkit : " << med << endl;

        cout << "\n\nPress H to Use Medkit " << endl;
        cout << "Press Q to Exit Game " << endl;
        user = _getch();
        user = toupper(user);

        if (user == '1')
        {
            mine();
            if (isGameOver == 'N')
            {
                user = 'Q';
                break;
            }
        }
        else if (user == '2')
        {
            town();
        }
        else if (user == 'H')
        {
            system("cls");
            useMedkit();
            system("cls");
        }

        if (user == 'Q')
        {
            system("cls");
            cout << "QUIT GAME?";
            cout << "\nProgress will not be saved ? (y/n)";
            user = _getch();
            user = toupper(user);

            if (user == 'Y')
            {
                system("cls");
                break;
            }
            else
            {
                system("cls");
                user = ' ';
            }
        }
    }
}

void mine()
{

    int isMining, isGameOverMine;
    bool isUseMed;
    while (isMining != 'Q')
    {
        do
        {
            while (!_kbhit())
            {
                isGameOverMine = ' ';

                system("cls");
                cout << "Mining." << endl;
                cout << "\n\n\nHp : " << hp << "     Press Q to Exit";
                cout << "\nMedkit : " << med << "     Press H to use Medkit" << endl;
                Sleep(800);
                system("cls");
                cout << "Mining.." << endl;
                cout << "\n\n\nHp : " << hp << "     Press Q to Exit";
                cout << "\nMedkit : " << med << "     Press H to use Medkit" << endl;
                Sleep(1500);
                system("cls");
                cout << "Mining..." << endl;
                random();

                cout << "\n\n\nHp : " << hp << "     Press Q to Exit";
                cout << "\nMedkit : " << med << "     Press H to use Medkit" << endl;

                if (hp <= 0)
                {
                    if (isUseMed == true)
                    {
                        useMedkit();
                        isUseMed = false;
                    }
                    else
                    {
                        isGameOverMine = 'N';
                        break;
                        _kbhit;
                    }
                }
                Sleep(1000);
                system("cls");
            }

            if (isGameOverMine == 'N')
            {
                system("cls");
                cout << "You are dead !!";
                Sleep(1000);
                isGameOver = isGameOverMine;
                // system("cls");
                break;
            }
            else
            {
                int input = _getch();
                input = toupper(input);
                if (input == 'Q')
                {
                    isMining = 'Q';
                    break;
                }

                if (input == 'H')
                {
                    useMedkit();
                    isUseMed = true;
                }
            }

        } while (hp <= 0);

        if (hp <= 0)
        {
            break;
        }
    }
}

void town()
{

    bool status = false;
    while (!status)
    {
        system("cls");
        Sleep(200);
        user = ' ';
        cout << "You're in Town\nSelect Action\n[1]Sell\n[2]Buy Med\n[3]Go Home" << endl;
        user = _getch();
        user = toupper(user);

        if (user == '1')
        {
            sell();
        }
        if (user == '2')
        {
            buyMed();
        }
        if (user == '3')
        {
            status = true;
        }
        if (user == 'Q')
        {
            status = true;
        }
    }
}

void sell()
{
    system("cls");
    int oldCoin = coin;
    coin += (gold * 5) + (silver * 3) + (copper * 1);
    cout << "Alhamdullilah dapet +" << coin - oldCoin << endl;
    Sleep(1000);
    copper = 0;
    silver = 0;
    gold = 0;
    earnings[scoreIndex] += coin;
    system("cls");
}

void buyMed()
{

    if (coin != 0)
    {
        int isBuy;

        while (isBuy != '3')
        {
            int max = coin / 2;
            system("cls");
            cout << "Buy med ?\n[1]One Med\n[2]Max (" << max << " meds)\n[3]Back to Town";
            isBuy = _getch();
            isBuy = toupper(isBuy);
            if (isBuy == '1' || isBuy == '2')
            {
                if (coin >= 2)
                {
                    if (isBuy == '1')
                    {
                        system("cls");

                        cout << "Success !!\n+1 Med";
                        Sleep(1000);
                        med += 1;
                        coin -= 2;
                        isBuy = 'N';

                        system("cls");
                    }
                    else
                    {
                        system("cls");

                        coin -= max * 2;
                        med += max;

                        cout << "Success !!\n+ " << max << " med "
                             << "\n-" << max * 2 << " coins";
                        Sleep(1000);
                        system("cls");
                    }
                }
                else
                {
                    system("cls");

                    cout << "Not Enough Coins !!";
                    Sleep(600);

                    system("cls");
                }
            }
            if (user == 3)
            {
                break;
            }
        }
    }
    else
    {
        cout << "You dont Have Money !!\n\n\nPress any Key to Continue...";
        _getch();
    }
}

void random()
{
    int random;
    random = rand() % 100;
    if (random >= 0 && random <= 5)
    {
        cout << "Alhamdullilah Gusti Dapet Gold\n";
        Sleep(200);
        gold += 1;
    }
    else if (random > 5 && random <= 15)
    {
        cout << "Ihiyyy Silver nih Cuyy\n";
        Sleep(200);
        silver += 1;
    }
    else if (random > 15 && random <= 25)
    {
        cout << "Mayan Copper\n";
        Sleep(200);
        copper += 1;
    }
    else if (random > 26 && random <= 50)
    {
        cout << "You've Encountered an Enemy !!\n\nhp-2!!";
        Sleep(600);
        hp -= 2;

        if (hp <= 0)
        {
            hp = 0;
        }
    }
    else
    {
        cout << "Huhu g dpet\n";
        Sleep(200);
    }
}

void useMedkit()
{
    if (med >= 0)
    {

        if (hp >= 5)
        {
            system("cls");
            cout << "+0 HP";
            Sleep(400);
            system("cls");
            hp = 5;
        }
        else
        {
            system("cls");
            cout << "+2 HP";
            Sleep(800);
            system("cls");
            med -= 1;
            hp += 2;
        }
    }
    else
    {
        system("cls");
        cout << "You don't have Medkit !!";
        Sleep(400);
        system("cls");
    }
}

void log()
{
    system("cls");
    cout << "Log";
    Sleep(1000);
    system("cls");
}

void gameOver()
{
    system("cls");
    cout << "Game Over !! \nContinue? (y/n)";
    isGameOver = _getch();
    isGameOver = toupper(isGameOver);
    system("cls");
}

void printASCII(string filename)
{
    string line = " ";
    ifstream inFile;
    inFile.open("title.txt");
    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {
            cout << line << endl;
        }
    }
    else
    {
        cout << "Failed to Display" << endl;
    }
}

void saveGame()
{
    system("cls");
    cout << "Saving." << endl;
    Sleep(800);
    system("cls");
    cout << "Saving.." << endl;
    Sleep(800);
    system("cls");
    cout << "Saving..." << endl;
    Sleep(800);
    ofstream SaveFile("saveGames.txt");
    SaveFile << userName << endl;
    SaveFile << copper << endl;
    SaveFile << silver << endl;
    SaveFile << gold << endl;
    SaveFile << coin << endl;
    SaveFile << endl;
    SaveFile.close();

    system("cls");
    cout << "Game Saved !!" << endl;
    Sleep(800);
    system("cls");
}