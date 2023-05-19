#include<stdio.h>
#include"Circular_Queue.h"
#include<stdlib.h>

int main(){
    int hamber[] = {12,15,24};
    int bugercounter[] ={0,0,0};
    int random =0;
    
    //대기실 
     int limit_time = 3600;
     int time = 0;
    Queue que;
    QueInit(&que);
    //한시간동안 주문
    while(time < limit_time){
        if(time % 15){
            //큐에 대기손님 추가
            int rnumber = rand() % 3; 
            
            if(QEmpty(&que))
            Enqueue(&que,hamber[random]+time);
            else
            Enqueue(&que,peek(&que)+hamber[random]);
            
            bugercounter[random]++;
        }
        
        if(time > 15 && !QEmpty(&que)){
            if(time == peek(&que)){
                Dequeue(&que);
            }
        }

    }
      // printReport함수로 빼면됨
        printf("Simulation Report!\n");
        printf("- Cheese burger : %d\n", bugercounter[0]);
        printf(" - Bulgogi burger: %d\n", bugercounter[1]);
        printf(" - Double burger : %d\n",bugercounter[2]);
        printf(" - Waiting room size: %d",MAX_LEN);

    return 1;
}