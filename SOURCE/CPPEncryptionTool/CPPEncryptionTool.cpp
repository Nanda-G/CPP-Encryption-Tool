// CPP-Encryption-Tool v0.6 | Developed by Liam Z. Charles.
// https://github.com/LiamZC/CPP-Encryption-Tool
//

#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<fstream>
#include<cctype>

using namespace std;

int Quit = 0; // Global exit variable.
int RESET = 0; // Global reset variable.
int key0x = 0, key0y = 0, key0z = 0;
int inpBufferFill = 0;
int inpBufferCount;
char aX = 'a', bY = 'b', cZ = 'c';
char SECURKEY[3];
int CRYPTKEY[3];
string inpBuffer, viewBuffer, cryptBuffer, tempBuffer;

// ifstream loadBuffer; //

void initialize();
void reset();
void encrypt(int);
void inputData();
void viewData();
void terminalIntake();

/*
KEYGEN

aX - 0x - bY - 0a - cZ - 0b
Where,
aX is a+X (a is ASCII 'a' and X is randomly generated integer between 1-25.)
bY is b+Y (b is ASCII 'b' and Y is randomly generated integer between 1-25.)
cZ is c+Z (c is ASCII 'c' and Z is randomly generated integer between 1-25.)
aX, bY, cZ are used to populate the final encryption key.

0x is key0x, which is a randomly generated integer between 1-4. -|
0a is key0y, which is a randomly generated integer between 3-6.  | --> Value ranges were randomly chosen.
0b is key0z, which is a randomly generated integer between 1-6. -|
key0x, key0y, key0z are used in the encryption process.

*/

int main()
{
ToReset:
	Quit = 0;
	RESET = 0;
	system("CLS");
	cout << "\nWelcome to the CPP Encryption Tool | v0.6";
	cout << "\nThis program follows a terminal-input style. Use the 'help' command to see all available commands and their valid parameters.\n\nUse CTRL+C to force quit from the program.\n\n";
	while (Quit < 1) // Keeps the terminal intake running as long as an exit/quit command wasnt entered.
	{
		if (RESET == 1)
		{
			goto ToReset;
		}
		terminalIntake();
	}
	cout << "\n\nPress any key to exit."; // When exit command is entered.
	std::cin.get();
	return 0;
}

void reset()
{
	cout << "\nResetting key values...";
	key0x = 0;
	key0y = 0;
	key0z = 0;
	aX = 'a';
	bY = 'b';
	cZ = 'c';
	for (int i = 0; i < 3; i++)
	{
		CRYPTKEY[i] = 0;
	}
	cout << "\nDone.";
	cout << "\nResetting program values...";
	inpBufferCount = 0;
	inpBufferFill = 0;
	cout << "\nDone.";
	RESET = 1;
	system("CLS");
}

void initialize()
{
	// Initialization function. This function will reset key regeneration and essentially reset the program. Leave as is for now.
	cout << "\nResetting key values...";
	key0x = 0;
	key0y = 0;
	key0z = 0;
	aX = 'a';
	bY = 'b';
	cZ = 'c';
	for (int i = 0; i < 3; i++)
	{
		CRYPTKEY[i] = '?';
	}
	cout << "\nDone.";

	cout << "\nInitializing new values...";
	int rand125 = rand() % 25 + 1;
	key0x = rand() % 4 + 1;
	cout << key0x;
	key0y = rand() % 6 + 3;
	cout << key0y;
	key0z = rand() % 6 + 1;
	cout << key0z;
	aX = aX + rand125;
	cout << aX;
	bY = bY + rand125;
	cout << bY;
	cZ = cZ + rand125;
	cout << cZ;
	cout << "\nDone.";

	cout << "\n\nInitialization complete.\n";
}

void encrypt(int datSET) // datSET specifies whether to initialize and save as a binary file or a regular txt.
{
	if (inpBufferFill == 1)
	{
		if (datSET == 1)
		{
			cout << "\nStarting encryption process...";
			cout << "\n\nGenerating encryption key...";
			cout << "\nInitializing program...";
			initialize();

			cout << "\nCreating secure-key...";
			SECURKEY[0] = aX;
			SECURKEY[1] = bY;
			SECURKEY[2] = cZ;
			CRYPTKEY[0] = key0x;
			CRYPTKEY[1] = key0y;
			CRYPTKEY[2] = key0z;
			cout << "\n";
			for (int i = 0; i < 3; i++)
			{
				cout << SECURKEY[i];
				cout << CRYPTKEY[i];
			}
			cout << "\nDone.";

			cout << "\nInitializing Files...";
			ofstream saveBuffer;
			saveBuffer.open("OUTPUT.dat", fstream::out | fstream::binary);
			cout << "\nDone.\n";
			if (saveBuffer.bad())
			{
				cout << "\nERROR: FAILED TO INITIALIZE FILE.\n\n";
			}
			else
			{
				cout << "\nDone.\n";

				cout << "\nSaving final file as .DAT (Binary file).";

				cout << "\nWriting secure-key...";
				for (int i = 0; i < 3; i++)
				{
					saveBuffer << SECURKEY[i];
					saveBuffer << CRYPTKEY[i];
				}
				cout << "\nDone.";

				cout << "\nStarting encryption...\n\n";
				tempBuffer = inpBuffer;
				for (int i = 0; i < inpBufferCount; i++)
				{
					cout << "\n %% TPkey0x<<" << i;
					tempBuffer[i] = tempBuffer[i] + key0x;
					cout << "\n %% TMkey0y<<" << i;
					tempBuffer[i] = tempBuffer[i] - key0y;
					cout << "\n %% TPkey0z<<" << i;
					tempBuffer[i] = tempBuffer[i] + key0z;
					cout << "\nWriting...";
					saveBuffer << tempBuffer[i];
				}
				cout << "\n\nFinalizing...";
				cout << "\nDone.\n";
				cout << "\n\nData successfully encrypted. Check OUTPUT.txt for encrypted output.\n\n";
			}

			saveBuffer.close();
			datSET = 0;
		}
		else // datSet == 0
		{
			cout << "\nStarting encryption process...";
			cout << "\n\nGenerating encryption key...";
			cout << "\nInitializing program...";
			initialize();

			cout << "\nCreating secure-key...";
			SECURKEY[0] = aX;
			SECURKEY[1] = bY;
			SECURKEY[2] = cZ;
			CRYPTKEY[0] = key0x; // +
			CRYPTKEY[1] = key0y; // - 
			CRYPTKEY[2] = key0z; // +
			cout << "\n";
			for (int i = 0; i < 3; i++)
			{
				cout << SECURKEY[i];
				cout << CRYPTKEY[i];
			}
			cout << "\nDone.";

			cout << "\nInitializing Files...";
			ofstream saveBuffer;
			saveBuffer.open("OUTPUT.txt", fstream::out);
			if (saveBuffer.bad())
			{
				cout << "\nERROR: FAILED TO INITIALIZE FILE.\n\n";
			}
			else
			{
				cout << "\nDone.\n";

				cout << "\nWriting secure-key...";
				for (int i = 0; i < 3; i++)
				{
					saveBuffer << SECURKEY[i];
					saveBuffer << CRYPTKEY[i];
				}
				cout << "\nDone.";

				cout << "\nStarting encryption...\n\n";
				tempBuffer = inpBuffer;
				for (int i = 0; i < inpBufferCount; i++)
				{
					cout << "\n %% TPkey0x<<" << i;
					tempBuffer[i] = tempBuffer[i] + key0x;
					cout << "\n %% TMkey0y<<" << i;
					tempBuffer[i] = tempBuffer[i] - key0y;
					cout << "\n %% TPkey0z<<" << i;
					tempBuffer[i] = tempBuffer[i] + key0z;
					cout << "\nWriting...";
					saveBuffer << tempBuffer[i];
				}
				cout << "\n\nFinalizing...";
				cout << "\nDone.\n";
				cout << "\n\nData successfully encrypted. Check OUTPUT.txt for encrypted output.\n\n";
			}
			saveBuffer.close();
		}
	}

	else
	{
		cout << "\nFATAL ERROR: No data found in inpBuffer.";
		cout << "\n\nUse the inputdata command to enter data for encryption.\n\n";
	}
}

void inputData()
{
	cout << "\n\nYou can input a paragraph or information here for encryption.";
	cout << "\nAfter entering data, enter the encrypt command to start the encryption process.";

	cout << "\n\nStart typing your data, and hit enter when you're done:\n\n\n";
	getline(cin, inpBuffer);
	inpBufferFill = 1;
	inpBufferCount = 0;
	for (int i = 0; i < inpBuffer.size(); i++)
	{
		if (isprint(inpBuffer[i]))
		{
			inpBufferCount++;
		}
	}
	cout << "\nBuffer count = " << inpBufferCount;
	cout << "\n\nData saved. You can use the viewdata command to view what you've input, or use the encrypt command to start the process of encryption.\n";
}

void viewData()
{
	if (inpBufferFill == 1)
	{
		cout << "\nThe screen will be cleared and the data will be shown. Press any key to show data.\n\n";
		std::cin.get();
		system("CLS");
		cout << ">>>\n\n";
		for (int i = 0; i < inpBufferCount; i++)
		{
			cout << inpBuffer[i];
		}
		cout << "\n\n<<<";

		cout << "\n\nPress any key to continue. The screen will be cleared.\n";
		std::cin.get();
		system("CLS");
	}

	else
	{
		cout << "\nFATAL ERROR: INPBUFFER IS EMPTY.";
		cout << "\n\nUse the 'inputdata' command to enter data for viewing.\n\n";
	}
}

void terminalIntake() //This function is the core for the terminal-style input. 
{
Intake:
	char intake[5000]; // Command line intake string.
	int dat = 0;
	cout << "$> ";
	gets_s(intake);
	//The loop in the next line acts according to the 'encrypt' command.
	if (intake[0] == 'e' && intake[1] == 'n' && intake[2] == 'c' && intake[3] == 'r' && intake[4] == 'y' && intake[5] == 'p' && intake[6] == 't')
	{
		//The loop in the next line checks for extra parameters given with the 'encrypt' command.
		if (intake[7] == ' ' && intake[8] == '-' && intake[9] == '-')
		{
			cout << "\nChecking extra parameter...";
			if (intake[10] == 'd' && intake[11] == 'a' && intake[12] == 't')
			{
				dat = 1;
				encrypt(dat);
				dat = 0;
			}

			else
			{
				cout << "\nInvalid parameter provided.";
				cout << "\n[FATAL ERROR] Encryption process failed. Invalid Parameter provided. Please use the 'help' command to see valid commands and their parameters.";
				cout << "\n\n";
				goto Intake;
			}
		}

		// Runs encrypt function when no parameters are provided.
		else
		{
			dat = 0;
			encrypt(dat);
			goto Intake;
		}

	}

	// Quit/Exit command. Exits the program.
	else if (strcmp(intake, "quit") == 0 || strcmp(intake, "exit") == 0)
	{
		Quit = 1;
	}

	// Help command.
	else if (strcmp(intake, "help") == 0)
	{
		cout << "\n\nList of commands:";
		cout << "\n\n1. help -> Shows this thing you're currently looking at.";
		cout << "\n2. clear -> Clears the console screen.";
		cout << "\n3. inputdata -> Starts the process of inputting data.";
		cout << "\n4. viewdata -> Shows currently input data.";
		cout << "\n5. initialize -> Resets and initializes the program. This is automatically run at start-up.";
		cout << "\n6. reset -> Resets the program and returns to the starting screen.";
		cout << "\n7. encrypt -> Starts the encryption process. This will encrypt the data input using 'inputdata' and save it as a file.";
		cout << "\n\t*** use 'encrypt --dat' to encrypt text and save as a binary file.";
		cout << "\n\n---------------------------------------------------------------";
		cout << "\n\nVersion 0.6 || Developed by Liam Z. Charles";
		cout << "\ngithub.com/LiamZC/CPP-Encryption-Tool\n\n";
		cout << "\n---------------------------------------------------------------\n";
	}

	// Clear command. Clears the console screen.
	else if (strcmp(intake, "clear") == 0)
	{
		system("CLS");
	}

	// Initialize command.
	else if (strcmp(intake, "initialize") == 0)
	{
		initialize();
	}

	// Reset command.
	else if (strcmp(intake, "reset") == 0)
	{
		reset();
	}

	// Code to make terminal ignore blank entries and a single space.
	else if (strcmp(intake, "") == 0 || strcmp(intake, " ") == 0)
	{
		cout << "";
	}

	// inputdata command.
	else if (strcmp(intake, "inputdata") == 0)
	{
		inputData();
	}

	// viewdata command.
	else if (strcmp(intake, "viewdata") == 0)
	{
		viewData();
	}

	// Output for invalid command.
	else
	{
		cout << "\nInvalid command. \nFor list of valid commands, please use the 'help' command.\n\n";
	}

}