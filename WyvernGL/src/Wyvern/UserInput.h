#pragma once
#include "Wyvern.h"
#include "Core.h"


namespace Wyvern {

	class UserInput {
	public:
		static std::map<int, std::function<void>>& keyMap;
		static std::map<int, int>& directKeyMap;
		// Polling input checks
		static bool isKeyPressed(int key);
		static bool isMouseButtonDown(int mouseButton);
		// Reset & set default key bindings
		static void setDefaultKeyBindings() {
			keyMap.insert_or_assign(GLFW_KEY_W, BIND_VOID_FN_NOPARAM(Application::get().getCamera(), Camera::moveForward));
			directKeyMap.insert_or_assign("WYVERN_MV_FORWARD", )
		}
		static void setKeyBinding(int key, std::function<void> fnCallback);
		static void removeKeyBinding(int key);

	};
}