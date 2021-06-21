//
// Created by Magda on 17.02.2021.
//

#include "functions.h"

std::string str_i(int x)
{
	std::stringstream out;
	out << x;
	return out.str();
}

std::string DoubleToString(double a)
{
	std::ostringstream temp;
	temp << a;
	return temp.str();
}

void shuffleArray (int arr[], int n){
	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::mt19937 mt_rand(seed);
	std::uniform_int_distribution<int> intDist(0, n-1);
	for (int i = 0; i < n; i++){
		int temp = arr[i];
		int randomIndex = intDist(mt_rand);
		arr[i] = arr[randomIndex];
		arr[randomIndex] = temp;
	}
}

void copyArray (int arr[], int copy[], int n){
	for (int i = 0; i < n; i++){
		copy[i] = arr[i];
	}
}
