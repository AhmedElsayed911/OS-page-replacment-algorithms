#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int searcharray(int array[],int size,int value)
{
    int i;
    for(i=0; i<size; i++)
    {
        if(array[i]==value)
            return 1;
    }

    return 0;
}
int biggestcountindex(int array[],int size)
{
    int i, max=0, index ;

    for(i=0; i<size; i++)
    {
        if (array[i]>max)
        {
            max=array[i];
            index=i;
        }

    }
    return index;
}
int findindex(int array [], int size,int value )
{
    int  i, index ;
    for (i=0; i<size; i++)
    {

        if (array[i]==value)
            index = i ;
    }
    return index ;
}


void fifo(int space,int array[],int size)
{
    int memory[space];
    int faults=0;
    int currentindex=0;

    printf("Replacment Policy = FIFO \n");
    printf("---------------------------------\n");
    printf("Page\tContent of Frames\n");
    printf("----\t--------------------\n");
    int i;
    int count=0;

    for (i=0; i<size; i++)
    {



        if(count<space)
        {

            if(searcharray(memory,count,array[i])==0)
                memory[count++]=array[i];
            printf("%02d   \t",array[i]);

        }
        else
        {

            if(searcharray(memory,count,array[i])==0)
            {

                memory[currentindex]=array[i];
                faults++;
                currentindex++;
                if(currentindex==count)
                    currentindex=0;
                printf("%02d F \t",array[i]);

            }
            else
                printf("%02d   \t",array[i]);



        }

        int j;
        for(j=0; j<count; j++)
        {
            printf("%02d  ",memory[j]);
        }
        printf("\n");



    }


    printf("-------------------------------------\n");
    printf("Number of page faults = %d\n",faults);



}
void optimal (int space, int array[],int size)
{
    int memory[space];
    int faults=0;


    printf("Replacment Policy = OPTIMAL \n");
    printf("---------------------------------\n");
    printf("Page\tContent of Frames\n");
    printf("----\t--------------------\n");
    int i;
    int count=0;

    for (i=0; i<size; i++)
    {



        if(count<space)
        {

            if(searcharray(memory,count,array[i])==0)
                memory[count++]=array[i];
            printf("%02d   \t",array[i]);

        }
        else
        {

            if(searcharray(memory,count,array[i])==0)
            {
                int z, q;
                int counts[space] ;



                for(q=0; q<space; q++)
                {
                    counts[q]=0;
                    for (z=i+1; z<size; z++)
                    {

                        if(memory[q]==array[z])
                            break;

                        counts[q]++;

                    }
                }


                int index = biggestcountindex(counts,space);

                memory[index]=array[i];



                faults++;
                printf("%02d F \t",array[i]);

            }
            else
                printf("%02d   \t",array[i]);



        }

        int j;
        for(j=0; j<count; j++)
        {
            printf("%02d  ",memory[j]);
        }
        printf("\n");



    }


    printf("-------------------------------------\n");
    printf("Number of page faults = %d\n",faults);


}
void lru  (int space, int array[], int size)
{

    int memory[space];
    int faults=0;


    printf("Replacment Policy = LRU \n");
    printf("---------------------------------\n");
    printf("Page\tContent of Frames\n");
    printf("----\t--------------------\n");
    int i;
    int count=0;

    for (i=0; i<size; i++)
    {



        if(count<space)
        {

            if(searcharray(memory,count,array[i])==0)
                memory[count++]=array[i];
            printf("%02d   \t",array[i]);

        }
        else
        {

            if(searcharray(memory,count,array[i])==0)
            {
                int z, q;
                int counts[space] ;



                for(q=0; q<space; q++)
                {
                    counts[q]=0;
                    for (z=i-1; z>0; z--)
                    {

                        if(memory[q]==array[z])
                            break;

                        counts[q]++;

                    }
                }


                int index = biggestcountindex(counts,space);

                memory[index]=array[i];



                faults++;
                printf("%02d F \t",array[i]);

            }
            else
                printf("%02d   \t",array[i]);



        }

        int j;
        for(j=0; j<count; j++)
        {
            printf("%02d  ",memory[j]);
        }
        printf("\n");



    }


    printf("-------------------------------------\n");
    printf("Number of page faults = %d\n",faults);



}
void clock (int space,int array[], int size)
{

    int memory[space];
    int faults=0;
    int currentindex=0;

    printf("Replacment Policy = CLOCK \n");
    printf("---------------------------------\n");
    printf("Page\tContent of Frames\n");
    printf("----\t--------------------\n");
    int i;
    int count=0;
    int counts[space];

    for (i=0; i<space ; i++)
    {
        counts[i]=1;
    }

    for (i=0; i<size; i++)
    {



        if(count<space)
        {

            if(searcharray(memory,count,array[i])==0)
                memory[count++]=array[i];
            printf("%02d   \t",array[i]);

        }
        else
        {

            if(searcharray(memory,count,array[i])==0)
            {

            while(1){

                if(currentindex==count)
                    currentindex=0;

                if (counts[currentindex]==0){

                memory[currentindex]=array[i];
                counts[currentindex]=1;
                faults++;
                currentindex++;
                printf("%02d F \t",array[i]);
                break;

                }
                else {
                    counts[currentindex]=0;
                    currentindex++;
                }
            }//for loop

        }
        else
        {
                printf("%02d   \t",array[i]);
               int f = findindex(memory,space,array[i]);

                counts[f]=1;


        }


    }

        int j;
        for(j=0; j<count; j++)
        {
            printf("%02d  ",memory[j]);
        }
        printf("\n");



    }


    printf("-------------------------------------\n");
    printf("Number of page faults = %d\n",faults);


}





int main()
{
    int space;
    char method[10];
    int array[300];
    scanf("%d",&space);
    scanf("%s",method);
    int i=0;
    while (1)
    {
        scanf("%d",&array[i]);
        if (array[i]==-1)
            break;
        i++;
    }

    if (strcasecmp(method,"fifo")==0){
    fifo(space,array,i);
    }
    else if (strcasecmp(method,"optimal")==0) {
    optimal(space,array,i);
    }
    else if (strcasecmp(method,"lru")==0){
    lru(space,array,i);
    }else {
    clock(space,array,i);
    }



    return 0;
}
