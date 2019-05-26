//
// Created by DELL on 2019/4/13.
//

#ifndef DATASTRUCT_LEECODE_H
#define DATASTRUCT_LEECODE_H

#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<cstring>
#include<cmath>
#include<cassert>

using namespace std;
namespace LeeCode {
    /**104
 * Definition for a binary tree node.
     */
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

    };

    class Solution {
    public:
        int maxDepth(TreeNode *root) {
            if (NULL == root) {
                return 0;
            }
            return max(maxDepth(root->left), maxDepth(root->right));

        }

        int minDepth(TreeNode *root) {
            if (NULL == root) {
                return 0;
            }

            if (NULL == root->left && NULL == root->right) {
                return 1;
            }

            minDepth(root->left);


        }

        /**
         * 226
         * @param root
         * @return
         */
        TreeNode *invertTree(TreeNode *root) {
            if (NULL == root) {
                return NULL;
            }
            invertTree(root->left);
            invertTree(root->right);
            swap(root->left, root->right);
            return root;
        }

        /**
         * 100
         * @param p
         * @param q
         * @return
         */
        bool isSameTree(TreeNode *p, TreeNode *q) {
            if (NULL == p || NULL == q) {

                if (p == q) {
                    return true;
                }
                return false;
            }

            return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));

        }

        /**
         * 101
         * @param root
         * @return
         */
        bool isSymmetric(TreeNode *root) {
            if (NULL == root) {
                return true;
            }
            return isSymmetric(root->left, root->right);
        }

        bool isSymmetric(TreeNode *left, TreeNode *right) {
            if (!left && !right) return true;
            if (left && !right || !left && right || left->val != right->val) return false;
            return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
        }

        /**
         * 112
         * @param root
         * @param sum
         * @return
         */
        bool hasPathSum(TreeNode *root, int sum) {
            if (NULL == root) {
                return false;
            }

            if (root->left == NULL && root->right == NULL) {
                return root->val == sum;
            }

            if (hasPathSum(root->left, sum - root->val)) {
                return true;
            }

            if (hasPathSum(root->right, sum - root->val)) {
                return true;
            }

            return false;

        }

        /**
         *
         * @param root
         * @return
         */
        vector<string> binaryTreePaths(TreeNode *root) {
            vector<string> rest;
            if (NULL == root) {
                return rest;
            }
            if (NULL == root->left && NULL == root->right) {

                rest.push_back(to_string(root->val));
                return rest;
            }
            vector<string> left = binaryTreePaths(root->left);
            for (int i = 0; i < left.size(); i++) {
                rest.push_back(to_string(root->val) + "->" + left[i]);
            }

            vector<string> right = binaryTreePaths(root->right);
            for (int i = 0; i < right.size(); i++) {
                rest.push_back(to_string(root->val) + "->" + right[i]);
            }
            return rest;

        }

        int pathSum(TreeNode *root, int sum) {
            if (NULL == root) {
                return 0;
            }
            int total = 0;
            total = findPath(root, sum);
            total += pathSum(root->left, sum);
            total += pathSum(root->right, sum);
            return total;

        }

    private:
        int findPath(TreeNode *root, int sum) {


            if (NULL == root) {
                return 0;
            }
            int rest = 0;
            if (root->val == sum) {
                rest += 1;
            }
            rest += findPath(root->right, sum - root->val);
            rest += findPath(root->left, sum - root->val);

            return rest;

        }

        /**
         * 3
         * @param s
         * @return
         */
        int lengthOfLongestSubstring(string s) {
            int m[256] = {0}, res = 0, left = 0;
            for (int i = 0; i < s.size(); ++i) {
                if (m[s[i]] == 0 || m[s[i]] < left) {
                    res = max(res, i - left + 1);
                } else {
                    left = m[s[i]];
                }
                m[s[i]] = i + 1;
            }
            return res;

        }

        string longestPalindrome(string s) {
            int size = s.size();

            if (size == 0) {
                return "";
            }

            if (size == 2) {
                if (s[0] == s[1]) {
                    return s;
                }
            }
            for (int i = 3; i < size; i++) {

            }

        }

        string findPalindrome(int index, string str) {

        }

        /**
         * 50
         * @param x
         * @param n
         * @return
         */
        double myPow(double x, int n) {
            if (0 == x) {
                return 0;
            }

            if (0 == n) {
                return 1;
            }

            int p = n;

            if (p < 0) {
                p = -p;
            }

            double rest = x;

            for (int i = 1; i < p; i++) {
                rest *= x;
            }

            return n < 0 ? 1 / rest : rest;

        }

        struct ListNode {
            int val;
            ListNode *next;

            ListNode(int x) : val(x), next(NULL) {}
        };

        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            int total = linkToInt(l1) + linkToInt(l2);
            ListNode *head;
            int count = 0, num = total;

            while (total != 0) {
                total = total / 10;
                count++;
            }
            int power, temp;
            for (int i = 1; i <= count; i++) {
                power = pow(10.0, count - i);
                temp = num / power;
                num = num % power;
            }
            return head;
        }

        int linkToInt(ListNode *L) {
            stack<int> s;
            ListNode *temp;
            temp = L;
            while (temp) {
                s.push(temp->val);
                temp = temp->next;
            }
            int size = s.size();
            if (size <= 0) {
                return 0;
            }
            int h = pow(10, size);
            int sum = 0;
            for (int i = size; i > 0; i--) {
                h = h / 10;
                sum += s.top() * h;
                s.pop();
            }
            return sum;
        }
    };

    /**
     * 17 number of tel `s Combinations
     */
    vector<string> letterStr;
    const string letterMap[10] = {
            " ",   //0
            "",    //1
            "abc",  //2
            "def",  //3
            "ghi",  //4
            "jkl",  //5
            "mno",  //6
            "pqrs", //7
            "tuv",  //8
            "wxyz" //9
    };

    void findCombination(const string &digits, int index, const string &s) {
        if (index == digits.size()) {
            letterStr.push_back(s);
            return;
        }
        char c = digits[index];
        assert(c >= '0' && c <= '9' && c != '1');
        string letters = letterMap[c - '0'];
        for (int i = 0; i < letters.size(); i++) {
            findCombination(digits, index + 1, s + letters[i]);
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        letterStr.clear();
        if (digits == "") {
            return letterStr;
        }
        findCombination(digits, 0, "");
        return letterStr;
    }

    /**
     * 46 Permutations
     */
    vector<vector<int>> permutationVect;
    vector<bool> isUsed;

    void generatePermutation(const vector<int> &nums, int index, vector<int> &p) {
        if (index == nums.size()) {
            permutationVect.push_back(p);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (isUsed[i]) {
                continue;
            }
            p.push_back(nums[i]);
            isUsed[i] = true;
            generatePermutation(nums, index + 1, p);
            p.pop_back();
            isUsed[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        permutationVect.clear();

        if (nums.size() == 0) {
            return permutationVect;
        }
        isUsed = vector<bool>(nums.size(), false);
        vector<int> p;
        generatePermutation(nums, 0, p);
        return permutationVect;
    }

    /**
     * 77
     * @param n
     * @param k
     * @return
     */
    vector<vector<int>> combineRest;

    void generateCombine(int n, int k, int start, vector<int> &c) {
        if (c.size() == k) {
            combineRest.push_back(c);
            return;
        }

        for (int i = start; i <= (n - (k - c.size())) + 1; i++) {
            c.push_back(i);
            generateCombine(n, k, i + 1, c);
            c.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        combineRest.clear();
        if (n <= 0 || k <= 0 || k > n) {
            return combineRest;
        }
        vector<int> c;
        generateCombine(n, k, 1, c);
        return combineRest;

    }

    /**
     * 39 combinations Sum
     */
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {

    }

    /**
     * 40 Combinations Sum II
     */

    /**
     * 216 combination SUM III
     */

    /**
     * 78 subsets
     */

    /**
     * 90 subsets II
     */

    /**
     * 79 word search
     */

    int direct[4][2] = {{-1, 0},
                        {0,  1},
                        {1,  0},
                        {0,  -1}};
    int row, col;
    vector<vector<bool>> isVisited;

    bool isInArea(int x, int y) {
        return x > 0 && x < row && y > 0 && y < col;
    }

    bool searchWord(const vector<vector<char>> &board, const string &word, int index, int startx, int starty) {
        if (index == word.size() - 1) {
            return board[startx][starty] == word[index];
        }

        if (board[startx][starty] != word[index]) {
            return false;
        }

        isVisited[startx][starty] = true;

        for (int i = 0; i < 4; i++) {
            int newx = startx + direct[i][0];
            int newy = starty + direct[i][1];
            if (!isInArea(newx, newy) || isVisited[newx][newy]) {
                continue;
            }
            if (searchWord(board, word, index + 1, newx, newy)) {
                return true;
            }
        }
        isVisited[startx][starty] = false;
        return false;
    }

    bool exist(vector<vector<char>> &board, string word) {
        row = board.size();
        assert(row > 0);
        col = board[0].size();

        isVisited = vector<vector<bool>>(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (searchWord(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;

    }
    /**
     * 200 number if islands
     */
    int islandHeight = 0;
    int islandWidth = 0;

    //vector<vector<bool>> islandVisitor;
    void dfsIsland(vector<vector<char>> &grid, int x, int y) {
        if ((x < 0) || (x >= islandHeight) || (y < 0) || (y >= islandWidth) || (grid[x][y] != '1')) {
            return;
        }
        grid[x][y] = 2;
        // isVisitor[x][y] = true;
        dfsIsland(grid, x + 1, y);
        dfsIsland(grid, x - 1, y);
        dfsIsland(grid, x, y + 1);
        dfsIsland(grid, x, y - 1);
    }

    int numIslands(vector<vector<char>> &grid) {
        islandHeight = grid.size();
        if (islandHeight <= 0) {
            return 0;
        }
        islandWidth = grid[0].size();
        if (islandWidth <= 0) {
            return 0;
        }
        int num = 0;
        //islandVisitor = vector<vector<bool>>(islandHeight,vector<bool>(islandWidth, false));
        for (int i = 0; i < islandHeight; i++) {
            for (int j = 0; j < islandWidth; j++) {
                if (grid[i][j] != '1') {
                    continue;
                }
                dfsIsland(grid, i, j);
                num++;
            }
        }
        return num;
    }

    /**
     * 130 Surrounded regions
     */
    int h = 0, w = 0;
    int  directRegions[4][2] = {{-1, 0},
                                {0,  1},
                                {1,  0},
                                {0,  -1}};
    bool isInRegions(int i, int j) {
        return ((i >=0)&&(i<h)&&(j>=0)&&(j<w));
    }
      void markDfs(vector<vector<char>> &board, int i, int j) {
           board[i][j] = 'P';
           for(int start = 0; start < 4; start++) {
               int newi = directRegions[start][0] + i;
               int newj = directRegions[start][1] + j;
               if(!isInRegions(newi,newj)){
                   continue;
               }
               if(board[newi][newj] != 'O') {
                   continue;
               }
               markDfs(board, newi, newj);
           }


    }
    void solve(vector<vector<char>>& board) {
         h = board.size();
         if(h < 1) {
             return;
         }
         w = board[0].size();
         if(w < 1) {
             return;
         }
         for(int i = 0; i< w; i++) if(board[0][i] == 'O')markDfs(board, 0, i);
         for(int j = 0; j< w; j++) if(board[h-1][j] == 'O') markDfs(board, h-1, j);
         for(int m = 1; m < h-1; m++) if(board[m][0] == 'O') markDfs(board, m, 0);
         for(int n = 1; n < h-1; n++) if(board[n][w-1] == 'O') markDfs(board,n, w-1);

         for(int b = 0; b < h; b++) {
             for(int k = 0; k < w; k++){
                 if(board[b][k] == 'O') {
                     board[b][k] = 'X';
                 }
                 if(board[b][k] == 'P'){
                     board[b][k] = 'O';
                 }

             }
         }

    }
     /**
     * 417 Pacific Atlantic Water Flow
     */
     vector<pair<int,int>> directMove =  {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
     void pacificDFS(vector<vector<int>> &matrix, vector<vector<bool>> &isVisitor, int i, int j){
          //cout << "i:" << i  << " j:" << j << endl;
          isVisitor[i][j] = true;
          for(auto d : directMove) {
              int newx = i + d.first;
              int newy = j + d.second;
             /*if((newx < 0)||(newx > h)||(newy < 0) || newy > w) {
                  continue;
              }
             if(isVisitor[newx][newy]) {
                 continue;
              }
              if(matrix[i][j] > matrix[newx][newy]) {
                  continue;
              }*/
              //cout << "current :" << i << "," << j <<  " val:" << matrix[i][j] << " next :" << newx << "," << newy << " val:" << matrix[newx][newy] << endl;
             if(newx >= 0 && newx < h && newy >= 0 && newy < w && !isVisitor[newx][newy] && matrix[newx][newy] >= matrix[i][j]){
                 pacificDFS(matrix, isVisitor, newx, newy);
             }
          }
     }
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int i, int j) {
        const int M = matrix.size();
        const int N = matrix[0].size();
        visited[i][j] = true;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto d : dirs) {
            int nx = i + d.first;
            int ny = j + d.second;
            if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[nx][ny] && matrix[nx][ny] >= matrix[i][j]) {
                dfs(matrix, visited, nx, ny);
            }
        }
    }
     vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
         vector<vector<int>> rest;
         rest.clear();
         h = matrix.size();
         if (h < 1) {
             return rest;
         }
         w = matrix[0].size();
         if (w < 1) {
             return rest;
         }
         vector<vector<bool>> isVisitor_p(h, vector<bool>(w));
         vector<vector<bool>> isVisitor_a(h, vector<bool>(w));
        /* for(int i=0; i< w; ++i)dfs(matrix,isVisitor_p,0,i);
         for(int j=1; j< h; ++j)dfs(matrix,isVisitor_p,j,0);
         for(int k=0; k< w; ++k)dfs(matrix,isVisitor_a,h-1,k);
         for(int b=0; b< h-1; ++b)dfs(matrix,isVisitor_a,w-1,b); */
        for (int i = 0; i < h; ++i) {
            pacificDFS(matrix, isVisitor_p, i, 0);
            pacificDFS(matrix, isVisitor_a, i, h - 1);
         }

         for (int j = 0; j < w; ++j) {
             pacificDFS(matrix, isVisitor_p, 0, j);
             pacificDFS(matrix, isVisitor_a, h - 1, j);
         }

         for (int i = 0; i < h; i++) {
             for (int j = 0; j < w; j++) {
                 if (isVisitor_a[i][j] && isVisitor_p[i][j]) {
                     vector<int> temp = {i, j};
                     rest.push_back(temp);
                 }
             }
         }
         return rest;
     }
   /* vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        const int M = matrix.size();
        const int N = matrix[0].size();
        vector<vector<bool>> p_visited(M, vector<bool>(N));
        vector<vector<bool>> a_visited(M, vector<bool>(N));
        for (int i = 0; i < M; ++i) {
            dfs(matrix, p_visited, i, 0);
            dfs(matrix, a_visited, i, N - 1);
        }
        for (int j = 0; j < N; ++j) {
            dfs(matrix, p_visited, 0, j);
            dfs(matrix, a_visited, M - 1, j);
        }
        vector<vector<int>> res;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (p_visited[i][j] && a_visited[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }*/


    /**
     * 51 N-Quenens
     */
    void backtracking(vector<vector<string>>& ans, vector<string> current, int i, int n, vector<bool>& column, vector<bool>& cross1, vector<bool>& cross2) {
        // 判断是否已经枚举完了每一行的皇后位置，如果是，说明已经找到了一组解
        if (i == n) {
            ans.push_back(current);
        }
        else {
            // 否则枚举当前行皇后放置的位置
            for (int j = 0; j < n; j++) {
                // 判断是否会和之前放置的皇后产生列上的冲突
                if (column[j]) continue;
                // 判断是否会和之前放置的皇后产生第一种对角线上的冲突
                if (cross1[i + j]) continue;
                // 判断是否会和之前放置的皇后产生第二种对角线上的冲突
                if (cross2[i - j + n - 1]) continue;
                // 如果都不产生冲突，说明当前方案合法，对状态进行修改并递归的枚举下一行的放置方案
                current[i][j] = 'Q'; column[j] = true; cross1[i + j] = true; cross2[i - j + n - 1] = true;
                backtracking(ans, current, i + 1, n, column, cross1, cross2);
                // 回溯，消去产生的修改
                current[i][j] = '.'; column[j] = false; cross1[i + j] = false; cross2[i - j + n - 1] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        // 答案
        vector<vector<string>> ans;
        // 构造一个初始棋盘
        vector<string> current(n, string(n, '.'));
        // 构造用于判断攻击的数组
        vector<bool> column(n, false);
        vector<bool> cross1(n * 2 - 1, false);
        vector<bool> cross2(n * 2 - 1, false);
        // 回溯求解所有的方案
        backtracking(ans, current, 0, n, column, cross1, cross2);
        // 返回所有答案
        return ans;
    }


    /**
     * 52 N-Quenens
     */

    /**
     * 37 sudoku solver
     */
    int singleNumber(vector<int>& nums) {
         if(nums.size() ==0) {
             return 0;
         }
         int count  = 0;
         for(int i=1; i<nums.size(); i++) {
             if(nums[count] != nums[i]) {
                 count++;
                 nums[count] = nums[i];
             }
         }
         return ++count;
    }

    /**
     * 122
     * @param prices
     * @return
     */
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) {
            return 0;
        }
        int p,max = 0;
        for(int i = 1; i < prices.size(); i++) {
            p = prices[i] - prices[i-1];
            if(p <= 0) continue;
            max += p;
        }
        return max;

    }
    /**
     * 3
     * @param nums
     * @param k
     */
    void moveToRight(vector<int> &nums, int size) {
        int tail = nums[size-1];
        for(int end = size-1; end >=1;size--) {
            nums[end] = nums[end-1];
        }
        nums[0] = tail;
    }

    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if(size == 0) {
            return;
        }
        for(int i = 0; i<k; i++) {
            moveToRight(nums,size);
        }
        return;
    }
   /**
    *
    * @param nums
    * @return
    */
    bool containsDuplicate(vector<int>& nums) {
         map<int,int> record;
         for(auto n : nums){
             record[n]++;
             if(record[n] > 1) {
                 return true;
             }
         }
         return false;
    }
   /**
    *
    * @param nums
    * @return
    */
     bool countTime(vector<int> &num, int index) {
          int size = num.size();
          for(int i = 0; i < size; i++) {
              if(num[i] == num[index] && i != index) {
                  return false;
              }
          }
       return true;

     }
    int singleNumber2(vector<int>& nums) {
         int size = nums.size();
        for(int i = 0; i<size; i++) {
             if(countTime(nums,i))return nums[i];
        }
        return 0;
     }
    /**
     *
     * @param nums1
     * @param nums2
     * @return
     */
     bool isExite(vector<int> nums, int target, map<int, bool> &record) {
           for(int i = 0; i< nums.size(); i++) {
              if(record[i]) {
                  continue;
              }
              if(target == nums[i]) {
                  record[i] = true;
                  return true;
              }
          }
          return false;
     }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
           vector<int> rest;
           vector<int> sour = nums1;
           vector<int> desc = nums2;
           if(desc.size() == 0 || sour.size() ==0 ) {
               return rest;
           }
           if(nums1.size() > nums2.size()) {
               sour = nums2;
               desc = nums1;
           }
          map<int,bool> record;
           for(auto n : sour) {
               if(!isExite(desc,n,record)) {

                   continue;
               }
               rest.push_back(n);
           }

        return rest;

    }
   /**
    *
    * @param num
    * @return
    */
    stack<int> separateInt(unsigned long int num) {
        stack<int> s;
        while (num > 0) {
            s.push(num % 10);
            num = num /10;
        }
        return s;
    }
    vector<int> plusOne(vector<int>& digits) {
        vector<int> rest;
        int size = digits.size();
        if(0==size) {
            return rest;
        }
        unsigned long int step = 1;
        unsigned long int total = 0;
        for(int i = size-1; i >=0; i--) {
            total += (digits[i] * step);
            step *= 10;
        }
        ++total;
        stack<int> s = separateInt(total);
        if(s.empty()){
            return rest;
        }
        while (!s.empty()) {
            rest.push_back(s.top());
            s.pop();
        }
        return rest;
    }
    /**
     *移动零
     * @param nums
     */
    void moveZeroes(vector<int>& nums) {
         if(nums.size() == 0) {
             return;
         }
         int index = 0;
         for(int i = 0; i<nums.size(); i++) {
             if(nums[i] != 0) {
                nums[index++] = nums[i];
             }
         }
         for(int i = index; i< nums.size(); i++) {
             nums[i] = 0;
         }
        return;

}
    /**
     * 反转字符串
     * @param s
     */
    void reverseString(vector<char>& s) {
         int size = s.size();
         if(size <= 1) {
             return;
         }
         int index = size / 2;
         if((size % 2) != 0){
             index += 1;
         }
         for(int i = index; i < size; i++ ){
             swap(s[i],s[size-(i+1)]);
         }
     }

     bool isPalindrome(string s) {
         int start = 0, end = s.size()-1;
         if(end == 0)return true;
         while(start < end) {
              if(isalnum(s[start]) == false){
                  ++start;
                  continue;
              }

              if(isalnum(s[end]) == false){
                  --end;
                  continue;
              }
              if(tolower(s[start]) != tolower(s[end]))return false;
              ++start;
              --end;

         }
         return true;
    }
    /**
     *整数反转
     * @param x
     * @return
     */
    long int reverse(int x) {
        long long result=0;
        long long temp = x;
        int flag = 1;
        if (0 > x){
            flag = -1;
            temp = -temp;
        }
        while (0<temp) {
            result = result * 10 + temp % 10;
            temp /= 10;
        }

        if (result > INT_MAX) result = 0;
        return result * flag;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> rest;
        if(nums.size() == 0) {
            return rest;
        }
          for(int i = 0; i < nums.size()-1; i++) {
                  for(int j = i+1; j < nums.size(); j++) {
                      if(nums[i] + nums[j] == target) {
                          rest.push_back(i);
                          rest.push_back(j);
                          return rest;
                      }
                  }
          }
          return rest;

    }
     /**
      * 字符串中的第一个唯一字符
      * @param s
      * @return
      */
    int firstUniqChar(string s) {
        map<char,int> strMap;
        for(int i = 0; i < s.length(); i++)strMap[s[i]]++;
        for(int j = 0; j < s.length(); j++)if(strMap[s[j]] == 1)return j;
        return -1;
    }

    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return  false;
        }
         map<char,int> record_s,record_t;
         for(int i = 0; i < s.length(); i++)record_s[s[i]]++;
         for(int j = 0; j < t.length(); j++)record_t[t[j]]++;
         map<char,int>::iterator view;
         for(view = record_s.begin(); view != record_s.end(); view++) {
             if(view->second != record_t[view->first])return false;
         }
        return true;
    }
    struct ListNode {
             int val;
             ListNode *next;
             ListNode(int x) : val(x), next(NULL) {}
         };
    void deleteNode(ListNode* node) {

    }
    /**
     *字符串转换整数 (atoi)
     * @param str
     * @return
     */
    int myAtoi(string str) {


    }
    /**
     * 实现strStr()
     * @param haystack
     * @param needle
     * @return
     */
    int strStr(string haystack, string needle) {
        if(haystack == needle) {
            return 0;
        }
        int size = haystack.size();
        if(size == 0) {
            return -1;
        }

        if(needle.size() == 0) {
            return 0;
        }
        if(size < needle.size()) {
            return -1;
        }
        string str;
        for(int i = 0; i < size; i++) {
            str = haystack.substr(i,needle.size());
            if(str == needle) {
                return i;
            }
        }
        return -1;

    }

    int majorityElement(vector<int>& nums) {
        map<int,int> record;
        for(auto val : nums)record[val]++;
        pair<int,int> max = {0,0};
        map<int,int>::iterator view;
        for(view = record.begin(); view != record.end(); view++ ){
            if(view->second >max.second) {
                max.second = view->second;
                max.first  = view->first;
            }
        }
        return max.first;
    }

    string countAndSay(int n) {


    }
    /**
     * 搜索二维矩阵 II
     * @param list
     * @param l
     * @param r
     * @param target
     * @return
     */
    bool binarySearch(vector<int> &list,int l, int r, int target) {
        if(l > r) {
            return false;
        }
        int mid = l + ((r-l)/2);
        if(list[mid] == target) {
            return true;
        }
        if(list[mid] > target) {
           return binarySearch(list,0,mid-1,target);
        }

        if(list[mid] < target) {
          return binarySearch(list,mid+1,r,target);
        }

        return false;
    }

    bool binarySearchII(vector<int> &list,int target) {
         int size = list.size();
         int left = 0;
         int right = size-1;
         while (left <= right) {
               int mid = left + (right-left)/2;
               if(target == list[mid])return true;
               if(list[mid] > target) right = mid-1;
               if(list[mid] < target) left  = mid+1;
         }
         return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int h = matrix.size();
         if(h < 1) {
             return false;
         }
         int w = matrix[0].size();
         if(w < 1) {
             return false;
         }
        for(int i = 0; i < h; i++) {
            if(matrix[i][0] > target || matrix[i][w-1] < target) {
                continue;
            }
            if(binarySearchII(matrix[i],target)){
                return true;
            }
        }
        return false;

    }
   /**
    * 合并两个有序数组
    * @param nums1
    * @param m
    * @param nums2
    * @param n
    */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         if(n < 1) {
             return;
         }

         int temp[m+n];
         int index1=0,index2=0,index3=0;
         while(index1 < m && index2 < n){
              if(nums1[index1] <=nums2[index2])temp[index3++] = nums1[index1++];
              else
              temp[index3++] = nums2[index2++];
         }
         while (index1 < m)temp[index3++] = nums1[index1++];
         while (index2 < n)temp[index3++] = nums2[index2++];
         copy(temp, temp+m+n, nums1.begin());
         return;
    }
    /**
     * 鸡蛋掉落 887
     * @param K
     * @param N
     * @return
     */
    int superEggDrop(int K, int N) {
        int count = 0;
        int start = 0;
        int end   = N;
        while (start <= end) {
            int mid = start + (end - start)/2;
            if(mid == K) {
               ++count;
                return count;
            }

            if(mid > K) {
              end = mid -1;
              count++;
              continue;
            }

            if(mid < K) {
              start = mid+1;
            }
        }

        return 0;
    }
    /**
     * 分割回文串
     * @param s
     * @return
     */
     void getSubstring(string s, int index,string prevStr,vector<string> &rest){
         if(index == s.size()){
              rest.push_back(prevStr);
              return;
          }
          for(int start = index; start < s.size(); start++) {
              rest.push_back(prevStr+s[start]);
              getSubstring(s,index+1,prevStr +s[start],rest);
          }
     }
    vector<string> partition(string s) {
      vector<string> rest;
      rest.clear();
      getSubstring(s,0,"",rest);
      return rest;
    }
    /**
     * 第一个错误的版本
     * @param version
     * @return
     */
    bool isBadVersion(int version);
    int firstBadVersion(int n) {
        long start = 1, end = n, mid = start + ((end - start) >> 1);

        while (start < end) {
             if(isBadVersion(mid))
                 end = mid -1;
             else
                 start = mid + 1;
             mid = start + ((end - start) >> 1);
        }
        return start;

    }



    /**
     * 爬楼梯
     * @param n
     * @return
     */
    map<int,int> record;
    int climbStairs(int n) {
        if(n < 1)return 0;
        if(1==n) return 1;
        if(2==n) return 2;

        int sum = climbStairs(n-1) + climbStairs(n-2);
        record.insert(pair<int,int>(n,sum));
    }
    /**
     * 买卖股票的最佳时机
     * @param prices
     * @return
     */
    int maxProfitII(vector<int>& prices) {
        int m = 0;
        if(prices.size() < 1) {
        return m;
        }
        for(int i=0; i < prices.size(); i++) {
                for(int j = i+1; j < prices.size(); j++) {
                    if(prices[i] >= prices[j]) {
                        continue;
                    }
                    m = max(m,prices[j] - prices[i]);
                }
        }

        return m;
    }
    int maxProfitIII(vector<int>& prices) {
        if(prices.size() < 1) {
            return 0;
        }
        int max = 0;
        int mix = prices[0];
        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < mix) {
                mix = prices[i];
                continue;
            }
            if((prices[i] - mix) <= max) continue;
            max = prices[i] - mix;
        }
        return max;
    }
    /**
     * 有效的数独
     * @param board
     * @return
     */
    bool isValidSudoku(vector<vector<char>>& board) {


    }
    /**
     * 最长公共前缀
     * @param strs
     * @return
     */

    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        for(int len = 0; len < strs[0].length(); len++)
            for(int i = 1; i < strs.size(); i++)
                if(len >= strs[i].length() || strs[i][len] != strs[0][len])
                    return strs[0].substr(0, len);
        return strs[0];
    }
    /**
     * 最大子序和
     * @param nums
     * @return
     */
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        if(nums.size() == 0) return sum;
        sum = nums[0];
        if(nums.size() == 1) return nums[0];
        for(int i = 0; i < nums.size(); i++) {
            int total = 0;
            for(int j= i; j < nums.size(); j++) {
                total += nums[j];
                if(total <= sum)continue;
                sum = total;
            }
        }
        return sum;
    }







}

#endif //DATASTRUCT_LEECODE_H
