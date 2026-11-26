#include "my_dlist.h"

void test_prev()
{
    std::cout << "\n=== prev 链完整性 ===\n";
    MyDList a;
    for (int i = 1; i <= 5; ++i)
        a.push_back(i);
    a.print();
    a.print_reverse();        // 必须是 null <- 5 <- 4 <- 3 <- 2 <- 1

    a.pop_front();
    a.print();
    a.print_reverse();        // null <- 5 <- 4 <- 3 <- 2

    a.pop_back();
    a.print();
    a.print_reverse();        // null <- 4 <- 3 <- 2

    a.remove(3);
    a.print();
    a.print_reverse();        // null <- 4 <- 2
}

void test_remove_tail()
{
    std::cout << "\n=== 删尾巴（tail_ = cur 分支）===\n";

    MyDList a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.remove(3);          // 删的是尾巴
    std::cout << "remove(3) 后: ";
    a.print();
    a.print_reverse();    // null <- 2 <- 1

    a.push_back(4);       // 关键：如果 tail_ 没更新到这里就崩
    std::cout << "push_back(4) 后: ";
    a.print();
    a.print_reverse();

    std::cout << "\n=== 删到空（tail_ = nullptr 分支）===\n";
    MyDList b;
    b.push_back(9);
    b.push_back(9);
    b.remove(9);
    std::cout << "删空后 size=" << b.size()
              << "  empty=" << (b.empty() ? "true" : "false") << '\n';
    b.push_back(7);       // 空之后能正常 push
    b.print();
    b.print_reverse();
}

int main()
{
    MyDList list;

    list.push_back(2);
    list.push_back(3);
    std::cout << "push_back 2,3:\n  ";
    list.print();
    std::cout << "  ";
    list.print_reverse();

    list.push_front(1);
    std::cout << "\npush_front 1:\n  ";
    list.print();
    std::cout << "  ";
    list.print_reverse();

    list.push_back(4);
    std::cout << "\npush_back 4:\n  ";
    list.print();
    std::cout << "  ";
    list.print_reverse();

    std::cout << "\nsize = " << list.size() << '\n';
    
    test_prev();
    test_remove_tail();
    
    return 0;
}