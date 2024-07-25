#include "Window.h"

namespace azura
{
    void Window::initVariables()
    {
        this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Azura");
    }

    Window::Window()
    {
        this->initVariables();
    }
    Window::~Window()
    {
        delete this->window;
    }

    void Window::run()
    {
        GapBuffer gapBuffer;

        bool keyCharPressed = false;
        char lastCharPressed;
        bool keyBackspacePressed = false;
        bool keySpacePressed = false;

        while (this->window->isOpen())
        {
            sf::Event e;
            while (this->window->pollEvent(e))
            {
                if (e.type == sf::Event::Closed)
                {
                    this->window->close();
                }

                if (e.type == sf::Event::KeyPressed)
                {
                    if (e.key.code >= 0 && e.key.code <= 25 && !keyCharPressed)
                    {
                        char charPressed = 'a' + e.key.code;
                        gapBuffer.insert(charPressed);
                        gapBuffer.displayBuffer();
                        keyCharPressed = true;
                        lastCharPressed = charPressed;
                    }
                    else if (e.key.code == sf::Keyboard::Space && !keySpacePressed)
                    {
                        gapBuffer.insert(' ');
                        gapBuffer.displayBuffer();
                        keySpacePressed = true;
                    }
                    else if (e.key.code == sf::Keyboard::BackSpace && !keyBackspacePressed)
                    {
                        gapBuffer.backSpace();
                        gapBuffer.displayBuffer();
                        keyBackspacePressed = true;
                    }
                }

                if (e.type == sf::Event::KeyReleased)
                {
                    if (e.key.code == lastCharPressed - 'a')
                    {
                        keyCharPressed = false;
                    }
                    else if (e.key.code == sf::Keyboard::Space)
                    {
                        keySpacePressed = false;
                    }
                    else if (e.key.code == sf::Keyboard::BackSpace)
                    {
                        keyBackspacePressed = false;
                    }
                }
            }
        }
    }
} // namespace azura
