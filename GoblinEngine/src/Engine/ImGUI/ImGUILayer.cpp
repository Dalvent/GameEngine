#include "pch.h"

#include "ImGUILayer.h"
#include "imgui.h"

#include "Engine/Core.h"
#include "Engine/Application.h"
#include "Engine/Platform/OpenGL/ImGUIOpenGLRenderer.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace GoblinEngine
{
	ImGUILayer::~ImGUILayer()
	{

	}

	void ImGUILayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
		io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
		io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
		io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
		io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
		io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
		io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
		io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
		io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
		io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
		io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
		io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
		io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
		io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
		io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
		io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
		io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGUILayer::OnDetach()
	{
	}

	void ImGUILayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		Window& window = Application::Get().GetWindow();
		io.DisplaySize = ImVec2(window.GetWidth(), window.GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = _lastFrameTime > 0.0f ? (time - _lastFrameTime) : (1.0f / 60.0f);
		_lastFrameTime = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool isDemoWindowShow = true;
		ImGui::ShowDemoWindow(&isDemoWindowShow);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	} 

	void ImGUILayer::OnEvent(Event& event)
	{
		auto dispatcher = EventDispatcher(event);

		dispatcher.Dispatch<MouseButtonPressedEvent>(GE_BIND_EVENT(ImGUILayer::OnMouseButtonPressedEvent));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(GE_BIND_EVENT(ImGUILayer::OnMouseButtonReleasedEvent));
		dispatcher.Dispatch<MouseMovedEvent>(GE_BIND_EVENT(ImGUILayer::OnMouseMovedEvent));
		dispatcher.Dispatch<MouseScrolledEvent>(GE_BIND_EVENT(ImGUILayer::OnMouseScrolledEvent));
		dispatcher.Dispatch<KeyPressedEvent>(GE_BIND_EVENT(ImGUILayer::OnKeyPressedEvent));
		dispatcher.Dispatch<KeyReleasedEvent>(GE_BIND_EVENT(ImGUILayer::OnKeyReleasedEvent));
		dispatcher.Dispatch<KeyTypedEvent>(GE_BIND_EVENT(ImGUILayer::OnKeyTypedEvent));
		dispatcher.Dispatch<WindowResizeEvent>(GE_BIND_EVENT(ImGUILayer::OnWindowResizeEvent));
	}

	bool ImGUILayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = true;

		return false;
	}

	bool ImGUILayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = false;\
			
		return false;
	}

	bool ImGUILayer::OnMouseMovedEvent(MouseMovedEvent e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(e.GetX(), e.GetY());

		return false;
	}

	bool ImGUILayer::OnMouseScrolledEvent(MouseScrolledEvent e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheel += e.GetOffsetY();
		io.MouseWheelH += e.GetOffsetX();

		return false;
	}

	bool ImGUILayer::OnKeyPressedEvent(KeyPressedEvent e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.GetKeyCode()] = true;

		io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
		io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
		io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
		io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];

		return false;
	}

	bool ImGUILayer::OnKeyReleasedEvent(KeyReleasedEvent e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.GetKeyCode()] = false;

		return false;
	}
	bool ImGUILayer::OnKeyTypedEvent(KeyTypedEvent e)
	{
		ImGuiIO& io = ImGui::GetIO();
		if (e.GetKeyCode() > 0 && e.GetKeyCode() < 0x10000)
		{
			io.AddInputCharacter((unsigned short)e.GetKeyCode());
		}

		return false;
	}

	bool ImGUILayer::OnWindowResizeEvent(WindowResizeEvent e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0,0, e.GetWidth(), e.GetHeight());

		return false;
	}
}