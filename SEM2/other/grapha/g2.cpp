#include "QtGraphs.h"
#include <QPainter>
#include <vector>
#include <QLineEdit>
#include <QPushButton>
#include <cmath>
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
void Graph::DFS(int startData, vector<int> dfs)
{
    stack<Node*> nodeStack;
    vector<Node*> visited;

    nodeStack.push(nodes_map[startData]);

    while (!nodeStack.empty())
    {
        Node* currentNode = nodeStack.top();
        nodeStack.pop();

        if (find(visited.begin(), visited.end(), currentNode) == visited.end())
        {
            dfs.push_back(currentNode->data);
            visited.push_back(currentNode);
            for (Edge* edge : currentNode->edges_to_node)
            {
                nodeStack.push(edge->to);
            }
        }
    }
}
QtGraphs::QtGraphs(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    m_circleCenter = QPoint(400, 200);
    m_circlePressed = false;
    
    connect(ui.pushButton, &QPushButton::clicked, this, &QtGraphs::on_pushButton_clicked);
    connect(ui.pushButton_2, &QPushButton::clicked, this, &QtGraphs::on_pushButton_2_clicked);
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
                pos_f = QPoint(node->pos.x()+d, node->pos.y()-d);
                pos_t = QPoint(edge->to->pos.x()-d, edge->to->pos.y() + d);
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
                pos_f = QPoint(node->pos.x()+20, node->pos.y());
                pos_t = QPoint(edge->to->pos.x()-20, edge->to->pos.y());
            }
            else if (edge->to->pos.x() - node->pos.x() < 0 and edge->to->pos.y() - node->pos.y() == 0)
            {
                pos_f = QPoint(node->pos.x()-20, node->pos.y());
                pos_t = QPoint(edge->to->pos.x()+20, edge->to->pos.y());
            }
            else
            {
                pos_f = node->pos;
                pos_t = edge->to->pos;
            }
            painter.drawLine(pos_f, pos_t);
            int x_t = (pos_f.x() + pos_t.x()) / 2;
            int y_t = (pos_f.y() + pos_t.y()) / 2;
            painter.drawText(x_t, y_t, QString::number(edge->weight));
        }
    }

    for (const auto& pair : graph.nodes_map) {
        Node* node = pair.second;
        painter.drawEllipse(node->pos, 20, 20);
        painter.drawText(node->pos.x() - 7, node->pos.y() + 7, QString::number(node->data));
    }
}
void QtGraphs::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        for (const auto& pair : graph.nodes_map) {
            Node* node = pair.second;
            if ((event->pos() - node->pos).manhattanLength() < 30) {
                m_selectedNode = node;
                m_nodeSelected = true;
                break;
            }
        }
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
    int nodeValue = ui.lineEdit->text().toInt();
    graph.addNode(nodeValue);
    ui.lineEdit->clear();
    update();
}
void QtGraphs::on_pushButton_2_clicked() {
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
    SecondWindow wind;

}
