# 1) Задание
**Двумерные массивы** 

Заполнить двумерный массив: все элементы, которые выше 
главной диагонали = 0. Элементы главной диагонали и 
ниже главной диагонали, заполняются по возрастанию, 
начиная с 1. При этом каждая диагональ параллельная 
главной  состоит из одинаковых цифр.

# 2) Код программы

```cpp
#include <iostream>
using namespace std;
const int SIZE = 8;
int board[SIZE][SIZE];
bool t = 1;
void showBoard()
{
    for (int a = 0; a < 8; a++)
    {
        for (int b = 0; b < 8; b++)
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
    if (a == 8 && t == 1)
    {
        showBoard();
        t = 0;
        return;
    }
    for (int i = 0; i < 8; i++)
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
    cout << "Q - queen" << endl << ". - empty field cell" << endl;
    setQueen(0);
    return 0;
}
}
```

# 3) Блок схема
<image src ="lab2.drawio.png">
  
# 4) Тесты
<image src ="test1_lab2_TDA.png">

<image src ="test2_lab2_TDA.png">
