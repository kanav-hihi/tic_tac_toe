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


int possible_moves(int rows,int cols,char arr[rows][cols]){

        printf("\nPossible Moves: \n");
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                printf(" %d%d ",i,j);
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
    int rows, cols;
    printf("enter the size of grid(K x K): \n");
    scanf("%d %d",&rows,&cols);
    char arr[rows][cols];

    int count_moves = 0 ;

    // zero-katta

   print_board(rows,cols,arr);

   possible_moves(rows,cols,arr);



    int stop_game = 1;
    while (stop_game)
    {
    
        int p1 = 1;
        while (p1)
        {  //player 1 turn
            printf("Player1: ");
            int i, j;
            printf("enter your move : like 0 0 for first spot , %d %d for last spot\n",rows-1,rows-1);
            scanf("%d %d", &i, &j);

            printf("\n");
            // check for out of bound arr
            if(i<0 && i>rows && j<0 && j>cols){
                printf("wrong_input , try again: \n");
            }
            else if (arr[i][j] == '_')
            {
                printf("Valid Move! \n");
                arr[i][j] = 'X';
                count_moves=0;
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
        {   
             printf("--------------------------");
            printf("\nplayer 1 ('X') wins ");

            printf("\n--------------------------");
            break;
        }
        

        // check tie
        if(count_moves==(rows*cols)){

            printf("\n  match ties bitch!!");
            break;
        }

   
    	


        int p2 = 1;
        while (p2) // player 2 turn 
        {   
            printf("\nPlayer2: ");
            int k, m;
            printf("enter your move : like 0 0 for first spot , 2 2 for last spot\n");
            scanf(" %d %d", &k, &m);
         
            
            if(k<0 && m>rows && m<0 && m>cols){
                printf("wrong_input , try again: \n");
            }

            else if (arr[k][m] == '_')
            {
                printf("Valid Move! \n");
                arr[k][m] = 'O';
                count_moves=0;
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
        {
            printf("--------------------------");
            printf("\nplayer 2 ('O') wins ");

            printf("\n--------------------------");
            break;
        }


          if(count_moves==(rows*cols)){   // check tie 

            printf("\n  match ties bitch !!");
            break;
        }
    }

    
    return 0;
}
