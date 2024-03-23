# 1) Задание 

Осортировать массив естественной сортипровкой и многофазной сортировкой

# 2) Код программы

```cpp
﻿#include <iostream>
using namespace std;
const int Panzerselbstfahrlafette = 25;
int t[26];
int ta;
void Merge(int c[], int d[], int l, int m, int r);
void multiPhaseSort(int arr[])
{
    bool swapped = true;
    int gap = Panzerselbstfahrlafette;
    while (gap > 1 || swapped)
    {
        gap = (gap * 10) / 13; 
        if (gap < 1)
            gap = 1;

        swapped = false;
        for (int i = 0; i < Panzerselbstfahrlafette - gap; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}
void MergePass(int x[], int y[], int s, int n)
{
    int i = 0;
    while (i <= ta - 2 * s)
    {
        int r = ((i + 2 * s) < ta) ? t[i + 2 * s] : n;

        Merge(x, y, t[i], t[i + s] - 1, r - 1);
        i = i + 2 * s;
    }
    if (i + s < ta)
        Merge(x, y, t[i], t[i + s] - 1, n - 1);
    else  if (i < ta)
    {
        for (int j = t[i]; j <= n - 1; j++)
            y[j] = x[j];
    }
}
void MergeSort(int a[], int n)
{
    int* b = new int[n];
    int s = 1;
    while (s < ta)
    {
        MergePass(a, b, s, n);  
        s += s; 
        MergePass(b, a, s, n);
        s += s;
    }
}
void Merge(int c[], int d[], int l, int m, int r)
{   
    int i = l, j = m + 1, k = r;

    while ((i <= m) && (j <= r))
    {
        if (c[i] <= c[j])
            d[l++] = c[i++];   
        else
            d[l++] = c[j++];
    }
    if (i > m)
        for (int q = j; q <= r; q++)   
            d[l++] = c[q];
    else
        for (int p = i; p <= m; p++) 
            d[l++] = c[p];
}
void GetBPoint(int a[], int b[], int n, int& m)
{
    int j = 0;
    b[j++] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] < a[i])
            b[j++] = i + 1;
    }
    m = j;
}
int menu()
{
    cout << "1 - многофазная сортировка\n2 - естественная сортировка\nВведите цифру соответствующую тому какой метод сортировки применить: ";
    int n;
    cin >> n;
    return n;
}
void yae(int arr[])
{
    for (int i = 0; i < Panzerselbstfahrlafette; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    setlocale(LC_ALL, "ru_RU");
    int bal[Panzerselbstfahrlafette];
    for (int i = 0; i < Panzerselbstfahrlafette; i++) { bal[i] = rand() % 10; }
    cout << "Исходный массив: ";
    yae(bal);
    switch (menu())
    {
    case 1:
        multiPhaseSort(bal);
        cout << "Отсортированный массив: ";
        yae(bal);
        break;
    case 2:
        GetBPoint(bal, t, Panzerselbstfahrlafette, ta);
        MergeSort(bal, Panzerselbstfahrlafette);
        cout << "Отсортированный массив: ";
        yae(bal);
        break;
    default:
        cout << "Неправильный выбор " << endl;
        break;
    }
    return 0;
}
```

# 3) Блок схема

Функция main

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/mnogofaz_estest/images/2_sort_main.drawio.png">

Функция menu

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/mnogofaz_estest/images/2_sort_menu.drawio.png">

Функция multiPhaseSort

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/mnogofaz_estest/images/2_sort_mf_sort.drawio.png">

Функция MergePass

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/mnogofaz_estest/images/2_sort_mergePass.drawio.png">

Функция MergeSort

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/mnogofaz_estest/images/2_sort_mergeSort.drawio.png">

Функция Merge

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/mnogofaz_estest/images/2_sort_merge.drawio.png">

Функция GetBPoint

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/mnogofaz_estest/images/2_sort_getB.drawio.png">

Функция yae

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/mnogofaz_estest/images/2_sort_yae.drawio.png">



# 4) Тесты

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/mnogofaz_estest/images/изображение_2024-03-24_021920150.png">

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/mnogofaz_estest/images/изображение_2024-03-24_021924470.png">

