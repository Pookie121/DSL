#include <iostream>
using namespace std;

int main() {
    int arr[100], n, choice, pos, value, key;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    do {
        cout << "\n\n--- MENU ---";
        cout << "\n1. Traversal";
        cout << "\n2. Insertion";
        cout << "\n3. Deletion";
        cout << "\n4. Searching";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1:   // Traversal
                cout << "Array elements:\n";
                for(int i = 0; i < n; i++)
                    cout << arr[i] << " ";
                break;

            case 2:   // Insertion
                cout << "Enter position and value: ";
                cin >> pos >> value;

                for(int i = n; i > pos; i--)
                    arr[i] = arr[i - 1];

                arr[pos] = value;
                n++;
                cout << "Element inserted.";
                break;

            case 3:   // Deletion
                cout << "Enter position to delete: ";
                cin >> pos;

                for(int i = pos; i < n - 1; i++)
                    arr[i] = arr[i + 1];

                n--;
                cout << "Element deleted.";
                break;

            case 4:   // Searching
                cout << "Enter element to search: ";
                cin >> key;

                for(int i = 0; i < n; i++) {
                    if(arr[i] == key) {
                        cout << "Element found at index " << i;
                        goto end;
                    }
                }
                cout << "Element not found";
                end:;
                break;

            case 5:
                cout << "Exiting program.";
                break;

            default:
                cout << "Invalid choice";
        }

    } while(choice != 5);

    return 0;
}
