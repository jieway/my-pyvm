import tokenize

f = open("test_token.txt")
tk = tokenize.generate_tokens(f.readline)

for toknum , tokvalue, _, _,_ in tk:
    print(toknum,tokvalue)