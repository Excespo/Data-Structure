#include "Student.hpp"

int main (int argc, char* argv[]) {

    int size;
    std::cout << "Input size" << std::endl;
    std::cin >> size;

    auto students = new sjtu::Student[size];
    sjtu::Student stu("Amb");
    std::cout << stu << std::endl;


	for (int i = 0; i < size; i++) {
        // sjtu::Student stu;
        stu = students[i];
		stu.setName("stu" + std::to_string(i));
		stu.setAge(50+i);

		std::cout << stu << std::endl << std::endl;
	}
	delete[] students;
    return 0;
}