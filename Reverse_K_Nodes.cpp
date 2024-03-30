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

    int getlength(ListNode* head){

        ListNode* temp = head;
        int len = 0;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
       if(head == NULL){
           return head;
       }

       if(head == NULL){
           return head;
       }

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* Next = curr->next;

        int pos = 0;

        int length = getlength(head);

        if(length < k){
            return head;
        }

        while(pos<k){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
            pos++;
        }

        ListNode* recurisonkaans = NULL;

        if( Next != NULL){
            recurisonkaans = reverseKGroup(Next,k);
            head->next = recurisonkaans;
        }

        return prev;

        
    }
};
