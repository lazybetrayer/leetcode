// https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#if 1
// http://leetcode.com/2010/11/convert-sorted-list-to-balanced-binary.html

#else
ListNode *middleNode(ListNode *head, ListNode *tail) {
	if (head == NULL || head == tail || head->next == tail) {
		return head;
	}

	ListNode *fast = head, *slow = head;

	while (fast->next != tail && fast->next->next != tail) {
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
}

// 为了不破换单链表的结构，传入链表的结尾
TreeNode *sortedListToBST(ListNode *head, ListNode *tail) {
	if (head == NULL) {
		return NULL;
	}

	if (head->next == tail) {
		return new TreeNode(head->val);
	}

	ListNode *mid = middleNode(head, tail);
	ListNode *left = head, *right = mid->next;

	TreeNode *root = new TreeNode(mid->val);
	if (left != mid) {
		root->left = sortedListToBST(left, mid);
	}
	root->right = sortedListToBST(right, tail);

	return root;
}

TreeNode *sortedListToBST(ListNode *head) {
	return sortedListToBST(head, NULL);
}
#endif

void inorder(TreeNode *r) {
	if (r) {
		inorder(r->left);
		cout << r->val << endl;
		inorder(r->right);
	}
}

// http://leetcode.com/2010/11/convert-sorted-list-to-balanced-binary.html

int main(int argc, char const* argv[])
{
	ListNode *n1 = new ListNode(-10);
	ListNode *n2 = new ListNode(-3);
	ListNode *n3 = new ListNode(0);
	ListNode *n4 = new ListNode(5);
	ListNode *n5 = new ListNode(9);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	TreeNode *r = sortedListToBST(n1);
	inorder(r);
	return 0;
}
