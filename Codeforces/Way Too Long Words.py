tc = int(input())
while tc > 0:
    tc -= 1
    word = input()
    if len(word) <= 10:
        print(word)
    else:
        print(word[0] + str(len(word) - 2) + word[-1])


