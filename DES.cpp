//#include <bits/stdc++.h>
#include <string> 
#include <math.h>
#include <iostream>
#include <vector>
#include "table.h"
#include "function.h"
using namespace std;

int main(){

    int T = 5; // test case
    for(int i=1;i<=T;i++){
        string key,text;
        cin >> key >> text;
        int plainText[8];
        for(int word=0;word<text.size();word++){
            plainText[word] = text[word];
        }
        initialPermutation(plainText);
        int myKey[64];
        vector <int> C[100],D[100],K[100];
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
        for(int i=1;i<=16;i++){
            vector <int> CD;
            for(auto j : C[i])
                CD.push_back(j);
            for(auto j : D[i])
                CD.push_back(j);
            K[i] = DoPC_2(CD);
        }
        vector <int> L[50],R[50];
        for(int i=0;i<4;i++){
            int tmp = plainText[i];
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
            R[i] = XOR2;
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