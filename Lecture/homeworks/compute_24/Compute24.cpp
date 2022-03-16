#include <iostream>
#include <vector>
#include <algorithm>
#include "OperationSetA.h"
#include "OperationSetB.h"
using namespace std;

int main(int argn, char* argc[])
{
	BaseOperations* baseOp;
	if (argn<2 || argc[1][0] == '1'){
		OperationSetA cp24A;
		cp24A.Read();
		cp24A.Display();
		/*********************/
	}
	else{
		OperationSetB cp24B;
		/*********************/
	}
	
// 	/*
// 	 * 4 numbers are combined linearly or by two groups
// 	 */
// 	double numin[4];
// 	vector<double> vecin;
// 	for (int i = 0; i < 4; i++) vecin.push_back(numin[i]);

	
// 	vector< vector<double> > permutations = permute(vecin);
// 	for (int i = 0; i < 4*3*2*1; i++) {
//         cout << i << "-th permutation" << endl;
// 		vector<double> perm = permutations[i];
// 		cout << perm[0] << ", " << perm[1] << ", " << perm[2] << ", " << perm[3] << endl;
//     }
	
	
// 	return ;
}

// vector<vector<double>> permute(vector<double>& nums)
// {
//       vector<vector<double>> result;
//       sort(nums.begin(),nums.end());
//       result.push_back(nums);
//       while (next_permutation(nums.begin(), nums.end()))
//       {
//         result.push_back(nums);
//       }
//       return result;
// }