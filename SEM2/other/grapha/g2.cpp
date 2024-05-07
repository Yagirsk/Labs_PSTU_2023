#include "QtGraphs.h"
#include <QPainter>
#include <vector>
#include <QLineEdit>
#include <QPushButton>
#include <cmath>
#include <unordered_set>
#include <chrono>
#include <thread>
#include <QTimer>
#include <queue>
#include <limits>
//#include "QtWidgetsClass.h"
const double M_PI = 3.1415;
void Graph::addNode(int data) {
    if (nodes_map.find(data) == nodes_map.end()) {
        Node* newNode = new Node;
        newNode->data = data;
        nodes_map[data] = newNode;
    }
    else {
    }
}
void Graph::addEdge(int fromData, int toData, int weight) {
    Edge* newEdge = new Edge();
    newEdge->to = nodes_map[toData];
    newEdge->weight = weight;
    nodes_map[fromData]->edges_to_node.push_back(newEdge);
}
void Graph::DFS(int startData, vector<int>& dfs)
{
    stack<Node*> nodeStack;
    nodeStack.push(nodes_map[startData]);

    unordered_set<int> visited;
    visited.insert(startData);

    while (!nodeStack.empty())
    {
        Node* currentNode = nodeStack.top();
        nodeStack.pop();

        dfs.push_back(currentNode->data);

        for (Edge* edge : currentNode->edges_to_node)
        {
            if (visited.find(edge->to->data) == visited.end())
            {
                nodeStack.push(edge->to);
                visited.insert(edge->to->data);
            }
        }
    }

    for (auto const& pair : nodes_map)
    {
        if (visited.find(pair.first) == visited.end())
        {
            dfs.push_back(pair.first);
            visited.insert(pair.first);
        }
    }
}
void Graph::removeNode(int data)
{
    // Удаление всех ребер, ведущих к узлу с заданным значением
    for (auto& pair : nodes_map)
    {
        Node* node = pair.second;
        vector<Edge*> edges_to_remove;

        for (Edge* edge : node->edges_to_node)
        {
            if (edge->to->data == data)
            {
                edges_to_remove.push_back(edge);
            }
        }

        for (Edge* edge : edges_to_remove)
        {
            auto it = find(node->edges_to_node.begin(), node->edges_to_node.end(), edge);
            if (it != node->edges_to_node.end())
            {
                node->edges_to_node.erase(it);
                delete edge; // Освобождение памяти
            }
        }
    }

    // Удаление самого узла из nodes_map
    auto it = nodes_map.find(data);
    if (it != nodes_map.end())
    {
        delete it->second; // Освобождение памяти
        nodes_map.erase(it);
    }
}
void Graph::removeEdge(int startData, int endData)
{
    // Проверка наличия узлов с заданными значениями в графе
    auto startNodeIt = nodes_map.find(startData);
    auto endNodeIt = nodes_map.find(endData);

    if (startNodeIt == nodes_map.end() || endNodeIt == nodes_map.end())
    {
        return;
    }

    Node* startNode = startNodeIt->second;
    Node* endNode = endNodeIt->second;

    // Поиск и удаление ребра между узлами
    Edge* edgeToRemove = nullptr;

    for (Edge* edge : startNode->edges_to_node)
    {
        if (edge->to->data == endData)
        {
            edgeToRemove = edge;
            break;
        }
    }

    if (edgeToRemove)
    {
        auto it = find(startNode->edges_to_node.begin(), startNode->edges_to_node.end(), edgeToRemove);
        if (it != startNode->edges_to_node.end())
        {
            startNode->edges_to_node.erase(it);
            delete edgeToRemove; // Освобождение памяти
        }
    }
    else
    {
    }
}
vector<int> Graph::Dijkstra(int startData, int endData)
{
    std::priority_queue<std::pair<int, Node*>, std::vector<std::pair<int, Node*>>, std::greater<>> pq;

    Node* startNode = nodes_map[startData];
    startNode->distance = 0;

    pq.push({ 0, startNode });

    while (!pq.empty())
    {
        Node* current = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (current->distance == -1 || dist > current->distance) continue; // Пропускаем вершины без пути или уже обработанные

        for (Edge* edge : current->edges_to_node)
        {
            int newDist = dist + edge->weight;

            if (edge->to->distance == -1 || newDist < edge->to->distance)
            {
                edge->to->distance = newDist;
                edge->to->prev = current;
                pq.push({ newDist, edge->to });
            }
        }
    }

    // Формируем кратчайший путь, если он существует
    std::vector<int> shortestPath;
    if (nodes_map[endData]->distance != -1)
    {
        Node* endNode = nodes_map[endData];

        while (endNode != nullptr)
        {
            shortestPath.insert(shortestPath.begin(), endNode->data);
            endNode = endNode->prev;
        }
    }

    return shortestPath;
}
QtGraphs::QtGraphs(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    
    connect(ui.pushButton, &QPushButton::clicked, this, &QtGraphs::on_pushButton_clicked);
    connect(ui.pushButton_2, &QPushButton::clicked, this, &QtGraphs::on_pushButton_2_clicked);
    connect(ui.pushButton_4, &QPushButton::clicked, this, &QtGraphs::on_pushButton_3_clicked);
    connect(ui.pushButton_3, &QPushButton::clicked, this, &QtGraphs::on_pushButton_4_clicked);
    connect(ui.pushButton_5, &QPushButton::clicked, this, &QtGraphs::on_pushButton_5_clicked);
    connect(ui.pushButton_6, &QPushButton::clicked, this, &QtGraphs::on_pushButton_6_clicked);
}
QtGraphs::~QtGraphs()
{
}
void QtGraphs::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    QFont font = painter.font();
    font.setPointSize(16);
    painter.setFont(font);
    for (const auto& pair : graph.nodes_map) {
        Node* node = pair.second;
        for (Edge* edge : node->edges_to_node) {
            QPoint pos_f;
            QPoint pos_t;
            int d = 20 * sin(atan(1));
            if (edge->to->pos.x() - node->pos.x() == 0 and edge->to->pos.y() - node->pos.y() > 0)
            {
                pos_f = QPoint(node->pos.x(), node->pos.y() + 20);
                pos_t = QPoint(edge->to->pos.x(), edge->to->pos.y() - 20);
            }
            else if (edge->to->pos.x() - node->pos.x() == 0 and edge->to->pos.y() - node->pos.y() < 0)
            {
                pos_f = QPoint(node->pos.x(), node->pos.y() - 20);
                pos_t = QPoint(edge->to->pos.x(), edge->to->pos.y() + 20);
            }
            else if (edge->to->pos.x() - node->pos.x() > 0 and edge->to->pos.y() - node->pos.y() < 0)
            {
                pos_f = QPoint(node->pos.x() + d, node->pos.y() - d);
                pos_t = QPoint(edge->to->pos.x() - d, edge->to->pos.y() + d);
                
            }
            else if (edge->to->pos.x() - node->pos.x() < 0 and edge->to->pos.y() - node->pos.y() < 0)
            {
                pos_f = QPoint(node->pos.x() - d, node->pos.y() - d);
                pos_t = QPoint(edge->to->pos.x() + d, edge->to->pos.y() + d);
                
            }
            else if (edge->to->pos.x() - node->pos.x() < 0 and edge->to->pos.y() - node->pos.y() > 0)
            {
                pos_f = QPoint(node->pos.x() - d, node->pos.y() + d);
                pos_t = QPoint(edge->to->pos.x() + d, edge->to->pos.y() - d);
            }
            else if (edge->to->pos.x() - node->pos.x() > 0 and edge->to->pos.y() - node->pos.y() > 0)
            {
                pos_f = QPoint(node->pos.x() + d, node->pos.y() + d);
                pos_t = QPoint(edge->to->pos.x() - d, edge->to->pos.y() - d);
            }
            else if (edge->to->pos.x() - node->pos.x() > 0 and edge->to->pos.y() - node->pos.y() == 0)
            {
                pos_f = QPoint(node->pos.x() + 20, node->pos.y());
                pos_t = QPoint(edge->to->pos.x() - 20, edge->to->pos.y());
            }
            else if (edge->to->pos.x() - node->pos.x() < 0 and edge->to->pos.y() - node->pos.y() == 0)
            {
                pos_f = QPoint(node->pos.x() - 20, node->pos.y());
                pos_t = QPoint(edge->to->pos.x() + 20, edge->to->pos.y());
            }
            else
            {
                pos_f = node->pos;
                pos_t = edge->to->pos;
            }
            painter.drawLine(pos_f, pos_t);
            int x_t = pos_f.x() + 3 * (pos_t.x() - pos_f.x()) / 5;
            int y_t = pos_f.y() - 3 * (pos_f.y() - pos_t.y()) / 5;
            painter.drawText(x_t, y_t, QString::number(edge->weight));

            QLine line(pos_f, pos_t);
            double angle = atan2(-line.dy(), line.dx())-M_PI/2;
            double arrowSize = 15;
            double arrowLength = 20;
            QPointF arrowP1 = pos_t + QPointF(sin(angle - M_PI / 3) * arrowSize, cos(angle - M_PI / 3) * arrowSize);
            QPointF arrowP2 = pos_t + QPointF(sin(angle + M_PI / 3) * arrowSize, cos(angle + M_PI / 3) * arrowSize);
            QPolygonF arrowHead;
            arrowHead << pos_t << arrowP1 << arrowP2;
            painter.drawPolygon(arrowHead);
        }
    }

    for (const auto& pair : graph.nodes_map) {
        Node* node = pair.second;
        painter.drawEllipse(node->pos, 20, 20);
        painter.drawText(node->pos.x() - 7, node->pos.y() + 7, QString::number(node->data));
    }
    if (sel) {
        painter.drawEllipse(100,100, 40, 40);
        painter.setBrush(Qt::green);
        painter.drawEllipse(sNode->pos, 20, 20);
        painter.drawText(sNode->pos.x() - 7, sNode->pos.y() + 7, QString::number(sNode->data));
    }
}
void QtGraphs::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        m_nodeSelected = false; // Сброс флага выбранного узла
        for (const auto& pair : graph.nodes_map) {
            Node* node = pair.second;
            if ((event->pos() - node->pos).manhattanLength() < 30) {
                m_selectedNode = node;
                m_nodeSelected = true;
                break;
            }
        }
        update();
    }
}
void QtGraphs::mouseMoveEvent(QMouseEvent* event)
{
    if (m_nodeSelected && m_selectedNode) {
        m_selectedNode->pos = event->pos();
        update();
    }
}
void QtGraphs::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton && m_nodeSelected) {
        m_nodeSelected = false;
        m_selectedNode = nullptr;
        update();
    }
}
void QtGraphs::on_pushButton_clicked() {
    QString text = ui.lineEdit->text();
    if (text.isEmpty()) {
        return;
    }

    int nodeValue = text.toInt();
    graph.addNode(nodeValue);
    ui.lineEdit->clear();
    update();
}
void QtGraphs::on_pushButton_2_clicked() {
    if (ui.lineEdit_2->text().isEmpty() or ui.lineEdit_3->text().isEmpty() or ui.lineEdit_4->text().isEmpty()) {
        return;
    }
    int fromNode = ui.lineEdit_2->text().toInt();
    int toNode = ui.lineEdit_3->text().toInt();
    int weight = ui.lineEdit_4->text().toInt();
    if (graph.nodes_map.find(fromNode) != graph.nodes_map.end() && graph.nodes_map.find(toNode) != graph.nodes_map.end()) {
        graph.addEdge(fromNode, toNode, weight);
        ui.lineEdit_2->clear();
        ui.lineEdit_4->clear();
        ui.lineEdit_3->clear();
        update();
    }
    else {
    }
}
void QtGraphs::on_pushButton_3_clicked()
{
    if (ui.lineEdit_5->text().isEmpty()) {
        return;
    }
    int del = ui.lineEdit_5->text().toInt();
    graph.removeNode(del);
    ui.lineEdit_5->clear();
    update();
}
void QtGraphs::on_pushButton_4_clicked()
{
    if (ui.lineEdit_7->text().isEmpty() or ui.lineEdit_6->text().isEmpty()) {
        return;
    }
    int s = ui.lineEdit_7->text().toInt();
    int f = ui.lineEdit_6->text().toInt();
    graph.removeEdge(s, f);
    ui.lineEdit_7->clear();
    ui.lineEdit_6->clear();
    update();
}
void QtGraphs::on_pushButton_5_clicked()
{
    if (ui.lineEdit_8->text().isEmpty()) {
        return;
    }
    vector<int> dfsv;
    int s = ui.lineEdit_8->text().toInt();
    if (graph.nodes_map.find(s) != graph.nodes_map.end()) {
        graph.DFS(s, dfsv);
        QString resultString;
        for (int i = 0; i < dfsv.size(); i++) {
            resultString.append(QString::number(dfsv[i]));
            if (i < dfsv.size() - 1) {
                resultString.append(", ");
            }
        }
        ui.textBrowser->setText(resultString);

        static int idx = 0;
        QTimer* timer = new QTimer(this);
        connect(timer, &QTimer::timeout, [=]() {
            if (dfsv.size() != 0 and idx < dfsv.size()) {
                Node* nod = graph.nodes_map[dfsv[idx]];
                sNode = nod;
                sel = 1;
                update();
                idx++;
            }
            else {
                ui.textBrowser->setText(resultString);
                timer->stop();
                timer->deleteLater();
                sel = 0;
                ui.lineEdit_8->clear();
                update();
                idx = 0;
            }
            });
        timer->start(500);
    }
}
void QtGraphs::on_pushButton_6_clicked()
{
    if (ui.lineEdit_9->text().isEmpty() or ui.lineEdit_9->text().isEmpty()) {
        return;
    }
    
    int s = ui.lineEdit_9->text().toInt();
    int f = ui.lineEdit_10->text().toInt();
    if (graph.nodes_map.find(s) != graph.nodes_map.end() and graph.nodes_map.find(f) != graph.nodes_map.end()) {
        vector<int> di = graph.Dijkstra(s,f);
        QString resultString;
        for (int i = 0; i < di.size(); i++) {
            resultString.append(QString::number(di[i]));
            if (i < di.size() - 1) {
                resultString.append(", ");
            }
        }
        

        static int idx = 0;
        QTimer* timer = new QTimer(this);
        connect(timer, &QTimer::timeout, [=]() {
            if (di.size() != 0 and idx < di.size()) {
                Node* nod = graph.nodes_map[di[idx]];
                sNode = nod;
                sel = 1;
                update();
                idx++;
            }
            else {
                ui.textBrowser_2->setText(resultString);
                timer->stop();
                timer->deleteLater();
                sel = 0;
                ui.lineEdit_9->clear();
                ui.lineEdit_10->clear();
                update();
                idx = 0;
            }
            });
        timer->start(500);

        static bool ara_ara = 0;
        QTimer* timer2 = new QTimer(this);
        connect(timer2, &QTimer::timeout, [=]() {
            if (ara_ara)
            {
                timer2->stop();
                timer2->deleteLater();
            }
            else {
                ara_ara = 1;
            }
            });
        timer2->start(3000);
    }
}
