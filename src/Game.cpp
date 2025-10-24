#include "Game.h"

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    grid_.draw(target, states);
    snake_.draw(target, states);
}