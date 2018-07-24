#include <stdio.h>
#include <stdlib.h>
#include "program.h"
#define DPT
#define DAU
#define DAG

// Don't alter the main function.  Modify the 'modify_me' function
int main(void)
{
    return modify_me();
}

int modify_me()
{
    system("clear"); // clear screen [optional]
   

    // YOUR CODE HERE
    #ifdef DPT

	printf("Name: Platinum\nSymbol: Pt\nAtomic number: 78");

    #endif

    #ifdef DAU
     
        printf("Name: Gold\nSymbol: Au\nAtomic number: 79");
     
    #endif

    #ifdef DAG
     
        printf("Name: Silver\nSymbol: Ag\nAtomic number: 47");
     
    #endif
 

    
    
    return 0; // don't change this
}
