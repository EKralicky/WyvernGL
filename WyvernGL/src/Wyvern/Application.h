#pragma once

#include "GameWindow.h"
#include "Wyvern/render/Camera.h"
#include "Wyvern/render/Renderer.h"

#include "event/Event.h"
#include "event/MouseEvent.h"
#include "event/ApplicationEvent.h"
#include "event/KeyEvent.h"

#include "Wyvern/player/Player.h"

namespace Wyvern {

	class Application
	{
	private:
		Renderer* m_renderer;
		Camera* m_camera;
		Player* m_player;
		GameWindow* m_gameWindow;

		bool onWindowClose(WindowCloseEvent& e);
		bool onMouseMoved(MouseMovedEvent& e);
		bool onKeyPressed(KeyPressedEvent& e);
		bool onKeyReleased(KeyReleasedEvent& e);

		bool m_running;
		inline static Application* s_Instance;

	public:
		Application();
		~Application();
		void run();
		void onEvent(Event& e);

		static Application& get() { return *s_Instance;  };

		GameWindow& getWindow() {
			return *m_gameWindow;
		}

		Camera& getCamera() {
			return *m_camera;
		}
	};

	Application* createApplication();
}