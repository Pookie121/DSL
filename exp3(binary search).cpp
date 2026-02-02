#include <iostream>
using namespace std;

int main() {
    int a[] = {10, 20, 30, 40, 50};
    int key = 40, low = 0, high = 4;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == key) {
            cout << "Found at index " << mid;
            return 0;
        }
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << "Not found";
    return 0;
}
