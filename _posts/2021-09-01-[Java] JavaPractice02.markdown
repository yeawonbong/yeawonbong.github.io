---
layout: post
title: "[Java] JavaPractice02"
date: 2021-09-01 11:13:00 +0900
category: java
---
[자바 입문 과정 과제_2.pdf](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/1e17362c-43b5-44f8-87e6-72af71d39d30/자바_입문_과정_과제_2.pdf)

### 참조 자료형 변수

![image](https://user-images.githubusercontent.com/75327385/132973804-df98dcc7-d496-49fd-a22b-165abd1403bd.png)
- 클래스형으로 변수를 선언

### 객체협력 (cooperation)

---

## 접근 제어 지시자 (Access modifier)

- informaition hiding 기능, encapsulation이 구현된다.
- 클래스 외부에서 클래스의 변수, 메서드, 생성자 접근 권한을 지정하는 키워드
- 종류

    ![image](https://user-images.githubusercontent.com/75327385/132973829-40d473d6-4f7c-4f3a-be5e-753b88861e33.png)

    - `private`: 같은 클래스 내부에서만 접근할 수있다. (외부 클래스, 상속관계의 클래스에서도 접근 불가)
        - 외부에서 써야할 경우, `get()`/`set()`메서드로 접근한다.
            - eclipse - 우클릭 - Source - Generate Getters and Setters 
            (멤버변수에 대한 getter와 setter을 자동으로 생성해준다)
        - 수정할 수 있는 메서드를 public으로 제공
        - 객체의 직접 접근을 막기 때문에 더 안전하게. 오류를 막을 수있음. get이나 set에서 쓸데없는 데이터의 오용을 막아준다. 조건도 설정해주고. 디버깅하기에도 편하다. - 정보은닉
    - `default` (아무것도 없는 상태) : 같은 패키지 내부에서만 접근 가능 (상속 관계라도 패키지가 다르면 접근 불가)
    - `protected` : 같은 패키지나 상속관계의 클래스에서 접근 가능하고, 그 외의 외부에서는 접근불가
    - `public` : 클래스 외부 어디서나 접근 가능

## Encapsulation (캡슐화)

- 정보은닉보다 정보를 더 감싸서, 외부에 꼭 필요한 메서드 한두개만 오픈하고, 나머지는 자동으로 생성될 수 있도록 만드는 용도.
- 꼭 필요한 정보와 기능만 외부에 오픈한다.
- 대부분의 멤버 변수와 메서드를 감추고, 외부에 통합된 인터페이스만을 제공하여 일관된 기능을 구현하게 함.
- 각각의 메서드나 멤버 변수를 접근함으로써 발생하는 오류를 최소화한다.
- 클라이언트에서 쓸 수 있는 객체가 한정적이라 정보가 안전하다.

## this

- 현재 인스턴스 자신의 메모리를 가리킨다. (in heap)
- 생성자에서 또 다른 생성자를 호출할 때 사용
    - 클래스에 생성자가 여러 개인 경우, this를 이용하여 생성자에서 다른 생성자를 호출할 수 있음.
    - 생성자에서 다른 생성자를 호출하는 경우, 인스턴스의 생성이 완전하지 않은 상태이므로 this() statement 이전에 다른 statement를 쓸 수 없다. (주의할 점)
- 자신의 주소 (참조값)을 반환함.

---

스터디 내용

라이브러리 활용하기. 

유효성 검사하는 것 플래그를 두는 게 좋다.  (True로 시작했다가) 

- 인스턴스 변수는 0으로 초기화된다.

Readonly 하려면 setter을 안만들면 되는거다. 

---

[정리1](https://www.notion.so/2-0cd0f9dc7a4d48dfbee67f3b4e6fb3b6)

[정리2](https://www.notion.so/2-36ca4f325f354e09acaef277ae9dabdc)