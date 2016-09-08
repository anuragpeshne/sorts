#ifndef QSORT_H_
#define QSORT_H_

#include <iostream>

void qsort(int*, int, int);
int getPivotIndex(int*, int, int);
void swap(int*, int, int);
int divide(int*, int, int, int);

#endif
