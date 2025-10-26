#include "Snake.h"
#include <vector>

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

Snake::Snake(
	const std::vector<sf::Vector2i>& body, sf::Vector2i direction, float cellSize, bool alive) :
	body_(body),
	cellSize_(cellSize),
	alive_(alive),
	direction_(direction)
	{}

void Snake::move()
{
	body_[0].y--;
	body_[1].y--;
	body_[2].y--;
}

// void Snake::setDirection(const sf::Vector2i &direction)
// {
//
// }

void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (const sf::Vector2i& bodyChunk : body_)
	{
		sf::RectangleShape cell(sf::Vector2f(cellSize_, cellSize_));
		cell.setPosition(sf::Vector2f((float)bodyChunk.x * cellSize_, (float)bodyChunk.y * cellSize_));
		cell.setFillColor(sf::Color(0, 200, 0));
		target.draw(cell, states);
	}
}
