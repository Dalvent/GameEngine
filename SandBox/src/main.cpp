#include <iostream>
#include <GoblinEngine.h>

class SandBox : public GoblinEngine::Game
{
public:
	SandBox()
	{

	}
	~SandBox()
	{

	}
private:

};

GoblinEngine::Game* GoblinEngine::CreateGame()
{
	return new SandBox();
}