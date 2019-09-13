#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int main() {
	/* ----------------------------------- VARIABLE DECLARATIONS ----------------------------------- */
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
	/* ------------------------------- END OF VARIABLE DECLARATIONS -------------------------------- */

	fileInput1 = fopen(("%c", fileName1), "r");
	fileInput2 = fopen(("%c", fileName2), "r");

	while (caseQuestion == 1) {
		printf("Case sensitive? (Y/N): ");
		scanf(" %c", &sensitive);

		if (sensitive == 'y' || sensitive == 'Y') {
			caseQuestion = 0;
			isSensitive = 'y';
		}
		else if (sensitive == 'N' || sensitive == 'n') {
			caseQuestion = 0;
			isSensitive = 'n';
		}
	}

	printf("Case sensitive: %c\n", sensitive);

	while (lettersQuestion == 1) {
		printf("Compare letters only? (Y/N): ");
		scanf(" %c", &onlyLetters);

		if (onlyLetters == 'y' || onlyLetters == 'Y') {
			lettersQuestion = 0;
			isOnlyLetters = 'y';
		}
		else if (onlyLetters == 'N' || onlyLetters == 'n') {
			lettersQuestion = 0;
			isOnlyLetters = 'n';
		}
	}

	printf("Letters only: %c\n", onlyLetters);

	if (fileInput1 == NULL) {
		printf("Could not find file");
		return 1;
	}

	if (fileInput2 == NULL) {
		printf("Could not find file 2");
		return 1;
	}

	while (1) {
		readC1 = fgetc(fileInput1);
		readC2 = fgetc(fileInput2);

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

		if (readC1 == EOF) {
			// loop = 0;
			break;
		}
		else {
			printf("%c", readC1);
			printf("%c", readC2);
		}
	}

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