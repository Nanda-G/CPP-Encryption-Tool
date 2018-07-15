#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int Quit = 0; // Global exit variable.
int RESET = 0; // Global reset variable.
int key0x = 0, key0a = 0, key0b = 0;
char aX = 'a', bY = 'b', cZ = 'c';
char CRYPTKEY[6];

void initialize();
void encrypt(int);
void terminalIntake();

/*
KEYGEN

         aX - 0x - bY - 0a - cZ - 0b
	Where,
		aX is a+X (a is ASCII 'a' and X is randomly generated integer between 1-25.)
		bY is b+Y (b is ASCII 'b' and Y is randomly generated integer between 1-25.)
		cZ is c+Z (c is ASCII 'c' and Z is randomly generated integer between 1-25.)
		aX, bY, cZ are used to populate the final encryption key.

		0x is key0x, which is a randomly generated integer between 17-44.
		0a is key0a, which is a randomly generated integer between 10-37.
		0b is key0b, which is a randomly generated integer between 11-44.
		key0x, key0a, key0b are used in the encryption process.		
		
*/

int main()
{
	ToReset:
	Quit = 0;
	RESET = 0;
	clrscr();
	cout << "\nWelcome to the CPP Encryption Tool | v0.1";
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
	getch();
	return 0;
}

void initialize()
{
	// Initialization function. This function will reset key regeneration and essentially reset the program. Leave as is for now.
	cout << "\nResetting key values...";
	key0x = 0;
	key0a = 0;
	key0b = 0;
	aX = 'a';
	bY = 'b';
	cZ = 'c';
	for (int i = 0; i < 9; i++)
	{
		CRYPTKEY[i] = '?';
	}

	cout << "\nInitializing...";
	int rand125 = rand() % 25 + 1;

	key0x = rand() % 44 + 17;
	cout << key0x;
	key0a = rand() % 37 + 10;
	cout << key0a;
	key0b = rand() % 44 + 11;
	cout << key0b;
	aX = aX + rand125;
	cout << aX;
	bY = bY + rand125;
	cout << bY;
	cZ = cZ + rand125;
	cout << cZ;

	cout << "\n\nInitialization complete.";
}

void encrypt(int datSET) // Encryption function. Leave as is.
{
	if (datSET == 1)
	{
		cout << "\nStarting encryption process...";
		cout << "\nSaving final file as .DAT (Binary file).";
		cout << "\nEncryption is currently being developed.\n\n";
		datSET = 0;
	}
	else
	{
		cout << "\nStarting encryption process...";
		cout << "\n\nGenerating encryption key...";
		cout << "\nInitializing program...";
		initialize();

		cout << "\nCreating encryption key...";
		CRYPTKEY[0] = aX;
		CRYPTKEY[1] = key0x;
		CRYPTKEY[2] = bY;
		CRYPTKEY[3] = key0a;
		CRYPTKEY[4] = cZ;
		CRYPTKEY[5] = key0b;
      cout<<"\n";
      for(int i=0; i<6; i++)
      {
      	cout<<CRYPTKEY[i];
      }
		cout << "\nDone.\n";
		cout << "Encryption is still in development.\n\n";
	}
}

void terminalIntake() //This function is the core for the terminal-style input. 
{
Intake:
	char intake[17]; // Command line intake string.
	int dat = 0;
	cout << "$> ";
	gets(intake);
	//The loop in the next line acts according to the 'encrypt' command.
	if (intake[0] == 'e' && intake[1] == 'n' && intake[2] == 'c' && intake[3] == 'r' && intake[4] == 'y' && intake[5] == 'p' && intake[6] == 't')
	{
		//The loop in the next line checks for extra parameters given with the 'encrypt' command.
		if (intake[8] == '-' && intake[9] == '-')
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
		cout << "\n6. encrypt -> Starts the encryption process. This will encrypt the data input using 'inputdata' and save it as a file.";
		cout << "\n\t*** use 'encrypt --dat' to encrypt text and save as a binary file.";
		cout << "\n\n---------------------------------------------------------------";
		cout << "\n\nVersion 0.1 || Developed by Liam Z. Charles & Nanda Gopal";
		cout << "\ngithub.com/LiamZC/CPP-Encryption-Tool\n\n";
		cout << "\n---------------------------------------------------------------\n";
	}

	// Clear command. Clears the console screen.
	else if (strcmp(intake, "clear") == 0)
	{
		clrscr();
	}

	else if (strcmp(intake, "initialize") == 0)
	{
		initialize();
	}

	else if (strcmp(intake, "reset") == 0)
	{
		cout << "\nResetting key values...";
		key0x = 0;
		key0a = 0;
		key0b = 0;
		aX = 'a';
		bY = 'b';
		cZ = 'c';
		for (int i = 0; i < 9; i++)
		{
			CRYPTKEY[i] = '?';
		}

		RESET = 1;
		clrscr();
	}

	// Code to make terminal ignore blank entries and a single space.
	else if (strcmp(intake, "") == 0 || strcmp(intake, " ") == 0)
	{
		cout << "";
	}

	// Code to input data to the buffer before encryption.
	else if (strcmp(intake, "inputdata") == 0)
	{
		// TO BE DEVELOPED.
		cout << "";
	}

	// Code to view data in the buffer before encryption.
	else if (strcmp(intake, "viewdata") == 0)
	{
		// TO BE DEVELOPED.
		cout << "";
	}

	// Code for invalid command.
	else
	{
		cout << "\nInvalid command. \nFor list of valid commands, please use the 'help' command.\n\n";
	}

}
