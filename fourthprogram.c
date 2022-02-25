/* need to include the timer stuff */
#include <sys/types.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
/* We need to put our diff_time routine */
int diff_time_func (struct timeval *t1, struct timeval *t2)
{
  int diff_time;

  diff_time =
    (int) (t1->tv_sec - t2->tv_sec) * 1000000 + (int) (t1->tv_usec - t2 ->tv_usec);
  if (diff_time < 0)
    printf ("diff_time is negative\n");
  return diff_time;
}

/* our main program finds out the time the computer takes to count up to 100
million
*/
int main ()
{
  struct timeval start, stop;
  int i = 0;
  int nmillions = 0;
  int time_diff = 0;
  gettimeofday (&start, 0);	/* start time */

  for (nmillions = 0; nmillions < 1000; i++)
    {
      do
	{
	  i++;
	}
      while ((i % 1000000) != 0);
      nmillions++;
      //printf ("now at %d million\n", nmillions);
    }
  /* we need to measure the time again */
  gettimeofday (&stop, 0);
  time_diff = diff_time_func (&stop, &start);
  printf ("Time taken:%d microseconds\n", time_diff);
}
