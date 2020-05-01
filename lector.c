#include <stdio.h>
#include <stdlib.h> // For exit()

int main()
{
    FILE *fptr;

    // Open file
    fptr = fopen("example.txt", "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
  char c;
    // Read contents from file
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }

    fclose(fptr);
    return 0;
}
