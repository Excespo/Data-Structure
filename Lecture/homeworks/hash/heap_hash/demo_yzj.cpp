#include <iostream>
#include <string>
#include "method_yzj.h"
// #include "MaxHeap.h"
// #include "Compare.h"
using namespace std;


int main(int argn, char* argc[])
{
	string buf;

	string table_word[1632] = {"\0"};
    int table_hash[1632] = {0};


    int value_arr[1632] = {0};
    string word_arr[1632] = {"\0"};

    int count = 1;
    int length;
	while (getline(cin, buf)){

        int aLine[100] = {0};
		int nCHN = buf.length()/3, a[3], k, i;
		for (k=0; k<nCHN; k++){ 
			for(i=0; i<3; i++) a[i] = static_cast<unsigned char>(buf[3*k+i]); 
			aLine[k] = a[0]*65536 + a[1]*256 + a[2];
		}
        
        int value = hash_yzj(aLine);
        add_table(table_word, table_hash, buf, value);
        
        length = 0;
        for (int i = 0; i < 1631; i++){
            if (table_hash[i]) length++;
        }

        int idx = 0;
        for (int i = 1630; i > 0; i--){
            if (table_hash[i]){
                value_arr[idx] = i;
                word_arr[idx] = table_word[i];
                idx++;
            }
        }
        
        int temp_value[length+1] = {0};
        string temp_word[length+1] = {"\0"};

        int temp_len = length>32?32:length;
        for (int i = 0; i < temp_len; i++){
            temp_value[i] = value_arr[i];
            temp_word[i] = word_arr[i];
        }


        if ((!(count % 300))){
            cout << "Heap Tree at Line " << count << ": " << endl;

            MaxHeap<int, IntCompare> heap_value(temp_value, temp_len, temp_len);

            print_heap(heap_value, table_word, temp_len);

        }

        count += 1;
        
	}
    
    int final_heap_value[length+1] = {0};
    string final_heap_word[length+1] = {"\0"};

    for (int i = 0; i < length; i++){
        final_heap_value[i] = value_arr[i];
        final_heap_word[i] = word_arr[i];
    }

    cout << "Heap Tree at Line " << count << ": " << endl;

    MaxHeap<int, IntCompare> heap_value(final_heap_value, length, length);

    print_heap(heap_value, table_word, 32);


    cout << "Final heap for words: " << endl;
    for (int i = 0; i < length; i++){
        cout << final_heap_word[i] << endl;
    }

    out_dat(final_heap_word, length);

	return 0;
}

