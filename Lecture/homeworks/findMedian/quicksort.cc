#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <memory>

void insertionSort(int * arr, int n, bool(*cmp)(int x, int y));

void quickSort(int * arr, int n, bool(*cmp)(int x, int y));
void quickSortBase(int * arr, int lo, int hi, bool(*cmp)(int x, int y));
std::vector<int> arr2vec(int * arr, int n);

void oneTest(int * arr, int n, void(*srt)(int* arr, int n, bool(*cmp)(int x, int y)));
void tests(int N);

bool lt(int x, int y) {return x<y;}
bool gt(int x, int y) {return x>y;}
bool nlt(int x, int y) {return x>=y;}
bool ngt(int x, int y) {return x<=y;}

int main() {
    tests(1);
    return 0;
}

void insertionSort(int * arr, int n, bool(*cmp)(int x, int y)) {
    for (int i = 0; i < n; ++i) {
        int sentinel = arr[i], j = i - 1;
        while ((j>=0) && cmp(sentinel, arr[j])) {
            arr[j+1] = arr[j]; j--;
        }
        arr[j+1] = sentinel;
    }
}

void quickSort(int * arr, int n, bool(*cmp)(int x, int y)) {
    quickSortBase(arr, 0, n-1, cmp);
}

void quickSortBase(int * arr, int lo, int hi, bool(*cmp)(int x, int y)) {
    if (lo < hi) {
        int pivID = lo, endID = hi;
        int piv = arr[lo++];
        while (true) {
            while (lo<endID && cmp(arr[lo], piv)) lo++;
            while (hi>pivID && cmp(piv, arr[hi])) hi--;
            if (lo>=hi) break;
            std::swap(arr[lo], arr[hi]); lo++; hi--;
        }
        std::swap(arr[pivID], arr[hi]);
        quickSortBase(arr, pivID, hi - 1, cmp);
        quickSortBase(arr, hi + 1, endID, cmp);
    }
}

std::vector<int> arr2vec(int * arr, int n) {
    std::vector<int> ivec;
    for (int i = 0; i < n; ++i) 
        ivec.push_back(arr[i]);
    return ivec;
}

void oneTest(int * arr, int n, void(*srt)(int* arr, int n, bool(*cmp)(int x, int y))) {
    std::vector<int> ivec = arr2vec(arr, n);
    std::sort(ivec.begin(), ivec.end(), lt);
    std::cout << "std::sort give:\n";
    for (const auto & elem: ivec)
        std::cout << elem << " ";
    std::cout << "\n";

    srt(arr, n, lt);
    std::cout << "my sort give:\n";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

void tests(int N) {
    while (N--) {
        srand(time(NULL));
        int n = 10 + rand() % 10;
        // std::unique_ptr<int[]> arr = std::make_unique<int[]>(n);
        int * arr = new int[n];
        for (int i = 0; i < n; ++i)
            arr[i] = rand() % (5*n);
        oneTest(arr, n, quickSort);
    }
}