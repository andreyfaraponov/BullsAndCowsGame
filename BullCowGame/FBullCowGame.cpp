#include "FBullCowGame.h"
#include <map>
#define TMap std::map


int32 FBullCowGame::GetMaxTries() const { return _maxTries; }
int32 FBullCowGame::GetCurrentTry() const { return _currentTry; }
int32 FBullCowGame::GetHiddenWordLength() const {return hiddenWord.length();}
bool FBullCowGame::IsGameWon() const { return b_GameIsWon; }

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
	b_GameIsWon = false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString val1) const {
	
	if (val1.length() != FBullCowGame::GetHiddenWordLength()) {
		return EGuessStatus::WRONG_LENGTH;
	}
	else if (FBullCowGame::IsUppercase(val1)) {
		return EGuessStatus::NOT_LOWERCASE;
	}
	else if (!FBullCowGame::IsIsogram(val1)) {
		return EGuessStatus::NOT_ISOGRAM;
	}

	return EGuessStatus::OK;
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString guess)
{
	++FBullCowGame::_currentTry;
	FBullCowCount bullCowCount;

	int32 wordLength = hiddenWord.length();
	int32 guessWordLength = guess.length();
	for (int32 i = 0; i < wordLength; i++) {
		for (int32 j = 0; j < wordLength && j < guessWordLength; j++) {
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
	b_GameIsWon = bullCowCount.bulls == FBullCowGame::GetHiddenWordLength();
	return bullCowCount;
}

bool FBullCowGame::IsIsogram(FString word) const
{
	if (word.length() <= 1) return true;
	TMap<char, bool> letterSeen;
	for (auto letter : word)
	{
		letter = tolower(letter);
		if (letterSeen[letter]) {
			return false;
		}
		else {
			letterSeen[letter] = true;
		}
	}
	return true;
}

bool FBullCowGame::IsUppercase(FString word) const
{
	if (word.length() <= 1) return true;
	TMap<char, bool> letterSeen;
	for (auto letter : word)
	{
		if (isupper(letter)) {
			return true;
		}
	}
	return false;
}
