#pragma once

#include "SFML/Graphics.hpp"
#include "GapBuffer.h"

namespace azura
{
    class Window
    {
    private:
        sf::RenderWindow *window;

        void initVariables();

    public:
        Window();
        ~Window();

        void run();
    };

} // namespace azura
