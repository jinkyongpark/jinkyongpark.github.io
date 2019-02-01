---
layout: post
title:  "Industrial IoT 보안 기술 "
subtitle: "산업제어시스템"
date:   2018-11-01 2:23:01
categories: [IoT]
---



## Industrial IoT 보안 기술

#### 산업 제어 시스템(ICS) 중심

→ IOT를 제조업에 적용



#### 1.  **산업 제어 시스템 개요**

> CADA, PCS, DCS, Automation, PLC등 다양한 통신 프로토콜, OS, 응용 기술로 구성
>
> 작업 공정을 감시하고 제어하는 컴퓨터 시스템
>
> 발전소, 전력망, 철도, 정유공장, 공장 자동화 등 다양한 응용 환경에서 사용됨



- Example

  - SCADA : 산업 공정이나 인프라, 생산설비/공정을 모니터링하고 제어하는 시스템

  - DCS : 제조 시스템 및 공정 제어 시스템으로서 SCADA는 데이터수집/모니터링에 중점을 두는 반면, DCS는 공정 제어에 중점을 둠

  

- 주요 특성

  - 특정 응용을 위한 vertical solution 제공

  - 응용에 따라 특정한 통신/네트워크 프로토콜 존재

  - 오랜 시간 사용

  - 초기 단계에서는 보안 고려 x

    

- IP/web service 연동

![img](file:///C:\Users\pc\AppData\Local\Temp\OICE_827EF895-6DA0-422C-8F28-F86C20A780A8.0\msohtmlclip1\01\clip_image002.jpg)



- 산업 제어 시스템과 인터넷 연결 

  : 전통적인 제어 시스템 통신 기술 + ip 네트워크 -> 보안 취약성 증대

#### 2. 제어 시스템 보안 특성



- 기존 IT시스템의 보안 요구 사항

  - Confidentiality : 기밀성

  - Integrity : 무결성, 정보에 대한 위변조 감지

  - Availability : 가용성, 서비스의 가용성 제공

    

- ICS의 주요 보안 요구 사항 (우선순위 있다)

- Availabilty와 Integrity는 신뢰성 높은 동작을 위해 매우 중요하고 Confidentiality는 상대적으로 덜 중요
  -  99.9999(six 9)% 가용성 추구

    : 암호를 통한 기밀성, 인증/인가, 추가된 보안들이 가용성 하락

    : 보안성 강화시 가용성을 동시에 제공해야한다.



- ICS특성과 보안 취약성
  - 보안 취약성이 있는 통신 프로토콜 사용

  - 제어 시스템에 사용되는 OS의 보안 취약성

    : 보안 취약성이 있는 embedded OS와 구버전의 windows를 사용하는 경우 많다.

  - 제어 시스템의 응용 소프트웨어 보안 취약성

    : 성능 및 기능 위주가 많다. Ex : fail-open, fail-close출력만 변경해도 가능

  -  공격이 용이한 제어 시스템 firmware

  - Web service와 연결되는 제어 시스템

    : 운용 관리를 위해 web 인터페이스를 구현하는데 이때 취약성

  - 기본 os, 제어 프로그램상에서 부족한 access control 기법

  - Ethernet-to-serial 연결 용이

  - 불완전한 IDS

  - 방화벽 등, 네트워크 보안 기술 부족



- ICS에 대한 공격 영향

  : 인명손실, 국가인프라 손상, 생산차질, 소송, 기업체신뢰 상실, 경쟁력 상실, 경제적손실, 환경파괴



### Summary

-높은 보안성을 제공하기 위해 고려해야 할 점

>   CIA에서 가용성의 비중이 큼
>
>   산업 제어 시스템의 구성요소에 많은 보안 취약점 존재
>
>   Proprietary 프로토콜을 많이 사용하므로 기존 보안 솔루션의 완성도는 떨어짐

  

### 단어 뜻

>  Proprietary 프로토콜 : [원거리 통신](https://translate.googleusercontent.com/translate_c?depth=1&hl=ko&prev=search&rurl=translate.google.co.kr&sl=en&sp=nmt4&u=https://en.wikipedia.org/wiki/Telecommunications&xid=17259,15700019,15700043,15700124,15700149,15700186,15700190,15700201,15700237,15700242&usg=ALkJrhgR3yQe3AhJAW9Cay_psrvalEHo_Q) 에서 **독점** **프로토콜** 은 단일 조직 또는 개인이 소유 한 [통신 프로토콜](https://translate.googleusercontent.com/translate_c?depth=1&hl=ko&prev=search&rurl=translate.google.co.kr&sl=en&sp=nmt4&u=https://en.wikipedia.org/wiki/Communications_protocol&xid=17259,15700019,15700043,15700124,15700149,15700186,15700190,15700201,15700237,15700242&usg=ALkJrhhSIGLaCedxq8jCTWSihAa1-EtX7Q) 입니다. 