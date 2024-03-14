#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(char *text)
{
    int letters = 0;
    int text_len = strlen(text);
    for (int i = 0; i < text_len; i++)
    {
        if (('a' <= text[i] && text[i] <= 'z') || ('A' <= text[i] && text[i] <= 'Z'))
        {
            letters += 1;
        }
    }
    return letters;
}

int count_words(char *text)
{
    int words = 0;
    int text_len = strlen(text);
    for (int i = 0; i < text_len; i++)
    {
        if (text[i] == ' ')
        {
            words += 1;
        }
    }
    if (text[text_len - 1] != ' ')
    {
        words += 1;
    }
    return words;
}

int count_sentences(char *text)
{
    int sentences = 0;
    int text_len = strlen(text);
    for (int i = 0; i < text_len; i++)
    {
        if (text[i] == '.' || (text[i] == '!') || (text[i] == '?'))
        {
            sentences += 1;
        }
    }
    return sentences;
}
float avg_letters(int letters, int words)
{
    float avg_letters = 0;
    avg_letters = ((float) letters / words);
    avg_letters *= 100;
    return avg_letters;
}

float avg_sentences(int sentences, int words)
{
    float avg_sentences = 0;
    avg_sentences = ((float) sentences / words);
    avg_sentences *= 100;
    return avg_sentences;
}

int main(void)
{

    // prompt user for some text
    char text[5000];
    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    // count numbers of letters, words and sentences in text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // compute result
    float L = avg_letters(letters, words);
    float S = avg_sentences(sentences, words);

    int result = round(0.0588 * L - 0.296 * S - 15.8);

    // print grade lvl
    if (result >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", result);
    }
}
