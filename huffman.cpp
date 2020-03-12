#include<iostream>
using namespace std;
struct node
{	int freq;
	char data;
	node	*left;
	node 	*right;
};
node *temp[100];
int n;
string a="0";
string b="1";
void swap(node* &a,node* &b)
{
	node *u=a;
		a=b;
		b=u;
}
void min_heapify(int i)
{
	int l=2*i+1,r=2*i+2,small;
	if(l<n && temp[l]->freq	<temp[i]->freq)
		small=l;
	else
		small=i;
	if(r<n && temp[r]->freq <temp[small]->freq)
		small=r;
	if(small!=i)
	{
		swap(temp[i],temp[small]);
		min_heapify(small);
	}
}
void build_min_heap()
{
	for(int i=n/2;i>=0;i--)
	{
		min_heapify(i);
	}
}
int parent(int i)
{
	return (i-1)/2;
}
void insert(node *j)
{
	n++;
	temp[n-1]=j;

	int y=n-1;
while(y!=0 && temp[parent(y)]>temp[y])
{
	swap(temp[parent(y)],temp[y]);
	y=parent(y);
}
cout<<"left"<<j->left->freq<<endl;
cout<<"right"<<j->right->freq<<endl;
}
node* extract_min()
{
	node *r=temp[0];
	temp[0]=temp[n-1];
	n--;
	min_heapify(0);

	return r;
}
void huffmann()
{

	int g=n;
	for(int i=0;i<g-1;i++)
	{	node *x,*y,*z;
	x=new node;
	y=new node;
	z=new node;
		z->left=x=extract_min();
		z->right=y=extract_min();
		z->freq=x->freq+y->freq;
			insert(z);
			}
}
void print(node *head,string s)
{
	node *l=new node;
	l=head->left;
	node *r=new node;
	r=head->right;
	if(!(l||r))
	{
		cout<<"char"<<head->data<<" \t hf code"<<s<<endl;
	}
	if(l)
	{
		string k;
		k=a+s;
		print(l,k);
	
	}
	if(r)
	{
		string k;
		k=b+s;
		print(r,k);
	}
}
		
 

int main()
{
	int f;
	char d;
	cout<<"enter no of elements";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		temp[i]=new node;

		cin>>f;
		//cin>>d;
		temp[i]->freq=f;
	}
build_min_heap();
huffmann();
print(temp[0]->left,a);
print(temp[0]->right,b);
}

		
	
