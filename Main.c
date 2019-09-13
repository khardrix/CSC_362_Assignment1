#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int main() {
	/* --------------------------------------- VARIABLE DECLARATIONS ---------------------------------------- */
	// Character Array variables to store the file names
	char fileName1[102] = "C:\\Users\\user\\Desktop\\NKU\\Fall 2019\\Computer Systems\\Programming Assignments\\Assignment #1\\file1a.txt";
	char fileName2[104] = "C:\\Users\\user\\Desktop\\NKU\\Fall 2019\\Computer Systems\\Programming Assignments\\Assignment #1\\file1b-2.txt";

	// File Pointer variables 
	FILE* fileInput1;
	FILE* fileInput2;

	// Character variables to read what is in the files that the file pointers point to 
	char readC1;
	char readC2;

	// Character variables to store the user's answers to questions on case sensitivity and letters only
	char sensitive;
	char onlyLetters;
	char isSensitive;
	char isOnlyLetters;

	// float counter variables
	float same = 0;
	float all = 0;
	float mismatches = 0;
	float notTested = 0;
	float sameResult, mismatchResult, notTestResult;

	// int variables to use with while loops
	int loop = 1;
	int caseQuestion = 1;
	int lettersQuestion = 1;
	/* ----------------------------------- END OF VARIABLE DECLARATIONS ------------------------------------- */

	// opening the files in read mode and assigning them to the file pointer variables
	fileInput1 = fopen(("%c", fileName1), "r");
	fileInput2 = fopen(("%c", fileName2), "r");

	/* ---------------------------------- WHILE LOOP TO VALIDATE USER INPUT --------------------------------- */
	// while loop will loop until the user inputs 'Y', 'y', 'N' or 'n'. Once that happens, 
		// the int caseQuestion variable will be set to 0, which will cause the while condition to 
		// fail and the while loop will be exited
	while (caseQuestion == 1) {
		// ask user if they want the testing of the files to be case sensitive (only applies to letters)
		printf("Case sensitive? (Y/N): ");
		// account for new line characters and white space and get user input to the above question 
			// and assign that Character value to the char sensitive variable
		scanf(" %c", &sensitive);

		// if statement to check if the user input was equal to 'y' or 'Y'
		if (sensitive == 'y' || sensitive == 'Y') {
			// set caseQuestion to 0 to exit the while loop and set the Character variable isSensitive to 'y'
			caseQuestion = 0;
			isSensitive = 'y';
		}
		// else if statement to check if the user input was to 'n' or 'N'
		else if (sensitive == 'N' || sensitive == 'n') {
			// set caseQuestion to 0 to exit the while loop and set the Character variable isSensitive to 'n'
			caseQuestion = 0;
			isSensitive = 'n';
		}
	}
	/* ------------------------------ END OF WHILE LOOP TO VALIDATE USER INPUT ------------------------------ */


	// print user answer to whether they want testing to be case sensitive
	printf("Case sensitive: %c\n", sensitive);


	/* ---------------------------------- WHILE LOOP TO VALIDATE USER INPUT --------------------------------- */
	// while loop will loop until the user inputs 'Y', 'y', 'N' or 'n'. Once that happens, 
		// the int caseQuestion variable will be set to 0, which will cause the while condition to 
		// fail and the while loop will be exited
	while (lettersQuestion == 1) {
		// ask the question if they want the testing and comparison of the files to 
			// be comparing letters only and assign th
		printf("Compare letters only? (Y/N): ");
		// account for new line characters and white space and get user input to the above question 
			// and assign that Character value to the char onlyLetters variable
		scanf(" %c", &onlyLetters);

		// if statement to check if the user input was equal to 'y' or 'Y'
		if (onlyLetters == 'y' || onlyLetters == 'Y') {
			// set lettersQuestion to 0 to exit the while loop and set the Character variable isOnlyLetters to 'y'
			lettersQuestion = 0;
			isOnlyLetters = 'y';
		}
		// else if statement to check if the user input was equal to 'n' or 'N'
		else if (onlyLetters == 'N' || onlyLetters == 'n') {
			// set lettersQuestion to 0 to exit the while loop and set the Character variable isOnlyLetters to 'n'
			lettersQuestion = 0;
			isOnlyLetters = 'n';
		}
	}
	/* ------------------------------ END OF WHILE LOOP TO VALIDATE USER INPUT ------------------------------ */


	// print user answer to whether they want testing to include only letters
	printf("Letters only: %c\n", onlyLetters);


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
	while (1) {
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

		/* ----- TESTING FOR MATCHES, MISMATCHES AND NOT TESTED BASED UPON USER DEFINED TEST CONDITIONS ----- */
		if (isOnlyLetters == 'y') {
			if ((readC1 < 65) || (readC1 > 122) || ((readC1 > 90) && (readC1 < 97))) {
				if ( ((readC2 >= 65) && (readC2 <= 90)) || ((readC2 >= 97) && (readC2 <= 122)) ) {
					all++;
					notTested++;
					// continue;
				}
				else {
					all++;
					mismatches++;
					// continue;
				}
			}
			else if ( ((readC2 >= 65) && (readC2 <= 90)) || ((readC2 >= 97) && (readC2 <= 122)) ) {
				all++;
				mismatches++;
				// continue;
			}
			else {
				if (isSensitive == 'y') {
					if (readC1 == readC2) {
						all++;
						same++;
						// continue;
					}
					else {
						all++;
						mismatches++;
						// continue;
					}
				}
				else {
					if ((readC1 == (readC2 - 32)) || (readC1 == (readC2 + 32))) {
						all++;
						same++;
						// continue;
					}
					else {
						all++;
						mismatches++;
						// continue;
					}
				}
			}
		}
		else {
			if (readC1 == readC2) {
				all++;
				same++;
				// continue;
			}
			else {
				all++;
				mismatches++;
				// continue;
			}
		}
		/* -- END OF TESTING FOR MATCHES, MISMATCHES AND NOT TESTED BASED UPON USER DEFINED TEST CONDITIONS - */


		if (readC1 == EOF) {
			// loop = 0;
			break;
		}
		else {
			printf("%c", readC1);
			printf("%c", readC2);
		}
	}
	/* --------------------------- END OF WHILE LOOP TO LOOP THROUGH FILE UNTIL EOF ------------------------- */


	fclose(fileInput1);
	fclose(fileInput2);

	sameResult = ((same / all) * 100);
	mismatchResult = ((mismatches / all) * 100);
	notTestResult = ((notTested / all) * 100);

	printf("File sizes: %d characters \n", all);
	printf("Mismatches: %.2f \n", mismatchResult);
	printf("Not tested: %.2f \n", notTestResult);

	printf("Same %d\nAll %d", same, all);

	return 0;
}

/*
1) declare variables - inside main() (all code inside main)
*/

/*
2.) ask user questions
*/

/*
3.) open files - "fopen, fclose, fgetc" - google "ansi c file io" look for "f"-something,
all caps with *. File* = file pointer. only c use file pointer
*/

/*
4.) Loop through files until eof
	/*
	5.) next 4 comments inside loop

	6.) read next character

	7.) check for eof

	8,) compare characters

	9.) increment counter (characters matched or didn't match)
	*/
	/*
	*/



	/*
	after loop
	*/

	/*
	10.) close the file
	*/

	/*
	11.) compute values (files, mismatches, not tested)
	*/

	/*
	12.) print results
	*/

	/*
	First, just open two files, loop through them until eof. counting the characters and printing the results.
	declare 2 file pointers, integer counter and two character variables to hold the current character.
	File pointer 1
	File pointer 2
	number of chars read
	*/

	/*
	scan f
	*/

	/*
	*/

	/*
	#include <stdio.h>
	int main()
	{
		 /* Pointer to the file */
		 // FILE* fp1;

		 /* Character variable to read the content of file */
		 // char c;

		 /* Opening a file in r mode*/
		 // fp1 = fopen("C:\\myfiles\\newfile.txt", "r");

		 /* Infinite loop –I have used break to come out of the loop*/
		 // while (1)
		 // {
			 // c = fgetc(fp1);
			 // if (c == EOF)
				 // break;
			 // else
				 // printf("%c", c);
		 // }
		 // fclose(fp1);
		 // return 0;
		 // }
		 /**/


/*
		if ( ((isSensitive == 'y') && (isOnlyLetters == 'y')) ) {
			if ( (readC1 < 65) || (readC1 > 122) || ((readC1 > 90) && (readC1 < 97)) ) {
				if ( ((readC2 >= 65) && (readC2 <= 90)) || ((readC2 >= 97) && (readC2 <= 122)) ) {
					all++;
					mismatches++;
					continue;
				}
				else {
					all++;
					notTested++;
					continue;
				}
			}
			else if ( (readC2 < 65) || (readC2 > 122) || ((readC2 > 90) && (readC2 < 97)) ) {
				if ( ((readC1 >= 65) && (readC1 <= 90)) || ((readC1 >= 97) && (readC1 <= 122)) ) {
					all++;
					mismatches++;
					continue;
				}
				else {
					all++;
					notTested++;
					continue;
				}
			}
			else {
				if ( readC1 == readC2 ) {
					all++;
					same++;
					continue;
				}
				else {
					all++;
					mismatches++;
					continue;
				}
			}
		}
		else if ( ((isSensitive == 'y') && (isOnlyLetters == 'n')) ) {
			if (readC1 == readC2) {
				all++;
				same++;
				continue;
			}
			else {
				all++;
				mismatches++;
				continue;
			}
		}
		else if ( ((isSensitive == 'n') && (isOnlyLetters == 'y')) ) {
			if ( (readC1 < 65) || (readC1 > 122) || ((readC1 > 90) && (readC1 < 97)) ) {
				if ((readC2 < 65) || (readC2 > 122) || ((readC2 > 90) && (readC2 < 97))) {

				}
			}
		}


		if (readC1 == readC2) {
			same++;
			all++;
		}
		else {
			all++;
		}
		*/