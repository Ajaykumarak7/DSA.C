#include<stdio.h>
#include<limits.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int findMedian(int a[], int i, int j, int k) {
    if ((a[i] >= a[j] && a[i] <= a[k]) || (a[i] <= a[j] && a[i] >= a[k]))
        return i;
    else if ((a[j] >= a[i] && a[j] <= a[k]) || (a[j] <= a[i] && a[j] >= a[k]))
        return j;
    else
        return k;
}
void medianSort(int a[], int first, int last) {
    if (first < last) {
        int pivotIndex = partition(a, first, last);
        medianSort(a, first, pivotIndex - 1);
        medianSort(a, pivotIndex + 1, last);
    }
}
int partition(int a[], int first, int last) {
    int pivotIndex = findPivot(a, first, last);
    int pivotValue = a[pivotIndex];
    swap(&a[pivotIndex], &a[last]);
    int i = first - 1;
    for (int j = first; j < last; j++) {
        if (a[j] <= pivotValue) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[last]);
    return i + 1;
}
int findPivot(int a[], int first, int last) {
    int mid = (first + last) / 2;
    int medianIndex = findMedian(a, first, mid, last);
    return medianIndex;
}
int main() {
    int a[40], n, i;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    medianSort(a, 0, n - 1);
    printf("Sorted elements are: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
