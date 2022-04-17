#include<iostream>
#include<math.h>
#include <fstream>

using namespace std;


double one_process(int m, double c, double *heads){
    double min = 0;
    for (int i = 0; i<m; i++){
        if (min==0){
            min = heads[i];
        }else if(min!=0&&heads[i]!=0&&heads[i]<min){
            min = heads[i];
        }
    }
    for (int i = 0; i<m; i++){
        if (heads[i]){
            heads[i] -= min;
        }
    }
    // cout << "cost:" << min / c << endl;
    return min / c;
}

void order(int n, int *array)
{
    int temp;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-1; j++){
            if (array[j]<array[j+1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void to_entier(int *file_bits, int speed){
    int rest = 0;
    for (int i = 0; file_bits[i]; i++){
        rest = file_bits[i] % speed;
        if (rest){
            file_bits[i] += speed - rest;
        }
    }
}

bool end_task(int m, double *heads)
{
    for (int i = 0; i<m; i++){
        if (heads[i]!=0){
            return false;
        }
    }
    return true;
}

double time_cost(int m, double c, double *heads, int *file_bits)
{
    double time = 0;
    int turn = 0;
    while(1){
        for (int i = 0; i<m; i++){
            if ((!heads[i])&&(file_bits[turn])){
                heads[i] = file_bits[turn];
                turn += 1;
            }
        }
        // for (int i = 0; i < m;i++)
        // {
        //     cout << heads[i] << ' ';
        // }
        // cout << endl;
        if (end_task(m,heads))
        {
            break;
        }
        time += one_process(m, c, heads);
        // cout << "time:" << time << endl;
    }
    return time;
}

int main()
{
    int file_bits[100] = {0};
    double heads[100] = {0};
    double time;
    int n, m, c;
    cin >> n;
    cin >> m;
    cin >> c;
    for (int i = 0; i < n;i++){
        cin >> file_bits[i];
    }
    to_entier(file_bits, c);
    order(n, file_bits);
    // for (int i = 0; i < n;i++){
    //     cout << file_bits[i] <<' ';
    // }
    // cout << endl;
    time = time_cost(m, c, heads, file_bits);
    // cout << ceil(time);

    // test output
    std::ofstream f_out("out_ref.txt");
    f_out << ceil(time) << endl;
    f_out.close();
}