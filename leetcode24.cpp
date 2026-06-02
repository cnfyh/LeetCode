 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
/* 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
   你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
 */
class Solution2 {
public:
      ListNode* swapPairs(ListNode* head) {
         if (head==nullptr||head->next==nullptr) {
            return head;
         }
         ListNode*cur=head;
         ListNode*next=head->next;
         ListNode temp(0,cur);
         ListNode* prev=&temp;
         head=head->next;
         while (true) {
            prev->next=next;
            cur->next=next->next;
            next->next=cur;
            if (cur->next&&cur->next->next) {
               prev=cur;
               cur=cur->next;
               next=cur->next;
            }else {
               break;
            }
         }
         return head;
         
    }
};
/* 对于上边代码的优化 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* cur = head;

        while (cur && cur->next) { //短路访问，&&左边为假直接返回，不会判断右边
            ListNode* next = cur->next;
            cur->next = next->next;
            next->next = cur;
            prev->next = next;

            prev = cur;
            cur = cur->next;
        }
        return dummy.next;
    }
};