#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

//#define CLAMP_TO_20(n) (n < 1 ? 1 : (n>20 ? 20 : n))

int solution (vector<int> &);

int main() {
    
    vector <int> v;

    int input;
    //char as ='q';

    int sonuc;

    while (true){
        cin>>input;

        if(input==-200){
            break;
        }    

        v.push_back(input);    
    }


    sonuc=solution (v);

    cout<<"Sonuc: "<<sonuc;



    return 0;
}

int solution (vector<int> &A){
    sort(A.begin(),A.end());
    
    int enBuyukPozitif;

    vector<int>::iterator lastElementIterator = A.end();
    --lastElementIterator;
    vector<int>::iterator prevElementIterator = lastElementIterator;
    --prevElementIterator;
    if(A.size() ==1 && *lastElementIterator>0){
        enBuyukPozitif = A[0]+1;
    }
    else{
    if(*lastElementIterator<=0){
        enBuyukPozitif=1;
    }
    else if((*lastElementIterator)-1 != *prevElementIterator){
        enBuyukPozitif=(*lastElementIterator)-1;
    }
    else if((*lastElementIterator)-1 == *prevElementIterator){

        for (vector<int>::iterator it=lastElementIterator; it!=A.begin(); --it ){
                if((*it) - *(it-1) != 1){
                    enBuyukPozitif = (*it) - 1;
                    break;
                }
                else {
                    enBuyukPozitif = (*lastElementIterator) + 1;
                }
        }
        
    }

    } 
    

    

    return enBuyukPozitif;

}

