/*************************************************
 * A naive implementation of the permutation group
*************************************************/

#include <iostream>
#include "PermutationGroup.h"
using namespace std;

PermutationGroup::PermutationGroup(int n)
{
	pN = n;
	gN = 1;
	int k=0, aMax=1, a[pNMax], aflg[pNMax]; 
	for(int k1=0; k1<n; k1++) aMax *= n;
	for(int akIter=1; akIter<aMax; akIter++){
		int ak = akIter, k1, probflg = 0;
		for(k1=0; k1<n; k1++) aflg[k1] = 0;
		k1 = n;
		while (k1--){
			a[k1] = ak%n;
			ak = (ak-a[k1])/n;
			a[k1]++;
			if (aflg[a[k1]-1]){ probflg = 1; break; }
			else { aflg[a[k1]-1] = 1; }
		}
		if (probflg) continue;
		for (k1=0; k1<n; k1++) gp[k].p[k1] = a[k1];
		gp[k].n = n;
		k++;
	}
	gN = k; // In fact, gN = pN!
	// while (n) gN *= n--; // gN = pN!
}

Permutation PermutationGroup::Inv(Permutation p)
{
	Permutation pinv = p;
	/**************************************/
	// COMPUTE pinv from p

	int idx[pNMax], i;
	for (i = 0; i < p.n; i++) idx[i] = pinv.p[i];
	for (i = 0; i < p.n; i++) pinv.p[idx[i]-1] = i+1;
	/**************************************/
	return pinv;
}

// Multiplication of two permutation groups p*q
Permutation PermutationGroup::Mul(Permutation p, Permutation q)
{
	Permutation r = p;
	/**************************************/
	// COMPUTE r from p and q
	
	for (int i = 0; i < r.n; i++) r.p[p.p[i]-1] = i+1;
	Permutation tmp = r;
	for (int i = 0; i < r.n; i++) r.p[q.p[i]-1] = tmp.p[i];
	r = this->Inv(r);

	/**************************************/
	return r;
}

void PermutationGroup::PrintPermutation(Permutation p)
{
	printf("[ ");
	for(int k2=0; k2<p.n; k2++) printf("%d ", k2+1);
	printf("| ");
	for(int k2=0; k2<p.n; k2++) printf("%d ", p.p[k2]);
	printf("]\n");
}

// Print the permutation group
void PermutationGroup::PrintPG()
{
	for (int k=0; k<gN; k++){
		printf("[ ");
		for(int k2=0; k2<pN; k2++) printf("%d ", k2+1);
		printf("| ");
		for(int k2=0; k2<pN; k2++) printf("%d ", gp[k].p[k2]);
		printf("]\n");
	}
}

int Permutation2Value(Permutation p)
{
	int sum = 0;
	for (int k1=0; k1<p.n; k1++) sum = sum*p.n + p.p[k1]-1;
	return sum;
}
// Compute and print the dn-th derived permutation group
void PermutationGroup::PrintDerivedPG(int dn)
{
	int PVal[gNMax*gNMax], dpN;
	Permutation dp[gNMax], dporg[gNMax];
	for (dpN=0; dpN<gN; dpN++) dporg[dpN] = gp[dpN];
	for (int k=0; k<dn; k++){
		for (int k1=0; k1<gNMax*gNMax; k1++) PVal[k1] = 1;
		int ck = 0, valtmp;
		Permutation ptmp;
		printf("%d-th derived permutation group of G[%d] :\n", k+1, pN);
		for (int k1=0; k1<dpN; k1++){
			for (int k2=0; k2<dpN; k2++){
				ptmp = Mul(Inv(dporg[k1]), Inv(dporg[k2]));
				ptmp = Mul(dporg[k1], Mul(dporg[k2], ptmp));
				valtmp = Permutation2Value(ptmp);
				if (PVal[valtmp]){
					PVal[valtmp] = 0;
					dp[ck++] = ptmp;
					PrintPermutation(ptmp);
				}
			}
		}
		dpN = ck;
		for (int k1=0; k1<dpN; k1++) dporg[k1] = dp[k1];
	}
}


