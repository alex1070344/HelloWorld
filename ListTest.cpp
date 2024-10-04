#include <iostream>

int main() {
    int arr[20];

    // Initialize the array with some values
    for (int i = 0; i < 20; i++) {
        arr[i] = i;
    }

    // Print the array elements
    for (int i = 0; i < 20; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}