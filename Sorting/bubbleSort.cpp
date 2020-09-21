#include <iostream>
#include <vector>
using namespace std;
#define loop(x,start,end) for(int x = start; x < end; ++x)

//For placements - 

void Swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void BubbleSort(vector<int>&A, int start, int end)
{
	for (int i = start; i < end; ++i)
	{
		for (int j = i+1; j < end; ++j)
		{
			if(A[i] > A[j]) Swap(&A[i],&A[j]);
		}
	}
}

//


void swap(float* a,float* b)
{
	float t = *a;
	*a = *b;
	*b = t;
}

void bubbleSort(float* array,int start, int end)
{
	for (int i = end-1; i >=start; i--)
	{
		for(int j = start;j<i;j++)
		{
			if (array[j] > array[j+1])
			{
				swap(&array[j],&array[j+1]);
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	//int size;
	//cout<<" Enter size"<<endl;
	//cin>>size;
	//cout<<" Enter array"<<endl;
int size = 1000;
	 float array[] = {
0.681,
1.11,
0.485,
0.502,
0.545,
0.434,
0.423,
0.479,
0.270,
0.500,
0.483,
0.508,
0.509,
0.488,
0.310,
0.497,
0.527,
0.490,
1.08,
0.480,
0.452,
0.476,
0.487,
0.484,
0.494,
0.463,
0.505,
0.488,
0.491,
0.968,
0.500,
0.503,
0.512,
0.305,
0.284,
0.301,
1.70,
1.89,
0.500,
0.501,
0.492,
0.521,
0.484,
0.517,
0.508,
0.546,
0.543,
0.498,
0.506,
0.521,
0.499,
0.487,
0.490,
0.457,
0.495,
0.490,
0.492,
0.496,
0.519,
0.269,
0.475,
0.303,
0.477,
0.481,
0.488,
0.498,
0.493,
0.495,
0.488,
0.495,
0.494,
0.494,
0.497,
0.493,
0.486,
0.502,
0.567,
0.526,
0.386,
0.528,
16.1,
2.24,
0.531,
0.496,
0.522,
0.500,
0.362,
0.547,
0.489,
0.543,
0.508,
0.527,
0.499,
0.493,
0.499,
0.486,
0.513,
0.575,
0.479,
0.470,
0.477,
0.510,
0.496,
3.00,
0.488,
0.495,
0.507,
0.484,
0.341,
0.382,
0.306,
0.510,
0.464,
0.508,
0.443,
0.443,
0.499,
0.499,
0.466,
0.538,
0.602,
0.497,
0.301,
0.451,
0.502,
0.500,
0.501,
0.497,
0.497,
0.760,
0.499,
0.502,
0.494,
0.309,
1.20,
0.393,
0.434,
0.471,
2.70,
0.925,
0.503,
0.503,
0.505,
0.529,
2.60,
1.74,
0.500,
0.417,
0.497,
0.527,
0.440,
0.418,
0.574,
0.525,
0.652,
0.495,
0.490,
0.506,
0.491,
0.525,
0.482,
0.514,
0.349,
0.734,
0.497,
0.412,
0.514,
0.522,
0.547,
0.549,
0.523,
0.304,
0.489,
0.498,
0.307,
0.558,
0.508,
0.759,
0.514,
0.433,
0.495,
0.497,
0.485,
0.489,
0.494,
0.306,
0.523,
0.505,
0.523,
0.573,
0.500,
0.496,
1.51,
3.18,
0.521,
0.529,
0.536,
0.511,
0.649,
0.385,
0.382,
0.541,
0.502,
0.517,
0.506,
0.391,
0.390,
0.497,
0.489,
0.488,
0.409,
0.508,
0.533,
0.476,
0.508,
0.306,
0.552,
0.508,
0.502,
0.498,
0.535,
0.516,
0.299,
1.85,
0.503,
0.337,
0.326,
0.498,
0.497,
0.501,
0.498,
0.364,
0.526,
0.521,
0.548,
0.330,
0.493,
0.448,
0.498,
0.506,
0.493,
0.490,
0.497,
0.493,
0.502,
0.487,
0.512,
0.482,
0.488,
0.511,
0.496,
0.421,
0.498,
0.507,
0.510,
0.522,
0.516,
0.548,
0.504,
0.512,
0.491,
0.548,
0.533,
0.542,
0.527,
0.504,
0.509,
0.556,
0.431,
0.532,
0.497,
0.541,
0.529,
0.525,
1.34,
0.454,
0.549,
0.507,
0.504,
0.501,
0.493,
0.513,
0.366,
0.282,
0.492,
0.477,
0.506,
0.508,
0.505,
0.508,
3.36,
0.523,
1.18,
0.534,
0.512,
0.469,
0.533,
0.513,
0.537,
0.523,
0.459,
0.533,
0.501,
0.532,
0.492,
0.511,
2.80,
0.535,
0.437,
0.520,
0.510,
0.494,
0.560,
0.534,
0.526,
0.426,
0.500,
0.478,
0.497,
0.491,
0.489,
0.520,
0.506,
0.491,
0.495,
0.491,
0.485,
0.489,
0.528,
0.496,
0.246,
0.501,
0.269,
0.304,
0.485,
0.507,
0.492,
0.493,
0.489,
0.460,
0.487,
0.513,
0.489,
0.513,
0.530,
0.491,
0.498,
0.498,
0.536,
0.920,
0.490,
0.474,
0.627,
0.467,
0.519,
0.290,
0.494,
0.525,
0.489,
0.480,
0.480,
1.99,
0.490,
0.512,
0.538,
0.521,
0.517,
0.528,
0.538,
0.515,
0.517,
0.529,
0.548,
0.373,
0.379,
1.48,
0.366,
0.294,
0.493,
0.477,
0.492,
0.358,
0.532,
2.14,
1.37,
0.458,
0.537,
0.832,
0.504,
0.473,
0.534,
0.496,
0.540,
0.515,
0.502,
0.529,
0.504,
0.506,
3.20,
0.490,
0.501,
0.507,
0.694,
0.490,
0.487,
0.490,
0.423,
0.488,
0.461,
1.13,
0.503,
1.46,
0.524,
0.498,
0.683,
0.510,
0.499,
0.497,
0.499,
0.522,
0.781,
0.515,
0.545,
0.524,
0.498,
0.524,
0.829,
0.540,
0.523,
0.510,
0.532,
0.476,
0.514,
0.523,
0.275,
0.527,
0.520,
0.534,
0.491,
0.535,
0.498,
0.353,
0.511,
0.468,
0.515,
0.494,
0.510,
0.485,
0.515,
0.455,
0.486,
0.483,
0.624,
0.495,
0.516,
0.457,
0.561,
0.490,
0.490,
1.70,
0.280,
0.506,
0.485,
0.513,
0.515,
0.550,
0.527,
0.332,
0.500,
0.524,
0.534,
0.505,
0.555,
0.518,
0.549,
0.517,
0.530,
0.537,
0.324,
0.639,
0.492,
0.530,
0.473,
0.310,
0.450,
0.477,
0.521,
0.544,
0.528,
0.311,
0.505,
0.533,
0.495,
0.493,
0.399,
4.11,
0.592,
0.491,
0.496,
0.493,
0.449,
0.489,
0.475,
0.498,
0.302,
1.19,
0.495,
0.484,
0.468,
0.265,
0.501,
0.497,
0.504,
0.536,
0.497,
0.482,
0.486,
0.446,
0.441,
0.517,
0.493,
0.489,
0.600,
0.485,
2.56,
0.490,
0.495,
0.432,
0.507,
0.447,
0.504,
0.493,
0.540,
0.275,
0.541,
0.518,
0.521,
0.519,
0.623,
0.529,
0.531,
0.464,
0.514,
4.99,
0.488,
0.524,
0.498,
0.495,
0.494,
0.493,
0.907,
0.483,
0.502,
0.506,
0.501,
0.475,
0.485,
1.01,
0.277,
0.402,
0.499,
0.512,
0.463,
0.500,
0.495,
0.498,
0.283,
0.507,
0.406,
0.506,
0.513,
0.489,
0.487,
0.522,
0.497,
0.496,
0.547,
0.511,
0.553,
0.454,
0.539,
0.509,
0.507,
0.490,
0.288,
0.492,
0.871,
0.514,
0.319,
0.455,
0.438,
0.518,
0.503,
0.492,
0.486,
0.481,
0.516,
0.527,
0.524,
0.530,
0.878,
0.304,
0.433,
0.467,
0.427,
0.396,
0.545,
0.540,
0.537,
1.09,
0.529,
0.535,
0.507,
0.407,
0.388,
1.03,
0.522,
0.501,
0.520,
1.05,
0.511,
0.515,
0.511,
0.516,
0.531,
0.502,
0.525,
0.491,
0.413,
0.500,
0.515,
0.525,
0.520,
0.514,
0.509,
0.509,
0.483,
0.492,
0.488,
0.503,
0.413,
0.513,
1.18,
0.545,
0.532,
0.507,
0.514,
0.296,
0.492,
0.521,
0.508,
0.499,
0.411,
0.413,
0.557,
0.495,
0.496,
0.383,
0.288,
0.526,
0.473,
0.547,
1.33,
0.563,
0.476,
0.405,
0.487,
0.497,
0.497,
0.597,
0.543,
0.534,
0.546,
0.369,
0.412,
0.380,
0.592,
0.538,
0.341,
1.34,
0.532,
0.526,
0.552,
0.509,
0.306,
0.377,
0.760,
0.528,
0.500,
0.382,
0.397,
0.372,
0.305,
0.518,
0.511,
0.501,
0.501,
0.491,
0.495,
0.497,
0.503,
0.360,
0.485,
0.496,
0.497,
0.366,
0.506,
0.943,
0.259,
0.277,
0.940,
0.500,
0.492,
0.494,
0.518,
0.320,
0.502,
0.522,
0.511,
0.366,
0.489,
0.487,
0.578,
0.503,
0.483,
0.495,
0.300,
0.506,
0.489,
0.489,
0.478,
0.491,
1.39,
0.489,
0.500,
3.23,
0.462,
0.490,
0.508,
0.497,
0.546,
0.483,
0.339,
0.490,
0.496,
0.505,
0.537,
0.347,
0.501,
0.546,
0.541,
0.967,
0.438,
0.390,
0.478,
0.517,
0.560,
0.533,
0.514,
0.531,
0.481,
0.526,
0.523,
0.535,
0.525,
0.508,
2.02,
0.458,
2.78,
0.517,
0.515,
0.524,
0.538,
0.524,
0.470,
0.406,
0.492,
0.489,
0.494,
0.511,
1.38,
0.582,
0.530,
0.446,
0.525,
0.524,
0.830,
0.524,
0.518,
0.504,
0.507,
0.324,
0.587,
0.540,
0.466,
0.487,
0.495,
0.496,
0.502,
1.30,
2.17,
0.517,
0.497,
0.493,
0.486,
0.491,
0.498,
0.500,
0.514,
0.311,
0.496,
0.553,
0.506,
0.308,
0.515,
0.795,
0.504,
0.577,
0.491,
0.500,
0.489,
0.557,
0.532,
0.501,
0.537,
0.523,
0.535,
0.535,
0.454,
0.495,
0.515,
0.303,
1.20,
0.554,
0.511,
0.511,
1.73,
0.525,
0.520,
0.314,
0.378,
0.523,
0.307,
0.536,
0.503,
0.572,
0.582,
1.38,
0.359,
0.489,
0.519,
0.502,
0.496,
0.490,
0.490,
0.496,
1.16,
0.494,
0.494,
0.478,
0.292,
0.494,
0.485,
0.500,
0.489,
2.67,
0.303,
0.695,
3.13,
0.503,
0.501,
0.810,
0.507,
0.495,
0.599,
0.492,
0.500,
0.353,
0.494,
0.486,
0.456,
3.71,
0.483,
0.509,
0.490,
0.500,
0.498,
0.487,
0.513,
0.497,
0.492,
0.497,
0.499,
0.489,
0.491,
0.490,
0.508,
0.488,
0.492,
0.603,
0.488,
0.509,
0.477,
0.486,
0.487,
0.514,
0.588,
0.495,
0.493,
0.583,
0.491,
0.503,
0.496,
0.495,
0.497,
0.276,
0.488,
0.491,
0.497,
0.495,
0.464,
0.483,
0.486,
0.490,
0.530,
0.495,
0.497,
0.496,
0.643,
0.491,
0.496,
0.497,
0.494,
0.494,
1.20,
0.500,
0.502,
0.487,
2.71,
3.18,
0.510,
0.590,
1.06,
0.415,
1.59,
0.555,
0.344,
0.523,
0.507,
0.509,
0.293,
0.502,
0.512,
0.512,
0.477,
0.515,
0.410,
0.317,
0.502,
0.536,
0.509,
0.518,
0.501,
0.494,
0.495,
0.495,
0.485,
0.497,
0.507,
0.492,
0.479,
0.485,
0.486,
0.505,
0.491,
1.08,
1.74,
0.485,
0.497,
0.474,
0.486,
0.480,
0.495,
0.496,
0.506,
1.71,
1.11,
0.437,
0.508,
0.500,
0.522,
0.478,
0.489,
0.510,
0.496,
0.494,
0.488,
0.481,
0.490,
0.496
};
	//vector<int> array(size);
	//for (int i = 0; i < size; ++i)
	//{
//		cin>>array[i];
//	}
	bubbleSort(array,0,1000);
	for (int i = 0; i < size; ++i)
	{
		cout<<array[i]<<endl;
	}
	cout<<endl;
	return 0;
}
