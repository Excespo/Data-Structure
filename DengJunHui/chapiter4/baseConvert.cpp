#include <bits/stdc++.h>

using std::stack;

void convert1 (stack<char> & S, __int64_t n, int base) {
    static char digit[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    if (0 < n) {
        S.push( digit[n%base] );
        convert1( S, n / base, base);
    }
}

void convert2 (stack<char> & S, __int64_t n, int base) {
    static char digit[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while ( n > 0 ) {
        int remainder = (int) (n % base); S.push(digit[remainder]);
        n /= base;
    }
}

void print_base_n(stack<char> & S, __int64_t n, int base) {
    std::cout << "Under base " << base << " , decimal repr " << n << " is : ";
    while (!S.empty()) {std::cout << S.top(); S.pop();}
    std::cout << std::endl;
}

int main(){
    stack<char> S1, S2;
    convert1(S1, 251652, 16);
    print_base_n(S1, 15, 2);
    convert2(S2, 251652, 16);
    print_base_n(S2, 15, 2);

    return 0;
}