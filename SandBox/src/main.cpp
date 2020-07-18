#include <iostream>
#include <GoblinEngine.h>

class SandBox : public GoblinEngine::GameApplication
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

GoblinEngine::GameApplication* GoblinEngine::CreateApplication()
{
	return new SandBox();
}