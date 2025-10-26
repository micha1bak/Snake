#include "Food.h"

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderStates.hpp"
#include "SFML/Graphics/RenderTarget.hpp"


Food::Food(sf::Vector2i pos, float cellSize, bool alive) :
        pos_(pos), cellSize_(cellSize), alive_(alive)
{

}

void Food::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
        sf::RectangleShape food(sf::Vector2f(50.f, 50.f));
        food.setPosition(sf::Vector2f((float)pos_.x * cellSize_, (float)pos_.y * cellSize_));
        food.setFillColor(sf::Color::Red);
        target.draw(food, states);
}
