#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Game.h"

int main()
{
    auto window = sf::RenderWindow(
        sf::VideoMode({800u, 600u}),
        "Snake",
        sf::Style::Close,
        sf::State::Windowed,
        {});

    window.setFramerateLimit(144);
    Snake snake;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        window.clear();
        window.display();
    }
    return 0;
}
