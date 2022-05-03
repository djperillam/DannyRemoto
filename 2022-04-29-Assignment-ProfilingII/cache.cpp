#include <cstdio>
#include <cstdlib>
#include <type_traits>

/*
  Tests cache misses.
*/
int rows;
int cols;
void option1(long arr[], int rows, int cols);
void option2(long arr[], int rows, int cols);
void option3(long arr[], int rows, int cols);

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("Usage: cacheTest sizeI sizeJ\nIn first input.\n");
    return 1;
  }
  long sI = atoi(argv[1]);
  long sJ = atoi(argv[2]);
  printf("Operating on matrix of size %ld by %ld\n", sI, sJ);
  long *arr = new long[sI * sJ]; // double array.
  option1(arr,sI,sJ);
  option2(arr,sI,sJ);
  option3(arr,sI,sJ);
  printf("%ld\n", arr[0]);
  delete[] arr; 
  return 0;
}

// option 1
void option1(long arr[], int rows, int cols) {
  for (long i = 0; i < rows; ++i)
    for (long j = 0; j < cols; ++j)
      arr[(i * (cols)) + j] = i;
  return;
}

// option 2
void option2(long arr[], int rows, int cols) {
  for (long i = 0; i < rows; ++i)
    for (long j = 0; j < cols; ++j)
      arr[(j * (rows)) + i] = i;
  return;
}

// option 3
void option3(long arr[], int rows, int cols) {
  for (int i = 0; i < rows * cols; ++i)
    arr[i] = i;
  return;
}
