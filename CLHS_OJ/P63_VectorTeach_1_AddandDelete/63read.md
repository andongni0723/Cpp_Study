此題目為vector教學題目，配合"Vector教學訓練計畫"更佳。

# 說明

### Vector是C++中最基礎的容器, 你可以把它想像成進階版的array, 使用好vector的功能，它能給你更好的體驗。

---

#### 以下是使用C++定義一個vector的語法

```cpp
vector<int> vec;
vector<int> vec2 = {1, 3, 4};
//vector <[資料類型]> [vector名稱];
```

- 在`<>`中填入資料類型後，vector中就只能含有該類型的資料。
- vector不用定義容器大小，可以 降低出現Index溢出的錯誤。~~array就在說你~~
- 在定義後加上`={ }`可以放入資料

#### 以下是vector用函式新增/刪除資料的語法

```cpp
vec.push_back(1);
// [vector名稱].push_back([想新增的資料]);

vector.pop_back();
// [vector名稱].pop_back();
```

- 使用`push_back()`可以在vector最後新增一筆資料
- 使用`pop_back()`可以刪除vector中最後一筆資料

# 題目

1. 定義一個資料類型為**string**, 名字為**simple**的vector。
2. 在名為**simple**的vector中，新增一筆名叫**341**的int資料。
3. 在名為**secVec**的vector中，刪除vector中最後一筆資料。

```cpp
vector<int> vec;
//         ^ 注意空格
```

## 輸出格式

此題為提交答案題，請按範例格式作答

```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> answerVector = {
            "answer1", // 把引號中的文字替換成答案
            "answer2", // 把引號中的文字替換成答案
    };

    int no;
    cin >> no;
    cout << answerVector[no - 1];
}
```
