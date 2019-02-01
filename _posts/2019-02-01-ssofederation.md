---
layout: post
title:  "SSO & ID federation 기술"
subtitle: "OpenID Connect, OAuth2 등"
date:   2019-02-01 2:10:02
categories: [IoT]
---

##  **SSO & ID federation** **기술** 

<br>

### 1. SAML/OAuth2/OpenID Connect 개요

- Single Sign-ON 이란?

  : 사용자는 한 번 인증받으면 응용 프로그램은 서비스와 통신하여 반복적으로 암호를 입력하지 않고도 사용자의 신원을 확인할 수 있다. 즉 한번의 로그인으로 여러 개의 사이트에 접속 가능

 <br>

- SAML (Security Assertion Markup Language) : 인증 + 인가

  : 보안 도메인간에 인증 및 권한부여 정보를 교환하기 위한 표준

  : XML, SSO for enterprise apps

  <br>

- OpenID Connect(OIDC) : 인증

   표준을 통해 조직간의 인증을 공유할 수 있다

  ex – 야후를 openid 인증 provider로 결정하면 사용자인증을 위해 야후로 redirect

   모바일기기와 NATIVE APP에 사용될 수 있다.

   OAuth2 authorization flow에 identity token을 추가하여, end-user에 대한 기본 정보 제공/ end-user 신원 확인에 사용됨.

   JSON, SSO for consumer apps
  - Authorization : 나임을 확인하는 것

  - Authentication : 사용자가 access할수 있는 권한 부여

     <br>

- Oauth2 : 인가

  : delegated access(ex – facebook)제공, 

  즉 application은 사용자의 동의를 받고 application과 중요한 비밀정보 공유없이 자원에 접근하게 해줌

  : identity propider가 3rd party application에 token을 발행함으로서 가능

  : JSON



### 2. OIDC(OpenID Connect)

- 사용자는 직접적으로 접근 토큰을 받지 않는다.
- 분산된 SSO시스템

![img](/assets/x.png)

①     사용자(브라우저)가 서비스에 접속하겠다고 함

Service’s Answer : 서비스사이트는 사용자에게 인증을 요구함 (너가 맞는지 증거를 대)

②     사용자가 OIDC Offering Party에게 인가 받고 싶다 함(인증해주세요! 왜냐하면 인가 받고 싶어요)

OP’s Answer : 너는 login jsp에가서 인증 받아야 돼

③     사용자가 login jsp의 주소를 알게 됨

④     사용자는 ID와 Password를 입력함

OP’s Answer : 자. 여기! 서비스에 보낼 인가코드야 (OP는 서비스사이트에 사용자를 인증했다는 사실을 보낼 예정이다)

⑤     사용자는 서비스 사이트에 인가코드를 주며 나는 권한이 있다는 것을 확인시킴

⑥     서비스사이트는 OP에게 이 인가코드에 대한 토큰을 달라고 함.

OP’s Answer : 자 여기! access_token과 refresh_token, id_token이야

⑦     서비스사이트는 OP에게 접근토큰을 주며 user의 정보를 달라고함

OP’s Answer : 추가정보를 줌

⑧     서비스사이트는 사용자에게 서비스 제공

<br><Br>

### 3. Oauth2

- Client가 접근토큰을 직접 받기 때문에 인증이아니다.

![img](/assets/x2.png)<br>

- frontend

①     Client가 User Agent에게 인가체계 시작하라고 함

②     사용자가 자기정보를 User Agent에게 넘김, User Agent는 Server에게 넘김

③     Server는 정보를 확인하고 인가코드를 User Agent에게 넘김

④     User Agent는 인가코드를 Client에게 넘김

<br>

- backend

⑤     Client는 Server에게 자신의 비밀정보와 인가코드를 보내며 접근토큰을 요청함

⑥     Server는 Client와 코드를 확인하고 접근토큰을 Client에게 준다.

- interact

⑦     Client는 접근토큰을 가지고 Resource Server에 API요청

⑧     Resource Server는 확인하고 Client에게 응답

<br><br>

### 4. API Security

![img](/assets/x3.png)

- FIDO : Fast Identity Online 단체이름. 안전하고 인증시스템을 구축하고 기술 표준 제시

  ->여기서의 인증은 절차가 아닌 수단

- Provisioning, Identities : ID관리 체계

- Federation : 인증에 대한 기본 골격수단을 제공

- Delegated Access : 인가체계