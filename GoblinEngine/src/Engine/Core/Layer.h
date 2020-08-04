#pragma once

#include "Engine/Events/Event.h"

namespace GoblinEngine
{
	class Layer
	{
	public:
		Layer(const std::string name) : _name(name) {}
		virtual ~Layer() {}

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		const std::string& GetName() const { return _name; }
	private:
		std::string _name;
	};
}