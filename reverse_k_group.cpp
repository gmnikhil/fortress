#include<iostream>
#include<deque>

using namespace std;
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        deque<ListNode*>s;
        int i=0;
        ListNode* iter = head;
        ListNode* ans = nullptr;
        ListNode* jiter = nullptr;
        while(iter!=nullptr || i%k==0) {
            if(i%k == 0 && i>0) {
                ListNode* x = s.back();
                s.pop_back();
            
                if(ans == nullptr) {
                    ans = x;
                    jiter = ans;
                }
                else {
                    jiter->next = x;
                    jiter = jiter->next;
                }
                while(!s.empty()) {
                    ListNode* y = s.back();
                    s.pop_back();
                    jiter->next = y;
                    jiter = jiter->next;
                }
                if(iter == nullptr) break;
                s.push_back(iter);
            } else {
                s.push_back(iter);
            }
            iter = iter->next;
            i++;
        }
        
        while(!s.empty()) {
            ListNode* y = s.front();
            s.pop_front();
            jiter->next = y;
            jiter = jiter->next;
        }
        jiter->next = nullptr;
        return ans;
    }
};