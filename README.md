#### * 소스 코드의 구조는 강의 목록과 같은 구조의 디렉토리로 되어 있고, 각 예제 디렉토리에는 아래와 같은 세개의 파일이 존재합니다.
<br/>
<table style="width:100%; font-variant-ligatures: none;">
<tr>
  <th><center>파일명</center></th>
  <th><center>내용</center></th>
</tr>
<tr>
  <td bgcolor='#F8F9F9'><center>example.sln</center></td>
  <td><center>Visual studio 솔루션 파일</center></td>
</tr>
<tr>
  <td bgcolor='#F8F9F9'><center>example.vcxproj</center></td>
  <td><center>Visual C++ 프로젝트 파일</center></td>
</tr>
<tr>
  <td bgcolor='#F8F9F9'><center>main.cpp</center></td>
  <td><center>예제 소스 파일</center></td>
</tr>
</table>
<br/><br/>

#### * 모든 디렉토리의 예제들이 위의 세 개의 파일들로 구성되어 있으므로 빌드와 실행 방법이 동일합니다. 아래의 내용을 참고하셔서 컴파일러별로 빌드하시면 됩니다.<br/><br/>

* Visual C++

  ```
  Visual studio에서 example.sln 파일을 연 후, 빌드 및 실행
  ```<br/>
* gcc

  소스 디렉토리로 이동 후 아래와 같이 gcc(또는 g++) 명령어로 빌드 및 실행<br/>

  [ 컴파일 및 링크 ]
  ```
  gcc -c main.cpp
  gcc -o example main.o
  ```

  [ 실행 ]
  ```
  ./example
  ```
  <br/>참고로, 위와 같이 컴파일과 링크를 실행했을 때, gcc가 64bit 버전으로 설치되어 있으면 기본적으로 64bit 바이너리가 생성되고, 32bit가 설치되어 있으면 32bit 바이너리가 생성됩니다.

  이때, -m64 또는 -m32 옵션을 통해 강제로 생성되는 바이너리의 bit를 설정할 수 있습니다.<br/><br/>

  * 64bit로 빌드
  ```
  gcc -m64 -c main.cpp
  gcc -m64 -o example main.o
  ```
  * 32bit로 빌드 (단, 64bit gcc가 설치되 환경에서는 libc6-dev-i386와 gcc-multilib 같은 32bit용 개발 패키지가 설치되어 있어야 함)
  ```
  gcc -m32 -c main.cpp
  gcc -m32 -o example main.o
  ```
