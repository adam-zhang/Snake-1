#pragma once

#include "Mine.hpp"
#include "Food.hpp"
#include "Snake.hpp"
#include "Sound.hpp"
#include "Timer.hpp"
#include "Wall.hpp"

#ifdef MSVC
#pragma warning(push, 0)
#endif

#include <boost/thread.hpp>
#include <boost/shared_ptr.hpp>
#include <list>
#include <SDL_events.h>

#ifdef MSVC
#pragma warning(pop)
#endif

struct ZippedUniqueObjectList;

class GameWorld
{
public:
	typedef boost::shared_ptr<Spawn> SpawnPtr;
	typedef std::list<SpawnPtr> SpawnList;
	typedef std::vector<Wall> WallList;
	typedef std::vector<Sound> SoundList;

private:
	void SpawnLoop();

	ZippedUniqueObjectList& gameObjects;

	SpawnList spawns;
	boost::mutex spawnMutex;

	boost::thread spawnThread;

	SoundList sounds;

	// whether or not to reset the game
	bool reset;

	Snake player;

	WallList walls;

	void Init();

public:
	GameWorld(ZippedUniqueObjectList& gameObjects);

	void Update();
	void Reset();

	// handle all the non object-specific side-effects of collisions (e.g. sound effects)
	void CollisionHandler(WorldObject&, WorldObject&);

	void KeyNotify(SDLKey key);
	void MouseNotify(Uint8 mouseButton);
};
