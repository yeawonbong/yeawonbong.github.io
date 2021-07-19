---
layout: post
title: "[Git] Branch 브랜치"
date: 2021-07-14 18:13:00 +0900
category: Git
---
~~*계속 덧붙이기*~~



## 로컬 브랜치
<a href="https://backlog.com/git-tutorial/kr/stepup/stepup2_5.html" download>참고</a>
- 브랜치 생성   


	```
	$ git branch <new_branchname>
	```
- 브랜치 전환
	```
	$ git checkout <branchname>
	```
- 브랜치 병합
	```
	$ git merge <병합할branchname>
	```

- 브랜치 삭제
	```
	$ git branch -d <branchname>

	same as

	$ git branch --delete <branchname>

	same as

	$ git 
	```

- 브랜치 이름 변경
	```
	$ git branch -m <old_branchname> <new_branchname>
	```
---


## 원격저장소 브랜치   
<a href="https://cjh5414.github.io/get-git-remote-branch/" download>참고</a>

- 원격저장소의 branch 목록 확인
	```
	$ git branch -r
	```
	```
	ybong@ybongui-MacBookPro minitalk % git branch -r
	origin/HEAD -> origin/master
	origin/debug
	origin/ex
	origin/master
	origin/new
	origin/ongoing
	```
	(원격+로컬 저장소의 모든 branch 목록 : git branch -a)

- 원격저장소 브랜치 가져오기
	```
	$ git checkout -t <branchname>
	```
	- branch 이름을 변경하여 가져오고 싶다면 
		```
		$ git checkout -b <생성할 branchname> <원격 저장소의 branchname>
		```

- 원격저장소 브랜치 생성
	```
	$ git push origin <new_branchname>
	```

- 원격저장소 브랜치 삭제
	```
	$ git push origin --delete <branchname>

	same as

	$ git push origin -d <branchname>

	same as

	$ git push origin :<branchname>
	```

- 브랜치 생성과 삭제를 한번에
	```
	$ git push origin :<old_branchname> <new_branchname>


- 원격저장소 브랜치 이름변경
	```
	$ git push 


---
## 로컬/원격 저장소의 브랜치 이름 변경 방법 정리

<a href="https://www.lainyzine.com/ko/article/how-to-rename-local-github-branch/" download>이름변경참고</a>

- 로컬 브랜치의 이름 변경은 git branch의 m 옵션을 사용힌디
	```
	$ git branch -m [OLD_BRANCH] [NEW_BRANCH]
	```

- GitHub나 원격 저장소의 변경은 git push를 사용한다.
	```
	$ git push origin new_branch
	$ git push origin --delete old_branch
	```
- old_branch를 삭제하고 new_branch 푸시를 한 방에 할 수도 있다.
	```
	$ git push origin :old_branch new_branch
	```