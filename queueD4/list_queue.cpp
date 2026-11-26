// list_queue.cpp
#include "list_queue.h"
#include "array_queue.h"
#include <iostream>

int main()
{
    std::cout << "=== ListQueue（链表队列）===\n";

    ListQueue q;
    std::cout << "空队列: empty=" << (q.empty() ? "true" : "false")
              << "  size=" << q.size() << '\n';

    for (int i = 1; i <= 5; ++i)
        q.push(i);

    std::cout << "push 1..5: size=" << q.size() << "  front=" << q.front() << '\n';

    std::cout << "依次出队: ";
    while (!q.empty())
    {
        std::cout << q.front() << ' ';
        q.pop();
    }
    std::cout << "\n（应该是 1 2 3 4 5）\n";

    q.pop();        // 空队列 pop，不崩
    std::cout << "空队列再 pop: size=" << q.size() << "   （不崩）\n";

    // 和 ArrayQueue 对比
    std::cout << "\n--- 与 ArrayQueue 对比 ---\n";

    ArrayQueue aq;
    ListQueue  lq;
    for (int i = 1; i <= 3; ++i)
    {
        aq.push(i * 10);
        lq.push(i * 10);
    }
    std::cout << "ArrayQueue: ";
    while (!aq.empty()) { std::cout << aq.front() << ' '; aq.pop(); }
    std::cout << "\nListQueue : ";
    while (!lq.empty()) { std::cout << lq.front() << ' '; lq.pop(); }
    std::cout << "\n（两者应该一致）\n";

    return 0;
}