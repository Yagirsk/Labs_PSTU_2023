#include <SFML/Graphics.hpp>
#include <iostream>
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

};

int main()
{
    cout << "Введите количество элементов в дереве: ";
    int n;
    cin >> n;
    Tree tr;
    int a1;
    cout << "Введите к̈орневойӭлемент дерева: ";
    cin >> a1;
    tr.head->data = a1;
    for (int i = 1; i < n; i++)
    {
        int a;
        cout << "Введите элемент №" << i + 1 << ": ";
        cin >> a;
        tr.push(a);
    }

    sf::RenderWindow window(sf::VideoMode(2000, 800), "Binary Tree Visualization");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        tr.drawTree(window, tr.head, 1000, 50);

        window.display();
    }

    return 0;
}
