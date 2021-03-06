#include "Base24.h"
#include <algorithm>
using namespace std;

int Base24::Read()
{
	cout << "Input the four integers with which you want to compute 24." << endl;
	for (int i = 0; i < 4; i++) cin >> num[i];
	cout << "Numbers read." << endl;

	return 0;
}


int Base24::Display()
{
	bool find = false;
	int id[4] = {0, 1, 2, 3};
	sort(id, id+4);
	
	double res = 0, res1 = 0, res2 = 0;
	do
	{
		double num_new[4];
		for (int n = 0; n < 4; n++) num_new[n] = num[id[n]];

		int operators[3];
		char cout_operators[4] = {'+', '-', '*', '/'};
		for (int i = 0; i < 4; i++){
			if (i == 0) res = Add(num_new[0], num_new[1]);
			if (i == 1) res = Sub(num_new[0], num_new[1]);
			if (i == 2) res = Mul(num_new[0], num_new[1]);
			if (i == 3) res = Div(num_new[0], num_new[1]);
			operators[0] = i;
			for (int j = 0; j < 4; j++){
				if (j == 0) res1 = Add(res, num_new[2]);
				if (j == 1) res1 = Sub(res, num_new[2]);
				if (j == 2) res1 = Mul(res, num_new[2]);
				if (j == 3) res1 = Div(res, num_new[2]);
				operators[1] = j;
				for (int k = 0; k < 4; k++){
					if (k == 0) res2 = Add(res1, num_new[3]);
					if (k == 1) res2 = Sub(res1, num_new[3]);
					if (k == 2) res2 = Mul(res1, num_new[3]);
					if (k == 3) res2 = Div(res1, num_new[3]);
					operators[2] = k;

					if (res2 == 24){
						find = true;
						cout << "(( " << num_new[0] << cout_operators[operators[0]] << num_new[1] << " )" << cout_operators[operators[1]] << num_new[2] << " )" << cout_operators[operators[2]] << num_new[3] << " = 24" << endl;
					}	
				}
			}
		}

		for (int i = 0; i < 4; i++){
			if (i == 0) res1 = Add(num_new[0], num_new[1]);
			if (i == 1) res1 = Sub(num_new[0], num_new[1]);
			if (i == 2) res1 = Mul(num_new[0], num_new[1]);
			if (i == 3) res1 = Div(num_new[0], num_new[1]);
			operators[0] = i;

			for (int j = 0; j < 4; j++){
				if (j == 0) res2 = Add(num_new[2], num_new[3]);
				if (j == 1) res2 = Sub(num_new[2], num_new[3]);
				if (j == 2) res2 = Mul(num_new[2], num_new[3]);
				if (j == 3) res2 = Div(num_new[2], num_new[3]);
				operators[1] = j;

				for (int k = 0; k < 4; k++){
					if (k == 0) res = Add(res1, res2);
					if (k == 1) res = Sub(res1, res2);
					if (k == 2) res = Mul(res1, res2);
					if (k == 3) res = Div(res1, res2);
					operators[2] = k;

					if (res == 24){
						find = true;
						cout << "( " << num_new[0] << cout_operators[operators[0]] << num_new[1] << " )" << cout_operators[operators[2]] << "( " << num_new[2] << cout_operators[operators[1]] << num_new[3] << " )" << " = 24" << endl;
					}		
				}
			}

		}
	}while (next_permutation(id, id+4));

	if (!find) cout << "No answers for these four newbers" << endl;

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


