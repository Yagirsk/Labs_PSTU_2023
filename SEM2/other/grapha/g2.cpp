#include "QtGraphs.h"
#include <QPainter>
#include <vector>
#include <QLineEdit>
#include <QPushButton>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <chrono>
#include <thread>
#include <QTimer>
#include <queue>
#include <limits>
#include <random>
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
    // Óäàëåíèå âñåõ óçëîâ
    for (auto& pair : nodes_map)
    {
        Node* node = pair.second;
        delete node;
    }

    // Î÷èñòêà õýø-òàáëèöû
    nodes_map.clear();
}
void Graph::updateEdgeWeight(int startData, int endData, int newWeight) {
    if (nodes_map.find(startData) == nodes_map.end() || nodes_map.find(endData) == nodes_map.end()) {
        
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
}
void Graph::removeNode(int data)
{
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
                delete edge;
            }
        }
    }

    auto it = nodes_map.find(data);
    if (it != nodes_map.end())
    {
        delete it->second;
        nodes_map.erase(it);
    }
}
void Graph::removeEdge(int startData, int endData)
{
    auto startNodeIt = nodes_map.find(startData);
    auto endNodeIt = nodes_map.find(endData);

    if (startNodeIt == nodes_map.end() || endNodeIt == nodes_map.end())
    {
        return;
    }

    Node* startNode = startNodeIt->second;
    Node* endNode = endNodeIt->second;

    // Ïîèñê è óäàëåíèå ðåáðà ìåæäó óçëàìè
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
            delete edgeToRemove; // Îñâîáîæäåíèå ïàìÿòè
        }
    }
    else
    {
    }
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
            double angles = atan2(-(edge->to->pos.y() - node->pos.y()), (edge->to->pos.x() - node->pos.x()));
            pos_f = QPoint(node->pos.x() + 20 * cos(angles), node->pos.y() - 20 * sin(angles));
            pos_t = QPoint(edge->to->pos.x() - 20 * cos(angles), edge->to->pos.y() + 20 * sin(angles));
            painter.drawLine(pos_f, pos_t);
            int x_t = pos_f.x() + 4 * (pos_t.x() - pos_f.x()) / 5;
            int y_t = pos_f.y() - 4 * (pos_f.y() - pos_t.y()) / 5;
            painter.drawText(x_t - 10, y_t + 10, QString::number(edge->weight));

            QLine line(pos_f, pos_t);
            double angle = atan2(-line.dy(), line.dx()) - M_PI / 2;
            double arrowSize = 15;
            double arrowLength = 20;
            QPointF arrowP1 = pos_t + QPointF(sin(angle - M_PI / 10)* arrowSize, cos(angle - M_PI / 10) * arrowSize);
            QPointF arrowP2 = pos_t + QPointF(sin(angle + M_PI / 10) * arrowSize, cos(angle + M_PI / 10) * arrowSize);
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
        painter.drawEllipse(100, 100, 40, 40);
        painter.setBrush(Qt::green);
        painter.drawEllipse(sNode->pos, 20, 20);
        painter.drawText(sNode->pos.x() - 9, sNode->pos.y() + 8, QString::number(sNode->data));
    }
}
void QtGraphs::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        m_nodeSelected = false; // Ñáðîñ ôëàãà âûáðàííîãî óçëà
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

double Graph::pathCost(const vector<int>& path) {
    double cost = 0.0;
    for (size_t i = 0; i < path.size() - 1; ++i) {
        if (nodes_map[path[i]]->edges_to_node.size() > 0) {
            auto it = find_if(nodes_map[path[i]]->edges_to_node.begin(), nodes_map[path[i]]->edges_to_node.end(),
                [&](Edge* e) { return e->to->data == path[i + 1]; });
            if (it != nodes_map[path[i]]->edges_to_node.end()) {
                cost += (*it)->weight;
            }
            else {
                cost += numeric_limits<double>::max() / (path.size() - 1); // Назначаем максимально возможный вес, если путь невозможен
            }
        }
    }
    // Добавляем стоимость возвращения в начальный узел
    auto it = find_if(nodes_map[path.back()]->edges_to_node.begin(), nodes_map[path.back()]->edges_to_node.end(),
        [&](Edge* e) { return e->to->data == path[0]; });
    if (it != nodes_map[path.back()]->edges_to_node.end()) {
        cost += (*it)->weight;
    }
    else {
        cost += numeric_limits<double>::max() / (path.size() - 1); // Если возвращение невозможно
    }
    return cost;
}

void Graph::crossover(const vector<int>& parent1, const vector<int>& parent2, vector<int>& child) {
    // Простой одноточечный кроссовер
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, parent1.size() - 2);

    int crossoverPoint = dis(gen);

    unordered_set<int> included(parent1.begin(), parent1.begin() + crossoverPoint);
    child.clear();
    child.insert(child.end(), parent1.begin(), parent1.begin() + crossoverPoint);

    for (auto& city : parent2) {
        if (included.find(city) == included.end()) {
            child.push_back(city);
        }
    }
}

void Graph::mutate(vector<int>& path, double mutationRate, int startNode) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1);

    if (dis(gen) < mutationRate) {
        int swapIdx1 = uniform_int_distribution<>(1, path.size() - 1)(gen); // Исключаем начальный узел
        int swapIdx2 = uniform_int_distribution<>(1, path.size() - 1)(gen); // Исключаем начальный узел
        swap(path[swapIdx1], path[swapIdx2]);
    }
}

vector<int> Graph::solveTSPUsingGA(int startNode, int populationSize, int generations, double mutationRate) {
    random_device rd;
    mt19937 gen(rd());

    vector<vector<int>> population(populationSize);
    vector<int> bestPath;
    double bestCost = numeric_limits<double>::max();

    // Инициализация популяции с учетом начального узла
    vector<int> initialPath;
    for (auto& nodePair : nodes_map) {
        if (nodePair.first != startNode) { // Исключаем начальный узел из списка
            initialPath.push_back(nodePair.first);
        }
    }

    for (auto& path : population) {
        path = initialPath;
        shuffle(path.begin(), path.end(), gen);
        path.insert(path.begin(), startNode); // Добавляем начальный узел в начало каждого пути
    }

    for (int generation = 0; generation < generations; ++generation) {
        // Оценка
        for (auto& path : population) {
            double cost = pathCost(path);
            if (cost < bestCost) {
                bestCost = cost;
                bestPath = path;
            }
        }

        // Селекция и создание новой популяции
        vector<vector<int>> newPopulation;
        uniform_int_distribution<> dis(0, populationSize - 1);

        while (newPopulation.size() < populationSize) {
            const auto& parent1 = population[dis(gen)];
            const auto& parent2 = population[dis(gen)];

            vector<int> child;
            crossover(parent1, parent2, child); // Обновленная функция кроссовера
            mutate(child, mutationRate, startNode); // Обновленная функция мутации

            newPopulation.push_back(child);
        }

        population.swap(newPopulation);
    }

    return bestPath;
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
void QtGraphs::on_pushButton_8_clicked()
{
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);
    graph.addNode(6);
    graph.addEdge(1, 2, 4);
    graph.addEdge(1, 5, 8);
    graph.addEdge(5, 3, 12);
    graph.addEdge(3, 5, 12);
    graph.addEdge(5, 2, 23);
    graph.addEdge(2, 4, 9);
    graph.addEdge(4, 6, 11);
    graph.addEdge(2, 3, 15);
    graph.addEdge(3, 2, 15);
    graph.addEdge(6, 3, 6);
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
    graph.addEdge(1, 2, 8);
    graph.addEdge(2, 1, 8);
    graph.addEdge(2, 3, 12);
    graph.addEdge(3, 2, 12);
    graph.addEdge(3, 4, 16); 
    graph.addEdge(4, 3, 16);
    graph.addEdge(2, 5, 10);
    graph.addEdge(5, 2, 10);
    graph.addEdge(1, 6, 11);
    graph.addEdge(6, 1, 11);
    graph.addEdge(6, 4, 9);
    graph.addEdge(4, 6, 9);
    graph.addEdge(6, 5, 6);
    graph.addEdge(5, 6, 6);
    graph.addEdge(4, 5, 5);
    graph.addEdge(5, 4, 5);
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
void QtGraphs::on_pushButton_5_clicked()
{
    ui.textBrowser->clear();
    int s = ui.lineEdit_8->text().toInt();
    vector<int>shortestPath = graph.solveTSPUsingGA(s);
    QString resultString;
    for (int i = 0; i < shortestPath.size(); i++) {
        resultString.append(QString::number(shortestPath[i]));
        if (i < shortestPath.size() - 1) {
            resultString.append(", ");
        }
    }

    static int idx = 0;
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [=]() {
        if (shortestPath.size() != 0 and idx < shortestPath.size()) {
            Node* nod = graph.nodes_map[shortestPath[idx]];
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
