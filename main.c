#include <stdio.h>
// Prototype

void identify_identical(int values[], int n);
int identical_right(int snow1[], int snow2[], int start);


int main(int argc, char *argv[]) {
  printf("Welcome to Algorithmic Thinking!\n");
  int a[5] = {1, 2, 2, 4, 5};
  identify_identical(a, 5);
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
  for (offset = 0; offset < 6; offset++) {
      snow2_index = start + offset;
      if (snow2_index >= 6)
          snow2_index = snow2_index - 6;
      if (snow1[offset] != snow2[snow2_index])
          return 0;
    }
return 1;
  }
