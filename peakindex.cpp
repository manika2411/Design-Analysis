#include<iostream>
using namespace std;
int peak(int l,int h,int a[])
{
	if (l==h)
	{
		return l;
	}
	int m=(l+h)/2;
	if (a[m]>a[m+1])
	{
		return peak(l,m,a);
	}
	else
	{
		return peak(m+1,h,a);
	}
}
int main()
{
	int n;
	cout<<"enter number of elements:";
	cin>>n;
	int a[n];
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int p=peak(0,n-1,a);
	cout<<a[p]<<" found at index "<<p;
}
