#pragma once
#include <QWidget>
#include <QMouseEvent>
#include <ui_QtGraphs.h>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;
class Edge;
class Node;
class Graph;
class Node //класс для узла графа
{
public:
    int data;
    vector<Edge*> edges_to_node;
    QPoint pos;
    Node()
    {
        pos = QPoint(400, 200);
    }
};
class Edge //класс для ребра графа
{
public:
    int weight;
    Node* to;
};
class Graph
{
public:
    unordered_map<int, Node*> nodes_map;


    void addNode(int data);//добавление узла с новым значением
    void addEdge(int fromData, int toData, int weight);//добавление ребра с весом, от заданного узла к другому заданному узлу
    void clearGraph();//очитка графа
    void updateEdgeWeight(int startData, int endData, int newWeight);//редактирование веса ребра, при отсутсвиии ребра ничего не проиходит
    void DFS(int startData, vector<int> &dfs);//обход в глубину, возвращает вектор в которм элементы идут в собраном порядке
    void BFS(int startData, vector<int>& bfs);//обход в ширину, возвращает вектор в которм элементы идут в собраном порядке
    void removeNode(int data);//удлаение узла по заданному значению
    void removeEdge(int startData, int endData);//удаление ребра от заданного узла до заданного узла
    vector<int> Dijkstra(int startData, int endData);//алгоритм Дейкстры ищущий кратчайший путь от узла к узлу, возвращает вектор который является путем, вектор пуст -> пути нет
};
class QtGraphs : public QMainWindow
{
    Q_OBJECT
public:
    QtGraphs(QWidget* parent = nullptr);
    ~QtGraphs();
    Graph graph;

protected:
    void paintEvent(QPaintEvent* event) override;//переопределние отрисовки
    void mousePressEvent(QMouseEvent* event) override;//переопределние событий мыши для возможности перемещать узлы графа
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;//переопределние событий мыши для возможности перемещать узлы графа, конец
    
private:
    Ui::QtGraphsClass ui;
    Node* m_selectedNode;
    bool m_nodeSelected;

    bool sel = 0;
    Node* sNode;

    void on_pushButton_clicked();//функции выполняемые при нажатии на соответствующие кнопки, начало
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();//функции выполняемые при нажатии на соответствующие кнопки, конец
};
