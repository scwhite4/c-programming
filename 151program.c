#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int main(void)
{
  srand((unsigned)time(NULL)); // seed the random number generate with the current time
  int n[100];

  // Initialize each element of n with a random number between 0 and 8192
  int index;
  int max = 0;
  int min = 8192;
  for(index = 0; index < 100; index++)
  {
    n[index] = rand() % 8192;

    if(n[index] > max)
    {
      max = n[index];
    }

    if(n[index] < min)
    {
      min = n[index];
    }	
  }

  printf("%d,%d\n", min, max);


  /* Student implementation */

  return 0;
}
