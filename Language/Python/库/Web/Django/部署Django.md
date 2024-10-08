<!--
 * @Brief        : 
 * @Author       : dmjcb
 * @Date         : 2021-02-03 13:54:04
 * @LastEditors  : dmjcb@outlook.com
 * @LastEditTime : 2024-09-28 14:33:13
-->

# 部署Django

# uwsgi部署

建立项目mysite

```sh
django-admin.py startproject mysite

python manage.py runserver 0.0.0.0:8000
```

## 配置

### uwsgi

```ini
[uwsgi]

socket = 127.0.0.1:8000

# 启动主进程, 来管理其他进程
master = true

# 开启的进程数量
processes = 2

# 运行线程
threads = 8

# 设置用于uwsgi包解析的内部缓存区大小为64k.默认是4k
buffer-size = 32768
```

### nginx

```sh
server {
    listen 80;
    server_name localhost;
    location / {
        include  uwsgi_params;
        
        # 必须和 uwsgi中的设置一致
        uwsgi_pass  127.0.0.1:8000;
        
        # 入口文件, 即wsgi.py相对于项目根目录的位置, "."相当于一层目录
        uwsgi_param UWSGI_SCRIPT /mysite/mysite.wsgi;
        
        # 项目根目录
        uwsgi_param UWSGI_CHDIR /mysite;
        index  index.html index.htm;
        client_max_body_size 35m;
    }
}
```