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
    string addBig(string a, string b) {
        if (b.size() > a.size()) swap(a, b);
        while (b.size() < a.size()) b = "0" + b;
        string res = "";
        int carry = 0;
        for (int i = (int)a.size() - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        res.push_back((sum % 10) + '0');
        carry = sum / 10;
        }
        if (carry) res.push_back(carry + '0');
        reverse(res.begin(), res.end());
        return res;
        }
    string extract(ListNode* l1){
        if(l1==nullptr)return "";
        string n1="";
        ListNode* temp=l1;
        while(temp!=nullptr){
            n1+=temp->val+'0';
            temp=temp->next;
        }
        reverse(n1.begin(),n1.end());
        return n1;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string num1=extract(l1);
        string num2=extract(l2);
        // cout<<num1<<":"<<num2<<endl;
        string ans=addBig(num1,num2);
        reverse(ans.begin(),ans.end());
        // cout<<ans<<endl;
        ListNode* head;
        ListNode* temp;
        for(int i=0;i<ans.size();i++){
            if(i==0){
                ListNode*newnode=new ListNode(ans[i]-'0');
                head=newnode;
                temp=head;
            }
            else{
                ListNode*newnode=new ListNode(ans[i]-'0');
                temp->next=newnode;
                temp=temp->next;
            }
        }
        return head;
    }
};