---
layout: post
title: "[Java] JavaPractice06. interface"
date: 2021-10-13 11:13:00 +0900
category: java
---
[자바 입문 과정 과제_6.pdf](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/ca438ff5-b14d-4a7f-8792-9f83372837e8/%EC%9E%90%EB%B0%94_%EC%9E%85%EB%AC%B8_%EA%B3%BC%EC%A0%95_%EA%B3%BC%EC%A0%9C_6.pdf?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20211024%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20211024T145006Z&X-Amz-Expires=86400&X-Amz-Signature=8b6d7c8d5cc38e8a94e81749d74e3dbc5501997ab1f9d49027e2bc3b67e36345&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22%25EC%259E%2590%25EB%25B0%2594%2520%25EC%259E%2585%25EB%25AC%25B8%2520%25EA%25B3%25BC%25EC%25A0%2595%2520%25EA%25B3%25BC%25EC%25A0%259C_6.pdf%22)

# 인터페이스

## 인터페이스란 무엇인가?

- 인터페이스는 추상 메서드로만 구현되어있다 (구현코드가 없다.) `public abstract`
    - java8으로 넘어오면서는 인터페이스에 구현코드가 조금 들어오게 되었다.
    - public abstract 키워드를 넣지 않아도 모든 메서드가 public abstract로 컴파일된다.

## 인터페이스에 선언된 변수는?

- 모든 변수는 상수로 선언된다 `public static final`
    - 추상클래스에는 안에 변수를 선언해도 나중에 그 변수를 인스턴스화될 때 멤버변수로 쓰이지만, 인터페이스는 구현코드가 없기때문에 그 안에 멤버변수를 가질 수 없다. 따라서 인터페이스에 선언된 변수는 모두 상수화된다.
    - 아무것도 쓰지 않더라도 저 키워드가 넣어짐. (pre-compile 단계에서 자동으로 추가됨.)

```java
interface 인터페이스이름{
	public static final float po = 3.14F;
	public void makeSomething();
}
```

## 인터페이스 정의와 구현

![image](https://user-images.githubusercontent.com/75327385/138599425-cec60795-0871-45f9-8573-a2f59aefb6fa.png)

- 문법: `[class name] implements [interface name]`
- "인터페이스를 어떤 클래스가 구현한다" 라고 얘기한다. (상속과 다른 개념)
    - 상속은 구현된 코드를 상속받는 것이고, 인터페이스는 구현코드가 없는 상태에서 class가 인터페이스를 구현한다.
    - 다이어그램에서 점선표시
- "type 상속을 했다" 라고 얘기한다. ?^^.. 구현 상속과 다르다.
    - "CompleteCalc 클래스가 Calc인터페이스 타입이다"
- *자바에서 클래스간의 상속은 single inheritance만 가능하다. (여러 개의 클래스를 다중상속 할 수 없다.) ~~뭔말인 지 모르겠다.~~*
    - 하지만 인터페이스는 구현코드가 없기 때문에 여러 인터페이스를 구현할 수 있다.
- 예제
    
    ```java
    public interface Calc {
        double PI = 3.14;
        int ERROR = -99999;
    
        int add(int num1, int num2);
        int substract(int num1, int num2);
        int times(int num1, int num2);
        int divide(int num1, int num2);
    
    }
    ```
    
    ```java
    public abstract class Calculator implements Calc{ // 일부만 구현하기때문에 abstract
        @Override
        public int add(int num1, int num2) {
            return num1 + num2;
        }
    
        @Override
        public int substract(int num1, int num2) {
            return num1 - num2;
        }
    }
    ```
    
    ```java
    public class CompleteCalc extends Calculator{
        @Override
        public int times(int num1, int num2) {
            return num1 * num2;
        }
    
        @Override
        public int divide(int num1, int num2) {
            return num1 / num2;
        }
    }
    public void showInfo() {
            System.out.println("모두 구현했습니다.");
        }
    ```
    

### 인터페이스 구현과 형변환

- **`type상속`** : 인터페이스를 구현한 클래스는 인터페이스 형으로 선언한 변수로 형변환할 수 있다. (위 예제에서 CompleteCalc 클래스가 Calc인터페이스 타입으로 선언되었다.)
    
    ```java
    Calc calc = new CompleteCarlc();
    ```
    
- 상속에서의 형변환과 동일한 의미.
- 클래스 상속과 달리 구현 코드가 없으므로 여러 인터페이스를 구현할 수 있음 (참고. extends)
- 형변환 되는 경우 인터페이스에 선언된 메서드만을 사용가능함.
    
    ![image](https://user-images.githubusercontent.com/75327385/138599450-5aa5edd6-3a0f-4fdc-9173-476e7aaf1089.png)
    

### 인터페이스는 왜 쓰는가?

- 인터페이스, TV와 사람을 연결하는 통로인 리모컨 - 어떠한 연결점을 "인터페이스"라고 한다.
- 자바에서 인터페이스는 코드. 코드가
- 인터페이스가 하는 일
    - 클래스나 프로그램이 제공하는 기능을 명시적으로 선언 (객체가 어떤 기능을 제공하는 지 명세해놓은 것)
    - 일종의 클라이언트 코드와의 약속이며, 클래스나 프로그램이 제공하는 명세(sepcification)이다. 일종의 계약서
    - 클라이언트 프로그램은 인터페이스에 선언된 메서드 명세만 보고 이를 구현한 클래스를 사용할 수 있음.
    - 어떤 객체가 하나의 인터페이스 타입이라는 것은 그 인터페이스가 제공하는 모든 메서드를 구현했다는 의미임.
    - 인터페이스를 구현한 다양한 객체를 사용함 (다형성)
    - 예) JDBC 인터페이스 Interface Connection ~~무슨말일까^^....~~
    - 어찌됐든... 대략 클라이언트는 인터페이스에 명세된 대로 쓴다는 얘기인듯.

# 인터페이스와 다형성

![image](https://user-images.githubusercontent.com/75327385/138599487-a6c908d5-9d91-45d4-8a43-50cb542523cb.png)
- 하나의 인터페이스를 여러 객체가 구현하게 되면, 클라이언트 프로그램은 인터페이스의 메서드를 활용하여 여러 객체의 구현을 사용할 수 있다 (다형성)
- 여러 가지 예
    
    ![image](https://user-images.githubusercontent.com/75327385/138599504-4922772e-a0ab-4a51-acd9-de079ad60a12.png)
    

### 인터페이스를 활용한 dao (data access object)구현하기

![image](https://user-images.githubusercontent.com/75327385/138599514-0f65479d-8e9d-4304-ac72-565a0d33428b.png)
- 하나의 인터페이스 하위에 세가지 버전의 구현클래스를 두어 replace할 수 있도록 한다.
- 하나의 인터페이스를 활용하여 메서드를 호출하지만, 각자 다른 인스턴스가 돌아간다.
    - 똑같은 코드가 여러가지 implementation을 가지는, 다형성!
    - 실무에서 중요한 것은 이 인터페이스를 설계하는 것. 어떻게 설계해야 클라이언트 프로그램이 유용하게 쓸 수 있는가. *(~~주로 시니어 개발자들이 이런 설계를 함~~)*
- study 예제
    - 조건
        - DB에 회원 정보를 넣는 dao (data access object)를 여러 DB 제품이 지원될 수 있게 구현함
        - 환경파일 (db.properties)에서 database의 종류에 대한 정보를 읽고 그 정보에 맞게 dao 인스턴스를 생성하여 실행될 수 있게 함
        - source hierarchy는 다음과 같음
            
            ![image](https://user-images.githubusercontent.com/75327385/138599545-c0bad927-0508-4be4-80c2-116100887675.png)


# 인터페이스의 여러 요소들

### 상수

- 인터페이스에서 모든 변수는 상수로 변환된다. `public static final`
    
    ```java
    double PI = 3.14;
    int ERROR = -99999999;
    ```
    

### 추상 메서드

- 인터페이스에서 모든 메서드는 추상 메서드로 선언된다. `public abstract`

# 인터페이스에서의 구현메서드

### 디폴트메서드 default method (java 8 이후)

- 구현을 가지는 메서드, 인터페이스르 구현하는 클래스들에서 공통적으로 사용할 수 있는 기본 메서드.
    - 자바8 이후 인터페이스에도 구현코드가 추가되게 되었다.
    - 인터페이스를 구현하는 클래스들에서 같은 메서드를 중복으로 구현해야 하는 경우가 발생하니까, 디폴트 메서드가 새로 생김.
- `default` 키워드 사용
    
    ```java
    default void description() {
    	System.out.println("정수 계산기를 구현합니다.");
    	myMethod();
    }
    ```
    
- 인터페이스를 구현한 클래스의 인스턴스가 생성되어야 사용 가능하다.

### 디폴트메서드 재정의하기

- 구현 하는 클래스에서 디폴트 메서드를 재정의 할 수 있다.
    
    ```java
    @Override
    public void description() {
    	System.out.println("CompleteCalc에서 재정의한 default 메서드");
    	//super.description();
    }
    ```
    

### 정적 메서드 static method - 자바8 이후

- 인스턴스 생성과 상관없이 인터페이스 타입으로 사용할 수 있는 메서드 (클래스 정적 변수랑 같은 개념)
- default 메서드 vs static 메서드 차이
    - default는 그 인터페이스를 구현한 클래스가 인스턴스화 되었을 때 (new된 이후) 호출하여 사용할 수 있음
    - static은 클래스 정적 변수와 같이, 인스턴스 생성과 관계 없이 인터페이스 type으로 직접 사용할 수 있는 메서드이다.

### private 메서드 - 자바9 이후

- 구현 클래스에서 사용할 수도 없고, 재정의 할 수도 없는 private 메서드.
- 즉, 인터페이스 내부에서만 사용하기 위해 구현하는 메서드이다. 인터페이스 내부에 선언한다.
- default 메서드나 static 메서드에서 사용함.

# 여러 인터페이스의 구현

- 하나의 클래스에서 여러 인터페이스를 구현할 수 있다.
    
    ![image](https://user-images.githubusercontent.com/75327385/138599530-8657740f-d0a5-4f6a-b6d7-78950946b296.png)

    
- 자바의 인터페이스는 기본적으로 구현 코드가 없으므로, 하나의 클래스가 여러 인터페이스는 구현할 수 있다.
    - 클래스는 불가능함. 단일상속이다.
        - diamond problem
            
            ![image](https://user-images.githubusercontent.com/75327385/138599566-d2b5eb56-0eb4-4bc6-964b-a5d3317c2aff.png)

            
- 디폴트 메서드가 중복되는 경우는 구현하는 클래스에서 재정의해야 한다.
- 여러 인터페이스를 구현한 클래스는 인터페이스 타입으로 형변환되는 경우 해당 인터페이스에서 선언된 메서드만 사용 가능하다.
- 스터디질문
    - ~~자바에서 클래스는 단일 상속이지만, 인터페이스는 구현코드가 없으므로 여러 인터페이스를 하나의 클래스가 구현 할 수 있습니다. (다중상속 아님…)~~
    - Q) 두 인터페이스를 구현한 Customer 클래스가 각 Buy와 Sell로 형변환될때 어떻게 사용되는지?
        - 형변환 된 인터페이스에서 선언된 메서드만 사용 가능하다.
    - Q) default 메서드가 중복되는경우 Customer에서 어떻게 처리해야하는지?
        - 구현하는 Customer 클래스에서 default 메서드를 재정의해야 한다.

# 인터페이스간의 상속

![image](https://user-images.githubusercontent.com/75327385/138599582-c1e8f423-a587-4d92-93cf-08833c16935a.png)
```java
public interface X{
	void x();
}
public interface Y{
	void y();
}

public interface MyInerface extentds X, Y{ // 인터페이스를 상속한 인터페이스, 다중상속 가능
	void myMethod();
}
```

```java
public class MyClass implements MyInterface{ // 인터페이스 구현하는 클
	@Override
	public void x(){
		System.out.println("x()");
	}
	@Override
	public void y(){
		System.out.println("y()");
	}	
	@Override
	public void myMethod() {
		System.out.println("myMethod()");
	}
}
// 구현할 모든 인스턴스에 대하여 오버라이딩 해주어야 한다.
```

- 인터페이스간의 상속이 가능하다.
- 인터페이스는 다중 상속이 가능하고, 구현 코드의 상속이 아니므로, `타입 상속`이라고 한다.
- `extends` 키워드 사용
- ~~구현 상속이 아니므로 type상속이라고 함~~

# 인터페이스 구현과 클래스 상속 같이 사용하기

- 실무에서 프레임워크나 오픈소스와 함께 연동되는 구현을 하게 되면, 클래스 상속과 인터페이스의 구현을 같이 사용하는 경우가 많음.
- 둘 같이 사용할 경우, extends - implements 순서로 쓴다.
- 예제
    
    ![image](https://user-images.githubusercontent.com/75327385/138599610-2cc23957-85f1-4627-b29e-1100b1491807.png)
    - 조건
        - 책이 순서대로 대여가 되는 도서관 구현 (FIFO)
        - 책을 보관하는 자료구조가 Shelf에 구현됨 (ArrayList)
        - Queue 인터페이스를 구현함
        - Shelf 클래스를 상속 받고 Queue를 구현한다.

# Think about..

- 구현 코드도 없는 인터페이스는 왜 쓰는걸까요? ( 아래 그림을 보며 생각해보세요 )
    
    ![image](https://user-images.githubusercontent.com/75327385/138599585-075cb8bd-f841-4c9c-949e-b3e31ec54212.png)

- 인터페이스와 추상 클래스의 쓰임새의 차이는 무엇일까요? ( 추상 클래스도 구현코드 없이 메서드 선언만 하는 경우도 종종 있습니다. )
- => 어떤 경우 추상 클래스로 구현하여 상속을 하고, 어떤 경우에 인터페이스로 선언한것을 구현해야 할까요?

# Object Class 찾아보기

---

# 추가공부

### Try Catch

- Try-catch문은 예외를 처리하기 위한 구문이다.
- 구조
    
    ```java
    try {
    
    //예외 발생할 가능성이 있는 문장
    
    }catch(Exeption1 e1) {
    
    //Exception1이 발생했을 경우, 이를 처리하지 위한 문장적는다.
    //보통 이곳에 예외메세지를 출력하고 로그로 남김.
    
    }catch(Exeption2 e2) {
    
    //Exception2이 발생했을 경우, 이를 처리하지 위한 문장적는다.
    
    }catch(ExeptionN eN) {
    
    //ExeptionN이 발생했을 경우, 이를 처리하기 위한 문장을 적는다.
    
    }finally{
    
    //예외발생여부에 관계없이 상황 수행되어야 하는 문장을 적는다.
    
    }
    ```
    
    기본적인 try catch 구문의 구조이다.
    
    try 문에서 Exception 예외가 발생할 경우 catch (Exception e) 로 빠져서 그 안의 실행문을 실행한다.
    
    마지막의 finally블럭은 try-catch문과 함께 예외발생 여부과 관계없이 "항상. 무조건" 실행되어야할 코드를 적는다.
    
    필수는 아니며 마지막에 선택적으로 덧붙여 사용한다.
    
    예외 발생시 try->catch->finally 순으로,  발생 하지 않은 경우 try->finally 순으로 실행된다.
    
    [출처](https://cheershennah.tistory.com/147)
    
- 추상 - 동물 - 사람 새 고래
- 인터페이스 - walkable fly [interface]
    - 접근제어자 제한이 더 제한적이니까 추상클래스에서 더 자유롭게 쓸 수 있음.
- default 메소드는 암묵적으로 public (쓰지 않아도 public으로 처리된다.) default 메소드는 무조건 public으로 써야 한다.
- static 메서드는 무조건 public이며 생략할 수 있다.

---

### 10/13 스터디

- 추상클래스는 클래스와 클래스의 관계를 위해 존재
- 공통메서드를 상위에 두고, 위임할 클래스를 추상으로 둔다. 상속용으로 쓰겠다는 거

### 추상클래스와 인터페이스

- 다 abstract메서드만 있더라도 class hierarchy를 위해 존재하는 경우 추상클래스
    - class hierarchy 제공하는 개념
- 기능을 위해 존재하는 것이 interface
    - 기능을 정의한 개념.
- 인터페이스는 얘가 어떤 기능을 하는 애라고 정의를 해준다. 모듈의 상세 내용을 몰라도, 어떤 기능을 제공하는 지 명세해놓은다. 그걸 봄으로써 모듈의 기능을 아는 것.
- "스펙"이라고도 얘기함. 계약서같은 것.

---

## 이후 공부

- io stream
- 자바의 모든 입출력은 io stream으로 한다.