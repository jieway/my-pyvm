import sys
import tokenize

class Token:
    def __init__(self, tok_num, tok_vale):
        self.tok_num = tok_num
        self.tok_vale = tok_vale

# 定义一个全局变量，方便保存操作
global current_token 

def current():
    global current_token
    return current_token

def next(tk):
    toknum, tokvalue, _, _, _ = tk.next()
    global current_token
    current_token = Token(toknum, tokvalue)

def expr(tk):
    s1 = term(tk)
    toknum = current().toknum
    tokvalue = current().tokvalue



# 当前模块代码的执行顺序，具体可参考：https://www.zhihu.com/question/49136398/answer/138164069
if __name__ == "__main__":
    # argv 是 sys 模块的一个全局变量
    # argv[0] 代码模块名， argv[1] 代表第一个参数，argv[2] 代表第二个参数，以此类推。
    # 具体可参考：https://blog.csdn.net/cadi2011/article/details/84638659
    f = open(sys.argv[1])
    # 词法分析
    tk = tokenize.generate_tokens(f.readline)

    next(tk)
    # print(expr(tk))