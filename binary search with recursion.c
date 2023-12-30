int binary_search(int arr[], int low, int high, int key) {
  if (low > high) {
    return -1;
  }
  int mid = (low + high) / 2;
  if (key == arr[mid]) {
    return mid;
  }
  else if (key < arr[mid]) {
    return binary_search(arr, low, mid-1, key);
  }
  else {
    return binary_search(arr, mid+1, high, key);
  }
}
// A main function to test the binary search function
#include <stdio.h>
int main() {
  int arr[] = {2, 4, 6, 8, 10, 12, 14}; 
  int n = sizeof(arr) / sizeof(arr[0]); 
  int key; 
  printf("Enter the element to be searched: ");
  scanf("%d", &key);
  int index = binary_search(arr, 0, n-1, key); 
  if (index == -1) {
    printf("The element %d is not found in the array\n", key);
  }
  else {
    printf("The element %d is found at index %d in the array\n", key, index);
  }
  return 0;
}
