#include<stdio.h>

#define MAX 25

int main()
{
    int frag[MAX], b[MAX], f[MAX], i, j, nb, nf, temp, best;
    static int bf[MAX], ff[MAX];
    
    
    printf("\nEnter the number of blocks:");
    scanf("%d", &nb);
    
    printf("Enter the number of files:");
    scanf("%d", &nf);
    
    printf("\nEnter the size of the blocks:\n");
    for(i = 1; i <= nb; i++)
    {
        printf("Block %d:", i);
        scanf("%d", &b[i]);
    }
    
    printf("Enter the size of the files:\n");
    for(i = 1; i <= nf; i++)
    {
        printf("File %d:", i);
        scanf("%d", &f[i]);
    }
    
    for(i = 1; i <= nf; i++)
    {
        best = -1;
        for(j = 1; j <= nb; j++)
        {
            if(bf[j] != 1)
            {
                if(b[j] >= f[i])
                {
                    if(best == -1 || b[j] < b[best])
                    {
                        best = j;
                    }
                }
            }
        }
        
        if(best != -1)
        {
            frag[i] = b[best] - f[i];
            ff[i] = best;
            bf[best] = 1;
        }
    }
    
    printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragmentation");
    
    for(i = 1; i <= nf; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
    
    return 0;
}
