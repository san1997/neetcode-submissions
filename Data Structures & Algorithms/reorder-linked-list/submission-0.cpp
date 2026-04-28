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

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* h = head;
        ListNode* sl;

        while (true) {
            sl = h;
            while (sl->next && sl->next->next) {
                sl = sl->next;
            }

            if (sl == h) {
                break;
            }

            ListNode* second = h->next;
            h->next = sl->next;
            h->next->next = second;
            sl->next = nullptr;
            h = h->next->next;
        }

    }
};
