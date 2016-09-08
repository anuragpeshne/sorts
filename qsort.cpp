#include "qsort.h"

void qsort(int* inp, int start, int end) {
  if (start < end) {
    int pivotIndex;

    pivotIndex = getPivotIndex(inp, start, end);
    pivotIndex = divide(inp, start, end, pivotIndex);
    qsort(inp, start, pivotIndex - 1);
    qsort(inp, pivotIndex + 1, end);
  }
}

int divide(int* inp, int start, int end, int pivotIndex) {
  int i = start;
  int j = end;
  int pivot = inp[pivotIndex];

  while (i <= j) {
    while ((i <= j) && (inp[i] <= pivot))
      i++;

    while ((i <= j) && (inp[j] > pivot))
      j--;

    if (i < j) {
      swap(inp, i, j);
      i++;
      j--;
    }
  }

  swap(inp, pivotIndex, i - 1);

  return i - 1;
}

void swap(int* inp, int i, int j) {
  int temp;

  temp = inp[i];
  inp[i] = inp[j];
  inp[j] = temp;
}

int getPivotIndex(int* inp, int start, int end) {
  return start;
}
