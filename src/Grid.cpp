#include "Grid.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

Grid::Grid(int rows, int cols, float cellSize)
		: rows_(rows), cols_(cols), cellSize_(cellSize)
{

}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int y = 0; y < rows_; ++y)
	{
		for (int x = 0; x < cols_; ++x)
		{
			sf::RectangleShape cell(sf::Vector2f(cellSize_, cellSize_));
			cell.setPosition(sf::Vector2f((float)x * cellSize_, (float)y * cellSize_));
			cell.setFillColor(sf::Color::Blue);
			cell.setOutlineThickness(1.f);
			cell.setOutlineColor(sf::Color::Black);
			target.draw(cell, states);
		}
	}
}