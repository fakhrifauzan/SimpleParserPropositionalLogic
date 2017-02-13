#include "stack.h"
void createStack(Stack &S){
    for(int i=0; i<=19; i++){
        S.info[i] = 0;
    }
    top(S) = -1;
}

void push(Stack &S, infotype x){
    if (top(S) == 19){
        cout << "Stack Penuh";
    } else{
        top(S)++;
        S.info[top(S)] = x;
    }
}

infotype pop(Stack &S){
    if (top(S) == -1){
        return 0;
    } else{
        top(S)--;
        return S.info[top(S)+1];
    }
}

void printInfo(Stack S){
    if(top(S) == -1){
        cout << "Stack Kosong";
    } else{
        cout << "[TOP] ";
        for (int i=top(S); i>-1; i--){
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}
