//#include <bits/stdc++.h>
#include <string> 
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

int PC_1[56] = { 57, 49, 41, 33, 25, 17,  9, 
                  1, 58, 50, 42, 34, 26, 18,
                 10,  2, 59, 51, 43, 35, 27, 
                 19, 11,  3, 60, 52, 44, 36,
                 63, 55, 47, 39, 31, 23, 15, 
                  7, 62, 54, 46, 38, 30, 22,
                 14,  6, 61, 53, 45, 37, 29, 
                 21, 13,  5, 28, 20, 12,  4 };

int PC_2[48] = { 14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10,
                 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2,
                 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48,
                 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32 };

int E[48] = { 32, 1, 2, 3, 4, 5, 4, 5,
              6, 7, 8, 9, 8, 9, 10, 11,
              12, 13, 12, 13, 14, 15, 16, 17,
              16, 17, 18, 19, 20, 21, 20, 21,
              22, 23, 24, 25, 24, 25, 26, 27,
              28, 29, 28, 29, 30, 31, 32, 1 };

int P[32] = { 16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10,
              2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25 };

int S[8][4][16] = { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
                          0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
                          4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
                          15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 },
                        { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
                          3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
                          0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
                          13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 },
                        { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
                          13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
                          13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
                          1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 },
                        { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
                          13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
                          10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
                          3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 },
                        { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
                          14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
                          4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
                          11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 },
                        { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
                          10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
                          9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
                          4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 },
                        { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
                          13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
                          1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
                          6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 },
                        { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
                          1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
                          7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
                          2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } };

int IP_inv[64] = { 40, 8, 48, 16, 56, 24, 64, 32,
                   39, 7, 47, 15, 55, 23, 63, 31,
                   38, 6, 46, 14, 54, 22, 62, 30,
                   37, 5, 45, 13, 53, 21, 61, 29,
                   36, 4, 44, 12, 52, 20, 60, 28,
                   35, 3, 43, 11, 51, 19, 59, 27,
                   34, 2, 42, 10, 50, 18, 58, 26,
                   33, 1, 41, 9, 49, 17, 57, 25 };
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
    /*for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout << Textarr[i][j] << ' ';
        }
        cout << '\n';
    }*/
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
    /*for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout << perText[i][j] << ' ';
        }
        cout << '\n';
    }*/
    int resText[8] = {};
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            resText[i] += perText[i][j] * (1 << (8 - j - 1));
        }
    }
    for(int i=0;i<8;i++){
        plainText[i] = resText[i];
        //cout << resText[i] << ' ';
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

int main(){
    int T = 5;
    
    for(int i=1;i<=T;i++){
        string key,text;
        cin >> key >> text;
        int plainText[8];
        for(int word=0;word<text.size();word++){
            plainText[word] = text[word];
        }
        //for(int i=0;i<8;i++) cout << plainText[i] << ' ';
        initialPermutation(plainText);
      
        
        int myKey[64];
        vector <int> C[100],D[100],K[100];
        //int tmp[8] = {19,52,87,121,155,188,223,241};
        for(int i=0;i<8;i++){
            int word = key[i];
            for(int j=7;j>=0;j--){
                if(word >= (1 << j)){
                    word -= (1 << j);
                    K[0].push_back(1);
                }
                else {
                    K[0].push_back(0);
                }
            }
        }
        K[0] = DoPC_1(K[0]);
        /*for(int i=0;i<K[0].size();i++){
            cout << K[0][i] << ' ';
            if((i + 1) % 8 == 0) cout << '\n';
        }*/
        for(int i=0;i<28;i++)
            C[0].push_back(K[0][i]);
        for(int i=28;i<56;i++)
            D[0].push_back(K[0][i]);
        
        // Shift Left
        
        for(int i=1;i<=16;i++){
            int first,second;
            if(i == 1 || i == 2 || i == 9 || i == 16){
                first = C[i-1][0];
                for(int j=1;j<C[i-1].size();j++){
                    C[i].push_back(C[i-1][j]);
                }
                C[i].push_back(first);
                first = D[i-1][0];
                for(int j=1;j<D[i-1].size();j++){
                    D[i].push_back(D[i-1][j]);
                }
                D[i].push_back(first);
            }
            else{
                first = C[i-1][0];
                second = C[i-1][1];
                for(int j=2;j< C[i-1].size();j+=2){
                    C[i].push_back(C[i-1][j]);
                    C[i].push_back(C[i-1][j+1]);
                }
                C[i].push_back(first);
                C[i].push_back(second);
                first = D[i-1][0];
                second = D[i-1][1];
                for(int j=2;j<D[i-1].size();j+=2){
                    D[i].push_back(D[i-1][j]);
                    D[i].push_back(D[i-1][j+1]);
                }
                D[i].push_back(first);
                D[i].push_back(second);
            }
        }
        /*
        for(int i=1;i<=16;i++){
            cout << "i = : " << i << '\n';
            for(auto j : C[i]){
                cout << j;
            }
            cout << '\n';
            for(auto j : D[i]){
                cout << j;
            }
            cout << '\n';
        }*/
        
        for(int i=1;i<=16;i++){
            vector <int> CD;
            for(auto j : C[i])
                CD.push_back(j);
            for(auto j : D[i])
                CD.push_back(j);
            K[i] = DoPC_2(CD);
        }/*
        for(int i=1;i<=16;i++){
            for(auto j : K[i]){
                cout << j;
            }
            cout << '\n';
        }*/
        vector <int> L[50],R[50];
        for(int i=0;i<4;i++){
            int tmp = plainText[i];
            //cout << tmp << ' ';
            for(int j=7;j>=0;j--){
                if(tmp >= (1 << j)){
                    tmp -= (1 << j);
                    L[0].push_back(1);
                }
                else {
                    L[0].push_back(0);
                }
            }
        }
        for(int i=4;i<8;i++){
            int tmp = plainText[i];
            //cout << tmp << ' ';
            for(int j=7;j>=0;j--){
                if(tmp >= (1 << j)){
                    tmp -= (1 << j);
                    R[0].push_back(1);
                }
                else{
                    R[0].push_back(0);
                }
            }
        }
        
        // Do
        vector <int> textPerRound[50];
        for(int i=1;i<=16;i++){
            L[i] = R[i-1];
            vector <int> Expansion = DoExpansion(R[i-1]);
            
            vector <int> XOR;
            for(int j=0;j<48;j++){
                XOR.push_back((Expansion[j] ^ K[i][j]));
            }
            
            vector <int> S;
            for(int j=0;j<8;j++){
                vector <int> sPerRound;
                vector <int> tmp;
                for(int k=j*6;k<j*6+6;k++)
                    tmp.push_back(XOR[k]);

                sPerRound = DoS(tmp,j);
                for(int k=0;k<sPerRound.size();k++){
                    S.push_back(sPerRound[k]);
                }
            }
            
            vector <int> P = DoP(S);
            
            vector <int> XOR2;
            for(int j=0;j<32;j++){
                XOR2.push_back((P[j] ^ L[i-1][j]));
            }
            R[i] = XOR2;/*
            if(i == 1){
                for(auto j : R[i])
                    cout << j << ' ';
                cout << '\n';
            }*/
            for(int j=0;j<32;j++){
                textPerRound[i].push_back(L[i][j]);
            }
            for(int j=0;j<32;j++){
                textPerRound[i].push_back(R[i][j]);
            }
            
        }
        vector <int> SWAP = DoSwap(textPerRound[16]);
        vector <int> ANS = finalPermutation(SWAP);
        
        for(int i=0;i<64;i+=4){
            int tmp = (ANS[i] * 8 + ANS[i + 1] * 4 + ANS[i + 2] * 2 + ANS[i + 3] * 1);
            if(tmp < 10)
                cout << tmp ;
            else
                cout << (char('A' + (tmp - 10)));
        }
        cout << '\n';
    }
}