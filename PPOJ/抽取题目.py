import pandas as pd
import numpy as np
df=pd.read_csv("./目录.csv")
num=input('你今天要进行几道题目：')
lucknum=input('输入你今日的幸运数字：')
np.random.seed(int(lucknum))
num_list=np.random.randint(0,61,int(num))
print('计算完成！请完成如下{}道题目:'.format(int(num)))
[print(df.iloc[i,1]) for i in num_list]