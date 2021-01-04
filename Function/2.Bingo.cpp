//
//  bingo
//
//  Created by chj on 2020/12/09.
//

#include <iostream>
#include <climits>
#include <time.h>

/*
 숙제 : TextRPG를 함수로 만들어보자.
 */

using namespace std;

enum AIMode{
    AI_EASY = 1 ,
    AI_HARD = 2
};

enum LINE_NUMBER
{
    LN_H1,
    LN_H2,
    LN_H3,
    LN_H4,
    LN_H5,
    LN_V1,
    LN_V2,
    LN_V3,
    LN_V4,
    LN_V5,
    LN_LT,
    LN_RT
};


// 함수는 선언과 정의 부분으로 나눌 수 있다.
void SetNumber(int *pArray);
void Shuffle(int *pArray);
AIMode SelectAIMode();
void OutputNumber(int *pArray, int iBingo);
bool ChangeNumber(int *pArray, int iInput);
int SelectAINumber(int *pArray, AIMode eMode);
int BingoCounting(int *pArray);
int BingoCountingH(int *pArray);
int BingoCountingV(int *pArray);
int BingoCountingLTD(int *pArray);
int BingoCountingRTD(int *pArray);

int main()
{
    int iNumber[25] = {};
    int iAINumber[25] = {};
    int iInput;
    srand((unsigned int)time(0));

    // 배열에 숫자 채워넣기
    SetNumber(iNumber);
    SetNumber(iAINumber);

    // 배열 섞기
    Shuffle(iNumber);
    Shuffle(iAINumber);

    int iBingo = 0, iAIBingo = 0;
    // AI 난이도를 선택한다.
    AIMode eAIMode = SelectAIMode();

    /*
     AI Easy 모드는 현재 AI의 숫자 목록 중 *로 바뀌지 않을 숫자 목록을 만들어서
     그 목록중 하나를 선택하게 한다. (랜덤하게)
     */

    while (true)
    {
        // system("cls");
        // 섞인 배열 출력
        cout << "============= Player ===============" << endl;
        OutputNumber(iNumber, iBingo);

        // AI 배열 출력
        cout << "================ AI =================" << endl;
        OutputNumber(iAINumber, iAIBingo);

        if (iBingo >= 5)
        {
            cout << "Player 가 이겼습니다." << endl;
            break;
        }

        else if (iAIBingo >= 5)
        {
            cout << "AI 가 이겼습니다." << endl;
            break;
        }

        cout << "숫자를 입력하세요(0 = 종료) : ";
        cin >> iInput;

        if (iInput == 0)
            break;

        else if (iInput < 1 || iInput > 25)
        {
            cout << "잘못된 숫자입니다." << endl;
            continue;
        }

        // 중복을 체크하기 위한 변수
        bool bAcc = ChangeNumber(iNumber, iInput);

        // bAcc 변수가 true일 경우 중복된 숫자를 입력해서 숫자를 *로 바꾸지 못했으므로
        // 다시 입력을 받을 수 있도록 해준다.
        if (bAcc)
            continue;

        // 중복이 아니라면 AI의 숫자도 찾아서 * 로 바꿔준다.
        ChangeNumber(iAINumber, iInput);

        // AI가 숫자를 선택한다. AI 모드에 맞추어 선택되도록 함수가 구성되어 있다.
        iInput = SelectAINumber(iAINumber, eAIMode);

        ChangeNumber(iNumber, iInput);
        ChangeNumber(iAINumber, iInput);

        // AI가 숫자를 선택했으므로 플레이어와 AI의 숫자를 *로 바꿔준다.
        for (int i = 0; i < 25; ++i)
        {
            if (iNumber[i] == iInput)
            {
                iNumber[i] = INT_MAX;
                break;
            }
        }

        // AI 숫자 바꿔준다.
        for (int i = 0; i < 25; ++i)
        {
            if (iAINumber[i] == iInput)
            {
                iAINumber[i] = INT_MAX;
                break;
            }
        }

        // 빙고 줄 수를 체크하는 것은 매번 숫자를 입력할 때 마다 새로 체크를 할 것이다.
        // 매번 iBingo 를 0으로 초기화하고 새로 빙고 갯수를 구해준다.
        iBingo = BingoCounting(iNumber);
        iAIBingo= BingoCounting(iAINumber);
    }
    cout << endl;

    return 0;
}

void SetNumber(int *pArray)
{
    for (int i = 0; i < 25; ++i)
    {
        pArray[i] = i + 1;
    }
}

void Shuffle(int *pArray)
{
    int iTemp, idx1, idx2;
    for (int i = 0; i < 100; ++i)
    {
        idx1 = rand() % 25;
        idx2 = rand() % 25;

        iTemp = pArray[idx1];
        pArray[idx1] = pArray[idx2];
        pArray[idx2] = iTemp;
    }
}

AIMode SelectAIMode()
{
    int iAIMode;
    while (true)
    {
        cout << "1. Easy" << endl;
        cout << "2. Hard" << endl;
        cout << "AI 모드를 선택하세요 : ";
        cin >> iAIMode;

        if (iAIMode >= AI_EASY && iAIMode <= AI_HARD)
            break;
    }

    return (AIMode)iAIMode;
}

void OutputNumber(int *pArray, int iBingo)
{
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (pArray[i * 5 + j] == INT_MAX)
                cout << "*\t";
            else
                cout << pArray[i * 5 + j] << "\t";
        }

        cout << endl;
    }

    cout << "Bingo Line : " << iBingo << endl;
}

bool ChangeNumber(int *pArray, int iInput)
{
    // 모든 숫자를 차례대로 검사해서 입력한 숫자와 같은 숫자가 있는지 찾아낸다.
    for (int i = 0; i< 25; ++i)
    {
        // 같은 숫자가 있는 경우
        if(iInput == pArray[i])
        {
            // 중복된 숫자가 아닌경우 bAcc를 false로 초기화한다.
            pArray[i] = INT_MAX;

            //더이상 다른 숫자를 찾아볼 필요가 없으므로 반복문을 빠져나간다.
            return false;
        }
    }

    // 여기까지 오게 되면 return false 가 작동하지 않은 것이므로 중복된 숫자가 없다는 뜻이다.
    // 즉 여기서는 true를 return 한다.
    return true;
}

int SelectAINumber(int *pArray, AIMode eMode)
{
    // 선택안된 목록 배열을 만들어준다.
    int iNoneSelect[25] = {};
    // 선택안된 숫자 개수를 저장한다.
    int iNoneSelectCount = 25;
    switch (eMode)
    {
        /*
         AI Easy 모드는 현재 AI의 숫자목록 중 * 로 바뀌지 않은 숫자 목록에서
         랜덤하게 하나를 선택한다.
         */
        case AI_EASY:
            // 선택안된 숫자 목록을 만들어준다.
            iNoneSelectCount = 0;

            for (int i = 0; i < 25; ++i)
            {
                if (pArray[i] != INT_MAX)
                {
                    // * 이 아닌 숫자일 경우 iNoneSelectCount를 인덱스로 활용한다.
                    // 선택 안된 목록에 추가할 때 마다 개수를 1 증가시켜 선택되지 않은 숫자 개수를 구한다.
                    // 카운트가 추가될 때 마다 숫자가 추가 된 것으로 세팅된다.
                    iNoneSelect[iNoneSelectCount] = pArray[i];
                    ++iNoneSelectCount;
                }
            }
            // for 문을 빠져나오게 되면 선택안된 목록이 만들어지고
            // 선택안된 목록의 개수가 만들어지게 된다.
            // 선택안된 목록의 숫자중 랜덤한 하나의 숫자를 얻어오기 위해
            // 인덱스를 랜덤하게 구해준다
            return iNoneSelect[rand() % iNoneSelectCount];

        case AI_HARD:
        {
            // 하드 모드는 현재 숫자중 빙고 가능성이 가장 높은 줄을 찾아서
            // 그 줄에 있는 숫자중 하나를 * 로 만들어 준다.
            int iLine = 0;
            int iStarCount = 0;
            int iSaveCount = 0;

            // 가로 세로 라인 중 가장 * 이 많은 라인을 찾아낸다.
            for (int i = 0; i < 5; ++i)
            {
                iStarCount = 0;
                for (int j = 0; j < 5; ++j)
                {
                    if (pArray[i * 5 + j] == INT_MAX)
                        ++iStarCount;
                }

                // 별이 5개 미만이어야 빙고 줄이 아니고 다른 라인들보다 별이 많아야 하므로
                // 라인을 교체해주고 저장된 별 수를 교환한다.
                // 가로 라인 0 ~ 4 로 의미를 부여했다.
                if (iStarCount < 5 && iSaveCount < iStarCount)
                {
                    iLine = i;
                    iSaveCount = iStarCount;
                }
            }

            // 가로 라인 중 가장 별이 많은 라인은 구했다.
            // 이 값과 세로 라인을 비교하여 별이 가장 많은 라인을 구한다.
            for (int i =0; i < 5; ++i)
            {
                for (int j =0; j < 5; ++j)
                {
                    if (pArray[j * 5 + i] == INT_MAX)
                    {
                        ++iStarCount;
                    }
                }

                if (iStarCount < 5 && iSaveCount < iStarCount)
                {
                    // 세로 라인은 5 ~ 9 로 의미를 부여했다.
                    iLine = i + 5;
                    iSaveCount = iStarCount;
                }
            }



            // 모든 라인을 조사했으면 iLine에 가능성이 가장 높은 줄 번호가 저장되었다.
            // 그 줄에 있는 * 이 아닌 숫자 중 하나를 선택하게 한다.
            // 가로줄에 있을 겨우
            if (iLine <= LN_H5)
            {
                // 가로줄 iLine 0 ~ 4
                for (int i =0; i<5; ++i)
                {
                    if (pArray[iLine * 5 + i] != INT_MAX)
                    {
                        return pArray[iLine * 5 + i];
                    }
                }
            }


            else if (iLine <= LN_V5)
            {
                // 세로줄일 경우 iLine이 5 ~ 9 사이 값이다.
                for (int i = 0; i < 5; ++i)
                {
                    if(pArray[i * 5 + (iLine - 5)] != INT_MAX)
                        return pArray[i * 5 + (iLine - 5)];
                }
            }

            else if (iLine == LN_LT)
            {
                for (int i = 0; i < 25; i += 6)
                {
                    if (pArray[i] != INT_MAX)
                    {
                        return pArray[i];
                    }
                }
            }

            else if (iLine == LN_RT)
            {
                for (int i = 4; i <= 20; i += 4)
                {
                    return pArray[i];
                }
            }
            break;
        }
    }

    return -1;
}

int BingoCounting(int *pArray)
{
    int iBingo = 0;

    // 가로줄 체크
    iBingo += BingoCountingH(pArray);
    // 세로줄 체크
    iBingo += BingoCountingV(pArray);
    // 왼쪽 상단 대각선 체크
    iBingo += BingoCountingLTD(pArray);
    // 오른쪽 상단 대각선 체크
    iBingo += BingoCountingRTD(pArray);

    return iBingo;
}

int BingoCountingH(int *pArray)
{
    // 가로, 세로 줄 수를 구해준다.
    int iStar1 = 0, iBingo = 0;
    for (int i =0; i < 5; ++i)
    {
        // 한줄을 체크하기 전에 먼저 0으로 별 개수를 초기화한다.
        iStar1 = 0;
        for (int j =0; j < 5; ++j)
        {
            // 가로 별 갯수를 구해준다.
            if (pArray [i * 5 + j] == INT_MAX)
                ++iStar1;
        }

        // j for 문을 빠져나오고 나면 현재 줄의 가로 별 갯수가 몇 개인지 iStar1 수에 들어가게 된다.
        if (iStar1 == 5)
            iBingo += 1;
    }

    return iBingo;
}
int BingoCountingV(int *pArray)
{
    // 세로 줄 수를 구해준다.
    int iStar1 = 0, iBingo = 0;
    for (int i =0; i < 5; ++i)
    {
        // 한줄을 체크하기 전에 먼저 0으로 별 개수를 초기화한다.
        iStar1 = 0;
        for (int j =0; j < 5; ++j)
        {
            // 세로 별 갯수를 구해준다.
            if (pArray [j * 5 + i] == INT_MAX)
                ++iStar1;
        }

        // j for 문을 빠져나오고 나면 현재 줄의 가로 별 갯수가 몇 개인지 iStar1 수에 들어가게 된다.
        if (iStar1 == 5)
            iBingo += 1;
    }

    return iBingo;
}
int BingoCountingLTD(int *pArray)
{
// 왼쪽 -> 오른쪽 대각선 체크
    int iStar1 = 0, iBingo = 0;
    for (int i = 0; i < 25; i += 6)
    {
        if (pArray[i] == INT_MAX)
        {
            ++iStar1;
        }
    }

    if (iStar1  == 5)
    {
        ++iBingo;
    }

    return iBingo;
}
int BingoCountingRTD(int *pArray)
{
    // 오른쪽 -> 왼쪽 대각선 체크
    int iStar1 = 0, iBingo = 0;
    for (int i = 4; i < 21; i += 4)
    {
        if (pArray[i] == INT_MAX)
        {
            ++iStar1;
        }
    }

    if (iStar1  == 5)
    {
        ++iBingo;
    }

    return iBingo;
}