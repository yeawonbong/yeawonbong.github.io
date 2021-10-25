---
layout: post
title: "[Java] JavaStudy_Ch05-10. ArrayList Practice"
date: 2021-10-25 11:13:00 +0900
category: java
---

### ArrayList

```java
import java.util.ArrayList;

---

private ArrayList<Member> arrayList;
```

- default capacity는 10이다. (size와는 다름)

```java
package ch10;

public class Member {

    private int memberId; //회원 아이디
    private String memberName; // 회원 이름

    public Member(int memberId, String memberName) { // 생성자
        this.memberId = memberId;
        this.memberName = memberName;
    }

    public int getMemberId() {
        return memberId;
    }

    public void setMemberId(int memberId) {
        this.memberId = memberId;
    }

    public String getMemberName() {
        return memberName;
    }

    public void setMemberName(String memberName) {
        this.memberName = memberName;
    }

    @Override
    public String toString() {
        return memberName + " 회원님의 아이디는 " + memberId + "입니다.";
    }
}
```

```java
package ch10;

import java.util.ArrayList;

public class MemberArrayList {

    private ArrayList<Member> arrayList;
    public MemberArrayList() {
        arrayList = new ArrayList<>();
    }
    public MemberArrayList(int size) {
        arrayList = new ArrayList<>(size);
    }

    public void addMember(Member member) {
        arrayList.add(member);
    }

    public boolean removeMember(int memberId) {
        for (int i=0; i<arrayList.size(); i++) {
            Member member = arrayList.get(i);

            int tempId = member.getMemberId();
            if (tempId == memberId) {
                arrayList.remove(i);
                return true;
            }
        }
        System.out.println(memberId + "가 존재하지 않습니다.");
        return false;
    }

    public void showAllMember() {
        for (Member member : arrayList) {
            System.out.println(member);
        }
        System.out.println();
    }
}
```

```java
package ch10;

public class MemberArrayListTest {

    public static void main(String[] args) {

        MemberArrayList memberArrayList = new MemberArrayList();
        Member memLee = new Member(1001,"이순신");
        Member memKim = new Member(1002,"김유신");
        Member memKang = new Member(1003,"강감찬");
        Member memHong = new Member(1004,"홍길동");

        memberArrayList.addMember(memLee);
        memberArrayList.addMember(memKim);
        memberArrayList.addMember(memKang);
        memberArrayList.addMember(memHong);

        memberArrayList.showAllMember();
        memberArrayList.removeMember(memKim.getMemberId());
        memberArrayList.showAllMember();

    }
}
```

출력

```
이순신 회원님의 아이디는 1001입니다.
김유신 회원님의 아이디는 1002입니다.
강감찬 회원님의 아이디는 1003입니다.
홍길동 회원님의 아이디는 1004입니다.

이순신 회원님의 아이디는 1001입니다.
강감찬 회원님의 아이디는 1003입니다.
홍길동 회원님의 아이디는 1004입니다.
```