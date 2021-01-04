//
// Created by 조철현 on 2020/12/21.
//

/*
 관리 프로그램 만들기
 도서대여 프로그램 만들기
 1. 책 등록
 2. 책 대여
 3. 책 반납
 4. 책 목록
 5. 종료
 */

#include <iostream>
#include <curses.h>
#include <time.h>

using namespace std;

#define NAME_SIZE 32
#define NUM_BOOKS_MAX 5

struct _tagBookInfo{
    char strBookName[NAME_SIZE];
    char strArthor[NAME_SIZE];
    char strPublisher[NAME_SIZE];
    char strStatus[NAME_SIZE];
};

enum MENU
{
    MENU_NONE,
    BOOK_REGISTER,
    BOOK_RENT,
    BOOK_RETURN,
    BOOK_LIST,
    MENU_EXIT
};

int PrintCurrentTime() {
    time_t t = time(0);   // get time now
    tm *now = localtime(&t);
    cout << (now->tm_year + 1900) << '-'
              << (now->tm_mon + 1) << '-'
              << now->tm_mday
              << endl;
    return 1;
}

int main()
{
    _tagBookInfo tBookArr[NUM_BOOKS_MAX] = {};
    int iCount = 0;
    int iMenu;
    int iAvailable = 0;

    while (true)
    {
        clear();
        cout << "=========================== 메뉴 선택 ===========================" << endl;
        cout << "1. 책 등록" << endl;
        cout << "2. 책 대여" << endl;
        cout << "3. 책 반납" << endl;
        cout << "4. 책 목록" << endl;
        cout << "5. 종료" << endl;
        cout << "메뉴를 선택해주세요 : ";
        cin >> iMenu;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }

        if (iMenu == MENU_EXIT)
            break;

        switch (iMenu){
            case BOOK_REGISTER:
            {
                clear();
                if (iCount >= NUM_BOOKS_MAX)
                {
                    cout << "책 수량을 초과하였습니다." << endl;
                }

                cout << "=========================== 책 등록 ===========================" << endl;
                cout << "현재 권수 : " << iCount << "권" << endl;
                cout << "책 이름 : ";
                cin >> tBookArr[iCount].strBookName;
                cin.ignore(1024, '\n');
                cout << "작가 : ";
                cin >> tBookArr[iCount].strArthor;
                cin.ignore(1024, '\n');
                cout << "출판사 : ";
                cin >> tBookArr[iCount].strPublisher;
                cin.ignore(1024, '\n');

                strcpy(tBookArr[iCount].strStatus, "대여가능");

                ++iCount;
                ++iAvailable;
                break;
            }

            case BOOK_RENT:
            {
                clear();
                if (iCount == 0)
                {
                    cout << "대여 가능한 책이 없습니다." << endl;
                    break;
                }

                cout << "=========================== 책 대여 ===========================" << endl;
                cout << iCount << "권의 책이 존재합니다." << endl;
                cout << "대여 가능한 책 : " << iAvailable << "권" << endl;
                for (int i = 0; i < iCount; ++i)
                {
                    if (strcmp(tBookArr[i].strStatus, "대여가능") == 0)
                    {
                        cout << i + 1 << ". ";
                        cout << "책 이름 : " << tBookArr[i].strBookName << endl;
                    }
                }

                cout << "책 번호를 입력해주세요 : ";
                cin >> iMenu;

                if (iMenu <= iCount)
                {
                    strcpy(tBookArr[iMenu - 1].strStatus, "대여중");
                }

                else
                {
                    cout << "잘못 입력하였습니다." << endl;
                    cin.clear();
                    cin.ignore(1024, '\n');
                    continue;
                }

                cout << iMenu << "번의 책이 대여되었습니다." << endl;
                cout << "책 이름 : " << tBookArr[iMenu - 1].strBookName << endl;
                cout << "저자 : " << tBookArr[iMenu - 1].strArthor << endl;
                cout << "출판사 : " << tBookArr[iMenu - 1].strPublisher << endl;
                cout << "현재 상태 : " << tBookArr[iMenu - 1].strStatus << endl << endl;

                --iAvailable;

                break;
            }

            case BOOK_RETURN:
            {
                clear();
                if (iCount == iAvailable)
                {
                    cout << "반납 가능한 책이 없습니다." << endl;
                    break;
                }

                cout << "=========================== 책 반납 ===========================" << endl;
                cout << iCount << "권의 책이 존재합니다." << endl;
                cout << "반납 가능한 책 : " << iCount - iAvailable << "권" << endl;
                for (int i = 0; i < iCount; ++i)
                {
                    if (strcmp(tBookArr[i].strStatus, "대여중") == 0)
                    {
                        cout << i + 1 << ". ";
                        cout << "책 이름 : " << tBookArr[i].strBookName << endl;
                    }
                }

                cout << "책 번호를 입력해주세요 : ";
                cin >> iMenu;

                if (iMenu <= iCount)
                {
                    strcpy(tBookArr[iMenu - 1].strStatus, "대여가능");
                }

                else
                {
                    cout << "잘못 입력하였습니다." << endl;
                    cin.clear();
                    cin.ignore(1024, '\n');
                    continue;
                }

                cout << iMenu << "번의 책이 반납되었습니다." << endl;
                cout << "책 이름 : " << tBookArr[iMenu - 1].strBookName << endl;
                cout << "저자 : " << tBookArr[iMenu - 1].strArthor << endl;
                cout << "출판사 : " << tBookArr[iMenu - 1].strPublisher << endl;
                cout << "현재 상태 : " << tBookArr[iMenu - 1].strStatus << endl << endl;

                ++iAvailable;

                break;
            }

            case BOOK_LIST:
            {
                clear();
                cout << "=========================== 책 목록 ===========================" << endl;
                cout << iCount << "권의 책이 존재합니다." << endl;
                for (int i = 0; i < iCount; ++i)
                {
                    cout << i+1 << "번째 책" << endl;
                    cout << "책 이름 : " << tBookArr[i].strBookName << endl;
                    cout << "저자 : " << tBookArr[i].strArthor << endl;
                    cout << "출판사 : " << tBookArr[i].strPublisher << endl;
                    cout << "현재 상태 : " << tBookArr[i].strStatus << endl << endl;
                }

                cout << "뒤로가기 (1)" << endl;
                cin >> iMenu;

                if (iMenu == 1)
                    break;
            }

        }
    }

    return 0;
}