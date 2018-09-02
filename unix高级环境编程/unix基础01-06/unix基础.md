# unix 基础

## 1、unix基础知识

### 1、系统体系结构

操作系统可以定义为一种`软件`，我们通常称它为`内核`。

内核的接口称为`系统调用`，`公用库函数`在系统调用接口上，`应用程序`既可以使用公用库函数，也可以使用系统调用，`shell`是一个特殊的应用程序，是为其它应用程序提供接口。

### 2、登录

```bash
cat /etc/passwd

root:*:0:0:System Administrator:/var/root:/bin/sh
```

- 口令文件解释
  - 登录名 `root`
  - 加密口令 `*`
  - 数字用户ID `0`
  - 数字组ID `0`
  - 注释字段 `System Administrator`
  - 起始目录 `/var/root`
  - shell程序 `/bin/sh`

### 3、文件和目录

- 根 `/`