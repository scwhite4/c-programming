#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int compare(const void* a, const void* b);

int main(void)
{
  int array[1024] = { 0 };

  /* Fill array with random numbers */
  srand((unsigned)time(NULL));

  int index;
  for(index = 0; index < 1024; index++)
    array[index] = rand() % 100;
  /* ------------------------------- */\


  //const size_t num_elem = 1024;
  qsort( array, index, sizeof(int), compare);

  for(index = 0; index < 1024; index++)
	printf("%d\n", array[index]);
  /* Student implementation */

  return 0;
}

int compare(const void* a, const void* b)
{

  if( *(int*)a == *(int*)b ) return 0;
  return *(int*)a > *(int*)b ? -1 : 1;
  /* Student implementation */
}
