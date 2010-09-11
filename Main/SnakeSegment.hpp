#pragma once

#include "Direction.hpp"
#include "Food.hpp"
#include "WorldObject.hpp"

class SnakeSegment : public World::WorldObject
{
private:
	bool dead;
	bool hasEaten;

	void FoodCollisionHandler(const Food& foodObject);
	void DeathCollisionHandler();

	// change length by _amount_
	void ModifyLength(int amount);

public:
	Direction direction;

	SnakeSegment(Point location, Direction direction);

	void CollisionHandler(const WorldObject&);

	// increase length
	SnakeSegment& operator++();
	// increase length
	SnakeSegment operator++(int);
	// decrease length
	SnakeSegment& operator--();
	// decrease length
	SnakeSegment operator--(int);

	bool IsDead() const;
	bool HasEaten();
};
