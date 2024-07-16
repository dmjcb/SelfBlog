<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:  
 * @Date: 2021-11-13 19:15:39
 * @LastEditors: dmjcb
 * @LastEditTime: 2023-04-23 09:31:06
-->

# send_from_directory

## 返回静态文件

```py
send_from_directory('文件目录', 文件名)
```

```py
@app.route('/<path>')
def get_image(path):
    return send_from_directory('templates', path)
```

图片路径为/templates/a.jpg, 访问127.0.0.1:5000/a.jpg即返回静态文件

![](/.imgur/20211113191621.png)

![](/.imgur/2021-07-06_01-44-37.jpg)
