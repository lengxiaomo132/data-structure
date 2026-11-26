#include "array_queue.h"
#include <iostream>

int main()
{
    ArrayQueue q;
    std::cout << "空队列: empty=" << (q.empty() ? "true" : "false") << '\n';

    q.push(1);
    q.push(2);
    q.push(3);
    std::cout << "push 1,2,3: size=" << q.size() << "  front=" << q.front() << '\n';

    q.pop();
    std::cout << "pop 后: size=" << q.size() << "  front=" << q.front() << '\n';

    // 关键测试：制造绕圈
    q.push(4);
    q.push(5);
    std::cout << "push 4,5: size=" << q.size() << "  front=" << q.front() << '\n';

    while (!q.empty())
    {
        std::cout << q.front() << ' ';
        q.pop();
    }
    std::cout << "\n（应该是 2 3 4 5）\n";

    return 0;
}