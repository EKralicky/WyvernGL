#pragma once
#include "Wyvern.h"

namespace Wyvern 
{
	class KeyInputHandler {
	private:
		std::vector<int> instantKeyList;
		std::vector<int> repeatingKeyList;


	public:
		KeyInputHandler();
		~KeyInputHandler();

		// bind callbacks that will add functionality to the keys
		void bindRepeatingCallback(); 
		void bindInstantCallback();
		// Add key to both lists if it was pressed
		void onKeyPressed(int key);
		// Remove key from repeatingkeylist when released
		void onKeyReleased(int key);
		// This should be run on repeat in the application class
		// iterates over key lists and calls the callbacks
		// after the instant callback is called for each instant key, the instant key gets removed from the list
		void handleKeyInput();

	};
}
