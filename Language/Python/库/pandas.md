<!--
 * @Brief        : 
 * @Author       : dmjcb
 * @Date         : 2022-01-28 20:34:49
 * @LastEditors  : dmjcb@outlook.com
 * @LastEditTime : 2024-09-28 14:37:15
-->

# pandas

## 读取网页中表格

```py
import pandas as pd

url='http://www.kuaidaili.com/free/'

# [0]: 表示第一个table, 多个table需要指定, 如果不指定默认第一个
df = pd.read_html(url)[0] 
```

## 下载表格

```py
import pandas as pd

url='http://192.168.1.36:5000/data'

# [0]: 表示第一个table, 多个table需要指定, 如果不指定默认第一个

df = pd.read_html(url, encoding='utf-8', header = 0)[0]
df.to_excel('xian_tianqi.xlsx', index = False)
```
