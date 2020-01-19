#pragma once
#include <iostream>

class FBullCowGame {
public:
	void Reset();
	int GetMaxTries();
	int GetCurrentTry;
	bool IsGameWon();
	bool CheckGuessValidity(std::string);
	


	// Please Try and ignore this and focus on the interface above ^^
private:
	int MyCurrentTry;
	int MyMaxTries;

};