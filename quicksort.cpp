
#include <iostream>
#include <cstdlib>  // For rand()
using namespace std;

// Step 1: Place pivot at correct position
int partition(int a[], int low, int high) {

    int pivot = a[high]; // Last element is pivot
    int i = low - 1;     // Smaller element position

    for (int j = low; j < high; j++) {

        if (a[j] < pivot) {  // If element is smaller
            i++;            // Move position
            swap(a[i], a[j]); // Swap elements
        }
    }

    swap(a[i + 1], a[high]); // Place pivot correctly

    return i + 1; // Return pivot index
}

// Step 2: Quick Sort
void quickSort(int a[], int low, int high, bool random) {

    if (low < high) { // Stop when part has 1 element

        if (random) { // For randomized Quick Sort
            int r = low + rand() % (high - low + 1);
            swap(a[r], a[high]); // Move random pivot to end
        }

        int p = partition(a, low, high); // Divide array

        quickSort(a, low, p - 1, random);  // Sort left
        quickSort(a, p + 1, high, random); // Sort right
    }
}

int main() {

    int a[] = {10, 7, 8, 9, 1, 5};
    int b[] = {10, 7, 8, 9, 1, 5};
    int n = 6;

    // Deterministic Quick Sort
    quickSort(a, 0, n - 1, false);

    cout << "Deterministic: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    // Randomized Quick Sort
    quickSort(b, 0, n - 1, true);

    cout << "\nRandomized: ";
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";

    return 0;
}
