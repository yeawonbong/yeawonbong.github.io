---
layout: post
title: "[Java] JavaPractice03. static/Singleton Pattern/객체배열(shallow copy, deep copy)/enhanced for/javaDoc"
date: 2021-09-08 11:13:00 +0900
category: java
---
[자바 입문 과정 과제_3.pdf](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/5e72e254-5f9c-4cc4-b18c-3a5d9a47f676/자바_입문_과정_과제_3.pdf)

# static

### static 변수 (==클래스 변수, 정적변수)

- 여러 인스턴스에서 공통으로 사용하는 변수
    - 예) 학생에게 학번 부여, 회원번호 부여할 때
- 인스턴스 생성과 상관 없이 사용 가능하므로, 생성하지 않더라도, 클래스 이름으로 직접 참조가 가능하다.

    `Person.num = 001;`

    *~~(not PersonLee.num)~~*

### static 변수는 언제 생성되는가?

- 하드디스크에 프로그램을 구동시키면, 메모리에 올라가게 된다.
- 이 메모리에 올라갔을 때의 상태를 '프로세스'라고 한다. (thread상태로)
- 메모리에 올라갈 때 프로그램은 두가지 영역으로 나눌 수 있다.
    1. 코드영역
        - instruction set (명령어 집합)
    2. 데이터 영역 (static, 상수영역)
        - 상수, literal, static 변수가 여기에 올라간다.
- **static 변수는 처음에 프로그램이 메모리에 로딩되는 순간 Data영역에 올라가고, 프로그램 종료 시점에 없어진다.**
- (참고) instance가 생성될때마다 사용되는 메모리는 Heap메모리 (동적 메모리) - 사용 후 GC에 의해 수거가 된다.

### static 메서드 (==클래스 메서드)

- static 메서드 (클래스 메서드)에서는 인스턴스 변수를 사용할 수 없다.
    - static 메서드는 인스턴스 생성과 무관하게 클래스 이름으로 직접 호출될 수 있으므로, 인스턴스 생성 전에 호출될 수도 있다. 따라서 **static 메서드 내부에서는 인스턴스 변수를 사용할 수 없다**.

        `non-static variable employeeName cannot be referenced from a static context`

    - (클래스 메서드 함수 안의 지역변수는 사용 가능)

# 변수의 종류와 그 유효성

지역변수, 인스턴스변수, static 변수의 scope와 life cycle, 생성되는 메모리, 언제 소멸되는 지 등을 알아봅시다. 

- 변수의 scope와 life cycle은 각 변수의 종류마다 다르다. (지역변수, 멤버변수, 클래스 변수)
    - scope : 유효범위
    - life cycle : 변수가 언제 생성되어 언제 소멸하는 지

        ![image](https://user-images.githubusercontent.com/75327385/132973910-9c71ddfd-7ca3-40a7-a538-0c558871af33.png)

    - static 변수는 프로그램이 메모리에 있는 동안 계속 그 영역을 차지하므로, 너무 많은 변수를 할당하는 것은 좋지 않음.
    - 클래스 내부의 여러 메서드에서 사용하는 변수는 멤버변수로 선언하는 것이 좋다.
    - 멤버 변수가 너무 많으면 인스턴스 생성 시 쓸데없는 메모리가 할당됨.
    - 상황에 맞게 적절하게 변수를 사용해야 한다.

# Singleton Pattern

- design 패턴 - 객체지향 프로그래밍에서 어떻게 하면 더 효율적으로 구성하고, 유지보수가 쉽게 코딩할 것인 지를 여러가지의 패턴으로 정리해놓은 것. 그 중 하나인 singleton pattern.
- 싱글턴 패턴의 공통적인 특징은 private constructor 를 가진다는 것과, static method 를 사용한다는 점.
- 그 중 이른 초기화 Eager Initialization 방법

### Singleton pattern - 객체의 유일성

- 프로그램에서 인스턴스가 단 한 개만 생성되어야 하는 경우 사용하는 디자인 패턴
    - 프로그램에서 여러개의 인스턴스가 생성되었을 때 문제가 되는 경우가 있다. (ex_표준시간, 회사라는 객체는 하나로 유일하다)
- static 변수, 메서드를 활용하여 구현할 수 있다.
- 예제

    ```java
    public class Company {

        private static Company instance = new Company();
        private Company() {
        }

        public static Company getInstance() {
            return instance;
        }
    }
    ```

    - 기본 생성자를 private 로 설정.

    ```java
    public class CompanyTest {
        public static void main(String[] args) {
            Company company1 = Company.getInstance(); // static이기 때문에 외부에서 class로 접근 가능한 것
            Company company2 = Company.getInstance();
    				//Company error = new Company(); //오류 - 외부에서 생성 불가

    				System.out.println(company1);
            System.out.println(company2);
        }
    }
    ```

    ```
    ch18.Company@4617c264
    ch18.Company@4617c264
    ```

    - 객체의 주소가 같다. 하나의 객체만을 갖는다.
    - Company는 외부에서 생성할 수 없고, 내부의 private 생성자 하나만 존재한다.
    - 외부에서 사용할 수 있는 객체는 getInstance() method 하나만 제공하고 있다.
    - 즉, 생성자를 내부에 private로만 두어 하나의 객체만 생성할 수 있게 하는 것이 **singleton** 패턴이다.
    - Class Diagram

        ![image](https://user-images.githubusercontent.com/75327385/132973925-5c8a1a6c-3654-4ac7-bf41-a1a2fe81b0a4.png)

        1. class 이름
        2. 변수
        3. 생성자와 메서드
        - `-` : private
        - `+` : public
- ref

    [https://readystory.tistory.com/116](https://readystory.tistory.com/116)

    [https://webdevtechblog.com/싱글턴-패턴-singleton-pattern-db75ed29c36](https://webdevtechblog.com/%EC%8B%B1%EA%B8%80%ED%84%B4-%ED%8C%A8%ED%84%B4-singleton-pattern-db75ed29c36)

# 예제 - 카드 발급하기

# 객체 배열 (ArrayList)

- Java Utill Package 안에 제공되는 객체배열을 구현해놓은 클래스이다.
- 기본자료형 배열과 객체배열 사용하는 데 차이가 있다.

### 배열

- 배열 정리
    - 같은 자료형으로 구성된 배열
    - 배열의 경우 new 하여 선언하면, `0 / null`으로 초기화가 된다.

    ### 배열 선언과 초기화

    - 선언

        ```java
        int[] arr1 = new int[10];  // new를 써야 한다!
        int arr2[] = new int[10];  // 둘 형태 모두 사용 가능
        ```

    - 초기화

        ```java
        int[] nums = new int[]{10, 20, 30}; //갯수를 생략해야 함

        int[] nums = {10, 20, 30}; //new int[] 생략 가능

        int[] nums;
        nums = new int[]{10, 20, 30}; //선언 후 배열을 생성하는 경우는 new int[]를 생략할 수 없다. 
        ```

    ### 배열 사용하기

    - 클래스 제공 멤버 - `arr.length`
    - enhanced for문

### 객체배열

- 기본 자료형과 달리, 객체 배열엔 요소가 되는 객체의 주소가 들어갈 메모리(4Byte-32bit경우, 8Byte-64bit경우)만 할당되고 각 요소 객체는 생성하여 저장해야 함
- ***C에서 포인터 배열과 같은 느낌.***
- 객체배열 예제

    ```java
    public class BookTest {
        public static void main(String[] args) {
            Book[] library = new Book[5]; // 객체 배열
            
            library[0] = new Book("태백산맥1", "조정래");
            library[1] = new Book("태백산맥2", "조정래");
            library[2] = new Book("태백산맥3", "조정래");
            library[3] = new Book("태백산맥4", "조정래");
            library[4] = new Book("태백산맥5", "조정래");

            for (Book book : library) {
                System.out.println(book); // 객체 주소값
                book.showInfo();
            }
        }
    }
    ```

### 객체배열 복사하기 - 얕은 복사, 깊은 복사

**얕은 복사 shallow copy**

- 자바에서 제공되는 배열 복사 메서드
`System.arrayCopy(src, srcPos, dest, destPos, length)`

    Pos = 배열의 인덱스임. 어디부터 복사할 건 지.

- *같은 포인터를 가리키게 하는 개념 → 주소를 복사.*

**깊은 복사 deep copy**

- 아예 복제하는 개념
- 일일히 요소마다 객체를 생성해주고, 그 값의 멤버값을 복사해주는 식으로 해야 한다.

    ```java
    Book[] copyBookList = new Book[5];

    for(int i = 0; i < library.length; i++) {
    		copyBookList[i] = new Book(); //생성 해줘야 함! 할당 안된 상태라서. 
        copyBookList[i].setAuthor(library[i].getAuthor());
        copyBookList[i].setTitle(library[i].getTitle());
    }
    ```

# ArrayList 사용하기

### ArrayList 클래스 메서드

- ArrayList - java.util 패키지에서 제공된다.
- 주요 메서드
    - `boolean add(E)` : 요소(element) 하나를 배열에 추가한다. 인자 E는 요소의 자료형을 의미함.
    - `int size()` : 배열에 추가된 요소 전체 개수를 반환한다.
    - `E get(int index)` : 배열의 index위치에 있는 요소 값을 반환한다.
    - `E remove(int index)` : 배열의 index위치에 있는 요소 값을 제거하고, 그 값을 반환한다.
    - `boolean isEmpty()` : 배열이 비어 있는 지 확인한다.

### ArrList 사용하기

- [Array List Generics](https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=itinstructor&logNo=100203119515](https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=itinstructor&logNo=100203119515)) `ArrList< >` : 어떤 객체를 넣을 것인 지 type 지정.

### javadoc

- [https://docs.oracle.com/javase/9/docs/api/java/util/ArrayList.html](https://docs.oracle.com/javase/9/docs/api/java/util/ArrayList.html)
- [javaDoc 작성하기](https://blog.live2skull.kr/javadoc/java/java-javadoc/)

### enhanced for문

```java
int[] arr= {1, 2, 3};

for(int num : arr) {
      System.out.println(num);
}
```

```
1
2
3
```

- 처음부터 끝까지 돌 때 사용한다.
- 즉, 배열의 index0부터 배열끝까지 쭉 순회할 때 쓴다.

    ~~(아주 유용하군)~~

- 변수++ (ex_ int i++)식의 for문이 성능 면에서는 훨씬 빠르다고 한다.

[jwon님 notion 정리](https://www.notion.so/Java_Practice_03-2021-09-01-dc52b7ac93bd4dfbb494d61f8a51e52a) 

---

`volatile` 키워드 : 메인 메모리에서 해당 변수값을 읽어온다?