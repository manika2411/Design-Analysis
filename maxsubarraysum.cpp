#include<iostream>
using namespace std;
int main()
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	int arr[n];
	cout << "Enter " << n << " elements of the array: ";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int currentSum = 0;
	int maxSum = arr[0];
	for (int i = 0; i < n; i++)
	{
		currentSum += arr[i];
		if (currentSum > maxSum)
		{
			maxSum = currentSum;
		}
		if (currentSum < 0)
		{
			currentSum = 0;
		}
	}
	cout << "Maximum sum of contiguous subarray is: " << maxSum << endl;
	return 0;
}
