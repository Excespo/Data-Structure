#include <iostream>
#include "OperationSetA.h"
#include "OperationSetB.h"
using namespace std;

int main(int argn, char* argc[])
{
	BaseOperations* baseOp;
	cout << "ha" <<endl;
	if (argn<2 || argc[1][0] == '1'){
		cout << "Using OperationA." << endl;
		OperationSetA cp24A;
		cp24A.Read();
		cp24A.Display();
		/*********************/
	}
	else{
		cout << "Using OperationB." << endl;
		OperationSetB cp24B;
		cp24B.Read();
		cp24B.Display();
		/*********************/
	}
	/*
	 *
	 *
	 *
	 *
	 */
	
	return 0;
}

