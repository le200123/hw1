#include <iostream>
#include <stack>

unsigned int AckermannNonRecursive(unsigned int m, unsigned int n) {
    std::stack<unsigned int> stack;
    stack.push(m);

    while (!stack.empty()) {
        m = stack.top();
        stack.pop();

        if (m == 0) {
            n = n + 1;
        }
        else if (m > 0 && n == 0) {
            stack.push(m - 1);
            n = 1;
        }
        else {
            stack.push(m - 1);
            stack.push(m);
            n = n - 1;
        }
    }

    return n;
}

int main() {
    unsigned int m = 2, n = 3;
    std::cout << "AckermannNonRecursive(" << m << ", " << n << ") = " << AckermannNonRecursive(m, n) << std::endl;
    return 0;
}