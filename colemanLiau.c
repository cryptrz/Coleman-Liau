#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(int argc, char(*argv[]))
{
    //Get the text from the user
    char text[3000];
    printf("Text: ");
    fgets(text, 3000, stdin);

    //Check if text is empty and quit if it is
    if (text[0] == '\0'){
        return 1;
    }

    int nbLetters = 0;
    int nbWords = 1;
    int nbSentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {

        //Count letters
        if (isalpha(text[i]))
        {
            nbLetters++;
        }

        //Count words (spaces + 1)
        if (text[i] == ' ')
        {
            nbWords++;
        }

        //Count sentences
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            nbSentences++;
        }
    }

    //Calcultate average nb letters
    float averageLetters = ((float) nbLetters / (float) nbWords) * 100;

    //Calculate average nb sentences
    float averageSentences = ((float) nbSentences / (float) nbWords) * 100;

    //Calculate grade
    float grade = 0.0588 * averageLetters - 0.296 * averageSentences - 15.8;
    int result =  (int) round(grade);

    //Print the result
    if (result > 16)
    {
        printf("Grade 16+\n");
    }
    else if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else{
        printf("Grade %i\n", result);
    }
}
