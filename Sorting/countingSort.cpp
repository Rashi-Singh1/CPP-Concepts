#include <iostream>
#include <vector>
using namespace std;

//For placements -
void CountingSort(vector<int>& A, int start, int end)
{
	vector<int> buffer(end - start + 1 , 0);
	for (int i = 0; i < A.size(); ++i)
	{
		buffer[A[i]-start]++;
	}
	for (int i = 0,k=0; i < buffer.size(); ++i)
	{
		for (int j = 0; j < buffer[i]; ++j,++k)
		{
			A[k] = i + start;
		}
	}
}
//

int CountingSortForWholeNumbers(vector<int> &array, int range)
{
	vector<int> buffer(range+1,0);
	for (int i = 0; i < array.size(); ++i)
	{
		buffer[array[i]]++;
	}
	int k = 0;
	for (int i = 0; i <= range; ++i)
	{
		for (int j = 0; j < buffer[i]; ++j)
		{
			array[k++] = i;
		}
	}
}

int CountingSortForNegNumbers(vector<int> &array, int start, int end)
{
	vector<int> buffer(start + end + 1,0);
	for (int i = 0; i < array.size(); ++i)
	{
		buffer[array[i]+start]++;
	}
	int k = 0;
	for (int i = -1*start; i <= end; ++i)
	{
		for (int j = 0; j < buffer[i+start]; ++j)
		{
			array[k++] = i;
		}
	}
}

int main(int argc, char const *argv[])
{
	int start, end;
	cout<<"Enter 2 ranges"<<endl;
	cin>>start>>end;
	vector<int> v;
	int size;
	cout<<"Enter array size"<<endl;
	cin>>size;
	for (int i = 0; i < size; ++i)
	{
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	CountingSort(v,start,end);
	for (int i = 0; i < size; ++i)
	{
		cout<<v[i]<<" ";
	}cout<<endl;
	return 0;
}