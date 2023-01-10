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
		std::unique_ptr<GameWindow> m_gameWindow;
		std::unique_ptr<Renderer> m_renderer;
		std::unique_ptr<Player> m_player;
		std::queue<Event*> eventQueue;

		bool onWindowClose(WindowCloseEvent& e);
		bool onMouseMoved(MouseMovedEvent& e);
		bool onKeyPressed(KeyPressedEvent& e);
		bool onKeyReleased(KeyReleasedEvent& e);
		void processEvents();
		void processInput();

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
	};

	Application* createApplication();
}