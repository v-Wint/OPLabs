#include <iostream>
#define RANGE 100

using namespace std;

double** initialize(size_t, size_t);  //initalizes the array

double** copyArray(double**, size_t, size_t); //returns a copy of the given array

void display(double**, size_t, size_t); // displays the given array

size_t findTheMostElementRow(double**, size_t, size_t, bool); //returns the row in which greatest or the smallest element is

void swapRows(double**, double**, size_t, size_t); //swaps two rows in the two given arrays

void deleteArray(double**, size_t); //deletes an array

int main()
{
    srand(time(NULL));

    // input 
    int n, m;
    cout << "n = "; cin >> n;
    cout << "m = "; cin >> m;
    if (n < 0 || m < 0) {
        printf("The values must be greater than 0");
        return 0;
    }

    // initialization
    double **C = initialize(n, m), **B = initialize(n, m);
    
    //processing the new arrays
    double **Y = copyArray(C, n, m), **Z = copyArray(B, n, m);
    
    cout << "\nBEFORE THE SWAP:\n";
    cout << "Array C: \n"; display(C, n, m);
    cout << "Array B: \n"; display(B, n, m);
    cout << "Array Y: \n"; display(Y, n, m);
    cout << "Array Z: \n"; display(Z, n, m);

    size_t theMaxElementRowY = findTheMostElementRow(Y, n, m, true),
           theMaxElementRowZ = findTheMostElementRow(Z, n, m, true),
           theMinElementRowY = findTheMostElementRow(Y, n, m, false),
           theMinElementRowZ = findTheMostElementRow(Z, n, m, false);

    printf("\nThe greatest element row:\nY: %d\nZ: %d\n\nThe smallest element row:\nY: %d\nZ: %d\n\n", 
            theMaxElementRowY, theMaxElementRowZ, theMinElementRowY, theMinElementRowZ);

    swapRows(Y, Z, theMaxElementRowY, theMaxElementRowZ);
    swapRows(Y, Z, theMinElementRowY, theMinElementRowZ);

    cout << "\nAFTER THE SWAP:\n";
    cout << "Array C: \n"; display(C, n, m);
    cout << "Array B: \n"; display(B, n, m);
    cout << "Array Y: \n"; display(Y, n, m);
    cout << "Array Z: \n"; display(Z, n, m);
    
    deleteArray(C, n); deleteArray(B, n); deleteArray(Y, n); deleteArray(Z, n);

    return 0;
}

double** initialize(size_t n, size_t m) {
    double** arr = new double * [n];
    for (size_t i = 0; i < n; i++) {
        arr[i] = new double[m];
        for (size_t j = 0; j < m; j++) {
            arr[i][j] = (double)rand() / RAND_MAX * 2 * RANGE - RANGE;
        }
    }
    return arr;
}

void display(double** arr, size_t n, size_t m) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            printf("%8.2f ", arr[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

/*
* returns the number of a row in which the greatest element is if theGreatest == true, 
* else the number of a row in which the smallest element is
*/
size_t findTheMostElementRow(double** arr, size_t n, size_t m, bool theGreatest) {
    double mostElementValue = arr[0][0];
    size_t mostElementRow = 0;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            if ((arr[i][j] > mostElementValue) == theGreatest) {   // logical equivalence ~
                mostElementValue = arr[i][j];
                mostElementRow = i;
            } 
        }
    }
    return mostElementRow;
}


void swapRows(double** arr1, double** arr2, size_t row1, size_t row2) {
    double *temp = arr1[row1]; //just swap the pointers
    arr1[row1] = arr2[row2];
    arr2[row2] = temp;
}

double** copyArray(double** arr, size_t n, size_t m) {
    double** newArr = new double* [n];
    for (size_t i = 0; i < n; i++) {
        newArr[i] = new double[m];
        for (size_t j = 0; j < m; j++) {
            newArr[i][j] = arr[i][j];
        }
    }
    return newArr;
}

void deleteArray(double** arr, size_t n) {
    for (size_t i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
}
