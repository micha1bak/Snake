#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H
#include <vector>
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/RectangleShape.hpp"


class Snake : public sf::Drawable
{
	public:
		explicit Snake(
			const std::vector<sf::Vector2i>& body = {sf::Vector2i(7, 7), sf::Vector2i(7, 8), sf::Vector2i(7, 9)},
			sf::Vector2i direction = sf::Vector2i(0,-1),
			float cellSize = 50.f,
			bool alive = true);
		void move();
		void setDirection(const sf::Vector2i& direction);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:
		float cellSize_;
		std::vector<sf::Vector2i> body_;
		sf::Vector2i direction_;
		bool alive_ = true;
};


#endif //SNAKE_SNAKE_H