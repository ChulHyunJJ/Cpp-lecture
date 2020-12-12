//
//  baseball.cpp
//
//  Created by chj on 2020/12/08.
//

#include <iostream>
#include <time.h>

/*
 숙제 : 야구게임 만들기
 1 ~ 9 사이의 랜덤한 숫자를 3개 얻어온다. 단, 숫자는 중복되서는 안된다.
 3개의 숫자는 * * * 형태로 출력되고 이 3개의 숫자를 맞추는 게임이다.
 사용자는 이 3개의 숫자를 맞출 때 까지 계속해서 3개씩 숫자를 입력한다.
 
 만약 맞춰야할 숫자가 7 3 8 일 경우
 사용자는 3개의 숫자를 계속 입력한다.
 입력 : 1 2 4 를 입력했을 경우 1 2 4 는 맞춰야할 숫자중 아무것도 없으므로
 out 출력
 
 입력 : 7 5 9 를 입력했을 경우 7은 맞춰야할 숫자중 있고 위치도 같으므로
 strike지만 5, 9는 없으므로 출력은 1strike 0ball을 출력한다.
 
 입력 : 7 8 6 을 입력했을 경우 7은 1strike 8은 숫자는 있지만 위치가 다르므로 ball이 된다.
 1strike 1ball이 된다.
 
 이렇게 출력을 하고 입력을 받으면서 최종적으로 3개의 숫자를 자리까지 모두 일치하게 입력하면 게임이 종료된다.
 만약 입력받은 3개 숫자중 한 개라도 0이 있으면 게임이 종료된다.
 */

using namespace std;

int main()
{
    int iNumber[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    srand((unsigned int)time(0));
    
    for (int i = 0; i < 50; ++i)
    {
        int idx1 = rand() % 9;
        int idx2 = rand() % 9;
        int iTemp;
        
        iTemp = iNumber[idx1];
        iNumber[idx1] = iNumber[idx2];
        iNumber[idx2] = iTemp;
    }
    
//    for (int i = 0; i < 9; ++i)
//    {
//        cout << iNumber[i] << "\t";
//    }
    
    cout << endl;
    
    // 랜덤 3개 숫자
    int iAnswer[3] = { iNumber[0], iNumber[1], iNumber[2] };
    int iInput[3] = {};
    
    while (true)
    {
        cout << "숫자 3개를 입력하세요 : " << endl;
        cin >> iInput[0] >> iInput[1] >> iInput[2];
        
        if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0)
        {
            cout << "종료합니다." <<endl;
            break;
        }

        else if (iInput[0] < 0 || iInput[0] > 9 || iInput[1] < 0 || iInput[1] > 9 || iInput[2] < 0 || iInput[2] > 9)
        {
            cout << "잘못된 숫자를 입력하였습니다." << endl;
            continue;
        }
        
        else if (iInput[0] == iInput[1] || iInput[0] == iInput[2] || iInput[1] == iInput[2])
        {
            cout << "중복된 숫자를 입력하였습니다." <<endl;
            continue;
        }
            
        int iStrike = 0;
        int iBall = 0;
        
        // 답 체크하기
        for (int i = 0; i < 3; ++i)
        {
            for (int j =0; j < 3; ++j)
            {
                if (iInput[j] == iAnswer[i] && i == j)
                    ++iStrike;
                else if (iInput[j] == iAnswer[i] && i != j)
                    ++iBall;
                else
                    continue;
            }
        }
        
        if (iStrike == 0 && iBall == 0)
            cout << "Out" << endl;
        
        else if (iStrike == 3)
        {
            cout << "정답입니다!" << endl;
            break;
        }
        
        else
            cout << iStrike << "Strike\t" << iBall << "Ball" << endl;
    }
    return 0;
}
