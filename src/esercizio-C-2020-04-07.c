#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap (char **a, char **b)
{
    char *c = *a;
    *a = *b;
    *b = c;
}

char *make_random_word (char *word)
{
    char **words = (char **) malloc (sizeof (char *));
    int c = 0, tot = 0; //c contatore, tot lunghezza totale di tutte le parole
    char *token = strtok (word, " ");

    while (token)
    {
        words[c++] = token;
        tot += strlen (token);
        token = strtok (NULL, " ");
        words = realloc (words, (c + 1) * sizeof (char *));
    }

    srand (time (NULL));
    for (int i = 0; i < c * c; i++) //Mischio 'c*c' volte
        swap (words + (rand () % c), words + (rand () % c));

    char *random_word = calloc (tot + c, sizeof (char)); //'c-1' spazi e il terminatore
    for (int i = 0; i < c; i++) //Concateno le parole mischiate
    {
        strcat (random_word, words[i]);
        if (i < c - 1) //Spazio fra le parole
            strcat (random_word, " ");
    }
    return random_word;
}

int main ()
{
    char word[80];
    strcpy (word, "hello world mi chiamo pino sono date delle stringhe");
    printf ("Input: %s,\noutput: %s.\n", word, make_random_word (word));
    return 0;
}
