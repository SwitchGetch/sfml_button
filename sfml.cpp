#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <random>
using namespace std;

HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
COORD cord;

class Button
{

    sf::RectangleShape button;

    int beginX;
    int beginY;
    int endX;
    int endY;

    int red;
    int green;
    int blue;

    int count = 0;

    int randomValue(int lower, int upper)
    {
        return lower + rand() % (upper - lower + 1);
    }

public:

    Button(int sideX, int sideY, int cordX, int cordY)
    {
        this->beginX = cordX;
        this->beginY = cordY;
        this->endX = cordX + sideX;
        this->endY = cordY + sideY;

        this->button.setSize(sf::Vector2f(sideX, sideY));
        this->button.setPosition(sf::Vector2f(cordX, cordY));
    }

    void setColor(int red, int green, int blue)
    {
        this->red = red;
        this->green = green;
        this->blue = blue;

        this->button.setFillColor(sf::Color(this->red, this->green, this->blue));
    }

    void setRandomColor()
    {
        this->red = randomValue(0, 255);
        this->green = randomValue(0, 255);
        this->blue = randomValue(0, 255);

        this->button.setFillColor(sf::Color(this->red, this->green, this->blue));
    }

    sf::Color getColor()
    {
        return sf::Color(this->red, this->green, this->blue);
    }

    int getBeginX()
    {
        return this->beginX;
    }

    int getBeginY()
    {
        return this->beginY;
    }

    int getEndX()
    {
        return this->endX;
    }

    int getEndY()
    {
        return this->endY;
    }

    void increaseCount()
    {
        this->count++;
    }

    int getCount()
    {
        return this->count;
    }

    void buttonOutput(sf::RenderWindow& window)
    {
        window.clear();
        window.draw(this->button);
        window.display();
    }

    void statsOutput()
    {
        system("cls");

        cout << "number of button presses: " << this->count << endl;

        cout << endl;

        cout << "begin x: " << this->beginX << endl;
        cout << "begin y: " << this->beginY << endl;
        cout << "end x: " << this->endX << endl;
        cout << "end y: " << this->endY << endl;

        cout << endl;

        cout << "current color: " << endl;
        cout << "R: " << this->red << endl;
        cout << "G: " << this->green << endl;
        cout << "B: " << this->blue << endl;

        cout << endl;
    }
};

int main()
{
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    Button button(100, 100, 50, 50);
    button.setRandomColor();

    /*sf::RectangleShape shape(sf::Vector2f(100, 100));
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(sf::Vector2f(50, 50));*/

    button.statsOutput();
    button.buttonOutput(window);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.x >= button.getBeginX() && event.mouseButton.x <= button.getEndX() && event.mouseButton.y >= button.getBeginY() && event.mouseButton.y <= button.getEndY())
                {
                    system("cls");

                    button.increaseCount();

                    cout << "number of button presses: " << button.getCount() << endl;

                    button.setRandomColor();

                    button.buttonOutput(window);
                }

                button.statsOutput();

                cout << "the " << (event.mouseButton.button == sf::Mouse::Right ? "right" : "left") << " button was pressed" << endl;
                cout << "mouse x: " << event.mouseButton.x << endl;
                cout << "mouse y: " << event.mouseButton.y << endl;
            }
        }
    }
}