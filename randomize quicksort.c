#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define INT_MAX 2147483647

int random(int low, int high) {
    srand(time(0));
    return (rand() % (high - low + 1)) + low;
}

int partition(int a[], int low, int high) {
    int t;
    int i = low;
    int j = high + 1;
    int r = random(low, high);
    t = a[r];
    a[r] = a[low];
    a[low] = t;
    int pivot = a[low];
    do {
        do {
            i++;
        } while (a[i] < pivot);
        do {
            j--;
        } while (a[j] > pivot);
        if (i < j) {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    } while (i < j);
    t = a[j];
    a[j] = a[low];
    a[low] = t;
    return j;
}

void quicksort(int a[], int low, int high) {
    if (low < high) {
        int j = partition(a, low, high);
        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    a[n - 1] = INT_MAX;
    for (i = 0; i < n - 1; i++) {
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n - 2);

    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    free(a);
    return 0;
}
