import os
import pandas as pd
import numpy as np

# 查询当前目录下已经写好的文件
path='./day/'
#传入文件路径和后缀名称，返回列表
def getFile(path,suffix):           
    dir2_file=[]
    f_list = os.listdir(path)
    for i in f_list:
        if os.path.splitext(i)[1]  == suffix:
            dir2_file.append(i[:-4])
    return dir2_file
dir1 = os.listdir(path)
cpp_file=[]
for i in range(len(dir1)):
    path1=os.path.join(path,dir1[i])
    cpp_file=cpp_file + getFile(path1,'.cpp')
cpp_file
df=pd.read_csv("./目录.csv")
set1=set(list(df['题目']))
set2=set(cpp_file)
un_random=list((set1 | set2))

# 抽取题目
num=input('你今天要进行几道题目：')
lucknum=input('输入你今日的幸运数字：')
np.random.seed(int(lucknum))
num_list=np.random.randint(0,len(un_random),int(num))
print('计算完成！请完成如下{}道题目:'.format(int(num)))
[print(un_random[i]) for i in num_list]