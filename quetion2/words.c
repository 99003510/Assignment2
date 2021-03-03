#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * file;
    char path[100];

    char ch;
    int characters, words, lines;

    /* read mode 'r' */
    file = fopen("file1.txt", "r");


    /* checks if errors are there */
    if (file == NULL)
    {
        
		perror("open");
        
		exit(1);
	
    }

    /*
     * Logic to count characters, words and lines.
     */
    characters = words = lines = 0;
    while ((ch = fgetc(file)) != EOF)
    {
        characters++;

        /* Check new line */
        if (ch == '\n' || ch == '\0')
            lines++;

        /* Check words */
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            words++;
    }

   
    /* Print file details*/
    printf("\n");
    printf("Total characters = %d\n", characters);
    printf("Total words      = %d\n", words);
    printf("Total lines      = %d\n", lines);


    /* Close files to release resources */
    fclose(file);

    return 0;
}