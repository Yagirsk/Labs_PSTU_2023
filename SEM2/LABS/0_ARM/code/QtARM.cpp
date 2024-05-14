
#include "QtARM.h"
#include <cstdlib>
#include <ctime>
using namespace std;
int dosmotr = 0;
int ver_d = 0;
const char pass_char[17] = { 'A','B' ,'C' ,'X' ,'P' ,'1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7','8','9','0','W','Q' };
const char num_bukv[7] = { 'A' ,'B' ,'C' ,'D' ,'E' ,'W' ,'K' };
vector<string> cargo = { "Мешок", "Бочка","Ящик" };
bool c_dos = 0, ca_dos = 0;
string surnames[30] = {
        "Иванов", "Петров", "Смирнов", "Соколов", "Кузнецов", "Попов", "Лебедев", "Козлов", "Новиков", "Морозов",
        "Волков", "Зайцев", "Павлов", "Семенов", "Голубев", "Виноградов", "Богданов", "Воробьев", "Федоров", "Макаров",
        "Андреев", "Козлов", "Ильин", "Степанов", "Сорокин", "Михайлов", "Калинин", "Герасимов", "Алексеев", "Лазарев"
};
string names[30] = {
        "Иван", "Петр", "Александр", "Дмитрий", "Андрей",
        "Сергей", "Михаил", "Юрий", "Николай", "Артем",
        "Егор", "Илья", "Владимир", "Олег", "Григорий",
        "Василий", "Степан", "Кирилл", "Тимофей", "Максим",
        "Даниил", "Антон", "Павел", "Федор", "Виктор",
        "Роман", "Глеб", "Ярослав", "Борислав", "Лев"
};
string patronymics[30] = {
        "Александрович",
        "Иванович",
        "Дмитриевич",
        "Сергеевич",
        "Андреевич",
        "Михайлович",
        "Николаевич",
        "Владимирович",
        "Артемович",
        "Алексеевич",
        "Павлович",
        "Егорович",
        "Константинович",
        "Григорьевич",
        "Васильевич",
        "Юрьевич",
        "Олегович",
        "Игоревич",
        "Викторович",
        "Романович",
        "Денисович",
        "Тимурович",
        "Борисович",
        "Евгеньевич",
        "Леонидович",
        "Станиславович",
        "Валентинович",
        "Федорович",
        "Геннадьевич",
        "Степанович"
};
QString co_inf = "";
void human::new_human()
{
    srand(time(0));
    int tp = abs(rand()) % 5;
    int a = abs(rand()) % 30;
    name = name2= names[a];
    a = abs(rand()) % 30;
    surname = surname2= surnames[a];
    a = abs(rand()) % 30;
    patronymic = patronymic2= patronymics[a];
    vec_num = vec_num2= num_bukv[abs(rand() % 7)] + to_string(abs(rand() % 1000)) + num_bukv[abs(rand() % 7)] + num_bukv[abs(rand() % 7)];
    for (int i = 0; i < 8; i++)
    {
        pas_num += num_bukv[abs(rand() % 7)];
    }
    pas_num2 = pas_num;
    if (tp < 2)//truck
    {
        truck = true;
        int cargo_kol = 1 + abs(rand() % 3);
        for (int i = 0; i < cargo_kol; i++)
        {
            Cargo newCargo;
            int cargo_type = abs(rand() % 3);

            // Проверка на уникальность груза
            while (std::find_if(cargos.begin(), cargos.end(), [&cargo_type](const Cargo& c) { return c.cn == cargo[cargo_type]; }) != cargos.end())
            {
                cargo_type = abs(rand() % 3);
            }

            newCargo.cn = cargo[cargo_type];
            newCargo.sht = 1 + abs(rand() % 5);

            cargos.push_back(newCargo);
            cargos2.push_back(newCargo);
        }
    }

    if (abs(rand() % 2) == 0)
    {
        int change_type = abs(rand() % 6);
        switch (change_type)
        {
        case 0:
        {
            string new_name;
            do {
                int a = abs(rand()) % 30;
                new_name = names[a];
            } while (new_name == name);
            name2 = new_name;
            do_waht = 1;
            break;
        }
        case 1:
        {
            string new_surname;
            do {
                int a = abs(rand()) % 30;
                new_surname = surnames[a];
            } while (new_surname == surname);
            surname2 = new_surname;
            do_waht = 1;
            break;
        }
        case 2:
        {
            string new_patronymic;
            do {
                int a = abs(rand()) % 30;
                new_patronymic = patronymics[a];
            } while (new_patronymic == patronymic);
            patronymic2 = new_patronymic;
            do_waht = 1;
            break;
        }
        case 3:
        {
            string new_num = vec_num;
            do {
                new_num = num_bukv[abs(rand() % 7)] + to_string(abs(rand() % 1000)) + num_bukv[abs(rand() % 7)] + num_bukv[abs(rand() % 7)];
            } while (new_num == vec_num);
            vec_num2 = new_num;
            do_waht = 1;
            break;
        }
        case 4:
        {
            string new_pas_num = pas_num;
            do {
                new_pas_num = "";
                for (int i = 0; i < 8; i++)
                {
                    new_pas_num += num_bukv[abs(rand() % 7)];
                }
            } while (new_pas_num == pas_num);
            pas_num2 = new_pas_num;
            do_waht = 1;
            break;
        }
        case 5:
        {
            if (truck)
            {
                vector<Cargo> new_cargos;
                int cargo_kol = 1 + abs(rand() % 3);
                for (int i = 0; i < cargo_kol; i++)
                {
                    Cargo newCargo;
                    int cargo_type = abs(rand() % 3);

                    // Проверка на уникальность груза
                    do {
                        cargo_type = abs(rand() % 3);
                    } while (std::find_if(new_cargos.begin(), new_cargos.end(), [&cargo_type](const Cargo& c) { return c.cn == cargo[cargo_type]; }) != new_cargos.end());

                    newCargo.cn = cargo[cargo_type];
                    newCargo.sht = 1 + abs(rand() % 5);
                    do_waht = 1;
                    new_cargos.push_back(newCargo);
                }

                cargos2 = new_cargos;
            }
            break;
        }
        default:
            break;
        }
        
    }

    if (abs(rand() % 5) >=1)
    {
        int ttt = (abs(rand() % 2));
        if (ttt == 0)
        {
            vec_cantroband = 1;
            do_waht = 2;
        }
        else if (ttt == 1 and truck)
        {
            cargo_contraband = 1;
            do_waht = 2;
        }
        
    }
}
void human::clear()
{
    surname.clear();
    name.clear();
    patronymic.clear();
    pas_num.clear();
    truck = false;
    vec_num.clear();
    do_waht = 0;

    vec_cantroband = false;
    cargos.clear();
    cargos2.clear();
    cargo_contraband = false;

    surname2.clear();
    name2.clear();
    patronymic2.clear();
    pas_num2.clear();
    vec_num2.clear();
}
QtARM::QtARM(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.go_to->setStyleSheet("background-color: green;");
    ui.arrest->setStyleSheet("background-color: red;");

    hu.new_human();
    showa();
    
    connect(ui.pushButton, &QPushButton::clicked, this, &QtARM::on_pushButton_clicked);
    connect(ui.pushButton_2, &QPushButton::clicked, this, &QtARM::on_pushButton_2_clicked);
    connect(ui.pushButton_3, &QPushButton::clicked, this, &QtARM::on_pushButton_3_clicked);
    connect(ui.arrest, &QPushButton::clicked, this, &QtARM::on_pushButton_4_clicked);
    connect(ui.go_to, &QPushButton::clicked, this, &QtARM::on_pushButton_5_clicked);
    connect(ui.razvorot, &QPushButton::clicked, this, &QtARM::on_pushButton_6_clicked);
}
QtARM::~QtARM()
{
}
void QtARM::hidet()
{
    ui.pushButton->hide();
    ui.pushButton_3->hide();
    ui.label_15->hide();
    ui.label_16->hide();
    ui.textBrowser_4->hide();
    ui.textBrowser_5->hide();
    ui.textBrowser_6->hide();
    ui.textBrowser_7->hide();
}
void QtARM::showt()
{
    ui.pushButton->show();
    ui.pushButton_3->show();
    ui.label_15->show();
    ui.label_16->show();
    ui.textBrowser_4->show();
    ui.textBrowser_5->show();
    ui.textBrowser_6->show();
    ui.textBrowser_7->show();
}
void QtARM::showa()
{
    QString inf = QString::fromLocal8Bit("Досмотров ") + QString::number(dosmotr) + QString::fromLocal8Bit("\nВерных досмотров ") + QString::number(ver_d);
    ui.textBrowser_9->append(inf);

    ui.passport_surname->setText(QString::fromLocal8Bit(hu.surname.c_str()));
    ui.passport_name->setText(QString::fromLocal8Bit(hu.name.c_str()));
    ui.passport_patronymic->setText(QString::fromLocal8Bit(hu.patronymic.c_str()));
    ui.passport_num->setText(QString::fromLocal8Bit(hu.pas_num.c_str()));
    ui.passport_surname_2->setText(QString::fromLocal8Bit(hu.surname2.c_str()));
    ui.passport_name_2->setText(QString::fromLocal8Bit(hu.name2.c_str()));
    ui.passport_patronymic_2->setText(QString::fromLocal8Bit(hu.patronymic2.c_str()));
    ui.passport_carnum_2->setText(QString::fromLocal8Bit(hu.vec_num.c_str()));
    ui.vechile_num->setText(QString::fromLocal8Bit(hu.vec_num2.c_str()));
    ui.passport_num_2->setText(QString::fromLocal8Bit(hu.pas_num2.c_str()));
    if (hu.truck)
    {
        ui.textBrowser_5->clear();
        ui.car_type->setText(QString::fromLocal8Bit("Грузовик"));
        for (const Cargo& cargo : hu.cargos)
        {
            QString cargoInfo = QString::fromLocal8Bit(cargo.cn.c_str()) + " " + QString::number(cargo.sht) + QString::fromLocal8Bit(" шт.\n");
            ui.textBrowser_5->append(cargoInfo);
        }
        showt();
    }
    else {
        int ttk = rand() % 3;
        string strh;
        switch (ttk)
        {
        case(0):
            strh = "Седан";
            break;
        case(1):
            strh = "Внедорожник";
            break;
        case(2):
            strh = "Пикап";
            break;
        default:
            break;
        }
        ui.car_type->setText(QString::fromLocal8Bit(strh.c_str()));
        hidet();
    }
}
void QtARM::on_pushButton_clicked() {
    for (const Cargo& cargose : hu.cargos2)
    {
        QString cargoInfos = QString::fromLocal8Bit(cargose.cn.c_str()) + " " + QString::number(cargose.sht) + QString::fromLocal8Bit(" шт.\n");
        ui.textBrowser_6->append(cargoInfos);
    }
}
void QtARM::on_pushButton_2_clicked() {
    if (hu.vec_cantroband and !ca_dos) {
        ca_dos = 1;
        co_inf +=QString::fromLocal8Bit("Найдена контрабанда в ТС\n");
    }
    else if(!ca_dos) {
        ca_dos = 1;
        co_inf += QString::fromLocal8Bit("Контрабанда в ТС не обнаружена\n");
    }
    ui.textBrowser_8->clear();
    ui.textBrowser_8->append(co_inf);
}
void QtARM::on_pushButton_3_clicked() {
    if (hu.cargo_contraband and !c_dos) {
        c_dos = 1;
        co_inf += QString::fromLocal8Bit("Найдена контрабанда в грузе\n");
    }
    else if(!c_dos) {
        c_dos = 1;
        co_inf += QString::fromLocal8Bit("Контрабанда в грузе не обнаружена\n");
    }
    ui.textBrowser_8->clear();
    ui.textBrowser_8->append(co_inf);
}
void QtARM::on_pushButton_4_clicked() {
    if (hu.do_waht == 2) { ver_d++; }
    hu.clear();
    hu.new_human();
    dosmotr++;
    co_inf = "";
    ui.textBrowser_9->clear();
    ui.textBrowser_8->clear();
    ui.textBrowser_5->clear();
    ui.textBrowser_6->clear();
    c_dos = ca_dos = 0;
    showa();
}
void QtARM::on_pushButton_5_clicked() {
    if (hu.do_waht == 0) { ver_d++; }
    hu.clear();
    hu.new_human();
    dosmotr++;
    co_inf = "";
    ui.textBrowser_9->clear();
    ui.textBrowser_8->clear();
    ui.textBrowser_5->clear();
    ui.textBrowser_6->clear();
    c_dos = ca_dos = 0;
    showa();
}
void QtARM::on_pushButton_6_clicked() {
    if (hu.do_waht == 1) { ver_d++; }
    hu.clear();
    hu.new_human();
    dosmotr++;
    co_inf = "";
    ui.textBrowser_9->clear();
    ui.textBrowser_8->clear();
    ui.textBrowser_5->clear();
    ui.textBrowser_6->clear();
    c_dos = ca_dos = 0;
    showa();
}
