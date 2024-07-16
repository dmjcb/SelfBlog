<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:  
 * @Date: 2021-02-04 23:48:41
 * @LastEditors: dmjcb
 * @LastEditTime: 2024-07-07 02:02:37
-->

# Docker部署SQLServer

## 部署

```sh
# 用户名 SA
# 密码 dmjcb@13546!
docker run -itd                   \
    -e "ACCEPT_EULA=Y"            \
    -e "SA_PASSWORD=dmjcb@13546!" \
    -p 1433:1433                  \
    --name sqlserver2019          \
    registry.cn-hangzhou.aliyuncs.com/vex/sqlserver:v1
```

## 命令

### 进入

```sh
/opt/mssql-tools/bin/sqlcmd -S localhost -U SA -P "dmjcb@13546!"
```

### 显示所有数据库

```sql
SELECT Name FROM Master..SysDatabases ORDER BY Name
GO
```

![](/.imgur/2020-10-21_11-05-13.jpg)

### 显示表

```sql
SELECT * FROM [表名]
GO
```

![](/.imgur/2020-10-12_13-09-31.jpg)

别忘记输入`GO`, 那样才会执行命令(反人类的SQLServer)

## Python 交互

### 连接

![](/.imgur/20201012105710.png)

注意:反人类的SQLServer的主机地址需写为: `ip, 端口`, 注意是`逗号`

![](/.imgur/20201012130100.png)

```py
import pymssql

conn = pymssql.connect(
    host = IP:端口,
    user = "sa",
    password = 密码,
    database = 数据库,
    charset = 'utf8'
)

# 使用cursor()方法获取操作游标
cursor = conn.cursor()

sql = "SELECT * FROM 表"

try:
    # 执行SQL语句
    cursor.execute(sql)
    results = cursor.fetchall()
except:
    ...

# 关闭数据库连接
conn.close()
```

![](/.imgur/20201012180210.png)