#include<iostream>
using namespace std;
int n;
#define size 10
template<class T>

void selection(T arr[size]) {
    T temp;
    int min;
    for(int i=0; i<n-1; i++) {
        min = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[min]) min = j;
        }

        swap(arr[i], arr[min]);
    }

    cout << "\nSorted Array: ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
}


int main()
{
    int A[size];
    float B[size];

    int i, ch;
    do {
        cout << "\n**********Selection Sort System***********";
        cout << "\n-------------MENU------------------";
        cout << "\n1. Integer Values";
        cout << "\n2. Float Values";
        cout << "\n3. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
            cout << "\nEnter total no of int elements: ";
            cin >> n;
            cout << "\nEnter int elements: ";
            for(int i=0; i<n; i++) cin >> A[i];
            selection(A);
            break;

            case 2:
            cout << "\nEnter total no of float elements: ";
            cin >> n;
            cout << "\nEnter float elements: ";
            for(i=0; i<n; i++) cin >> B[i];
            selection(B);
            break;
            
            case 3:
            cout << "Thanks for using this program";
            exit(0);
        }
    } while(ch != 3);
    return 0;
}