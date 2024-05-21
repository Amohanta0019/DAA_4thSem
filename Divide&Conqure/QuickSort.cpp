#include<iostream>
using namespace std;
int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low; 
    int j = high;
    while (i<j)
    {
        while (arr[i] <= pivot && i<= high-1)
        {
            i++;
        }
        while (arr[j]> pivot && j>= low+1)
        {
            j--;
        }
        if (i<j)
        {
            swap(arr[i], arr[j]);
        } 
    }
    swap(arr[low], arr[j]);
    return j;
    
}
void quickSort(int arr[], int low, int high){
    if (low<high)
    {
        int pIdx = partition(arr, low, high);
        quickSort(arr, low, pIdx-1);
        quickSort(arr, pIdx+1, high);
    }
    
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}
int main(void)
{
     int arr[100];
    int n;
    
    cout << "Enter size of array: ";
    cin >> n;
    
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) {
        cout << "Enter " << i << "-th element-->";
        cin >> arr[i];
    }

    cout << "Array before sorting: ";
    print(arr,n);
    cout << endl;

    quickSort(arr, 0, n-1);

    cout << "Array after sorting: ";
    print(arr,n);
    cout << endl;
return 0;
}