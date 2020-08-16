#pragma once
namespace GoblinEngine
{
	class IGraphicsContext
	{
	public:
		virtual void Init() = 0;
		virtual void SwapBuffer() = 0;
	};
}