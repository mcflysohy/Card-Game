#ifndef STATE_HPP_INCLUDED
#define STATE_HPP_INCLUDED

class GameState
{
public:
	virtual void init() = 0;

	virtual void handleEvents() = 0;
	virtual void update() = 0;
	virtual void draw (float dt) = 0;

	virtual void pause() {};
	virtual void resume() {};
};

#endif
