class Solution(object):
def gcdOfStrings(self, str1, str2):

    def gcd(a, b):
        while b != 0:
            a, b = b, a % b
        return a
    

    if str1 + str2 != str2 + str1:
        return ""
    

    gcd_length = gcd(len(str1), len(str2))
    
    
    return str1[:gcd_length]
str1 = "ABCABC"
str2 = "ABC"
sr = Solution()
print(sr.gcdOfStrings(str1, str2))

str1 = "ABABAB"
str2 = "ABAB"
print(sr.gcdOfStrings(str1, str2))

str1 = "LEET"
str2 = "CODE"
print(sr.gcdOfStrings(str1, str2))