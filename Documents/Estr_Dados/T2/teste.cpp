#include<iostream>
#include<cstdio>
#include<fstream>

using namespace std;

int main(int argc, char *argv[]) {

    FILE *arq; 
    arq = fopen(argv[1], "wb");
    unsigned char buffer = 0x04;

    fwrite(&buffer, 1, 1, arq);
}