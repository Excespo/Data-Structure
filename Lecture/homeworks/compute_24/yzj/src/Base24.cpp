#include "Base24.h"
#include <algorithm>
using namespace std;

int Base24::Read()
{
	cout << "Please enter the four numbers you want to compute 24: " << endl;
	cin >> num[0];
	cin >> num[1];
	cin >> num[2];
	cin >> num[3];

	return 1;
}


int Base24::Display()
{	
	bool flag = false;
	int idx[4] = {0, 1, 2, 3};
	sort(idx, idx+4);
	
	double res = 0, res1 = 0, res2 = 0;
	do
	{
		double num_new[4];
		for (int n = 0; n < 4; n++) num_new[n] = num[idx[n]];

		int op[3];
		char cout_op[4] = {'+', '-', '*', '/'};
		for (int i = 0; i < 4; i++){
			if (i == 0) res = Add(num_new[0], num_new[1]);
			if (i == 1) res = Sub(num_new[0], num_new[1]);
			if (i == 2) res = Mul(num_new[0], num_new[1]);
			if (i == 3) res = Div(num_new[0], num_new[1]);
			op[0] = i;
			for (int j = 0; j < 4; j++){
				if (j == 0) res1 = Add(res, num_new[2]);
				if (j == 1) res1 = Sub(res, num_new[2]);
				if (j == 2) res1 = Mul(res, num_new[2]);
				if (j == 3) res1 = Div(res, num_new[2]);
				op[1] = j;
				for (int k = 0; k < 4; k++){
					if (k == 0) res2 = Add(res1, num_new[3]);
					if (k == 1) res2 = Sub(res1, num_new[3]);
					if (k == 2) res2 = Mul(res1, num_new[3]);
					if (k == 3) res2 = Div(res1, num_new[3]);
					op[2] = k;

					if (res2 == 24){
						flag = true;
						cout << "(( " << num_new[0] << cout_op[op[0]] << num_new[1] << " )" << cout_op[op[1]] << num_new[2] << " )" << cout_op[op[2]] << num_new[3] << " = 24" << endl;
					}	
				}
			}
		}

		for (int i = 0; i < 4; i++){
			if (i == 0) res1 = Add(num_new[0], num_new[1]);
			if (i == 1) res1 = Sub(num_new[0], num_new[1]);
			if (i == 2) res1 = Mul(num_new[0], num_new[1]);
			if (i == 3) res1 = Div(num_new[0], num_new[1]);
			op[0] = i;

			for (int j = 0; j < 4; j++){
				if (j == 0) res2 = Add(num_new[2], num_new[3]);
				if (j == 1) res2 = Sub(num_new[2], num_new[3]);
				if (j == 2) res2 = Mul(num_new[2], num_new[3]);
				if (j == 3) res2 = Div(num_new[2], num_new[3]);
				op[1] = j;

				for (int k = 0; k < 4; k++){
					if (k == 0) res = Add(res1, res2);
					if (k == 1) res = Sub(res1, res2);
					if (k == 2) res = Mul(res1, res2);
					if (k == 3) res = Div(res1, res2);
					op[2] = k;

					if (res == 24){
						flag = true;
						cout << "( " << num_new[0] << cout_op[op[0]] << num_new[1] << " )" << cout_op[op[2]] << "( " << num_new[2] << cout_op[op[1]] << num_new[3] << " )" << " = 24" << endl;
					}		
				}
			}

		}
	}while (next_permutation(idx, idx+4));

	if (!flag) cout << "These four num_newbers can't compute 24" << endl;

	return 1;
}

/*************************
 *
 *
 *
 *
 *
 * 
 *************************/


