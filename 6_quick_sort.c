#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do{
        while (arr[i] <= pivot){
            i++;
        }
        while (arr[j] > pivot){
            j--;
        }
        if (i < j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    // swap arr[low] and arr[j]
    temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;
}

void quicksort(int arr[], int low, int high)
{
    int partitionindex; // index of pivot after partition

    if (low < high)
    {
        partitionindex = partition(arr, low, high);
        quicksort(arr, low, partitionindex - 1);  // sort left subarray
        quicksort(arr, partitionindex + 1, high); // sort right subarray
    }
}

int main()
{

    int arr[] = {56, 78, 586,85, 11,8685, 24, 36,8, 48, 12};
    int n = sizeof(arr) / sizeof(int);

    printArray(arr, n);
    quicksort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}