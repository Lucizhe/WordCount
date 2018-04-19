#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype> 

int charcalculate=0;
int wordcalculate=0;
int sentcalculate=0;
int linecalculate=0;

void calculate(char * file)
{
    FILE * fp;
    char a;
    if((fp=fopen(file,"r"))==NULL)
    {
        printf("read file failed£¡\n");
        exit(-1);
    }
    bool aflag=false;
    while(!feof(fp))
    {
    	
        a=fgetc(fp);
        if(isalpha(a)){
            charcalculate++;
            aflag=true;
    	}
        if(isalpha(a)==0&&aflag){
            wordcalculate++;
            aflag=false;
    	}
        if(a=='!'||a=='?'||a=='.'||a==';'||a=='~'){
            sentcalculate++;
            aflag=false;
    	}
    	if(a=='\n'||a=='\t')
            linecalculate++;
    } 
    linecalculate++;          
    fclose(fp);
}
 
int main(int argc, char* argv[])              
{
    FILE *fp;
    while(1)
    {	
		
        if((fp=fopen(argv[2],"r"))==NULL)
	    {   
	        printf("No such file!\n");
	        break;
        }
		calculate(argv[2]);
        if(!strcmp(argv[1],"-c"))
		{                
            printf("File:%s  CharNum:%d\n",argv[2],charcalculate);
            break;
        }
        else if(!strcmp(argv[1],"-w"))   
		{           
            printf("File:%s  WordNum:%d\n",argv[2],wordcalculate);
            break;
    	}
        else if(!strcmp(argv[1],"-s"))
		{                
            printf("File:%s  sentNum:%d\n",argv[2],sentcalculate);
            break;
    	}
    	else if(!strcmp(argv[1],"-l"))
		{                
            printf("File:%s  LineNum:%d\n",argv[2],linecalculate);
            break;
    	}
        else if(!strcmp(argv[1],"exit"))
        {
            printf("Exit!\n");
            break;
        }
        else
        {
            printf("This Command is not supported!\n");
            break;
    	}
    }
    return 0;
     
}
