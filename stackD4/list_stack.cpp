// list_stack.cpp
#include "list_stack.h"
#include "array_stack.h"
#include <iostream>

int main()
{
    std::cout << "=== ListStack（链表栈）===\n";

    ListStack s;
    std::cout << "空栈: empty=" << (s.empty() ? "true" : "false")
              << "  size=" << s.size() << '\n';

    for (int i = 1; i <= 5; ++i)
        s.push(i);

    std::cout << "push 1..5: size=" << s.size() << "  top=" << s.top() << '\n';

    std::cout << "依次弹出: ";
    while (!s.empty())
    {
        std::cout << s.top() << ' ';
        s.pop();
    }
    std::cout << "\n（应该是 5 4 3 2 1）\n";

    s.pop();        // 空栈 pop，不崩
    std::cout << "空栈再 pop: size=" << s.size() << "   （不崩）\n";

    // 和 ArrayStack 对比：同样输入，同样输出
    std::cout << "\n--- 与 ArrayStack 对比 ---\n";

    ArrayStack as;
    ListStack ls;
    for (int i = 1; i <= 3; ++i)
    {
        as.push(i * 10);
        ls.push(i * 10);
    }
    std::cout << "ArrayStack: ";
    while (!as.empty()) { std::cout << as.top() << ' '; as.pop(); }
    std::cout << "\nListStack : ";
    while (!ls.empty()) { std::cout << ls.top() << ' '; ls.pop(); }
    std::cout << "\n（两者应该一致）\n";

    return 0;
}