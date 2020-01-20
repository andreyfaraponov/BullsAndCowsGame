#include <iostream>
#include <string>
#include "main.h"
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
bool AskToPlayAgain();
void PlayGame();
void PrintGameSummary();

FText GetValidGuess();
FBullCowGame BCGame;

int32 main() {
	bool playOneMoreTime = false;
	do
	{
		PrintIntro();
		PlayGame();
		playOneMoreTime = AskToPlayAgain();
	} while (playOneMoreTime);

	return 0;
}

void PlayGame()
{
	BCGame.Reset();
	int32 maxTries = BCGame.GetMaxTries();

	while (BCGame.GetCurrentTry() <= BCGame.GetMaxTries() && !BCGame.IsGameWon()) {
		FText guess = GetValidGuess();
		FBullCowCount bullCowCount = BCGame.SubmitValidGuess(guess);
		std::cout << "Bulls = " << bullCowCount.bulls << " ";
		std::cout << ". Cows = " << bullCowCount.cows;
		std::cout << std::endl;
	}
	PrintGameSummary();
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon()) {
		std::cout << "Well done - You Win!" << std::endl;
	}
	else {
		std::cout << "Better luck next time!" << std::endl;
	}
}

void PrintIntro() {
	std::cout << "Welcome to Bulls and Cows, a fun game." << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?" << std::endl;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again? ";
	FText Response = "";
	std::getline(std::cin, Response);
	std::cout << "First char: " << Response[0];
	return Response[0] == 'y' || Response[0] == 'Y';
}

FText GetValidGuess() {
	FText guess = "";
	EGuessStatus status = EGuessStatus::INVALID_VALUE;
	do {
		int32 currentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << currentTry << ". Enter Guess: ";
		std::getline(std::cin, guess);

		status = BCGame.CheckGuessValidity(guess);

		switch (status)
		{
		case EGuessStatus::NOT_ISOGRAM:
			std::cout << "Please enter a word without repeating letters.";
			break;
		case EGuessStatus::WRONG_LENGTH:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.";
			break;
		case EGuessStatus::NOT_LOWERCASE:
			std::cout << "Please enter all lowercase letters.";
			break;
		default:
			break;
		}
		std::cout << std::endl;
	} while (status != EGuessStatus::OK);

	return guess;
}
