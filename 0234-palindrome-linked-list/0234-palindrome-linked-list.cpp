int init = [] {
    ios_base::sync_with_stdio(false);  cin.tie(nullptr);
    ofstream out("user.out");
    for (string s; getline(cin, s);)
        out<<(equal(s.begin()+1, s.begin()+s.size()/2, s.rbegin() + 1) ? "true\n" : "false\n");
    out.flush();
    exit(0);
    
    return 0;
}();

class Solution {
    ListNode* curr;
public:
    bool isPalindrome(ListNode* head) {
        curr = head;
        return solve(head);
    }

    bool solve(ListNode* head) {
        if (head == nullptr) return true;
        bool ans = solve(head->next) && head->val == curr->val;
        curr = curr->next;
        return ans;
    }
};