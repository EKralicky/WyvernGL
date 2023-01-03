#pragma once

#include "Wyvern.h"
#include "event/Event.h"

namespace Wyvern {

	static const float WINDOW_WIDTH = 1920;
	static const float WINDOW_HEIGHT = 1080;

	struct GameWindowConfiguration {
		const char* windowName;
		int windowWidth;
		int windowHeight;

		// Default config
		GameWindowConfiguration(
			const char* windowName = "WyvernGL [TEST]",
			float windowWidth = WINDOW_WIDTH,
			float windowHeight = WINDOW_HEIGHT)
			: windowName(windowName), windowWidth(windowWidth), windowHeight(windowHeight)
		{
		}
	};

	class GameWindow {
		using EventCallbackFn = std::function<void(Event&)>;

	private:
		GLFWwindow* m_window;
		float m_deltaTime = 0; // Time between frames (current frame time - last frame time)
		float m_lastFrameTime = 0; // Time it took to render the last frame

		struct WindowData {
			const char* windowName;
			int windowWidth;
			int windowHeight;
			bool verticalSyncEnabled;

			EventCallbackFn eventCallbackFn;
		};

		WindowData windowData;

	public:
		GameWindow(const GameWindowConfiguration& config = GameWindowConfiguration());
		~GameWindow();

		void initWindow(const GameWindowConfiguration& config);
		void updateDeltaTime();
		void setVSync(bool enabled);
		void onUpdate();
		void initGlew();
		void setCursorMode(int mode);
		inline void setEventCallback(const EventCallbackFn& callback) { windowData.eventCallbackFn = callback; }
		inline GLFWwindow*& getGLFWWindow() {
			return m_window;
		}
		inline float deltaTime() {
			return m_deltaTime;
		}


	};
}


