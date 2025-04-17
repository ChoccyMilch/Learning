#include <iostream>
#include <thread> // Include this header for std::this_thread
#include <chrono> // Include this header for std::chrono

using namespace std;

enum TrafficLightState { RED, GREEN, YELLOW }; // Enum for the states of the traffic light.

// Fucntion which takes the state and uses the corresponding switch statement to print the correct case to the console.
void printTrafficLightState(TrafficLightState state) {

    switch (state) {
        case RED:
            cout << "State: red" << endl;
            break;
        case GREEN:
            cout << "State: green" << endl;
            break;
        case YELLOW:
            cout << "State: yellow" << endl;
            break;
        default:
            cout << "Invalid state" << endl;
            break;
    }
    this_thread::sleep_for(std::chrono::seconds(2)); // Sleep for 2 seconds. This adds a delay so that everything isnt spammed to the console at once.
}

// Function which iterates through the enum based on the current state of the enum.
TrafficLightState getNextState(TrafficLightState currentState) {
	switch (currentState) {
	case RED:
		return GREEN;
	case GREEN:
		return YELLOW;
	case YELLOW:
		return RED;
	default:
		return RED; // Default to RED if an invalid state is encountered.
	}
}

int main() {
	TrafficLightState currentState = RED; // Start with RED state.
    
    for (int i = 0; i < 10; i++) {
        printTrafficLightState(currentState);
	currentState = getNextState(currentState); // Get the next state.
    }

	return 0;
}



