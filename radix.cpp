#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

void radixsort(int A[], int n, int d) {
    int k = -1, ind, po = 1, e, p = 0;

    for (int i = 0; i < d; i++) {
        for (int j = 0; j < n; j++) {
            po = static_cast<int>(pow(10, p));
            e = A[j] / po;
            ind = e % 10;
            if (ind > k)
                k = ind;
        }

        int *C = (int *)calloc(sizeof(int), k + 1);
        int *ans = new int[n];

        for (int i = 0; i < n; i++) {
            po = static_cast<int>(pow(10, p));
            e = A[i] / po;
            ind = e % 10;
            C[ind] = C[ind] + 1;
        }

        for (int i = 1; i <= k; i++) {
            C[i] = C[i] + C[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            po = static_cast<int>(pow(10, p));
            e = A[i] / po;
            ind = e % 10;
            ans[C[ind] - 1] = A[i];
            C[ind] = C[ind] - 1;
        }

        for (int i = 0; i < n; i++) {
            A[i] = ans[i];
        }

        p++;

        delete[] C;
        delete[] ans;
    }

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
}

int main() {
    int a[] = {769, 134, 140, 241, 337, 608, 100, 565, 410, 131, 768, 230, 500, 431};
    radixsort(a, 14, 3);
    return 0;
}
