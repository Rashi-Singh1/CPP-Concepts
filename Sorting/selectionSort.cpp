#include <iostream>
#include <vector>
using namespace std;
#define loop(x,start,end) for(int x = start; x < end; ++x)


//For placements -


void Swap(vector<int>& A, int index1, int index2)
{
	int t = A[index1];
	A[index1] = A[index2];
	A[index2] = t;
}

void SelectionSort(vector<int>& A, int start, int end)
{
	for (int i = start; i < end; ++i)
	{
		int minIndex = i;
		for (int j = i+1; j < end; ++j)
		{
			if(A[minIndex] > A[j]) minIndex = j;
		}
		if(i!=minIndex) Swap(A,i,minIndex);
	}
}


//


void swap(int* a,int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void selectionSort(int array[],int start, int end)
{
	int min;
	for (int i = start; i < end; ++i)
	{
		min  = i;
		for (int j = i+1; j < end; ++j)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		swap(&array[i],&array[min]);
	}
}


int main(int argc, char const *argv[])
{
	int k;
	cout<<" Enter size"<<endl;
	cin>>k;
	cout<<" Enter array"<<endl;
	int array[k];
	for (int i = 0; i < k; ++i)
	{
		cin>>array[i];
	}
	SelectionSort(array,0,k);
	for (int i = 0; i < k; ++i)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	return 0;
}