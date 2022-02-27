/*************************************************
 * A naive implementation of the permutation group
*************************************************/

#ifndef __PERMUTATION_GROUP__
#define __PERMUTATION_GROUP__

#define pNMax 10
#define gNMax 1000

typedef struct Permutation{
	int p[pNMax];
	int n;  // order of the permutation i.e. the number of elements to-be-permuted
}Permutation;

class PermutationGroup{
public:
	int pN, gN;
	Permutation gp[gNMax];
	PermutationGroup(int n);
	Permutation Inv(Permutation p);
	Permutation Mul(Permutation p, Permutation q);
	void PrintPermutation(Permutation p);
	void PrintPG(); // Print the permutation group
	void PrintDerivedPG(int dn);  // Print the dn-th derived permutation group
};

#endif
