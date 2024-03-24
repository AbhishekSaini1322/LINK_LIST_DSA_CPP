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
     ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        // Find the middle of the linked list
        ListNode* mid = findMid(head);

        // Reverse the second half of the linked list
        ListNode* reversedSecondHalf = reverseList(mid->next);

        // Compare the first half with the reversed second half
        ListNode* p1 = head;
        ListNode* p2 = reversedSecondHalf;
        while (p2 != nullptr) {
            if (p1->val != p2->val)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }

        return true;
    }
};





























// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:

//     ListNode* findMid(ListNode* head){
//         ListNode* slow = head;
//         ListNode* fast = head;
//         while(fast->next != NULL){
//             fast = fast->next;
//             if(fast->next != NULL){
//                 fast = fast->next;
//                 slow = slow->next;
//             }
//         }
//         return slow;
//     }

//     bool checkPalidrome(ListNode* head1,ListNode* head2){
//         while(head1 != NULL && head2 != NULL){
//             if(head1 != head2){
//                 return false;
//             }
//             else{
//                 head1 = head1->next;
//                 head2 = head2->next;
//             }
//         }
//         return true;
//     }

//     bool isPalindrome(ListNode* head) {
//         // break into two parts
//         // find mid
//         ListNode* mid = findMid(head);
//         ListNode* head2 = mid->next;
//         mid->next = NULL;

//         ListNode* prev = NULL;
//         ListNode* curr = head2;
//         while(curr != NULL){
//             ListNode* next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }
//         head2 = prev;

//         bool ans = checkPalidrome(head,head2);
//         return ans;

//     }
// };
