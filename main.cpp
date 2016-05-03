#include<stdio.h>
#include <stdlib.h>
#include <vector>

using std::vector;

int main()
{
    //read to buffer
    FILE *file = fopen("/Users/xiaoyulove/Documents/old/sgnannan/fread-vect/hello.txt", "rb+");

    size_t curpos,length;
    curpos=ftell(file);
    fseek(file,0L,SEEK_END);
    length=ftell(file);
    fseek(file,curpos,SEEK_SET);

    unsigned char* inbuff=(unsigned char*)malloc(length);
    size_t readlength = fread(inbuff, 1, length, file);

    if(readlength != length)
    {
        printf("read err\n");
        fclose(file);
        return false;
    }

    vector<unsigned char> tempbuff(inbuff, inbuff + length);

    for(vector<unsigned char>::iterator it = tempbuff.begin();it!=tempbuff.end();it++)
    {
       printf("%c", *it);
    }

    int temp;
    scanf("%d", &temp);
}
