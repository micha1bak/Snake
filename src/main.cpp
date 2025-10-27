#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include "Grid.h"
#include "Snake.h"
#include "Food.h"



int main()
{
     sf::RenderWindow window(
        sf::VideoMode({1000u, 1000u}),
        "Snake",
        sf::Style::Close,
        sf::State::Windowed,
        {});
    window.setFramerateLimit(4);

    Grid grid;
    Snake snake;
    Food food;
    bool pause = false;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 19);

    while (window.isOpen())
    {
        // Events
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
                    case sf::Keyboard::Key::Up:
                        snake.setDirection(sf::Vector2i(0, -1));
                        break;
                    case sf::Keyboard::Key::S:
                        snake.setDirection(sf::Vector2i(0, 1));
                        break;
                    case sf::Keyboard::Key::Down:
                        snake.setDirection(sf::Vector2i(0, 1));
                        break;
                    case sf::Keyboard::Key::A:
                        snake.setDirection(sf::Vector2i(-1, 0));
                        break;
                    case sf::Keyboard::Key::Left:
                        snake.setDirection(sf::Vector2i(-1, 0));
                        break;
                    case sf::Keyboard::Key::D:
                        snake.setDirection(sf::Vector2i(1, 0));
                        break;
                    case sf::Keyboard::Key::Right:
                        snake.setDirection(sf::Vector2i(1, 0));
                        break;
                    case sf::Keyboard::Key::Escape:
                        pause = true;
                        break;
                    case sf::Keyboard::Key::Space:
                        pause = false;
                        snake.restart();
                        break;
                    default:
                        break;
                }
            }
        }

        if (snake.getHead() == food.getPosition())
        {
            sf::Vector2i newPos = sf::Vector2i(dist(gen), dist(gen));
            bool unique = false;
            while (!unique)
            {
                for (int i = 0; i < snake.getBody().size(); ++i)
                {
                    if (newPos == snake.getBody()[i])
                    {
                        newPos = sf::Vector2i(dist(gen), dist(gen));
                        i = 0;
                    }
                }
                unique = true;
            }
            food.setPosition(newPos);
            snake.grow();
        }

        window.clear();
        window.draw(grid);
        //std::cout << snake.isAlive_ << std::endl;
        if (snake.isAlive_ && !pause)
        {
            snake.move();
            window.draw(food);
            window.draw(snake);
        }
        window.display();
    }
    return 0;
}
