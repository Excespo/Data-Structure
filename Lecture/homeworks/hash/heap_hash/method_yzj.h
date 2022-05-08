#include <iostream>
#include <string>
#include <fstream>
#include "MaxHeap.h"
#include "Compare.h"
using namespace std;

int hash_yzj(int* arr){
    int sum = 0;
    
    for (int i = 0; arr[i]; i++){
        sum += arr[i] % 1631;
    }

    return sum%1631;
}

int probe(string word, int value){
    return (word.length()*value) % 1631;
}

void add_table(string* table_word, int* table_hash, string words, int value){

    int tmp;
    if (!(table_hash[value])){
        table_hash[value] = value;
        table_word[value] = words;

    }
    else{
        tmp = value;
		while (table_hash[tmp] && table_word[tmp] != words){
			tmp = probe(words, tmp);
			if (!(table_hash[tmp])){
				table_word[tmp] = words;
				table_hash[tmp] = value;
			}
		}

	}
}

void print_heap(MaxHeap<int, IntCompare> heap_value, string* table_word, int num){
    for (int i = 0; i < num; i++){
        int hash = heap_value.heap[i];
        cout << hash << ": " << table_word[hash] << endl; 
    }

    cout << endl;
}

void out_dat(string* final_heap_word, int length){
    ofstream file("HeapAll", ofstream::app);

    if (file.is_open()){
        for (int i = 0; i < length; i++){
            file << "Index " << i << ": " << final_heap_word[i] << endl;
        }

        file.close();
    }
}
