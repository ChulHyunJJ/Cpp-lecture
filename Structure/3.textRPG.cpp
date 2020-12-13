//
// Created by chj on 2020/12/12.
//

#include <iostream>
#include <curses.h>
#include <time.h>

using namespace std;

enum MAIN_MENU
{
    MM_NONE,
    MM_MAP,
    MM_STORE,
    MM_INVENTORY,
    MM_EXIT
};

enum MAP_TYPE
{
    MT_NONE,
    MT_EASY,
    MT_NORMAL,
    MT_HARD,
    MT_BACK
};

enum JOB {
    JOB_KIGHT,
    JOB_ARCHER,
    JOB_WIZARD
};

#define NAME_SIZE 32

struct _tagPlayer
{
    char strName[NAME_SIZE];
    char strJobName[NAME_SIZE];
    JOB eJOB;
    int iAttackMin;
    int iAttackMax;
    int iArrmorMin;
    int iArrmorMax;
    int iHP;
    int iHPMax;
    int iMP;
    int iMPMax;
    int iExp;
    int iLevel;
};

struct _tagMonster{
    char strName[NAME_SIZE];
    int iAttackMin;
    int iAttackMax;
    int iArrmorMin;
    int iArrmorMax;
    int iHP;
    int iHPMax;
    int iMP;
    int iMPMax;
};

int main()
{
    while (true)
    {
        clear();
        cout << "1. 맵" << endl;
        cout << "2. 상점" << endl;
        cout << "3. 가방" << endl;
        cout << "4. 종료" << endl;
        cout << "메뉴를 선택하세요 : ";
        int iMenu;
        cin >> iMenu;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }

        if (iMenu == MM_EXIT)
            break;

        switch(iMenu)
        {
            case MM_MAP:
                while (true)
                {
                    clear();
                    cout << "***************************** 로비 *****************************" << endl;
                    cout << "1. 쉬움" << endl;
                    cout << "2. 보통" << endl;
                    cout << "3. 어려움" << endl;
                    cout << "4. 뒤로가기" << endl;
                    cout << "맵을 선택하세요 : ";
                    cin >> iMenu;

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(1024, '\n');
                        continue;
                    }

                    // 이 if 문 내부의 break 는 맵 메뉴를 표시하기 위한 반복문을 탈출한다.
                    if (iMenu == MT_BACK)
                        break;
                }
                break;
            case MM_STORE:
                break;
            case MM_INVENTORY:
                break;
            default:
                cout << "잘못 선택하였습니다." << endl;
                break;
        }
    }

    return 0;
}