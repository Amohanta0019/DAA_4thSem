#include<iostream>
using namespace std;
void maxmin(int arr[], int i, int j,int &max, int &min){
    int max1,min1;
    if (i==j)
    {
        max = min = arr[i];
    }
    else if (i+1==j)
    {
        if (arr[i]>arr[j])
        {
            max = arr[i];
            min = arr[j];
        }
        else
        {
            max = arr[j];
            min = arr[i];
        }
    }
    else
    {
        int mid = (i+j)/2;
        maxmin(arr,i,mid,max,min);
        maxmin(arr,mid+1,j,max1,min1);
        if (max1>max)
        {
            max = max1;
        }
        if (min1<min)
        {
            min = min1;
        }
        
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
    cout << "Enter size  : " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i << "-th element-->";
        cin >> arr[i];
    }
    print(arr, n);
    int max , min;
    maxmin(arr,0,n-1,max,min);
    cout<<"max = "<<max<<"\t";
    cout<<"min = "<<min<<"\t";
return 0;
}