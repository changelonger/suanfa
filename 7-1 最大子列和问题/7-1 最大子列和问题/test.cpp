#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int arr[100001]; int sum = 0;; int max = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);

    }
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (max < sum)
            max = sum;
        else if (sum < 0)
            sum = 0;
    }
    printf("%d", max);
    return 0;
}