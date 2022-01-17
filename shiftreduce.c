#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

struct stack{
    char item[2];
    struct stack *next;
};
struct st{
    char opr[2];
    struct st *next;
};
struct table{
    char action[6][3][3];
    char Goto[3][2][2];
    
};
struct st *push(struct st *head,char opr[2]){
    struct st *newnode,*ptr;
    newnode=(struct st*)malloc(sizeof(struct st));
    int i;
    int length=strlen(opr);
    
    for(i=0;i<length;i++){
        newnode->opr[i]=opr[i];
    }
    if(head==NULL){
        head=newnode;
        newnode->next=NULL;
        return head;
    }
    else{
        ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=newnode;
        newnode->next=NULL;
        return head;
    }
}
void create_st(char *item,struct stack **head ){
    struct stack *newnode,*ptr;
    int length=strlen(item);
    char temp[length];
    int i=0;
    newnode=(struct stack*)malloc(sizeof(struct stack));
    for(i=0;i<length;i++){
        newnode->item[i]=item[i];
        
    }
    
    if(*head==NULL){
        *head=newnode;
        newnode->next=NULL;
    }
    else{
        ptr=*head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=newnode;
        newnode->next=NULL;
  
    }
}
struct stack *pop(struct stack **head){
    struct stack *ptr,*temp;
    ptr=*head;
    *head=ptr->next;
  
    return ptr;
}
struct st *popst(struct st *head){
    struct st *ptr;
    ptr=head;
    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=NULL;
    return head;
}
struct st *onTop(struct st *head){
    struct st *ptr;
    ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    return ptr;
}
void createList(struct table list[12]){
    strcpy(list[0].action[0][0],"id");
    strcpy(list[0].action[0][1],"s");
    strcpy(list[0].action[0][2],"5");
    strcpy(list[0].action[1][0],"(");
    strcpy(list[0].action[1][1],"s");
    strcpy(list[0].action[1][2],"4");
    strcpy(list[0].Goto[0][0],"E");
    strcpy(list[0].Goto[0][1],"1");
    strcpy(list[0].Goto[1][0],"T");
    strcpy(list[0].Goto[1][1],"2");
    strcpy(list[0].Goto[2][0],"F");
    strcpy(list[0].Goto[2][1],"3");
    strcpy(list[1].action[0][0],"+");
    strcpy(list[1].action[0][1],"s");
    strcpy(list[1].action[0][2],"6");
    strcpy(list[1].action[1][0],"$");
    strcpy(list[1].action[1][1],"acc");
    strcpy(list[1].action[1][2],"");
    strcpy(list[1].Goto[0][0],"E");
    strcpy(list[1].Goto[0][1],"1");
    strcpy(list[2].action[0][0],"+");
    strcpy(list[2].action[0][1],"r");
    strcpy(list[2].action[0][2],"2");
    strcpy(list[2].action[1][0],"*");
    strcpy(list[2].action[1][1],"s");
    strcpy(list[2].action[1][2],"7");
    strcpy(list[2].action[2][0],")");
    strcpy(list[2].action[2][1],"r");
    strcpy(list[2].action[2][2],"2");
    strcpy(list[2].action[3][0],"$");
    strcpy(list[2].action[3][1],"r");
    strcpy(list[2].action[3][2],"2");
    strcpy(list[3].action[0][0],"+");
    strcpy(list[3].action[0][1],"r");
    strcpy(list[3].action[0][2],"4");
    strcpy(list[3].action[1][0],"*");
    strcpy(list[3].action[1][1],"r");
    strcpy(list[3].action[1][2],"4");
    strcpy(list[3].action[2][0],")");
    strcpy(list[3].action[2][1],"r");
    strcpy(list[3].action[2][2],"4");
    strcpy(list[3].action[3][0],"$");
    strcpy(list[3].action[3][1],"r");
    strcpy(list[3].action[3][2],"4");
    strcpy(list[4].action[0][0],"id");
    strcpy(list[4].action[0][1],"s");
    strcpy(list[4].action[0][2],"5");
    strcpy(list[4].action[1][0],"(");
    strcpy(list[4].action[1][1],"s");
    strcpy(list[4].action[1][2],"4");
    strcpy(list[4].Goto[0][0],"E");
    strcpy(list[4].Goto[0][1],"8");
    strcpy(list[4].Goto[1][0],"T");
    strcpy(list[4].Goto[1][1],"2");
    strcpy(list[4].Goto[2][0],"F");
    strcpy(list[4].Goto[2][1],"3");
    strcpy(list[5].action[0][0],"+");
    strcpy(list[5].action[0][1],"r");
    strcpy(list[5].action[0][2],"6");
    strcpy(list[5].action[1][0],"*");
    strcpy(list[5].action[1][1],"r");
    strcpy(list[5].action[1][2],"6");
    strcpy(list[5].action[2][0],")");
    strcpy(list[5].action[2][1],"r");
    strcpy(list[5].action[2][2],"6");
    strcpy(list[5].action[3][0],"$");
    strcpy(list[5].action[3][1],"r");
    strcpy(list[5].action[3][2],"6");
    strcpy(list[6].action[0][0],"id");
    strcpy(list[6].action[0][1],"s");
    strcpy(list[6].action[0][2],"5");
    strcpy(list[6].action[1][0],"(");
    strcpy(list[6].action[1][1],"s");
    strcpy(list[6].action[1][2],"4");
    strcpy(list[6].Goto[0][0],"T");
    strcpy(list[6].Goto[0][1],"9");
    strcpy(list[6].Goto[1][0],"F");
    strcpy(list[6].Goto[1][1],"3");
    strcpy(list[7].action[0][0],"id");
    strcpy(list[7].action[0][1],"s");
    strcpy(list[7].action[0][2],"5");
    strcpy(list[7].action[1][0],"(");
    strcpy(list[7].action[1][1],"s");
    strcpy(list[7].action[1][2],"4");
    strcpy(list[7].Goto[0][0],"F");
    strcpy(list[7].Goto[0][1],"10");
    strcpy(list[8].action[0][0],"+");
    strcpy(list[8].action[0][1],"s");
    strcpy(list[8].action[0][2],"6");
    strcpy(list[8].action[1][0],")");
    strcpy(list[8].action[1][1],"s");
    strcpy(list[8].action[1][2],"11");
    strcpy(list[9].action[0][0],"+");
    strcpy(list[9].action[0][1],"r");
    strcpy(list[9].action[0][2],"1");
    strcpy(list[9].action[1][0],"*");
    strcpy(list[9].action[1][1],"s");
    strcpy(list[9].action[1][2],"7");
    strcpy(list[9].action[2][0],")");
    strcpy(list[9].action[2][1],"r");
    strcpy(list[9].action[2][2],"1");
    strcpy(list[9].action[3][0],"$");
    strcpy(list[9].action[3][1],"r");
    strcpy(list[9].action[3][2],"1");
    strcpy(list[10].action[0][0],"+");
    strcpy(list[10].action[0][1],"r");
    strcpy(list[10].action[0][2],"3");
    strcpy(list[10].action[1][0],"*");
    strcpy(list[10].action[1][1],"r");
    strcpy(list[10].action[1][2],"3");
    strcpy(list[10].action[2][0],")");
    strcpy(list[10].action[2][1],"r");
    strcpy(list[10].action[2][2],"3");
    strcpy(list[10].action[3][0],"$");
    strcpy(list[10].action[3][1],"r");
    strcpy(list[10].action[3][2],"3");
    strcpy(list[11].action[0][0],"+");
    strcpy(list[11].action[0][1],"r");
    strcpy(list[11].action[0][2],"5");
    strcpy(list[11].action[1][0],"*");
    strcpy(list[11].action[1][1],"r");
    strcpy(list[11].action[1][2],"5");
    strcpy(list[11].action[2][0],")");
    strcpy(list[11].action[2][1],"r");
    strcpy(list[11].action[2][2],"5");
    strcpy(list[11].action[3][0],"$");
    strcpy(list[11].action[3][1],"r");
    strcpy(list[11].action[3][2],"5");

}

void parser(struct stack *head){
    struct st *head_st=NULL;
    struct table list[12];
    int check=1,i,y=0,syntax_check=0;
    struct stack *ptr;
    struct st *ptrst,*end;
    char opr[2];
    char number[2],goto_number[2];

    head_st=push(head_st,"0");
    createList(list);
    printf("STACK\t\t\t\t\t\t\t\t\t\t\t\tINPUT\t\t\t\t\t\t\t\t\t\t\t\tACTION\n");
    while(check){
        syntax_check=0;
        ptrst=head_st;
        while(ptrst!=NULL){
            printf("%s",ptrst->opr);
            ptrst=ptrst->next;
        }
        printf("\t\t\t\t\t\t\t\t\t\t\t\t");
        ptr=head;
        while(ptr!=NULL){
            printf("%s",ptr->item);
            ptr=ptr->next;
        }
        
        printf("\t\t\t\t\t\t\t\t\t\t\t\t");
        for(i=0;i<12;i++){
            if(!strcmp(head->item,list[atoi(onTop(head_st)->opr)].action[i][0])){
  
                strcpy(opr,list[atoi(onTop(head_st)->opr)].action[i][1]);
                strcpy(number,list[atoi(onTop(head_st)->opr)].action[i][2]);
                syntax_check=1;
 
            }
 
        }
        
        if(syntax_check && (!strcmp(opr,"ac"))){
            check=0;
            printf("accept");
        }
        else if(syntax_check && (!strcmp(opr,"s"))){
            head_st=push(head_st,pop(&head)->item);
            head_st=push(head_st,number);
            printf("Shift %s\n",number);
           
        }
        else if(syntax_check && (!strcmp(opr,"r"))){
           
            switch(atoi(number)){
                case 1:
                    for(i=0;i<6;i++){
                        head_st=popst(head_st);
                    }
                    
                    for(i=0;i<12;i++){
                        if(!strcmp("E",list[atoi(onTop(head_st)->opr)].Goto[i][0])){
                            strcpy(goto_number,list[atoi(onTop(head_st)->opr)].Goto[i][1]);
                        }
                    }
             
                    printf("Reduce %s use GOTO[E,%s]\n",number,goto_number);
                    head_st=push(head_st,"E");
                    head_st=push(head_st,goto_number);
                    break;
                case 2:
                    for(i=0;i<2;i++){
                        head_st=popst(head_st);
                    }
                    
                    for(i=0;i<12;i++){
                        if(!strcmp("E",list[atoi(onTop(head_st)->opr)].Goto[i][0])){
                            strcpy(goto_number,list[atoi(onTop(head_st)->opr)].Goto[i][1]);
                        }
                    }
                    printf("Reduce %s use GOTO[E,%s]\n",number,goto_number);
                    head_st=push(head_st,"E");
                    head_st=push(head_st,goto_number);
                    break;
                case 3:
                    for(i=0;i<6;i++){
                        head_st=popst(head_st);
                    }
                   
                    for(i=0;i<12;i++){
                        if(!strcmp("T",list[atoi(onTop(head_st)->opr)].Goto[i][0])){
                            strcpy(goto_number,list[atoi(onTop(head_st)->opr)].Goto[i][1]);
                        }
                    }
                    printf("Reduce %s use GOTO[T,%s]\n",number,goto_number);
                     head_st=push(head_st,"T");
                    head_st=push(head_st,goto_number);
                    break;
                case 4:
                    for(i=0;i<2;i++){
                        head_st=popst(head_st);
                    }
                    
                    for(i=0;i<12;i++){
                        if(!strcmp("T",list[atoi(onTop(head_st)->opr)].Goto[i][0])){
                            strcpy(goto_number,list[atoi(onTop(head_st)->opr)].Goto[i][1]);
                          
                        }
                    }
                    printf("Reduce %s use GOTO[T,%s]\n",number,goto_number);
                    head_st=push(head_st,"T");
                    head_st=push(head_st,goto_number);
                    break;
                case 5:
                    for(i=0;i<6;i++){
                        head_st=popst(head_st);
                    }
                   
                    for(i=0;i<12;i++){
                        if(!strcmp("F",list[atoi(onTop(head_st)->opr)].Goto[i][0])){
                            strcpy(goto_number,list[atoi(onTop(head_st)->opr)].Goto[i][1]);
                        }
                    }
                    printf("Reduce %s use GOTO[F,%s]\n",number,goto_number);
                    head_st=push(head_st,"F");
                    head_st=push(head_st,goto_number);
                    break;
                case 6:
                    for(i=0;i<2;i++){
                        head_st=popst(head_st);
                    }
                    
                    for(i=0;i<12;i++){
                        if(!strcmp("F",list[atoi(onTop(head_st)->opr)].Goto[i][0])){
                            strcpy(goto_number,list[atoi(onTop(head_st)->opr)].Goto[i][1]);
                        }
                    }
                    printf("Reduce %s use GOTO[F,%s]\n",number,goto_number);
                    head_st=push(head_st,"F");
                    head_st=push(head_st,goto_number);
                    break;
            }
        }
        else{
            printf("invalid syntax");
            check=0;
            break;
        }
    }
}

int main(){
    struct stack *inputHead=NULL;
    int i=0,check=1;
    char *str,c;
    struct stack *ptr;
    int count1=0,count2=0;
    while((scanf("%c",&c))!=EOF){
        if(c==' '){
            i=0;
            
            continue;
        }
        else if(c=='i'){
            i=0;
            str[i++]=c;
            continue;
            
        }
        else if(c=='d'){
            str[i++]=c;
            create_st(str,&inputHead);
            i=0;
            str[1]=0;
            continue;
        }
        str[0]=c;
        create_st(str,&inputHead);
        
    }
    create_st("$",&inputHead);
    ptr=inputHead;
    parser(inputHead);

    return 0;
}
