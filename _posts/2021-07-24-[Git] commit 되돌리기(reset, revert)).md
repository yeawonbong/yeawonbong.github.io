---
layout: post
title: "[Git] Commit 되돌리기 (reset, revert)"
date: 2021-07-24 19:13:00 +0900
category: Git
---
*(작성중)*

commit 혹은 push했던 내용을 이전 상태로 되돌리려 할 때,
로컬의 commit만 한 경우는 **reset**으로 처리할 수 있지만, 원격 저장소까지 push가 된 경우는 **revert**를 사용해야 한다. 

## 1. reset

```
	git reset --hard <돌아갈 커밋>
```
	
```
	ex)
	$ git reset --hard aa7aa22967c96e01ee3b994b2e4e4f65d394cd64
```
- reset하고자 하는 커밋으로 돌아가서 해당 커밋 이후의 이력을 전부 삭제한다.
- 만약 reset --hard 후 다시 push를 하려 한다면, 원격 저장소의 커밋 히스토리보다 뒤에 있기 때문에(전에 있기때문에?) 오류가 발생한다. 이럴 때는 강제로 push -f 또는 push --force 옵션으로 강제 덮어쓰기 하면 된다.

```
	$ git reset --mixed <돌아갈 커밋>
```
- 변경 이력은 전부 삭제하지만, 변경된 내용은 unstage 상태로 남아있다. (git add 하지 않은 상태인 것)
- 이후 `git add`, `git commit`을 해주면 기존 상태로 돌아온다. 

```
	$ git reset --soft <돌아갈 커밋>
```
- 변경 이력은 전부 삭제하지만, 변경된 내용이 stage에 올라간 상태로 남아있다. (git add까지 한 상태인 것)
- 이후 바로 `git commit`으로 커밋을 진행할 수 있다. 

---
## 2. revert
- revert 기능은 특정 커밋을 되돌리는 작업을 하나의 커밋으로 간주하여 커밋 히스토리에 추가한다.
- 즉, 이력을 모두 그대로 두고, 뒤에 새로 커밋을 추가하는 것. 
```
	$ git revert <되돌릴 커밋 hash>
```
```
    ex)
    $ git revert aa7aa22967c96e01ee3b994b2e4e4f65d394cd64
```
만약 자동으로 커밋을 진행하고 싶지 않다면, **--no-commit** 옵션을 주면 된다.
```
	$ git revert --no-commit <되돌릴 커밋 hash>
```
---
<a href="https://brownbears.tistory.com/477" download>참고</a>
