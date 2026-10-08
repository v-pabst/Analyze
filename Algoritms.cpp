#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

const int SIZE = 10;
using Array = array<int, SIZE>;

Array bubbleSort(Array arr) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = t;
            }
        }
    }
    return arr;
}

Array bubbleSort2(Array arr) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
    return arr;
}

Array selectionSort(Array arr) {
    for (int i = 0; i < SIZE - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        int t = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = t;
    }

    return arr;
}

Array insertionSort(Array arr) {
    for (int i = 1; i < SIZE; i++) {
        int t = arr[i];
        int j = i - 1;
        while (j >= 0 && t < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = t;
    }

    return arr;
}

void mergeSortRange(Array& arr, Array& buf, int left, int right) {
    if (right - left <= 1) return;
    int center = (right - left) / 2 + left;
    mergeSortRange(arr, buf, left, center);
    mergeSortRange(arr, buf, center, right);
    int i = left;
    int j = center;
    for (int k = left; k < right; k++) {
        if (j == right || (i < center && arr[i] <= arr[j])) {
            buf[k] = arr[i++];
        }
        else {
            buf[k] = arr[j++];}
    }
    for (int k = left; k < right; k++) {
        arr[k] = buf[k];
    }
}

Array mergeSort(Array arr) {
    Array buf{};
    mergeSortRange(arr, buf, 0, SIZE);
    return arr;
}

int hoarePart(Array& arr, int left, int right) {
    int pivot = arr[(right - left) / 2 + left];
    int i = left - 1;
    int j = right + 1;
    while (true) {
        do { i++; } while (arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);
        if (i >= j) return j;
        swap(arr[i], arr[j]);
    }
}

void hoareSortRange(Array& arr, int left, int right) {
    if (left >= right) return;
    int center = hoarePart(arr, left, right);
    hoareSortRange(arr, left, center);
    hoareSortRange(arr, center + 1, right);
}

Array hoareSort(Array arr) {
    hoareSortRange(arr, 0, SIZE - 1);
    return arr;
}

void print(Array arr) {
    cout << "[";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i];
        if (i < SIZE - 1) {cout << ",";}
    }
    cout << "]" << endl;
}

void printArray(Array arr) {
    cout << "[ ";
    for (int i = 0; i < SIZE; i++) cout << arr[i] << "";
    cout << "]" << endl;
}

int main()
{
    Array a = {23,4,12,8,137,2288,14,98,66,689};
    Array Bubble = bubbleSort(a);
    Array Selection = selectionSort(a);
    Array insertion = insertionSort(a);
    Array Bubble2 = bubbleSort2(a);
    print(a);
    print(Bubble);
    print(Bubble2);
    print(Selection);
    print(insertion);

    return 0;
}