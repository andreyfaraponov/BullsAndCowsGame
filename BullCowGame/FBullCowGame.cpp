#include "FBullCowGame.h"

int32 FBullCowGame::GetMaxTries() const { return _maxTries; }

int32 FBullCowGame::GetCurrentTry() const { return _currentTry; }

bool FBullCowGame::IsGameWon() const { return false; }

FBullCowGame::FBullCowGame()
{
	FBullCowGame::Reset();
}

FBullCowGame::~FBullCowGame()
{
}

FBullCowGame::FBullCowGame(FBullCowGame&)
{
}

FBullCowGame& FBullCowGame::operator=(const FBullCowGame& e)
{
	return *(new FBullCowGame());
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	_maxTries = MAX_TRIES;

	_currentTry = 1;

	const FString HIDDEN_WORLD = "planet";
	hiddenWord = HIDDEN_WORLD;

}

bool FBullCowGame::CheckGuessValidity(FString val1) {
	
	return false;
}

FBullCowCount FBullCowGame::SubmitGuess(FString guess)
{
	++FBullCowGame::_currentTry;
	FBullCowCount bullCowCount;

	int32 hiddenWordLength = hiddenWord.length();
	int32 guessWordLength = guess.length();
	for (int32 i = 0; i < hiddenWordLength; i++) {
		for (int32 j = 0; j < hiddenWordLength && j < guessWordLength; j++) {
			if (guess[j] == hiddenWord[i]) {
				if (i == j) {
					++bullCowCount.bulls;
				}
				else {
					++bullCowCount.cows;
				}
			}
		}
	}

	return bullCowCount;
}
