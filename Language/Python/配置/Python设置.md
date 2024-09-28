<!--
 * @Brief        : 
 * @Author       : dmjcb
 * @Date         : 2021-08-19 23:44:15
 * @LastEditors  : dmjcb@outlook.com
 * @LastEditTime : 2024-09-28 14:40:03
-->

# Python设置

## 换源

```sh
python -m pip install -i http://mirrors.aliyun.com/pypi/simple/ --trusted-host mirrors.aliyun.com --upgrade pip
```

```sh
pip config set global.index-url http://mirrors.aliyun.com/pypi/simple
```

## 生成requestment

```sh
pip freeze > requirements.txt
```

## 虚拟环境

### 激活

```sh
source venv/bin/activate
```

### 退出

```sh
deactivate
```