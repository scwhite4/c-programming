#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/*
int main (int argc, char **argv)
{
  int aflag = 0;
  int bflag = 0;
  char *cvalue = NULL;
  int index;
  int c;

  opterr = 0;

  while ((c = getopt (argc, argv, "abc:")) != -1)
    switch (c)
      {
      case 'a':
        aflag = 1;
        break;
      case 'b':
        bflag = 1;
        break;
      case 'c':
        cvalue = optarg;
        break;
      case '?':
        if (optopt == 'c')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }

  printf ("aflag = %d, bflag = %d, cvalue = %s\n",
          aflag, bflag, cvalue);

  for (index = optind; index < argc; index++)
    printf ("Non-option argument %s\n", argv[index]);
  return 0;
}
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
      /*case 'c':
        cvalue = optarg;
        break;
      case '?':
        if (optopt == 'c')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();*/
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

