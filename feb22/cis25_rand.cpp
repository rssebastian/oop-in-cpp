#include "cis25_rand.h"
#include <random>
#include <chrono>
#include <ctime>

Cis25Rand::Cis25Rand(){
	auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
	mt_rand.seed(seed);
}

void Cis25Rand::reseed(){
	auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
	mt_rand.seed(seed);
}

// returns a random int in range (min, max), 
// inclusive of min, not inclusive of max
int Cis25Rand::getInt(int min, int max) {
	uniform_int_distribution<int> dist(min, max);
	return dist(mt_rand);

}

// returns a random double in range (min, max)
double Cis25Rand::getDouble(double min, double max) {
	uniform_real_distribution<double> dist(min, max);
	return dist(mt_rand);
}
