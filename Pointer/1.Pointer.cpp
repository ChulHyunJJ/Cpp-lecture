#include <iostream>

using namespace std;

struct _tagStudent
{
  int iKor;
  int iEng;
  int iMath;
  int iTotal;
  float fAvg;
};

int main()
{
    /*
     포인터 : 가리키다. 일반 변수는 일반적인 값을 저장하게 되지만
     포인터 변수는 메모리 주소를 저장하게 된다. 모든 변수 타입은 포인터 타입을 선언할 수 있다.
     int 변수의 주소는 int 포인터 변수에 저장을 해야한다.
     포인터는 메모리 주소를 담아놓는 변수이기 때문에 x86 으로 개발할 때는 무조건 4bytes 가 나온다.
     x64 일때는 8bytes 가 나온다.

     포인터는 자기 스스로 아무런 일도 할 수 없다. 반드시 다른 변수의 메모리 주소를 가지고 있어야
     일을 할 수 있는데 가지고 있는 메모리 주소에 접근하여 값을 제어할 수 있다.

     형태 : 변수타입 * 변수명; 의 형태로 선언한다.
     */

    int iNumber = 100;
    // 변수 선언시 *을 붙여주면 해당 타입의 포인터 변수가 선언된다.
    // 변수 앞에 &을 붙여주면 해당 변수의 메모리 주소가 된다.
    // pNum 은 iNumber 의 메모리 주소를 값으로 갖게 된다.
    // 그러므로 pNum 을 이용해서 iNumber 의 값을 제어할 수 있게 되었다.
    int *pNum = &iNumber;

    cout << sizeof(int*) << endl;
    cout << sizeof(char*) << endl;
    cout << sizeof(double*) << endl;

    // pNum을 이용해서 iNumber 의 값을 제어해보자.
    // 역참조를 이용해서 값을 얻어오거나 변경할 수 있다.
    // 역참조는 포인터 변수 앞에 * 을 붙이게 되면 역참조가 된다.
    cout << *pNum << endl;
    *pNum = 1234;

    cout << "iNumber Value : " << iNumber << endl;
    cout << "iNumber Address : " << &iNumber << endl;
    cout << "pNum Value : " << pNum << endl;
    cout << "pNum Address : " << &pNum << endl;

    /*
     포인터와 배열의 관계 : 배열명은 포인터다.
     배열명 자체가 해당 배열이 저장된 메모리에서의 시작점 주소를 가리킨다.
     */

    int iArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Array Address : " << iArray << endl;
    cout << "Array Address : " << &iArray[0] << endl;

    int *pArray = iArray;

    cout << pArray[2] << endl;

    /*
     포인터 연산 : +, - 연산을 제공한다. ++, -- 연산도 가능한데 1을 증가하게 되면
     단순히 메모리주소값이 1 증가하는 것이 아니다.
     int 포인터의 경우 int 타입의 메모리 주소를 갖게 되는데 메모리 주소에 1을 더해주면
     1증가가 아닌 가리키는 해당 포인터 타입의 변수 타입 크기만큼 증가하게 된다.
     int 포인터의 경우 int 의 크기인 4 만큼 값이 증가한다.
     */

    cout << pArray << endl;
    cout << pArray + 2 << endl;
    cout << *pArray << endl;
    cout << *(pArray + 2) << endl;
    cout << *pArray + 100 << endl;

    char *pText = "테스트문자열";

    cout << pText << endl;
    cout << (int*)pText << endl;

    pText = "abcd";

    cout << pText << endl;
    cout << (int*)pText << endl;

    pText = "abcdefg";

    cout << pText << endl;
    cout << (int*)pText << endl;

    char str[8] = "abcdefg";

    cout << str << endl;
    cout << (int*)str << endl;
    cout << (int*)&str << endl;

    _tagStudent tStudent = {};

    tStudent.iKor = 100;

    _tagStudent *pStudent = &tStudent;

    // 연산자 우선순위 때문에 .을 먼저 연산한다.
    // 메모리 주소. 은 잘못된 문법이다.
    // 그러므로 괄호로 감싸준 후에 .을 이용해서 가리키는 멤버변수에 접근해야 한다.
    (*pStudent).iKor = 50;

    //메모리주소-> 을 이용해서 가리키는 대상의 멤버에 접근할 수 있다.
    // 위 아래 같은 문법이다. 주로 -> 방식을 자주 사용
    pStudent->iKor = 80;

    cout << tStudent.iKor << endl;

    // void : 타입이 없다. void의 포인터타입을 활용할 수 있다.
    // void* 변수를 선언하게 되면 이 변수는 어떤 타입의 메모리 주소든 모두 저장 가능하다.
    // 단, 역참조가 불가능하고 메모리 주소만 저장 가능하다.
    void *pVoid = &iNumber;

    cout << "iNumber Address : " << pVoid << endl;
    //*pVoid = 10;
    int *pConvert = (int*)pVoid;
    *((int*)pVoid) = 9999;
    *pConvert = 10101010;

    cout << *pConvert << endl;

    pVoid = &tStudent;

    cout << "tStudent Address : " << pVoid << endl;

    int iNumber1 = 1111;
    iNumber = 2222;
    pNum = &iNumber;

    // 이중 포인터 : *을 2개 붙인다. 일반 포인터 변수가 일반 변수의 메모리 주소를 저장하는 변수라면
    // 이중 포인터는 포인터의 포인터이다. 즉 이중 포인터는 포인터 변수의 메모리를 저장하는 포인터이다.
    int **ppNum = &pNum;

    *ppNum = &iNumber1;
    *pNum = 3333;

    cout << "iNumber1 : " << iNumber1 << endl;
    cout << "iNumber : " << iNumber << endl;
    cout << "iNumber Addr : " << &iNumber << endl;
    cout << "*pNum : " << *pNum << endl;
    cout << "pNum Value : " << pNum << endl;
    cout << "pNum addr : " << &pNum << endl;
    cout << "*ppNum : " << *ppNum << endl;
    cout << "**ppNum : " << **ppNum << endl;
    cout << "ppNum Value : " << ppNum << endl;
    cout << "ppNum Addr : " << &ppNum << endl;

    return 0;
}
