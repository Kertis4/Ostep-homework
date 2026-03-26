#include <bits/types/struct_timeval.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
int main() {

  struct timeval tStart;
  struct timeval tEnd;

  int fd = open("test.txt", O_RDONLY);

  if (fd < 0) {
    perror("open");
    return 1;
  }

  char buf[64];

  int i = 0;
  double calls = 500000.0;
  int startTime = gettimeofday(&tStart, NULL);
  while (i < calls) {

    ssize_t n = read(fd, buf, 0);
    ++i;
  }

  int endTime = gettimeofday(&tEnd, NULL);

  long difSec = tEnd.tv_sec - tStart.tv_sec;
  long difMSec = tEnd.tv_usec - tStart.tv_usec;

  if (difMSec < 0) {
    difSec -= 1;
    difMSec += 100000;
  }

  double totalMicro = (difSec * 100000.0) + difMSec;
  double timePerCall = totalMicro / calls;
  printf("Total time: %ld.%06ld seconds\n", difSec, difMSec);

  printf("Time per call: %.4f microseconds \n", timePerCall);
}
