#include <iostream>
using namespace std;
int menu1()
{
	int type;
	cout << "1 - задать массив упорядоченный по возрастанию (линейный поиск)\n2 - задать массив не упорядоченный по возрастанию (интерполяционный и бинарный поиск)\nВведите цифру соответствующую тому как задать массив: ";
	cin >> type;
	return type;
}
int menu2()
{
	int type;
	cout << "1 - интерполяционный поиск\n2 - бинарный поиск\nВведите цифру соответствующую тому какой метод поиска использовать: ";
	cin >> type;
	return type;
}
void print_array(int arr[], int zise)
{
	cout << "Массив: ";
	for (int i = 0; i < zise; i++) { cout << arr[i] << " ";}
	cout << endl;
}
void linear_s(int arr[], int siz, int key)
{
	int* tmp = new int[0];
	int tmp_size = 0;
	for (int i = 0; i < siz; i++)
	{
		if (arr[i] == key)
		{
			tmp[tmp_size++] = i;
		}
	}
	if (tmp_size != 0)
	{
		for (int j = 0; j < tmp_size; j++)
		{
			cout << "Ключ найден на позиции: " << tmp[j] + 1 << endl;
		}
	}
	else { cout << "Элемент не найден\n"; }
}
void interpolating_search(int arr[], int sze, int key) 
{
	if (arr[0] == key) { cout << "Ключ найден на позиции: 1" << endl; return}
	int low = 0;
	int high = sze - 1;
	int mid;
	int key_place = - 1;
	while (arr[low] < key && arr[high] >= key)
	{
		mid = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);
		if (arr[mid] == key) { key_place = mid + 1; break; }
		else if (arr[mid] < key) { low = mid + 1; }
		else if (arr[mid] > key) { high = mid - 1; }
	}
	if (key_place != -1) 
	{
		cout << "Ключ найден на позиции: " << key_place << endl;
	}
	else 
	{
		cout << "Ключ не найден" << endl;
	}
}
void binary_search(int arr[], int sze, int key) {
	int low = 0;
	int high = sze - 1;
	while (low <= high) 
	{
		int mid = low + (high - low) / 2;

		if (arr[mid] == key)
		{
			cout << "Ключ найден на позиции: " << mid + 1 << endl;
			break;
		}
		else if (arr[mid] < key) 
		{
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "ru_RU");
	string endt;
	cout << "Введите 'Panzerselbstfahrlafette' если хотите прекратить работу программы: ";
	cin >> endt;
	if (endt == "Panzerselbstfahrlafette") { return 0; }

	int type_set_arr = menu1();
	if (type_set_arr == 1)
	{
		int size, key;
		cout << "Введите длинну массива: ";
		cin >> size;
		int* array = new int[size];
		for (int i = 0; i < size; i++) { array[i] = rand() % 21; }
		print_array(array, size);
		cout << "Введите значение которое надо искать: ";
		cin >> key;
		linear_s(array, size, key);
	}

	else if (type_set_arr == 2)
	{
		int size, key, tmp = 0;
		cout << "Введите длинну массива: ";
		cin >> size;
		int* array = new int[size];
		for (int i = 0; i < size; i++) 
		{
			tmp += rand() % 3 + 1;
			array[i] = tmp;
		}

		print_array(array, size);
		cout << "Введите значение которое надо искать: ";
		cin >> key;
		cout << "\n\n";
		int type_search = menu2();

		if (type_search == 1) { interpolating_search(array, size, key); }
		else if (type_search == 2) { binary_search(array, size, key); }
		else { cout << "Неправильный выбор"; }

	}
	else { cout << "Неправильный выбор"; }

	system("pause");
	main();
}
