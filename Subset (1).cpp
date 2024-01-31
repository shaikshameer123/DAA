#include <stdio.h>
#include <stdlib.h>
void subsets(int set[], int n)
{
	int i,j;
    for (i = 0; i < (1 << n); i++)
	{
        printf("{ ");
        for (j = 0; j < n; j++)
		{
            if (i & (1 << j)) {
                printf("%d,", set[j]);
            }
        }
        printf("}\n");
    }
}

int main() 
{
    int i,j,n;

    printf("Enter the size of the set: ");
    scanf("%d", &n);
	int set[n];
    printf("Enter the elements of the set:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Subsets of the given set:\n");
    subsets(set, n);

    //free(set);
    return 0;
}
