#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buf[1024] = {0};
    FILE* fp = fopen("/usr/share/dict/words","r");
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
		strcpy(content[linesRead-1],buf);
    }
    
	
	fclose(fp);

    

    for(int i = 0; i < linesRead; i++)
	{
	char* newlineptr = strchr(content[i], '\n');
	if (newlineptr != NULL)
	*newlineptr = '\0';
	}	

    for(int i = 0; i < linesRead; i++)
	{
	for(int j = 0; j < linesRead; j++)
	{
		printf("Bob \n%s%s\n",content[i],content[j]);
	}
	}

    // Should free what we've allocated before we return
    return 0;
}
