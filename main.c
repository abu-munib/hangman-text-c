#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
 * Hangman guessing word games
 * Author: Abu munib
*/

#define NUM_OF_WORDS 3

const char *words[NUM_OF_WORDS] = {
	"Banana",
	"Watermelon",
	"Papaya"
};

int main() {

	printf("========================\n");
	printf("WELCOME TO HANGMANT\n");
	printf("========================\n");

	int word_index, word_len, trial = 9, stats = 0;
	char user_input;

	srand(time(NULL)); // seeds using current time 

	// Choose random words when start
	word_index = rand() % NUM_OF_WORDS;
	const char *word = words[word_index];

	// Determine word length and print spaces
	word_len = strlen(word);
	char word_box[word_len];
	for (int i = 0; i < word_len; i++) {
		word_box[i] = '_';
	}
	printf("\n");

	while (trial > 0 && stats == 0) {

		printf("========================\n");
		for (int i = 0; i < word_len; i++) {
			printf("%c", word_box[i]);
		}
		printf("\n");

		printf("You have %d trials left\n", trial);

		printf("\nEnter a letter: ");
		scanf(" %c", &user_input);

		// find character in the word
		int found = 0;
		for (int i = 0; i < word_len; i++) {
			if (user_input == word[i]) {
				word_box[i] = word[i];
				found = 1;
			} else {
				continue;
			}
		}
		if (found == 0) {
			trial -= 1;
		}
		for (int i = 0; i < word_len; i++) {
			if (word_box[i] == '_') {
				stats = 0;
				break;
			} else {
				stats = 1;
			}
		}
	}

	if (trial <= 0) {
		printf("You've lost\n");
	}
	if (stats == 1) {
		printf("You've won\n");
	}

	printf("The word is: %s\n", word);
	
	return 0;
}
