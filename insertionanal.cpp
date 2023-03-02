#include<iostream>
#include<stdlib.h>
#include<time.h>
#define SIZE 2500
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
			arr[i]=(rand()%n);
		}
	}

void Insertion(int A[],int n)
{	
	count_steps=0;
 	int i,j,x;
	for(i=1;i<n;i++)
 	{
 		j=i-1;
 		x=A[i];
 		count_steps++;
 		while(j>-1 && A[j]>x)
 		{
 			count_steps++;
 			A[j+1]=A[j];
 			j--;
	 	}
 		A[j+1]=x;
	 }
}

int main()
{
	int arr[SIZE];
	int n;
	cout<<"Enter the size n: ";
	cin>>n;
	BestCaseinput(arr,n);
	Insertion(arr,n);
	cout<<"Best Case Steps: "<<count_steps<<endl;
	
	WorstCaseinput(arr, n);
	Insertion(arr,n);
	cout<<"Worst Case Steps: "<<count_steps<<endl;
	
	RandomInput(arr,n);
	Insertion(arr,n);
	cout<<"Random Case Steps: "<<count_steps<<endl;
	cout<<"Robin-23498-DAA-lab-Prime"<<endl;
	
	return 0;
}

