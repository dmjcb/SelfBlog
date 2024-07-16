<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:  
 * @Date: 2022-01-01 17:20:15
 * @LastEditors: dmjcb
 * @LastEditTime: 2023-04-16 23:41:00
-->

# url_for


## 返回静态文件

```js
<link rel="stylesheet" href="{{ url_for('static', filename='bootstrap.min.css') }}">


<script src="{{ url_for('static', filename='jquery.min.js') }}"></script>
```


## 动态路由

```html
<a href="{{ url_for('test', name=1) }}">点击这里查看</a>
```

```py
@app.route('/index/<name>', methods=['GET'])
def test(name):
    return name
```

![](/.imgur/20211001235447.png)