#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Game.h"
#include "Grid.h"

int main()
{
    auto window = sf::RenderWindow(
        sf::VideoMode({750u, 750u}),
        "Snake",
        sf::Style::Close,
        sf::State::Windowed,
        {});
    window.setFramerateLimit(1);

    Game game;

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
        window.draw(game);
        window.display();
    }
    return 0;
}