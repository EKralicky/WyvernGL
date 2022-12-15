#pragma once

#include "GameWindow.h"
#include "Wyvern/render/Camera.h"
#include "Wyvern/render/Renderer.h"

#include "event/Event.h"
#include "event/MouseEvent.h"
#include "event/ApplicationEvent.h"
#include "event/KeyEvent.h"


namespace Wyvern {

	class Application
	{
	private:
		Renderer* m_renderer;
		Camera* m_camera;
		GameWindow* m_gameWindow;
		bool m_running;
		std::unordered_set<int> m_repeatingKeyInputs; // Keeps a list of keys that will need to be checked every frame such as movement keys

		void handleRepeatingKeyInputs();
		bool onWindowClose(WindowCloseEvent& e);
		bool onMouseMoved(MouseMovedEvent& e);
		bool onKeyPressed(KeyPressedEvent& e);
		bool onKeyReleased(KeyReleasedEvent& e);
		 

	public:
		Application();
		~Application();
		void run();
		void onEvent(Event& e);
	};

	Application* createApplication();
}