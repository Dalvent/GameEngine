#pragma once

#include "Engine/Core/Layer.h"

#include "Engine/Events/AppEvent.h"
#include "Engine/Events/KeyEvent.h"
#include "Engine/Events/MouseEvent.h"

namespace GoblinEngine
{
	class ENGINE_API ImGUILayer : public Layer
	{
	public:
		ImGUILayer() : Layer("ImGUILayer") {}
		~ImGUILayer() override;

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;
	private:
		// Mouse Events.
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent e);
		bool OnMouseMovedEvent(MouseMovedEvent e);
		bool OnMouseScrolledEvent(MouseScrolledEvent e);

		// Keyboard events
		bool OnKeyPressedEvent(KeyPressedEvent e);
		bool OnKeyReleasedEvent(KeyReleasedEvent e);
		bool OnKeyTypedEvent(KeyTypedEvent e);

		// Application events.
		bool OnWindowResizeEvent(WindowResizeEvent e);
	private:
		float _lastFrameTime = 0.0f;
	};
}