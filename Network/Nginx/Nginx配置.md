<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:  
 * @Date: 2021-04-06 20:05:41
 * @LastEditors: dmjcb
 * @LastEditTime: 2022-07-19 22:16:31
-->

# Nginx

## 配置

### 安装

- docker容器中 nginx.conf 位置

```sh
/etc/nginx/nginx.conf
```

- Docker部署

```sh
docker run -itd -v $PWD/conf:/etc/nginx --net="host" nginx
```

### 命令

```sh
sudo systemctl status nginx

sudo systemctl start nginx

sudo systemctl stop nginx

sudo systemctl reload nginx
```

### IP 代理

```sh
server{
    listen 80;
    # 配置服务名, 若无特殊配置localhost即指代本机的127.0.0.1地址
    server_name localhost;
    # 将:80端口转发到:5000
    location / {
        proxy_pass http://127.0.0.1:5000;
    }
}
```

### 页面代理

```ini
server{
    listen 80;
    # 配置服务名, 若无特殊配置localhost, 即指代本机的127.0.0.1
    server_name localhost;
    location / {
        # 设置自定义文件的目录
        root /home/demo;
        # 设置自定义的首页文件
        index a.html a.htm;
    }
}
```

```sh
# 重新加载配置文件
nginx -s reload
```

终端显示`signal process started`时表明修改成功, 若有问题会提示错误

### 跨域

只需在Nginx的配置文件中配置以下参数

```sh
location / {  
    add_header Access-Control-Allow-Origin *;

    add_header Access-Control-Allow-Methods 'GET, POST, OPTIONS';
    
    add_header Access-Control-Allow-Headers 'DNT, X-Mx-ReqToken, Keep-Alive, User-Agent, X-Requested-With, If-Modified-Since, Cache-Control, Content-Type, Authorization';

    if ($request_method = 'OPTIONS') {
        return 204;
    }
} 
```

### 问题

Windows下可使用`host.docker.internal`指代宿主机的$localhost$ 地址

Linux下可使用`--net="host"`参数

## 实例

### 搭建图床

编辑/etc/nginx/nginx.conf

```sh
server {
    location ~ .*\.(gif|jpg|jpeg|png|jfif)$ {
        # 图片存放路径 
        root         
        autoindex    on
    location / {
        ...
    }
}
```
