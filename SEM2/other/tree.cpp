#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tree.cpp"
#include <thread>
#include <sstream>
#include <string>
#include <chrono>
using namespace std;
void reverserss(string& str)
{
    int left = 0;
    int right = str.length() - 1;

    while (left < right)
    {
        swap(str[left], str[right]);
        left++;
        right--;
    }
}
int main()
{
    setlocale(LC_ALL, "ru_RU");

    cout << "Введите количество элементов в дереве: ";
    int n;
    cin >> n;

    Tree tr;
    int a1;
    cout << "Введите \"корневой\" элемент дерева : ";
    cin >> a1;
    tr.head->data = a1;

    for (int i = 1; i < n; i++)
    {
        int a;
        cout << "Введите элемент №" << i + 1 << ": ";
        cin >> a;
        tr.push(a);
    }

    sf::RenderWindow window(sf::VideoMode(1600, 800), "Binary Tree Visualization");

    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/arial.ttf");

    sf::Text buttonText;
    buttonText.setFont(font);
    buttonText.setString("Balance Tree");
    buttonText.setCharacterSize(24);
    buttonText.setFillColor(sf::Color::White);
    buttonText.setPosition(20, 20);

    sf::Text button_td_Text;
    button_td_Text.setFont(font);
    button_td_Text.setString("delete mode");
    button_td_Text.setCharacterSize(24);
    button_td_Text.setFillColor(sf::Color::White);
    button_td_Text.setPosition(20, 90);

    sf::Text button_addd_Text;
    button_addd_Text.setFont(font);
    button_addd_Text.setString("add mode");
    button_addd_Text.setCharacterSize(24);
    button_addd_Text.setFillColor(sf::Color::White);
    button_addd_Text.setPosition(20, 160);

    sf::Text button_sum_Text;
    button_sum_Text.setFont(font);
    button_sum_Text.setString("get average value");
    button_sum_Text.setCharacterSize(24);
    button_sum_Text.setFillColor(sf::Color::White);
    button_sum_Text.setPosition(20, 230);

    sf::Text button_search_Text;
    button_search_Text.setFont(font);
    button_search_Text.setString("search");
    button_search_Text.setCharacterSize(24);
    button_search_Text.setFillColor(sf::Color::White);
    button_search_Text.setPosition(20, 300);

    bool balanced = false;
    bool deleted = false;
    bool isMouseOverAddButton = false;
    bool isMouseOverSrArButton = false;
    bool isMouseOverButton = false;
    bool isMouseOverDeleteButton = false;
    bool isMouseOverSearchButton = false;
    sf::FloatRect buttonBounds;
    sf::FloatRect deleteButtonBounds;
    sf::FloatRect addButtonBounds;
    sf::FloatRect midButtonBounds;
    sf::FloatRect searchButtonBounds;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (buttonBounds.contains(static_cast<sf::Vector2f>(mousePos)))
                {
                    tr.balanceTree();
                    balanced = true;
                    deleted = false;
                }
                if (deleteButtonBounds.contains(static_cast<sf::Vector2f>(mousePos)))
                {
                    sf::String unicodeString = L"Введите путь к узлу который будет удален, путь должен состоять из симловл 'r' и 'l'\nr - переход к правом улементу\nl - переход к левому элементу";
                    sf::Text text(unicodeString, font, 30);
                    text.setFont(font);
                    text.setFillColor(sf::Color::White);
                    text.setPosition(200, 100);
                    window.clear();
                    window.draw(text);
                    window.display();

                    tr.del_node();
                    deleted = true;
                    balanced = false;
                }
                if (addButtonBounds.contains(static_cast<sf::Vector2f>(mousePos)))
                {
                    sf::String unicodeString = L"В консоли введи дерево которое вставится в данное";
                    sf::Text text(unicodeString, font, 30);
                    text.setFont(font);
                    text.setFillColor(sf::Color::White);
                    text.setPosition(200, 100);
                    window.clear();
                    window.draw(text);
                    window.display();

                    tr.add_node();
                    balanced = false;
                    deleted = false;
                }
                if (midButtonBounds.contains(static_cast<sf::Vector2f>(mousePos)))
                {
                    float mid = tr.getSumOfAllElements() / tr.getCountOfAllElements();
                    sf::String unicodeString = L"Среднее арифмитическое дерева = " + std::to_wstring(mid);
                    sf::Text text(unicodeString, font, 30);
                    text.setFont(font);
                    text.setFillColor(sf::Color::White);
                    text.setPosition(200, 100);
                    window.clear();
                    window.draw(text);
                    window.display();
                    this_thread::sleep_for(std::chrono::seconds(3));
                }
                if (searchButtonBounds.contains(static_cast<sf::Vector2f>(mousePos)))
                {
                    sf::String unicodeString = L"В консоли введите значение элемента который надо найти";
                    sf::Text text(unicodeString, font, 30);
                    text.setFont(font);
                    text.setFillColor(sf::Color::White);
                    text.setPosition(200, 100);
                    window.clear();
                    window.draw(text);
                    window.display();
                    string strv = "";
                    int key;
                    cin >> key;

                    reverserss(strv);
                    Tree_el* node_searched = tr.search(tr.head, key, strv);

                    if (node_searched != nullptr && node_searched != tr.head)
                    {
                        sf::String sfStrv = sf::String::fromUtf8(strv.begin(), strv.end());
                        sf::String sunicodeString = L"Элемент найден на пути " + sfStrv;
                        sf::Text textt(sunicodeString, font, 30);
                        textt.setFont(font);
                        textt.setFillColor(sf::Color::White);
                        textt.setPosition(200, 100);
                        window.clear();
                        window.draw(textt);
                        window.display();
                        this_thread::sleep_for(std::chrono::seconds(5));
                    }
                    else if (node_searched == tr.head)
                    {
                        sf::String sunicodeString = L"Элемент является корневым";
                        sf::Text textt(sunicodeString, font, 30);
                        textt.setFont(font);
                        textt.setFillColor(sf::Color::White);
                        textt.setPosition(200, 100);
                        window.clear();
                        window.draw(textt);
                        window.display();
                        this_thread::sleep_for(std::chrono::seconds(5));
                    }
                    else
                    {
                        sf::String sunicodeString = L"Элемент не найден";
                        sf::Text textt(sunicodeString, font, 30);
                        textt.setFont(font);
                        textt.setFillColor(sf::Color::White);
                        textt.setPosition(200, 100);
                        window.clear();
                        window.draw(textt);
                        window.display();
                        this_thread::sleep_for(std::chrono::seconds(5));
                    }
                }
            }

            if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                buttonBounds = buttonText.getGlobalBounds();
                buttonBounds.left -= 20;
                buttonBounds.top -= 20;
                buttonBounds.width += 40;
                buttonBounds.height += 40;
                if (buttonBounds.contains(static_cast<sf::Vector2f>(mousePos)))
                {
                    isMouseOverButton = true;
                }
                else
                {
                    isMouseOverButton = false;
                }

                deleteButtonBounds = button_td_Text.getGlobalBounds();
                deleteButtonBounds.left -= 18;
                deleteButtonBounds.top -= 20;
                deleteButtonBounds.width += 38;
                deleteButtonBounds.height += 40;
                if (deleteButtonBounds.contains(static_cast<sf::Vector2f>(mousePos)))
                {
                    isMouseOverDeleteButton = true;
                }
                else
                {
                    isMouseOverDeleteButton = false;
                }

                addButtonBounds = button_addd_Text.getGlobalBounds();
                addButtonBounds.left -= 18;
                addButtonBounds.top -= 20;
                addButtonBounds.width += 38;
                addButtonBounds.height += 40;
                if (addButtonBounds.contains(static_cast<sf::Vector2f>(mousePos)))
                {
                    isMouseOverAddButton = true;
                }
                else
                {
                    isMouseOverAddButton = false;
                }

                midButtonBounds = button_sum_Text.getGlobalBounds();
                midButtonBounds.left -= 18;
                midButtonBounds.top -= 20;
                midButtonBounds.width += 38;
                midButtonBounds.height += 40;
                if (midButtonBounds.contains(static_cast<sf::Vector2f>(mousePos)))
                {
                    isMouseOverSrArButton = true;
                }
                else
                {
                    isMouseOverSrArButton = false;
                }

                searchButtonBounds = button_search_Text.getGlobalBounds();
                searchButtonBounds.left -= 15;
                searchButtonBounds.top -= 20;
                searchButtonBounds.width += 30;
                searchButtonBounds.height += 40;
                if (searchButtonBounds.contains(static_cast<sf::Vector2f>(mousePos)))
                {
                    isMouseOverSearchButton = true;
                }
                else
                {
                    isMouseOverSearchButton = false;
                }
            }
        }

        window.clear(sf::Color::Black);

        if (balanced)
            tr.drawTree(window, tr.head, 800, 50);
        if (deleted)
            tr.drawTree(window, tr.head, 800, 50);
        else
            tr.drawTree(window, tr.head, 800, 50);

        if (isMouseOverSrArButton)
        {
            sf::RectangleShape midButtonOutline(sf::Vector2f(midButtonBounds.width, midButtonBounds.height));
            midButtonOutline.setPosition(midButtonBounds.left, midButtonBounds.top);
            midButtonOutline.setFillColor(sf::Color::Transparent);
            midButtonOutline.setOutlineColor(sf::Color::Red);
            midButtonOutline.setOutlineThickness(2.f);
            window.draw(midButtonOutline);
        }
        if (isMouseOverDeleteButton)
        {
            sf::RectangleShape deleteButtonOutline(sf::Vector2f(deleteButtonBounds.width, deleteButtonBounds.height));
            deleteButtonOutline.setPosition(deleteButtonBounds.left, deleteButtonBounds.top);
            deleteButtonOutline.setFillColor(sf::Color::Transparent);
            deleteButtonOutline.setOutlineColor(sf::Color::Red);
            deleteButtonOutline.setOutlineThickness(2.f);
            window.draw(deleteButtonOutline);
        }
        if (isMouseOverAddButton)
        {
            sf::RectangleShape deleteButtonOutline(sf::Vector2f(addButtonBounds.width, addButtonBounds.height));
            deleteButtonOutline.setPosition(addButtonBounds.left, addButtonBounds.top);
            deleteButtonOutline.setFillColor(sf::Color::Transparent);
            deleteButtonOutline.setOutlineColor(sf::Color::Red);
            deleteButtonOutline.setOutlineThickness(2.f);
            window.draw(deleteButtonOutline);
        }
        if (isMouseOverButton)
        {
            sf::RectangleShape deleteButtonOutline(sf::Vector2f(buttonBounds.width, buttonBounds.height));
            deleteButtonOutline.setPosition(buttonBounds.left, buttonBounds.top);
            deleteButtonOutline.setFillColor(sf::Color::Transparent);
            deleteButtonOutline.setOutlineColor(sf::Color::Red);
            deleteButtonOutline.setOutlineThickness(2.f);
            window.draw(deleteButtonOutline);
        }
        if (isMouseOverSearchButton)
        {
            sf::RectangleShape searchButtonOutline(sf::Vector2f(searchButtonBounds.width, searchButtonBounds.height));
            searchButtonOutline.setPosition(searchButtonBounds.left, searchButtonBounds.top);
            searchButtonOutline.setFillColor(sf::Color::Transparent);
            searchButtonOutline.setOutlineColor(sf::Color::Red);
            searchButtonOutline.setOutlineThickness(2.f);
            window.draw(searchButtonOutline);
        }

        window.draw(buttonText);
        window.draw(button_td_Text);
        window.draw(button_addd_Text);
        window.draw(button_sum_Text);
        window.draw(button_search_Text);

        window.display();
    }

    system("pause");

    return 0;
}
