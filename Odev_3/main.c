#include <stdio.h>
#include <stdlib.h>
typedef struct yigin
{
    char operatorler;
    struct yigin *next;

} stacklar;
stacklar *top = NULL;
typedef struct yigin2
{
    int a;
    struct yigin2 *next;

} stacklar2;
stacklar2 *head = NULL;
void infixcevir(char* infix,char * postfix)
{

    int i =0;
    for (i =0; i<strlen(infix); i++)
    {
        if('0' <= *(infix+i) && *(infix+i)<= '9' )
        {
            char *karakter;
            karakter = (char *)calloc(10,sizeof(char));
            for ( int j =i; '0' <= *(infix+j) && *(infix+j)<= '9'; j++)
            {
                int uzunluk = strlen(karakter);
                *(karakter+uzunluk) = *(infix+j);
                i = j;


            }
            strcat(postfix,",");
            strcat(postfix,karakter);
            strcat(postfix,",");
        }
        else if ( *(infix+i) == ' ')
        {
            continue;

        }
        else if ( *(infix+i) == '(')
        {
            stacklar * new = (stacklar*)malloc(sizeof(stacklar));
            new->operatorler = '(';
            new->next = top;
            top = new;
        }
        else if (*(infix+i) == ')')
        {
            stacklar * ptr = top;
            while(ptr->operatorler != '(')
            {
                int uzunluk = strlen(postfix);
                *(postfix+uzunluk) += ptr->operatorler;
                ptr = ptr->next;
                free(top);
                top = ptr;


            }
            ptr = ptr->next;
            free(top);
            top = ptr;

        }
        else
        {
            if (top == NULL)
            {
                top = (stacklar*)malloc(sizeof(stacklar));
                top->operatorler = *(infix+i);
                top->next = NULL;
            }
            else
            {
                if(*(infix+i) == '*' ||*(infix+i) == '/' )
                {
                    if(top->operatorler == '*' || top->operatorler == '/')
                    {

                        int uzunluk = strlen(postfix);
                        *(postfix+uzunluk)= top->operatorler;

                        top->operatorler = *(infix+i);
                    }
                    else
                    {
                        stacklar * new = (stacklar*)malloc(sizeof(stacklar));
                        new->operatorler = *(infix+i);
                        new->next = top;
                        top = new;

                    }


                }

                else if (*(infix+i) == '+' ||*(infix+i) == '-')
                {
                    if(top->operatorler == '*' || top->operatorler == '/' ||top->operatorler == '+' || top->operatorler == '-'  )
                    {
                        int uzunluk = strlen(postfix);
                        *(postfix+uzunluk) += top->operatorler;
                        top->operatorler = *(infix+i);
                    }
                    else if (top->operatorler == '(')
                    {
                        stacklar * new = (stacklar*)malloc(sizeof(stacklar));
                        new->operatorler = *(infix+i);
                        new->next = top;
                        top = new;
                    }


                }
            }

        }
        if (*(infix+i+1) == NULL)
        {
            stacklar * new = top;
            while(new)
            {
                int uzunluk = strlen(postfix);
                *(postfix+uzunluk) =new->operatorler;
                new = new->next;
                free(top);
                top = new;
            }

        }
         FILE *dosya;
      dosya = fopen("veriler.txt", "a");
        char *ptr1 = infix+i+1;
        while(*ptr1)
        {
            if(*ptr1 == NULL){
                fprintf(dosya,"bos");
             printf("bos");
            }

            fprintf(dosya,"%c",*ptr1);
            printf("%c",*ptr1);
            ptr1++;
        }
        printf("%-20c ");
        fprintf(dosya,"%-20c ");
        char *ptr = postfix;

        while (*ptr)
        {
            if(*ptr != ',')
            {
                fprintf(dosya,"%c",*ptr);
                printf("%c",*ptr);
            }
            fprintf(dosya," ");
            printf(" ");
            ptr++;
        }
        printf("%-20c ");
        fprintf(dosya,"%-20c ");
        stacklar * new = top;
        if (new == NULL)
        {
            printf("bos");
            fprintf(dosya,"bos");
        }
        else
        {


            while(new!= NULL)
            {
                fprintf(dosya,"%c ",new->operatorler);
                printf("%c  ",new->operatorler);
                new = new->next;
            }
        }

        printf("\n");
        fprintf(dosya,"\n");
        fclose(dosya);



    }
}
void postfixcevir(char *postfix)
{


    int uzunluk = strlen(postfix);
    for(int i=0; i<uzunluk; i++)
    {

        if(*(postfix+i) == '+' || *(postfix+i) == '-' ||*(postfix+i) == '*' ||*(postfix+i) == '/' )
        {
            stacklar2*ptr = head;

            switch(*(postfix+i))
            {
            case '+':
                ptr->next->a = ptr->next->a + ptr->a;
                head = ptr->next;
                free(ptr);
                break;
            case '-':
                ptr->next->a = ptr->next->a - ptr->a;
                head = ptr->next;
                free(ptr);
                break;
            case '*':
                ptr->next->a = ptr->next->a * ptr->a;
                head = ptr->next;
                free(ptr);
                break;
            case '/':
                ptr->next->a = ptr->next->a /ptr->a;
                head = ptr->next;
                free(ptr);

                break;
            }
        }

        else
        {
            int eleman =0,j = 1;
            char gecici[10];
             for (int i = 0; i < sizeof(gecici); i++)
            {
                gecici[i] = '\0';
            }
            if (*(postfix+i) == ',')
            {
                while(*(postfix+i+j) != ',')
                {
                    int uzunluk1 = strlen(gecici);
                    gecici[uzunluk1] += *(postfix+i+j);
                    j++;
                }
                i = i+j;
            }
            stacklar2 * newx = (stacklar2*)malloc(sizeof(stacklar2));

            newx->a = atoi(gecici);
            for (int i = 0; i < sizeof(gecici); i++)
            {
                gecici[i] = '\0';
            }
            newx->next =head;
            head= newx;

        }
        FILE *dosya;
        dosya = fopen("veriler.txt", "a");
        char *ptr1 = postfix+i+1;
        while(*ptr1)
        {
            if(*ptr1 != ',')
            {
                 fprintf(dosya,"%c  ",*ptr1);
                printf("%c  ",*ptr1);
            }
            ptr1++;
        }
        printf("%-20c ");
        fprintf(dosya,"%-20c ");
        stacklar2 * new = head;
        if (new == NULL)
        {
            printf("bos");
            fprintf(dosya,"bos");
        }
        else
        {


            while(new!= NULL)
            {
                fprintf(dosya,"%d  ",new->a);
                printf("%d  ",new->a);
                new = new->next;
            }
            printf("\n");
            fprintf(dosya,"\n");
        }

    }


}


int main()
{

    FILE *dosya;
    dosya = fopen("veriler.txt", "r");

    if (dosya == NULL)
    {
        printf("Dosya acilamadi.\n");
        return 1;
    }

    char karakter;
    char *infix, postfix[100][100];
    int i=0;
    infix = (char *)calloc(1000,sizeof(char));
    karakter=fgetc(dosya);
    while (karakter!=EOF)
    {
        *(infix+i)=karakter;
        karakter=fgetc(dosya);
        i++;
    }
    fclose(dosya);
    FILE *dosya1;
    dosya1 = fopen("veriler.txt", "a");
    fprintf(dosya1, "\ninfix\t\t\t\tposfix\t\t\t\tstack\n bos \t\t\t\t bos \t\t\t\t bos\n");
    printf("infix\t\t\t\tposfix\t\t\t\tstack\n bos \t\t\t\t bos \t\t\t\t bos\n");
    fclose(dosya1);
    infixcevir(infix,postfix);
    FILE *dosya2;
    dosya2 = fopen("veriler.txt", "a");
    fprintf(dosya1,"tposfix\t\t\t\tstack\n bos \t\t\t\t bos \n");
    printf("tposfix\t\t\t\t\t\tstack\n bos \t\t\t\t bos \n");
    fclose(dosya2);

    postfixcevir(postfix);


    return 0;
}
