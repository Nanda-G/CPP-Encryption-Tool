#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<string.h>

int Quit = 0; // Global exit variable.
int RESET = 0; // Global reset variable.

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
		cout << "\nEncryption is currently being developed.\n\n";
	}
}

void initialize() 
{
	// Initialization function. This function will reset key regeneration and essentially reset the program. Leave as is for now.
	cout << "\nInitializing...";
	//
	cout << "\nResetting key values...";
	//
	cout << "\n\nInitialization complete. Press any key to reset.";
	getch();
	RESET = 1;
}

void terminalIntake() //This function is the core for the terminal-style input. 
{
	Intake:
	char intake[17]; // Command line intake string.
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
				int dat = 1;
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
			int dat = 0;
			encrypt(dat);
		}

	}

	// Quit/Exit command. Exits the program.
	else if (strcmp(intake, "quit")==0 || strcmp(intake, "exit")==0)
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

int main()
{
	ToReset:
	Quit = 0;
	RESET = 0;
	clrscr();
	textcolor(GREEN); // Sets console color as green for text being output through cprintf.
	// cprintf and textcolor() are from CONIO.H
	cprintf("Welcome to the CPP Encryption Tool | v0.1"); // cprintf is used instead of cout to use the above textcolor(GREEN) attribute. Will be implemented fully in the program when coloring the entire console.
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
}
