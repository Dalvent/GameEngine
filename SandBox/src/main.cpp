#include <iostream>
#include <GoblinEngine.h>

class SuckLayer : public GoblinEngine::Layer
{
public:
	SuckLayer(std::string name) 
		: Layer(name)
	{

	}

	void OnEvent(GoblinEngine::Event& event) override
	{
		GE_CORE_INFO("I SUCKK!!!!!")
	}
};

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
	auto game = new SandBox();
	game->AddLayer(new SuckLayer("Some"));

	return game;
}