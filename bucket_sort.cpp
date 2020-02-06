#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<fstream>
using namespace std;
void bucket_sort(float a[],int n)
{
	float b[n][n];
	float h[n];
	int k;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		b[i][j]=0;
		h[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		k=a[i];
		b[k][h[k]]=a[i];
		h[k]++;
	}
	for(int i=0;i<n;i++)
	insertion_sort(b[i],h[i]);
}
void insertion_sort(int a[],int n)
{
	int i,j,temp;
	for(j=1;j<n;j++)
	{
		temp=a[j];
		i=j-1;
		for(;i>=0&&a[i]>temp;i--)
		{
			a[i+1]=a[i];
			comp++;
		}
		a[i+1]=temp;
	}		
}
int main()
{
	clock_t start,end;
	int n,*a,d=0;
	cout<<"enter no of values\n";
	cin>>n;
	int f=n;
	for(;f!=0;f=f/10,d++)
	a=new int[n];
	ofstream ofs;
	ofs.open("inp_prash(bsort).txt");
	for(int i=0;i<n;i++)
	{	
		ofs<<float(rand()/<<"\t";
	}
	ofs.close();
	ifstream ifs;
	ifs.open("inp_prash(bsort).txt");
	for(int i=0;i<n;i++)
		ifs>>a[i];
	ifs.close();
	start=clock();
	radix_sort(a,d,n);
	end=clock();
	ofs.open("out_prash(bsort).txt");
	for(int i=0;i<n;i++)
	{	
		ofs<<a[i]<<"\t";
	}
	ofs.close();
	cout<<double(end-start)/CLOCKS_PER_SEC<<"seconds"<<endl;
	cout<<comp<<"comparisons\n";
}
