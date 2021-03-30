/* ------------------------------------------------------------------|
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
 

示例 1：


输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true
示例 2：


输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
输出：false
 

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-a-2d-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/**
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：8.1 MB, 在所有 C++ 提交中击败了81.94%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


/*  遍历法
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：9.1 MB, 在所有 C++ 提交中击败了89.86%的用户
*/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; ++i) {
        if (matrix[i][0] <= target && matrix[i][m - 1] >= target) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
    }
    return false;
}

/*  单二分法
*	执行用时：4 ms, 在所有 C++ 提交中击败了87.61%的用户
*	内存消耗：9.3 MB, 在所有 C++ 提交中击败了59.03%的用户
*/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; ++i) {
        if (matrix[i][0] <= target && matrix[i][m - 1] >= target) {
            int l = 0;
            int r = m - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (matrix[i][mid] >= target) {
                    r = mid;
                }
                else {
                    l = mid + 1;
                }
            }
            return matrix[i][l] == target;
        }
    }
    return false;
}

/*  双二分法
*	执行用时：4 ms, 在所有 C++ 提交中击败了87.61%的用户
*	内存消耗：9.2 MB, 在所有 C++ 提交中击败了87.96%的用户
*/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    int up = 0;
    int down = n - 1;
    while (up < down) {
        int mid = (up + down) / 2;
        if (matrix[mid][m - 1] >= target) {
            down = mid;
        }
        else {
            up = mid + 1;
        }
    }

    int l = 0;
    int r = m - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (matrix[up][mid] >= target) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    return matrix[up][l] == target;
}