#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

using std::vector;
using std::cout;
using std::endl;

int const CARD = 4;
int const RANGE = 13;
char ops[4] = {'+', '-', '*', '/'};

typedef vector<double> DV1;
typedef vector<vector<double>> DV2;

DV2 permute(DV1 &);
void test_permute(DV1 &);
void test_permute(DV2 &);
void test_cal(DV1 &);
void rand_fill(DV1 &);
double cal(double, double, int);
double way1(double, double, double, double, int, int, int);
double way2(double, double, double, double, int, int, int);
double way3(double, double, double, double, int, int, int);
double way4(double, double, double, double, int, int, int);
double way5(double, double, double, double, int, int, int);
double try_way_n(DV1, int, int, int, int);
int cal24(DV1 &);
void cal_all(DV2 &);

int main() {
    /* Data Construction */
    DV1 nums;
    rand_fill(nums);
    DV2 perms = permute(nums);
    DV1 perm1 = perms[0];

    /* test */
    // test_permute(nums);
    // test_permute(perms);
    // test_cal(perm1);
    // int flag = cal24(perm1);
    // if (!flag) cout << "No ans" << endl;
    cal_all(perms);

    return 0;
}

DV2 permute(DV1 & nums)
{
      vector<vector<double>> result;
      sort(nums.begin(),nums.end());
      result.push_back(nums);
      while (next_permutation(nums.begin(), nums.end()))
      {
        result.push_back(nums);
      }
      return result;
}

void test_permute(DV1 & nums){
    int perm_nums = 1, n = nums.size();
    while (n) perm_nums *= n--;
    DV2 perms = permute(nums);
    for (int i = 0; i < perm_nums; i++) {
        cout << i + 1 << "-th perm" << endl;
        for (int j = 0; j < nums.size(); j++) {
            cout << perms[i][j] << ", ";
        }
        cout << endl;
    }
}

void test_permute(DV2 & perms) {
    for (int i = 0; i < perms.size(); i++) {
        cout << i + 1 << "-th perm" << endl;
        for (int j = 0; j < perms[0].size(); j++) {
            cout << perms[i][j] << ", ";
        }
        cout << endl;
    }
}

void test_cal(DV1 & perm) {
    srand((unsigned)time(0));
    int op1 = rand()%4, op2 = rand()%4, op3 = rand()%4;
    cout << op1 << " -> " << ops[op1] << ",";
    cout << op2 << " -> " << ops[op2] << ",";
    cout << op3 << " -> " << ops[op3] << endl;
    cout << perm[0] << ", " << perm[1] << ", " << perm[2] << ", " << perm[3] << endl;
    cout << "way1= " << try_way_n(perm, 1, op1, op2, op3) << endl;
    cout << "way2= " << try_way_n(perm, 2, op1, op2, op3) << endl;
    cout << "way3= " << try_way_n(perm, 3, op1, op2, op3) << endl;
    cout << "way4= " << try_way_n(perm, 4, op1, op2, op3) << endl;
    cout << "way5= " << try_way_n(perm, 5, op1, op2, op3) << endl;
}

void rand_fill(DV1 & nums) {
    unsigned seed = time(0); srand(seed);
    for (int i = 0; i < CARD; i++) {
        nums.push_back(rand()%RANGE + 1);
    }
}

double cal(double x, double y, int op_id) {
    switch (op_id)
    {
    case 0:
        return x + y;
    case 1:
        return x - y;
    case 2: 
        return x * y;
    case 3:
        return x / y;
    default:
        cout << "Wrong operation id, should be in {1, 2, 3, 4}." << endl;
        return 0.0;
    }
}

double way1(double n1, double n2, double n3, double n4, int op1, int op2, int op3) {
    return cal(cal(cal(n1, n2, op1), n3, op2), n4, op3);
}

double way2(double n1, double n2, double n3, double n4, int op1, int op2, int op3) {
    return cal(cal(n1, n2, op1), cal(n3, n4, op3), op2);
}

double way3(double n1, double n2, double n3, double n4, int op1, int op2, int op3) {
    return cal(n1, cal(n2, cal(n3, n4, op3), op2), op1);
}

double way4(double n1, double n2, double n3, double n4, int op1, int op2, int op3) {
    return cal(cal(n1, cal(n2, n3, op2), op1), n4, op3);
}

double way5(double n1, double n2, double n3, double n4, int op1, int op2, int op3) {
    return cal(n1, cal(cal(n2, n3, op2), n4, op3), op1);
}

// NO USE
double try_way_n(DV1 perm, int n, int op1, int op2, int op3){
    double n1 = perm[0], n2 = perm[1], n3 = perm[2], n4 = perm[3];
    switch (n)
    {
    case 1:
        return way1(n1, n2, n3, n4, op1, op2, op3);
    case 2:
        return way2(n1, n2, n3, n4, op1, op2, op3);
    case 3:
        return way3(n1, n2, n3, n4, op1, op2, op3);
    case 4:
        return way4(n1, n2, n3, n4, op1, op2, op3);
    case 5:
        return way5(n1, n2, n3, n4, op1, op2, op3);
    default:
        cout << "Error" << endl;
        return 0.0;
    }
}

int cal24(DV1 & perm) {
    int flag = 0;
    double n1 = perm[0], n2 = perm[1], n3 = perm[2], n4 = perm[3];
    for (int op1 = 0; op1 < 4; op1++) {
        for (int op2 = 0; op2 < 4; op2++) {
            for (int op3 = 0; op3 < 4; op3++) {
                if (way1(n1, n2, n3, n4, op1, op2, op3)==24) {
                    flag = 1;
                    printf("((%.0f %c %.0f) %c %.0f) %c %.0f = 24\n", n1, ops[op1], n2, ops[op2], n3, ops[op3], n4);
                }
                if (way2(n1, n2, n3, n4, op1, op2, op3)==24) {
                    flag = 1;
                    printf("((%.0f %c %.0f) %c (%.0f %c %.0f) = 24\n", n1, ops[op1], n2, ops[op2], n3, ops[op3], n4);
                }
                if (way3(n1, n2, n3, n4, op1, op2, op3)==24) {
                    flag = 1;
                    printf("%.0f %c (%.0f %c (%.0f %c %.0f)) = 24\n", n1, ops[op1], n2, ops[op2], n3, ops[op3], n4);
                }
                if (way4(n1, n2, n3, n4, op1, op2, op3)==24) {
                    flag = 1;
                    printf("(%.0f %c (%.0f %c %.0f)) %c %.0f = 24\n", n1, ops[op1], n2, ops[op2], n3, ops[op3], n4);
                }
                if (way5(n1, n2, n3, n4, op1, op2, op3)==24) {
                    flag = 1;
                    printf("%.0f %c ((%.0f %c %.0f) %c %.0f) = 24\n", n1, ops[op1], n2, ops[op2], n3, ops[op3], n4);
                }
            }
        }
    }
    return flag;
}

void cal_all(DV2 & perms) {
    int ans_nums = 0;
    for (int i = 0; i < perms.size(); i++) {
        ans_nums += cal24(perms[i]);
    }
    if (!ans_nums) {
        cout << "No ans for ";
        for (int j = 0; j < 4; j++) {
            cout << perms[0][j] << ", ";
        }
        cout << endl;
    }
}