#include <stdio.h>

void squeeze(char *s1, char *s2){
    if(s1 && s2){
        int i=0, k=0;
        while(s1[i]){
            int j=0;
            int found=0;
            while(s2[j] && !found){
                if(s1[i]==s2[j]){
                    found=1;
                }
                j++;
            }
            if(!found){
                s1[k++]=s1[i];
            }
            i++;
        }
        s1[k]='\0';
        printf("%s\n",s1);
    }
}

int charToValue(char text){
    if(text>='0'&&text<='9'){
        return text-'0';
    }
    return text-'A'+10;
}

void isDecMult4(char *text, int base){
    if(text){
        int len=0;
        while(text[len]){
            len++;
        }
        int value;
        if(len==0){
            value=0;
        }
        else if(len==1){
            value=charToValue(text[0]);
        }
        else{
            int a=charToValue(text[len-2]);
            int b=charToValue(text[len-1]);
            value=a*base+b;
        }
        if(value%4==0){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }
}

void printDifWords(char *sq, char *W){
    if(sq && W){
        int i=0;
        int wlen=0;
        char tmp[100];
        while(W[wlen]){
            wlen++;
        }
        while(sq[i]){
            while(sq[i]&&(sq[i]==','||sq[i]==' '||sq[i]=='.')){
                i++;
            }
            if(!sq[i]){
                break;
            }
            int j=0;
            while(sq[i]&&sq[i]!=','&&sq[i]!=' '&&sq[i]!='.'){
                tmp[j++]=sq[i++];
            }
            tmp[j]='\0';
            int sqlen=j;
            int eq=(sqlen==wlen);
            if(eq){
                int k=0;
                while(k<sqlen){
                    if(tmp[k]!=W[k]){
                        eq=0;
                        break;
                    }
                    k++;
                }
            }
            if(!eq){
                printf("%s ",tmp);
            }
        }
    }
}

int main()
{
    char s1[]="asndfghasjkar";
    char s2[]="sdafe";
    squeeze(s1,s2);

    char text[]="1C";
    int base=16;
    isDecMult4(text,base);

    char sq[]="aaa, bbb, bbbc, bbbb, bb.";
    char W[]="bbb";
    printDifWords(sq,W);

    return 0;
}
