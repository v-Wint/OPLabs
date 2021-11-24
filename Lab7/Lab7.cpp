#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdarg.h>

#define RANGE 100

using namespace std;

double* initialize(size_t);    //initialize dynamic array with the random float numbers in the range of [-RANGE; +RANGE]

void display(double*, size_t);  //display elements of a given array

void proccessElementsSmallerThan(double* arr, size_t size, int z, int& numberOfElements, int& maxElementIndex, double& maxElement);  //finds the number of elements smaller than z, the greatest of those elements and its index

void replaceElementWithFirst(double*, size_t, double); // replace the given element with the first in the array

int main() {
    // values input
    size_t n; int z;
    cout << "n = "; cin >> n;
    cout << "z = "; cin >> z;
    if (n < 1 ) {
        printf("n cannot be smaller than 1\n"); 
        return 0;
    }

    //array initialization
    double* B = initialize(n);

    printf("Initial array: \n"); display(B, n);

    //process the elements smaller than z
    int numberOfElements, maxElementIndex; double maxElement;

    proccessElementsSmallerThan(B, n, z, numberOfElements, maxElementIndex, maxElement);

    // if there are such elements, output, replace the greatest of those with the first
    if (numberOfElements == 0) {
        printf("There are no elements smaller than %d in the array\n", z);
    }
    else {
        printf("There are %d elements smaller than %d. The greatest of those is the element %f with the index %d\n\n", \
            numberOfElements, z, maxElement, maxElementIndex);

        replaceElementWithFirst(B, maxElementIndex, maxElement);

        printf("Array after replacement:\n"); display(B, n);
    }

    delete[] B;

    return 0;
}


double* initialize(size_t size) {
    double* arr = new double[size];
    srand(time(NULL));
    for (size_t i = 0; i < size; i++)
        arr[i] = (double)rand() / RAND_MAX * 2 * RANGE - RANGE;    //random double in [-RANGE; +RANGE]
    return arr;
}

void display(double* arr, size_t size) {
    for (size_t i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n\n";
}

void proccessElementsSmallerThan(double* arr, size_t size, int z, int& numberOfElements, int& maxElementIndex, double& maxElement) {
    double el;
    numberOfElements = 0, maxElementIndex = -1;
    for (size_t i = 0; i < size; i++) {
        el = arr[i];
        if (el < z) {
            
            numberOfElements++;

            if (maxElementIndex < 0 ) {  //if the first occurence and we can`t know the maxElement
                maxElementIndex = i;
                maxElement = el;
            }
            else if (el > maxElement) { 
                maxElementIndex = i;
                maxElement = el;
            }
        }
    }
    
}
void replaceElementWithFirst(double* array, size_t index, double value) {
    double firstElement = array[0];
    array[0] = value;
    array[index] = firstElement;
}