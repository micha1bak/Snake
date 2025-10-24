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
    const Grid grid(15,15,50.0);
    std::vector<sf::Vector2i> currentPosition = {sf::Vector2i(7, 7), sf::Vector2i(7,8)};
    Snake snake(currentPosition);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        snake.move();
        window.clear();
        window.draw(grid);
        window.draw(snake);
        window.display();
    }
    return 0;
}
