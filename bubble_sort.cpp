#include <iostream>

int* bubbleSort(int arr[], int size);

int main() {
    std::cout << "Welcome to the Bubble Sort program!" << std::endl;

    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(array) / sizeof(array[0]);

    if(size <= 1) {
        std::cout << "Array is already sorted." << std::endl;
    } else {
        int* sortedArray = bubbleSort(array, size);
        std::cout << "Sorted array: " << sortedArray[0] << " " << sortedArray[1] << " " << sortedArray[2] << " " << sortedArray[3] << " " << sortedArray[4] << " " << sortedArray[5] << " " << sortedArray[6] << std::endl;
    }

    return 0;
}

int* bubbleSort(int arr[], int size) {
    int temp = arr[0];

    for(int i=0; i<size - 1; i++) {
        for(int j=0; j< size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
              temp = arr[j]; 
              arr[j] = arr[j + 1];
              arr[j + 1] = temp;
            }
        }
    }

    return arr;
}


