#include <stdio.h>

int main()
{
    int n, frames, i, j, k;
    int pages[50], frame[20];
    int pointer = 0, faults = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for (i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\n");

    for (i = 0; i < n; i++)
    {
        found = 0;

        for (j = 0; j < frames; j++)
        {
            if (frame[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            frame[pointer] = pages[i];
            pointer = (pointer + 1) % frames;
            faults++;
        }

        printf("%d\t", pages[i]);

        for (k = 0; k < frames; k++)
        {
            if (frame[k] == -1)
                printf("- ");
            else
                printf("%d ", frame[k]);
        }

        if (!found)
            printf("F");

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    printf("Total Page Hits = %d\n", n - faults);

    return 0;
}
                  