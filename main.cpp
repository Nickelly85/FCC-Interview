#include <iostream>
#include <vector>
#include <random>
#include <map>
#include <chrono>

using namespace std;

int diceAmount = 2; // Global dice amount for easy adjustment of game
int iterations = 10000; // Global iterations for easy adjustment of game

#include "game.h"

int main() {
	game g;

	auto start_time = std::chrono::high_resolution_clock::now(); // Log start time

	g.play();
	
	auto current_time = std::chrono::high_resolution_clock::now(); // Log end time

	std::cout << "Total simulation took " << std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count() << " milliseconds." << std::endl; // Print time it took

	return 0;
}