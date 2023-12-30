#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSort(vector<float>& arr) {
    int N = arr.size();


    vector<vector<float>> buckets(N);


    for (int i = 0; i < N; i++) {
        int bucketIndex = N * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }


    for (int i = 0; i < N; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }


    int index = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    vector<float> arr = {0.42,0.11,0.24, 0.32,0.15,0.03, 0.33,0.16,0.52,0.44,0.88,0.96,0.77,0.66,0.58,0.97, 0.37, 0.47, 0.51};

    cout << "Original array: ";
    for (float value : arr) {
        cout << value << " ";
    }

    bucketSort(arr);

    cout << "\nSorted array: ";
    for (float value : arr) {
        cout << value << " ";
    }

    return 0;
}