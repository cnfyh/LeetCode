struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

//给你一个链表，删除链表的-倒数-第 n 个结点，并且返回链表的头结点。
/*
 链表中结点的数目为 sz
 1 <= sz <= 30
 1 <= n <= sz 
*/
/*  用步长=n来控制 */
class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) {
            return nullptr;
        }
        ListNode* cur=head;
        if (n==1) {
            while (cur->next->next) {
                cur=cur->next;
            }
            cur->next=nullptr;
            return head;
        }
        ListNode dunmy(0,head);
        ListNode* delpre=&dunmy;
        for (int i=n; i>1; i--) {
            cur=cur->next;
        }
        while (cur->next) {
            cur=cur->next;
            delpre=delpre->next;
        }
        if (delpre==&dunmy) {
            return head->next;
        }
        delpre->next=delpre->next->next;
        return head;
    }
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // fast 先走 n+1 步，这样当 fast 到 nullptr 时，slow 在待删节点的前驱
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        return dummy.next;
    }
};