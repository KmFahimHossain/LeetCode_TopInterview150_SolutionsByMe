def solution(s):
    newString = ""
    words = s.split()
    for i in range(len(words) - 1, -1, -1):
        if(i!=0):
            newString = newString + words[i] + " " 
    else:
        newString = newString + words[0]
    return newString

s = "  the sky is   blue  "
print(solution(s))
