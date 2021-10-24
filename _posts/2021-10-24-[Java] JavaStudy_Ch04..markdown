---
layout: post
title: "[Java] JavaStudy_Ch04. 자바의 유용한 클래스들"
date: 2021-10-24 11:13:00 +0900
category: java
---

*자바 스터디에 이어, 팀원들을 모아 스터디를 이어서 진행하기로 했다.*  
<br/>

[00.들어가며](#00-들어가며)  
[01.Object클래스](#01-object-클래스---모든-클래스의-최상위-클래스)  
[02.Object클래스-메서드활용](#02-object-클래스의-메서드-활용)  
[03.String-StringBuilder-StringBuffer-클래스-text block](#03-string-stringbuilder-stringbuffer-클래스-text-block)  
[04.Class클래스-사용하기](#04-class-클래스-사용하기)

# 00. 들어가며..

여기부터는 JDK에 대해 공부해보겠으.

- Java의 기본적인 클래스들이 몇가지 있다.
    - Object 클래스
    - String 클래스
    - Class 클래스
    - 기본 클래스들이 어떻게 구현되어있고, 활용될 수 있는 지 살펴볼 것이다.

# 01. Object 클래스 - 모든 클래스의 최상위 클래스

[javaDocs_ClassObject](https://docs.oracle.com/javase/10/docs/api/java/lang/Object.html)

모든 클래스의 최상위 클래스, root 클래스라고 한다. java.lang 패키지에 들어있다.

### java.lang 패키지

- object 클래스는 java.lang 패키지 안에 들어있다.
- 프로그래밍 시 import 하지 않아도 자동으로 import 된다.
- `import.java.lang`
- 많이 사용하는 기본 클래스들이 속한 패키지이다.
- ex) String, Integer, System...

### 모든 클래스는 Object 클래스를 상속 받는다

- `java.lang.Object` 클래스
- 모든 클래스의 최상위 root 클래스,
- 다시말해 모든 클래스는 Object 클래스에서 상속을 받는다.
    - Object 클래스의 메서드를 하위 클래스에서 사용 가능하며, 그 중 일부는 하위 클래스에서 재정의하여 사용할 수 있다. (final이 아닌 메서드)
- 컴파일러가 extends Object를 자동으로 추가한다.
    - class Student ⇒ class Student extends Object
- Method Summary
    
    ![스크린샷 2021-10-06 오후 12.20.05.png](https://www.notion.so/image/https%3A%2F%2Fs3-us-west-2.amazonaws.com%2Fsecure.notion-static.com%2F58247add-0847-4124-a565-b9314f8dca48%2F%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2021-10-06_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_12.20.05.png?table=block&id=d3bf8dbd-e2eb-480d-b97d-871670755d60&spaceId=42b12171-94c5-49c8-9011-96ced12ff52f&width=1530&userId=2fe0b541-751d-4d6d-9cb5-a17d28d28aad&cache=v2)
    

### toString() 메서드

- 객체 정보를 String으로 바꾸어서 사용할 때 쓰임
- String이나 Integer 클래스는 이미 재정의 되어 있음
- toString()메서드 재정의 예
    
    ```java
    class Book{
        private String title;
        private String author;
    
        public Book(String title, String author) {
            this.title = title;
            this.author = author;
        }
    }
    
    public class BookTest {
    
        public static void main(String[] args) {
    
            Book book = new Book("데미안", "헤르만 헤세");
    
            System.out.println(book); //ch01.Book@4617c264 실제 주소 아닌, 가상 메모리 값이다.
    
            String str = new String("test");
            
    				System.out.println(str); // test 얘는 주소가 아니라, 문자가 나온다. 
    				System.out.println(str.toString());
        }
    }
    ```
    
    ```java
    ch01.Book@4617c264
    test
    test //위와 동일한 값 
    ```
    
    - 아래 스트링의 경우, 문자열이 나온다.
    - toString이 오버라이딩 되어서 그렇다.
        - `System.out.println(str)` ⇒ `System.out.println(str.toString())` 자동으로 오버라이딩 된다.
    
    ---
    
    이 toString 메서드 (in Object method)를 오버라이딩 해보자. 
    
    ```java
    class Book{
        private String title;
        private String author;
    
        @Override
        public String toString() {
            return title +","+ author;
        }
    
        public Book(String title, String author) {
            this.title = title;
            this.author = author;
        }
    }
    
    public class BookTest {
    
        public static void main(String[] args) {
    
            Book book = new Book("데미안", "헤르만 헤세");
    
            System.out.println(book); //ch01.Book@4617c264 실제 주소 아닌, 가상 메모리 값이다.
        }
    }
    ```
    
    ```java
    데미안, 헤르만 헤세 //오버라이딩 한 메서드의  값으로 출력된다. 
    ```

    # 02. Object 클래스의 메서드 활용
    ### equals() 메서드

- 원형: 두 인스턴스의 주소값을 비교하여 `true/false`를 반환한다.
    - 두 인스턴스가 같다고 말할 때는 힙메모리 위치가 같을 때를 의미한다.
- **오버라이드하여**: 두 인스턴스가 논리적으로 돌일함 여부를 구현할 수 있다.
    - 인스턴스가 다르더라도(힙메모리 안에 주소가 달라도) 논리적으로 동일한 경우 true를 반환하도록 재정의할 수 있다.
        - ex) 같은 학번, 같은 사번, 같은 아이디의 회원 등등..

### hashCode() 메서드

- 자바에서 힙 메모리를 관리하는 방식 - hash 방식이다.
    - hash : 정보를 저장, 검색하는 자료구조
- hashCode()는 인스턴스의 저장 주소를 반환한다.
- 자료의 특정 값(키 값)에 대한 저장 위치를 변환해주는 해시 함수를 사용.
    
    ![Untitled](https://www.notion.so/image/https%3A%2F%2Fs3-us-west-2.amazonaws.com%2Fsecure.notion-static.com%2F17a158bb-d0b3-4b25-b1eb-b83dd3fc5bbe%2FUntitled.png?table=block&id=d5552b4f-e7f8-48b9-aefc-2a37bdc18270&spaceId=42b12171-94c5-49c8-9011-96ced12ff52f&width=1530&userId=2fe0b541-751d-4d6d-9cb5-a17d28d28aad&cache=v2)
    
- 두 인스턴스가 같다는 것은 ? 두 인스턴스에 대한 equals()의 반환값이 true일 때, 동일한 hashCode() 값을 반환하는 것!
    - 즉, 논리적으로 동일함을 위해 equals() 메서드를 재정의 하였다면 hashCode()메서드도 **오버라이드** 하여 동일한 hashCode 값이 반환되도록 한다
    - 예를들어, 논리적으로 동일한 경우 실제로 인스턴스 물리 주소는 다른데, 오버라이딩하여 hashCode는 같게 나온다.
    
    ```java
    String str1 = new String("abc");
    String str2 = new String("abc");
    
    System.out.println(str1.equals(str2));
    
    System.out.println(str1.hashCode());
    System.out.println(str2.hashCode());
    -------------------------
    Integer i = 100;
    System.out.println(i.hashCode());
    ```
    
    ```
    true
    96354
    96354
    -----------------
    100
    ```
    
    다른 인스턴스지만, 해시값이 같게 나온다. 
    
- 그럼 원래 해시값을 어떻게 알아내나?
    
    → `System.identityHashCode([알아낼변수])` 메서드
    

### clone() 메서드

- 객체의 원본을 복제하는데 사용하는 메서드
- 생성과정의 복잡한 과정을 반복하지 않고 복제할 수 있음
- clone()메서드를 사용하면 객체의 정보 (멤버 변수 값 등..)가 동일한 또 다른 인스턴스가 생성되는 것이므로, 객체지향 프로그램에서의 정보은닉, 객체 보호의 관점에서 위배될 수 있음. - private까지 죄다 복제가 되니까.
- 해당 클래스의 clone()메서드의 사용을 허용한다는 의미로 implements `Clonable` 인터페이스 구현를 명시해줌.

```java
Student copyStudent = (Student)std1.clone();
```

# 03. String, StringBuilder, StringBuffer 클래스, text block 
### String 클래스    

- String 선언하기
    
    ```c
    String str1 = new String("abc");
    String str2 = "abc";
    ```
    
    - new 해서 생성하는 방법: **Heap영역**에 메모리가 생성된다. (생성될 때마다 다른 주소를 갖는다)
    - assign해서 쓰는 방법: **상수 풀(constant pool)**에 "abc"라는 string 이 있고, 이 주소를 가리키는거. (모두 같은 주소를 가리킨다)
    
    ```c
    public class StringTest {
    
    	public static void main(String[] args) {
    		String str1 = new String("abc");
    		String str2 = new String("abc");
    		
    		System.out.println(str1 == str2); // false
    		
    		String str3 = "abc";
    		String str4 = "abc";
    		
    		System.out.println(str3 == str4); // true
    	}
    }
    ```
    
    - 한 번 생성된 String은 불변한다. (immutable)
    - String을 연결하면 기존의 String에 연결되는 것이 아닌 새로운 문자열이 생성된다 (메모리 낭비가 발생할 수도) - `concat` 메서드
        
        ```c
        public class StringTest {
            public static void main(String[] args) {
        
                String java = new String("java");
                String android = new String("android");
        
                System.out.println(System.identityHashCode(java));
                java = java.concat(android);
        
                System.out.println(System.identityHashCode(java));
            }
        }
        ```
        
        ```
        295530567
        2003749087      //다르다
        ```
        
        - 메모리 낭비가 된다. 그래서..

### StringBuilder, StringBuffer 활용하기

- 내부에적으로 가변적인 char[]를 멤버 변수로 가짐. (final이 아니라서 문자열이 바뀔 수가 있다.)
- 문자열을 여러 번 연결하거나 변경할 때 사용하면 유용함
- 새로운 인스턴스를 생성하지 않고 char[]를 변경함.
- 단일 스레드는 StringBuilder, 멀티 스레드는 StringBuffer를 사용한다.
    - StringBuffer는 멀티쓰레드 프로그래밍에서 동기화(synchronization)을 보장한다.
- toString()메서드로 String 반환
    
    ```java
    public class StringBuilderTest {
        public static void main(String[] args) {
            String java = new String("java");
            String android = new String("android");
    
            StringBuilder buffer = new StringBuilder(java);
    System.out.println(System.identityHashCode(buffer));
            buffer.append(android);
    System.out.println(System.identityHashCode(buffer));
            String test = buffer.toString();
            System.out.println(test);
        }
    }
    ```
    
    ```java
    295530567
    295530567
    javaandroid
    ```
    

### text block 사용하기 (java 13)

- 문자열을 `""" """` 사이에 이어서 만들 수 있음
- html, json 문자열을 만드는 데 유용하게 사용할 수 있음.

```java
public class TextBlockTest {
    public static void main(String[] args) {
        String textBlocks = """
                Hello,
                hi,
                how are you?
                """;
        System.out.println(textBlocks);
    }
}
```

```
Hello,
hi,
how are you?
```

# 04. Class 클래스 사용하기
### Class 클래스

- 자바의 모든 클래스와 인터페이스는 컴파일 후 class 파일이 생성된다.
- Class 클래스는 컴파일된 class 파일을 로드하여 객체를 동적로드하고, 정보를 가져오는 메서드가 제공된다.
- **Class.forName("클래스 이름")**메서드
    - 클래스를 동적으로 로드함.
    
    ```java
    Class c = Class.forName("java.lang.String");
    ```
    
- **.class**
    - 클래스 이름으로 직접 Class 클래스 가져오기
    
    ```java
    Class c = String.class;
    ```
    
- **getClass()**
    - 생성된 인스턴스에서 Class 클래스 가져오기
    
    ```java
    String s = new String();
    Class c = s.getClass(); //Object 메서드
    ```
    
- 예제 - 동적으로 Class 가져와서 Constructor(생성자) 출력해보기
    
    ```java
    import java.lang.reflect.Constructor;
    
    public class StringTest {
        public static void main(String[] args) throws ClassNotFoundException {
    
            Class c = Class.forName("java.lang.String"); //동적로딩
            Constructor[] cons = c.getConstructors();
            for (Constructor co : cons) {
                System.out.println(co);
            }
        }
    }
    ```
    
    ```
    public java.lang.String(byte[])
    public java.lang.String(byte[],int,int)
    public java.lang.String(byte[],java.nio.charset.Charset)
    public java.lang.String(byte[],java.lang.String) throws java.io.UnsupportedEncodingException
    public java.lang.String(byte[],int,int,java.nio.charset.Charset)
    public java.lang.String(java.lang.StringBuilder)
    public java.lang.String(java.lang.StringBuffer)
    public java.lang.String(char[],int,int)
    public java.lang.String(char[])
    public java.lang.String(java.lang.String)
    public java.lang.String()
    public java.lang.String(byte[],int,int,java.lang.String) throws java.io.UnsupportedEncodingException
    public java.lang.String(byte[],int)
    public java.lang.String(byte[],int,int,int)
    public java.lang.String(int[],int,int)
    ```
    

### 동적로딩이란?

- 컴파일 시에 데이터 타입이 binding되는 것이 아니라, 실행중(runtime)에 데이터 타입을 binding하는 방법 (동적으로 클래스를 로드함)
- 프로그래밍 시에는 문자열 변수로 처리했다가 런타임 시에 원하는 클래스를 로딩하여 binding할 수 있다는 장점이 있다.
- 컴파일 시에 타입이 정해지지 않으므로, 동적 로딩시 오류가 발생하면 프로그램의 심각한 장애가 발생가능하다.
- 오타 등 오류 날 위험이 있긴 함

### Class의 **newInstance()메서드** - 인스턴스 생성

- new 키워드를 사용하지 않고 클래스 정보를 활용하여 인스턴스를 생성할 수 있다.
    
    ```java
    public class ClassTest {
        public static void main(String[] args) throws ClassNotFoundException, InstantiationException, IllegalAccessException {
            Class c1 = Class.forName("ch04.Person");
    
            Person person = (Person)c1.newInstance(); //new키워드 없이 생성
            person.setName("Bong");
            System.out.println(person);
        }
    }
    ```
    

### 클래스 정보 알아보기

- reflection 프로그래밍: Class 클래스를 사용하여 클래스의 정보(생성자, 변수, 메서드) 등을 알 수 있고, 인스턴스를 생성하고, 매서드를 호출하는 방식의 프로그래밍
- 로컬 메모리에 객체가 없는 경우, 원격 프로그래밍, 객체 타입을 알 수 없는 경우에 사용.
- java.lang.reflect 패키지에 있는 클래스를 활용하여 프로그래밍
- 일반적으로 자료형을 알고 있는 경우엔 사용하지 않음.