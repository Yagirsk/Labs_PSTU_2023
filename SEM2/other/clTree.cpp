#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <sstream>
#include <string>
#include <chrono>
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
        text.setFillColor(sf::Color::Red);
        text.setPosition(x + 10, y + 9);

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
    void del_node(sf::RenderWindow& window, sf::Font font)
    {
        Tree_el* ntd = head;
        Tree_el* parent = nullptr;
        bool delte = true;

        sf::String unicodeString = L"Введите путь к узлу который будет удален, путь должен состоять из симловл 'r' и 'l'\nr - переход к правом улементу\nl - переход к левому элементу";
        sf::Text text(unicodeString, font, 30);
        text.setFont(font);
        text.setFillColor(sf::Color::White);
        text.setPosition(200, 100);
        sf::Text inputText("", font, 30);
        inputText.setFillColor(sf::Color::White);
        inputText.setPosition(200, 215);
        sf::String uunicodeString = L"Некорректный путь к узлу";
        sf::Text erroText(uunicodeString, font, 30);
        erroText.setFont(font);
        erroText.setFillColor(sf::Color::White);
        erroText.setPosition(200, 100);

        string inputString = "";

        bool isInputting = true;

        while (isInputting)
        {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode < 128) {
                        if (event.text.unicode == 'l' || event.text.unicode == 'r') {
                            inputString += static_cast<char>(event.text.unicode);
                        }
                        else if (event.text.unicode == '\b' && inputString.size() > 0) {
                            inputString.pop_back();
                        }
                                               
                        inputText.setString(inputString);
                    }
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                    isInputting = false;
                }
            }

            window.clear();
            window.draw(inputText);
            window.draw(text);
            window.display();
        }
        string s = inputString;
        for (int i = 0; i < s.size(); i++)
        {
            if (ntd == nullptr)
            {
                cout << "некоректная позиция1\n";
                window.clear();
                window.draw(erroText);
                window.display();
                delte = false;
                this_thread::sleep_for(std::chrono::seconds(3));
                break;
            }
            parent = ntd;
            if (s[i] == 'l') {
                ntd = ntd->l;
            }
            else if (s[i] == 'r') {
                ntd = ntd->r;
            }
            else if (s[i] != 'l' and s[i] != 'r')
            {
                cout << "некоректная позиция2\n";
                window.clear();
                window.draw(erroText);
                window.display();
                delte = false;
                this_thread::sleep_for(std::chrono::seconds(3));
                break;
            }
        }
        if (delte)
        {
            deleteNode(ntd, parent);
        }
    }
    void add_node(sf::RenderWindow& window, sf::Font font)
    {
        std::string inputString1 = "";

        bool isInputting11 = true;
        sf::Text inputText1("", font, 30);
        inputText1.setFillColor(sf::Color::White);
        inputText1.setPosition(999, 150);

        sf::String unicodeString1 = L"Введите количество элементов в новом дереве\n(не менее одного)";
        sf::Text outText1(unicodeString1, font, 30);
        outText1.setFillColor(sf::Color::White);
        outText1.setPosition(300, 150);
        while (isInputting11)
        {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode < 128) {
                        if (event.text.unicode == '\b' && inputString1.size() > 0) {
                            inputString1.pop_back();
                        }
                        else if (event.text.unicode != '\b') {
                            inputString1 += static_cast<char>(event.text.unicode);
                        }
                        inputText1.setString(inputString1);
                    }
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                    isInputting11 = false;
                }
            }

            window.clear();
            window.draw(inputText1);
            window.draw(outText1);
            window.display();
        }
        int n = stoi(inputString1);

        std::string inputString2 = "";
        bool isInputting12 = true;
        sf::Text inputText2("", font, 30);
        inputText2.setFillColor(sf::Color::White);
        inputText2.setPosition(970, 150);

        sf::String unicodeString3 = L"Введите \"корневой\" элемент нового дерева";
        sf::Text outText3(unicodeString3, font, 30);
        outText3.setFillColor(sf::Color::White);
        outText3.setPosition(300, 150);
        while (isInputting12)
        {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode < 128) {
                        if (event.text.unicode == '\b' && inputString2.size() > 0) {
                            inputString2.pop_back();
                        }
                        else if (event.text.unicode != '\b') {
                            inputString2 += static_cast<char>(event.text.unicode);
                        }
                        inputText2.setString(inputString2);
                    }
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                    isInputting12 = false;
                }
            }

            window.clear();
            window.draw(inputText2);
            window.draw(outText3);
            window.display();
        }
        int a1 = stoi(inputString2);
        Tree tra;
        tra.head->data = a1;

        for (int i = 2; i <= n; i++)
        {
            std::string inputString3 = "";
            bool isInputting13 = true;
            sf::Text inputText3("", font, 30);
            inputText3.setFillColor(sf::Color::White);
            inputText3.setPosition(620, 150);

            string isp = to_string(i);
            sf::String is = sf::String::fromUtf8(isp.begin(), isp.end());
            sf::String unicodeString3 = L"Введите элемент №" + is;
            sf::Text outText4(unicodeString3, font, 30);
            outText4.setFillColor(sf::Color::White);
            outText4.setPosition(300, 150);
            while (isInputting13)
            {
                sf::Event event;
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::TextEntered) {
                        if (event.text.unicode < 128) {
                            if (event.text.unicode == '\b' && inputString3.size() > 0) {
                                inputString3.pop_back();
                            }
                            else if (event.text.unicode != '\b') {
                                inputString3 += static_cast<char>(event.text.unicode);
                            }
                            inputText3.setString(inputString3);
                        }
                    }
                    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                        isInputting13 = false;
                    }
                }

                window.clear();
                window.draw(inputText3);
                window.draw(outText4);
                window.display();
            }

            int a = stoi(inputString3);
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
