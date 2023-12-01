#include <windows.h>
#include <string.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

char squ[10] = {'0','1','2','3','4','5','6','7','8','9'};
int checkwin();
void board(player_name_1,player_name_2);
void heder(char player_1[10],char player_2[10]);
FILE *moves;

int main()
{

    moves = fopen("moves_history.txt","a");
    char player_name_1[10];
    char player_name_2[10];
   int player = 1,i,choice;
   char mark;
   printf ("====================================\n");
    printf ("\t tic tac toe\n");
    printf ("====================================\n\n\n");
   printf("Enter name 'x' player:");
   scanf("%s",player_name_1);
    printf("Enter name 'o' player:");
   scanf("%s",player_name_2);
   heder(player_name_1,player_name_2);
    do {
       board(player_name_1,player_name_2);
       player =(player % 2) ? 1:2;
       if(player==1){
       printf ("player %s,enter the choice :",player_name_1);}
       else{printf ("player %s,enter the choice :",player_name_2);}
       scanf("%d",&choice);
       mark=(player==1)? 'x':'o';
       if (choice == 1 && squ[1] == '1')
        squ[1]=mark;
       else if (choice == 2 && squ[2]=='2')
       squ[2]=mark;
       else if (choice == 3 && squ[3]=='3')
       squ[3]=mark;
       else if (choice == 4 && squ[4]=='4')
       squ[4]=mark;
       else if (choice == 5 && squ[5]=='5')
       squ[5]=mark;
       else if (choice == 6 && squ[6]=='6')
       squ[6]=mark;
       else if (choice == 7 && squ[7]=='7')
       squ[7]=mark;
       else if (choice == 8 && squ[8]=='8')
       squ[8]=mark;
       else if (choice == 9 && squ[9]=='9')
       squ[9]=mark;
       else {
           printf("invalid option");
           if(player==1){
                fprintf(moves,"player %s marked %d ,invalid option\n",player_name_1,choice);
            }
            else{
                fprintf(moves,"player %s marked %d ,invalid option\n",player_name_2,choice);
            }
           player--;
           getch();

       }
       if(player==1){
       fprintf(moves,"player %s marked %d\n",player_name_1,choice);
       }
       else{fprintf(moves,"player %s marked %d\n",player_name_2,choice);}
       i=checkwin();
       player++;


   }
   while (i== -1);
   player--;
   board(player_name_1,player_name_2);
   if(i==1){
        if(player==1){
            printf("==>player %s won",player_name_1);
            fprintf(moves,"==>\a%s  has won the match\n\n ", player_name_1);
        }
        else{printf("==>player %s won",player_name_2);
        fprintf(moves,"==>\a%s  has won the match \n\n", player_name_2);}
}
else {
    printf("==>game draw");
    fprintf(moves,"==>game draw\n\n");

}
 getchar();
 fclose(moves);
    return 0;
}
int checkwin(){
    if (squ[1] == squ[2] && squ[2]==squ[3])
        return 1;
    else if(squ[4] == squ[5] && squ[5]==squ[6])
        return 1;
    else if(squ[7] == squ[8] && squ[8]==squ[9])
    return 1;
    else if(squ[1] == squ[4] && squ[4]==squ[7])
    return 1;
     else if(squ[2] == squ[5] && squ[5]==squ[8])
    return 1;
     else if(squ[3] == squ[6] && squ[6]==squ[9])
    return 1;
     else if(squ[1] == squ[5] && squ[5]==squ[9])
    return 1;
     else if(squ[3] == squ[5] && squ[5]==squ[7])
    return 1;
    else if(squ[1] != '1' && squ[2] != '2'&& squ[3] != '3'&& squ[4] != '4' && squ[5] != '5' && squ[6] != '6' && squ[7] != '7' && squ[8] != '8' && squ[9] != '9')
    return 10;
    else
        return -1;
}
void heder(char player_1[10],char player_2[10]){
    fprintf(moves,"============================================================\n");
    fprintf(moves,"               --------TIC TAC TOE---------               \n");
    fprintf(moves,"============================================================\n\n\n");
    fprintf(moves,"%s (X)  -  %s (O)\n\n\n", player_1, player_2);
}

void board(char player_name1[10],char player_name2[10]){
    system ("cls");
    printf ("====================================\n");
    printf ("\t tic tac toe\n");
    printf ("====================================\n");
    printf("%s (x) - %s (o)\n\n\n",player_name1,player_name2);
    printf("     |     |     \n");
    printf("  %c  |  %c  | %c   \n",squ[1],squ[2],squ[3]);
    printf(" ____|_____|____\n");
     printf("     |     |     \n");
    printf("  %c  |  %c  | %c   \n",squ[4],squ[5],squ[6]);
     printf(" ____|_____|____\n");
     printf("     |     |     \n");
     printf("  %c  |  %c  | %c   \n\n",squ[7],squ[8],squ[9]);

}

