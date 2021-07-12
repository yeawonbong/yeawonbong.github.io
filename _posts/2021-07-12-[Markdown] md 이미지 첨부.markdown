---
layout: post
title: [Markdown] md 이미지 첨부
date: 2021-07-12 18:00:00 +0900
category: Markdown
---
<br/>
<br/>

## Markdown 언어에서 간단하게 이미지를 첨부하는 방법은

`![04.0.png](./img/04.0.java_process.png)`
<br/>(로컬 경로 혹은 이미지 주소를 넣으면 됨)

하지만 위 방법은 <u>**사이즈 조절을 못한다는 단점**</u>이 있다.
<br/>~~{: width="10%" height="10%"} 와 같은 문법은 더이상 사용이 안된다고 함~~ 
<br/>
<br/>

## 결론은.. HTML 문법으로 넣자.
`<img src="이미지 URL / 경로">`

<br/>그럼 이미지 **사이즈 조정** 가능하다.
<br/>`<img src="이미지 URL / 경로" width="100px">`
<br/>`<img src="이미지 URL / 경로" width="50%">`

<br/>**정렬**도 가능하다.
<br/>`<center><img src="이미지 URL / 경로" width="100px"></center>`
<br/><center><img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTc82HSA1rp5CZyoyQKXzK6VhhWN8hErihcIotr7B9f2QbNF6UzUfhTPnXezhOQ2z9zzGI&usqp=CAU" width="100px"></center>
<br/>`<img src="이미지 URL / 경로" width="100px" align="right">`
<br/><img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTc82HSA1rp5CZyoyQKXzK6VhhWN8hErihcIotr7B9f2QbNF6UzUfhTPnXezhOQ2z9zzGI&usqp=CAU" width="100px" align="right">
<br/>left도 동일하다. 
<br/>~~근데 왠지 모르지만 align="center"는 안된다. 흠..~~
<br/>
<br/>
<br/>
<br/>
<br/>
끝.