#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char playAgain;
    
    do {
        // Seed the random number generator
        srand(time(0));

        // Generate a random number between 1 and 100
        int randomNumber = (rand() % 100) + 1;
        int guessed_number;
        int no_of_guesses = 0;

        printf("Welcome to the Guessing Game!\n");
        printf("I've selected a random number between 1 and 100. Can you guess it?\n");

        do {
            printf("Enter your guess: ");
            scanf("%d", &guessed_number);
            
            // Validate input
            if (guessed_number < 1 || guessed_number > 100) {
                printf("Please enter a number between 1 and 100.\n");
                continue; // Skip to the next iteration
            }
            
            no_of_guesses++;

            if (guessed_number > randomNumber) {
                printf("Lower number please!\n");
            } else if (guessed_number < randomNumber) {
                printf("Higher number please!\n");
            } else {
                printf("Congrats! You've guessed the number.\n");
            }
        } while (guessed_number != randomNumber);
        
        printf("You guessed the number in %d guesses.\n", no_of_guesses);

        // Ask if the user wants to play again
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain); // Note the space before %c to consume any leftover newline character

    } while (playAgain == 'y' || playAgain == 'Y');
    
    printf("Thanks for playing!\n");
    return 0;
}
