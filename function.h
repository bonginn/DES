#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
using namespace std;

void initialPermutation(int* plainText){
    int Textarr[8][8];
    for(int i=0;i<8;i++){
        int word = plainText[i];
        for(int j=7;j>=0;j--){
            if(word >= (1 << j)){
                Textarr[i][8 - j - 1] = 1;
                word -= (1 << j);
            }
            else {
                Textarr[i][8 - j - 1] = 0;
            }
        }
    }
    int perText[8][8];
    for(int i=0;i<8;i++){
        int idx = 0;
        for(int j=1;j<8;j+=2){
            perText[idx++][8 - i - 1] = Textarr[i][j];
        }
        for(int j=0;j<8;j+=2){
            perText[idx++][8 - i - 1] = Textarr[i][j];
        }
    }
    int resText[8] = {};
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            resText[i] += perText[i][j] * (1 << (8 - j - 1));
        }
    }
    for(int i=0;i<8;i++){
        plainText[i] = resText[i];
    } 
}

vector <int> DoPC_1(vector <int> K0){
    vector <int> res;
    for(int i=0;i<56;i++){
        res.push_back(K0[PC_1[i] - 1]);
    }
    return res;
}

vector <int> DoPC_2(vector <int> CD){
    vector <int> res;
    for(int i=0;i<48;i++){
        res.push_back(CD[PC_2[i] - 1]);
    }
    return res;
}

vector <int> DoExpansion(vector <int> R){
    vector <int> res;
    for(int i=0;i<48;i++){
        res.push_back(R[E[i] - 1]);
    }
    return res;
}

vector <int> DoS(vector <int> tmp,int round){
    vector <int> res;
    int ROW = tmp[0] * 2 + tmp[5] * 1;
    int COL = tmp[1] * 8 + tmp[2] * 4 + tmp[3] * 2 + tmp[4] * 1;
    int VAL = S[round][ROW][COL];
    for(int i=3;i>=0;i--){
        if(VAL >= (1 << i)){
            VAL -= (1 << i);
            res.push_back(1);
        }
        else{
            res.push_back(0);
        }
    }
    return res;
}

vector <int> DoP(vector <int> S){
    vector <int> res;
    for(int i=0;i<32;i++){
        res.push_back(S[P[i] - 1]);
    }
    return res;
}

vector <int> DoSwap(vector <int> final){
    vector <int> l;
    for(int i=0;i<32;i++){
        l.push_back(final[i]);
    }
    for(int i=0;i<32;i++){
        final[i] = final[i + 32];
    }
    for(int i=32;i<64;i++){
        final[i] = l[i - 32];
    }
    return final;
}

vector <int> finalPermutation(vector <int> swap){
    vector <int> res;
    for(int i=0;i<64;i++){
        res.push_back(swap[IP_inv[i] - 1]);
    }
    return res;
}

#endif // FUNCTIONS_H