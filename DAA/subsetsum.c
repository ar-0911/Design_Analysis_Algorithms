#include <stdio.h>
#define MAX 100

int set[MAX];
int subset[MAX];
int n, sum;
int count;

void backtrack(int i, int s)
{
    if (s == sum)
    {
        printf("Subset %d: ", ++count);
        for (int j = 0; j < i; j++)
        {
        	if(subset[j]==0){
        		continue;
			}
            printf("%d ", subset[j]);
        }
        printf("\n");
        return;
    }

    if (i == n || s > sum)
    {
        return;
    }

    subset[i] = set[i];
    backtrack(i+1, s+set[i]);

    subset[i] = 0;
    backtrack(i+1, s);
}

int main()
{
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter set elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
    }

    printf("Enter required sum: ");
    scanf("%d", &sum);

    count = 0;
    backtrack(0, 0);

    if (count == 0)
    {
        printf("No subset found.\n");
    }

    return 0;
}