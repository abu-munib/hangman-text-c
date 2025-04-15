#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
 * Hangman guessing word games
 * Author: Abu munib
*/

#define NUM_OF_WORDS 3
#define TRIAL 9

const char *words[NUM_OF_WORDS] = {
	"Banana",
	"Watermelon",
	"Papaya"
};

int main() {

	printf("WELCOME TO HANGMANT\n");
	printf("========================\n");

	int word_index, word_len;
	char user_input;

	srand(time(NULL)); // seeds using current time 

	// Choose random words when start
	word_index = rand() % NUM_OF_WORDS;
	const char *word = words[word_index];

	// Print trials
	printf("You have %d trials left\n", TRIAL);

	// Determine word length and print spaces
	word_len = strlen(word);
	for (int i = 0; i < word_len; i++) {
		printf("_");
	}
	printf("\n");
	printf("========================\n");


	
	return 0;
}
