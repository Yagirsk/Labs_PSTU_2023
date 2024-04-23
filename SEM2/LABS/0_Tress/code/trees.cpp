#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tree.cpp"
#include <thread>
#include <sstream>
#include <string>
#include <chrono>
using namespace std;
string bcan[61];
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
    sf::RenderWindow window(sf::VideoMode(1920, 800), "Binary Tree Visualization");
    for (int i = 0; i < 61; ++i) {
        bcan[i] = std::to_string(-30 + i);
    }
    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/arial.ttf");
    setlocale(LC_ALL, "ru_RU");

    std::string inputString1 = "";

    bool isInputting11 = true;
    sf::Text inputText1("", font, 30);
    inputText1.setFillColor(sf::Color::White);
    inputText1.setPosition(900, 150);

    sf::String unicodeString1 = L"Введите количество элементов в дереве\n(не менее одного)\nесли не будет введено ничего, будет задано 7 элементов";
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
                    else if (inputString1.size() == 0) {
                        if (event.text.unicode >= '1' && event.text.unicode <= '9') {
                            inputString1 += static_cast<char>(event.text.unicode);
                        }
                    }
                    else if (inputString1.size() > 0 && inputString1.size()<=8) {
                        if ((event.text.unicode >= '0' && event.text.unicode <= '9')) {
                            inputString1 += static_cast<char>(event.text.unicode);
                        }
                    }
                    inputText1.setString(inputString1);
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                isInputting11 = false;
                if (inputString1.empty()) {
                    inputString1 = "7";
                }
            }
        }

        window.clear();
        window.draw(inputText1);
        window.draw(outText1);
        window.display();
    }

    int n = std::stoi(inputString1);


    std::string inputString2 = "";
    bool isInputting12 = true;
    sf::Text inputText2("", font, 30);
    inputText2.setFillColor(sf::Color::White);
    inputText2.setPosition(850, 150);

    sf::String unicodeString3 = L"Введите \"корневой\" элемент дерева\nесли не будет введено значение, оно будет задано случайно от -30 до 30";
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
                    else if (inputString2.size() == 0) {
                        if (event.text.unicode == '1' || event.text.unicode == '2' || event.text.unicode == '3' || event.text.unicode == '4' || event.text.unicode == '5' || event.text.unicode == '6' || event.text.unicode == '7' || event.text.unicode == '8' || event.text.unicode == '9' || event.text.unicode == '0' || event.text.unicode == '-') { 
                            inputString2 += static_cast<char>(event.text.unicode); }
                    }
                    else if (inputString2.size() > 0 && inputString2.size() <= 8) {
                        if (event.text.unicode == '1' || event.text.unicode == '2' || event.text.unicode == '3' || event.text.unicode == '4' || event.text.unicode == '5' || event.text.unicode == '6' || event.text.unicode == '7' || event.text.unicode == '8' || event.text.unicode == '9' || event.text.unicode == '0') {
                            inputString2 += static_cast<char>(event.text.unicode);
                        }
                    }
                    inputText2.setString(inputString2);
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                isInputting12 = false;
                if (inputString2 == "" or inputString2 == "-") { int ara_ara = rand() % 61; inputString2 = bcan[ara_ara]; }
            }
        }

        window.clear();
        window.draw(inputText2);
        window.draw(outText3);
        window.display();
    }
    int a1 = stoi(inputString2);
    Tree tr;
    tr.head->data=a1;

    for (int i = 2; i <= n; i++)
    {
        std::string inputString3 = "";
        bool isInputting13 = true;
        sf::Text inputText3("", font, 30);
        inputText3.setFillColor(sf::Color::White);
        inputText3.setPosition(650, 150);

        string isp = to_string(i);
        sf::String is = sf::String::fromUtf8(isp.begin(), isp.end());
        sf::String unicodeString3 = L"Введите элемент №"+is+L"\nесли не будет введено значение, оно будет задано случайно от -30 до 30";
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
                        else if (inputString3.size() == 0) {
                            if (event.text.unicode == '1' || event.text.unicode == '2' || event.text.unicode == '3' || event.text.unicode == '4' || event.text.unicode == '5' || event.text.unicode == '6' || event.text.unicode == '7' || event.text.unicode == '8' || event.text.unicode == '9' || event.text.unicode == '0' || event.text.unicode == '-') {
                                inputString3 += static_cast<char>(event.text.unicode); }
                        }
                        else if (inputString3.size() > 0 && inputString3.size()<=8) {
                            if (event.text.unicode == '1' || event.text.unicode == '2' || event.text.unicode == '3' || event.text.unicode == '4' || event.text.unicode == '5' || event.text.unicode == '6' || event.text.unicode == '7' || event.text.unicode == '8' || event.text.unicode == '9' || event.text.unicode == '0') {
                                inputString3 += static_cast<char>(event.text.unicode);
                            }
                        }
                        inputText3.setString(inputString3);
                        if (inputString3 == "" or inputString3 == "-") { int ara_ara = rand() % 61; inputString3 = bcan[ara_ara]; }
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
        tr.push(a);
    }

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

    float aswl = 0;
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

                    tr.del_node(window, font);
                    deleted = true;
                    balanced = false;
                }
                if (addButtonBounds.contains(static_cast<sf::Vector2f>(mousePos)))
                {
                    tr.add_node(window, font);
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
                    sf::Text inputText("", font, 30);
                    inputText.setFillColor(sf::Color::White);
                    inputText.setPosition(865, 150);

                    sf::String unicodeString = L"Введите значение которое надо найти";
                    sf::Text outText(unicodeString, font, 30);
                    outText.setFillColor(sf::Color::White);
                    outText.setPosition(300, 150);

                    std::string inputString;

                    bool isInputting = true;

                    while (isInputting)
                    {
                        sf::Event event;
                        while (window.pollEvent(event)) {
                            if (event.type == sf::Event::TextEntered) {
                                if (event.text.unicode < 128) {
                                    if (event.text.unicode == '\b' && inputString.size() > 0) {
                                        inputString.pop_back();
                                    }
                                    else if (inputString.size() == 0) {
                                        if (event.text.unicode == '1' || event.text.unicode == '2' || event.text.unicode == '3' || event.text.unicode == '4' || event.text.unicode == '5' || event.text.unicode == '6' || event.text.unicode == '7' || event.text.unicode == '8' || event.text.unicode == '9' || event.text.unicode == '0' || event.text.unicode == '-') {
                                            inputString += static_cast<char>(event.text.unicode);
                                        }
                                    }
                                    else if (inputString.size() > 0 && inputString.size() <= 8) {
                                        if (event.text.unicode == '1' || event.text.unicode == '2' || event.text.unicode == '3' || event.text.unicode == '4' || event.text.unicode == '5' || event.text.unicode == '6' || event.text.unicode == '7' || event.text.unicode == '8' || event.text.unicode == '9' || event.text.unicode == '0') {
                                            inputString += static_cast<char>(event.text.unicode);
                                        }
                                    }
                                    inputText.setString(inputString);
                                }
                            }
                            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                                isInputting = false;
                                if (inputString == "") { inputString = "err"; }
                            }
                        }

                        window.clear();
                        window.draw(inputText);
                        window.draw(outText);
                        window.display();
                    }
                    if (inputString != "err")
                    {
                        int key = stoi(inputString);

                        string strv = "";
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
                            this_thread::sleep_for(std::chrono::seconds(3));
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
                            this_thread::sleep_for(std::chrono::seconds(3));
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
                            this_thread::sleep_for(std::chrono::seconds(3));
                        }
                    }
                    else
                    {
                        sf::String sunicodeString = L"Не введено значения для поиска";
                        sf::Text textt(sunicodeString, font, 30);
                        textt.setFont(font);
                        textt.setFillColor(sf::Color::White);
                        textt.setPosition(200, 100);
                        window.clear();
                        window.draw(textt);
                        window.display();
                        this_thread::sleep_for(std::chrono::seconds(2));
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
            tr.drawTree(window, tr.head, 1100, 50);
        if (deleted)
            tr.drawTree(window, tr.head, 1100, 50);
        else
            tr.drawTree(window, tr.head, 1100, 50);

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
