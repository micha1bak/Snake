#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include "Grid.h"
#include "Snake.h"
#include "Food.h"



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
    Food food;

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

                switch (event->getIf<sf::Event::KeyPressed>()->code)
                {
                    case sf::Keyboard::Key::W:
                        snake.setDirection(sf::Vector2i(0, -1));
                        break;
                    case sf::Keyboard::Key::S:
                        snake.setDirection(sf::Vector2i(0, 1));
                        break;
                    case sf::Keyboard::Key::A:
                        snake.setDirection(sf::Vector2i(-1, 0));
                        break;
                    case sf::Keyboard::Key::D:
                        snake.setDirection(sf::Vector2i(1, 0));
                        break;
                    default:
                        break;
                }
            }

        }

        window.clear();
        window.draw(grid);
        snake.move();
        window.draw(snake);
        window.draw(food);
        window.display();
    }
    return 0;
}
