#include <stdio.h>

int main()
{
    int n, frames, i, j, k;
    int pages[50], frame[20];
    int faults = 0, found, pos;
    int farthest, next;

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
            faults++;
            pos = -1;

            for (j = 0; j < frames; j++)
            {
                if (frame[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            if (pos == -1)
            {
                farthest = -1;

                for (j = 0; j < frames; j++)
                {
                    next = -1;

                    for (k = i + 1; k < n; k++)
                    {
                        if (pages[k] == frame[j])
                        {
                            next = k;
                            break;
                        }
                    }

                    if (next == -1)
                    {
                        pos = j;
                        break;
                    }

                    if (next > farthest)
                    {
                        farthest = next;
                        pos = j;
                    }
                }
            }

            frame[pos] = pages[i];
        }

        printf("%d\t", pages[i]);

        for (j = 0; j < frames; j++)
        {
            if (frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }

        if (!found)
            printf("F");

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    printf("Total Page Hits = %d\n", n - faults);

    return 0;
}
