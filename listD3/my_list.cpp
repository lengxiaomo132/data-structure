// my_list.cpp
#include "my_list.h"

int main()
{
    MyList list;
    list.print(); // 空链表

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.print(); // 1 -> 2 -> 3 -> null

    std::cout << "\n--- size / empty / front ---\n";
    MyList l2;
    std::cout << "空链表: size=" << l2.size()
              << "  empty=" << (l2.empty() ? "true" : "false") << '\n';

    l2.push_back(10);
    l2.push_back(20);
    l2.push_back(30);

    std::cout << "push 3 个后: size=" << l2.size()
              << "  empty=" << (l2.empty() ? "true" : "false") << '\n';
    std::cout << "front() = " << l2.front() << '\n';

    l2.front() = 999;
    std::cout << "front() = 999 之后: ";
    l2.print();

    const MyList &cl = l2; // 是引用不是复制，不受拷贝函数限制，cl是l2的别名
    std::cout << "const 引用调 front() = " << cl.front() << '\n';

    std::cout << "\n--- push_front / pop_front ---\n";
    MyList l3;
    l3.push_back(2);
    std::cout << "初始: ";
    l3.print();

    l3.push_front(1);
    std::cout << "push_front(1) 后: ";
    l3.print();

    l3.push_front(0);
    std::cout << "push_front(0) 后: ";
    l3.print();
    std::cout << "size = " << l3.size() << '\n';

    l3.pop_front();
    std::cout << "pop_front() 后: ";
    l3.print();
    std::cout << "size = " << l3.size() << '\n';

    l3.pop_front();
    l3.pop_front();
    std::cout << "再 pop 两次后: ";
    l3.print();
    std::cout << "size = " << l3.size() << "  empty="
              << (l3.empty() ? "true" : "false") << '\n';

    l3.pop_front(); // 空时 pop，不崩
    std::cout << "空时 pop_front() 后: size = " << l3.size() << "   （不崩）\n";

        std::cout << "\n--- find ---\n";
    MyList l4;
    l4.push_back(10);
    l4.push_back(20);
    l4.push_back(30);

    int *p = l4.find(20);
    std::cout << "find(20) = " << (p != nullptr ? std::to_string(*p) : "没找到") << '\n';
    std::cout << "find(99) = " << (l4.find(99) != nullptr ? "找到" : "没找到") << '\n';

    if (p != nullptr)
        *p = 999;
    std::cout << "改 *p 之后: ";
    l4.print();

    std::cout << "\n--- remove ---\n";
    MyList l5;
    l5.push_back(1);
    l5.push_back(2);
    l5.push_back(2);
    l5.push_back(2);
    l5.push_back(3);
    std::cout << "初始: ";
    l5.print();
    std::cout << "size = " << l5.size() << '\n';

    l5.remove(2);
    std::cout << "remove(2) 后: ";
    l5.print();
    std::cout << "size = " << l5.size() << "   （连删三个）\n";

    std::cout << "\n--- 删头节点 ---\n";
    MyList l6;
    l6.push_back(5);
    l6.push_back(5);
    l6.push_back(1);
    std::cout << "初始: ";
    l6.print();
    l6.remove(5);
    std::cout << "remove(5) 后: ";
    l6.print();

    std::cout << "\n--- 删不存在的 ---\n";
    MyList l7;
    l7.push_back(1);
    l7.push_back(2);
    l7.remove(99);
    std::cout << "remove(99) 后: ";
    l7.print();

    test_tail();
    return 0;
}