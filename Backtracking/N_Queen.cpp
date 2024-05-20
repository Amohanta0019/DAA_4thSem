#include<iostream>
#include<cmath>
using namespace std;
int *x;

bool place(int k, int i){
	for (int j = 0; j < k; j++)
	{
		if (x[j] == i || abs(x[j]-i) == abs(j-k))
		{
			return false;
		}
	}
	return true;
}
void NQueen(int k, int n){
	for (int i = 0; i < n; i++)
	{
		if (place(k,i))
		{
			x[k]= i;
			if (k == n-1)
			{
				for (int j = 0; j < n; j++)
				{
					cout << x[j] +1 << "  ";
				}
				cout<<endl;
			}
			else
			{
				NQueen(k+1,n);
			}
		}
	}
}
int main(void)
{
	int n;
	cout<< "Enter number of queens --->"<<endl;
	cin>>n;
	x = new int[n];
	NQueen(0,n);
	delete[] x;
return 0;
}
