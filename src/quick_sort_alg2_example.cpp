//
// Quick Sort Example
// quick_sort_alg2_example.cpp
// Description: An efficient method of quicksort
//
// created: 4/4/15 by j-concept
//

#include <iostream>
#include <cstdlib>

using namespace std;

// function prototypes
void quickSort(int arr[], int left, int right);
void print(int array[], const int& N);

int main()
{
	int A[] = {1, 12, 5, 26, 7, 14, 3, 8, 2};
	int N;

	// compute the number of elements in the array
	N = sizeof(A)/sizeof(A[0]);

	cout << "The original array can be viewed below:" << '\n';
	print(A, N);
	cout << '\n';

	quickSort(A, 0, N-1);

	cout << "The sorted array can be viewed below:" << '\n';
	print(A, N);

	return 0;
}

// function definition
// O(nlog(n))
void quickSort(int arr[], int left, int right) 
{
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (arr[i] < pivot) {
		      i++;
		      // cout << "i = " << i << " pivot = " << pivot << '\n';
		}
		while (arr[j] > pivot) {
		      j--;
		      // cout << "j = " << j << " pivot = " << pivot << '\n';
		}
		if (i <= j) {
			// basic swap
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};
 
		/* recursion */
		if (left < j)
		    quickSort(arr, left, j);
		if (i < right)
		    quickSort(arr, i, right);
}

void print(int a[], const int& N)
{
	for(int k = 0 ; k < N ; k++)
	    cout << "array[" << k << "] = " << a[k] << endl;
} 
