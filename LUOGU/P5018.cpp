////
//// Created by GreenArrow on 2020/3/7.
////
//#include <iostream>
//#include <map>
//#include <cstdio>
//
//#define MAX 1000100
//using namespace std;
//
//
//typedef struct treeNode {
//    int val;
//    struct treeNode *left;
//    struct treeNode *right;
//    bool flag = true;
//} *TreeNode, treeNode;
//
//int leftOrRight(TreeNode left, TreeNode right);
//
//
//int isSymmetry(TreeNode root) {
//    if (root) {
//        return leftOrRight(root->left, root->right);
//    } else
//        return 0;
//}
//
//int leftOrRight(TreeNode left, TreeNode right) {
//    if (!left && !right) {
//        return 1;
//    } else if ((left && !right) || (!left && right) || left->val != right->val)
//        return -1;
//    else {
//        int leftNum = leftOrRight(left->left, left->right);
//        if (leftNum == -1) {
//            return -1;
//        }
//        int rightNum = leftOrRight(right->left, right->right);
//        if (rightNum == -1) {
//            return -1;
//        }
//        return leftNum + rightNum + 1;
//    }
//}
//
//
//int main() {
//
//    int target[MAX];
//    map<int, TreeNode> treeNode_map;
//    int n;
//    scanf("%d", &n);
//    for (int i = 1; i <= n; ++i) {
//        scanf("%d", &target[i]);
//        TreeNode u = new treeNode;
//        u->val = target[i];
//        u->left = u->right = nullptr;
//        treeNode_map[i] = u;
//    }
//
//    for (int j = 1; j <= n; ++j) {
//        int left, right;
//        scanf("%d %d", &left, &right);
//        TreeNode cur = treeNode_map[j];
//        if (left != -1) {
//            cur->left = treeNode_map[left];
//            treeNode_map[left]->flag = false;
//        }
//        if (right != -1) {
//            cur->right = treeNode_map[right];
//            treeNode_map[right]->flag = false;
//        }
//    }
//
//    TreeNode root = nullptr;
//    for (int k = 1; k <= n; ++k) {
//        if (treeNode_map[k]->flag) {
//            root = treeNode_map[k];
//            break;
//        }
//    }
//
//    int number = 0;
//
//    for (int l = 1; l <= n; ++l) {
//        if (number < isSymmetry(treeNode_map[l])) {
//            number = isSymmetry(treeNode_map[l]);
//        }
//    }
//
//
//    cout << number;
//}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>

using namespace std;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

int n, son[1000050][2], val[1000050], size[1000050];


inline void dfs(int u) {
    size[u] = 1;
    if (son[u][0] != -1) {
        dfs(son[u][0]);
        size[u] += size[son[u][0]];
    }
    if (son[u][1] != -1) {
        dfs(son[u][1]);
        size[u] += size[son[u][1]];
    }
}

inline bool check(int u, int v) {
    if (u == -1 && v == -1)
        return true;
    return u != -1 && v != -1 && val[u] == val[v] &&
           check(son[u][0], son[v][1]) &&
           check(son[u][1], son[v][0]);
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++)
        val[i] = read();
    for (int i = 1; i <= n; i++) {
        son[i][0] = read();
        son[i][1] = read();
    }
    dfs(1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (check(son[i][0], son[i][1]))
            ans = max(ans, size[i]);
    cout << ans << endl;
    return 0;
}