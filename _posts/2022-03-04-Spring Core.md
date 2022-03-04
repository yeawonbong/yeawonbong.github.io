---
layout: post
title: "[Web] Spring Core"
date: 2022-03-04 11:59:00 +0900
category: web
---
Spring이 무엇인지, Spring Framework를 구성하고 있는 모듈에는 어떠한 것들이 있는 지 알아보자.

# 핵심개념

- Spring Framework
- Spring Framework Modules

# Spring Framework

## Framework란?

- 반제품이라고 생각하면 된다 (다 만들어진 것은 아닌데, 반정도 만들어진 것)
- 이미 구현되어있는 반제품을 이용해서 필요한 제품을 만드는 것

## Spring Framework란?

- 엔터프라이즈급(큰 규모의) 어플리케이션을 구축할 수 있는 가벼운 솔루션이자, 원스-스탑-숍(One-Stop-Shop)
- 원하는 부분만 가져다 사용할 수 있도록 모듈화가 잘 되어 있습니다.
    - 레고처럼 조립하듯이 사용할 수 있다.
- IoC 컨테이너입니다.
    - Inversion of Control, 제어권의 역전이란 객체의 생성에서부터 생명주기의 관리까지 모든 객체에 대한 제어권이 바뀌었다는 것(IoC 컨테이너)
- 선언적으로 트랜잭션을 관리할 수 있습니다.
- 완전한 기능을 갖춘 MVC Framework를 제공합니다.
- AOP 지원합니다.
    - Aspect Oriented Programming, 관점 지향 프로그래밍
    - 관점 지향은 쉽게 말해 어떤 로직을 기준으로 핵심적인 관점, 부가적인 관점으로 나누어서 보고 그 관점을 기준으로 각각 모듈화하겠다는 것이다
- 스프링은 도메인 논리 코드와 쉽게 분리될 수 있는 구조로 되어 있습니다.

## Spring Framework Module

![https://cphinf.pstatic.net/mooc/20180201_180/1517452205302mNfIy_PNG/2_10_1___.png](https://cphinf.pstatic.net/mooc/20180201_180/1517452205302mNfIy_PNG/2_10_1___.png)

- 스프링 프레임워크는 약 20개의 모듈로 구성되어있으며, 필요한 모듈만 가져다 사용할 수 있다.

## ~~AOP와 Instrumentation~~

- 지금 당장은 패스, 스프링 좀 익숙해진 다음 나중에 공부하기

## **~~메시징(Messaging)~~**

- 지금 당장은 패스, 스프링 좀 익숙해진 다음 나중에 공부하기

## **데이터 엑서스(Data Access) / 통합(Integration)**

- 데이터 엑세스/통합 계층은 JDBC, ORM, OXM, JMS 및 트랜잭션 모듈로 구성되어 있다.
- **spring-jdbc** : 자바 JDBC프로그래밍을 쉽게 할 수 있도록 기능을 제공합니다.
- **spring-tx** : 선언적 트랜잭션 관리를 할 수 있는 기능을 제공합니다.
- spring-orm : JPA, JDO및 Hibernate를 포함한 ORM API를 위한 통합 레이어를 제공합니다.
- spring-oxm : JAXB, Castor, XMLBeans, JiBX 및 XStream과 같은 Object/XML 맵핑을 지원합니다.
- spring-jms : 메시지 생성(producing) 및 사용(consuming)을 위한 기능을 제공, Spring Framework 4.1부터 spring-messaging모듈과의 통합을 제공합니다.

spring jdbc를 앞으로 사용할 것이다. 

## **웹(Web)**

- 웹 계층은 spring-web, spring-webmvc, spring-websocket, spring-webmvc-portlet 모듈로 구성됩니다.
- **spring-web** : 멀티 파트 파일 업로드, 서블릿 리스너 등 웹 지향 통합 기능을 제공한다. HTTP클라이언트와 Spring의 원격 지원을 위한 웹 관련 부분을 제공합니다.
- **spring-webmvc** : Web-Servlet 모듈이라고도 불리며, Spring MVC 및 REST 웹 서비스 구현을 포함합니다.
- spring-websocket : 웹 소켓을 지원합니다.
- spring-webmvc-portlet : 포틀릿 환경에서 사용할 MVC 구현을 제공합니다.

본 과정에서는 spring-web, spring-webmvc를 사용할 것이다.

# Spring IoC/DI 컨테이너

## 컨테이너(Container)란?

- 인스턴스의 생명주기(Life Cycle)를 관리한다.
    - 컨테이너의 핵심!
    - 인스턴스를 생성해서 실행하고 소멸시키는 작업들을 개발자가 직접 하지 않고, 대신 해주는 것이 컨테이너
    - Container 예시
        - 서블릿 클래스가 그러했다.
            - 서블릿 생성하고 소멸 등 톰캣이 대신 해줌
            - 서블릿을 실행시켜주는 WAS는 서블릿 컨테이너를 갖고 있다.
                - 웹브라우저로부터 서블릿 url에 해당하는 요청을 받으면, 해당 서블릿을 메모리에 올리고 실행을 한다. 개발자가 실제로 메모리에 올리고 실행하지 않는다. WAS의 서블릿 컨테이너가 해준다.
                - WAS는 동일한 서블릿에 해당하는 요청을 받으면 메모리에 또 올리지 않고, 이미 올라간 서블릿을 실행해서 결과를 웹브라우저에 전달해준다.
        - JSP 파일
            - JSP가 서블릿으로 바뀌고 서블릿이 인스턴스로 만드는 그런 과정들을 tomcat이라는 WAS가 대신 실행했다.
- 생성된 인스턴스들에게 추가적인 기능을 제공한다.

## IoC

- Inversion of Control, 제어의 역전
- 개발자는 프로그램의 흐름을 제어하는 코드를 작성한다. 그런데, 이 흐름의 제어를 개발자가 하는 것이 아니라 다른 프로그램이 그 흐름을 제어하는 것을 IoC라고 말한다.
- 예를 들어, 서블릿 클래스는 개발자가 만들지만, 그 서블릿 메소드를 알맞게 호출하는 것은 WAS이다.
- 이렇게 개발자가 만든 어떤 클래스나 메소드를 다른 프로그램이 대신 실행해주는 것을 제어의 역전이라고 한다.
- 공장을 만드는 것. (TV예시)

## **DI(Dependency Injection)**

- DI는 의존성 주입이란 뜻을 가지고 있다.
- 클래스 사이의 의존 관계를 빈(Bean) 설정 정보를 바탕으로 컨테이너가 자동으로 연결해주는 것을 말합니다.
- 공장이 인스턴스를 만들었다면, 만들어진 인스턴스를 내가 사용하는 프로그램에서 가져와야한다. 그런 방법중에 하나가 DI.
- 의존성을 주입받는 방법

### DI 예시

- DI 적용 안된 예
    
    ```java
    class 엔진 {
    
    }
    
    class 자동차 {
         엔진 v5 = new 엔진();
    }
    ```
    
    - 엔진을 new로 직접 생성하고 있다.
        
        ![https://cphinf.pstatic.net/mooc/20181218_284/1545136782491NSgAa_JPEG/3.7.2-1.jpg](https://cphinf.pstatic.net/mooc/20181218_284/1545136782491NSgAa_JPEG/3.7.2-1.jpg)
        
- DI 적용된 예
    
    ```java
    @Component
    class 엔진 {
    
    }
    
    @Component
    class 자동차 {
         @Autowired
         엔진 v5;
    }
    ```
    
    - 인스턴스를 만드는 주체가 역전됨
    - 인스턴스를 개발자가 생성하지 않고, 약속된 어노테이션으로 선언만 해주면, Spring Container가 알아서 객체를 생성하여 주입해준다.
        
        ![https://cphinf.pstatic.net/mooc/20181218_190/1545137156742y8WiS_JPEG/3.7.2-2.jpg](https://cphinf.pstatic.net/mooc/20181218_190/1545137156742y8WiS_JPEG/3.7.2-2.jpg)
        

## Spring에서 제공하는 IoC/DI 컨테이너

- *대표적인 공장 두 개라고 생각하면 된다.*
- **BeanFactory** : IoC/DI에 대한 기본 기능을 가지고 있습니다.
    - *아주 기본적인 기능만 갖고 있는 공장*
- **ApplicationContext** : BeanFactory의 모든 기능을 포함하며, 일반적으로 BeanFactory보다 추천됩니다. 트랜잭션처리, AOP등에 대한 처리를 할 수 있습니다. BeanPostProcessor, BeanFactoryPostProcessor등을 자동으로 등록하고, 국제화 처리, 어플리케이션 이벤트 등을 처리할 수 습니다.
- **BeanPostProcessor** : 컨테이너의 기본로직을 오버라이딩하여 인스턴스화 와 의존성 처리 로직 등을 개발자가 원하는 대로 구현 할 수 있도록 합니다.
- **BeanFactoryPostProcessor** : 설정된 메타 데이터를 커스터마이징 할 수 있습니다.