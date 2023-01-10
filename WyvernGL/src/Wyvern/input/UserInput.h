#pragma once
#include "Wyvern.h"
#include "Wyvern/Core.h"

namespace Wyvern {

	enum class InputAction {
		NONE,
		// POLL_MOVEMENT, // Every frame, this event will be dispatched to poll for player movement
		// Entity Specific
		ENTITY_JUMP,
		ENTITY_CROUCH,
		ENTITY_SPRINT,
		ENTITY_MOVE_FORWARD,
		ENTITY_MOVE_BACKWARD,
		ENTITY_STRAFE_LEFT,
		ENTITY_STRAFE_RIGHT,
		ENTITY_OPEN_INVENTORY,
		// User Specific
		ESCAPE,
		OPEN_DEBUG_MENU,
		VIEW_ONLINE_PLAYERS
	};

	/*class KeyBinding {

	public:
		KeyBinding(int keycode, InputAction action) : m_keycode(keycode), m_actionName(action) {}
		inline int getKeycode() const { return m_keycode; }
		inline InputAction getActionName() const { return m_actionName; }

		bool operator==(const KeyBinding& otherPoint) const
		{
			if (this->getActionName() == otherPoint.getActionName() &&
				this->getKeycode() == otherPoint.getKeycode()) return true;
			else return false;
		}

		struct keybind_hash {
			std::size_t operator()(const KeyBinding& kebind) const {
				return std::hash<int>()(kebind.getKeycode());
			};
		};

	private:
		int m_keycode;
		InputAction m_actionName;
	};*/

	class UserInput {
	public:
		static bool isKeyPressed(int keycode);
		static bool isMouseButtonDown(int mouseButton);
		static void addKeyBinding(InputAction action, int keycode);
		static void removeKeyBinding(InputAction action);
		static void setDefaultKeyBindings();
		static InputAction getKeyBinding(int keycode);
		static int getKeyBinding(InputAction action);
	private:
		inline static std::map<InputAction, int> m_keyBindings; // maps input to GLFW (or our own) keycode
		inline static std::map<InputAction, bool> m_keyMap; // Stores state of each key (pressed or not pressed)
	};
};

#define WYV_KEY_NONE -1

#define WYV_KEY_SPACE              32
#define WYV_KEY_APOSTROPHE         39  /* ' */
#define WYV_KEY_COMMA              44  /* , */
#define WYV_KEY_MINUS              45  /* - */
#define WYV_KEY_PERIOD             46  /* . */
#define WYV_KEY_SLASH              47  /* / */
#define WYV_KEY_0                  48
#define WYV_KEY_1                  49
#define WYV_KEY_2                  50
#define WYV_KEY_3                  51
#define WYV_KEY_4                  52
#define WYV_KEY_5                  53
#define WYV_KEY_6                  54
#define WYV_KEY_7                  55
#define WYV_KEY_8                  56
#define WYV_KEY_9                  57
#define WYV_KEY_SEMICOLON          59  /* ; */
#define WYV_KEY_EQUAL              61  /* = */
#define WYV_KEY_A                  65
#define WYV_KEY_B                  66
#define WYV_KEY_C                  67
#define WYV_KEY_D                  68
#define WYV_KEY_E                  69
#define WYV_KEY_F                  70
#define WYV_KEY_G                  71
#define WYV_KEY_H                  72
#define WYV_KEY_I                  73
#define WYV_KEY_J                  74
#define WYV_KEY_K                  75
#define WYV_KEY_L                  76
#define WYV_KEY_M                  77
#define WYV_KEY_N                  78
#define WYV_KEY_O                  79
#define WYV_KEY_P                  80
#define WYV_KEY_Q                  81
#define WYV_KEY_R                  82
#define WYV_KEY_S                  83
#define WYV_KEY_T                  84
#define WYV_KEY_U                  85
#define WYV_KEY_V                  86
#define WYV_KEY_W                  87
#define WYV_KEY_X                  88
#define WYV_KEY_Y                  89
#define WYV_KEY_Z                  90
#define WYV_KEY_LEFT_BRACKET       91  /* [ */
#define WYV_KEY_BACKSLASH          92  /* \ */
#define WYV_KEY_RIGHT_BRACKET      93  /* ] */
#define WYV_KEY_GRAVE_ACCENT       96  /* ` */
#define WYV_KEY_WORLD_1            161 /* non-US #1 */
#define WYV_KEY_WORLD_2            162 /* non-US #2 */
	    
/* Func keys */
#define WYV_KEY_ESCAPE             256
#define WYV_KEY_ENTER              257
#define WYV_KEY_TAB                258
#define WYV_KEY_BACKSPACE          259
#define WYV_KEY_INSERT             260
#define WYV_KEY_DELETE             261
#define WYV_KEY_RIGHT              262
#define WYV_KEY_LEFT               263
#define WYV_KEY_DOWN               264
#define WYV_KEY_UP                 265
#define WYV_KEY_PAGE_UP            266
#define WYV_KEY_PAGE_DOWN          267
#define WYV_KEY_HOME               268
#define WYV_KEY_END                269
#define WYV_KEY_CAPS_LOCK          280
#define WYV_KEY_SCROLL_LOCK        281
#define WYV_KEY_NUM_LOCK           282
#define WYV_KEY_PRINT_SCREEN       283
#define WYV_KEY_PAUSE              284
#define WYV_KEY_F1                 290
#define WYV_KEY_F2                 291
#define WYV_KEY_F3                 292
#define WYV_KEY_F4                 293
#define WYV_KEY_F5                 294
#define WYV_KEY_F6                 295
#define WYV_KEY_F7                 296
#define WYV_KEY_F8                 297
#define WYV_KEY_F9                 298
#define WYV_KEY_F10                299
#define WYV_KEY_F11                300
#define WYV_KEY_F12                301
#define WYV_KEY_F13                302
#define WYV_KEY_F14                303
#define WYV_KEY_F15                304
#define WYV_KEY_F16                305
#define WYV_KEY_F17                306
#define WYV_KEY_F18                307
#define WYV_KEY_F19                308
#define WYV_KEY_F20                309
#define WYV_KEY_F21                310
#define WYV_KEY_F22                311
#define WYV_KEY_F23                312
#define WYV_KEY_F24                313
#define WYV_KEY_F25                314
#define WYV_KEY_KP_0               320
#define WYV_KEY_KP_1               321
#define WYV_KEY_KP_2               322
#define WYV_KEY_KP_3               323
#define WYV_KEY_KP_4               324
#define WYV_KEY_KP_5               325
#define WYV_KEY_KP_6               326
#define WYV_KEY_KP_7               327
#define WYV_KEY_KP_8               328
#define WYV_KEY_KP_9               329
#define WYV_KEY_KP_DECIMAL         330
#define WYV_KEY_KP_DIVIDE          331
#define WYV_KEY_KP_MULTIPLY        332
#define WYV_KEY_KP_SUBTRACT        333
#define WYV_KEY_KP_ADD             334
#define WYV_KEY_KP_ENTER           335
#define WYV_KEY_KP_EQUAL           336
#define WYV_KEY_LEFT_SHIFT         340
#define WYV_KEY_LEFT_CONTROL       341
#define WYV_KEY_LEFT_ALT           342
#define WYV_KEY_LEFT_SUPER         343
#define WYV_KEY_RIGHT_SHIFT        344
#define WYV_KEY_RIGHT_CONTROL      345
#define WYV_KEY_RIGHT_ALT          346
#define WYV_KEY_RIGHT_SUPER        347
#define WYV_KEY_MENU               348
	 
#define WYV_KEY_LAST               GLFW_KEY_MENU