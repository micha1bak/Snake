#ifndef SNAKE_FOOD_H
#define SNAKE_FOOD_H
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/System/Vector2.hpp"


class Food : public sf::Drawable
{
public:
    explicit Food(sf::Vector2i pos = sf::Vector2i(1,1), float cellSize = 50.f);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void setPosition(const sf::Vector2i& pos);
    sf::Vector2i getPosition() const;
private:
    sf::Vector2i pos_;
    float cellSize_;
};


#endif //SNAKE_FOOD_H