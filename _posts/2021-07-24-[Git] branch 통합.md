---
layout: post
title: "[Git] Branch 통합 (merge, rebase)"
date: 2021-07-24 18:13:00 +0900
category: Git
---

브랜치 통합에는 두가지의 방법이 있다.
- merge
- rebase
---
## 1. merge
### fast-forward merge
<img width="450" alt="스크린샷 2021-07-24 오후 6 13 37" src="https://user-images.githubusercontent.com/75327385/126863842-b0d62a8b-8088-496f-8a75-216a6f9ed155.png">
<img width="499" alt="스크린샷 2021-07-24 오후 6 14 22" src="https://user-images.githubusercontent.com/75327385/126863872-697d67fd-fd12-4318-ac39-26c4ed2f4793.png">

- 작업한 branch가 master에서 분기한 bugfix이고, master branch의 변경사항이 없을 경우, 그대로 master branch가 bugfix로 이동하여 내용이 적용된다.
- 이같은 방법은 **fast-forward(빨리감기) 병합** 이라고 부른다. 

---
### merge commit
<img width="449" alt="스크린샷 2021-07-24 오후 6 20 49" src="https://user-images.githubusercontent.com/75327385/126864076-3c1bdefa-dfd2-4125-9b53-75e4400164ab.png">
<img width="576" alt="스크린샷 2021-07-24 오후 6 21 52" src="https://user-images.githubusercontent.com/75327385/126864104-0443c16e-fb81-4721-8227-ba9dec6c5f40.png">
- 하지만 bugfix 분기 이후, master branch에 변경사항이 있을 경우, master branch의 변경내용과 bugfix branch의 변경내용을 통합할 필요가 있다.

- 이럴 때, 양 쪽의 변경사항을 병합하는 **merge commit (병합커밋)** 을 실행한다.

- master branch로 통합이 된다. 
---
## 2. rebase
<img width="449" alt="스크린샷 2021-07-24 오후 6 20 49" src="https://user-images.githubusercontent.com/75327385/126864076-3c1bdefa-dfd2-4125-9b53-75e4400164ab.png">
<img width="598" alt="스크린샷 2021-07-24 오후 6 26 49" src="https://user-images.githubusercontent.com/75327385/126864244-b7fc0c12-8b57-4ca3-a03a-16fa48e19fe5.png">

- 위와 동일한 상황에서,
bugfix branch를 master branch에 **rebase** 하면, bugfix branch의 이력이 master branch 뒤로 이동하게 되어, 하나의 줄기로 연결되게 된다. 
<img width="603" alt="스크린샷 2021-07-24 오후 6 27 27" src="https://user-images.githubusercontent.com/75327385/126864257-5e1044c6-6a41-416d-85a7-6cc3cdb78da3.png">
- 이 때 이동하게 되는 bugfix branch의 이력들이 master branch의 커밋된 버전과 충돌한다면, 발생한 충돌을 수정해야 한다. 

---
### after rebase
<img width="601" alt="스크린샷 2021-07-24 오후 6 27 54" src="https://user-images.githubusercontent.com/75327385/126864267-47d36680-b8b3-4129-904c-ca74653b3971.png">

- rebase만 하게 된다면, 그림처럼 master의 위치는 그대로 유지된 채 뒤에 bugfix 이력들이 이어붙은 상태가 된다. 그 상태에서 master branch의 위치를 변경하고 싶다면, merge를 사용하여 fast-foward 병합을 하면 된다. 

```
merge 와 rebase 는 통합 브랜치에 토픽 브랜치를 통합하고자 하는 목적은 같으나, 그 특징은 약간 다릅니다.

- merge
변경 내용의 이력이 모두 그대로 남아 있기 때문에 이력이 복잡해짐.

- rebase
이력은 단순해지지만, 원래의 커밋 이력이 변경됨. 정확한 이력을 남겨야 할 필요가 있을 경우에는 사용하면 안됨.

merge 와 rebase 는 팀 운용 방침에 따라 구별해 쓸 수 있습니다.
예를 들어 이력을 하나로 모두 모아서 처리하도록 운용한다고 치면 아래와 같이 구별해 사용할 수 있습니다.

- 토픽 브랜치에 통합 브랜치의 최신 코드를 적용할 경우에는 rebase 를 사용,
- 통합 브랜치에 토픽 브랜치를 불러올 경우에는 우선 rebase 를 한 후 merge
```

---
<a href="https://backlog.com/git-tutorial/kr/stepup/stepup1_4.html" download>branch 병합 참고</a>

<a href="https://velog.io/@godori/Git-Rebase" download>rebase 참고</a>
