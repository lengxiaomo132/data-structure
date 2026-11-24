// practiceD2.cpp
#include "my_vector.h"
#include <iostream>

int main()
{
    MyVector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::cout << "size = " << v.size() << '\n';
    std::cout << "capacity = " << v.capacity() << '\n';

    std::cout << "\n--- 读元素 ---\n";
    std::cout << "v[0] = " << v[0] << '\n';
    std::cout << "v[1] = " << v[1] << '\n';
    std::cout << "v[2] = " << v[2] << '\n';

    std::cout << "\n--- 改元素 ---\n";
    v[0] = 99;
    std::cout << "v[0] = 99 之后，v[0] = " << v[0] << '\n';

    std::cout << "\n--- const 对象读 ---\n";
    const MyVector<int> &cv = v;
    std::cout << "cv[0] = " << cv[0] << '\n';

    std::cout << "\n--- 深拷贝测试 ---\n";
    MyVector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    MyVector<int> b = a; // 拷贝构造

    std::cout << "拷贝后  a[0]=" << a[0] << "  b[0]=" << b[0] << '\n';

    b[0] = 999; // 改副本

    std::cout << "改 b[0] 后  a[0]=" << a[0] << "  b[0]=" << b[0] << '\n';
    std::cout << "（a[0] 应该还是 1，没被影响）\n";

    std::cout << "\n--- 拷贝赋值 ---\n";
    MyVector<int> c;
    c.push_back(77);
    std::cout << "赋值前   c.size=" << c.size() << "  c[0]=" << c[0] << '\n';
    c = a;
    std::cout << "赋值后   c.size=" << c.size() << "  c[0]=" << c[0] << '\n';

    std::cout << "\n--- 自赋值 ---\n";
    a = a;
    std::cout << "a = a 后   a.size=" << a.size() << "  a[0]=" << a[0] << '\n';

    // ===== empty / pop_back / clear =====
    std::cout << "\n--- empty / pop_back / clear ---\n";
    MyVector<int> m;
    std::cout << "空时 empty() = " << (m.empty() ? "true" : "false") << '\n';

    m.push_back(1);
    m.push_back(2);
    m.push_back(3);
    std::cout << "push 3 个后 empty() = " << (m.empty() ? "true" : "false")
              << "  size=" << m.size() << '\n';

    m.pop_back();
    std::cout << "pop 后 size=" << m.size() << "  m[1]=" << m[1] << '\n';

    m.clear();
    std::cout << "clear 后 size=" << m.size() << "  capacity=" << m.capacity()
              << "   （size=0，capacity 不变）\n";

    // 空时 pop_back 不崩
    m.pop_back();
    std::cout << "空时 pop_back 后 size=" << m.size() << "   （不崩）\n";

    // ===== reserme =====
    std::cout << "\n--- reserme ---\n";
    MyVector<int> r;
    r.reserve(10);
    std::cout << "reserve(10) 后  size=" << r.size()
              << "  capacity=" << r.capacity() << '\n';

    r.push_back(1);
    std::cout << "push 1 个后  size=" << r.size()
              << "  capacity=" << r.capacity() << "   （容量没变）\n";

    r.reserve(5);
    std::cout << "reserve(5) 后  capacity=" << r.capacity()
              << "   （比现在小，不缩容）\n";
    return 0;
}