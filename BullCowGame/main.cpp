#include <iostream>
#include <string>
#include "main.h"

void PrintIntro();
bool AskToPlayAgain();

std::string GetGuess();

int main() {
	PrintIntro();
	bool playOneMoreTime = false;
	do
	{
		PlayGame();
		playOneMoreTime = AskToPlayAgain();
	} while (playOneMoreTime);
	;

	return 0;
}

void PlayGame()
{
	constexpr int guess_times = 1;
	for (size_t i = 0; i < guess_times; i++)
	{
		std::cout << "You guess was " << GetGuess() << std::endl;
	}
}

void PrintIntro() {
	constexpr int WORLD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun game." << std::endl;
	std::cout << "Can you guess the " << WORLD_LENGTH;
	std::cout << " letter isogram I'm thinking of?" << std::endl;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again? ";
	std::string Response = "";
	std::getline(std::cin, Response);
	std::cout << "First char: " << Response[0];
	return Response[0] == 'y' || Response[0] == 'Y';
}

std::string GetGuess() {
	std::string guess;
	std::cout << "Enter Guess: ";
	std::getline(std::cin, guess);
	return guess;
}
