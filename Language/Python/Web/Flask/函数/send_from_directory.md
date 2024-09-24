<!--
 * @Brief        : 
 * @Author       : dmjcb
 * @Date         : 2024-09-10 02:06:37
 * @LastEditors  : dmjcb@outlook.com
 * @LastEditTime : 2024-09-24 19:44:13
-->
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

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/20211113191621.png)

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/2021-07-06_01-44-37.jpg)