/*
 * This is free and unencumbered software released into the public domain.

 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* RANGE_MIN is alawys 0 */
#define RANGE_MAX 5
#define GUESSES 10
#define ROUNDS 5

int init_game(void);
int init_leaderboard_check(void);
int rand_clamp(int min, int max);

int main(void)
{
	int choice;

	/* initialize randomseed */
	srand(time(NULL));

	do {
		printf("Number game v1.0.0\n1) Play game\n2) Check leaderboards\n");
		scanf("%d", &choice);
	
		if (choice == 1) {
			init_game();
			break;
		} else if (choice == 2) {
			init_leaderboard_check();
			break;
		} else
			printf("Invalid choice\n");
	} while (1);

	return 0;
}

/* starts the game */
int init_game(void)
{
	/* loop through ROUNDS */
	/* and play each one   */
	for (int a=1; a<=ROUNDS; a++) {
		printf("Round %d of %d:\n", a, ROUNDS);
		int random_int = rand_clamp(0, RANGE_MAX);
		/* loop through GUESSES_MAX */
		/* and play until match     */
		for (int b=1; b<=GUESSES; b++) {
			int guess;
			printf("I am thinking of an integer between 0 and %d. What is it?\n", RANGE_MAX);
			scanf("%d", &guess);
			if (guess == random_int) {
				if (a == ROUNDS)
					printf("Correct, You win!\n\n");
				else
					printf("Correct! Try another.\n\n");
				break;
			}
			if (a != GUESSES)
				printf("Wrong! you have %d guesses left.\n\n", GUESSES-b);
			else
				printf("No more guesses left! This one's a loss.\n\n");
		}
	}

	return 0;
}

/* check the leaderboard for the current session */
int init_leaderboard_check(void)
{
	/* TODO */
	return 0;
}

/* clamped rand wrapper */
int rand_clamp(int min, int max)
{
	return min + rand() % (max+1 - min);
}

