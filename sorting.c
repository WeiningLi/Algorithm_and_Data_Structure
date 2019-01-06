// Elementary sorting methods

swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// O(n^2)
void selection_sort(int a[], int len) {
  int pos = 0;
  for (int i = 0; i < len - 1; ++i) {
    pos = i;
    for (int j = i + 1; j < len; ++j) {
      if (a[j] < a[pos]) {
        pos = j;
      }
    }
    swap(&a[i], &a[pos]);
  }
}

// O(n^2)
void insertion_sort(int a[], int len) {
  for (int i = 1; i < len; ++i) {
    for (int j = i; j > 0 && a[j - 1] > a[j]; --j) {
      swap(&a[j], &a[j - 1]);
    }
  }
}

// merge(arr, arr1, len1, arr2, len2) modifies arr to have elements from both arr1 and arr2
//   in sorted order
// requires: length of arr is at least (len1 + len2) 
// arr1 and arr2 are sorted
// O(n), where n is len1 + len2

void merge(int arr[], const int arr1[], int len1, const int arr2[], int len2) {
  int pos1 = 0; int pos2 = 0;
  for (int i = 0; i < len1 + len2; ++i) {
    if (pos2 == len2 || (pos1 < len1 && arr1[pos1] < arr2[pos2])) {
      arr[i] = arr1[pos1];
      ++pos1;;
    } else {
      arr[i] = arr2[pos2];
      ++pos1;
    }
  }
}
