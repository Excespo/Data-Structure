#include <string.h>
#include "Compare.h"
#include "InternalSortingPreview.h"
using namespace std;

template <class Elem>
void printA(Elem A[], int n){
	for(int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << "\n";
}

template <typename Elem, typename Comp>
Elem findKbiggestBase(Elem* arr, int lo, int hi, int K) {
    if (lo < hi) {
        int pivRank = lo, endRank = hi;
        Elem piv = arr[lo++];
        while (true) {
            while (lo < endRank && Comp::lt(arr[lo],piv)) lo++;
            while (hi > pivRank && Comp::lt(piv,arr[hi])) hi--;
            if (lo>=hi) break;
            std::swap(arr[lo], arr[hi]); lo++; hi--;
        }
        std::swap(arr[pivRank], arr[hi]);
        if ( K == (endRank - hi + 1) ) {
            return arr[hi];
        } else if ( K < (endRank - hi + 1) ) {
            findKbiggestBase<Elem, Comp>(arr, hi + 1, endRank, K);
        } else {
            findKbiggestBase<Elem, Comp>(arr, pivRank, hi - 1, K - (endRank - hi + 1));
        }
    }
} 

// Find median
// Apply divide & conquer 
template <class Elem, class Comp>
Elem FindMedian(Elem A[], int n){
	Elem median = findKbiggestBase<Elem, Comp>(A, 0, n, n/2);
	return median;
}

int main()
{
	int a_int[] = {42, 92, 79, 96, 66, 4, 85, 93, 68, 76, 74, 39, 63, 17, 71, 3};
	int a_int2[] = {42, 92, 79, 96, 66, 4, 85, 93, 68, 76, 74, 39, 63, 17, 71, 3};
	int n_int = 16;

	cout << "A set of integers: "; printA(a_int, n_int);
	InsertionSort<int,IntCompare>(a_int, n_int);
	cout << "Median integer: " << a_int[n_int/2] << endl;
	
	int a_median = FindMedian<int,IntCompare>(a_int2, n_int);
	// int a_median = findKbiggestBase<int, IntCompare>( a_int, 0, n_int, n_int/2 );
	cout << "Median integer: " << a_median << endl; 

	return 0;
}

