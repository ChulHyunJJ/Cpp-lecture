//  bitOperator
//
//  Created by chj on 2020/12/03.
//
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    // 5. 비트논리연산자와 쉬프트연산자
    // 상수 : 변하지 않는 수. 값을 한번 지정해놓으면 바꿀 수 없다.
    // 상수는 선언과 동시에 값을 지정해두어야 한다.
    const int iAttack = 0x00000001;     //      1
    const int iArmor = 0x00000002;      //     10
    const int iHP = 0x00000004;         //    100
    const int iMP = 0x00000008;         //   1000
    const int iCritical = 0x00000010;   //  10000
    
    // 001 | 100 -> 101 | 10000 -> 10101
    int iBuf = iAttack | iHP | iCritical;
    
    // 연산자 축약형 : 연산자를 줄여서 사용할 수 있다.
    // 아래를 풀어서 쓰면
    // iBuf = iBuf ^ iHP;
    // 10101 ^ 00100 = 10001
    iBuf ^= iHP;
    
    // 10001 ^ 00100 = 10101
    iBuf ^= iHP;
    // XOR 을 사용하여 스위치처럼 껐다 켰다 할 수 있다.
    
    // 10101 & 00001 = 00001
    cout << "Attack : " << (iBuf & iAttack) << endl;
    // 10101 & 00010 = 00000
    cout << "Armor : " << (iBuf & iArmor) << endl;
    // 10101 & 00100 = 00100
    cout << "HP : " << (iBuf & iHP) << endl;
    // 10101 & 01000 = 00000
    cout << "MP : " << (iBuf & iMP) << endl;
    // 10101 & 10000 = 10000
    cout << "Critical : " << (iBuf & iCritical) << endl;
    
    /*
     쉬프트 연산자 : <<, >> 값 대 값을 연산하여 값으로 반환
     이 연산자 또한 이진수 단위의 연산을 하게 된다.
     
     20 을 2진수로 변환한다.
     10100
     
     0 을 뒤에 붙여라랑 같은 뜻
     20 << 2 = 1010000 = 80
     20 << 3 = 10100000 = 160
     20 << 4 = 320
     
     뒤에서 지워라랑 같은 뜻
     20 >> 2 = 101 = 5
     20 >> 3 = 10 = 2
     20 >> 4 = 1
     */
    
    // 비트 필드 사용법 (하나의 변수 32비트를 상위 16비트 하위 16비트로 쪼개서 사용하는방법)
    int iHigh = 187;
    int iLow = 13560;
    
    int iNumber = iHigh;
    
    // iNumber 에는 187이 들어가있다. 이 값을 <- 방향으로 16비트 이동시키면 상위 16비트로 이동한다.
    iNumber <<= 16;
    
    // 하위 16비트를 채운다.
    iNumber |= iLow;
    // High 값을 출력한다.
    cout << "High : " << (iNumber >> 16) << endl;
    cout << "Low : " << (iNumber & 0x0000ffff) << endl;
    
    // 증감연산자 : ++, -- 가 있다. 1 증가, 1 감소
    iNumber = 10;
    
    // 전치
    ++iNumber;
    
    // 후치
    iNumber++;
    
    cout << ++iNumber << endl;
    cout << iNumber++ << endl;
    cout << iNumber << endl;
    
    // 6. if 문
    /*
     분기문에는 크게 2가지 종류가 있다.
     if 문, switch 문이 존재한다.
     if 문 : 조건을 체크해주는 기능이다.
     형태 : if(조건식) {}(코드 블럭)
     if 문은 조건식이 true 가 될 경우 코드블럭 안의 동작이 실행된다.
     false 일 경우에는 동작되지 않는다.
     */
    if (true)
    {
        cout << "if 문 조건이 true 입니다." << endl;
    }
    
    // 버프가 있는지 확인한다.
    if ((iBuf & iAttack) != 0)
    {
        cout << "Attack 버프가 있습니다." << endl;
    }
    
    // if 문 내부에 들어갈 코드가 한줄 일 경우 코드블럭 생략 가능
    if ((iBuf & iArmor) != 0)
        cout << "Armor 버프가 있습니다." << endl;
    
    if ((iBuf & iHP) != 0)
        cout << "HP 버프가 있습니다." << endl;
    
    if ((iBuf & iMP) != 0)
        cout << "MP 버프가 있습니다." << endl;
    
    if ((iBuf & iCritical) != 0)
        cout << "Critical 버프가 있습니다." << endl;
    
    /*
     else : if 문과 반드시 같이 사용되어야 한다.
     if 문 조건이 false 일 경우 else가 있다면 else 구문 안의 코드가 동작된다.
     
     else if : if 문과 반드시 같이 사용되어야 한다.
     if 문 아래 와야 하고 else 보다는 위에 있어야 한다.
     else if 는 자신의 위에 있는 조건식이 false 일 경우 다음 else if 의 조건식을 체크한다.
     else if 는 몇개든 사용이 가능하다.
     */
    
    if (false)
        cout << "if 문 조건이 true 입니다." << endl;
    
    else
        cout << "if 문 조건이 false 입니다." << endl;
    
    cout << "숫자를 입력하세요 : ";
    cin >> iNumber;
    
    if (10 <= iNumber && iNumber <= 20)
        cout << "10 ~ 20 사이의 숫자입니다." << endl;
    else if (21 <= iNumber && iNumber <= 30)
        cout << "21 ~ 30 사이의 숫자입니다." << endl;
    else if (31 <= iNumber && iNumber <= 40)
        cout << "31 ~ 40 사이의 숫자입니다." << endl;
    
    else
        cout << "그 외의 숫자입니다." << endl;
        
    // 7. 난수와 확률 & if 문의 활용
    // 난수 발생
    srand((unsigned int)time(0));
    
    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;
    cout << (rand() % 101 + 100) << endl; // 100 ~ 200
    cout << (rand() % 10000 / 100.f) << endl; // 0 ~ 100 %
    
    int iUpgrade = 0;
    cout << "Upgrade 기본 수치를 입력하세요 : ";
    cin >> iUpgrade;
    
    // 강화 확률을 구한다.
    float fPercent = rand() % 10000 / 100.f;
    
    // 강화 확률 :
    // 0 ~ 3 :  100% 성공
    // 4 ~ 6 : 40% 성공
    // 7 ~ 9 : 10% 성공
    // 10 ~ 13 : 1 % 성공
    // 14 ~ 15 : 0.01% 성공
    
    cout << "Upgrade : " << iUpgrade << endl;
    cout << "Percent : " << fPercent << endl;
    
    if (iUpgrade <= 3)
        cout << "강화 성공" << endl;
    
    else if ( 4 <= iUpgrade && iUpgrade <= 6)
    {
        if (fPercent < 40.f)
            cout << "강화 성공" << endl;
        else
            cout << "강화 실패" << endl;
    }
    
    else if ( 7 <= iUpgrade && iUpgrade <= 9)
    {
        if (fPercent < 10.f)
            cout << "강화 성공" << endl;
        else
            cout << "강화 실패" << endl;
    }
    
    else if ( 10 <= iUpgrade && iUpgrade <= 13)
    {
        if (fPercent < 1.f)
            cout << "강화 성공" << endl;
        else
            cout << "강화 실패" << endl;
    }
    
    else if ( 14 <= iUpgrade && iUpgrade <= 15)
    {
        if (fPercent < 0.01f)
            cout << "강화 성공" << endl;
        else
            cout << "강화 실패" << endl;
    }
    
    return 0;
}
