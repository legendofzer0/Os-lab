#include <stdio.h>

int main()
{
    int t[20], n, i, tohm[20], tot = 0;
    float avhm;

    printf("Enter the number of tracks: ");
    scanf("%d", &n);

    printf("Enter the tracks to be traversed: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }

    for (i = 0; i < n - 1; i++) {
        tohm[i] = t[i + 1] - t[i];
        if (tohm[i] < 0)
            tohm[i] = tohm[i] * (-1);
    }

    for (i = 0; i < n - 1; i++) {
        tot += tohm[i];
    }

    avhm = (float)tot / n;

    printf("Tracks traversed\tDifference between tracks\n");
    for (i = 0; i < n - 1; i++) {
        printf("%d\t\t\t%d\n", t[i], tohm[i]);
    }
    printf("\nTotal Head movement is: %d",tot);
    printf("\nAverage header movements: %.2f\n", avhm);

    return 0;
}
