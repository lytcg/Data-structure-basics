#include<bits/stdc++.h>
using namespace std;

int main()
{
	int k,flag=0;
	cin>>k;
	int arr[k];
	
	for(int i=0;i<k;i++)
	{
		cin>>arr[i];
		if(flag==0)
		{
			if(arr[i]>=0)
			{
				flag=1;
			}
		}
	}
	
	if(flag==0)
	{
		cout<<"0"<<" "<<arr[0]<<" "<<arr[k-1];
		return 0;
	}
	
	int thissum=0,maxsum=0;
	int m,n,tmp=arr[0];
	
	for(int i=0;i<k;i++)
	{
		thissum+=arr[i];
		if(thissum>maxsum)
		{
			m=tmp;
			n=arr[i];
			maxsum=thissum;
		}
		if(thissum<0)
		{
			if(i<k-1)
			{
				tmp=arr[i+1];
			}
			thissum=0;
		}
	}
	
	cout<<maxsum<<" "<<m<<" "<<n;
	
	return 0;
}
