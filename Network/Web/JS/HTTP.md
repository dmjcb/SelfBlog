<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:  
 * @Date: 2021-03-18 16:29:32
 * @LastEditors: dmjcb
 * @LastEditTime: 2024-07-06 23:43:30
-->

# JS用法

## HTTP

### GET

```js
function get(url, callback) {
    const XMLHttpRequest = require("xhr2")
    const httpRequest = new XMLHttpRequest()

    httpRequest.open("GET", url, true)
    httpRequest.send()
    httpRequest.onreadystatechange = () => {
        if (httpRequest.readyState == 4 && httpRequest.status == 200) {
            const json = httpRequest.responseText
            // ...
            callback()
        }
    };
}
```

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/2021-11-13_20-47-54.jpg)

### POST

```js
function post(url, data, callback){
    const XMLHttpRequest = require("xhr2")
    const httpRequest = new XMLHttpRequest()

    httpRequest.open('POST', url, true)
    httpRequest.setRequestHeader("Content-type", "application/json")
    // 转为JSON字符串
    httpRequest.send(JSON.stringify(data))
    httpRequest.onreadystatechange = ()=> {
        if (httpRequest.readyState == 4 && httpRequest.status == 200) {
            const result = httpRequest.responseText
            callback(result)
        }
    }
}
```
