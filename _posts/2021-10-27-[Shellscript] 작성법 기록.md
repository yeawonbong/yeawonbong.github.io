---
layout: post
title: "[Shellscript] 작성법 기록"
date: 2021-10-27 11:54:00 +0900
category: shellscript
---

# #!/bin/bash 의미

- 스크립트 파일이 ***bash*** 쉘로 실행시킨다는 의미이다.
- `#!` : 스크립트의 제일 앞에서 이 파일이 어떤 명령어 집합인 지를 시스템에게 알려주는 역할. "magic number", 실행 가능한 쉘 스크립트라는 것을 나타내는 표시자이다.
- #! 뒤의 `경로`는 스크립트에 들어있는 명령어를 해석할 프로그램 위치를 나타낸다.
	```shell
	#!/bin/bash

	(내용..)

	exit 0
	```