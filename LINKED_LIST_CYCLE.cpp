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
    bool hasCycle(ListNode *head) {

        unordered_map<ListNode* ,bool> mapping;
        ListNode* temp = head;

        while(temp != NULL){
            // check karlo pehle aay hai ya nhi 
            if(mapping.find(temp) != mapping.end()){
                // cycle hai
                return true;
            }
            else{
                mapping[temp] = true;
            }
            temp = temp->next;
        }
        return false;

        // ListNode* slow = head;
        // ListNode* fast = head;

        // while( fast != NULL){
        //     fast = fast->next;
        //     if(fast != NULL){
        //         fast = fast->next;
        //         slow = slow->next;
        //     }
        //      if(fast == slow){
        //          return true;
        //         }
        // }
        // return false;

            // map<ListNode*,bool> table;

            // ListNode* temp = head;

            // while(temp != NULL){

            //     if(table[temp] == false){
            //         table[temp] = true;
            //     }
            //     else {
            //         return true;
            //     }
            //     temp = temp->next;
            // }
            // return false;
    }
};
