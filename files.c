#include <stdio.h>
#include <string.h>

int countWordsFromFile()
{
    int wordCount = 0;
    FILE *fptr;
    char ch, prevCh = ' ';

    fptr = fopen("words.txt", "r");
    if (fptr == NULL)
    {
        perror("Error opening file");
        return -1;
    }

    ch = fgetc(fptr);
    while (ch != EOF)
    {
        if (ch == ' ' || ch == '\n' || ch == '\t')
        {
            if (prevCh != ' ' && prevCh != '\n' && prevCh != '\t')
            {
                wordCount++;
            }
        }
        prevCh = ch;
        ch = fgetc(fptr);
    }

    if (prevCh != ' ' && prevCh != '\n' && prevCh != '\t')
        wordCount++;

    fclose(fptr);
    return wordCount;
}

int main()
{
    int ans = countWordsFromFile();
    if (ans == -1)
        return 1;
    printf("%d\n", ans);
    return 0;
}