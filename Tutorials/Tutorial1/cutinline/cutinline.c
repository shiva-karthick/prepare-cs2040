#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STRING_LEN 30
#define LEN(a) (sizeof(a) / sizeof(*(a)))

// this is just simluating a queue

int main(int argc, char const *argv[])
{
    int no_names, no_instructions;
    scanf("%d", &no_names);
    char **names = malloc(no_names * sizeof(char *));
    for (int i = 0; i < no_names; i++)
    {
        names[i] = malloc(STRING_LEN * sizeof(char));
        scanf("%s", names[i]);
    }

    scanf("%d", &no_instructions);
    // printf("%d\n", no_instructions);

    char *event = malloc(STRING_LEN * sizeof(char));
    char *personA = malloc(STRING_LEN * sizeof(char));
    char *personB = malloc(STRING_LEN * sizeof(char));

    char buffer[100];
    int new_size;

    for (int i = 0; i < no_instructions + 1; i += 1)
    {
        fgets(buffer, 100, stdin);
        sscanf(buffer, "%s", event);

        if (strcmp("cut", event) == 0)
        {
            sscanf(buffer, "%s %s %s", event, personA, personB);
            // printf("%s %s %s\n", event, personA, personB);

            // =================================================

            // Create new array of old size + 1
            new_size = no_names + 1;
            char **temp = malloc(new_size * sizeof(char *));
            for (int i = 0; i < new_size; i += 1)
            {
                temp[i] = malloc(STRING_LEN * sizeof(char));
            }

            // Find index of person B
            int index_personB = 0;
            for (int i = 0; i < no_names; i++)
            {
                if (strcmp(names[i], personB) == 0)
                {
                    index_personB = i;
                    break;
                }
            }

            // Copy names up to index_personB
            for (int i = 0; i < index_personB; i++)
            {
                strcpy(temp[i], names[i]);
            }

            // Insert person A
            strcpy(temp[index_personB], personA);

            // Copy names after index_personB
            for (int i = index_personB + 1; i < new_size; i++)
            {
                strcpy(temp[i], names[i - 1]);
            }

            // Realloc names array
            names = realloc(names, new_size * sizeof(char *));
            for (int i = 0; i < new_size; i += 1)
            {
                names[i] = malloc(STRING_LEN * sizeof(char));
            }

            // Copy temp to names
            for (int i = 0; i < new_size; i += 1)
            {
                strcpy(names[i], temp[i]);
            }

            // print names array
            // printf("names : ");
            // for (int i = 0; i < new_size; i += 1)
            // {
            //     printf("%s ", names[i]);
            // }
            // printf("\n");

            no_names = new_size; // update no_names VERY **IMPORTANT**
            // =================================================
        }
        else if (strcmp("leave", event) == 0)
        {
            sscanf(buffer, "%s %s", event, personA);
            // printf("%s %s\n", event, personA);

            // =================================================

            // create a new temp array of size no_names - 1
            new_size = no_names - 1;

            char **temp = malloc(new_size * sizeof(char *));
            for (int i = 0; i < new_size; i += 1)
            {
                temp[i] = malloc(STRING_LEN * sizeof(char));
            }

            // Copy all data into temp except personA
            int index_personA = 0;
            for (int i = 0; i < no_names; i++)
            {
                if (strcmp(names[i], personA) == 0)
                {
                    index_personA = i;
                    break;
                }
            }

            // Copy names up to index_personA
            for (int i = 0; i < index_personA; i++)
            {
                strcpy(temp[i], names[i]);
            }

            // Copy names after index_personA
            for (int i = index_personA + 1; i < no_names; i++)
            {
                strcpy(temp[i - 1], names[i]);
            }

            // Realloc names array
            names = realloc(names, new_size * sizeof(char *));
            for (int i = 0; i < new_size; i += 1)
            {
                names[i] = malloc(STRING_LEN * sizeof(char));
            }

            // Copy temp to names
            for (int i = 0; i < new_size; i += 1)
            {
                strcpy(names[i], temp[i]);
            }

            // print names array
            // printf("names : ");
            // for (int i = 0; i < new_size; i += 1)
            // {
            //     printf("%s ", names[i]);
            // }
            // printf("\n");

            no_names = new_size; // update no_names VERY **IMPORTANT**

            // =================================================
        }
    }

    for (int i = 0; i < no_names; i += 1)
    {
        printf("%s\n", names[i]);
    }

    return 0;
}
