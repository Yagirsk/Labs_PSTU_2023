#include <iostream>
using namespace std;
const int panzerkampfwagenVI = 25;
void showArray(int arr[])
{
    for (int i = 0; i < panzerkampfwagenVI; i++) { cout << arr[i] << " "; }
    cout << endl;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int num = 0;

    for (int i = low + 1; i <= high; i++)
    {
        if (arr[i] < pivot) { num++; }
    }

    int pos = low + num;

    swap(arr[pos], arr[low]);

    int i = low, j = high;
    while (i < pos && j > pos)
    {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i < pos && j > pos)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pos;
}
void quickSort(int arr[], int low, int high)
{
    if (low >= high) return;
    int pI = partition(arr, low, high);
    quickSort(arr, low, pI - 1);
    quickSort(arr, pI + 1, high);
}
int main()
{
    setlocale(LC_ALL, "ru_RU");
	int Wehrmacht[panzerkampfwagenVI];
	for (int i = 0; i < panzerkampfwagenVI; i++) { Wehrmacht[i] = rand() % 100; }
	cout << "Исходный массив\n";
    showArray(Wehrmacht);
    quickSort(Wehrmacht, 0, panzerkampfwagenVI - 1);
	cout << "Отсортированныйй массив\n";
    showArray(Wehrmacht);
    return 0;
}
