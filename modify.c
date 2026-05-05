#include <stdio.h>


int print_board(int rows, int cols , char arr[rows][cols]){
     for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = '_';
        }
    }
  
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("  %c  ", arr[i][j]);
        }
        printf("\n");
    }

}

   

int move_mock_def(int rows,int cols,int mock_move[rows][cols]){
    int count = 0;
    for(int a=0;a<rows;a++){
        for(int b=0;b<cols;b++){
            mock_move[a][b]=count;
            count++;
        }
    }
    
}



// int possible_moves(int rows,int cols,char arr[rows][cols]){

//         printf("\nPossible Moves: \n");
//         for(int i=0;i<rows;i++){
//             for(int j=0;j<cols;j++){
//                 printf(" %d%d ",i,j);
//             }
//             printf("\n");
//         }
// }

int mock_possible_moves(int rows,int cols ,int mock_move[rows][cols]){
    printf("Possible moves: \n");
     for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(mock_move[i][j]<10){
            printf("%d   ",mock_move[i][j]);
            }
            else{
                 printf("%d  ",mock_move[i][j]);
            }
        }
        printf("\n");
    }
}
int check_row_col(int rows,int cols,char arr[rows][cols],char move){
        int check = 0;
       for(int c=0;c<rows;c++){
            int count_row_col=0;
            for(int d=0;d<cols;d++){
                if(arr[c][d]==move){
                    count_row_col++;
                }
            }
            if(count_row_col==cols){
                check = 1;
                break;
            }
        }

          for(int d =0;d<cols;d++){
            int count_row_col=0;
            for(int c=0;c<rows;c++){
                if(arr[c][d]==move){
                    count_row_col++;
                }
            }
            if(count_row_col==rows){
                check = 1;
                break;
            }
        }

        return check;
}

int check_both_diag(int rows,int cols,char arr[rows][cols],char move){
    int check_diag= 0;
     int count_diag=0;
        for(int c=0;c<rows;c++){
            for(int d=0;d<cols;d++){
                if(c==d){
                    if(arr[c][d]==move){
                        count_diag++;   // sidhi diagonal
                    }
                }
            }
        }

        if(count_diag==rows){
            check_diag = 1;
        }

        int count_diag_2=0;
        for(int c=0;c<rows;c++){
            for(int d=0;d<cols;d++){
                if(c+d==rows-1){
                    if(arr[c][d]==move){
                        count_diag_2++;
                    }
                }
            }  // zero-katta  ulti diagonal
        }
        if(count_diag_2==rows){
           check_diag = 1;
        }

        return check_diag;

}



int main()

{  
    int p1_score = 0, p2_score = 0, draw_score = 0;
    FILE *fp = fopen("score.txt", "r");

    if (fp != NULL) {
     fscanf(fp, "P1: %d\nP2: %d\nDraw: %d", &p1_score, &p2_score, &draw_score);
     fclose(fp);
}
    int rows, cols;
    printf("enter the size of grid(K x K): \n");
    scanf("%d %d",&rows,&cols);
    

    if(rows!=cols){
        printf("Board must be a square , exiting the program......");
        return 0;
    }
    char arr[rows][cols];
    int mock_move[rows][cols];


    int count_moves = 0 ;
    

    // zero-katta
   move_mock_def(rows,cols,mock_move);
   print_board(rows,cols,arr);
   mock_possible_moves(rows,cols,mock_move);



    int stop_game = 1;
    while (stop_game)
    {
    
        int p1 = 1;
        while (p1)
        {  //player 1 turn
            printf("Player1: ");
            int i, j;
           
            int move;
            
            printf("enter your move : like 0 for first spot , %d for last spot\n",(rows*cols)-1);
            scanf("%d",&move);
            for(int a=0;a<rows;a++){
                for(int b=0;b<cols;b++){
                    if(move==mock_move[a][b]){
                       i=a;
                       j=b;
                       break;
                    }
                }
            }
           // scanf("%d %d", &i, &j);

            printf("\n");
            // check for out of bound arr
            if(i<0 ||i>=rows || j<0 || j>=cols){
                printf("wrong_input , try again: \n");
            }
            else if (arr[i][j] == '_')
            {
                printf("Valid Move! \n");
                arr[i][j] = 'X';
                count_moves++;
                break;
            }
            else
            {
                printf("wrong input , try again: \n");
            }
        }

        printf("After Player 1 Move : \n");

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                printf("  %c  ", arr[i][j]);
            }
            printf("\n");
        }
       
        // check win 

        int row_col_1 = check_row_col(rows,cols,arr,'X');

        int diagonals_1= check_both_diag(rows,cols,arr,'X');

        

         if (row_col_1 || diagonals_1)
        {       p1_score++;
             printf("--------------------------");
            printf("\nplayer 1 ('X') wins ");

            printf("\n--------------------------");
            break;
        }
        

        // check tie
        if(count_moves==(rows*cols)){
            draw_score++;
            printf("\n  match ties !!!");
            break;
        }

   
    	


        int p2 = 1;
        while (p2) // player 2 turn 
        {   
            printf("\nPlayer2: ");
            int k, m;

            int move;
    
            printf("enter your move : like 0 for first spot , %d for last spot\n",(rows*cols)-1);
            scanf(" %d",&move);

            for(int a=0;a<rows;a++){
                for(int b=0;b<cols;b++){
                    if(move==mock_move[a][b]){
                       k=a;
                       m=b;
                       break;
                    }
                }
            }
            
            //scanf(" %d %d", &k, &m);
         
            
            if(k<0 || k>=rows || m<0 || m>=cols){
                printf("wrong_input , try again: \n");
            }

            else if (arr[k][m] == '_')
            {
                printf("Valid Move! \n");
                arr[k][m] = 'O';
                count_moves++;
                break;
            }
            else
            {
                printf("wrong input , try again: \n");
            }
        }

        printf("After Player 2 Move : \n");

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                printf("  %c  ", arr[i][j]);
            }
            printf("\n");
        }

        // check win 

        int row_col_2 = check_row_col(rows,cols,arr,'O');

        int diagonals_2= check_both_diag(rows,cols,arr,'O');

        if (row_col_2 || diagonals_2)
        {      p2_score++;
            printf("--------------------------");
            printf("\nplayer 2 ('O') wins ");

            printf("\n--------------------------");
            break;
        }


          if(count_moves==(rows*cols)){   // check tie 
            draw_score++;
            printf("\n  match ties....!!");
            break;
        }
    }


    fp = fopen("score.txt", "w");

if (fp == NULL) {
    printf("Error writing file!\n");
    return 1;
}
printf("\n--- Scoreboard ---\n");
printf("Player 1 (X): %d\n", p1_score);
printf("Player 2 (O): %d\n", p2_score);
printf("Draws: %d\n", draw_score);

fprintf(fp, "P1: %d\n", p1_score);
fprintf(fp, "P2: %d\n", p2_score);
fprintf(fp, "Draw: %d\n", draw_score);

fclose(fp);
    return 0;
}
