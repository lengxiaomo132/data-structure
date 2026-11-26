#include "array_stack.h"
#include <iostream>

int main()
{
    ArrayStack s;
    std::cout << "空栈: empty=" << (s.empty() ? "true" : "false")
              << "  size=" << s.size() << '\n';

    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << "push 1,2,3 后: size=" << s.size()
              << "  top=" << s.top() << '\n';

    s.pop();
    std::cout << "pop 后: size=" << s.size() << "  top=" << s.top() << '\n';

    s.top() = 99;
    std::cout << "改 top=99 后: top=" << s.top() << '\n';

    s.pop();
    s.pop();
    std::cout << "全 pop 后: empty=" << (s.empty() ? "true" : "false")
              << "  size=" << s.size() << '\n';

    s.pop();        // 空栈 pop，不崩
    std::cout << "空栈再 pop: size=" << s.size() << "   （不崩）\n";

    return 0;
}