// ============================[ S E L E C T I O N    S O R T ]============================ //
#include<iostream>
using namespace std;

int findIndexMin(int *arr, int start, int N){
    int posmin = start;
    int index;

    for(index=start; index < N; index++)
        if (arr[index] < arr[posmin]) posmin  =  index;
        return posmin;  }

void SelectionSort(int *arr, int N){
int posmin, count, tmp;

    for(count=0;count<N;count++){
        posmin = findIndexMin(arr,count,N);
        tmp = arr[posmin];
        arr[posmin] =  arr[count];
        arr[count]  =  tmp;     }   }

int main(){
    int size = 5;
    int array[size] = {40, 10, 30, 20, 50};

    SelectionSort(array, size);

    for(int i = 0; i<size; i++){ cout<<array[i]<<"\t"; }

    return 0;   }
