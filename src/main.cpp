#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include "Grid.h"
#include "Snake.h"



int main()
{
     sf::RenderWindow window(
        sf::VideoMode({750u, 750u}),
        "Snake",
        sf::Style::Close,
        sf::State::Windowed,
        {});
    window.setFramerateLimit(2);

    Grid grid;
    Snake snake;

    while (window.isOpen())
    {

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            if (event->is<sf::Event::KeyPressed>())
            {
                if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::W)
                {
                    snake.move();
                }
            }

        }

        window.clear();
        window.draw(grid);
        window.draw(snake);
        window.display();
    }
    return 0;
}
