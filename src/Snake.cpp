#include "Snake.h"

#include <iostream>
#include <ostream>
#include <vector>

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

Snake::Snake(
	const std::vector<sf::Vector2i>& body, sf::Vector2i direction, float cellSize, bool alive) :
	body_(body),
	cellSize_(cellSize),
	isAlive_(alive),
	direction_(direction)
	{}

void Snake::move()
{
	sf::Vector2i newHead = body_[0] + direction_;
	if ((body_[0] + direction_).x > 19 || newHead.x < 0)
	{
		isAlive_ = false;
	}
	if ((body_[0] + direction_).y > 19 || newHead.y < 0)
	{
		isAlive_ = false;
	}
	for (auto cell : body_)
	{
		if (cell == newHead)
		{
			isAlive_ = false;
		}
	}
	body_.insert(body_.begin(), newHead);
	body_.pop_back();
}

void Snake::grow()
{
	body_.push_back(body_[body_.size() - 1]);
}

void Snake::setDirection(const sf::Vector2i &direction)
{
	direction_ = direction;
}

sf::Vector2i Snake::getDirection() const
{
	return direction_;
}

sf::Vector2i Snake::getHead() const
{
	return body_[0];
}

std::vector<sf::Vector2i> Snake::getBody() const
{
	return body_;
}

void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (const sf::Vector2i& bodyChunk : body_)
	{
		sf::RectangleShape cell(sf::Vector2f(cellSize_, cellSize_));
		cell.setPosition(sf::Vector2f((float)bodyChunk.x * cellSize_, (float)bodyChunk.y * cellSize_));
		cell.setFillColor(sf::Color::Green);
		target.draw(cell, states);
	}
}

void Snake::restart()
{
	body_ = {sf::Vector2i(7, 7), sf::Vector2i(7, 8), sf::Vector2i(7, 9)};
	isAlive_ = true;
	direction_ = sf::Vector2i(0,-1);
}
