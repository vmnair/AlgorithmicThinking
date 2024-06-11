#include <stdio.h>

#define ARR_SIZE 100000
#define SNOW_FLAKE_SIZE 6
// Prototype
/*void identify_identical(int values[], int n);*/

/* This function compares if snow1[] and snow2[] are same arrays beginning from
 * the "start" position in the snow[]2 and going in a rightward direction.
 */
void identify_identical(int snowflakes[][SNOW_FLAKE_SIZE], int n);

/* This function compares if snow1[] and snow2[] are same arrays beginning from
 * the "start" position in the snow[]2 and going in a leftward direction.
 */
int identical_left(int snow1[], int snow2[], int start);
/* This function determines if two arrays passed to it are identical by comparing
 * it both rightward as well as leftword direction.
 */
int are_identical(int snow1[], int snow2[]);

int main(int argc, char *argv[]) {
  printf("Welcome to Algorithmic Thinking!\n");
  static int snowflakes[ARR_SIZE][SNOW_FLAKE_SIZE];
  int n, i, j;
  printf("How many arrays do you want to enter: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < SNOW_FLAKE_SIZE; j++) {
      printf("Enter [%d][%d]: ", i, j);
      scanf("%d", &snowflakes[i][j]);
    }
  }
  identify_identical(snowflakes, n);
  return 0;
}

void identify_identical(int snowflakes[][SNOW_FLAKE_SIZE], int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (are_identical(snowflakes[i], snowflakes[j])) {
        printf("Twin snowflakes found.\n");
        return;
      }
    }
  }
  printf("No two snowflakes are identical\n");
}

int identical_right(int snow1[], int snow2[], int start) {
  int offset, snow2_index;
  for (offset = 0; offset < SNOW_FLAKE_SIZE; offset++) {
    // wrap-around
    if (snow1[offset] != snow2[(start + offset) % SNOW_FLAKE_SIZE])
      return 0;
  }
  // A match found
  return 1;
}

int identical_left(int snow1[], int snow2[], int start) {
  int offset, snow2_index;

  for (offset = 0; offset < SNOW_FLAKE_SIZE; offset++) {
    snow2_index = start - offset;
    if (snow2_index <= -1)
      snow2_index = snow2_index + SNOW_FLAKE_SIZE;
    if (snow1[offset] != snow2[snow2_index])
      return 0;
  }
  return 1;
}

int are_identical(int snow1[], int snow2[]) {
  int start;
  for (start = 0; start < SNOW_FLAKE_SIZE; start++) {
    if (identical_right(snow1, snow2, start))
      return 1;
  }

  for (start = 0; start < SNOW_FLAKE_SIZE; start++) {
    if (identical_left(snow1, snow2, start))
      return 1;
  }
  return 0;
}
