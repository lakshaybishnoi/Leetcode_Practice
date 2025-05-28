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
    ListNode* deleteMiddle(ListNode* head) {
        int n =0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp=temp->next;

        }
        n = n/2;
        temp = head;
        ListNode* prev = nullptr;
        int count =0;
        if(head == nullptr || head->next==nullptr)return nullptr;
        while(temp!=nullptr){
            if(count == n){
                if(prev!=nullptr){
                    prev->next = temp->next;
                }else{
                    head = head->next;
                }
                break;
            }
            count++;
            prev = temp;
            temp = temp->next;
            
        }
    return head;}
};