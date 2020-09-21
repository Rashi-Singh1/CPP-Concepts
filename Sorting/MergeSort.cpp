#include <iostream>
#include <cstdlib>
#include<vector> 
#include "../Hashing/hashing.h"
#include <bits/stdc++.h>
using namespace std;
#define loop(x,start,end) for(int x = start; x < end; ++x)


//For placements : 

//end included
void Merge(vector<int>& A, int start, int end)
{
	if(start == end) return;

	int mid = (start + end)/2;
	//start - mid : first array
	//mid+1 - end : second array

	int array[end-start + 1];
	int k = 0;
	int index1 = start;
	int index2 = mid + 1;
	while(index1 <= mid && index2 <= end)
	{
		array[k++] = A[index1] < A[index2] ? A[index1++] : A[index2++];
	}
	while(index1 <= mid)
	{
		array[k++] = A[index1++];
	}
	while(index2 <= end)
	{
		array[k++] = A[index2++];
	}
	for (int i = 0; i < end-start + 1; ++i)
	{
		A[start + i] = array[i];
	}
}

//end included
void MergeSort(vector<int>& A, int start, int end)
{
	//ensures 2 elements
	if(start < end)
	{
		int mid = (start + end)/2;
		MergeSort(A,start,mid);
		MergeSort(A,mid+1,end);
		Merge(A,start,end);
	}
}

int main(int argc, char const *argv[])
{
	int size;
	cout<<" Enter size"<<endl;
	cin>>size;
	cout<<" Enter array"<<endl;
	vector<int> array(size);
	for (int i = 0; i < size; ++i)
	{
		cin>>array[i];
	}
	MergeSort(array,0,size-1);
	for (int i = 0; i < size; ++i)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	return 0;
}
//


void merge(int* value, int start,int mid, int end)
{
	int array[end-start+1];
	int k = 0,i=start,j=mid+1;
	while(i<=mid && j<=end)
	{
		if (value[i] <= value[j])
		{
			array[k++] = value[i ];
			i++;
		}
		else
		{
			array[k++] = value[j];
			j++;
		}
	}
	while(i <= mid){
		array[k++] = value[i];
		i++;
	}
	while(j <= end){
		array[k++] = value[j];
		j++;
	}
	for (int i = 0; i < end-start+1; ++i)
	{
		value[i+start] = array[i];
	}
}

void mergeSort(int array[],int start, int end)
{
	if (start < end)
	{
		int mid = (start+end)/2;
		mergeSort(array,start,mid);
		mergeSort(array,mid+1,end);
		merge(array,start,mid ,end);
	}
}


/*Student Count thingy jiska binary search pattern i use everywhere (probabaly the q next to painters's something problem) */
// void main2() {
// 	vector<int> A = {23, 6, 13, 70, 38, 94, 20, 44, 66, 34, 26, 94, 63, 38, 44, 90, 50, 59, 23, 47, 85, 17, 72, 39, 47, 85};
// 	int B = 7;
// 	// int ans;
//  //    if(B > A.size()) ans = -1;
//  //    if(A.size() == 0) ans = -1;
//     int start = A[0];
//     int end = A[0];
//     int maximum = A[0];
//     for(int i = 1;i<A.size();i++)
//     {
//         start = min(start,A[i]);
//         end += A[i];
//         maximum = max(maximum,A[i]);
//     }
//     int ans = -1;
//     int mid;
//     while(start<=end)
//     {
//         mid = (start+end)/2;
//         int sum = 0,count = 0;
//         if(maximum > mid)
//         {
//         	start = mid+1;
//         	continue;
//         }
//         cout<<"1     "<<start<<" "<<mid<<" "<<end<<endl;
//         for(int i = 0;i<A.size();i++)
//         {
//             sum+=A[i];
//             cout<<"2     sum "<<sum<<"  count yet "<<count<<"    i "<<i<<endl;
//             if(sum > mid) {
//                 count++;
//                 sum=0;
//                 i--;
//             }
//             // if(sum == mid)
//             // {
//             //     if(i < A.size()-1) count++;
//             //     sum = 0;
//             // }
//         }
//         if(count < B)
//         {
//             end = mid-1;
//             ans = mid;
//         }
//         else{
//             start = mid+1;
//         }
//         // mid = (start+end)/2;
//     }
//     cout<<ans<<endl;
// }



// bool ok(int mid,vector<int>v,int size,int StudCount){
// 	// cout<<mid<<" "<<StudCount<<endl;
//     int _max_ele = *max_element(v.begin(), v.end());
//             if(_max_ele > mid)
//                     return false; 
//     int s=0,c=0;
//     for(int i=0;i<size;){
//         s+=v[i];
//         if(s>mid){
//             c++;
//             s=0;
//         }
//         else i++;
//         cout<<"2     sum "<<s<<"  count yet "<<c<<"    i "<<i<<endl;
//     }
//     if(c < StudCount)return true;
//     return false;
// }
// int main() {
// 	// vector<int> v = {}
// 	vector<int> v = {23, 6, 13, 70, 38, 94, 20, 44, 66, 34, 26, 94, 63, 38, 44, 90, 50, 59, 23, 47, 85, 17, 72, 39, 47, 85};
// 	int x = 7;
//     int n=v.size(),end=0,start=0,r=(1<<30);
//     if(x>n)return -1;
//     for(int i=0;i<n;i++){
//         end+=v[i];
//     }
//     while(start<=end){
//         int mid=(start+end)/2;
//         cout<<"1     "<<start<<" "<<mid<<" "<<end<<endl;
//         if(ok(mid,v,n,x)){
//             r=min(r,mid);
//             end=mid-1;
//         }
//         else start=mid+1;
//     }
//     cout<<"ans : "<<r<<endl;
//     cout<<endl<<endl<<" My ans"<<endl;
//     main2();
// }


/*How to find median in 2D Array*/

// bool sortcol( const vector<int>& v1, 
//                const vector<int>& v2 ) { 
//  return v1[0] < v2[0]; 
// } 

// int floorSearch(vector<int> &array, int start, int end , int x)
// {
// 	cout<<"3    "<<endl;
//    while(start <= end )
//    {
//       if(x >= array[end]) return end;
//       if(x < array[start]) return -1;
//       int mid = (start+end)/2;
//       if(array[mid] == x) return mid;
//       else if(array[mid] < x)
//       {
//          if(mid+1 <=end && array[mid+1] > x)
//             return mid;
//          else
//             start = mid+1;
//       }else{
//          if(mid-1 >= start && array[mid-1] <= x)
//             return mid-1;
//          else
//             end = mid-1;
//       }
//    }
//    return -1;
// }


// int main() {
// 	vector<vector<int> > A =  {{1, 3, 5}
// 							  ,{2, 6, 9}
// 							  ,{3, 6, 9}};
//     if(A.size() > 0)
//     {
//         int row = A.size();
//         int col = A[0].size();
//         sort(A.begin(), A.end(),sortcol); 
//         int start = A[0][0];
//         int end = A[0][col-1];
//         for(int i = 1;i<row;i++)
//         {
//             start = min(start,A[i][0]);
//             end = max(end,A[i][col-1]);
//         }
//         while(start<=end)
//         {
//             int mid = (start+end)/2;
// 	    	cout<<"1    "<<start<<" "<<mid<<" "<<end<<endl;
//             int tots= 0;
//             for(int i = 0;i<row;i++)
//             {
//             	int temp = floorSearch(A[i],0,col-1,mid);
//                 tots += temp;
//                 if(A[i][temp] != mid)
//                 {
//                 	tots++;
//                 }
//                 cout<<"2   tots "<<tots<<endl;
                
//             }
//             if(tots == ((row*col)/2)) {
//                     cout<<"ans : "<<mid<<endl;
//                     start = end+1;
//                     break;
//                 }else if(tots > (row*col)/2)
//                 {
//                     end = mid - 1;
//                     tots = 0;
//                     break;
                    
//                 }else{
//                     start = mid + 1;
//                     tots = 0;
//                     break;
//                 }
//         }
//     }
//     return 0;
// }


//Codechef ques of pseudo palindrome strings
// int main()
// {
// 	int t;
// 	cin>>t;
// 	for(int o = 0;o<t;o++)
// 	{
// 		string name;
// 		int array[26];
// 		for (int i = 0; i < 26; ++i)
// 		{
// 			/* code */
// 			array[i] = 0;
// 		}
// 		cin>>name;
// 		// for(int i = 0;i<name.size();i++)

// 		int trash = -1;
// 		bool replaced = false;
// 		bool changed = false;
// 		int count = 0;
// 		bool flag = false;
// 		int count2 = 0;
// 		int trash2 =-1;
// 		for(int i = 0;i<name.size()/2;i++)
// 		{
// 			if(name[i] == name[name.size()-1-i]) {
// 				//cout<<"1 continue         i "<<i<<endl;
// 				continue;
// 			}
// 			else{
// 				if(changed == false && count2 == 0)
// 				{
// 					//cout<<"22 set trash2         i "<<i<<endl;
// 					trash2 = i;
// 					// count2++;
// 				}
// 				if(replaced == false  && count == 0) {
// 					count++;
// 					//cout<<"2 set trash         i "<<i<<endl;
// 					trash = i;
// 				}
// 				else if(replaced == true && changed == false)
// 				{
// 					count2++;
// 					//cout<<"3 replace        i "<<i<<endl;
// 					name[name.size()-1-i] = name[i];
// 					changed = true;
// 				}
// 			}
// 			if(replaced == false)
// 			{
// 				if(i!=trash && trash!=-1 && name[i] == name[trash]){
// 					//cout<<"5 replace         i "<<i<<endl;
// 					char t;
// 					t = name[i];
// 					//cout<<"trash "<<trash<<endl;
// 					//cout<<" t "<<t<<endl;
// 					name[i] = name[name.size()-1-trash];
// 					name[name.size()-1-trash] = t;
// 					replaced = true;
// 					//cout<<name<<endl;
// 					i--;
// 				}else if (i!=trash && trash!=-1 && name[name.size()-1-i] == name[trash])
// 				{
// 					//cout<<"6 replace         name.size()-1-i "<<name.size()-1-i<<endl;
// 					char t;
// 					t = name[name.size()-1-i];
// 					//cout<<"trash "<<trash<<endl;
// 					//cout<<" t "<<t<<endl;
// 					name[name.size()-1-i] = name[name.size()-1-trash];
// 					name[name.size()-1-trash] = t;
// 					replaced = true;
// 					//cout<<name<<endl;
// 					i--;
// 				}else if(name.size()-1-i!=(name.size()-1-trash) && trash!=-1 && name[name.size()-1-i] == name[name.size()-1-trash]){
// 					//cout<<"7 replace         name.size()-1-i "<<name.size()-1-i<<endl;
// 					char t;
// 					t = name[name.size()-1-i];
// 					//cout<<"trash "<<trash<<endl;
// 					//cout<<" t "<<t<<endl;
// 					name[name.size()-1-i] = name[trash];
// 					name[trash] = t;
// 					replaced = true;
// 					//cout<<name<<endl;
// 					i--;
// 				}
// 				else if(i!=(name.size()-1-trash) && trash!=-1 && name[i] == name[(name.size()-1-trash)])
// 				{
// 					//cout<<"8 replace         i "<<i<<endl;
// 					char t;
// 					t = name[i];
// 					//cout<<"trash "<<trash<<endl;
// 					//cout<<" t "<<t<<endl;
// 					name[i] = name[trash];
// 					name[trash] = t;
// 					replaced = true;
// 					//cout<<name<<endl;
// 					i--;
// 				}
// 			}
// 		}
// 		if(trash2!= -1 && changed == false)
// 		{
// 			//cout<<"50 change        "<<"trash2  "<<trash2<<endl;
// 			name[trash2] = name[name.size()-1-trash2];
// 			changed = true;
// 			count2++;
// 		}
// 		//cout<<"trash "<<trash<<" mid "<<name[name.size()/2]<<" replaced "<<replaced<<endl;
// 		if(replaced == false && name.size()%2!=0 && trash!=-1 && name[trash] == name[name.size()/2])
// 		{
// 			//cout<<"9 replace         i "<<endl;
// 			char t;
// 			t = name[name.size()/2];
// 			//cout<<"trash "<<trash<<endl;
// 			//cout<<" t "<<t<<endl;
// 			name[name.size()/2] = name[name.size()-1-trash];
// 			name[name.size()-1-trash] = t;
// 			replaced = true;
// 			//cout<<name<<endl;
					
// 		}else if(replaced == false && name.size()%2!=0 && trash!=-1 && name[name.size()-1-trash] == name[name.size()/2])
// 		{
// 			//cout<<"10 replace         i "<<endl;
// 			char t;
// 			t = name[name.size()/2];
// 			//cout<<"trash "<<trash<<endl;
// 			//cout<<" t "<<t<<endl;
// 			name[name.size()/2] = name[trash];
// 			name[trash] = t;
// 			replaced = true;
// 			//cout<<name<<endl;
// 		}
// 		string blah = name;
// 		reverse(blah.begin(),blah.end());

// 		if(!(count==0 && count2==0) && flag == false && (name.compare(blah)) == 0) cout<<"DPS"<<endl;
// 		else if(flag == false){
// 			if(name.size()%2!=0 && changed == false)
// 				cout<<"DPS"<<endl;
// 			else
// 				cout<<"!DPS"<<endl;
// 		}
// 	}
// }
