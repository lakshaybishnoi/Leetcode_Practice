class Solution {
public:
    int n;
    vector<string> res;
    bool isValid(string str) {
        if (str.length() > 1 && str[0] == '0')
            return false;
        int val = stoi(str);

        return val >= 0 && val <= 255;
    }

    void solve(int ind, int parts, string curr, string& s) {
        if (ind == n && parts == 4) {
            curr.pop_back();
            res.push_back(curr);
        }
        if (ind + 1 <= n) {
            solve(ind + 1, parts + 1, curr + s.substr(ind, 1) + ".", s);
        }
        if (ind + 2 <= n && isValid(s.substr(ind, 2))) {
            solve(ind + 2, parts + 1, curr + s.substr(ind, 2) + ".", s);
        }
        if (ind + 3 <= n && isValid(s.substr(ind, 3))) {
            solve(ind + 3, parts + 1, curr + s.substr(ind, 3) + ".", s);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if (s.length() > 12)
            return {};
        n = s.length();
        res.clear();
        string curr = "";
        int parts = 0;
        solve(0, parts, curr, s);
        return res;
    }
};