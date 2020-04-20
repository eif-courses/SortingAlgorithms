#include <iostream>

using namespace std;


void swap(int *x, int *y) {
  int temp = *x;
  *x = *y; // x -> y
  *y = temp; // y -> x;
}

void bubbleSort(int array[], int n) {

  for (int i = 0; i < n - 1; i++) {
    int swapped = 0;
    for (int j = 0; j < n - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        swap(&array[j], &array[j + 1]);
        swapped = 1;
      }
    }
    if (swapped == 0) {
      break;
    }
  }


}

void displayBubbleSort() {
  int array[] = {66, 45, 20, 10, 9, 8};
  cout << "Bubble sort: Unsorted array: ";
  for (int &i: array) {
    cout << i << " ";
  }
  int size = sizeof(array) / sizeof(array[0]);
  bubbleSort(array, size);

  cout << "Sorted array: ";
  for (int &i: array) {
    cout << i << " ";
  }

}


// l - start index of collection array, m- middle [0..5..n], r -> end
void merge(int array[], int l, int m, int r) {
  int i, j, k;

  int n1 = m - l + 1;
  int n2 = r - m;

  int LSubArray[n1];
  int RSubArray[n2];

  // copy data to subarrays

  for (i = 0; i < n1; i++) {
    LSubArray[i] = array[l + i];
  }
  for (j = 0; j < n2; j++) {
    RSubArray[j] = array[m + 1 + j];
  }

  i = 0;
  j = 0;
  k = l;

  // array[k] -> merged array

  while (i < n1 && j < n2) {
    if (LSubArray[i] <= RSubArray[j]) { // Ascending -> ( <= ) or descending -> ( >= )
      array[k] = LSubArray[i];
      i++;
    } else {
      array[k] = RSubArray[j];
      j++;
    }
    k++;
  }


  // copy remaining elements to merged array

  while (i < n1) {
    array[k] = LSubArray[i];
    i++; // left array
    k++; // merged array
  }
  while (j < n2) {
    array[k] = RSubArray[j];
    j++; // right array
    k++; // merged array
  }
}

void mergeSort(int array[], int l, int r) {
  if (l < r) {
    // (l+r)/2
    int m = l + (r - l) / 2;
    // [0..m..n]
    mergeSort(array, l, m); // [0..m] // left
    mergeSort(array, m + 1, r); //[m+1..n] // right

    merge(array, l, m, r);

  }
}

void displayMergeSort() {

  /// TODO appending output
  int array[] = {582, 115, 120, 4, 40, 62, 25, 69};

  cout << "Merge sort: Unsorted array: ";
  for (int i: array) {
    cout << i << " ";
  }
  int size = sizeof(array) / sizeof(array[0]);

  mergeSort(array, 0, size - 1);

  cout << "Sorted array: ";
  for (int i: array) {
    cout << i << " ";
  }

}

int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}

void countingSort(int array[], int size, int place) {
  const int max = 10;
  int output[size];
  int count[max];
  for (int &i: count)
    i = 0;

  // Calculate count of elements
  for (int i = 0; i < size; i++)
    count[array[i] / place % 10]++;

  // Calculate cumulative count
  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

  // place elements in sorted order

  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }
  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

void radixSort(int array[], int size) {
  int max = getMax(array, size);
  for (int place = 1; max / place > 0; place *= 10) {
    countingSort(array, size, place);
  }
}

void displayRadixSort() {
  /// TODO appending output
  int array[] = {25, 1, 6, 11, 2, 58, 99, 35};

  cout << "Radix sort: Unsorted array: ";
  for (int i: array) {
    cout << i << " ";
  }
  int size = sizeof(array) / sizeof(array[0]);

  radixSort(array, size);

  cout << "Sorted array: ";
  for (int i: array) {
    cout << i << " ";
  }
}


int main() {

  displayMergeSort();
  cout << endl;
  displayBubbleSort();
  cout << endl;
  displayRadixSort();
  return 0;
}

