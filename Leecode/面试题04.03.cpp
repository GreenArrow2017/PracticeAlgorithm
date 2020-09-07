//
// Created by GreenArrow on 2020/7/26.
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

    class TreeNodeWithDepth {
    public:
        TreeNode *node;
        int Depth;
    };

public:
    vector<ListNode *> listOfDepth(TreeNode *tree) {
        vector<ListNode *> result;
        queue<TreeNodeWithDepth *> q;
        TreeNodeWithDepth *treeNodeWithDepth = new TreeNodeWithDepth;
        treeNodeWithDepth->node = tree;
        treeNodeWithDepth->Depth = 0;
        q.push(treeNodeWithDepth);
        while (!q.empty()) {
            TreeNodeWithDepth *current = q.front();
            q.pop();
            if (result.size() < current->Depth + 1) {
                ListNode *head = new ListNode(current->node->val);
                result.push_back(head);
            } else {
                add(result[current->Depth], current->node->val);
            }
            if (current->node->left) {
                TreeNodeWithDepth *treeNodeWithDepth = new TreeNodeWithDepth;
                treeNodeWithDepth->node = current->node->left;
                treeNodeWithDepth->Depth = current->Depth + 1;
                q.push(treeNodeWithDepth);
            }
            if (current->node->right) {
                TreeNodeWithDepth *treeNodeWithDepth = new TreeNodeWithDepth;
                treeNodeWithDepth->node = current->node->right;
                treeNodeWithDepth->Depth = current->Depth + 1;
                q.push(treeNodeWithDepth);
            }
        }
        return result;
    }

    void add(ListNode *head, int value) {
        ListNode *p = head;
        while (p->next != nullptr) {
            p = p->next;
        }
        ListNode *q = new ListNode(value);
        p->next = q;
    }
};