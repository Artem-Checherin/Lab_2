#include <stdio.h>
#include <iostream>
#include <cctype>
#include "PerestanCipher.h"
#include <locale>
using namespace std;
void check(const wstring& Text, const int & key)
{
    wstring s=Text;
    try {
        PerestanCipher skey(key);
        wcout<<skey.CoderPerestanCipher(key, s)<<endl;
        wstring g=skey.CoderPerestanCipher(key, s);
        wcout<<skey.DecoderPerestanCipher(key,g)<<endl;
    } catch (const cipher_error & e) {
        cerr<<"Error: "<<e.what()<<endl;
    }
}
int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    check(L"HelLo",2);
    check(L"HEllO",5);
    check(L"Hello1",0);
    return 0;
}