#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int x;
int s[10][10];

void paren(int i,int j)
{
	if(i==j)
		cout<<"a["<<i<<"]";
	else
		{
			cout<<"(";
			paren(i,s[i][j]);
			paren(s[i][j]+1,j);
			cout<<")";
		}
}

void mcm(int p[],int n)
{
	int m[n][n];
	for(int i=1;i<=n;i++)
		m[i][i]=0;
	for(int l=2;l<=n;l++)
	{
		for(int i=1;i<=n-l+1;i++)
		{
			int j=i+l-1;
			m[i][j]=99999;
			for(int k=i;k<j;k++)
			{
				int x=m[i][k]+m[k+1][j]+p[i-1]*p[j]*p[k];
				if(x<m[i][j])
				{
					m[i][j]=x;
					s[i][j]=k;
				}
			}
		}
	}
cout<<m[1][n];
paren(1,n);

}
int brute(int p[],int i,int j)
{int min=999999,count;
	if(i==j)
	{
		return 0;
	}
	else
	{
		
		for(int z=i;z<j;z++)
		{

			count=p[i-1]*p[z]*p[j]+brute(p,i,z)+brute(p,z+1,j);
			if(min>count)
			{	
				min=count;
				
			}
		}
		return min;
	}

}
		
	 
int main()
{
	int n;
	cout<<"enter no of matrices";
	cin>>n;
	x=n;
	int *p;
	p=new int[n+1];
	cout<<"enter the size of matrices";
	for(int i=0;i<=n;i++)
		cin>>p[i];
	mcm(p,n);
	int a=brute(p,1,n);
	cout<<'\n'<<a;
}
	
