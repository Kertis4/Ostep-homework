#include <stdio.h>
#include <sys/time.h>

int main() {
  struct timeval tStart;
  struct timeval tEnd;

  int i = 0;
  int calls = 10000;

  int startTime = gettimeofday(&tStart, NULL);
  while (i < calls) {
    // context switch logic goes here

    ++i;
  }
  int endTime = gettimeofday(&tEnd, NULL);

  long difSec = tEnd.tv_sec - tStart.tv_sec;
  long difMSec = tEnd.tv_usec - tStart.tv_usec;

  if (difMSec < 0) {
    difSec -= 1;
    difMSec += 1000000;
  }
  double TotalMicro = (1000000.0 * difSec) + difMSec;
  double TimePerCall = TotalMicro / (double)calls;

  printf("It took %f microseconds to make %d context switches \n", TotalMicro,

         calls);
  printf("That is 1 conext switch every %.4f microseconds \n", TimePerCall);
}
