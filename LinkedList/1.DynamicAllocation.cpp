#include <iostream>

using namespace std;

int main() {
    /* 43.동적할당
     동적할당 : 메모리 생성을 원하는 시점에 할 수 있는 기능
     메모리 영역 중 힙 영역 공간에 할당된다.
     힙의 특성상 메모리를 해제하기 전까지는 계속 남아있다.
     동적할당을 하고 메모리를 해제하지 않으면 사용하지는 않지만 공간은 계속 잡혀있게 된다.
     해당 공간은 다른 곳에서 사용이 불가능 하다.
     이런 현상을 메모리 leak 이라고 한다.

     동적 할당은 new 키워드를 이용해서 할 수 있다.
     C언어 에서는 malloc() 함수를 이용해서 할 수 있다.

     new 할당 타입; 으로 처리한다.
     new나 malloc() 둘다 마찬가지로 힙 영역에 메모리 공간을 할당하고 해당 메모리에 주소를 반환해준다.

     delete 키워드를 이용해서 동적할당한 메모리를 해제할 수 있다.
     delete 메모리주소;
    */

    // 아래처럼 할당해주면 힙에 new 뒤에 들어오는 타입인 int의 크기만큼 공간을 할당한다.
    // 즉 4바이트 공간을 할당한다. 그 뒤에 할당한 공간의 메모리 주소를 pNumber에 넣어주었다.
    // 동시에 stack 에 int* 변수가 할당된다.
    int* pNumber = new int;

    // pNumber이 가리키는 주소에 100을 할당하겠다.
    *pNumber = 100;

    delete pNumber;

    /*
     동적배열 할당방법 : new 타입[개수]; 의 형태로 사용할 수 있다.
     배열의 특성 : 연속된 메모리 주소를 참조한다.
     동적 배열을 지울때는 delete[] 메모리주소;
     */
    // 아래처럼 동적배열로 할당하면 메모리 공간에 400바이트만큼 공간을 할당하고 해당 메모리의 시작주소를 반환한다.
    int* pArray = new int[100];

    pArray[1] = 300;

    cout << "pArray Address : " << pArray << endl;
    cout << "pArray Value : " << *pArray << endl;

    delete[] pArray;

    return 0;
}
