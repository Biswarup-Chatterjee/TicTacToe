#include <stdio.h>

void compTurn(char brd[][3], char plr, char com);
int vct(char brd[][3], char plr, char com);
void display(char brd[][3]);

void main(){

    int i,x,y;
    char plr,com;
    char brd[3][3] = {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };

    display(brd);

    printf("\nPress 1 for < O > and 2 for < X >\n");
    scanf("%d", &i);
    
    if(i == 1){
        
        plr = 'O';
        com = 'X';
    }
    else if(i == 2){
        
        plr = 'X';
        com = 'O';
    }     
    else{
        printf("Select from the given options\n----------------------------------\n");
        main();
    }
        

    

    
    
    while(1){


        printf("PLAYER's TURN\n----------------------------------\n");
        printf("Enter your position\n");
        printf("Row (1-3) : ");
        scanf("%d", &x);
        printf("\nColumn (1-3) : ");
        scanf("%d", &y);
        
        if((brd[x-1][y-1] == ' ') && (x<4) && (y<4)){

            brd[x-1][y-1] = plr;

        }
        else{

            printf("Enter a valid position\n");
            continue;
        }
            
        display(brd);

        if(vct(brd,plr,com) == 1){
            printf("Player won!\n");
            break;
        }
        else if(vct(brd,plr,com) == 0){
            printf("Player lost !\n");
            break;
        }

        printf("COMPUTER's TURN\n----------------------------------\n");

        compTurn(brd,plr,com);

        display(brd);

        if(vct(brd,plr,com) == 1){
            printf("Player won!\n");
            break;
        }
        else if(vct(brd,plr,com) == 0){
            printf("Player lost !\n");
            break;
        } 
    }

    
}

void display(char brd[][3]){
    
    printf("\n");
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            printf("|%c|",brd[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------------\n");
}

int vct(char brd[][3], char plr, char com){

    for(int i=0; i<3; i++){
        int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
        for(int j=0; j<3; j++){
            s1 += brd[i][j];
            s2 += brd[j][i];
            s3 += brd[j][j];
            s4 += brd[2-j][j];
        }
        if(s1 == plr*3 || s2 == plr*3 || s3 == plr*3 || s4 == plr*3)
            return 1;
    }

    for(int i=0; i<3; i++){
        int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
        for(int j=0; j<3; j++){
            s1 += brd[i][j];
            s2 += brd[j][i];
            s3 += brd[j][j];
            s4 += brd[2-j][j];
        }
        if(s1 == com*3 || s2 == com*3 || s3 == com*3 || s4 == com*3)
            return 0;
    }

    return 100;
}

void compTurn(char brd[][3], char plr, char com){

    if(brd[1][1] == ' '){
        brd[1][1] = com;
        return;
    }

    //Final Victory Move

    for(int i=0; i<3; i++){
        int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
        for(int j=0; j<3; j++){
            s1 += brd[i][j];
            s2 += brd[j][i];
            s3 += brd[j][j];
            s4 += brd[2-j][j];
        }
        if(s1 == com*2+32){
            brd[i][0]=com;
            brd[i][1]=com;
            brd[i][2]=com;
            return;
        }
        if(s2 == com*2+32){
            brd[0][i]=com;
            brd[1][i]=com;
            brd[2][i]=com;
            return;
        }
        if(s3 == com*2+32){
            brd[0][0]=com;
            brd[1][1]=com;
            brd[2][2]=com;
            return;
        }
        if(s4 == com*2+32){
            brd[0][2]=com;
            brd[1][1]=com;
            brd[2][0]=com;
            return;
        }
            
    }

    //Preventing Victory Move
    
    for(int i=0; i<3; i++){
        int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
        for(int j=0; j<3; j++){
            s1 += brd[i][j];
            s2 += brd[j][i];
            s3 += brd[j][j];
            s4 += brd[2-j][j];
        }
        if(s1 == (plr*2)+32){

            for(int k=0; k<3; k++){
                if(brd[i][k]==' ')
                    brd[i][k] = com;
            }
            return;
        }
        if(s2 == (plr*2)+32){
            for(int k=0; k<3; k++){
                if(brd[k][i]==' ')
                    brd[k][i] = com;
            }
            return;
        }
        if(s3 == (plr*2)+32){
            for(int k=0; k<3; k++){
                if(brd[k][k]==' ')
                    brd[k][k] = com;
            }
            return;
        }
        if(s4 == (plr*2)+32){
            for(int k=0; k<3; k++){
                if(brd[2-k][k]==' ')
                    brd[2-k][k] = com;
            }
            return;
        }
            
    }

    if(brd[0][0] == ' '){
        brd[0][0] = com;
        return;
    }
        
    if(brd[0][2] == ' '){
        brd[0][2] = com;
        return;
    }

    if(brd[2][2] == ' '){
        brd[2][2] = com;
        return;
    }

    if(brd[2][0] == ' '){
        brd[2][0] = com;
        return;
    }

}
