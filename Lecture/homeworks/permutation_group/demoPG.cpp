#include <iostream>
#include "PermutationGroup.h"

bool eq(Permutation p, Permutation q, int n) {
	for (int i = 0; i < n; i++) {
		if (p.p[i]!=q.p[i]) return false;
	}
	return true;
}

int main(int argn, char* argc[])
{
	using std::cout;
	using std::endl;
	int n, dn;
	if (argn<2){ n = 4; dn = 3; }
	else if (argn<3){ n = std::stoi(argc[1]); dn = 3; }
	else{ n = std::stoi(argc[1]); dn = std::stoi(argc[2]); }

	PermutationGroup g(n);
	printf("Permutation group G[%d] : totally %d permutations\n", g.pN, g.gN);
	g.PrintPG();
	g.PrintDerivedPG(dn);

	int error = 0;
	for (int i = 0; i < g.gN; i++) {
		error += !(eq(g.gp[i], g.Inv(g.Inv(g.gp[i])), g.pN));
	}
	cout << "Test for Inv has " << error << " errors." << endl;

	for (int i = 0; i < g.pN; i++) {
		cout << g.gp[10].p[i];
	}
	cout << endl;

	for (int i = 0; i < g.pN; i++) {
		cout << g.gp[15].p[i];
	}
	cout << endl;

	
	for (int i = 0; i < g.pN; i++) {
		cout << g.Mul(g.gp[10], g.gp[15]).p[i];
	}
	cout << endl;

	
	Permutation p; p.n = 4; p.p[0] = 2; p.p[1] = 3; p.p[2] = 4; p.p[3] = 1;
	g.PrintPermutation(p);
	g.PrintPermutation(g.Mul(p,p));
	g.PrintPermutation(g.Inv(p));
	g.PrintPermutation(g.Mul(p,g.Inv(p)));
	


	return 0;
}
