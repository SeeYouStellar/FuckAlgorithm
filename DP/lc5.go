func longestPalindrome(s string) string {
    // dp[i][j]代表从下标i到下标j之间的串是否是回文串
 
    ret := string(s[0])  // 不管怎样每一个单独的字符都是一个回文子串
    dp := make([][]bool, len(s))
    for i:=0;i<len(s);i++ {
        dp[i] = make([]bool, len(s))
        dp[i][i] = true
        if i<len(s)-1 && s[i]==s[i+1] {
            dp[i][i+1] = true
            ret = string(s[i:i+2])	
        }
    }
    for i:=2;i<len(s);i++ {
        flag := false
        index := 0
        for j:=0;j<len(s)-i;j++ {
            if dp[j+1][j+i-1] == true && s[j] == s[j+i] {
                dp[j][j+i] = true
                flag = true
                index = j
            }
        }
        if flag {
            ret = string(s[index:index+i+1])
        }
    }
    return ret
}