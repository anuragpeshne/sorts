#include "mergeSort.h"

void mergeSort(int* inp, int start, int end) {
  if (start < end) {
    int mid = start + ((end - start) / 2);
    mergeSort(inp, start, mid);
    mergeSort(inp, mid + 1, end);
    merge(inp, start, mid, end);
  }
}

void merge(int* inp, int start, int mid, int end) {
  int head1 = start;
  int head2 = mid + 1;
  int* scratchPad = new int[end - start + 1];
  int scratchPtr = 0;

  while (head1 <= mid && head2 <= end) {
    if (inp[head1] < inp[head2]) {
      scratchPad[scratchPtr++] = inp[head1++];
    } else {
      scratchPad[scratchPtr++] = inp[head2++];
    }
  }

  while (head1 <= mid) scratchPad[scratchPtr++] = inp[head1++];

  while (head2 <= end) scratchPad[scratchPtr++] = inp[head2++];

  for (int offset = 0; offset < (end - start + 1); offset++) {
    inp[start + offset] = scratchPad[offset];
  }

  delete[] scratchPad;
}
