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

void InsertionSort(vector<int>& A, int start, int end)
{
	for (int i = start + 1; i < end; ++i)
	{
		for(int j = i-1; j>=start; j--)
		{
			if(A[j] > A[j+1]) Swap(A,j,j+1);
			else break;
		}
	}
}



//

void swap(int* a,int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void insertionSort(int array[],int start, int end)
{
	for (int i = start+1; i < end; ++i)
	{
		if (array[i-1] > array[i])
		{			
			// cout<<" array[i-1] > array[i] "<<array[i-1]<<" "<< array[i]<<endl;
			int temp = array[i];
			int index = -1;
			for (int j = i; j >0 ; j--)
			{
				// cout<<"j for i "<<j<<" "<<i<<endl;
				if (temp < array[j-1])
				{
					array[j] = array[j-1];
					index = j-1;
				}	
			}
			if(index > -1)
			{
				array[index] = temp;
			}
		}
		
	}
}


int main(int argc, char const *argv[])
{
	int size;
	cout<<" Enter size"<<endl;
	cin>>size;
	cout<<" Enter array"<<endl;
	// int array[size];
	vector<int> array(size);
	for (int i = 0; i < size; ++i)
	{
		cin>>array[i];
	}
	InsertionSort(array,0,size);
	for (int i = 0; i < size; ++i)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	return 0;
}
