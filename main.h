#include <iostream>
#include <iterator>

#include "qsort.h"
#include "mergeSort.h"

#include <mach/mach_time.h>
#define ORWL_NANO (+1.0E-9)
#define ORWL_GIGA UINT64_C(1000000000)

static double orwl_timebase = 0.0;
static uint64_t orwl_timestart = 0;

void testSortingMethod(struct method *, int *, int);
void printArray(int*, int);
struct timespec orwl_gettime(void);

struct method{
  void (*method) (int*, int, int);
  char methodName[64];
};
