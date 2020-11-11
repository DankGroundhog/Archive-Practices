class Solution:
    def isValid(self, s: str) -> bool:
        
        paren_list = list()
        
        for i in range(len(s)):
            if s[i] == '(' or s[i] == '{' or s[i] == '[':
                paren_list.append(s[i])
                
            elif (len(paren_list) != 0):
                if s[i] == ')' and paren_list[len(paren_list)-1] == '(':
                    paren_list.pop()
                elif s[i] == '}' and paren_list[len(paren_list)-1] == '{':
                    paren_list.pop()
                elif s[i] == ']' and paren_list[len(paren_list)-1] == '[':
                    paren_list.pop()
                else:
                    return False
            else:
                return False
            
        return len(paren_list) == 0