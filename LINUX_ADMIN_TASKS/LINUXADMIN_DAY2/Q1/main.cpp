#include <stdio.h>

#define DATA_MAX_SIZE 10



int BinarySearchAlgorithm(int Data[], int Req_Value){
    
    int M_Index ,S_Index= 0;
    int E_Index=(DATA_MAX_SIZE-1);

    while(S_Index <= E_Index){
        M_Index = S_Index + ((E_Index - S_Index) / 2);

        if(Req_Value == Data[M_Index]){
            return M_Index;
        }
        else if(Req_Value > Data[M_Index]){
            S_Index = M_Index + 1;
        }
        else{
            E_Index = M_Index - 1;
        }
    }

    return -1;
}

int main()
{
int MyData[DATA_MAX_SIZE] = {0, 11, 22, 33, 44, 55, 66, 77, 88, 99};
unsigned int index=0;
index=BinarySearchAlgorithm(MyData,55);
printf("FOUND ON INDEX %d \n",index);

return 0;
}
