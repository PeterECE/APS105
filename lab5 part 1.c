#include <stdio.h>
// lab 5 part 2: longest sequence
void longestSequence(int a[], int sizeA);
int main()
{
    int a[] = {1, 3, 10, 1, 7, 8, 10, 30, 0};

    longestSequence(a, 9);
}
//  print longest sequence.
void longestSequence(int a[], int sizeA)
{
    int i, num[sizeA], count = 1; // 计算每一个数的最长sequence
    num[0] = 1;
    for (i = 1; i < sizeA; i++)
    {
        if (a[i] >= a[i - 1])
        {
            count = count + 1;
        }
        else
        {
            count = 1;
        }
        num[i] = count;
    }
    int maxn = num[0], p;
    for (i = 1; i < sizeA; i++)
    {
        if (maxn < num[i])
        {
            p = i;
            maxn = num[i];
        }
    }

    for (i = p - maxn + 1; i <= p; i++)
    // p - maxn + 1 ~ p
    
    {
        printf("Longesr common Sequence is %d ", a[i]);
    }
    printf("\n");
}
