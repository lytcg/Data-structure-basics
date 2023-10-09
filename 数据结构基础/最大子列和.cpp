#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int thissum=0,maxsum=0;
	
	for(int i=0;i<n;i++)
	{
		thissum+=arr[i];
		if(thissum>maxsum)
		{
			maxsum=thissum;
		}
		if(thissum<0)
		{
			thissum=0;
		}
	}
	
	cout<<maxsum;
	return 0;
}
