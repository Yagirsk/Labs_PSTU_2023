#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;
size_t HashFuction(const string& fio, size_t M)
{
    size_t sum = 0;
    for (int i = 0; i < fio.length(); i++)
    {
        sum += (unsigned int)fio[i];
    }
    sum = sum % M;
    return sum;
}
struct Person
{
    string fio;
    long long int passport_num;
    long long int phone;
};
struct HashTable //тип данных, в котором хранится хеш-код и список с информацией о людях типа Person
{
    list<Person> information;
};
Person* set_people(int n)
{
    string fioStr;
    int a = 0;
    Person* people = new Person[n];

    string surname[10] = { "Иванов", "Сидоров", "Петров", "Петухов", "Байбурин", "Андреев", "Кузнецов", "Богатырев", "Печкин", "Саночкин" };
    string name[10] = { "Иван", "Петр", "Сидор", "Никола", "Илон", "Альберт", "Исаак", "Роберт", "Андрей", "Иосиф" };
    string patronymics[10] = { "Иванович","Петрович","Сидорович","Николаевич","Илонович","Альбертович","Исаакович","Робертович","Маркович","Иосифович" };

    for (int i = 0; i < n; i++)
    {
        fioStr.clear();
        a = rand() % 10;
        fioStr += surname[a] + ' ';
        a = rand() % 10;
        fioStr += name[a] + ' ';
        a = rand() % 10;
        fioStr += patronymics[a];

        people[i].fio = fioStr;

        people[i].passport_num = rand()%10000000;

        people[i].phone = 80000000000+rand()%10000000000;
    }
    return people;
}
HashTable* setHashTable(int size, Person* people, int n)
{
    HashTable* HT = new HashTable[size];
    int cod = 0;
    for (int i = 0; i < n; i++)
    {
        cod = HashFuction(people[i].fio, size);

        HT[cod].information.push_back(people[i]);
    }
    return HT;
}
void print_hash_table(HashTable* HT, int size)
{
    cout << "\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Хеш-код " << i << ", размер списка " << HT[i].information.size() << ":\n";
        for (list<Person>::iterator j = HT[i].information.begin(); j != HT[i].information.end(); j++)
        {
            cout << '\t' << j->fio << " " << j->passport_num << " " << j->phone << endl;
        }
    }
    cout << "\n\n";
}
HashTable* reHash(HashTable* table, int sizeTable, int n)
{
    Person* tmp_people = new Person[n];
    int count = 0;
    for (int i = 0; i < sizeTable; i++)
    {
        for (list<Person>::iterator j = table[i].information.begin(); j != table[i].information.end(); ++j)
        {
            tmp_people[count].fio = j->fio;
            tmp_people[count].passport_num = j->passport_num;
            tmp_people[count].phone = j->phone;
            count++;
        }
    }

    delete[] table;
    HashTable* table2 = new HashTable[n];
    int cod = 0;
    for (int i = 0; i < n; i++)
    {
        cod = HashFuction(tmp_people[i].fio, n);
        if (table2[cod].information.size() > 0)
        {
            int j = 0;
            while (table2[j].information.size() >= 1)
            {
                j++;
            }
            table2[j].information.push_back(tmp_people[i]);
        }
        else
        {
            table2[cod].information.push_back(tmp_people[i]);
        }
    }
    delete[] tmp_people;
    return table2;
}
void count_coolusion(HashTable* table, int sizeTable)
{
    int kolv_collusion = 0;
    for (int i = 0; i < sizeTable; i++)
    {
        if (table[i].information.size() > 1)
        {
            kolv_collusion += table[i].information.size() - 1;
        }
    }
    cout << "Количество коллизий: " << kolv_collusion << "\n\n\n";
}
void search_people(HashTable* table, int sizeTable)
{
    string fioStr;
    string surname[10] = { "Иванов", "Сидоров", "Петров", "Петухов", "Байбурин", "Андреев", "Кузнецов", "Богатырев", "Печкин", "Саночкин" };
    string name[10] = { "Иван", "Петр", "Сидор", "Никола", "Илон", "Альберт", "Исаак", "Роберт", "Андрей", "Иосиф" };
    string patronymics[10] = { "Иванович","Петрович","Сидорович","Николаевич","Илонович","Альбертович","Исаакович","Робертович","Маркович","Иосифович" };
    cout << "\n\n" << "Фамилии: " << "1 - Иванов, 2 - Сидоров, 3 - Петров, 4 - Петухов, 5 - Байбурин, 6 - Андреев, 7 - Кузнецов, 8 - Богатырев, 9 - Печкин, 10 - Саночкин\n";
    cout << "Имена: " << "1 - Иван, 2 - Петр, 3 - Сидор, 4 - Никола, 5 - Илон, 6 - Альберт, 7 - Исаак, 8 - Роберт, 9 - Андрей, 10 - Иосиф\n";
    cout << "Отчества: " << "1 - Иванович, 2 - Петрович, 3 - Сидорович, 4 - Николаевич, 5 - Илонович, 6 - Альбертович, 7 - Исаакович, 8 - Робертович, 9 - Маркович, 10 - Иосифович\n";

    cout << "Введите цифры соответствующие Фамилии Имени и Отчеству человека которого надо найти: ";
    int a, b, c;
    cin >> a >> b >> c;
    fioStr += surname[a - 1] + ' ';
    fioStr += name[b - 1] + ' ';
    fioStr += patronymics[c - 1];
    cout << "Ищем человека: " << fioStr << endl << endl;
    bool search = 0;

    for (int i = 0; i < sizeTable; i++)
    {
        int count = 1;
        for (list<Person>::iterator j = table[i].information.begin(); j != table[i].information.end(); j++)
        {
            if (j->fio == fioStr)
            {
                cout << "Человек найден по хэш-коду " << i << " и находится на позиции " << count << endl;
                search = 1;
            }
            count++;
        }
    }
    if (!search)
    {
        cout << "Человек не найден" << endl;
    }
}
void add_elem(HashTable* table, int sizeTable)
{
    int n1, n2, a = 0;
    cout << "Введите хэш-номер и позицию в списке элмента который будет добавлен: ";
    cin >> n1 >> n2;

    Person new_peop;
    string surname[10] = { "Иванов", "Сидоров", "Петров", "Петухов", "Байбурин", "Андреев", "Кузнецов", "Богатырев", "Печкин", "Саночкин" };
    string name[10] = { "Иван", "Петр", "Сидор", "Никола", "Илон", "Альберт", "Исаак", "Роберт", "Андрей", "Иосиф" };
    string patronymics[10] = { "Иванович","Петрович","Сидорович","Николаевич","Илонович","Альбертович","Исаакович","Робертович","Маркович","Иосифович" };
    string fioStr;

    a = rand() % 10;
    fioStr += surname[a] + ' ';
    a = rand() % 10;
    fioStr += name[a] + ' ';
    a = rand() % 10;
    fioStr += patronymics[a];
    new_peop.fio = fioStr;
    new_peop.passport_num = rand() % 10000000;
    new_peop.phone = 80000000000 + rand() % 10000000000;
    cout << "Будет добавлен: " << new_peop.fio << " " << new_peop.passport_num << " " << new_peop.phone << endl;
    if (n1 < sizeTable && n1 >= 0 && n2 <= table[n1].information.size()+1 && n2 > 0)
    {
        if (n2 == table[n1].information.size() + 1) { table[n1].information.push_back(new_peop); }
        else
        {
            list<Person>::iterator it = table[n1].information.begin();
            advance(it, n2 - 1);
            table[n1].information.insert(it, new_peop);
        }
    }
    else
    {
        cout << "Некорректныая позиция\n";
    }
}
void del_elem(HashTable* table, int sizeTable)
{
    int n1, n2;
    cout << "Введите хэш-номер и позицию в списке элмента который надо удалить соответственно: ";
    cin >> n1 >> n2;
    if (n1 < sizeTable && n1 >= 0 && n2 <= table[n1].information.size() && n2 > 0)
    {
        int tmp_size = table[n1].information.size();
        Person* tmp_people = new Person[table[n1].information.size()];
        int count = 0;
        for (int i = 0; i < tmp_size; i++)
        {
            list<Person>::iterator j = table[n1].information.begin();
            tmp_people[count].fio = j->fio;
            tmp_people[count].passport_num = j->passport_num;
            tmp_people[count].phone = j->phone;
            count++;
            table[n1].information.pop_front();
        }
        for (int i = 0; i < tmp_size; i++)
        {
            if (i != n2 - 1)
            {
                table[n1].information.push_back(tmp_people[i]);
            }
        }
        delete[] tmp_people;
    }
    else
    {
        cout << "Некорректныая позиция\n";
    }
}
int nemu_add_del()
{
    cout << "1 - добавить элемент в хэш-таблицу\n2 - удалить элемент из хэш-таблицы\nВведите цифру соответствующую тому какое действие сделать, если не хотите делать что-либо введите любое другое значение: ";
    int n;
    cin >> n;
    return n;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int end_rec;
    cout << "Если хотите прекратить работу программы введите '0' если нет, введите что-либо другое ";
    cin >> end_rec;
    if (end_rec == 0)
    {
        return 0;
    }

    Person person1;
    list<Person>::iterator j;
    int n, sizeTable = 0;
    cout << "Введите число записей: ";
    cin >> n;

    cout << "\n";
    Person* people = set_people(n);
    for (int i = 0; i < n; i++)
    {
        cout << people[i].fio << " " << people[i].passport_num << " " << people[i].phone << endl;
    }

    cout << "\n\n\nВведите размер таблицы: ";
    cin >> sizeTable;
    HashTable* table = setHashTable(sizeTable, people, n);
    print_hash_table(table, sizeTable);


    switch (nemu_add_del())
    {
    case 1:
        add_elem(table, sizeTable); cout << endl; n++; break;
    case 2:
        del_elem(table, sizeTable); cout << endl; break;
    default:
        cout << endl;
    }
    cout << "\n";
    print_hash_table(table, sizeTable);


    search_people(table, sizeTable);
    cout << "\n\n";

    count_coolusion(table, sizeTable);
    cout << "\n";


    table = reHash(table, sizeTable, n);
    cout << "Рехэшированная таблица\n";
    sizeTable = n;
    print_hash_table(table, sizeTable);


    delete[] table;
    delete[] people;

    system("pause");
    main();
    return 0;
}