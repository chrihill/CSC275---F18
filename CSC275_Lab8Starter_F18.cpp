//Credit to:  https://www.geeksforgeeks.org/merge-sort/
//(With some modifications by Dr. Spradling)

#include <iostream>
#include <string>

using namespace std;

// Purpose:   Merges two subarrays of arr[].
// Preconditions:
//          First subarray is arr[l..m]
//          Second subarray is arr[m+1..r]
// Postconditions:
//          arr[l...r] sorted in ascending order
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}




//Purpose:  recursively sort a subsection of an integer array in ascending order
//Preconditions:
//      Initial call to the algorithm should have int l = 0,  int r = arr_size - 1
//      l is for left index and r is right index of the
//      sub-array of arr to be sorted
//Post-conditions:
//      arr[l...r] sorted in ascending order.
void mergeSort_aux(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort_aux(arr, l, m);
        mergeSort_aux(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

//Purpose:  recursively sort an integer array in ascending order
//Preconditions:        arr is an integer array,  n is the size of the array.
//Postconditions:       arr is sorted in ascending order by reference
void mergeSort(int arr[], int n){
    mergeSort_aux(arr, 0, n-1);

}



/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

/* Driver program to test above functions */
int main()
{
    int int_arr[] = {12, 11, 13, 5, 6, 7};
    int int_arr_size = 6;

    cout << "Given int array is: " << endl;
    printArray(int_arr, int_arr_size);

    mergeSort(int_arr, int_arr_size);

    cout << endl << "Sorted int array is: " << endl;
    printArray(int_arr, int_arr_size);



    /* PART E:    UNCOMMENT THE REMAINING CODE WHEN YOU ARE READY TO TEST:

    string str_arr[] = {"xy", "ay", "ab", "xz", "ac", "bd", "bc"}
    int str_arr_size = 7;


    cout << "Given str array is: " << endl;

    printArray(str_arr, str_arr_size);

    mergeSort(str_arr, str_arr_size);

    cout << endl << "Sorted str array is: " << endl;
    printArray(str_arr, str_arr_size);

    */ //END UNCOMMENT SECTION FOR PART E

    return 0;
}
