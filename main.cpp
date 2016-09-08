#include "main.h"

int main() {
  const int inpSize = 7;
  int inp[inpSize] = {5, 8, 1, 3, 7, 9, 2};


  struct method methodList[2];

  methodList[0].method = qsort;
  strcpy(methodList[0].methodName, "Quick Sort");
  methodList[1].method = mergeSort;
  strcpy(methodList[1].methodName, "Merge Sort");

  for (int methodIndex = 0; methodIndex < 2; methodIndex++) {
    testSortingMethod(&methodList[methodIndex], inp, inpSize);
  }
}

void testSortingMethod(struct method *methodStruct, int *inp, const int inpSize) {
  int *inpCopy = new int[inpSize];
  memcpy(inpCopy, inp, inpSize * sizeof(int));

  timespec startTime = orwl_gettime();
  methodStruct->method(inpCopy, 0, inpSize - 1);
  timespec endTime = orwl_gettime();

  std::cout<<"Elapsed Time for " << methodStruct->methodName << ": ";
  std::cout<<(endTime.tv_nsec - startTime.tv_nsec)<< "ns" <<std::endl;

  printArray(inpCopy, inpSize);

  delete[]  inpCopy;
}

void printArray(int* inp, int inpSize) {
  for (int i = 0; i < inpSize; i++) {
    std::cout<<inp[i]<<" ";
  }
  std::cout<<std::endl;
}

//taken from http://stackoverflow.com/a/5167506/1291435
struct timespec orwl_gettime(void) {
  // be more careful in a multithreaded environement
  if (!orwl_timestart) {
    mach_timebase_info_data_t tb = { 0 };
    mach_timebase_info(&tb);
    orwl_timebase = tb.numer;
    orwl_timebase /= tb.denom;
    orwl_timestart = mach_absolute_time();
  }
  struct timespec t;
  double diff = (mach_absolute_time() - orwl_timestart) * orwl_timebase;
  t.tv_sec = diff * ORWL_NANO;
  t.tv_nsec = diff - (t.tv_sec * ORWL_GIGA);
  return t;
}
