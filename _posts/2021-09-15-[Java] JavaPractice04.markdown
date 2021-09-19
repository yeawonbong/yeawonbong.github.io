---
layout: post
title: "[Java] JavaPractice04. inheritance(상속), super, protected, upcasting, overriding, virtual method(가상메서드), polymorphism(다형성)"
date: 2021-09-15 11:13:00 +0900
category: java
---
상속(inheretance), super, protected, upcasting, overriding, 가상메서드(virtual method), 다형성(polymorphism)

[자바 입문 과정 과제_4.pdf](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/a61e632c-e5cf-45d2-9c67-a779b383cfc5/자바_입문_과정_과제_4.pdf)

# 상속

### 클래스 상속

![image](https://user-images.githubusercontent.com/75327385/133356753-f3cbb5d4-49a4-4c03-a85f-40c7212568d6.png)

- 새로운 클래스를 정의할 때 이미 구현된 클래스를 상속(inheritance)받아서 속성이나 기능을 확장하여 클래스를 구현함.
- 기존에 있는 클래스의 기능, 속성 등 이미 구현되어있는 부분을 다른 클래스에서 받아 쓰는 것.
- 확장하는 개념으로 생각해야 한다.
- 이미 구현된 클래스보다 더 구체적인 기능을 가진 클래스를 구현해야 할 때 기존 클래스를 상속함.
- '하위 클래스가 상위 클래스를 바라본다' 고 생각하면 된다.
- 용어
    - 상속하는 클래스: 상위 클래스, parent class, base class, super class
    - 상속받는 클래스: 하위 클래스, child class, derived class, subclass
- 상속의 문법

    ```java
    class B extends A{
    }
    ```

    - extemds 키워드 뒤에는 단 하나의 클래스만 올 수 있음
    - 자바는 단일 상속(single inheritance)만을 지원함

### 상속을 구현하는 경우

- 상위 클래스는 하위 클래스보다 더 일반적인 개념과 기능을 가짐
- 하위 클래스는 상위 클래스보다 더 구체적인 개념과 기능을 가짐
- 하위 클래스가 상위 클래스의 속성과 기능을 확장(extends)한다는 의미
    ![image](https://user-images.githubusercontent.com/75327385/133356845-024e797a-f8af-429b-bdb5-0c042c45f3d6.png)

### 상속 예제

- 예제

    ```java
    public class Customer {
        protected int customerID;
        protected String customerName;
        protected String customerGrade;
        int bonusPoint;
        double bonusRatio;

        public Customer() {
            customerGrade = "SILVER";
            bonusPoint = 0,01;
        }
        public int calcPrice(int price) {
            bonusPoint += price * bonusRatio;
            return price;
        }
        public String showCustomerInfo() {
            return customerName + "님의 등급은 " + customerGrade + "이며, 보너스 포인트는 " + bonusPoint + "입니다.";
        }
    }
    ```

    - `protected` → 외부 클래스에서 접근할 수 없지만, 하위 클래스에서 접근할 수 있는 접근제어자.

    ```java
    public class VIPCustomer extends Customer {

        double saleRatio; //할인율
        String agentID; //담당 상담원

        public VIPCustomer() {
            bonusRatio = 0.05;
            saleRatio = 0.1;
            customerGrade = "VIP";
        }
    ```

## 상속에서 클래스 생성 과정과 형 변환

### 하위 클래스의 생성 순서

- 하위 클래스를 생성하면 항상 상위 클래스가 먼저 생성된다.

    ![image](https://user-images.githubusercontent.com/75327385/133356943-b3631544-5694-4287-bcbe-076b6ebbef18.png)

- 위 예제에서, `new VIPCustomer()`를 호출하면 상위 클래스인 `Customer()`가 먼저 호출된다.
- 클래스가 상속 받은 경우 하위 클래스의 생성자에서는 반드시 상위 클래스의 생성자를 호출함.

### super - 상위 클래스 생성자 호출

- 묵시적으로 호출
- 하위 클래스에서 가지는 상위 클래스에 대한 참조 값(this처럼, 상위 클래스를 참조한다)
- `super()` - 상위 클래스의 기본 생성자를 호출함
- 하위 클래스에서 명시적으로 상위 클래스의 생성자를 호출하지 않으면 **묵시적으로 super()가 호출된다.**
(이 때, 반드시 상위 클래스의 기본 생성자가 존재해야 한다)
- 상위 클래스의 기본 생성자가 없는 경우 (다른 생성자가 있는경우), 하위 클래스의 생성자에서 super를 이용하여 **명시적으로 상위 클래스의 생성자를 호출**한다.
- super는 생성된 상위 클래스 인스턴스의 참조값을 가지므로, super를 이용하여 상위 클래스의 메서드나 멤버 변수에 접근할 수 있다.

### protected 접근 제어자

- 상위 클래스에 선언된 private 멤버 변수는 하위 클래스에서 접근할 수 없다.
- 외부 클래스는 접근할 수 없지만, 하위 클래스는 접근할 수 있도록 protected 접근 제어자를 사용

### 업캐스팅 (upcasting) 형변환 - 묵시적 형변환

- 하위 클래스가 상위 클래스로 자동 형변환이 되는 것. 업캐스팅! - 그 반대는 성립하지 않는다.
- 하위 클래스는 상위 클래스의 타입을 내포하고 있기 때문.
- 단, 업캐스팅 된 경우, 타입이 상위클래스인 것이기 때문에, **상위 클래스의 멤버변수만 사용이 가능**하다.
- 상위 클래스로 변수를 선언하고, 하위 클래스의 생성자로 인스턴스를 생성할 수 있다.

    ```java
    Customer customerLee = new VIPCustomer();
    ```

- 상위 클래스 타입의 변수에 하위 클래스 변수가 대입될 수 있다.

    ```java
    VIPCustomer vCustomer = new VIPCustomer();
    addCustomer(vCustomer);
    int addCustomer(Customer customer){
    }
    ```

    - VIPCustomer의 상위 클래스인 Customer로 형변환이 가능하다.

![image](https://user-images.githubusercontent.com/75327385/133357012-0dd1cf09-0fb9-411b-a6d5-a400c189321b.png)


# Overriding - 메서드 재정의하기

- 오버라이딩 (overriding) : 상위 클래스에서 정의된 메서드의 구현 내용이 하위 클래스에서 구현할 내용과 맞지 않는 경우 하위 클래스에서 동일한 이름의 메서드를 재정의할 수 있다.
- 재정의 하여 구현해야 함
    - 주의: 반환값, 메서드 이름, 매개변수의 타입과 갯수가 같아야 한다 (function signiture)
- 위 예제에서, VIPCustomer 클래스의 calcPrice()는 할인율이 적용되지 않으므로 재정의가 필요하다.

    ```java
    @Override
    public int calcPrice(int price) {
    		bonusPoint += bonusRatio;
    		return price - (int)(price * salesRatio);
    }
    ```

- Intellij) Ctrl + n + overriding Method 선택하고 overriding할 메서드를 선택해준다.

    ```java
    @Override
    public int calcPrice(int price) {
            bonusPoint += price * bonusRatio;
            price -= (int)price * saleRatio;
            return super.calcPrice(price);
        }
    ```

    - annotation (@) : 주석으로, 컴파일러에게 이것이 오버라이드 된 메서드라는 것을 알려주는 역할

        ![image](https://user-images.githubusercontent.com/75327385/133357055-4fc91a51-bd7a-494f-8d40-0c8a653a956f.png)


    - `@`overriding 애노테이션은 재정의된 메서드라는 의미로, 선언부가 (함수 정의부)기존의 메서드와 다른 경우 에러가 난다.

### 형 변환과 오버라이딩 메서드 호출

`Customer vc = new VIPCustomer();`

- vc 변수의 타입은 Customer지만 인스턴스 타입은 VIPCustomer이다.
- 자바에서는 항상 인스턴스의 메서드가 호출된다. (가상 메서드의 원리)
- 자바에서 모든 메서드는 가상 메서드이다 (virtual method) (??!)

# 메서드 재정의와 가상 메서드 원리

### 메서드는 어떻게 호출되고 실행되는가?

- 메서드(함수)의 이름은 주소값을 나타냄
- 메서드는 명령어 set이고, 프로그램이 로드되면 메서드 영역(코드 영역)에 명령어 set이 위치
- 해당 메서드가 호출되면 명령어 set이 있는 주소를 찾아 명령어가 실행됨
- 이때 메서드에서 사용하는 변수들은 스택 메모리에 위치하게 됨
- 따라서 다른 인스턴스라도 같은 메서드의 코드는 같으므로 같은 메서드가 호출됨
- 인스턴스가 생성되면 변수는 힙 메모리에 따로 생성되지만, 메서드 명령어 set은 처음 한번만 로드 됨

### 가상 메서드의 원리

[가상메서드 참고](https://ga-you-ni.tistory.com/164)

- 가상 메서드 테이블(virtual method table)에서 해당 메서드에 대한 address를 가지고 있음.
- 재정의된 경우는 재정의 된 메서드의 주소를 가리킴
- 멤버변수는 필드에 저장(힙메모리), 멤버 메서드는 메서드영역(코드영역의 메서드영역)에 저장된다. 저장되는 위치가 다르다. 인스턴스가 생성될 때마다 메서드가 메모리에 올라가는 것이 아니라, 한번 올라가고, 그것을 계속 참조하는 식이라고 생각하면 된다.

    ![image](https://user-images.githubusercontent.com/75327385/133357102-176c1e5e-55ec-4979-91f7-38d8be2cd086.png)

# 다형성 (polymorphism)

[ref](https://medium.com/@kjunha77/%EA%B0%95%EC%9D%98%EB%85%B8%ED%8A%B8-9-%EA%B0%9D%EC%B2%B4%EC%A7%80%ED%96%A5-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D-3-%EB%8B%A4%ED%98%95%EC%84%B1-41484ce6c55b)

- 하나의 코드가 여러 자료형으로 구현되어 실행되는 것
- 같은 코드에서 여러 다른 실행 결과가 나온다.
- 정보은닉, 상속과 더불어 객체지향 프로그래밍의 가장 큰 특징 중 하나이다.
- 다형성을 잘 활용하면 유연하고 확장성 있는 프로그램을 만들 수 있으며, 유지보수가 편리하다.

### 다형성 예제

```java

class Animal {
    public void move() {
        System.out.println("동물이 움직입니다.");
    }
}

class Human extends Animal {
    @Override
    public void move() {
        System.out.println("사람이 두 발로 걷습니다.");
    }
    public void readBook() {
        System.out.println("사람이 책을 읽습니다.");
    }
}

class Tiger extends Animal {
    @Override
    public void move() {
        System.out.println("호랑이가 네 발로 뜁니다.");
    }
    public void hunting() {
        System.out.println("호랑이가 사냥을 합니다.");
    }
}

class Eagle extends Animal {
    @Override
    public void move() {
        System.out.println("독수리가 하늘을 납니다.");
    }
    public void flying() {
        System.out.println("독수리가 양날개를 쭉 펴고 날아다닙니다.");
    }
}

public class AnimalTest {
    public static void main(String[] args) {
        Animal hAnimal = new Human();
        Animal tAnimal = new Tiger();
        Animal eAnimal = new Eagle();

        AnimalTest test = new AnimalTest();
        test.moveAnimal(hAnimal);
        test.moveAnimal(tAnimal);
        test.moveAnimal(eAnimal);
    }
    public void moveAnimal(Animal animal) {
        animal.move();
    }
} 
```

- 코드는 하나인데, 데이터형에 따라 move의 impementation이 달라진다.
    - 상속이 되었고, 메서드 오버라이딩을 하고, 상위 클래스로의 형변환이 일어났다.
    - 상속을 하면, 하위 클래스들을 상위클래스 하나의 type으로 핸들링 할 수 있다.
        - 그 결과- 클래스간의 결합도가 tight해진다. (상위 클래스를 바꾸면 하위 클래스에 영향)
        - 따라서 상속을 설계할 경우 꼭 필요할 경우에 신중하게 설계해야 한다.
    - 상위 클래스로 upcasting하여 사용하기 때문에(`moveAnimal()`), 하위 클래스의 메서드는 사용할 수 없다. (ex_readBook(), hunting())
        - 이럴 때, 다시 하위 클래스로 변환해주는 **downcasting**을 해줘야 한다.

### 다형성을 사용하는 이유?

- 다른 동물을 추가하는 경우 수정이 편리하다.
- 상속과 메서드 재정의를 활용하여 확장성 있는 프로그램을 만들 수 있다.
- 다형성을 사용하지 않고 하나의 클래스에서 처리한다면 많은 if-else문이 구현되고, 코드의 유지보수가 어려워진다.
- **상위 클래스에서는 공통적인 기능**을 제공하고, **하위 클래스에서는 각 클래스에 맞는 개별기능**을 구현할 수 있다.
- 여러 클래스를 하나의 타입(상위 클래스)으로 핸들링할 수 있다.

## 상속은 언제 사용할까?

### IS-A 관계 (is a relationship: inheritance)

- 일반적인 개념과 구체적인 개념과의 관계 (general - specific)
- 상위 클래스: 하위 클래스보다 일반적인 개념 (예_Employee)
- 하위 클래스: 상위 클래스보다 구체적인 개념들이 더해짐 예_FullTime, PartTime)
- 상속은 클래스간의 결합도가 높은 설계이다.
- 상위 클래스의 수정이 많은 하위 클래스에 영향을 미칠 수 있다.
- 계층구조가 복잡하거나 hierarchy(계층의 depth)가 높으면 좋지 않다.

### HAS-A 관계 (composition)

- 기존 클래스를 이용한다고 무조건 상속하는 것이 아니다.
- 클래스가 다른 클래스를 포함하는 관계 (변수로 선언)
- 코드 재사용의 가장 일반적인 방법
- 예_Student가 Subject를 포함한다.
- 상속이 아니다.

# 다운캐스팅과 instanceof

### 다운 캐스팅 (downcasting)

- 업캐스팅된 클래스를 다시 원래의 타입으로 형변환 하는 것.
- 하위 클래스로의 형변환은 명시적으로 해야한다.

```java
Customer vc = new VIPCustomer(); //묵시적
VIPCustomer vCustomer = (VIPCustomer)vc; //명시적
```

### A instanceof B

- A 변수가 원래 B인스턴스였는 지 체크하는 키워드
- 원래 인스턴스의 형이 맞으면 true, 아니면 false를 반환한다.

```java
if(customerK instanceof VIPCustomer) {
    VIPCustomer vc = (VIPCustomer)customerK; //명시적 형변환 - downcasting
    System.out.println(customerK.showCustomerInfo());
}
```

### 다운캐스팅 예제

```java
public void testDownCasting(ArrayList<Animal> list) {
        for(int i=0; i<list.size(); i++){
            Animal animal = list.get(i);
            if(animal instanceof Human){
                Human human = (Human)animal;
                human.readBook();
            }
            else if(animal instanceof Tiger){
                Tiger tiger = (Tiger)animal;
                tiger.hunting();
            }
            else if(animal instanceof Eagle){
                Eagle eagle = (Eagle)animal;
                eagle.flying();
            }
            else
                System.out.println("unsupported type");
        }
    }
```

- 다운캐스팅을 쓰면 코드가 많이 지저분해지고, 각 타입으로 되돌려야하니까
- 할 수 있으면 굳이 다운캐스팅 하지 말고, 다형성(polymophism)으로 overriding해서 쓰는 것이 코드가 깔끔하다.
- 반드시 원래 타입으로 되돌려야 한다면, Instanceof로 체크를 하고 사용하면 된다.

---

# Practice

- 형변환 했을때 주소값이 같다..

    ```java
    if(customerK instanceof VIPCustomer) {
        VIPCustomer vc = (VIPCustomer)customerK; //명시적 형변환 - downcasting
        System.out.println(customerK.showCustomerInfo());
        System.out.println(customerK);
        System.out.println(customerK.customerName + "의 담당 Agent는 " + ((VIPCustomer) customerK).getAgentID());
        System.out.println(vc);
        System.out.println("vc " + vc.customerName + "의 담당 Agent는 " + vc.getAgentID());
    }
    ```

    ```
    Kim님의 등급은 VIP이며, 보너스 포인트는 0입니다.
    Chapter3.ch06.VIPCustomer@2a84aee7
    Kim의 담당 Agent는 123
    Chapter3.ch06.VIPCustomer@2a84aee7
    vc Kim의 담당 Agent는 123
    ```

    - 변수는 다른데, 참조하는 메모리 영역이 같아서?
- 이렇게 캐스팅 해서 하위 클래스 변수에 접근하여 값을 변경하는 것도 가능하다.

    ```java
    ((VIPCustomer)customerK).setAgentID(321);
    //System.out.println(customerK.getAgentID); // Error
    System.out.println(((VIPCustomer) customerK).getAgentID());
    ```

    ```
    321
    ```

---

# Q

- ~~상속보다 has-a 관계가 더 좋은 지? 아니면 의미에 따라 상속/has-a를 선택하여 설계하는 것이 좋은 지?~~
- ~~업캐스팅 다운캐스팅은 절차적으로 생각하면 되는지?~~
    - ~~만약 모든 Customers를 (SILVER, GOLD, VIP) Customer로 업캐스팅하여 핸들한다. 
    그런데 VIPCustomer의 담당 직원의 정보를 사용하고 싶으면 다시 Downcasting해서 사용하고 다시 Upcasting 해놓아야 하는가? - practice로 궁금증 해결~~

---

# 스터디

- [자바 컴파일](https://injeblog.tistory.com/53)