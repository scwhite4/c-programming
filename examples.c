#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>
#include <getopt.h>
#include <stdint.h>




/* ++++++++++++++++++++ General Question ++++++++++++++++++++
 * Correct the practice_q1 function so that properly computes the 
 * sum of all the parameters and returns it.
 * if (practice_q1(111, 222, 333, 444) != 1110)
 * {
 *   printf("Incorrect\n");
 * }
 */

long practice_q1(int parm1, int parm2, int parm3, int parm4)
{
  long sum = 0;
  sum = sum + parm1;
  sum += parm2;
  sum = sum + parm3;
  sum = sum + parm4;
  return sum;
	
	//could also return parm1 + parm2 + parm3 + parm4;
}




/* ++++++++++++++++++++ Two Dimensional Array ++++++++++++++++++++
 * For practice_q2, use the input to produce the desired output described below.
 * See the example call.
 * Parameters:
 * array is defined as an two dimensional integer array.
 *    The first dimension is allocated with arrayLen members.
 *    The second dimension is defined as 3 integers.
 * key is the first int in the second dimension that is sought.
 *
 * Steps to complete:
 * 1. Find the first member in the second dimension which matches the key parameter.
 * 2. Once the member is located, return the sum of all 3 integers in the second dimension.
 * 3. If the key is not found as the first integer in the second dimension, return -1.
 *
 * An illustrative example call:
 * int array[][3] = {{20,   61,  82},
 *                   {65,   19,  25},
 *                   {128, 325, 900},
 *                   {42, 165,   92},
 *                   {91, 78,   105},
 *                   {512, 22,   75}};
 * int arrayLen = sizeof(array)/sizeof(array[0]);
 * int key = 42;
 * int expected = 42 + 165 + 92;
 * if (practice_q2(array, arrayLen, key) != expected)
 * {
 *   printf("Incorrect\n");
 * }
 * NOTE: This code will not compile and run properly, it is only illustrative 
 * of the concept and what is expected.
 */

int practice_q2(int **array, int arrayLen, int key)
{
  int sum;

  if(key == NULL)
	return -1;

  for(int i = 0; i < arrayLen; i++)
	{
	for(int j = 0; j < 3; j++)
		{
		if(array[i][j] == key)
			{
			sum = array[i][0] + array[i][1] + array[i][2];
			return sum;
			}
		}
	}
  return INT_MAX;  
}

//Alternative
/*
int practice_q2 (int **array, int arrayLen, int key)
{

  int sum;


  for (int i = 0; i < arrayLen; i++)
    {

      if (**(array + i) == key)
	{
	  sum = array[i][0] + array[i][1] + array[i][2];
	  return sum;
	}

    }
 
  return -1;
}
*/




/* ++++++++++++++++++++ Structure ++++++++++++++++++++
 * For practice_q3, create a structure using the order and types specified.
 * The name of the structure members are NOT important, the ORDER and TYPE is.
 * Once the structure is created, create a pointer to this type on the heap 
 * and set the value of the members to those listed in the value column below.
 * 
 * Order  Type                             Value
 * -----  ----                             -----
 *  1     char array 31 bytes in length    "C programming for the LULZ"
 *  2     unsigned integer                 0xC0FFEE00
 *  3     float                            3.1415
 *  
 * Return the pointer you allocated without freeing it. 
 */

void *practice_q3()
{
  struct member
  {
	char phrase[31];
	unsigned int intNumber;
        float number;
  };
  if(member)
	{
  struct member* pointer = (struct member*) malloc(sizeof(struct member)); 
  strcpy(pointer->phrase,"C programming for the LULZ");
	//memset(ret,0,sizeof(struct member)); //optional
  pointer->intNumber = 0xC0FFEE00;
  pointer->number = 3.1415;
		
		//if copying to int array you can add to index, or add using memcpy.
		/*
		memcpy(p->arr, arr 0, sizeof(int) * num of elemts)
		*/
	}
  return pointer; 
}

//Alternative
/*
struct Duck {
//typedef struct Duck {
     char a[31];
     unsigned int b;
     float c;
 };
 
void *practice_q3 ()
{
       struct Duck *f = (struct Duck*) malloc(sizeof(struct Duck));
       //Duck *f = (Duck*) malloc(sizeof(Duck));
       strcpy(f->a, "C programming for the LULZ");
       f->b = 0xC0FFEE00;
       f->c = 3.1415;
       return f;
}
*/


/* ++++++++++++++++++++ Read Input from Stream ++++++++++++++++++++
 * For practice_q4, read a line from the standard input stream (up
 * to 100 bytes in length) and print it out to the standard output 
 * stream. Read another line in (up to 100 bytes) and print it out
 * to the standard error stream. Ensure that only one new line is
 * present on the output. Return 0 to the caller upon completion 
 * unless an error occurs. If an error occurs, return 1.
 *
 * NOTE: No more than 100 bytes, including the newline, for each
 * call will be provided to your function.
 *
 * Assume your function will be called like this:
 * int main()
 * {
 *   practice_q4();
 *   return 0;
 * }
 */
int practice_q4()
{
  char buffer [101];// given bytes +1 = 100+1
	if(fgets(buffer,sizeof(buffer),stdin)== NULL)
	{
		return 1;
	}
	else
	{
		fprintf(stdout,"%s",buffer);
 	}
	if(fgets(buffer,sizeof(buffer),stdin)!= NULL)
	{
	  fprintf(stderr,"%s", buffer);
	  buffer[strcspn(buffer,"\n")] = '\0';
	  return 0;	
	} 
    	return 0;
}

//Alternative

int myFunc()
{
	char buffer[1024];					//creates buffer greater than required
	fgets(buffer,sizeof(buffer),stdin); 	//takes in user input
	buffer[strcspn(buffer,"\n")] = '\0';	//removes extra new lines from user input
									//may want to add +1 after \n then remove \n from below
	
	/*
	if the word bacon is in the buffer then output an error
	*/
	if(strstr(buffer,"Bacon ") == buffer)	//checks if word is in buffer and returns pointer to where it found it which would be buffer
	{	
		fprintf(stderr,"%s\n", buffer);	//outputs a standard error
	}	
	/*
	if bacon is not in the word then output the word
	*/
	else
	{
		fprintf(stdout,"%s\n",buffer);
	}
	//return 0 from the function
	return 0;


}

int main(void)
{
	myFunc();
}


/* ++++++++++++++++++++ Bitwise ++++++++++++++++++++
 * For practice_q5, validate the input parameters and return a 
 * bit mask as specified:
 * if numericValue is positive, set return bit 0x1 to on(1).
 * if numericValue is zero, set return bit 0x2 to on(1).
 * if numericValue is negative, set return bit 0x4 to on(1).
 * if numericValue is even, set return bit 0x8 to on(1).
 *     Assume 0 is an even number for this exercise.
 * if numericValue is odd, set return bit 0x10 to on(1).
 * if message is NULL, set return bit 0x20 to on(1).
 * if message is not NULL and the length of message < 1, 
 *     set return bit 0x40 to on(1).
 * Return the composite number you created to the caller
 */
unsigned int practice_q5(int numericValue, char *message)
{

unsigned int returnValue = 0;
if(numericValue > 0)
{
	returnValue |= 0x1;
}else  if(numericValue == 0)
{
	returnValue |= 0x2;
}else
{
	returnValue |= 0x4;
}


if((numericValue%2)==0 || numericValue ==0  )
{
	returnValue |= 0x8;
}else
{
	returnValue |= 0x10;
}



 if(message==NULL)
{
	returnValue |= 0x20;
}else if(message!= NULL && strlen(message) < 1)
{
	returnValue |= 0x40;
}


	return returnValue;
}




/* ++++++++++++++++++++ Read Input from File ++++++++++++++++++++
*/
int file_read (const char *path, const int lineNumber, const *buffer)
{
FILE *file= fopen(path,"r");
if(!file) {
    fprintf(stderr, "unable to open %s\n", path);
    return -1;
}
char temp[65];
int i = 1;
while(fgets(temp, 64, file) != NULL) {
    if(i++ == lineNumber) {
        memset(buffer, 0, 64);
        strncpy(buffer, temp, 64);
        fclose(file);
        printf("line size is %lu\n", strlen(buffer));
        return strlen(buffer);
    }
}
fclose(file);
printf("NOPE\n");
return -1;

//Alternative

int main()
{
    char buf[1024] = {0};
    FILE* fp = fopen("sshd_config","r");
    if(!fp)
    {
		fprintf(stderr,"error opening file\n");
		exit(EXIT_FAILURE);
    }

    char** content = malloc(sizeof(char*));
    if(!content)
    {
        fprintf(stderr,"line allocation failed\n");
		exit(EXIT_FAILURE);
    }

    int linesRead = 0;
    int linesAllocated = 1;

    while(fgets(buf,1024,fp))
    {
		content[linesRead] = malloc(sizeof(char)*strlen(buf)+1);
		if(!content[linesRead])
		{
        	fprintf(stderr,"line allocation failed\n");
	    	// Should free what we can here before we exit
	    	exit(EXIT_FAILURE);
		}
		linesRead++;
		if(linesRead > linesAllocated)
		{
			linesAllocated *= 2;
			char** tmp = realloc(content,linesAllocated*sizeof(char*));
			if(!tmp)
			{
		    	fprintf(stderr,"reallocation failed\n");
		    	// Should free what we can here before we exit
		    	exit(EXIT_FAILURE);
			}
			content = tmp;
		}
		if((*buf != '\n') && (*buf != '#'))
		{
		strcpy(content[linesRead-1],buf);
		}
		else
		{
		linesRead -= 1;
		}
    }
    
	fclose(fp);
    for(int i = 0; i < linesRead; i++)
		printf("%s",content[i]);

    // Should free what we've allocated before we return
    return 0;
}

//Alternative

int line_Finder(char* buffer, int lineNumber);

int main()
{
	char* buffer[128];
	line_Finder(*buffer, 5);
}

int line_Finder(char* buffer, int lineNumber)
{
	FILE* fp = fopen("scwtest.txt", "r");
	if(!fp)
	{
		fprintf(stderr, "The fopen function failed!\n");
		return(EXIT_FAILURE);
	}

	int counter = 1;
	char line[128] = {0};

	while(fgets(line,sizeof(line),fp) != NULL)
	{
		if(strstr(line, "Seth") == line) //(counter == lineNumber)
		{
			memset(buffer, 0, 64);
			strncpy(buffer, line, 63);
			fclose(fp);
			printf("%s",line);
			return strlen(buffer);
		}
		counter++;
	}
	
	
	return -1;
	
}




/* ++++++++++++++++++++ Getopt ++++++++++++++++++++
*/
int main (int argc, char **argv)
{
  int fflag = 0;
  int nflag = 0;
  int lflag = 0;
  int x = 0;
  char *cvalue = NULL;
  int index;
  int c;
  char* f;
  char* n;
  char* l;
   

  opterr = 0;

  while ((c = getopt (argc, argv, "f:n:l:")) != -1)
    switch (c)
      {
      case 'f':
        fflag = 1;
	f = optarg;
        break;
      case 'n':
        nflag = 1;
	n = optarg;
        break;
      case 'l':
        lflag = 1;
	l = optarg;
        break;
      }

   if(fflag) 
   {
	printf("%s\n", f);
   }
   if(nflag) 
   {
   	printf("%s\n", n);
   }
   if(lflag) 
   {
	printf("%s\n", l);
   }

  for (index = optind; index < argc; index++)
    printf ("%s\n", argv[index]);
  return 0;
}


/* ++++++++++++++++++++ Swap ++++++++++++++++++++
*/

int main(void)
{

}

void mySwapFunc(int* a, int* b)//swaps these two values
{
	
	int temp = *a;
	*a = *b;
	*b = temp;
}



/* ++++++++++++++++++++ MinMax ++++++++++++++++++++
*/

int main()
{

//PassedCode
unsigned char arr[] = {19, 15, 18, 4, 199, 45, 63, 82, 85, 186, 244};
size_t arrLen = sizeof(arr)/sizeof(arr[0]);


//Mycode
unsigned char minimum = UINT8_MAX;
unsigned char maximum = 0;

for (int i=0; i < arrLen; i++)
{
	if (arr[i] < minimum)
	{
		minimum = arr[i];
	}
	if (arr[i] > maximum)
	{
	maximum = arr[i];
	}
}
printf("Minimum %u\n", minimum);
printf("Maximum %u\n", maximum);

return 0;
}




/* ++++++++++++++++++++ Qsort ++++++++++++++++++++
*/
int compare(const void* a, const void* b)//function to compare the numbers
{
    int* thingA = (int *)a;
    int* thingB = (int *)b; 	
    return (*thingA - *thingB);
    /*a-b = ascending	
	b-a = descending*/
}

int main(void)
{
	const int num_elem = 10;
	int elements[] = {2,6,1,9,8,2,0,5,7,4};

	/*
	qsort((array, size of array, size of each number (type of arrray), compare func to use
	*/
	qsort((void *)elements, num_elem,sizeof(int), &compare);
	

	/*
	prints out the final array
	*/
	for(int index = 0; index < 10; index++)
	{
	printf("%d\n",elements[index]);
	}

	return 0;
}

//Alternative

int compare_int( const void* a, const void* b ) 
{ 
     if( *(int*)a == *(int*)b ) return 0;
     return *(int*)a < *(int*)b ? -1 : 1;
}  

int main(void)
{
    const size_t num_elem = 10;
    int elements[num_elem] = { 3, 6, 1, 9, 8, 2, 0, 5, 7, 4 };
    qsort( elements, num_elem, sizeof(int), compare_int );
}



/* ++++++++++++++++++++ Swap ++++++++++++++++++++
*/

