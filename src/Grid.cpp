#include "Grid.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

Grid::Grid(int rows, int cols, float cellSize)
		: rows(rows), cols(cols), cellSize(cellSize)
{
	for (int y = 0; y < rows; ++y)
	{
		for (int x = 0; x < cols; ++x)
		{
			sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
			cell.setPosition(sf::Vector2f(x * cellSize, y * cellSize));
			cell.setFillColor(sf::Color::Transparent);
			cell.setOutlineThickness(1.f);
			cell.setOutlineColor(sf::Color(100, 100, 100));
			cells.push_back(cell);
		}
	}
}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (const auto& cell : cells)
	{
		target.draw(cell, states);
	}
}