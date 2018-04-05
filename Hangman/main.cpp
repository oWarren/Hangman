#include <iostream>
#include <random>
#include <chrono>
#include <conio.h>
#include <windows.h>
#include <cstring>
#include <time.h>

void MassiveHangmanWin();
void MassiveHangmanLose();
void StartScreen();
void HangmanTemplate();
void ThemeTemplate();
void DifficultyTemplate();
void YouWin();
void YouLose();

int main()
{
	bool exitGame = false;
	bool mainLoop = true;
	bool* guessedCorrectly = { false };


	int wordLength = 0;
	char guessedLetter = 0;
	char word[30] = { 0 };
	srand((unsigned int)time(NULL));                                                                                 // Seeding the random 
	char theme = 0;
	char difficulty = 0;

	bool playAgainLoop = true;                                                                                       // Initialisation of the play again loop
	bool themeLoop;
	bool difficultyLoop;
	do
	{
		mainLoop = true;
		wordLength = 0;
		guessedLetter = 0;
		word[0] = { 0 };
		theme = 0;
		difficulty = 0;

		playAgainLoop = true;
		char x = 0;
		bool firstPageLoop;																					         // initialisation of the first page loop


		do
		{

			StartScreen();                                                                                           // Calls start_screen() void function
			x = _getch();                                                                                            // Reads in a character
			std::cout << "\n\t\tYou selected : " << x;                                                               // Tells you what character you inputted
			Sleep(1000);                                                                                             // A pause
			firstPageLoop = false;                                                                                   // Returns here if a valid letter is not inputted
			switch (x)                                                                                               // Start of switch statement for playing the game
			{
			case 'y' | 'Y':                                                                                          // If yes is selected then continue
			{
				continue;
				break;
			}
			case 'n' | 'N':                                                                                          // If no exit firstPageLoop and exit game is also true thus exiting the game
			{
				playAgainLoop = false;
				exitGame = true;
				break;
			}
			default:
			{
				std::cout << "\n\t    Please press a valid key\n";                                                   // If a valid key is not inputted then loop runs again
				firstPageLoop = true;
				Sleep(1000);                                                                                         // A pause
				break;
			}
			}
		} while (firstPageLoop == true);                                                                             // first_page_loop runs until the loop returns false

		if (exitGame == false)
		{

			themeLoop = true;

			while (themeLoop == true)
			{
				themeLoop = false;

				int currentWord = rand() % 5;                                                                        // Randomly selects a number between 1 and 5

				HangmanTemplate();                                                                                   // Calls hangman_template void function
				ThemeTemplate();                                                                                     // Calls theme_template void function
				theme = _getch();                                                                                    // Reads in a character
				std::cout << "\t\t You selected : " << theme;                                                        // Prints out the character the player selecter
				Sleep(1000);                                                                                         // A pause

				switch (theme)                                                                                       // Start of a switch statement for theme
				{
				case 'a':                                                                                            // If a is selected the themem animals has been selected
				{
					do
					{
						HangmanTemplate();                                                                           // Calls hangman_template void function
						DifficultyTemplate();                                                                        // Calls difficulty_template void function

						difficultyLoop = false;
						char animalEasy[5][20] = { "cat", "dog" , "rat", "pig", "ant" };
						char animalMedium[5][30] = { "horse", "tiger", "whale","mouse","snake" };                    // Arrays storing varied words depending on difficulty
						char animalHard[5][40] = { "dolphin", "leopard", "giraffe","narwhal", "unicorn" };

						difficulty = _getch();                                                                       // Reads in a character
						std::cout << "\t\t You selected : " << difficulty;                                           // Prints out the character the player selected
						Sleep(1000);                                                                                 // A pause

						switch (difficulty)                                                                          // Start of switch statement for difficulty
						{
						case 'e':                                                                                    // If e is inputted
						{
							strcpy(word, animalEasy[currentWord]);                                                   // Selects a word randomly from "animal_easy" and copies the array
							break;                                                                                   // to the array "word"
						}
						case 'm':                                                                                    // If m is inputted
						{
							strcpy(word, animalMedium[currentWord]);                                                 // Selects a word randomly from "animal_medium" and copies the array
							break;                                                                                   // to the array "word"
						}
						case 'h':                                                                                    // If h is inputted
						{
							strcpy(word, animalHard[currentWord]);                                                   // selects a word randomly from "animal_hard" and copies the array
							break;                                                                                   // to the array "word"
						}
						default:                                                                                     // If an invalid letter is inputted
						{
							std::cout << " \n\t\t please input a valid letter\n";                                    // Tells the player they have inputted an invalid letter
							Sleep(1000);                                                                             // A pause
							difficultyLoop = true;
						}
						}
					} while (difficultyLoop == true);                                                                // difficulty_loop runs until the loop returns as false
				} break;

				case'f':
				{
					do
					{
						HangmanTemplate();
						DifficultyTemplate();

						difficultyLoop = false;
						char filmEasy[5][20] = { "seven", "cars" , "thor", "twins", "jaws" };
						char filmMedium[5][30] = { "scream", "dodgeball", "hancock", "psycho", "wanted" };
						char filmHard[5][40] = { "ratatouille", "transformers", "inception","gladiator", "interstellar" };

						difficulty = _getch();
						std::cout << "\t\t You selected : " << difficulty;
						Sleep(1000);

						switch (difficulty)
						{

						case 'e':
						{
							strcpy(word, filmEasy[currentWord]);
							break;
						}
						case 'm':
						{
							strcpy(word, filmMedium[currentWord]);
							break;
						}
						case 'h':
						{
							strcpy(word, filmHard[currentWord]);
							break;
						}
						default:
						{
							std::cout << " \n\t\t please input a valid letter\n";
							Sleep(1000);
							difficultyLoop = true;
						}
						}
					} while (difficultyLoop == true);

					break;
				}
				case'g':
				{
					do
					{
						HangmanTemplate();
						DifficultyTemplate();

						difficultyLoop = false;
						char gamesEasy[5][20] = { "doom", "xcom" , "fear", "portal", "dayz" };
						char gamesMedium[5][30] = { "minecraft", "overwatch", "bioshock", "superhot", "titanfall" };
						char gamesHard[5][40] = { "counterstrike", "wolfenstein", "civilization","hearthstone", "bloodbourne" };

						difficulty = _getch();
						std::cout << "\t\t You selected : " << difficulty;
						Sleep(1000);

						switch (difficulty)
						{

						case 'e':
						{
							strcpy(word, gamesEasy[currentWord]);
							break;
						}
						case 'm':
						{
							strcpy(word, gamesMedium[currentWord]);
							break;
						}
						case 'h':
						{
							strcpy(word, gamesHard[currentWord]);
							break;
						}
						default:
						{
							std::cout << " \n\t\t please input a valid letter\n";
							Sleep(1000);
							difficultyLoop = true;
						}
						}
					} while (difficultyLoop == true);
					break;
				}
				case'c':
				{
					do
					{
						HangmanTemplate();
						DifficultyTemplate();

						difficultyLoop = false;
						char countriesEasy[5][20] = { "cuba", "fiji" , "china", "chile", "qatar" };
						char countriesMedium[5][30] = { "romania", "slovakia", "ukraine", "Uruguay", "australia" };
						char countriesHard[5][40] = { "switzerland", "madagascar", "luxembourg","Kyrgyzstan", "Azerbaijan" };

						difficulty = _getch();
						std::cout << "\t\t You selected : " << difficulty;
						Sleep(1000);

						switch (difficulty)
						{

						case 'e':
						{
							strcpy(word, countriesEasy[currentWord]);
							break;
						}
						case 'm':
						{
							strcpy(word, countriesMedium[currentWord]);
							break;
						}
						case 'h':
						{
							strcpy(word, countriesHard[currentWord]);
							break;
						}
						default:
						{
							std::cout << " \n\t\t please input a valid letter\n";
							Sleep(1000);
							difficultyLoop = true;
						}
						}
					} while (difficultyLoop == true);
					break;
				}
				default:
				{
					std::cout << "\n \t\t please enter a valid letter\n";
					Sleep(1000);
					themeLoop = true;
				}
				}
			}

			system("CLS");                                                                                           // Clears the screen

			wordLength = strlen(word);                                                                               // Makes word_length store the array length of the array "word"
			guessedCorrectly = new bool[wordLength];                                                                 // Creates a number of boolean values for the number of letters in the word
			char alreadyGuessedLetters[20] = { 0 };                                                                  // Initialisation of an array that stores already inputted letters
			bool ifLetterIsCorrect = false;                                                                          // Boolean value that checks if the letter is correct
			bool ifLetterHasBeenUsed = false;                                                                        // Boolean value that checks if the letter has been used
			int characterCounter = 0;                                                                                // This counts the number of incorrect guessed starting at 0
			guessedLetter = ' ';

			do                                                                                                       // Start of loop
			{
				ifLetterIsCorrect = false;
				ifLetterHasBeenUsed = false;
				if (characterCounter <= 5)                                                                           // If character counter is less than or equal to 5 then continue
				{
					std::cout << "**********************************************************";
					std::cout << "\n\t\t\t\t   You have " << 6 - characterCounter << " guesses left\n";              // Prints out how many guessed the player has remaining
					if (characterCounter == 0)
					{
						std::cout << "\n\n\n\n\n        ";
					}
					if (characterCounter == 1)
					{
						std::cout << "\n\n\n\n\n/|\\     ";
					}
					if (characterCounter == 2)
					{
						std::cout << "\n |\n |\n |\n |\n/|\\     ";
					}
					if (characterCounter == 3)
					{
						std::cout << "  _____\n |/\n |\n |\n |\n/|\\     ";
					}
					if (characterCounter == 4)
					{
						std::cout << "  _____\n |/   |\n |   (_)\n |\n |\n/|\\     ";
					}
					if (characterCounter == 5)
					{
						std::cout << "  _____\n |/   |\n |   (_)\n |   /|\\\n |\n/|\\     ";

					}
					if (characterCounter == 6)
					{
						std::cout << "  _____\n |/   |\n |   (_)\n |   /|\\\n |   / \\\n/|\\     ";
					}

					for (int i = 0; i < wordLength; i++)                                                             // Loop goes through each position in the array and checks the character against other
					{                                                                                                // characters in the array 
						if (guessedCorrectly[i] == true)                                                             // If a letter is correct it will print the letter in its correct position
						{
							std::cout << " " << word[i] << " ";
						}
						else                                                                                         // If a letter is not correct then print an underscore
						{
							std::cout << " _ ";
						}
					}

					std::cout << "\n\n";
					std::cout << "  Guessed letters\t\t\tGuess a letter\n";

					for (int i = 0; i < 20; i++)
					{
						std::cout << alreadyGuessedLetters[i] << " ";                                                // Prints letters out already guessed
					}

					std::cout << "";
					guessedLetter = _getch();                                                                        // Reads in a character
					std::cout << "Letter guessed : " << guessedLetter << "\n";                                       // Prints out letter guessed
					Sleep(1000);                                                                                     // A pause

					bool isValidChar = false;                                                                        // Initialisation that tests if a char is valid

					for (int i = 97; i < 123; i++)                                                                   // Creating an array of  lower case characters
					{
						if (guessedLetter == (char)i)                                                                // If the guessed letter is a lower case letter 
						{
							isValidChar = true;                                                                      // This then continues with the program and breaks the loop
							break;
						}
					}

					if (isValidChar == false)                                                                        // If the guessed letter is not lower case then 
					{
						std::cout << "\t\tThis character is invalid.\n\n";                                           // Inform the player that the character is invalid
						std::cout << "\t\tCaps lock may be turned on";
						Sleep(2000);                                                                                 // A pause
						system("CLS");                                                                               // Clears the screen
						continue;
					}

					int length = strlen(alreadyGuessedLetters);                                                      // Creation of a variable that stores the length of the array of "already_guessed_letters"

					for (int i = 0; i < length; i++)
					{
						if (alreadyGuessedLetters[i] == guessedLetter)                                               // If the "guessed_letter" is equal to any character in the "already_guessed_letters" array
						{
							ifLetterHasBeenUsed = true;                                                              // Then "if_letter_has_been_used" is true 
							std::cout << "\t   This letter has already been guessed\n";                              // This prints out a message for the player 
							Sleep(1000);                                                                             // A pause
						}
					}

					if (ifLetterHasBeenUsed == false)                                                                // If the "guessed_letter" is equal to no character in the "already_guessed_letters" array
					{
						alreadyGuessedLetters[length] = guessedLetter;                                               // Then add the character from "guessed_letter" to the array, "already_guessed_letters"
						alreadyGuessedLetters[length + 1] = 0;                                                       // Then add one to the poisition of the writing array
					}

					for (int i = 0; i < wordLength; i++)
					{
						if (word[i] == guessedLetter)                                                                // If "guessed_letter" = a letter in the "word" array
						{
							guessedCorrectly[i] = true;
							ifLetterIsCorrect = true;                                                                // Then letter is correct
						}
					}

					if (!ifLetterIsCorrect && !ifLetterHasBeenUsed)                                                  // If the letter is incorrect or has been used but still valid
					{
						characterCounter++;                                                                          // The "character_counter" increases by one
					}

					int counter = 0;

					for (int i = 0; i < wordLength; i++)
					{
						if (guessedCorrectly[i] == true)                                                             // If guessed_correctly[i] is true then add one to the counter
						{
							counter++;                                                                               // Once the counter reaches the number of letters in the word then the player has won
						}
					}

					printf("\n");
					system("CLS");

					if (counter == wordLength)                                                                       // If the counter reaches the number of letters in the word 
					{
						MassiveHangmanWin();                                                                         // Calls MassiveHangmanWin() void function
						Sleep(3000);                                                                                 // A pause for 3 seconds
						std::cout << "\t\tYou saved this mans life";
						Sleep(2000);
						YouWin();                                                                                    // Calls YouWin() void function
						std::cout << word;                                                                           // Prints out the word you guessed correctly
						Sleep(3000);
						mainLoop = false;                                                                            // Then exit main_loop
					}


				}
				else if (characterCounter > 5)
				{
					MassiveHangmanLose();                                                                            // Calls MassiveHangmanLose() void function
					Sleep(3000);                                                                                     // A pause for 3 seconds
					std::cout << "\n\t\tYou let this man die";
					Sleep(2000);
					YouLose();                                                                                       // Calls YouLose() void function
					std::cout << word;                                                                               // Prints out the word you guessed incorrectly
					Sleep(3000);
					mainLoop = false;                                                                                // then exit Main_loop
				}
			} while (mainLoop == true);

			bool continueLoop = false;                                                                               // Initalisation of a boolean value
			do
			{
				system("CLS");                                                                                       // Clears the screen
				std::cout << "Would you like to play again? y/n\n";                                                  // Asks player whether they wish to play again
				continueLoop = false;
				char continuu = _getch();                                                                            // Reads in a character
				std::cout << "You selected : " << continuu;                                                          // Prints out the character you inputted
				Sleep(1500);                                                                                         // Pauses for 1.5 seconds

				switch (continuu)                                                                                    // Start of switch statement 
				{
				case 'y':                                                                                            // If yes is selected 
				{
					playAgainLoop = true;                                                                            // This will make the play again loop = true thus returning to the start of the game
					break;
				}
				case 'n':                                                                                            // If no is selected 
				{
					std::cout << "\n";
					playAgainLoop = false;                                                                           // This will make the play again loop = false thus exiting the loop 
					break;
				}
				default:                                                                                             // If the valid input is not a valid character
				{
					std::cout << "\nYou have inputted an invalid letter";                                            // Prints out an error message
					Sleep(1000);                                                                                     // Pauses screen for a second
					continueLoop = true;                                                                             // continuu loop = true thus making the loop run until a valid character is inputted
					break;
				}
				}
			} while (continueLoop == true);
			delete guessedCorrectly;
		}
	} while (playAgainLoop == true);


	return 0;
}

void MassiveHangmanLose()
{
	system("CLS");
	std::cout << "**********************************************************\n";
	std::cout << "___________.._______\n";
	std::cout << "| ._________))______|\n";
	std::cout << "| | / /     ||.-''.\n";
	std::cout << "| |/ /      |/ _  \\\n";
	std::cout << "| | /       || `/,|\n";
	std::cout << "| |/       (\\`_.'\n";
	std::cout << "| |       .-`--'.\n";
	std::cout << "| |      /Y.   .Y\\\\\n";
	std::cout << "| |     // |   |  \\\\\n";
	std::cout << "| |    //  |   |   \\\\\n";
	std::cout << "| |   //   | . |    \\\\\n";
	std::cout << "| |  ')    |   |     (`\n";
	std::cout << "| |        ||'||\n";
	std::cout << "| |        || ||\n";
	std::cout << "| |        || ||\n";
	std::cout << "| |        || ||\n";
	std::cout << "| |        || ||\n";
	std::cout << "| |_______/_|_|_\\_____\n";
	std::cout << "| |____________________| |\n";
	std::cout << "| |                    | |\n";
	std::cout << "| |                    | |\n";
	std::cout << "| |                    | |\n";
	Sleep(1000);
	system("CLS");
	std::cout << "**********************************************************\n";
	std::cout << "___________.._______\n";
	std::cout << "| ._________))______|\n";
	std::cout << "| | / /     ||\n";
	std::cout << "| |/ /      ||\n";
	std::cout << "| | /       ||.-''.\n";
	std::cout << "| |/        |/ _  \\\n";
	std::cout << "| |         || `/,|\n";
	std::cout << "| |         (\\`_.'\n";
	std::cout << "| |        .-`--'.\n";
	std::cout << "| |       /Y.   .Y\\\\\n";
	std::cout << "| |      // |   |  \\\\\n";
	std::cout << "| |     //  |   |   \\\\\n";
	std::cout << "| |    //   | . |    \\\\\n";
	std::cout << "| |   ')    |   |     (`\n";
	std::cout << "| |         ||'||\n";
	std::cout << "| |         || ||\n";
	std::cout << "| |         || ||\n";
	std::cout << "| |_______  || ||  ____\n";
	std::cout << "| |_______  || ||  ____| |\n";
	std::cout << "| |      \\\\/_| |_\\     | |\n";
	std::cout << "| |       \\\\           | |\n";
	std::cout << "| |        \\\\          | |\n";
}
void MassiveHangmanWin()
{
	system("CLS");
	std::cout << "**********************************************************\n";
	std::cout << "\n\n\n\n";
	std::cout << "            ____\n";
	std::cout << "           / _ _ \\\n";
	std::cout << "           | ^ ^ |\n";
	std::cout << "           \\  _  /\n";
	std::cout << "           .-`--'.\n";
	std::cout << "          /Y.   .Y\\\\\n";
	std::cout << "         // |   |  \\\\\n";
	std::cout << "        //  |   |   \\\\\n";
	std::cout << "       //   | . |    \\\\\n";
	std::cout << "      ')    |   |     (`\n";
	std::cout << "            ||'||\n";
	std::cout << "            || ||\n";
	std::cout << "            || ||\n";
	std::cout << "            || ||\n";
	std::cout << "            || ||\n";
	std::cout << "           / | | \\\n";
	std::cout << "           `-' `-'\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "";
	Sleep(1000);
	system("CLS");
	std::cout << "**********************************************************\n";
	std::cout << "\n\n\n\n";
	std::cout << "            ____\n";
	std::cout << "      .)   / _ _ \\   (.\n";
	std::cout << "       \\\\  | ^ ^ |  //\n";
	std::cout << "        \\\\ \\  _  / //\n";
	std::cout << "         \\\\.-`--'.//\n";
	std::cout << "          \\\\.   .//\n";
	std::cout << "            |   |\n";
	std::cout << "            |   |\n";
	std::cout << "            | . |\n";
	std::cout << "            |   |\n";
	std::cout << "            ||'||\n";
	std::cout << "            || ||\n";
	std::cout << "            || ||\n";
	std::cout << "            || ||\n";
	std::cout << "            || ||\n";
	std::cout << "           / | | \\\n";
	std::cout << "           `-' `-'\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "";
}
void StartScreen()
{
	system("CLS");

	std::cout << "**********************************************************" << "\n";
	std::cout << "  _____" << "\n";
	std::cout << " |/   |" << "\n";
	std::cout << " |   (_)" << "\n";
	std::cout << " |   /|\\ " << "\n";
	std::cout << " |   / \\ " << "\n";
	std::cout << "/|\\    \tHangman" << "\n";
	std::cout << "               By Oliver Warren" << "\n\n\n";

	std::cout << "\tDo you want to play hangman? y/n";
}
void HangmanTemplate()
{
	system("CLS");

	std::cout << "**********************************************************" << "\n";
	std::cout << "  _____" << "\n";
	std::cout << " |/   |" << "\n";
	std::cout << " |   (_)" << "\n";
	std::cout << " |   /|\\ " << "\n";
	std::cout << " |   / \\ " << "\n";
	std::cout << "/|\\     ";
}
void ThemeTemplate()
{
	std::cout << "Themes\n";
	std::cout << "\t\t Please choose a theme\n\n";                                                                    // Asks which theme the player would like to select
	std::cout << "\t\t [a]nimals\n";
	std::cout << "\t\t [f]ilms\n";
	std::cout << "\t\t [g]ames\n";
	std::cout << "\t\t [c]ountries\n";
}
void DifficultyTemplate()
{
	std::cout << "Difficulty\n";
	std::cout << "\t\t Please choose a difficulty\n\n";
	std::cout << "\t\t [e]asy\n";
	std::cout << "\t\t [m]edium\n";
	std::cout << "\t\t [h]ard\n";
}
void YouWin()
{
	system("CLS");
	std::cout << "**********************************************************\n";
	std::cout << "\n\n\n\n\n\t\t       (^_^)\n\t    You guessed the word correctly!\n\t\t       You Win";
	std::cout << "\n\t        The word was : ";
}
void YouLose()
{
	system("CLS");
	std::cout << "**********************************************************\n";
	std::cout << "\n\n\n\n\n\t\t       (x_x)\n\t  You guessed the word incorrectly!\n\t\t      You lose";
	std::cout << "\n\t        The word was : ";
}