//#include <QtCore/QCoreApplication>
#include <stdio.h>
#include <string.h>

bool comparaEnteros(void *a, void *b);
void* bubbleSort(void *p,bool (*f)(void*,void*),int tam,int size);
bool comparaChars(void * a,void *b);


int main()
{
    int a[] = {7,6,8,4,2,6};
    char c[] = {'a','m','z','g'};

    bubbleSort(a,comparaEnteros,6,sizeof(int));
    bubbleSort(c,comparaChars,4,sizeof(char));

    return 0;
}


void* bubbleSort(void *p,bool (*f)(void*,void*),int tam, int size){

    char *block = new char[size];

    for(int i= 0; i<tam;i++)
    {
        for(int j = i+1;j<tam;j++)
        {
            if(f(p+i*size,p+j*size)){
                memcpy(block,p+i*size,size);
                memcpy(p+i*size,p+j*size,size);
                memcpy(p+j*size,block,size);
            }

        }
    }

}

bool comparaEnteros(void * a,void *b)
{
    return *((int *) a) > *((int *)b);
}

bool comparaChars(void *a,void *b){
    return *((char *) a) > *((char *)b);
}
