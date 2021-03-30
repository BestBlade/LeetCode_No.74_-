### LeetCode_No.74_-搜索二维矩阵
* 题目描述

      编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

      每行中的整数从左到右按升序排列。
      每行的第一个整数大于前一行的最后一个整数。

* 示例 1：

![](https://assets.leetcode.com/uploads/2020/10/05/mat.jpg)

    输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    输出：true
* 示例 2：

![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/11/25/mat2.jpg)

    输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
    输出：false
 

* 提示：

      m == matrix.length
      n == matrix[i].length
      1 <= m, n <= 100
      -104 <= matrix[i][j], target <= 104
      
### 解法思路
* 优化遍历
  * 时间复杂度O(n+m)
  * 空间复杂度O(1)
* 一次二分
  * 时间复杂度O(n+logm)
  * 空间复杂度O(1)
* 两次二分
  * 时间复杂度O(logmn)
  * 空间复杂度O(1)
  
来源：力扣（LeetCode）\
链接：https://leetcode-cn.com/problems/search-a-2d-matrix \
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。      
