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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                // yaha tak fast 2 step chl gya
                // ab slow ko ek step chla do
                slow = slow->next;
            }
        }
        return slow;
    }
};

// ------------------- SECOND APPORACH ----------------------------------------------------------


class Solution {
public:

    int getLength(ListNode* head){
        int count = 0;
        ListNode* temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode* middleNode(ListNode* head) {
        int len = getLength(head);
        int position = len/2+1;
        int currPosition = 1;
        ListNode* temp = head;
        while(currPosition != position){
            currPosition++;
            temp = temp->next;
        }
        return temp;
    }
};


