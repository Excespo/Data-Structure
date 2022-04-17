#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool lt(int x, int y) {return x<y;}
bool gt(int x, int y) {return x>y;}

void disp(vector<int> ivec){
    if (ivec.empty()) cout<<"Empty vector.\n";
    else{
        cout<<"vector contains: ";
        for (auto ele: ivec)
            cout<<ele<<" ";
        cout<<endl;
    }
}

/* prefix sorted to simplify push-back-new-element-and-sort case */
void insertSort(vector<int> & ivec, bool(*cmp)(int x, int y)) {
    for (int i = 1; i < ivec.size(); ++i) {
        int sentinel = ivec[i];
        int j = i - 1;
        while ((cmp(sentinel, ivec[j])) && (j>=0)) {
            ivec[j+1] = ivec[j];
            j--;
        }
        ivec[j+1] = sentinel;
    }
}

int main(){
    vector<int> ivec;
    disp(ivec);
    ivec.push_back(1);
    disp(ivec);
    ivec.insert(ivec.end()-1, 2);
    ivec.insert(ivec.end(), 3);
    ivec.insert(ivec.end()-1, 2);
    ivec.insert(ivec.end(), 3);
    ivec.insert(ivec.end()-1, 2);
    ivec.insert(ivec.end(), 3);
    insertSort(ivec, lt);
    disp(ivec);
    insertSort(ivec, gt);
    disp(ivec);
}