#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#define rdm(x) ((rand()) % (x) + 1)

// int const MAX_N = 1e2;
// int const MAX_M = 1e2;
// int const MAX_C = 1e2;
// int const MAX_A = 1e4;
int const MAX_N = 2e1;
int const MAX_M = 8;
int const MAX_C = 8;
int const MAX_A = 2e1;

int main() {
    srand(time(0));
    int n = rdm(MAX_N);
    int m = rdm(MAX_M);
    int c = rdm(MAX_C);

    std::ofstream f_out("in.txt");
    f_out << n << " "
          << m << " "
          << c << " "
          << std::endl;
    for (int i = 0; i < n; ++i)
        (i == n-1) ? f_out << rdm(MAX_A) << std::endl : f_out << rdm(MAX_A) << " ";

    f_out.close();

    return 0;
}