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

    window.setFramerateLimit(144);
    const Grid grid(15,15,50.0);
    Snake snake({{7,7}, {7, 8}, {7, 9} });

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
        window.draw(grid);
        window.draw(snake);
        window.display();
    }
    return 0;
}
