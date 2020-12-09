//  do_while.cpp
//
//  Created by chj on 2020/12/07.
//

#include <iostream>
#include <time.h>

using namespace std;


int main()
{
    // 12. 배열
    /*
     do while 문 : 반복문의 한 종류이다.
     형태 : do {} while(조건식); 의 형태로 구성된다.
     while 문은 처음 진입부터 조건식을 체크하지만 do while 문은 처음 한번은
     무조건 동작이 되고 그 후에 조건식을 체크해서
     true 일 경우 동작이 된다.
     */
    int iNumber = 0;
    int iNumber1 = 0 , iNumber2 = 0, iNumber3 = 0;
    
    do {
        //cout << iNumber << endl;
    } while (iNumber > 0);
    
    /*
     배열 : 여러 개의 변수를 한번에 생성해줄 수 있는 기능이다.
     형태 : 변수타입 배열명[개수]: 의 형태로 선언할 수 있다.
     배열의 특징 : 배열은 연속된 메모리 블럭에 공간이 할당된다.
     배열은 인덱스를 이용해서 원하는 부분에 접근하여 값을 저장할 수 있다.
     인덱스는 0부터 갯수 - 1 까지이다. 즉, 10개라면 0 ~ 9 까지의 총 10개의 인덱스를 갖는다.
     */
    
    // 배열 뿐만 아니라 일반 변수들도 선언을 하고 값을 초기화하지 않을 경우 쓰레기 값이 들어간다.
    // int iArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // 0 ~ 4 번까지는 1, 2, 3, 4, 5 의 값이 들어가게 되고 나머지는 전부 0으로 초기화된다.
    // int iArray[10] = {1, 2, 3, 4, 5};
    
    // 비어있는 중괄호를 대입해줄 경우 모든 인덱스를 0으로 초기화한다.
    int iArray[10] = {};
    
    iArray[1] = 1234;
    
    cout << iArray[5] << endl;
    
    for (int i = 0; i < 10; ++i)
    {
        cout << iArray[i] << endl;
    }
    
    /*
     배열 개수를 2개 지정하면 이차원배열이 된다. 3개 지정하면 3차원 배열이 된다.
     2차원 배열의 갯수는 앞의수 * 뒤의수가 된다.
     */
    
    int iArray2[10][10] = { { 1, 2, 3 }, {4, 5, 6} };
    // int iArr[999999999];
    for (int i =0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cout << iArray2[i][j] << "\t";
        }
        cout << endl;
    }
    
    system("cls");
    
    srand((unsigned int)time(0));
    
    // Lottery Program
    int iLotto[45] = {};
    
    // 1에서 45까지 숫자를 차례로 넣어준다.
    for (int i = 0; i < 45; ++i)
    {
        iLotto[i] = i + 1;
    }
    
    // Swap 알고리즘
//    int iNum1 = 1, iNum2 = 2, iNum3;
//    iNum3 = iNum1;
//    iNum1 = iNum2;
//    iNum2 = iNum3;
    
    // Shuffle
    int iTemp, idx1, idx2;
    // 100번정도 골고루 섞어준다.
    for (int i = 0; i < 100; ++i)
    {
        idx1 = rand() % 45;
        idx2 = rand() % 45;
        
        iTemp = iLotto[idx1];
        iLotto[idx1] = iLotto[idx2];
        iLotto[idx2] = iTemp;
    }
    
    for (int i = 0; i < 45; ++i)
    {
        cout<< iLotto[i] << endl;
    }
    
    for (int i =0; i<6; ++i)
    {
        cout << iLotto[i] << "\t";
    }
    
    cout << "Bonus Number : " << iLotto[6] << endl;
    
    return 0;
}
