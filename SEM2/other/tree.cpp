#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tree.cpp"
using namespace std;

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

    bool balanced = false;
    bool isMouseOverButton = false;
    sf::FloatRect buttonBounds;

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
            }
        }

        window.clear(sf::Color::Black);

        if (balanced)
            tr.drawTree(window, tr.head, 800, 50);
        else
            tr.drawTree(window, tr.head, 800, 50);

        if (isMouseOverButton)
        {
            sf::RectangleShape buttonOutline(sf::Vector2f(buttonBounds.width, buttonBounds.height));
            buttonOutline.setPosition(buttonBounds.left, buttonBounds.top);
            buttonOutline.setFillColor(sf::Color::Transparent);
            buttonOutline.setOutlineColor(sf::Color::Red);
            buttonOutline.setOutlineThickness(2.f);
            window.draw(buttonOutline);
        }

        window.draw(buttonText);

        window.display();
    }

    system("pause");

    return 0;
}
