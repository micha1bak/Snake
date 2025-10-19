#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H
#include <vector>
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/RectangleShape.hpp"


class Snake : public sf::Drawable
{
private:
	float cellSize_ = 50.f;
	std::vector<std::vector<int>> pos_;
	std::vector<sf::RectangleShape> cells;

public:
	explicit Snake(const std::vector<std::vector<int>>& pos);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif //SNAKE_SNAKE_H