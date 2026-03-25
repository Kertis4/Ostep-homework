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

  int startTime = gettimeofday(&tStart, NULL);
  while (i < 10000) {

    ssize_t n = read(fd, buf, 0);
    ++i;
  }

  int endTime = gettimeofday(&tEnd, NULL);

  int difSec = tEnd.tv_sec - tStart.tv_sec;
  int difMSec = 0;
  if (difSec > 0) {
    difSec -= 1;
    difMSec += 100000;
  }
  difMSec += tEnd.tv_usec - tStart.tv_usec;

  printf("It took %d.%d seconds.microseconds to run 10000 0 byte reads \n",
         difSec, difMSec);

  int timePerCall = 10000 / difMSec;
}
