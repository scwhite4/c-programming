#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<ctype.h>

int main(void)
{

	
















	char name[16] = {'\0'};

	int i = 1;

	//int j = 10;

	while(i != 0)
	{
		printf("I’ve spun your straw into gold now guess my name: \n");

		fgets(name, sizeof(name), stdin);

		name[strcspn(name, "\r\n")] = 0;

		name[15] = 0;


		for (int e = 0; e < 15; e++)
		{
			if (isdigit(name[e]))
			{
				printf("Invalid input, try again!\n");
				return -1;
			}
		}

		i = strcasecmp(name, "rumpelstiltskin");

		if (i == 0) 
    		{
        	    	printf("Who told you!\n");
			return 0;
    		}
	    	else
		{
			printf("Wrong, try again!\n");
			return -1;
		}
        	   
    	}

    	return 0;
}
