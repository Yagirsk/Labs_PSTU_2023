#include <iostream>
using namespace std;
int Panzerselbstfahrlafette;
int menu()
{
    cout << "1 - сортировка ведрами(карманами)\n" << "2 - сортировка подсчетом\n" << "3 - сортировка слиянием\n" << "4 - сортировка Шелла\n" << "5 - быстрая сортировка\n" << "Введите цифру соответствующую тому какой метод сортировки будет использован: ";
    int n;
    cin >> n;
    return n;
}
void setArray(int arr[])
{
    for (int i = 0; i < Panzerselbstfahrlafette; i++)
    {
        arr[i] = rand() % 10;
    }
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
    int BUCKET_NUM = sqrt(Panzerselbstfahrlafette)+2;
    int BUCKET_SIZE = sqrt(Panzerselbstfahrlafette) + 2;
    int** buckets;
    int l, h;
    buckets = new int*[BUCKET_NUM];
    for (l = 0; l < BUCKET_NUM; l++)
    {
        buckets[l] = new int[BUCKET_NUM];
        for (h = 0; h < BUCKET_NUM; h++)
        {
            buckets[l][h] = rand() % 10;
        }
    }
    int *bucketSizes= new int[BUCKET_NUM];
    for (int i = 0; i < BUCKET_NUM; i++) { bucketSizes[i] = 0; }
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
void shellSort(int arr[])
{
    for (int h = Panzerselbstfahrlafette / 2; h > 0; h /= 2)
    {
        for (int i = h; i < Panzerselbstfahrlafette; i++)
        {
            int tmp = arr[i];
            int j;
            for (j = i; j >= h && arr[j - h] > tmp; j -= h)
            {
                arr[j] = arr[j - h];
            }
            arr[j] = tmp;
        }
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
    cout << "Введите длинну массива: ";
    int n;
    cin >> n;
    if (n <= 0)
    {
        cout << "Нельзя создать массив с данным количеством элементов\n";
    }
    else if(n == 1)
    {
        int arr[1] = {rand() % 10};
        cout << "Исходный массив: " << arr[0] << endl;
        cout << "Массив из одного элемента отсортирован по умолчанию\n";
    }
    else
    {
        Panzerselbstfahrlafette = n;
        extern int n;
        int* array = new int[Panzerselbstfahrlafette];
        for (int i = 0; i < Panzerselbstfahrlafette; i++) { array[i] = rand() % 10; }
        setArray(array);
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
            shellSort(array);
            cout << "Отсортированный массив: ";
            show_array(array);
            break;
        case 5:
            quickSort(array, 0, Panzerselbstfahrlafette - 1);
            cout << "Отсортированный массив: ";
            show_array(array);
            break;
        default:
            cout << "Неправильный выбор " << endl;
            break;
        }
    }
    return 0;
}
