#include<iostream>
#include<stdlib.h>
#include<time.h>
#define SIZE 5000
using namespace std;

float count_steps=0;

void BestCaseinput(int* arr, int n)
	{
		for(int i=0; i<n; i++)
			{
				arr[i] = i+1;
			}
	}

void WorstCaseinput(int* arr, int n)
	{
		arr[0]=n;
		for(int i=1;i<n;i++)
		{
			arr[i] =arr[i-1]- 1;
		}
	}

void RandomInput(int* arr, int n )
	{
		srand(time(0));
		for(int i=0;i<n;i++)
		{
			arr[i]=1+(rand()%n);
		}
	}

void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void merge(int arr[], int p, int q, int r)
{
	int n1 = q - p + 1;
  	int n2 = r - q;
  	int L[n1], M[n2];
 	for (int i = 0; i < n1; i++)
    	L[i] = arr[p + i];
    //	count_steps++;
  	for (int j = 0; j < n2; j++)
    	M[j] = arr[q + 1 + j];
    	//count_steps++;
  	int i, j, k;
  	i = 0;
  	j = 0;
  	k = p;
  	while (i < n1 && j < n2) {
    	if (L[i] <= M[j]) {
      		arr[k] = L[i];
      		i++;
      		count_steps++;
    	} else {
      		arr[k] = M[j];
      		j++;
      		count_steps++;
   		 }
    	k++;
    	
  	}
  	while (i < n1) {
    	arr[k] = L[i];
    	i++;
    	k++;
    	count_steps++;
  	}

  	while (j < n2) {
    	arr[k] = M[j];
    	j++;
    	k++;
    	count_steps++;
  	}
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
	count_steps++;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}
void Merge(int A[],int l,int mid,int h)
	{
		int i=l,j=mid+1,k=l;
 		int B[SIZE];
		count_steps++;
 		while(i<=mid && j<=h)
 		{
 			count_steps++;
 			if(A[i]<A[j])
 				B[k++]=A[i++];
 			else
 				B[k++]=A[j++];
 		}
 		for(;i<=mid;i++)
 			B[k++]=A[i];
 			count_steps++;
 		for(;j<=h;j++)
 			B[k++]=A[j];
 			count_steps++;
 		for(i=l;i<=h;i++)
 			A[i]=B[i];
 			count_steps++;
}
void MergeSort(int A[],int l,int h)
	{
 		int mid;
 		if(l<h)
 		{
 			count_steps++;
 			mid=(l+h)/2;
 			MergeSort(A,l,mid);
 			MergeSort(A,mid+1,h);
 			Merge(A,l,mid,h);
		}
	}

int main()
{
	int arr[SIZE];
	int n;
	cout<<"Enter the size n: ";
	cin>>n;
//	BestCaseinput(arr,n);
//	MergeSort(arr,0,n);
//	cout<<"Best Case Steps: "<<count_steps<<endl;
//	count_steps=0;
//	WorstCaseinput(arr, n);
//	MergeSort(arr,0,n);
//	cout<<"Worst Case Steps: "<<count_steps<<endl;
	count_steps=0;
	RandomInput(arr,n);
	MergeSort(arr,0,n);
	cout<<"Number of Steps: "<<count_steps<<endl;
	cout<<"Robin-23498-DAA-lab-Prime"<<endl;
	
	return 0;
}

