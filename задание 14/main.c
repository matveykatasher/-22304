include <iostream>
#include <windows.h>
#include <conio.h>
 
using namespace std;
 
void gameOverManagement()
{
system("cls");
cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t     Game Over!\n\n\n\n\n\n\n\n\n\n\n";
system("pause");
Sleep(1000);
exit(0);
} void gameVictoryManagement()
{
system("cls");
cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t     Victory!\n\n\n\n\n\n\n\n\n\n\n";
system("pause");
} int dataManagement(int management, int stopGame)
{
if(management == 1)
{
  gameOverManagement();
  stopGame = 1;
}
if(management == 3)
{
  gameVictoryManagement();
  stopGame = 1;
}
management = 2;
return management,stopGame;
}
int main()
{
// 1 - стенки лабиринта
// 0 - путь
    int mas[24][24] = { {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
                        {1,0,1,0,0,1,0,1,0,0,0,1,1,1,1,0,0,0,0,1,},
                        {1,0,1,1,0,1,0,1,0,1,0,0,0,0,1,0,1,1,0,1,},
                        {1,0,0,0,0,0,0,1,0,1,1,1,1,0,1,0,0,1,0,1,},
                        {1,1,1,1,1,1,0,1,0,1,0,0,1,0,1,1,0,1,0,1,},
                        {1,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,1,},
                        {1,0,1,1,0,1,1,1,1,1,0,0,1,0,1,1,1,1,0,1,},
                        {1,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,1,},
                        {1,1,1,1,1,1,0,1,1,1,0,0,0,0,1,0,1,1,1,1,},
                        {1,1,0,0,0,1,0,0,1,1,0,1,1,1,1,0,0,0,0,1,},
                        {1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,1,1,0,1,},
                        {1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,},
                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,},
                        {1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,},
                        {1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,1,0,1,},
                        {1,0,1,1,1,1,1,0,1,0,1,1,1,0,1,0,0,0,0,1,},
                        {1,0,1,0,0,0,1,0,1,0,0,0,1,1,1,1,1,1,1,1,},
                        {1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,},
                        {1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,},
                        {1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,},
                        {1,0,1,0,1,0,0,0,1,0,1,1,1,1,1,1,0,1,0,1,},
                        {1,0,1,0,1,1,1,1,1,0,0,0,1,0,1,0,0,1,0,1,},
                        {1,0,1,0,0,0,0,0,1,1,1,0,0,0,1,0,1,1,0,1,},
                        {1,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,} };
unsigned short keysArrow; int s1 = 0;
int s2 = 1;
int stopGame(0);
mas[s1][s2] = 2; do
{
  system("cls");
  for (int i = 0; i < 24; i++) //переключение по строкам
  {
   for (int j = 0; j < 20; j++)// переключение по столбцам
   {
    if (mas[i][j] == 1)
    {
     // вывести два раза символ (номер которого 176 в таблице аски) в консоль
     cout << static_cast<char>(176);
     cout << static_cast<char>(176);
    }
    if (mas[i][j] == 0 || mas[i][j] == 3)
    {
      cout << "  ";
    }
    if (mas[i][j] == 2)
    {
      cout << static_cast<char>(182);
      cout << static_cast<char>(182);
    }
   }
   cout << endl;
  }
  keysArrow = getch();
  keysArrow = getch();   if(keysArrow == 0)
  keysArrow = getch();
  if(keysArrow == 72 || keysArrow == 150 || keysArrow == 230)
  {
   // Вверх
   mas[s1][s2] = 1;
   s1--;
   dataManagement(mas[s1][s2],stopGame);
   mas[s1][s2] = 2;
  }
  if(keysArrow == 80 || keysArrow == 155 || keysArrow == 235)
  {
   // Вниз
   mas[s1][s2] = 1;
   s1++;
   dataManagement(mas[s1][s2],stopGame);
   mas[s1][s2] = 2;
  }
  if(keysArrow == 77 || keysArrow == 130 || keysArrow == 262)
  {
   // Вправо
   mas[s1][s2] = 1;
   s2++;
   dataManagement(mas[s1][s2],stopGame);
   mas[s1][s2] = 2;
  }
  if(keysArrow == 75 || keysArrow == 148 || keysArrow == 235)
  {
   // Влево
   mas[s1][s2] = 1;
   s2--;
   dataManagement(mas[s1][s2],stopGame);
   mas[s1][s2] = 2;
  }
} while(true);
    getch();
    return 0;
}