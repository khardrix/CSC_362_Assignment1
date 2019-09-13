#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <ctype.h>

/******************************************************************************************************************
 ******************************************************************************************************************
 *****     Class: CSC-362-001                       Professor: Fox                 Student: Ryan Huffman      *****                                                          
 *****________________________________________________________________________________________________________*****                                                                                                     
 *****                               Programming Assignment #1: Compare Two Files                             *****                                                         
 *****--------------------------------------------------------------------------------------------------------*****                                                                                                     
 *****                           Program that compares two files using file pointers.                         *****                                                
 *****                    The program then asks the user if they want to compare only letters                 *****                                                           
 *****                       and if the user wants letter comparisons to be case sensitive.                   *****                                                           
 *****                                                                                                        *****
 *****                       The program then loops through the files counting Characters,                    *****                                                        
 *****                           how many were mismatched and how many were not tested                        *****                                                 
 *****                               according to the conditions the user defined.                            *****                                        
 *****                                                                                                        *****
 *****                         The program compares respective Characters from each file                      *****                                                       
 *****                              one at a time according to how the user wants.                            *****                                            
 *****                                                                                                        *****
 *****                        At the end of the program, the program prints to the terminal                   *****                                                            
 *****                                the user reponses to the two questions asked,                           *****                                            
 *****                           the number of total characters in the individual files,                      *****                                                    
 *****            the percentage of mismatches between the files according to the user defined conditions     *****                                                                              
 *****        and the percentage of Characters that were not tested according to the user defined conditions. *****
 ******************************************************************************************************************
 ******************************************************************************************************************/

int main() {
	/* --------------------------------------- VARIABLE DECLARATIONS ---------------------------------------- */
	// Character Pointer variables to store the file names
	char* fileName1 = "file2a.txt";
	char* fileName2 = "file2b.txt";

	// Character Pointer variables to store strings for use in final output
	char* sensitiveOutput = "";
	char* letterOutput = "";
	
	// File Pointer variables 
	FILE* fileInput1;
	FILE* fileInput2;

	// Character variables to read what is in the files that the file pointers point to 
	char readC1;
	char readC2;

	// Character variables to store the user's answers to questions on case sensitivity and letters only
	char sensitive;
	char onlyLetters;

	// int counter variables
	int sameCounter = 0;
	int allCounter = 0;
	int mismatchCounter = 0;
	int notTestedCounter = 0;

	// float variables to store the percentage results
	float samePercentage, mismatchPercentage, notTestedPercentage;
	/* ----------------------------------- END OF VARIABLE DECLARATIONS ------------------------------------- */


	// opening the files in read mode and assigning them to the file pointer variables
	fileInput1 = fopen(("%c", fileName1), "r");
	fileInput2 = fopen(("%c", fileName2), "r");


	// ask user if they want the testing of the files to be case sensitive (only applies to letters)
	printf("Case sensitive? (Y/N): ");
	// account for new line characters and white space and get user input to the above question 
		// and assign that Character value to the char sensitive variable
	scanf(" %c", &sensitive);


	// ask the question if they want the testing and comparison of the files to 
		// be comparing letters only and assign th
	printf("Compare letters only? (Y/N): ");
	// account for new line characters and white space and get user input to the above question 
		// and assign that Character value to the char onlyLetters variable
	scanf(" %c", &onlyLetters);


	// if statement to check if the file pointer variable fileInput1 is equal to NULL
	if (fileInput1 == NULL) {
		// print to the terminal that the file could not be found
		printf("Could not find file");
		// return 1 to indicate that an error has occured
		return 1;
	}


	// if statement to check if the file pointer variable fileInput2 is equal to NULL
	if (fileInput2 == NULL) {
		// print to the terminal that the file could not be found
		printf("Could not find file 2");
		// return 1 to indicate that an error has occured
		return 1;
	}


	/* ------------------------------ WHILE LOOP TO LOOP THROUGH FILE UNTIL EOF ----------------------------- */
	// infinite while loop that will only exit when the EOF (End Of File) 
		// of the first file is reached
	while ( !feof(fileInput1) ) {
		// get the current Character (initially starts with the top left (first) character) from 
			// the first file that has the file pointer variable name of fileInput1. With every
			// iteration of the while loop, the current Character will advance to the next
			// Character in the file (moving just like if a human was reading the file)
		readC1 = fgetc(fileInput1);
		// get the current Character (initially starts with the top left (first) character) from 
			// the second file that has the file pointer variable name of fileInput2. With every
			// iteration of the while loop, the current Character will advance to the next
			// Character in the file (moving just like if a human was reading the file)
		readC2 = fgetc(fileInput2);


		// increments every time a character is inspected
		allCounter++;


		/* ----- TESTING FOR MATCHES, MISMATCHES AND NOT TESTED BASED UPON USER DEFINED TEST CONDITIONS ----- */
		// if statement that checks if the user wants to check only letters
		if (onlyLetters == 'y' || onlyLetters == 'Y') {
			// store "letters only" for use in final output in the Character Pointer variable letterOutput
			letterOutput = "letters only";

			// if statement that checks if the Charcter variable readC1 is not an alphabetical Character
			if (isalpha(readC1) == 0) {
				// increment the notTestedCounter variable
				notTestedCounter++;
			}
			// else statement that executes if the Character variable readC1 is an alphabetical Character
			else {
				// if statement that checks if the user wants the alphabetical comparisons to be case sensitive
				if (sensitive == 'y' || sensitive == 'Y') {
					// store "sensitivity" for use in final output in the Character Pointer variable sensitiveOutput
					sensitiveOutput = "sensitivity";

					// if statement that checks if the Characters variable readC1 is lowercase and
						// the Character variable readC2 is uppercase
					if ( ((isupper(readC1) == 0) && (isupper(readC2) != 0)) ) {
						// increment the mismatchCounter variable
						mismatchCounter++;
					}
					// else if statement that checks if the Characters variable readC1 is uppercase and
						// the Character variable readC2 is lowercase
					else if (((isupper(readC1) != 0) && (isupper(readC2) == 0))) {
						// increment mismatchCounter variable
						mismatchCounter++;
					}
					// else statement that executes if the alphabetical Character variables readC1 and 
						// readC2 have matching cases (upper or lower)
					else {
						// if statement that checks if the Character variables readC1 and readC2
							// are the same
						if (readC1 == readC2) {
							// increment the sameCounter variable
							sameCounter++;
						}
						// else statement that executes if the Character variables readC1 and
							// readC2 are different
						else {
							// increment the mismatchCounter variable
							mismatchCounter++;
						}
					}
				}
				// else statement that executes on alphabetical Character variables readC1 and
					// readC2 if their case (upper or lower) does not matter 
				else {
					// store "insensitivity" for use in final output in the Character Pointer variable sensitiveOutput
					sensitiveOutput = "insensitivity";

					// if statement that converts the Character variables readC1 and readC2 to
						// lowercase and then compares them to see if they are the same
					if (tolower(readC1) == tolower(readC2)) {
						// increment the sameCounter variable
						sameCounter++;
					}
					// else statement that executes if the Character variables readC1 and
						// readC2 are different letters
					else {
						// increment the mismatchCounter variable
						mismatchCounter++;
					}
				}
			}
		}
		// else statement that executes if Characters that are not alphabetical are going to be compared
		else {
			// store "letters and characters" for use in final output in the Character Pointer variable letterOutput
			letterOutput = "letters and characters";

			// if statement that checks if the Character variables readC1 and readC2 are the same
			if (readC1 == readC2) {
				// increment the sameCounter variable
				sameCounter++;
			}
			// else statement that executes if the Character variables readC1 and readC2 are different
			else {
				// increment the mismatchCounter variable
				mismatchCounter++;
			}
		}
		/* -- END OF TESTING FOR MATCHES, MISMATCHES AND NOT TESTED BASED UPON USER DEFINED TEST CONDITIONS - */
	}
	/* --------------------------- END OF WHILE LOOP TO LOOP THROUGH FILE UNTIL EOF ------------------------- */


	// close both files
	fclose(fileInput1);
	fclose(fileInput2);


	// compute the percentage values of the Characters that were the same, a mismatch and not tested
	samePercentage = (((float)sameCounter) / allCounter) * 100;
	mismatchPercentage = (((float)mismatchCounter) / allCounter) * 100;
	notTestedPercentage = (((float)notTestedCounter) / allCounter) * 100;


	// print whether the user wanted alphabetical comparisons to be case sensitive
	printf("\n\n\n\nCase sensitive? (Y/N) %c\n", sensitive);
	// print whether the user wanted to compare letters only
	printf("Compare letters only? (Y/N) %c\n\n", onlyLetters);
	// print the information about the files being compared and how they are being compared
	printf("Comparing %s to %s testing for case %s and for %s \n", fileName1, fileName2, sensitiveOutput, letterOutput);
	// print the number of Characters that were in the individual files
	printf("\tFile sizes: %d characters \n", allCounter);
	// print the percentage of mismatched Characters in the files to two decimal places
	printf("\tMismatches: %.2f%% \n", mismatchPercentage);
	// print the percentage of Characters not tested in the files to two decimal places
	printf("\tNot tested: %.2f%% \n", notTestedPercentage);


	return 0;
}

/*
Output of comparing file2a.txt and file2b.txt:
Case sensitive? (Y/N) y
Compare letters only? (Y/N) y

Comparing file2a.txt to file2b.txt testing for case sensitivity and for letters only
		File sizes: 729 characters
		Mismatches: 5.35%
		Not tested: 23.32%
*/