#include <iostream>
#include <ostream>
using namespace std;
int collis = 0;
int error_push = 0;
string surname[50] = { "Иванов", "Петров", "Сидоров", "Козлов", "Смирнов", "Кузнецов", "Васильев", "Попов", "Соколов", "Михайлов","Новиков", "Федоров", "Морозов", "Волков", "Алексеев", "Лебедев", "Семенов", "Егоров", "Павлов", "Козлов","Степанов", "Николаев", "Орлов", "Андреев", "Макаров", "Никитин", "Захаров", "Зайцев", "Борисов", "Кудрявцев","Шарапов", "Григорьев", "Лазарев", "Исаев", "Тимофеев", "Фомин", "Калинин", "Герасимов", "Ефимов", "Тарасов","Беляков", "Артемьев", "Гаврилов", "Мельников", "Денисов", "Крылов", "Зуев", "Пономарев" 
};
string name[50] = { "Иван", "Петр", "Александр", "Дмитрий", "Андрей", "Сергей", "Михаил", "Юрий", "Олег", "Артем", "Владимир", "Николай", "Алексей", "Игорь", "Степан", "Константин", "Георгий", "Евгений", "Борис", "Виктор","Денис", "Василий", "Антон", "Григорий", "Илья", "Роман", "Максим", "Кирилл", "Тимур", "Арсений","Федор", "Павел", "Матвей", "Семен", "Леонид", "Вадим", "Ярослав", "Валентин", "Даниил", "Егор","Виталий", "Савелий", "Тарас", "Руслан", "Марк", "Лев", "Платон", "Глеб", "Давид" 
};
string patronymics[50] = { "Иванович", "Петрович", "Александрович", "Дмитриевич", "Андреевич", "Сергеевич", "Михайлович", "Юрьевич", "Олегович", "Артемович", "Владимирович", "Николаевич", "Алексеевич", "Игоревич", "Степанович", "Константинович", "Георгиевич", "Евгеньевич", "Борисович", "Викторович", "Денисович", "Васильевич", "Антонович", "Григорьевич", "Ильич", "Романович", "Максимович", "Кириллович", "Тимурович", "Арсеньевич", "Федорович", "Павлович", "Матвеевич", "Семенович", "Леонидович", "Вадимович", "Ярославович", "Валентинович", "Данилович", "Егорович", "Витальевич", "Савельевич", "Тарасович", "Русланович", "Маркович", "Львович", "Платонович", "Глебович", "Давидович" 
};
string adress_a[50] = {"Москва, ул. Ленина, д. 10, кв. 5", "Санкт-Петербург, пр. Невский, д. 20, кв. 3","Екатеринбург, ул. Пушкина, д. 15, кв. 8", "Новосибирск, пр. Гагарина, д. 12, кв. 4","Красноярск, ул. Советская, д. 7, кв. 2", "Владивосток, пр. Ленинградский, д. 3, кв. 6","Ростов-на-Дону, ул. Кирова, д. 9, кв. 1", "Казань, пр. Баумана, д. 25, кв. 7","Нижний Новгород, ул. Октябрьская, д. 14, кв. 10", "Сочи, ул. Морская, д. 22, кв. 5","Волгоград, ул. Победы, д. 18, кв. 7", "Омск, пр. Ленина, д. 22, кв. 11","Калининград, ул. Горького, д. 6, кв. 4", "Тюмень, ул. Советская, д. 14, кв. 3","Иркутск, пер. Цветочный, д. 9, кв. 2", "Самара, пр. Строителей, д. 17, кв. 6","Томск, ул. Лесная, д. 11, кв. 8", "Челябинск, ул. Заводская, д. 4, кв. 10","Барнаул, пр. Победы, д. 30, кв. 1", "Ульяновск, ул. Ленина, д. 5, кв. 3","Краснодар, ул. Солнечная, д. 13, кв. 6", "Ярославль, пр. Ленинградский, д. 8, кв. 2","Тула, ул. Пролетарская, д. 19, кв. 4", "Воронеж, пр. Победы, д. 7, кв. 9","Уфа, ул. Кирова, д. 16, кв. 3", "Курск, ул. Гагарина, д. 25, кв. 1","Пенза, пр. Октябрьский, д. 14, кв. 6", "Белгород, ул. Советская, д. 11, кв. 8","Саратов, ул. Лермонтова, д. 22, кв. 7", "Владимир, пр. Горького, д. 10, кв. 5","Тверь, ул. Цветочная, д. 8, кв. 3", "Киров, пр. Строителей, д. 12, кв. 4","Петрозаводск, ул. Пушкина, д. 30, кв. 2", "Мурманск, пр. Ленина, д. 16, кв. 7","Ижевск, ул. Октябрьская, д. 9, кв. 3", "Волжский, пр. Гагарина, д. 5, кв. 6","Хабаровск, ул. Ленинградская ,д .20 ,кв .11", "Тамбов ,пр .Баумана ,д .15 ,кв .8","Брянск ,ул .Советская ,д .7 ,кв .2","Смоленск, ул. Гагарина, д. 11, кв. 9","Кострома, пр. Ленина, д. 13, кв. 4","Магадан, ул. Пролетарская, д. 6, кв. 7","Йошкар-Ола, пр. Победы, д. 17, кв. 3","Тобольск, ул. Ленинградская, д. 28, кв. 5","Астрахань, ул. Советская, д. 9, кв. 2","Кемерово, пр. Горького, д. 21, кв. 6","Смоленск-18, ул. Цветочная-2а, д. 14б, кв. 1","Жуковский-1, пр. Строителей-2б, д. 23а, кв. 8","Дзержинск-2, ул. Мира-1г, д. 19в, кв. 3",
};
struct human
{
	string fio;
	long long int phone;
	string adress;
};
struct list_elem
{
	human data;
	list_elem* next;
	list_elem* prev;
};
struct list
{
	list_elem* start;
	int size_t;

	void init()
	{
		start = new list_elem;
		start->next = nullptr;
		start->prev = nullptr;
		size_t = 0;
	}

	void push_back(human data_n)
	{
		if (size_t == 0)
		{
			start->data = data_n;
			size_t++;
		}
		else if (size_t == 1)
		{
			list_elem* new_el = new list_elem;
			new_el->data = data_n;
			new_el->prev = start;
			new_el->next = nullptr;
			start->next = new_el;
			size_t++;
		}
		else
		{
			list_elem* tmp = start;
			while (tmp->next != nullptr)
			{
				tmp = tmp->next;
			}
			list_elem* new_el = new list_elem;
			new_el->data = data_n;
			new_el->next = nullptr;
			new_el->prev = tmp;
			tmp->next = new_el;
			size_t++;
		}
	}

	/*void push_front(human data_n)
	{
		list_elem* tmp = new list_elem;
		tmp->next = start;
		start = tmp;
		start->prev = nullptr;
		start->data = data_n;
		size_t++;
	}

	human pop_back()
	{
		if (size_t > 1)
		{
			list_elem* tmp;
			tmp = start;
			while (tmp->next != nullptr)
			{
				tmp = tmp->next;
			}
			human r_data = tmp->data;
			tmp->prev->next = nullptr;
			size_t--;
			return r_data;
		}
		else
		{
			human tmp = start->data;
			init();
			return tmp;
		}
	}

	human pop_front()
	{
		if (size_t > 1)
		{
			list_elem* tmp;
			tmp = start;
			human r_data = start->data;
			start = start->next;
			start->prev = nullptr;
			size_t--;
			return r_data;
		}
		else
		{
			human tmp = start->data;
			init();
			return tmp;
		}
	}

	human erase(int n)
	{
		if (n < size_t && n > 1)
		{
			int i = 1;
			list_elem* tmp;
			tmp = start;
			while (i < n)
			{
				tmp = tmp->next;
				i++;
			}
			human tmp_h = tmp->data;
			tmp = tmp->prev;
			tmp->next = tmp->next->next;
			tmp->next->prev = tmp;
			size_t--;
			delete tmp->next;
			return tmp_h;
		}
		else if (n == size_t)
		{
			return pop_back();
		}
		else if (n == 1)
		{
			human t = pop_front();
			return t;
		}
		else
		{
			cout << "Некорректная позиция\n";
			return{};
		}
	}*/

	void print()
	{
		if (size_t > 1)
		{
			list_elem* tmp = start;
			while (tmp != nullptr)
			{
				cout << tmp->data.fio << "   " << tmp->data.phone << "   " << tmp->data.adress << endl;
				tmp = tmp->next;
			} 
		}
		else if (size_t == 1)
		{
			cout << start->data.fio << "   " << start->data.phone << "   " << start->data.adress << endl;
		}
		else
		{
			cout << "Void list\n";
		}
	}
	void print_tab()
	{
		if (size_t > 1)
		{
			list_elem* tmp = start;
			while (tmp != nullptr)
			{
				cout << "\t" << tmp->data.fio << "   " << tmp->data.phone << "   " << tmp->data.adress << endl;
				tmp = tmp->next;
			}
		}
		else if (size_t == 1)
		{
			cout << "\t" << start->data.fio << "   " << start->data.phone << "   " << start->data.adress << endl;
		}
	}
};
human set_human()
{
	human new_h;
	string str_t = "";
	int a = rand() % 50;
	str_t += surname[a] + " ";
	a = rand() % 50;
	str_t += name[a] + " ";
	a = rand() % 50;
	str_t += patronymics[a];
	a = rand() % 50;
	new_h.adress = adress_a[a];
	new_h.phone = 80000000000 + abs(rand() % 100000) + abs(rand()%100000*100000);
	new_h.fio = str_t;
	return new_h;
}
int hash_fuction(string fio, int M)
{
	int sum = 0; int a = 0;
	for (int i = 0; i < fio.length(); i++)
	{
		a = fio[i];
		sum += a;
	}
	sum = sum % M;
	return abs(sum);
}
long long int set_search_phone()
{
	long long int phone;
	cout << "Введите номер телефона человека которого надо найти: ";
	cin >> phone;
	return phone;
}
int choice()
{
	int choi;
	cout << "1 - добавить элемент\n2 - удалить элемент\nВведите цифру соответствующую тому что вы хотите сделать, ввод любого иного значения соответствует не выполнению ни одного из действий: ";
	cin >> choi;
	return choi;
}
void add_del_list(int hash_size, list* &table)
{
	cout << "\n\n";
	human new_h;
	switch(choice())
	{
	case 1:
		cout << "Введите хэш-код по которому будет добавлен человек: ";
		int pos;
		new_h = set_human();
		cin >> pos;
		if (pos < hash_size && pos >= 0)
		{
			cout << "Будет добавлен  " << new_h.fio << "   " << new_h.phone << "   " << new_h.adress << endl;
			if (table[pos].size_t >= 1)
			{
				collis++;
			}
			table[pos].push_back(new_h);
		}
		else
		{
			cout << "Некорректная позиция\n";
		}
		break;
	case 2:
		cout << "Введите хэш-код и позицию человека которого надо удалить: ";
		int hash_del, pos_del;
		cin >> hash_del >> pos_del;
		if (hash_del < hash_size && hash_del >= 0 && pos_del <= table[hash_del].size_t && pos_del > 0)
		{
			if (pos_del != 1)
			{
				list_elem* tmp = table[hash_del].start;
				for (int i = 2; i < pos_del; i++)
				{
					tmp = tmp->next;
				}
				list_elem* tmp2 = tmp;
				tmp2 = tmp->next;
				tmp->next = tmp->next->next;
				delete tmp2;
				table[hash_del].size_t--;
			}
			else if (pos_del==1)
			{
				table[hash_del].start = table[hash_del].start->next;
				table[hash_del].start->prev = nullptr;
			}
		}
		else
		{
			cout << "Некорректная позиция\n";
		}
		break;
	default:
		cout << "\n";
	}
}
void add_del_o(int hash_size, human* table, int* arr_c)
{
	cout << "\n\n";
	human new_h;
	switch (choice())
	{
	case 1:
		cout << "Введите хэш-код по которому будет добавлен человек: ";
		new_h = set_human();
		int pos;
		cin >> pos;
		cout << "Будет добавлен  " << new_h.fio << "   " << new_h.phone << "   " << new_h.adress << endl;
		if (arr_c[pos] == 0 && pos < hash_size && pos >= 0)
		{
			table[pos] = new_h;
			arr_c[pos] = 1;
		}
		break;
	case 2:
		cout << "Введите хэш-код человека которого надо удалить: ";
		int pos1;
		cin >> pos1;
		if (arr_c[pos1] == 1 && pos1 < hash_size && pos1 >= 0)
		{
			arr_c[pos1] = 0;
		}
		break;
	default:
		cout << "\n";
	}
}
void list_method()
{
	int n;
	cout << "Введите количество человек: ";
	cin >> n;
	human* peoples = new human[n];
	for (int i = 0; i < n; i++)
	{
		peoples[i] = set_human();
	}

	int hash_size;
	cout << "Введите размер хэш таблицы: ";
	cin >> hash_size;

	list* table = new list[hash_size];
	for (int i = 0; i < hash_size; i++)
	{
		table[i].init();
	}
	for (int i = 0; i < n; i++)
	{
		human ph = peoples[i];
		int code = hash_fuction(ph.fio, hash_size);
		if (table[code].size_t >= 1) { collis++; }
		table[code].push_back(ph);
	}

	for (int i = 0; i < hash_size; i++)
	{
		cout << "Хэщ-код " << i << " Размер " << table[i].size_t << endl;
		table[i].print_tab();
	}
	cout << "\nКоллизий: " << collis << endl;

	long long int s_phone = set_search_phone();
	for (int i = 0; i < hash_size; i++)
	{
		list_elem* tmp = table[i].start;
		int counter = 1;
		while (tmp != nullptr)
		{
			if (tmp->data.phone == s_phone)
			{
				cout << "Человек найден по хэш-коду " << i << " На позиции " << counter << endl;
			}
			tmp = tmp->next;
			counter++;
		}
	}

	add_del_list(hash_size, table);
	for (int i = 0; i < hash_size; i++)
	{
		cout << "Хэщ-код " << i << " Размер " << table[i].size_t << endl;
		table[i].print_tab();
	}
}
void o_method()
{
	int n;
	cout << "Введите количество человек: ";
	cin >> n;
	human* peoples = new human[n];
	for (int i = 0; i < n; i++)
	{
		peoples[i] = set_human();
	}

	int hash_size;
	cout << "Введите размер хэш таблицы: ";
	cin >> hash_size;

	human* table = new human[hash_size];
	human* no_hash_people = new human[n];
	list not_hash;
	not_hash.init();
	int* count_arr = new int[hash_size];

	for (int i = 0; i < hash_size; i++) { count_arr[i] = 0; }
	for (int i = 0; i < n; i++)
	{
		bool hash_t = 1;
		human ph = peoples[i];
		int code = hash_fuction(ph.fio, hash_size);
		while (count_arr[code] != 0)
		{
			if (code == hash_size - 1)
			{
				no_hash_people[error_push] = ph;
				error_push++;
				hash_t = 0;
				break;
			}
			code++;
			collis++;
		}
		if (hash_t)
		{
			table[code] = ph;
			count_arr[code] = 1;
		}
	}
	for (int i = 0; i < hash_size; i++)
	{
		cout << "Хэш-код " << i << endl;
		if (count_arr[i] == 1)
		{
			cout << "\t" << table[i].fio << "   " << table[i].phone << "   " << table[i].adress << endl;
		}
	}

	cout << "\nКоллизий: " << collis;

	if (error_push > 0)
	{
		cout << "\nОшибок при хэшировании: " << error_push;
		cout << "\n\nЛюди не захешированные (будут преданы забвению)" << endl;
		for (int i = 0; i < error_push; i++)
		{
			cout << "\t" << no_hash_people[i].fio << "   " << no_hash_people[i].phone << "   " << no_hash_people[i].adress << endl;
		}
	}
	delete[] no_hash_people; //предаем забвению

	long long int s_phone = set_search_phone();
	for (int i = 0; i < hash_size; i++)
	{
		if (table[i].phone == s_phone)
		{
			cout << "Человек найден по хэш-коду " << i << endl;
		}
	}


	add_del_o(hash_size, table, count_arr);
	for (int i = 0; i < hash_size; i++)
	{
		cout << "Хэш-код " << i << endl;
		if (count_arr[i] == 1)
		{
			cout << "\t" << table[i].fio << "   " << table[i].phone << "   " << table[i].adress << endl;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "ru_RU");
	int end_if;
	cout << "Если хотите прекратить работу программы введите '1'   ";
	cin >> end_if;
	if (end_if == 1)
		return 0;
	
	cout << "\n1 - Метод списка\n2 - Метод переноса на O едениц\nВведите цифру соответствующую тому методу хегирование который будет использован, вводу любого другого значения соответсвует прекращению дальнейшего выполнения программы: ";
	int type_hash;
	cin >> type_hash;
	switch (type_hash)
	{
	case 1:
		list_method(); break;
	case 2:
		o_method(); break;
	default:
		cout << "хэширование не применяется\n";
	}

	system("pause");
	main();
}