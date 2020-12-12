//
//  Puzzle
//
//  Created by 조철현 on 2020/12/08.
//

#include <iostream>
#include <time.h>

// console input output 헤더파일이다. 콘솔창에서 입출력 하는 기능들을
// 제공해주는 헤더파일이다.
// #include <conio.h>
#include <stdio.h>

using namespace std;

// 15. 숫자 퍼즐게임
int main()
{
    srand((unsigned int)time(0));
    
    int iNumber[25] = {};
    
    for (int i = 0; i < 24; ++i)
    {
        iNumber[i] = i + 1;
    }
    
    // 가장 마지막은 공백으로 비워둔다. 공백을 의미하는 값으로 특수한 값을
    // 사용하는데 INT_MAX 라는 값을 사용할 것이다. INT_MAX는 이미 정의되어 있는 값으로
    // INT로 표현할 수 있는 최대 값이다.
    
    iNumber[24] = INT_MAX;
    
    // 별이 있는 위치를 저장할 변수를 만들어준다.
    int iStarIndex = 24;
    
    // 마지막 공백을 제외하고 1 ~ 24 까지의 숫자만 섞어준다. 즉 인덱스는 0 ~ 23번 까지만 섞어준다.
    
    int iTemp, idx1, idx2;
    
    for (int i = 0; i < 100; ++i)
    {
        idx1 = rand() % 24;
        idx2 = rand() % 24;
        
        iTemp = iNumber[idx1];
        iNumber[idx1] = iNumber[idx2];
        iNumber[idx2] = iTemp;
    }
    
    while (true)
    {
        // i for 문이 세로줄을 의미한다.
        for (int i = 0; i < 5; ++i)
        {
            // j for 문이 가로 칸을 의미한다.
            for (int j = 0; j < 5; ++j)
            {
                // i 가 0 일 때 j 는 0 ~ 4 까지 반복한다. 이 경우 0 * 5 + (0 ~ 4) 를 더하게 되서
                // 인덱스는 0, 1, 2, 3, 4 가 나오게 된다.
                // i 가 1 일 때 j 는 0 ~ 4 까지 반복한다. 이 경우 1 * 5 + (0 ~ 4) 를 더하게 되서
                // 인덱스는 5, 6, 7, 8, 9 가 나오게 된다.
                // i 가 2 일 때 j 는 0 ~ 4 까지 반복한다. 이 경우 2 * 5 + (0 ~ 4) 를 더하게 되서
                // 인덱스는 10, 11, 12, 13, 14 가 나오게 된다.
                // i 가 3 일 때 j 는 0 ~ 4 까지 반복한다. 이 경우 3 * 5 + (0 ~ 4) 를 더하게 되서
                // 인덱스는 15, 16, 17, 18, 19 가 나오게 된다.
                // i 가 4 일 때 j 는 0 ~ 4 까지 반복한다. 이 경우 4 * 5 + (0 ~ 4) 를 더하게 되서
                // 인덱스는 20, 21, 22, 23, 24 가 나오게 된다.
                // 줄 번호 * 가로 갯수 + 칸 번호
                if (iNumber[i * 5 + j] == INT_MAX)
                    cout << "*\t";

                else
                    cout << iNumber[i * 5 + j] << "\t";
            }
            
            cout << endl;
        }
        
        // true 로 두어 먼저 모두 맞추었다고 가정한다.
        bool bWin = true;
        
        // 퍼즐을 맞췄는지 체크한다.
        for (int i = 0; i < 24; ++i)
        {
            if (iNumber[i] != i + 1)
            {
                bWin = false;
                break;
            }
        }
        
        cout << "W : 위 S : 아래 A : 왼쪽 D : 오른쪽 Q : 종료" << endl;
        // _getch() 함수는 문자 1개를 입력받는 함수이다. 이 함수는 Enter를 치지 않아도
        // 문자를 누르는 순간 그 문자를 반환하고 종료된다.
        // char cInput = _getch();
        char cInput = getchar();
        
        if(cInput == 'q' || cInput == 'Q')
            break;
        
        switch (cInput)
        {
            case 'w':
            case 'W':
                // 가장 윗줄일때는 w를 눌러도 위로 올라가서는 안된다.
                if (iStarIndex > 4 )
                {
                    // 별이 있는 위치에 바로 위에 있는 값을 넣어준다.
                    iNumber[iStarIndex] = iNumber[iStarIndex - 5];
                    iNumber[iStarIndex - 5] = INT_MAX;
                    iStarIndex -= 5;
                }
                break;
            case 's':
            case 'S':
                // 가장 아랫줄이 아닐 경우 움직인다.
                if (iStarIndex < 20)
                {
                    iNumber[iStarIndex] = iNumber[iStarIndex + 5];
                    iNumber[iStarIndex + 5] = INT_MAX;
                    iStarIndex += 5;
                }
                break;
            case 'a':
            case 'A':
                if (iStarIndex % 5 != 0)
                {
                    iNumber[iStarIndex] = iNumber[iStarIndex - 1];
                    iNumber[iStarIndex - 1] = INT_MAX;
                    iStarIndex -= 1;
                }
                break;
            case 'd':
            case 'D':
                if (iStarIndex % 5 != 4)
                {
                    iNumber[iStarIndex] = iNumber[iStarIndex + 1];
                    iNumber[iStarIndex + 1] = INT_MAX;
                    iStarIndex += 1;
                }
                break;
        }
    }
    
    cout << endl << "게임을 종료합니다." <<endl;
    
    return 0;
}
