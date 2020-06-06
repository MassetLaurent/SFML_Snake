#ifndef STATE
#define STATE

class State
{
private:

public:
	State() {}
	virtual ~State() {}

	virtual void init() = 0;

	virtual void handleInput() = 0;
	virtual void update(const float &dt) = 0;
	virtual void render(const float &dt) = 0;

	virtual void pause() {}
	virtual void resume() {}
};

#endif // !STATE
