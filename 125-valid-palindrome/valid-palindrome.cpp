class Solution {
public:
    bool isPalindrome(string s) {
    /*
        - make empty string
        - loop over string
            - if not alnum char continue
            - else if isUpper then convert to lower and push
            - else push direct
        - end loop

        -init 2 pointers
            - p1 -> start string
            - p2 -> end string
        - loop over string
            - compare each pointer
            -   if not equal return false
            -   else equal then p1++ , p2--
        -end loop
        return true;
     */

    string res;
    for (char c : s) {
        if (!isalnum(c)) continue;
        else if (isupper(c)) res += tolower(c);
        else res += c;
    }

    int p1 = 0;
    int p2 = res.length() - 1;

    for (int i = 0; i < res.length(); i++)
    {
        if (res[p1] != res[p2]) return false;
        else p1++, p2--;
    }

    return true;
}
};