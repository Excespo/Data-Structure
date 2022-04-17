#include <iostream>

using std::cout;

template <typename T>
T findKbiggest(T* arr, int n, int K);
template <typename T>
T findKbiggestBase(T* arr, int lo, int hi, int K);
template <typename T>
T findMedian(T* arr, int n);

int main() {

    int n = 12;
    int arr[] = {7, 9, 63, 32, 79, 9, 31, 35, 25, 67, 78, 26};
    cout << "Find Median for int array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
    int median = findMedian(arr, n);
    cout << "Median is " << median << "\n";

    return 0;
}

template <typename T>
T findKbiggest(T* arr, int n, int K) {
    return findKbiggestBase(arr, 0, n-1, K);
}

template <typename T>
T findKbiggestBase(T* arr, int lo, int hi, int K) {
    if (lo < hi) {
        int pivRank = lo, endRank = hi;
        T piv = arr[lo++];
        while (true) {
            while (lo < endRank && arr[lo] < piv) lo++;
            while (hi > pivRank && piv < arr[hi]) hi--;
            if (lo>=hi) break;
            std::swap(arr[lo], arr[hi]); lo++; hi--;
        }
        std::swap(arr[pivRank], arr[hi]);
        if ( K == (endRank - hi + 1) ) {
            return arr[hi];
        } else if ( K < (endRank - hi + 1) ) {
            findKbiggestBase(arr, hi + 1, endRank, K);
        } else {
            findKbiggestBase(arr, pivRank, hi - 1, K - (endRank - hi + 1));
        }
    }
    ;
} 

template <typename T>
T findMedian(T* arr, int n) {
    // return (n % 2) ? ( findKbiggest(arr, n, n/2) + findKbiggest(arr, n, n/2 + 1) ) / 2 : findKbiggest(arr, n, n/2);
    return findKbiggest(arr, n, n/2);
}