#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i; // 設根為最大值
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    //比較根與左右子樹的值，找出最大值
    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    //如果最大值不是根，交換最大值與根
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // 遞迴，重新檢查受影響的子樹
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    //i 是最後一個父節點，n是元素個數
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    //將最大值與最後一個元素交換，再重新做一次
    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[6];
    cout << "Enter 6 integers: ";
    for (int i = 0; i < 6; i++) {
        cin >> arr[i];
    }
    //計算陣列大小
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted array is \n";
    printArray(arr, n);
    return 0;
}