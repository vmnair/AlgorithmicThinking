#include <stdio.h>

#define ARR_SIZE 5
// Prototype
void identify_identical(int values[], int n);
int identical_right(int snow1[], int snow2[], int start);
int identical_left(int snow1[], int snow2[], int start);
int are_identical(int snow1[], int snow2[]);

int main(int argc, char *argv[]) {
  printf("Welcome to Algorithmic Thinking!\n");
  int a[5] = {1, 2, 3, 4, 5};
  int b[5] = {3, 4, 5, 1, 2};
//  int c[5] = {3, 2, 1, 5, 4};
//  int d[5] = {3, 1, 2, 5, 4};
  printf("a and b are identical: %s\n",are_identical(a, b) ? "true" :  "false");
//  printf("a and c are identical:  %s\n",are_identical(a, c) ? "true" :  "false");
//
//printf("a and d are identical: %s\n",are_identical(a, d)? "true" :  "false");

  return 0;
}

void identify_identical(int values[], int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (values[i] == values[j]) {
        printf("Twin integers found %d , %d.\n", values[i], values[j]);
        return;
      }
    }
  }
  printf("No two integers are alike\n");
}

int identical_right(int snow1[], int snow2[], int start) {
  int offset, snow2_index;
  for (offset = 0; offset < ARR_SIZE; offset++) {
    // wrap-around
    if (snow1[offset] != snow2[(start + offset) % ARR_SIZE])
      return 0;
  }
  // A match found
  return 1;
}

int identical_left(int snow1[], int snow2[], int start) {
  int offset, snow2_index;

  for (offset = 0; offset < ARR_SIZE; offset++) {
    snow2_index = start - offset;
    if (snow2_index <= -1)
      snow2_index = snow2_index + ARR_SIZE;
    if (snow1[offset] != snow2[snow2_index])
      return 0;
  }
  return 1;
}

int are_identical(int snow1[], int snow2[]) {
  int start;
  for (start = 0; start < ARR_SIZE; start++) {
    if (identical_right(snow1, snow2, start))
      return 1;
  }

  for (start = 0; start < ARR_SIZE; start++) {
    if (identical_left(snow1, snow2, start))
      return 1;
  }
  return 0;
}
