#include <iostream>
using namespace std;
int binarySearch(int arr[], int key, int low, int high)
{
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int binSearch(int arr[], int key, int low, int high){
    if(low == high){
        if (arr[low] == key){
            return arr[low];
        }
        else
            return 0;
    }
    else{
        int mid = low + (high - low)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid]<key){
            return binSearch(arr , key, mid+1,high);
        }
        else{
            return binSearch(arr , key, low, mid-1);
        }
    }
    return -1;
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
    cout << "Enter size  : " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i << "-th element-->";
        cin >> arr[i];
    }
    print(arr, n);
    int x = 10;
    //int res = binarySearch(arr, x, 0, n - 1);
    int res = binSearch(arr, x, 0, n - 1);
    (res == -1) ? cout << "Element is not present in array" : cout << "Element is present at index " << res;
    cout << endl;
    print(arr, n);

    return 0;
}