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
class Node
{
public:
    int data;
    vector<Edge*> edges_to_node;
    QPoint pos;
    int distance;
    Node* prev;
    Node()
    {
        pos = QPoint(400, 200);
        distance = -1;
        prev = nullptr;
    }
};
class Edge
{
public:
    int weight;
    Node* to;
    bool isDirected;
};
class Graph
{
public:
    unordered_map<int, Node*> nodes_map;

    void addNode(int data);
    void addEdge(int fromData, int toData, int weight);
    void DFS(int startData, vector<int> &dfs);
    void removeNode(int data);
    void removeEdge(int startData, int endData);
    vector<int> Dijkstra(int startData, int endData);
};
class QtGraphs : public QMainWindow
{
    Q_OBJECT
public:
    QtGraphs(QWidget* parent = nullptr);
    ~QtGraphs();
    Graph graph;

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    
private:
    Ui::QtGraphsClass ui;
    Node* m_selectedNode;
    bool m_nodeSelected;

    bool sel = 0;
    Node* sNode;

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
};
