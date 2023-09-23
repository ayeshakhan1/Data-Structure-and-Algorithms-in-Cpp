// ============================[ I N S E R T I O N    S O R T ]============================ //
#include<iostream>

using namespace std;

void InsertionSort(int * Array, int N) {

  int pos, val;

  for (int count = 1; count < N; count++) {
    val = Array[count];

    for (pos = count - 1; pos >= 0; pos--)
      if (Array[pos] > val)
        Array[pos + 1] = Array[pos];
      else break;
    Array[pos + 1] = val;
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

  InsertionSort(array, size);

  for (int i = 0; i < size; i++) {
    cout << array[i] << "\t";
  }

  return 0;
}
