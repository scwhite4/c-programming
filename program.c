#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>
#include <getopt.h>
#include <stdint.h>

/*
 * This is the practice test for C programming.
 * Enter your details below
 *
 * RANK: {2LT}
 * NAME: {Seth White}
 * DATE: {27July2018}
 *
 * Add code to accomplish the task for each question.
 * Do not change the function prototypes given below.
 * You should include any header files needed by your answers. 
 * Follow instructions given by your instructor for submitting.
 * Do not move, remove, or modify the preprocessor statements (#ifdef/#endif)
 * You can perform a basic test of your code with "make checkit"
 * The basic tests will *NOT* check all possibilities to be checked by grading.
 */


#ifndef SUPPRESS_PRACTICE_QUESTION_1

/*
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
}

#endif //SUPPRESS_PRACTICE_QUESTION_1


#ifndef SUPPRESS_PRACTICE_QUESTION_2
/*
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


  for(int i = 0; i < arrayLen; i++)
	{
		if(array[i][0] == key)
		{
		return array[i][0] + array[i][1] + array[i][2];
		}
	}

  return -1;  
}


#endif //SUPPRESS_PRACTICE_QUESTION_2


#ifndef SUPPRESS_PRACTICE_QUESTION_3
/*
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


struct s
{
	char a[31];
	unsigned int b;
	float c;
};



void *practice_q3()
{


  struct s* sp = malloc(1 * sizeof(struct s));
  strcpy(sp->a, "C programming for the LULZ");
  sp->b = 0xC0FFEE00;
  sp->c = 3.1415;




  return sp; 
}

#endif //SUPPRESS_PRACTICE_QUESTION_3

#ifndef SUPPRESS_PRACTICE_QUESTION_4
/*
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
	if(fgets(buffer,sizeof(buffer),stdin) == NULL)
	{
		return 1;
	}
	else
	{
		fprintf(stdout,"%s",buffer);
 	}
	if(fgets(buffer,sizeof(buffer),stdin)== NULL)
	{
		return 1;
	}
	else
	{
		fprintf(stderr,"%s", buffer);
	}
	return 0;
}





#endif //SUPPRESS_PRACTICE_QUESTION_4

#ifndef SUPPRESS_PRACTICE_QUESTION_5
/* 
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

  unsigned int returnBit = 0;

  if(numericValue > 0)
	{
	returnBit |= 0x1;
	}

  else if(numericValue == 0)
	{
	returnBit |= 0x2;
	}

  else
	{
	returnBit |= 0x4;
	}

  if(numericValue%2 == 0)
	{
	returnBit |= 0x8;
	}

  else
	{
	returnBit |= 0x10;
	}

  if(message == NULL)
	{
	returnBit |= 0x20;
	}

  else if(strlen(message) < 1)
	{
	returnBit |= 0x40;
	}

  return returnBit;
}

#endif //SUPPRESS_PRACTICE_QUESTION_5




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

void orderParms(short *p1, short *p2)
{
	if (*p1 < *2) //acending order declaration here
	{
		//do nothing
		printf("Already in order\n");
	}
	else
	{
		//swap the values if not in ascending order
		//set the value for what p1 holds to
		short temp = *p1;
			*p1 = *p2;
			*p2 = temp;
			printf("Swapped the values\n");
	}
}


//code below already given on test
int main()
{
	short p1 = 10; //values in order
	short p2 = 20;
	
	//original
	orderParms(&p1, &p2);
	printf("First is %d second is %d\n", p1, p2);

	p1 = 99; //these two values are not in order
	p2 = 50;

	//swap
	orderParms(&p1, &p2);
	printf("First is %d second is %d\n", p1, p2);
}




/* ++++++++++++++++++++ GetOpt ++++++++++++++++++++
*/

int main(int argc, char ** argv){


	/*
		Initialize all of the flags to 0 (false) 
	*/
	int add = 0; 
	int subtract = 0; 
	int multiply = 0; 
	int divide = 0; 


	/*
		Loop through all of the argument flags: 
	*/
	int c; 
	//Note that there are no colons after any of the flags (they don't require arguments) 
	//For instance, you use ./get -a 2 2, where -a doesn't take any argument. 
	while((c = getopt(argc,argv,"asmd"))!=-1){
		switch(c){
			case 'a': 
				if(subtract || multiply || divide)
					return 1; 
				add = 1; 
				//printf("Adding\n");
				break; 
			case 's': 
				if(add || multiply || divide)
					return 1; 
				subtract = 1; 
				//printf("Subtracting\n");
				break; 
			case 'm': 
				if(add || subtract || divide)
					return 1; 
				multiply = 1; 
				//printf("Mult\n");
				break; 
			case 'd': 
				if(add || subtract || multiply)
					return 1;
				divide = 1; 
				//printf("Div\n");
				break; 
			case '?': 
				return 1; 
				//printf("Don't know what that is.\n");
				break; 
		}
	}


	//If there aren't two numbers after the flags
	if(argc - optind < 2){
		printf("You need 2 operands!\n");
		return 1;
	}

	//Get the operands, which are the arguments given after the flags. 
	int num1 = atoi(argv[optind]);
	int num2 = atoi(argv[optind+1]);
	

	//Check which flag is set to true, and return the result of that operation
	if(add)
		printf("The sum of %d and %d is %d\n",num1,num2,num1 + num2);
	if(subtract)
		printf("%d minus %d is %d\n",num1,num2,num1 - num2);
	if(multiply)
		printf("The product of %d and %d is %d\n",num1,num2,num1 * num2);
	if(divide){
		if(num2 == 0){
			printf("You can't divide by zero.\n");
			return 1; 
		}else
			printf("%d divided by %d is %d\n",num1,num2,num1 / num2);
	}
	return 0;
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




/* ++++++++++++++++++++ Read Input from Stream ++++++++++++++++++++
*/
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
