#ifndef SNAKE_GRID_H
#define SNAKE_GRID_H
#include "SFML/Graphics/Drawable.hpp"



class Grid : public sf::Drawable
{
public:
	explicit Grid(int rows = 20, int cols = 20, float cellSize = 50.f);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	int rows_, cols_;
	float cellSize_;
};


#endif //SNAKE_GRID_H