/* ------------------------------------------------------------------|
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
示例 1:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
输出: true
示例 2:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-a-2d-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
------------------------------------------------------------------*/

/*	两次二分查找法
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了99.44%的用户
*	内存消耗：9.3 MB, 在所有 C++ 提交中击败了18.40%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

bool searchMatrix(vector<int >& matrix, int target) {							/*	对一维数组进行二分查找	*/
	int head = 0;
	int tail = matrix.size() - 1;
	while (head < tail) {
		int mid = (head + tail) / 2;
		if (matrix[mid] >= target) {
			tail = mid;
		}
		else {
			head = mid + 1;
		}
	}
	return (matrix[head] == target);
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {					/*	对二维数组进行二分查找	*/
	if (matrix.size() == 0 || matrix[0].size() == 0) {
		return false;
	}
	int col = matrix[0].size() - 1;
	int head = 0;
	int tail = matrix.size() - 1;

	while (head < tail) {
		int mid = (head + tail) / 2;
		if (matrix[mid][col] >= target) {
			tail = mid;
		}
		else {
			head = mid + 1;
		}
	}

	return searchMatrix(matrix[head], target);
}

int main() {
	vector<vector<int> > matrix = { {1,   3,  5,  7},{10, 11, 16, 20},{23, 30, 34, 50} };
	int target = 13;

	cout << searchMatrix(matrix, target) << endl;
}