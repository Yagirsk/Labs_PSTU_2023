#include <iostream>
using namespace std;
const int CHAR_NUM = 256;
void calcCharTable(string str, int size, int charTable[CHAR_NUM])
{
    for (int i = 0; i < CHAR_NUM; i++)
    {
        charTable[i] = -1;
    }
    for (int i = 0; i < size; i++)
    {
        charTable[(int)str[i]] = i;
    }
}
void boyerMooreSearch(string str, string pat)
{
    int str_size = str.size();
    int pat_size = pat.size();
    int shift_table[CHAR_NUM];
    calcCharTable(str, pat_size, shift_table);
    int shift = 0;
    while (shift <= (str_size - pat_size))
    {
        int j = pat_size - 1;
        while (j >= 0 && pat[j] == str[shift + j]) { j--; }
        if (j < 0)
        {
            cout << "Паттерн найден на позиции " << shift + 1 << endl;
            if (shift + pat_size < str_size)
                shift += pat_size - shift_table[(int)str[shift + pat_size]];
            else
                shift++;
        }
        else
        {
            shift += max(1, j - shift_table[(int)str[shift + j]]);
        }
    }
}
int* prefixFunc(string pat, int size)
{
    int* lps = new int[size]; //longest prefix suffix
    int len = 0, i = 1;
    lps[0] = 0;
    while (i < size)
    {
        if (pat[i] == pat[len])
        {
            lps[i] = len;
            len++;
            i++;
        }
        else
        {
            if (len != 0) { len = lps[len - 1]; }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
void KMPsearch(string str, string pat)
{
    int str_size = str.size();
    int pat_size = pat.size();
    int* lps = prefixFunc(pat, pat_size);
    int str_idx = 0;
    int pat_idx = 0;
    while ((str_size - str_idx) >= (pat_size - pat_idx))
    {
        if (pat[pat_idx] == str[str_idx])
        {
            str_idx++;
            pat_idx++;
        }
        if (pat_idx == pat_size)
        {
            cout << "Паттерн найден на позиции " << str_idx - pat_idx + 1 << endl;
            pat_idx = lps[pat_idx - 1];
        }
        else if (str_idx < str_size && pat[pat_idx] != str[str_idx])
        {
            if (pat_idx != 0) { pat_idx = lps[pat_idx - 1]; }
            else { str_idx++; }
        }
    }
}
int main()
{
    setlocale(LC_ALL, "ru_RU");
    string str, pat;
    cout << "Введите строку в которой будет происхожить поиск\n";
    cin >> str;
    cout << "Введти паттерн который будет искаться\n";
    cin >> pat;
    cout << "1 - бойра мура\n2 - КМП\nВведите цифру которая бдует соответствовать поиску которых нужно применить: ";
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        boyerMooreSearch(str, pat);
        break;
    case 2:
        KMPsearch(str, pat);
        break;
    default: 
        cout << "Неправильный выбор";
    }
}