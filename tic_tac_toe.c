#include <stdio.h>

int main()
{
    int rows, cols;
    printf("enter the size of grid(K x K): \n");
    scanf("%d %d",&rows,&cols);
    char arr[rows][cols];

    int count = 0 ;

    // zero-katta

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

    int stop = 1;
    while (stop)
    {
    
        int p1 = 1;
        while (p1)
        {
            printf("Player1: ");
            int i, j;
            printf("enter your move : like 0 0 for first spot , 2 2 for last spot\n");
            scanf("%d %d", &i, &j);


            printf("\n");
            

            
            
            if (arr[i][j] == '_')
            {
                printf("Valid Move! \n");
                arr[i][j] = 'X';
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
        /*
        printf("\n");
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                printf(" %d%d ",i,j);
            }
            printf("\n");
        }
        */
        int check=0;
        int diag = 0 ;
        for(int c=0;c<rows;c++){
            int temp=0;
            for(int d=0;d<cols;d++){
                if(arr[c][d]=='X'){
                    temp++;
                }
            }
            if(temp==cols){
                check = 1;
                break;
            }
        }

          for(int d =0;d<cols;d++){
            int temp=0;
            for(int c=0;c<rows;c++){
                if(arr[c][d]=='X'){
                    temp++;
                }
            }
            if(temp==rows){
                check = 1;
                break;
            }
        }

        int count_diag=0;
        for(int c=0;c<rows;c++){
            for(int d=0;d<cols;d++){
                if(c==d){
                    if(arr[c][d]=='X'){
                        count_diag++;   // sidhi diagonal
                    }
                }
            }
        }

        if(count_diag==rows){
            diag = 1;
        }

        int count_diag_2=0;
        for(int c=0;c<rows;c++){
            for(int d=0;d<cols;d++){
                if(c+d==rows-1){
                    if(arr[c][d]=='X'){
                        count_diag_2++;
                    }
                }
            }  // zero-katta  ulti diagonal
        }
        if(count_diag_2==rows){
            diag = 1;
        }

        

         if (check || diag)
        {   
             printf("--------------------------");
            printf("\nplayer 1 ('X') wins ");

            printf("\n--------------------------");
            break;
        }



        count++;
        if(count==(((rows*cols)+1)/2)){

            printf("\n  match ties bitch !!");
            break;
        }

   
    	


        int p2 = 1;
        while (p2)
        {   
            printf("\nPlayer2: ");
            int k, m;
            printf("enter your move : like 0 0 for first spot , 2 2 for last spot\n");
            scanf(" %d %d", &k, &m);
         
           

            if (arr[k][m] == '_')
            {
                printf("Valid Move! \n");
                arr[k][m] = 'O';
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


      /*  printf("\n");
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                printf(" %d%d ",i,j);
            }
            printf("\n");
        }
        */


        int check1=0;
        int diag1 = 0 ;
        for(int c=0;c<rows;c++){
            int temp=0;
            for(int d=0;d<cols;d++){
                if(arr[c][d]=='O'){
                    temp++;
                }
            }
            if(temp==cols){
                check1 = 1;
                break;
            }
        }

          for(int d =0;d<cols;d++){
            int temp=0;
            for(int c=0;c<rows;c++){
                if(arr[c][d]=='O'){
                    temp++;
                }
            }
            if(temp==rows){
                check1 = 1;
                break;
            }
        }

        int count_diag_=0;
        for(int c=0;c<rows;c++){
            for(int d=0;d<cols;d++){
                if(c==d){
                    if(arr[c][d]=='O'){
                        count_diag_++;
                    }
                }
            }
        }

        if(count_diag_==rows){
            diag1 = 1;
        }

        int count_diag_2_=0;
        for(int c=0;c<rows;c++){
            for(int d=0;d<cols;d++){
                if(c+d==rows-1){
                    if(arr[c][d]=='O'){
                        count_diag_2_++;
                    }
                }
            }
        }
        if(count_diag_2_==rows){
            diag1 = 1;
        }




        if (check1 || diag1)
        {
            printf("--------------------------");
            printf("\nplayer 2 ('O') wins ");

            printf("\n--------------------------");
            break;
        }
    }

    return 0;
}
