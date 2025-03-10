#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"enter number of denomination:";
	cin>>n;
	cout<<"enter the denominations:\ngive in descending order:";
	int i;
	int a[n];
	for (i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int m;
	cout<<"enter the money to return:";
	cin>>m;
	int c=0;
	i=0;
	int count[n]={0};
	while(m>0)
	{
		int temp=c;
		c=c+m/a[i];
		m=m%a[i];
		count[i]=c-temp;
		i++;
	}
	cout<<"number of coins required:"<<c<<endl;
	cout<<"count of each denomination:\n";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<":"<<count[i]<<"\n";
	}
}
