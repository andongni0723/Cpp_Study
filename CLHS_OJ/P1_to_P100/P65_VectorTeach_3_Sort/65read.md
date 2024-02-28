此題目為vector教學題目，配合"Vector教學訓練計畫"更佳。

# 說明

#### vector擁有一個很強大的功能 --- 迭代器 Iterator，
它可以讓你更方便的遍歷vector或是排序vector

```cpp
// 簡易寫法
for(auto it : vec)
{
    cout << it << endl; // 遍歷vector 輸出資料
}

// for(auto [迭代器名稱] : [可迭代對象])
// {
//     程式...
// }

//----------------------
// 以前寫法
vector<int> vec;
vector<int>::iterator i;  
for (i = vec.begin(); i != vec.end(); ++i) 
{
    cout << *i;
}
```

- `auto`是自動類型，會依據你的vector類型做變化
- 在簡易寫法中，第4行的`it`代表的當前的資料，像`vec[i]`一樣
- `[vector名稱].begin()` 代表的是vector的首項
- `[vector名稱].end()` 代表的是vector的末項

#### 除了可以遍歷vector，學會迭代器還可以使用一些C++的內置函式

```cpp
sort(vec.begin(), vec.end()); // 小到大
sort(vec.begin(), vec.end(), greater<int>()); // 大到小
```
- 可以快速的排序vector

# 題目

給你一個大小為 $n$ 的vector $A$

$a_i$表示vector$A$中的第 i 個元素

現在有 q 筆資料

若當前這筆數據 $b$ 小於當前vector中的數據之和時

則將$b$加入vector$A$中

最後打印出vector$A$中所有的數據

## 輸入格式

$$
1 \le n \le 10 \\
1 \le q \le 100\\
0 \le a_i \le 10^7\\
0 \le b \le 10^7
$$

## 輸出格式

```input1
3 5
1 2 3
7
3
8
20
30
```

```output1
1
2
3
3
8
```

```input2
3 8
10 10 0
20
30
100
192
222
9
13
312
```

```output2
10
10
0
9
13
```
