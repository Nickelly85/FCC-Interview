#include <iostream>
#include <vector>
#include <random>
#include <map>
#include <chrono>

using namespace std;

int diceAmount = 2;
int iterations = 10000;

#include "game.h"

int main() {
	game g;

	auto start_time = std::chrono::high_resolution_clock::now();

	g.play();
	
	auto current_time = std::chrono::high_resolution_clock::now();

	std::cout << "Total simulation took " << std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count() << " milliseconds." << std::endl;

	return 0;
}