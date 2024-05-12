#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_QtARM.h"
#include <vector>
using namespace std;
struct Cargo
{
    string cn;
    int sht;
};
class human
{
public:
    string surname;
    string name;
    string patronymic;
    string pas_num ="";
    bool truck = 0;
    string vec_num;
    int do_waht = 0;

    bool vec_cantroband=0;
    vector<Cargo> cargos;
    vector<Cargo> cargos2;
    bool cargo_contraband = 0;

    string surname2;
    string name2;
    string patronymic2;
    string pas_num2 = "";
    string vec_num2;

    void new_human();
    void clear();

};

class QtARM : public QMainWindow
{
    Q_OBJECT

public:
    QtARM(QWidget *parent = nullptr);
    ~QtARM();
    human hu;
    void showa();
    void hidet();
    void showt();
private:
    Ui::QtARMClass ui;
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
};
