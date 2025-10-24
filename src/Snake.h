#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H
#include <vector>
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/RectangleShape.hpp"


class Snake : public sf::Drawable
{
private:
	float cellSize_ = 50.f;
	std::vector<sf::Vector2i> body_;
	sf::Vector2i direction;
	bool alive = true;

public:
	explicit Snake(const std::vector<sf::Vector2i>& body);
	void move();
	void setDirection(const sf::Vector2i& direction);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif //SNAKE_SNAKE_H