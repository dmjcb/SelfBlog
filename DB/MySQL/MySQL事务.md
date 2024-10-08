<!--
 * @Brief        : 
 * @Author       : dmjcb@outlook.com
 * @Date         : 2021-01-16 17:59:35
 * @LastEditors  : dmjcb@outlook.com
 * @LastEditTime : 2024-10-08 19:38:23
-->

# MySQL事务

事务处理可以用来维护数据库的完整性, 保证 $SQL$ 语句要么全执行, 要么全不执行

事务用来管理 `INSERT`, `UPDATE`, `DELETE` 语句, 只有使用 $Innodb$ 数据库引擎的数据库或表才支持事务

## 特性

### 原子性 Atomic

一个事务中的全部操作, 要么全部都完成, 要么全部不完成.事务在执行过程中发生错误, 会被回滚(rollback)到事务开始前的状态

### 一致性Consistency

在事务开始之前和事务结束以后, 数据库的完整性没有被破坏, 表示写入的资料必须完全符合所有的预设规则, 这包含资料的精确度、串联性以及后续数据库可以自发性地完成预定的工作

### 隔离性 Isolation

隔离性可以防止多个事务并发执行时, 由于交叉执行而导致对数据进行读写和修改产生不一致的情况

```mermaid
graph LR;
    S(事务隔离级别)

    S-->A(读未提交<br>Read uncommitted)
    S-->B(读提交<br>Read committed)
    S-->C(可重复读<br>Repeatable read)
    S-->D(串行化<br>Serializable)
    S-->E(持久性<br>Durability)
```

事务处理结束后, 对数据的修改即是永久

## 控制

```mermaid
graph LR;
    S(操作指令)

    S-->A(事务开始)-->A1(BEGIN)
    S-->B(事务回滚)-->B1(ROLLBACK)
    S-->C(事务确认)-->C1(COMMIT)
```

### 开始

```sql
CREATE TABLE "info" (
    "id"   text NOT NULL, 
    "name" text, 
    PRIMARY KEY ("id")
);
```

```sql
BEGIN;

INSERT INTO info (id, name) VALUES ('000A-X', 'WANG-LI');

# 事务确认
COMMIT;
```

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/20200712233125.png)

### 回滚

```sql
BEGIN;

INSERT INTO info (id, name) VALUES ('000B-Y', 'QING-XU');

COMMIT;

BEGIN;

INSERT INTO info (id, name) VALUES ('000C-Z', 'SONG-LING');

# 回滚, 撤回插入
ROLLBACK;
```

可以看到第二条数据并未写入

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/20200712235320.png)

```sql
BEGIN;

DELETE FROM info WHERE id = '000B-Y';

# 回滚, 撤销删除
ROLLBACK;
```

数据没有被删除

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/20200713000345.png)