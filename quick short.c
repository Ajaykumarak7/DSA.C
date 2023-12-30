#include<stdio.h>
#include<limits.h>
void quicksort(int a[], int first, int last) {
    int i, j, pivot, temp;
    
    if (first < last) {
        pivot = first;
        i = first;
        j = last;
        
        while (i < j) {
            while (a[j] >= a[pivot] && i < j)
                j--;
            
            while (a[i] < a[pivot])
                i++;
            
            if (i < j) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;
        
        quicksort(a, first, j - 1);
        quicksort(a, j + 1, last);
    }
}
int main() {
    int a[40], n, i;
    
    printf("Enter size of array: ");
    scanf("%d", &n);
    
    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    a[n] = INT_MAX; 
    quicksort(a, 0, n - 1);
    printf("Sorted elements are: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
