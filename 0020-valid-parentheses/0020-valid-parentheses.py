class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        for x in s:
            if x == "}" or x == ")" or x == "]":
                if len(stack) == 0:
                    return False
                if x == "}":
                    if stack[-1] == "{":
                        stack.pop()
                    else:
                        return False
                if x == "]":
                    if stack[-1] == "[":
                        stack.pop()
                    else:
                        return False
                if x == ")":
                    if stack[-1] == "(":
                        stack.pop()
                    else:
                        return False
            else:
                stack.append(x)

        if len(stack) > 0:
            return False

        return True
