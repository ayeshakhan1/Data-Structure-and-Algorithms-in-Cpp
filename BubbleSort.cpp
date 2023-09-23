// ============================[ B U B B L E    S O R T ]============================ //
#include<iostream>

using namespace std;

void BubbleSort(int * Array, int N) {
  int temp;
  int swapped = 1;

  while (swapped > 0) {
    swapped = 0;

    for (int i = 0; i < N - 1; i++)
      if (Array[i] > Array[i + 1]) {
        temp = Array[i];
        Array[i] = Array[i + 1];
        Array[i + 1] = temp;
        swapped = i;
      }
  }
}

int main() {
  int size = 5;
  int array[size] = {
    40,
    10,
    30,
    20,
    50
  };

  BubbleSort(array, size);

  for (int i = 0; i < size; i++) {
    cout << array[i] << "\t";
  }

  return 0;
}
