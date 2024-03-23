# 1) Задание 

Осортировать массив сортировкой Бойра-Мура и сортировкой Кнута-Мориса-Пратта

# 2) Код программы

```cpp
#include <iostream>
using namespace std;
const int Panzerselbstfahrlafette = 25;
int menu()
{
    cout << "1 - сортировка ведрами(карманами)\n" << "2 - сортировка подсчетом\n" << "3 - сортировка слиянием\n" << "4 - быстрая сортировка\n" << "Введите цифру соответствующую тому какой метод сортировки будет использован: ";
    int n;
    cin >> n;
    return n;
}
void show_array(int arr[])
{
    for (int i = 0; i < Panzerselbstfahrlafette; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void bucketSort(int arr[])
{
    const int BUCKET_NUM = 10;
    const int BUCKET_SIZE = 10;

    int buckets[BUCKET_NUM][BUCKET_SIZE];

    int bucketSizes[BUCKET_NUM] = { 0 };
    for (int i = 0; i < Panzerselbstfahrlafette; i++)
    {
        int bucketIndex = arr[i] / BUCKET_NUM;
        buckets[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
        bucketSizes[bucketIndex]++;
    }
    for (int i = 0; i < BUCKET_NUM; i++)
    {
        for (int j = 0; j < bucketSizes[i]; j++)
        {
            int tmp = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > tmp)
            {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = tmp;
        }
    }
    int idx = 0;
    for (int i = 0; i < BUCKET_NUM; i++)
    {
        for (int j = 0; j < bucketSizes[i]; j++)
        {
            arr[idx++] = buckets[i][j];
        }
    }
}
void countSort(int arr[])
{
    int *output= new int[Panzerselbstfahrlafette];
    int* count;
    int max = arr[0];
    for (int i = 0; i < Panzerselbstfahrlafette; i++)
    {
        if (arr[i] > max) { max = arr[i]; }
    }

    count = new int[max + 1];
    for (int i = 0; i <= max; ++i) { count[i] = 0; }

    for (int i = 0; i < Panzerselbstfahrlafette; i++) count[arr[i]]++;
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = Panzerselbstfahrlafette - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < Panzerselbstfahrlafette; i++) arr[i] = output[i];

    delete[] count;
}
void merge(int arr[], int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int* left = new int[n1];
    int* right = new int[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[start + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < n1)
        arr[k++] = left[i++];

    while (j < n2)
        arr[k++] = right[j++];

    delete[] left;
    delete[] right;
}
void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pI = partition(arr, low, high);
        quickSort(arr, low, pI - 1);
        quickSort(arr, pI + 1, high);
    }
}
int main()
{
    setlocale(LC_ALL, "ru_RU");
    int* array = new int[Panzerselbstfahrlafette];
    for (int i = 0; i < Panzerselbstfahrlafette; i++) { array[i] = rand() % 10; }
    cout << "Исходный массив: ";
    show_array(array);
    switch (menu())
    {
    case 1:
        bucketSort(array);
        cout << "Отсортированный массив: ";
        show_array(array);
        break;
    case 2:
        countSort(array);
        cout << "Отсортированный массив: ";
        show_array(array);
        break;
    case 3:
        mergeSort(array, 0, Panzerselbstfahrlafette - 1);
        cout << "Отсортированный массив: ";
        show_array(array);
        break;
    case 4:
        quickSort(array, 0, Panzerselbstfahrlafette - 1);
        cout << "Отсортированный массив: ";
        show_array(array);
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

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/complex_sorts/images/compl_sort_main.drawio.png">

Функция quickSort

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/complex_sorts/images/sortir_quick.drawio.png">

Функция partition

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/complex_sorts/images/sortir_parti.drawio.png">

Функция mergeSort

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/complex_sorts/images/sortir_mergesort.drawio.png">

Функция merge

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/complex_sorts/images/sortir_merge.drawio.png">

Функция countSort

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/complex_sorts/images/sortir_count.drawio.png">

Функция menu

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/complex_sorts/images/compl_sort_menu.drawio.png">

Функция bucketSort

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/complex_sorts/images/compl_sort_buck.drawio.png">

Функция show_array

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/complex_sorts/images/sortir_show.drawio.png">



# 4) Тесты

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/complex_sorts/images/изображение_2024-03-24_015806882.png">

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/complex_sorts/images/изображение_2024-03-24_015801599.png">

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/complex_sorts/images/изображение_2024-03-24_015755212.png">

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/complex_sorts/images/изображение_2024-03-24_015743532.png">
