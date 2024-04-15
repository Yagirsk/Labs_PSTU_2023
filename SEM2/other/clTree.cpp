#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Tree_el
{
    Tree_el* l;
    Tree_el* r;
    int data;
};
class Tree
{
public:
    Tree_el* head;
    Tree()
    {
        head = new Tree_el;
        head->l = nullptr;
        head->r = nullptr;
    }
    void push(int new_data)
    {
        Tree_el* tmp = this->head;
        while (tmp != nullptr)
        {
            if (tmp->data <= new_data && tmp->r == nullptr)
            {
                Tree_el* tmp2 = new Tree_el;
                tmp2->data = new_data;
                tmp2->r = nullptr;
                tmp2->l = nullptr;
                tmp->r = tmp2;
                break;
            }
            else if (tmp->data > new_data && tmp->l == nullptr)
            {
                Tree_el* tmp2 = new Tree_el;
                tmp2->r = nullptr;
                tmp2->l = nullptr;
                tmp2->data = new_data;
                tmp->l = tmp2;
                break;
            }
            else if (tmp->data <= new_data && tmp->r != nullptr)
            {
                tmp = tmp->r;
            }
            else if (tmp->data > new_data && tmp->l != nullptr)
            {
                tmp = tmp->l;
            }
        }
    }
    int getDepth(Tree_el* node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int leftDepth = getDepth(node->l);
        int rightDepth = getDepth(node->r);

        return 1 + max(leftDepth, rightDepth);
    }
    int getTreeDepth()
    {
        return getDepth(head);
    }
    void drawTree(sf::RenderWindow& window, Tree_el* node, float x, float y)
    {
        if (node == nullptr)
        {
            return;
        }

        sf::CircleShape circle(20);
        circle.setFillColor(sf::Color::White);
        circle.setPosition(x, y);
        window.draw(circle);


        int offsetX = 20 + 20 * pow(2, getDepth(node));
        int offsetY = 70;
        sf::Font font;
        font.loadFromFile("C:/Windows/Fonts/arial.ttf");
        sf::Text text(to_string(node->data), font, 20);
        text.setFillColor(sf::Color::Blue);
        text.setPosition(x + 10, y + 10);
        window.draw(text);

        if (node->l != nullptr)
        {
            sf::Vertex line[] =
            {
                sf::Vertex(sf::Vector2f(x + 20, y + 20)),
                sf::Vertex(sf::Vector2f(x - offsetX + 20, y + offsetY + 20))
            };
            window.draw(line, 2, sf::Lines);
            drawTree(window, node->l, x - offsetX, y + offsetY);
        }
        if (node->r != nullptr)
        {
            sf::Vertex line[] =
            {
                sf::Vertex(sf::Vector2f(x + 20, y + 20)),
                sf::Vertex(sf::Vector2f(x + offsetX + 20, y + offsetY + 20))
            };
            window.draw(line, 2, sf::Lines);
            drawTree(window, node->r, x + offsetX, y + offsetY);
        }
    }
    void balanceTree()
    {
        std::vector<int> nodes;
        collectNodes(head, nodes); // Собираем все значения узлов дерева в вектор

        clearTree(head); // Очищаем текущее дерево

        std::sort(nodes.begin(), nodes.end()); // Сортируем значения вектора

        head = buildBalancedTree(nodes, 0, nodes.size() - 1); // Строим сбалансированное дерево из значений вектора

    }
    void clearTree(Tree_el* node)
    {
        if (node == nullptr)
        {
            return;
        }

        clearTree(node->l);
        clearTree(node->r);
        delete node;
    }

private:
    void collectNodes(Tree_el* node, std::vector<int>& nodes)
    {
        if (node == nullptr)
        {
            return;
        }

        collectNodes(node->l, nodes);
        nodes.push_back(node->data);
        collectNodes(node->r, nodes);
    }
    
    Tree_el* buildBalancedTree(const std::vector<int>& nodes, int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }

        int mid = (start + end) / 2;
        Tree_el* newNode = new Tree_el;
        newNode->data = nodes[mid];
        newNode->l = buildBalancedTree(nodes, start, mid - 1);
        newNode->r = buildBalancedTree(nodes, mid + 1, end);

        return newNode;
    }
};
