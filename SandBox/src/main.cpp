#include <iostream>
#include <GoblinEngine.h>

class SuckLayer : public GoblinEngine::Layer
{
public:
	SuckLayer() 
		: Layer("SuckLayer")
	{
	}

	void OnEvent(GoblinEngine::Event& event) override
	{
	}
};

class SandBox : public GoblinEngine::Application
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

GoblinEngine::Application* GoblinEngine::CreateGame()
{
	auto game = new SandBox();
	game->AddLayer(new ImGUILayer());

	return game;
}