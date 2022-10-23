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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow, *fast;
        slow = head;
        fast = head;
      
      int i = 0; 
      while( i < n) {
        fast = fast->next;
        i++;
      }
      
      if (fast == NULL)
      {
         head = slow->next;
         return head; 
      }
      
      while (fast != NULL) {
        
        if (fast->next == NULL) {
          slow->next = slow->next->next;
        }
        
        slow = slow->next;
        fast = fast->next;

      }
      
      return head;
    }
};