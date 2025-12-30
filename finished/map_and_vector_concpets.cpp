#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	// iterator: 一種物件（object），用來走訪容器（container） 裡的元素。
	// 可以把迭代器想成類似指標（pointer），但它比指標更聰明，知道如何走訪不同類型的容器。
	// 這對 vector 有用，因為 vector 是連續記憶體陣列（array-like），可以用 v[i] 存取。
	vector<int> v = {10, 20, 30};
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";  // 10 20 30
	}

	// 但如果換成 map：
	map<int, string> m = {{1, "one"}, {2, "two"}};
	cout << m[0];  // ❌ 錯誤：map 沒有索引 0
	// map 沒有索引（index），只能透過迭代器來存取元素。

	// 這裡 it 是 迭代器（iterator）：
	//   v.begin()：指向 vector 的第一個元素
	//   v.end()：指向 最後一個元素的下一個位置（類似 NULL）
	//   *it：存取 it 目前指向的值（類似指標 *ptr）
	vector<int> v2 = {10, 20, 30};
	vector<int>::iterator it;
	for (it = v2.begin(); it != v2.end(); it++) {
		cout << *it << " ";  // 10 20 30
	}
	// 這種方式 適用於所有容器，不只 vector，連 map 也可以用。


	// 宣吿 m2 與他的雙向迭代器 (雙向移動)
	map<int, string> m2 = {{1, "one"}, {2, "two"}, {3, "three"}};
    map<int, string>::iterator it2;
    // 用迭代器走訪 map
    for (it2 = m.begin(); it2 != m.end(); it2++) {
        cout << "Key: " << it2->first << ", Value: " << it2->second << endl;
    }
	// 雙向迭代器的基本特性
	//   ++it 讓迭代器移動到下一個元素（順序遍歷）
	//   --it 讓迭代器移動到前一個元素（反向遍歷）
	//   無法使用 it + n 或 it - n 直接跳過多個元素
	// map 的迭代器比 vector 慢，因為它要透過樹狀結構尋找元素
	//   遍歷 vector = O(1)
	//   遍歷 map = O(log n)（因為 map 是紅黑樹）
}
