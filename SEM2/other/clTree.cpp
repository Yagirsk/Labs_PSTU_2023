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
        text.setPosition(x + 12, y + 8);
        window.draw(text);

        sf::Event event;
        

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
        collectNodes(head, nodes);
        clearTree(head);
        std::sort(nodes.begin(), nodes.end());
        head = buildBalancedTree(nodes, 0, nodes.size() - 1);

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
    void deleteNode(Tree_el*& node, Tree_el* parent)
    {
        if (node == nullptr)
            return;

        deleteNode(node->l, node);
        deleteNode(node->r, node);

        if (parent != nullptr)
        {
            if (parent->l == node)
                parent->l = nullptr;
            else if (parent->r == node)
                parent->r = nullptr;
        }

        delete node;
        node = nullptr;
    }
    void del_node()
    {
        string s;
        cin >> s;
        Tree_el* ntd = head;
        Tree_el* parent = nullptr;
        bool delte = true;
        for (int i = 0; i < s.size(); i++)
        {
            if (ntd == nullptr)
            {
                cout << "некоректная позиция\n";
                delte = false;
                break;
            }
            parent = ntd;
            if (s[i] == 'l')
                ntd = ntd->l;
            else if (s[i] == 'r')
                ntd = ntd->r;
            else if (s[i] != 'l' and s[i] != 'r')
            {
                cout << "некоректная позиция\n";
                delte = false;
                break;
            }
        }
        if (delte)
        {
            deleteNode(ntd, parent);
        }
    }
    void add_node()
    {
        cout << "Введите количество элементов нового дерева: ";
        int n;
        cin >> n;
        Tree tra;
        int a1;
        cout << "Введите \"корневой\" элемент нового дерева : ";
        cin >> a1;
        tra.head->data = a1;
        for (int i = 1; i < n; i++)
        {
            int a;
            cout << "Введите элемент №" << i + 1 << ": ";
            cin >> a;
            tra.push(a);
        }
        Tree_el* tmp = head;
        int t_data = tra.head->data;
        while (true)
        {
            if (tmp->data >= t_data)
            {
                if (tmp->l == nullptr)
                {
                    tmp->l = tra.head;
                    break;
                }
                tmp = tmp->l;
            }
            else if (tmp->data < t_data)
            {
                if (tmp->r == nullptr)
                {
                    tmp->r = tra.head;
                    break;
                }
                tmp = tmp->r;
            }
        }

    }
    float sumElements(Tree_el* node)
    {
        if (node == nullptr)
            return 0;

        // Рекурсивно считаем суммы левого и правого поддеревьев
        int sumLeft = sumElements(node->l);
        int sumRight = sumElements(node->r);

        // Суммируем значение текущего узла с суммами левого и правого поддеревьев
        return node->data + sumLeft + sumRight;
    }
    float getSumOfAllElements()
    {
        return sumElements(head);
    }
    float countElements(Tree_el* node)
    {
        if (node == nullptr)
            return 0;

        int countLeft = countElements(node->l);
        int countRight = countElements(node->r);

        return 1 + countLeft + countRight;
    }
    float getCountOfAllElements()
    {
        return countElements(head);
    }
    Tree_el* search(Tree_el* node, int key, string& strv)
    {
        if (node == nullptr || node->data == key)
        {
            return node;
        }

        if (key < node->data)
        {
            strv += "l";  // Добавляем "l" к пути
            return search(node->l, key, strv);
        }
        else
        {
            strv += "r";  // Добавляем "r" к пути
            return search(node->r, key, strv);
        }
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
