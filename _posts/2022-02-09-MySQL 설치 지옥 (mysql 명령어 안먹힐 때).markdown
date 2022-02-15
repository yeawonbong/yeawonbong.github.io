---
layout: post
title: "[MySQL] MySQL 설치 지옥 (mysql 명령어 안먹힐 때)"
date: 2022-02-09 23:59:00 +0900
category: mysql
---
### 명령 안먹힐때 (PATH 못찾을때.. 환경변수 설정 해주기)
```text
export PATH=/opt/homebrew/opt/mysql@5.7/bin:$PATH
```
- PATH 앞부분에 mysql 경로 넣어주는 것! 그 뒤에 환경변수 $PATH로 불러오니까, 앞에 이어붙이는 것이라 생각하면 됨. 경로에는 설치 시 나온 mysql PATH를 넣어준다. 

### 설치 시 안내 (path 참고)
``` c++
We've installed your MySQL database without a root password. To secure it run:
    mysql_secure_installation

MySQL is configured to only allow connections from localhost by default

To connect run:
    mysql -uroot

mysql@5.7 is keg-only, which means it was not symlinked into /opt/homebrew,
because this is an alternate version of another formula.

If you need to have mysql@5.7 first in your PATH, run:
  echo 'export PATH="/opt/homebrew/opt/mysql@5.7/bin:$PATH"' >> ~/.zshrc

For compilers to find mysql@5.7 you may need to set:
  export LDFLAGS="-L/opt/homebrew/opt/mysql@5.7/lib"
  export CPPFLAGS="-I/opt/homebrew/opt/mysql@5.7/include"


To restart mysql@5.7 after an upgrade:
  brew services restart mysql@5.7
Or, if you don't want/need a background service you can just run:
  /opt/homebrew/opt/mysql@5.7/bin/mysqld_safe --datadir=/opt/homebrew/var/mysql
```

### my.config 경로 찾기 
```
mysqld --verbose --help | grep -A 1 'Default options'
```
