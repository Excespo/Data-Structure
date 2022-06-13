#include "minHeap.h"

#include <string>

int main() {
    using std::cout;
    cout << "Test For minHeap begins\n";

    std::vector<std::string> keys = {"1", "40", "23", "19", "7", "22", "19", "32", "87"};
    std::vector<int> vals = {1, 40, 23, 19, 7, 22, 19, 32, 87};
    minHeap<std::string, int> h = {keys, vals};

    h.print_all();
    h.delMin();
    cout << "\ndelMin\n";
    h.print_all();
    h.sort();
    cout << "\nsort\n";
    h.print_all();
    h.push_back(std::move("50"), std::move(50));
    h.push_back(std::move("20"), std::move(20));
    h.push_back(std::move("30"), std::move(30));
    h.push_back("42", 42);
    cout << "\npush_back\n";
    h.print_all();
    h.sort();
    cout << "\nsort\n";
    h.print_all();
    h.set_val_with("20", -2);
    h.set_val_with("19", 119);
    h.print_all();
    cout << h.get_val_at("20") << "\n";
    h.get_val_at("-1");

    return 0;
}
