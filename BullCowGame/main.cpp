#include <iostream>
#include <string>
#include "main.h"
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
bool AskToPlayAgain();

FText GetGuess();
FBullCowGame BCGame;

int32 main() {
	bool playOneMoreTime = false;
	do
	{
		PrintIntro();
		PlayGame();
		// TODO: add a game summary
		playOneMoreTime = AskToPlayAgain();
	} while (playOneMoreTime);

	return 0;
}

void PlayGame()
{
	BCGame.Reset();
	int32 maxTries = BCGame.GetMaxTries();

	std::cout << maxTries << std::endl;
	while (BCGame.GetCurrentTry() <= BCGame.GetMaxTries() && !BCGame.IsGameWon()) {
		FText Guess = GetGuess();

		// SUbmit valid guess to the game
		FBullCowCount bullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls = " << bullCowCount.bulls << " ";
		std::cout << ". Cows = " << bullCowCount.cows << std::endl;
		// Print number of bulls and cows

		std::cout << "You guess was " << Guess;
		std::cout << std::endl;
		BCGame.CheckGuessValidity(Guess);
	}
}

void PrintIntro() {
	constexpr int32 WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?" << std::endl;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again? ";
	FText Response = "";
	std::getline(std::cin, Response);
	std::cout << "First char: " << Response[0];
	return Response[0] == 'y' || Response[0] == 'Y';
}

FText GetGuess() {
	int32 currentTry = BCGame.GetCurrentTry();
	FText guess;
	std::cout << "Try " << currentTry << ". Enter Guess: ";
	std::getline(std::cin, guess);
	return guess;
}
