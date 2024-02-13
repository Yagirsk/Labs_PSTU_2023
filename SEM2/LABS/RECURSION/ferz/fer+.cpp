#include <iostream>
using namespace std;
const int SIZE = 8;
int board[SIZE][SIZE];
int resultN = 1;
void showBoard()
{
    for (int a = 0; a < SIZE; a++)
    {
        for (int b = 0; b < SIZE; b++)
        {
            cout << ((board[a][b]) ? "Q " : ". ");
        }
        cout << endl;
    }
}
bool chekQueen(int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        if (board[i][b] == 1)
        {
            return false;
        }
    }
    for (int i = 1; i <= a && b - i >= 0; i++)
    {
        if (board[a - i][b - i] == 1)
        {
            return false;
        }
    }
    for (int i = 1; i <= a && b + i < SIZE; i++)
    {
        if (board[a - i][b + i] == 1)
        {
            return false;
        }
    }
    return true;
}
void setQueen(int a)
{
    if (a == SIZE)
    {
        showBoard();
        cout << "Результат номер " << resultN++ << endl << endl;
        return;
    }
    for (int i = 0; i < SIZE; i++)
    {
        if (chekQueen(a, i))
        {
            board[a][i] = 1;
            setQueen(a + 1);
            board[a][i] = 0;
        }
    }
    return;
}
int main()
{
    setlocale(LC_ALL, "ru_RU");
    cout << "Q - queen" << endl << ". - пустая клетка поля" << endl << endl;
    setQueen(0);
    return 0;
}
