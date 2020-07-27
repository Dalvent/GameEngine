#include "pch.h"
#include "Game.h"
#include "GLFW/glfw3.h"

GoblinEngine::Game::Game()
{
	_window = std::unique_ptr<Window>(Window::Create());
}

GoblinEngine::Game::~Game()
{
}

void GoblinEngine::Game::Run()
{
	GE_TRACE("GO!");
	while (true)
	{
		glClearColor(1, 1, 0, 1);


		glClear(GL_COLOR_BUFFER_BIT);
		_window->OnUpdate();
	}
}
