#include<iostream>
using namespace std;
void merge(int arr[],int low,int mid,int high){
    int temp[100];
    int left = low;
    int right = mid+1;
    int k = 0; 
    while (left<=mid && right<= high)
    {
        if(arr[left]<arr[right]){
            temp[k++]  = arr[left];
            left++;
        }
        else
        {
            temp[k++]  = arr[right];
            right++;
        }
        
    }
    while (left<=mid)
    {
        temp[k++]  = arr[left];
        left++;
    }
      while (right<=high)
    {
       temp[k++]  = arr[right];
        right++;
    }
    for (int i = 0; i < k; i++)
    {
        arr[low+i] = temp[i];
    }
    
    
}
void mergeSort(int arr[], int low, int high){
    if (low==high)
    {
        return;
    }
    int mid = (low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
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

    mergeSort(arr, 0, n - 1);

    cout << "Array after sorting: ";
    print(arr,n);
    cout << endl;
 
return 0;
}