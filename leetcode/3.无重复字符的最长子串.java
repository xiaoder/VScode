import java.util.HashSet;
import java.util.Set;

/*
 * @lc app=leetcode.cn id=3 lang=java
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int ans = 0;
        Set<Character> hs = new HashSet<Character>();
        int n = s.length();
        int r = -1;
        for(int i = 0; i < n; i++) {
            if(i != 0) {
                hs.remove(s.charAt(i - 1));
            }
            while (r + 1 < n && !hs.contains(s.charAt(r+1))) {
                hs.add(s.charAt(r+1));
                r++;
            }
            ans = Math.max(ans, r-i+1);
        }
        return ans;
    }
}
// @lc code=end

