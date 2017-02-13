#include<iostream>
#include<conio.h>
using namespace std;

void tokenn(char stringnormal[100]);
void cekValid();
void err();
char stringnormal[100];
char stackku[20];
int token[20];
int lala = 0;
int j = 0;


int main(){
  string err = "error";
  cin.getline(stringnormal, sizeof(stringnormal));
  tokenn(stringnormal);
  for (int i=0;i<lala;i++){
    cout<<token[i]<<" ";
  }
  int i = 0;
  int l = 0;
  int k = 0;
  while (stringnormal[i]!='\0'){
    if (stringnormal[i]=='('){
      stackku[l] = stringnormal[i];
      l++;
    }
  i++;
  }
  cout << endl;
  cekValid();
}

void cekValid(){
  int cekkb = 0;
  int cekkt = 0;
  int cekif = 0;
  int cekthen = 0;
  int i = 0;
  while (i < j) {
    if (token[i] == 1) {
      if ((token[i+1] != 1) && (token[i+1] != 2) && (token[i+1] != 6) && (token[i+1] != 7) && (token[i+1] != 9)) {
        i++;
      } else {
        break;
      }
    } else if (token[i] == 2) {
      if ((token[i+1] != 1) && (token[i+1] !=9)) {
        break;
      } else {
        i++;
      }
    } else if ((token[i] == 3) || (token[i] == 4) || (token[i] == 5) || (token[i] == 8)) {
      if ((token[i+1] != 1) && (token[i+1] != 9) && (token[i+1] != 2)) {
        break;
      } else {
        i++;
      }
    } else if (token[i] == 6) {
      cekif++;
      if ((token[i+1] == 1) || (token[i+1] == 2) || (token[i+1] == 9)) {
        i++;
      } else {
        break;
      }
    } else if (token[i] == 7) {
      cekthen++;
      if ((token[i+1] == 1) || (token[i+1] == 2) || (token[i+1] == 9)) {
        i++;
      } else {
        break;
      }
    } else if (token[i] == 9) {
      cekkb++;
      if ((token[i+1] == 9) || (token[i+1] == 1) || (token[i+1] == 2)) {
        i++;
      } else {
        break;
      }
    } else if (token[i] == 10) {
      cekkt++;
      if ((token[i+1] == 1) || (token[i+1] == 9)) {
        break;
      } else {
        i++;
      }
    } else {
      break;
    }
  }
  if ((i < j) || (cekif != cekthen) || (cekkb != cekkt)) {
    cout << "TIDAK VALID";
  } else {
    cout << "VALID";
  }
}

void tokenn(char stringnormal[20]){
  int i = 0;
  int j = 0;
  while (stringnormal[i]!='\0') {
    if (stringnormal[i]=='p' || stringnormal[i]=='q' || stringnormal[i]=='r' || stringnormal[i]=='s'){
      token[j] = 1;
      i++;
      j++;
    }
    else if (stringnormal[i]=='n'){
      if(stringnormal[i+1]=='o'){
        if(stringnormal[i+2]=='t') {
          token[j] = 2;
          i=i+3;
          j++;
        }
      }
    }
    else if (stringnormal[i]=='a'){
      if(stringnormal[i+1]=='n'){
        if(stringnormal[i+2]=='d'){
          token[j] = 3;
          i=i+3;
          j++;
        }
      }
    }
    else if (stringnormal[i]=='o'){
      if(stringnormal[i+1]=='r'){
        token[j] = 4;
        i=i+2;
        j++;
      }
    }
    else if (stringnormal[i]=='x'){
      if(stringnormal[i+1]=='o'){
        if(stringnormal[i+2]=='r'){
          token[j] = 5;
          i=i+3;
          j++;
        }
      }
    }
    else if (stringnormal[i]=='i'){
      if(stringnormal[i+1]=='f'){
        token[j] = 6;
        i=i+2;
        j++;
      }
    }
    else if (stringnormal[i]=='t'){
      if(stringnormal[i+1]=='h'){
        if(stringnormal[i+2]=='e'){
          if(stringnormal[i+3]=='n'){
            token[j] = 7;
            i=i+4;
            j++;
          }
        }
      }
    }
    else if (stringnormal[i]=='i'){
      if(stringnormal[i+1]=='f'){
        if(stringnormal[i+2]=='f'){
          token[j] = 8;
          i=i+3;
          j++;
        }
      }
    }
    else if (stringnormal[i]=='(') {
      token[j] = 9;
      i++;
      j++;
    }
    else if (stringnormal[i]==')') {
      token[j] = 10;
      i++;
      j++;
    }
    else if (stringnormal[i]==' '){
      i++;
    }
  }
  lala = j;
}
