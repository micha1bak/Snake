#ifndef SNAKE_GRID_H
#define SNAKE_GRID_H
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/RectangleShape.hpp"


class Grid : public sf::Drawable
{
private:
	int rows_, cols_;
	float cellSize_;
	std::vector<sf::RectangleShape> cells;
public:
	Grid(int rows, int cols, float cellSize);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif //SNAKE_GRID_H