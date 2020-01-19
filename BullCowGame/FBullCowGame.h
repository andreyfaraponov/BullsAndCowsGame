#pragma once
#include <iostream>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 bulls = 0;
	int32 cows = 0;
};

class FBullCowGame {
public:
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	FBullCowGame();
	~FBullCowGame();
	FBullCowGame(FBullCowGame&);
	FBullCowGame& operator=(const FBullCowGame&);

	void Reset();
	bool CheckGuessValidity(FString);
	FBullCowCount SubmitGuess(FString);
	


	// Please Try and ignore this and focus on the interface above ^^
private:
	int32 _currentTry = 1;
	int32 _maxTries = 5;
	bool isGameWon = false;
	FString hiddenWord;

};