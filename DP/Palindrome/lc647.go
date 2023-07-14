func countSubstrings(s string) int {
    // dp[i][j] 代表从i到j的回文子串数
    dp:=make([][]bool,len(s))
    ret := 0
    for i:=0;i<len(s);i++ {
        dp[i] = make([]bool, len(s))
        dp[i][i] = true
        ret ++
        if i<len(s)-1 && s[i]==s[i+1] {
            dp[i][i+1] = true
            ret ++
        }
    }
    for step:=3;step<=len(s);step++ {
        for i:=0;i<=len(s)-step;i++ {
            if s[i] == s[i+step-1] && dp[i+1][i+step-2] {
                dp[i][i+step-1] = true
                ret ++
            }
        }
    }
    return ret
}