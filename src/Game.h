#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H
#include "Grid.h"
#include "Snake.h"


class Game : public sf::Drawable{
private:
    Snake snake_ = Snake({sf::Vector2i(7, 7), sf::Vector2i(7, 8), sf::Vector2i(7, 9)});
    Grid grid_ = Grid(15, 15, 50.f);

public:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif //SNAKE_GAME_H