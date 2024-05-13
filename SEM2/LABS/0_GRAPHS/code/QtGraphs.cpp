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
    for (Edge* edge : nodes_map[fromData]->edges_to_node) {
        if (edge->to == nodes_map[toData]) {
            return;
        }
    }

    Edge* newEdge = new Edge();
    newEdge->to = nodes_map[toData];
    newEdge->weight = weight;
    nodes_map[fromData]->edges_to_node.push_back(newEdge);
}
void Graph::clearGraph()
{
    // Удаление всех узлов
    for (auto& pair : nodes_map)
    {
        Node* node = pair.second;
        delete node;
    }

    // Очистка хэш-таблицы
    nodes_map.clear();
}

void Graph::updateEdgeWeight(int startData, int endData, int newWeight) {
    if (nodes_map.find(startData) == nodes_map.end() || nodes_map.find(endData) == nodes_map.end()) {
        // Один из узлов не существует
        return;
    }

    Node* startNode = nodes_map[startData];
    Node* endNode = nodes_map[endData];

    for (Edge* edge : startNode->edges_to_node) {
        if (edge->to == endNode) {
            edge->weight = newWeight;
            return;
        }
    }

    // Ребро не найдено
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
void Graph::BFS(int startData, vector<int>& bfs)
{
    queue<Node*> q;
    unordered_map<int, bool> visited;

    Node* startNode = nodes_map[startData];
    q.push(startNode);
    visited[startData] = true;

    while (!q.empty())
    {
        Node* currentNode = q.front();
        q.pop();

        bfs.push_back(currentNode->data);

        for (Edge* edge : currentNode->edges_to_node)
        {
            Node* neighborNode = edge->to;
            if (!visited[neighborNode->data])
            {
                visited[neighborNode->data] = true;
                q.push(neighborNode);
            }
        }
    }

    // Проверяем не посещенные узлы и запускаем для них обход в ширину
    for (const auto& pair : nodes_map)
    {
        Node* node = pair.second;
        if (!visited[node->data])
        {
            q.push(node);
            visited[node->data] = true;

            while (!q.empty())
            {
                Node* currentNode = q.front();
                q.pop();

                bfs.push_back(currentNode->data);

                for (Edge* edge : currentNode->edges_to_node)
                {
                    Node* neighborNode = edge->to;
                    if (!visited[neighborNode->data])
                    {
                        visited[neighborNode->data] = true;
                        q.push(neighborNode);
                    }
                }
            }
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
    unordered_map<int, int> dist;
    unordered_map<int, int> prev;
    vector<int> result;

    for (auto& pair : nodes_map)
    {
        dist[pair.first] = INT_MAX;
        prev[pair.first] = -1;
    }

    dist[startData] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, startData });

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (u == endData)
            break;

        for (Edge* edge : nodes_map[u]->edges_to_node)
        {
            int v = edge->to->data;
            int alt = dist[u] + edge->weight;

            if (alt < dist[v])
            {
                dist[v] = alt;
                prev[v] = u;
                pq.push({ alt, v });
            }
        }
    }

    // Восстановление пути
    for (int at = endData; at != -1; at = prev[at])
    {
        result.push_back(at);
    }
    reverse(result.begin(), result.end());

    if (result[0] == endData) { result.pop_back(); }
    return result;
}
QtGraphs::QtGraphs(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    /*QString imagePath = "og_og_145233582124948366.jpg";
    //QString imagePath = "C:/Users/bushm/Desktop/class/QtGraphs/QtGraphs/og_og_145233582124948366.jpg";
    // Создаем кнопку
    QPushButton* button = ui.pushButton_6;

    button->setStyleSheet("QPushButton {"
        "border-image: url(\"" + imagePath + "\");"
        "}");*/
    connect(ui.pushButton, &QPushButton::clicked, this, &QtGraphs::on_pushButton_clicked);
    connect(ui.pushButton_2, &QPushButton::clicked, this, &QtGraphs::on_pushButton_2_clicked);
    connect(ui.pushButton_4, &QPushButton::clicked, this, &QtGraphs::on_pushButton_3_clicked);
    connect(ui.pushButton_3, &QPushButton::clicked, this, &QtGraphs::on_pushButton_4_clicked);
    connect(ui.pushButton_5, &QPushButton::clicked, this, &QtGraphs::on_pushButton_5_clicked);
    connect(ui.pushButton_6, &QPushButton::clicked, this, &QtGraphs::on_pushButton_6_clicked);
    connect(ui.pushButton_7, &QPushButton::clicked, this, &QtGraphs::on_pushButton_7_clicked);
    connect(ui.pushButton_8, &QPushButton::clicked, this, &QtGraphs::on_pushButton_8_clicked);
    connect(ui.pushButton_9, &QPushButton::clicked, this, &QtGraphs::on_pushButton_9_clicked);
    connect(ui.pushButton_10, &QPushButton::clicked, this, &QtGraphs::on_pushButton_10_clicked);
    connect(ui.pushButton_11, &QPushButton::clicked, this, &QtGraphs::on_pushButton_11_clicked);
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
            double angles = atan2(-(edge->to->pos.y() - node->pos.y()), (edge->to->pos.x()-node->pos.x()));
            pos_f = QPoint(node->pos.x()+20*cos(angles), node->pos.y() - 20*sin(angles));
            pos_t = QPoint(edge->to->pos.x()- 20 * cos(angles), edge->to->pos.y() + 20*sin(angles));
            painter.drawLine(pos_f, pos_t);
            int x_t = pos_f.x() + 4 * (pos_t.x() - pos_f.x()) / 5;
            int y_t = pos_f.y() - 4 * (pos_f.y() - pos_t.y()) / 5;
            painter.drawText(x_t-10, y_t+10, QString::number(edge->weight));

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
        painter.drawText(node->pos.x() - 9, node->pos.y() + 8, QString::number(node->data));
    }
    if (sel) {
        painter.drawEllipse(100,100, 40, 40);
        painter.setBrush(Qt::green);
        painter.drawEllipse(sNode->pos, 20, 20);
        painter.drawText(sNode->pos.x() - 9, sNode->pos.y() + 8, QString::number(sNode->data));
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
    ui.textBrowser->clear();
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
        //ui.textBrowser->setText(resultString);

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
    ui.textBrowser_2->clear();
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
                resultString.append("->");
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

    }
}
void QtGraphs::on_pushButton_7_clicked()
{
    if (ui.lineEdit_11->text().isEmpty()) {
        return;
    }
    vector<int> dfsv;
    int s = ui.lineEdit_11->text().toInt();
    if (graph.nodes_map.find(s) != graph.nodes_map.end()) {
        graph.BFS(s, dfsv);
        QString resultString;
        for (int i = 0; i < dfsv.size(); i++) {
            resultString.append(QString::number(dfsv[i]));
            if (i < dfsv.size() - 1) {
                resultString.append(", ");
            }
        }
        //ui.textBrowser_2->setText(resultString);

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
                ui.textBrowser_3->setText(resultString);
                timer->stop();
                timer->deleteLater();
                sel = 0;
                ui.lineEdit_11->clear();
                update();
                idx = 0;
            }
            });
        timer->start(500);
    }
}
void QtGraphs::on_pushButton_8_clicked()
{
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);
    graph.addNode(6);
    graph.addEdge(1, 2, 4);
    graph.addEdge(1,5,8);
    graph.addEdge(5,3,12);
    graph.addEdge(3,5,12);
    graph.addEdge(5,2,23);
    graph.addEdge(2,4,9);
    graph.addEdge(4,6,11);
    graph.addEdge(2,3,15);
    graph.addEdge(3,2,15);
    graph.addEdge(6,3,6);
    update();
}
void QtGraphs::on_pushButton_9_clicked()
{
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);
    graph.addNode(6);
    graph.addNode(7);
    graph.addNode(8);
    graph.addNode(9);
    graph.addNode(10);
    graph.addEdge(1,2,8);
    graph.addEdge(2,3,9);
    graph.addEdge(3,2,6);
    graph.addEdge(1,4,9);
    graph.addEdge(4,5,3);
    graph.addEdge(4,3,12);
    graph.addEdge(1,6,10);
    graph.addEdge(6,7,16);
    graph.addEdge(7,5,16);
    graph.addEdge(8,9,1);
    graph.addEdge(9,8,2);
    graph.addEdge(5,7,89);
    graph.addEdge(4,1,5);
    graph.addNode(11);
    graph.addEdge(8, 11, 69);
    graph.addEdge(11, 9, 44);
    update();
}
void QtGraphs::on_pushButton_10_clicked()
{
    if (ui.lineEdit_12->text().isEmpty() or ui.lineEdit_13->text().isEmpty() or ui.lineEdit_14->text().isEmpty()) {
        return;
    }
    int s = ui.lineEdit_12->text().toInt();
    int t = ui.lineEdit_14->text().toInt();
    int w = ui.lineEdit_13->text().toInt();
    graph.updateEdgeWeight(s, t, w);
    ui.lineEdit_12->text().clear();
    ui.lineEdit_14->text().clear();
    ui.lineEdit_13->text().clear();
    update();
}
void QtGraphs::on_pushButton_11_clicked()
{
    graph.clearGraph();
    update();
}
