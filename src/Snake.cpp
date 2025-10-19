#include "Snake.h"
#include <vector>

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

Snake::Snake(const std::vector<std::vector<int>>& pos)
	: pos_(pos)
{
	for (const auto & po : pos)
	{
			sf::RectangleShape cell(sf::Vector2f(cellSize_, cellSize_));
			cell.setPosition(sf::Vector2f(po[0] * cellSize_, po[1] * cellSize_));
			cell.setFillColor(sf::Color(0, 200, 0));
			cells.push_back(cell);
	}
}

void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (const auto& cell : cells)
	{
		target.draw(cell, states);
	}
}