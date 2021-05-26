#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int found (int a[], int size, int value){	// searches an array to see if a value is already present inside it, if not present, returns -1

    for (int i = 0; i < size; i++){
    if (a[i] == value)
        return 1;
    }
    return -1;
}


int uniqueRand (int a[], int size){	//adds unique random numbers to an array and calls found function to check for duplicates

    srand (time (0));
    int i = 0;
    while (i < size){
        int randomNum = (rand () % 9) + 1;	// creates a random number
        if (found (a, size, randomNum) == -1){ //make sure randomNum is not already added to the array using found function
            a[i] = randomNum; // add the randomNum to the array
            i++;
        }
    }
    return 1;
}

int main () {
    printf ("Welcome to the Mastermind Game!\n"); //intro message

    while (1){      //loop to run rounds of the game
        int l = 0;  // l variable is to continue while loop that checks if the value of the code legnth is valid (1-7 inclusive)
        while (l == 0){
        int numberOfDigits;                           //variable for code length
        printf("Enter the length of the code (A number from 1 to 7 inclusive): \n");
        scanf ("%d", &numberOfDigits);                // code length input from user

        if (numberOfDigits >= 1 && numberOfDigits <= 7){ //check to make sure code length entered is between 1 and 7
            int computerCode[numberOfDigits];             //array to hold the random generated computerCode of length equal to numberOfDigits
            int chances;
            int j = 0;
            uniqueRand (computerCode, numberOfDigits);    //call uniqueRand function to insert numberOfDigit worth of numbers into computerCode array
            printf ("Enter the number of chances from 1-100 inclusive: \n");
            scanf ("%d", &chances);

                if (chances >= 1 && chances <= 100){           //check chances input to make sure its valid 1-100
                    for (chances; chances > 0; chances--){                        //create a loop to count down the number of guesses left
                    printf ("%d chances remain.\n", chances);
                    printf ("Enter your guess digits (1-9) one by one (press enter after each digit):\n");
                    int guessCode[numberOfDigits];            //initilize an array (guessCode) of size = to numberOfDigits to hold the user's guess digits

                    for (j = 0; j < numberOfDigits; j++)
                        scanf ("%d", &guessCode[j]);	         // user gets to input guess digits
                    int position, correctLocationNumber = 0, correctNumber = 0;

                    for (j = 0; j < numberOfDigits; j++){               //loop to search the computerCode array for the presence of the guess digit
                        position = found (computerCode, numberOfDigits, guessCode[j]); //call found function to check if the guessed digit is inside the computer code
                        if (guessCode[j] == computerCode[j]){           // if the guess and the computer code arrays are same value at element j, then increase correct location and number by 1
                            correctLocationNumber++;
                            }
                        else if (position != -1){                       //if the guessed digit merely exists somewhere in the computerCode array, then increase correct number by 1
                            correctNumber++;
                        }
                    }
                    if (correctLocationNumber == numberOfDigits){	        // checks if the number of correct location and number is equal to the length of the code, user has won the game.
                        printf("Congrats you have won the game!\n");
                        l = 1;
                        break;                                          //ends game round
                    }
                    printf("Correct location and number(s): %d    Correct number(s): %d\n", correctLocationNumber, correctNumber); //updates user on accuracy of guesses.

                    }

                }
                else{
                    puts("You have entered invalid number of chances (1 to 100 inclusive please)"); //sends error message if guess less than 1 or more than 100
                    break;                  //restarts the user inputs again
                }
            if (chances == 0){	// user runs out of chances and loses game
                printf("Sorry, you lost the game!\n The code is: \n");
                for (int i=0 ;i < numberOfDigits; i++)  // print the code array
                    printf("%d\n",computerCode[i]);
                    break;
            }
        }
        else{   //else statement to give user input and restart length input from user if it is not valid (not 1 - 7 inclusive)
            puts("You have entered invalid length input (1-7 inclusive please)");
            l = 0;
            continue;
        }


}
 printf("Do you want to play again? 1/yes, 0/no "); // ask if user wants to play again
        int answer;
        scanf("%d", &answer);
        if (!answer)    //if user says no, then break loop, exit game
            break;
}
 puts("Goodbye!"); //exit message
}

