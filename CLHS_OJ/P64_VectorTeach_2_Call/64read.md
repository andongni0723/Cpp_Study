此題目為vector教學題目，配合"Vector教學訓練計畫"更佳。

# 說明

#### 以下是vector取得資料的方法，和大部份程式語言一樣

```cpp
vec[1];
// vector名稱.[資料編號];
```

- 在`[]`中填入資料編號後，可以取得vector中該編號的資料。

#### 以下是vector用For讀取資料的方法

```cpp
for(int i = 0 ; i < vec.size(); i++)
{
    //程式
    //...
}
```

- 可以使用`.size()`得到vector的大小

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
