#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>

int main(void)
{
  srand((unsigned)time(NULL));
  char text[41] = { '\0' };
  int index;
  for(index = 0; index < 40; index++)
  {
    if( rand() % 2 ) // 0 or 1, uppercase or lowercase
      text[index] = rand() % 26 + 65; // uppercase
    else
      text[index] = rand() % 26 + 97; // lowercase
  }

  /* Student implementation */
  
  
  for(int i = 0; i < 40; i++)
  {
      if((text[i] <= 'M') || ((text[i] >= 'a') && (text[i] <= 109)))
      {	
      text[i] = text[i] + 13;
      }
      else if(((text[i] > 77) & (text[i] < 91)) || (text[i] > 109))
      {
      text[i] = text[i] - 13;
      }
     
  }

	printf("%s", text);

  return 0;
}
