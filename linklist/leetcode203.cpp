/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
/* 给你一个链表的头节点 head 和一个整数 val ，
   请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* res=head;
        ListNode* prev=nullptr;
        while (head) {
            if (head->val==val) {
                if (prev) {
                    prev->next=head->next;
                    head=head->next;
                }else {
                    head=head->next;
                    res=head;
                }
            }else {
                prev=head;
                head=head->next;
            }
        }
        return res;
    }
};