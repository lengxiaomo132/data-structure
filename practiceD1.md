# D1 练习：复杂度

> 本课考「判断」，不考「实现」。答案写在各题下方的空白处。

---

## 第一题：给循环定复杂度

写出每段的大 O，并说明怎么算的。

```cpp
// a
for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
        sum += i * j;

// b
for (int i = 0; i < n; ++i)
    for (int j = 0; j < 10; ++j)
        sum += i * j;

// c
for (int i = 1; i < n; i *= 3)
    sum += i;

// d
int i = 0, j = n;
while (i < j) { ++i; --j; }

// e
for (int i = 0; i < n; ++i)
    for (int j = i; j < n; ++j)
        sum++;
```

**a.**

```
O(n^2)=n*n
```

**b.**

```
n*10=O(n)
```

**c.**

```
3^k=n;k=log3(n);O(log(n))
```

**d.**

```
O(n)
```

**e.**

```
O(n^2)
```

---

## 第二题：递归的复杂度

写出每个的大 O。

```cpp
// a
int f(int n)
{
    if (n <= 1) return 1;
    return f(n - 1) + f(n - 1);
}

// b
int g(int n)
{
    if (n <= 1) return 1;
    return g(n - 1) + 1;
}

// c
int h(int n)
{
    if (n <= 1) return 1;
    return h(n / 2) + h(n / 2);
}

// d
int binary_search(const std::vector<int> &v, int target)
{
    int lo = 0, hi = static_cast<int>(v.size()) - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (v[mid] == target) return mid;
        if (v[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
```

**注意 c 和 a 的区别：`f(n-1)` 和 `h(n/2)`。**

**a.**

```
O(2^n)
```

**b.**

```
O(n)
```

**c.**

```
O(n)
```

**d.**

```
O(log n)
```

---

## 第三题：自己造

写三段代码：

- 一段是 **O(n)**
- 一段是 **O(n²)**
- 一段是 **O(log n)**

每段不超过 5 行。**不能和第一、二题的代码重复。**

**O(n)**

```cpp
for (int i = 0;i < n; ++i)
    if (a[i] >0) count++;
```

**O(n²)**

```cpp
for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
        if (i != j) pairs++;
```

**O(log n)**

```cpp
int x = n;
while (x > 0) { ++digits; x /= 10; }
```

---

## 第四题：判断对错

下面的说法对不对？错的说明原因。

```
a. O(n) 的代码一定比 O(n²) 的代码快

b. 100 个元素时，O(n²) 的代码肯定比 O(n log n) 慢

c. vector::push_back 单次操作是 O(1)

d. 如果两个函数都是 O(n)，它们的运行时间一定相同
```

**a.**

```
错，O(n) 一定比 O(n²) 快 —— 只有 n 足够大时才成立。
```

**b.**

```
错，看起来 O(n²) 更慢。但如果 O(n²) 的常数是 0.01，
而 O(n log n) 的常数是 100：
  10000 × 0.01 = 100
  664 × 100 = 66400
O(n²) 反而更快！

所以在小数据量下，常数因子的影响可能抵消复杂度差异。
```

**c.**

```
半对，均摊 O(1)，单次最坏 O(n)，不能简单说“是 O(1)”。
```

**d.**

```
错，都是 O(n) 只说明“增长趋势相同”，不代表常数相同。
vector 遍历 vs list 遍历都是 O(n)，实测差 33 倍。
```

---

## 第五题：实战判断

你的 `cpp-learning/final/` 里，`battle.cpp` 的 `run_round` 有这个循环：

```cpp
for (const auto &p : enemies_)
{
    if (p->is_alive())
    {
        int back_dmg = p->get_atk() - player_.defense();
        player_.take_damage(back_dmg);
    }
}
```

**a. 这段的复杂度是多少？（提示：看循环次数取决于什么）**

```
O(n), n = 敌人数量
```

**b. 如果敌人从 3 个变成 10000 个，这段会变慢多少量级？**

```
3 → 10000，比例 = 10000 / 3 ≈ 3333
时间复杂度是线性的，所以耗时也按同样比例增长。
这还只是“一段循环”；如果每帧都跑，60 帧/秒就是 33 万倍。
```

**c. 如果有 10000 个敌人，一局 100 回合，总共多少次操作？**

```
10,000*100=1,000,000
```

---

## 附加：缓存局部性（可选）

**不写代码，回答问题：**

**第一题 b 段（外层 n 次、内层固定 10 次）的复杂度是 O(n)。**
**如果内层访问的是 `a[i][j]`，而 `a` 是二维数组——**

**按行遍历 `for i: for j: a[i][j]`** 和**按列遍历 `for j: for i: a[i][j]`**，两者复杂度都是 O(n²)，**但哪一个更快？为什么？**

```
按行遍历 for i: for j: a[i][j]：

访问顺序：a[0][0] → a[0][1] → a[0][2] ... 完全连续
每次读到的 cache line 都能用满

按列遍历 for j: for i: a[i][j]：

访问顺序：a[0][0] → a[1][0] → a[2][0] ...
每次跳一整行，读进来的 cache line 只用了 1 个元素

复杂度都是 O(n²)，但按列遍历的实际耗时可能高几倍到几十倍**。**
```

---

*做完后把本文件发回，或把答案直接贴在对话里。*
