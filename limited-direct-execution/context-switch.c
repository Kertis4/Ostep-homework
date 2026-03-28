#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
int main() {
  int p1[2], p2[2];
  pipe(p1);
  pipe(p2);

  struct timeval tStart;
  struct timeval tEnd;

  int i = 0;
  int calls = 10000;
  char buf = 'x';

  pid_t pid = fork();

  if (pid == 0) {
    while (i < calls) {
      read(p1[0], &buf, 1);
      write(p2[1], &buf, 1);

      ++i;
    }
    return 0;
  }

  int startTime = gettimeofday(&tStart, NULL);
  while (i < calls) {
    write(p1[1], &buf, 1);
    read(p2[0], &buf, 1);
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
  double TimePerCall = TotalMicro / ((double)calls * 2);

  printf("It took %f microseconds to make %d context switches \n", TotalMicro,

         (calls * 2));
  printf("That is 1 conext switch every %.4f microseconds \n", TimePerCall);
}
