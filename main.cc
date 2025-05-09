#include <iostream>


void test_cpp_stdlib();
void test_linux_syscalls();

int main() {
    std::cout << "Running C++ and Linux integration test..." << std::endl;
    test_cpp_stdlib();
    test_linux_syscalls();
    std::cout << "All tests completed successfully." << std::endl;
    return 0;
}

