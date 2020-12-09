// for 문 연습
//
//  Created by 조철현 on 2020/12/07.
//

#include <iostream>

/*
 숙제 :
 1. 구구단을 2단부터 9단까지 출력하는 중첩 for 문을 만들어 보자.
 2. 별을 아래의 형태로 출력되게 한다.
 *
 **
 ***
 ****
 *****
 
 3. 별을 아래의 형태로 출력되게 한다.
 *****
 ****
 ***
 **
 *
 
 4. 별을 아래의 형태로 출력되게 한다.
    *
   ***
  *****
 *******
 */
using namespace std;

int main()
{
    // 1. 구구단을 2단부터 9단까지 출력하는 중첩 for 문을 만들어 보자.
    for (int i = 2; i < 10; ++i)
    {
        for (int j = 1; j < 10; ++j)
        {
            cout << i << " * " << j << " = " << i * j << endl;
        }
    }
    
//    2. 별을 아래의 형태로 출력되게 한다.
//    *
//    **
//    ***
//    ****
//    *****
    for (int i=1; i<=5; ++i)
    {
        for (int j=1; j<=i; ++j)
        {
            cout << "*";
        }
        cout << endl;
    }
    
//    3. 별을 아래의 형태로 출력되게 한다.
//    *****
//    ****
//    ***
//    **
//    *
    for (int i=1; i<=5; ++i)
    {
        for (int j=5; j>=i; --j)
        {
            cout << "*";
        }
        cout << endl;
    }
//    4. 별을 아래의 형태로 출력되게 한다.
//       *
//      ***
//     *****
//    *******
    for (int i=1; i<=4; ++i)
    {
        for (int k=3; k>=i; --k)
        {
            cout << " ";
        }
        for (int j=1; j<=2*i-1; ++j)
        {
            cout << "*";
        }
        cout << endl;
    }
    
    /*
     2단 3단  4단
     5단 6단  7단
     8단 9단  10단
     */
    for (int i=2; i<11; i+=3)
    {
        for (int j = 1; j <= 9; ++j)
        {
            cout << i << " * " << j << " = " << i * j << "\t";
            cout << i + 1 << " * " << j << " = " << (i+1) * j << "\t";
            cout << i + 2 << " * " << j << " = " << (i+2) * j << endl;
        }
        cout << endl;
    }
    
    /*
        *
       ***
      *****
     *******
      *****
       ***
        *
     */
    int iLine = 7;
    int iCount = 0;
    for (int i = 0; i<7; ++i)
    {
        // 공백 3 2 1 0 1 2 3
        // 별 1 3 5 7 5 1
        iCount = i;
        
        // i 값이 7줄 기준 4, 5, 6 즉 밑의 삼각형을 구성할 때만 if 문에 들어가게 한다.
        if (i > iLine / 2)
        {
            iCount = iLine - 1 - i;
        }
        
        // i 값이 0, 1, 2, 3 일 때는 iCount 는 i 값을 따른다.
        // i 값이 4, 5, 6 일 때는 iCount 가 2, 1, 0 이 된다.
        // 최종 i 값은 0, 1, 2, 3, 2, 1 0 으로 들어가게 된다.
        
        for (int j =0; j < 3 - iCount; ++j)
        {
            cout << " ";
        }
        
        for (int j =0; j < iCount * 2 + 1; ++j)
        {
            cout << "*";
        }
        
        cout << endl;
    }
    
    return 0;
}
