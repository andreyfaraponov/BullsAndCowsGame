#pragma once
#include <iostream>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 bulls = 0;
	int32 cows = 0;
};

enum class EGuessStatus {
	INVALID_VALUE,
	OK,
	NOT_ISOGRAM,
	WRONG_LENGTH,
	NOT_LOWERCASE
};

class FBullCowGame {
public:
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	EGuessStatus CheckGuessValidity(FString) const;
	bool IsGameWon() const;

	FBullCowGame();
	~FBullCowGame();
	FBullCowGame(FBullCowGame&);
	FBullCowGame& operator=(const FBullCowGame&);

	void Reset();

	FBullCowCount SubmitValidGuess(FString);
	


	// Please Try and ignore this and focus on the interface above ^^
private:
	int32 _currentTry = 1;
	int32 _maxTries = 5;
	bool b_GameIsWon = false;
	FString hiddenWord;
	   
	bool IsIsogram(FString) const;
	bool IsUppercase(FString) const;
};