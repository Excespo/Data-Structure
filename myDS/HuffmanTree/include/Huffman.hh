#include "Huffman.h"
#include "BinTree.h"
#include "HashTable.h"

/* consider only printable chars: 0x20~0x7E */
int const N_CHAR = (int)(0x80 - 0x20);

struct HuffChar {
    char ch; int weight;
    HuffChar(char c = '^', int w = 0) : ch(c), weight(w) {};
    bool operator<(HuffChar const & hc) const {return weight<hc.weight;}
    bool operator>(HuffChar const & hc) const {return weight>hc.weight;}
    bool operator==(HuffChar const & hc) const {return weight==hc.weight;}
};

using HuffForest = List<HuffTree*>;
using HuffCode = Bitmap;
using HuffTable = HashTable<char, char*>;

int * statistics(char*);

HuffForest* initForest(int *);

HuffTree* minHChar(HuffForest*);

HuffTree* generateTree(HuffForest*);

static void generateCT(HuffCode*, int, HuffTable*, BinNodePosi);

HuffTable* generateTable(HuffTree*);

int encode(HuffTable*, HuffCode*, char*);

void decode(HuffTree*, HuffCode*, int);
