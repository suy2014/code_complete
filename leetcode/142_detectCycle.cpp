/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *point_first = head;
        ListNode *point_second = head;
        int find = 0;

        if (head == NULL ) {
            return NULL;
        }

        while ((point_second->next != NULL ) && (point_second->next->next != NULL)) {
            point_first = point_first->next;
            point_second = point_second->next->next;
            if ( (point_second == point_first)) {
                find = 1;
                break;
            }
        }
        if (find) {
            point_second = head;
            while (point_second != point_first) {
                point_first = point_first->next;
                point_second = point_second->next;
            }

            return point_second;
        }

        return NULL;
    }
};
