 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
/*给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur=head;
        ListNode* prev=nullptr;
        while (cur) {
            if (cur->next) {
                ListNode*temp=cur->next;
                cur->next=prev;
                prev=cur;
                cur=temp;
            }else {
                cur->next=prev;
                break;
            }
        }
        return cur;
    }
};