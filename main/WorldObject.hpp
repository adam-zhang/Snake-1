#pragma once

#include "Bounds.hpp"
#include "Color24.hpp"
#include "Mutex.hpp"

class Food;
class Mine;
class Screen;
class SnakeSegment;
class Wall;

class WorldObject
{
public:
	// must be exponents of 2 because they are masked
	enum ObjectType
	{
		snake = 1,
		wall = 1<<1,
		food = 1<<2,
		mine = 1<<3
	};

private:
	ObjectType type;

protected:
	Color24 color;
	// the rectangular bounds of this object
	Bounds bounds;

public:
	RecursiveMutex mutex;

	WorldObject(ObjectType);
	WorldObject(ObjectType, const Color24 color);
	virtual ~WorldObject();
	
	virtual void CollisionHandler(WorldObject&) const;
	virtual void CollisionHandler(const Food&);
	virtual void CollisionHandler(const Mine&);
	virtual void CollisionHandler(const SnakeSegment&);
	virtual void CollisionHandler(const Wall&);
	
	ObjectType GetObjectType() const;
	Bounds GetBounds() const;

	// draw this object to _target_
	void Draw(const Screen& target) const;
};
