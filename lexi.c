//Lexical Analyser 

# include <stdio.h>
# include <string.h>
char kw [ 30 ] [ 10 ] = { "include" , "int" , "float" , "char", "void" , "main" , "printf" , "scanf", "<stdio.h>" , "<string.h>" } ;
char op [ 30 ] [ 2 ] = { "++" , "--" ,"**","/","+","-","*","==","<=",">=","=","<",">","#","&&","||", "&","|"};
char sym[30][2]={".",",",";","(",")","{","}","[","]"};
void main()
{	char ch ; char s [ 100 ] ; int si = 0 ;int i,nf=0;int d=1;
	FILE *fp=fopen("prog.txt","r");
	while(!feof(fp))
	{	fscanf(fp,"%c",&ch);
		if((s[0]=='/' && s[1]=='/' && ch=='\n')||(s[0]=='/' && s[1]=='*' && s[si-1]=='*' && ch=='/'))
		{	s[0]='\0';si=0;nf=0;d=1;
            continue;
		}
		else if((s[0]=='/' && s[1]=='/')||(s[0]=='/' && s[1]=='*'))
			continue;
        		else if (s[0]=='"' && si!=1 && ch=='"')
        		{   	s[si++]=ch;s[si]='\0';
			printf("\n%s literal",s);
			s[0]='\0';si=0;nf=0;d=1;
       		 }	
       		 else if (s[0]=='"')
        		{   	s[si++]=ch;
            			continue;
       		 }
		else if (ch==' ' || ch=='\n' || ch=='\t')
		{	s[si]='\0';
            			if(strcmp(s,"")!=0)
           			 {  	 printf("\n%s",s);
                			for (i=0;i<10 && nf==0;i++)
                			{	if (strcmp(kw[i],s)==0)
                    				{	printf(" keyword");nf=1;
                    				}
                			}
                			for (i=0;i<14 && nf==0;i++)
                			{	if (strcmp(op[i],s)==0)
                    				{	printf(" operator");nf=1;
                    				}
                			}
                			for (i=0;i<7 && nf==0;i++)
                			{	if (strcmp(sym[i],s)==0)
                    				{	printf(" symbol");nf=1;
                    				}
                			}
                			if(nf==0)
                			{	d=1;
                    				for(i=0;i<strlen(s) && d==1;i++)
                    				{	if(!(s[i]>='0' && s[i]<='9'))
                        					{	d=0;
                        					}
                    				}
                    				if(d==1)
                    				{	printf(" constant");
                        					nf=1;
                    				}
                    				else
                    				{	printf(" identifier");
                    				}
                			}
            			}
			s[0]='\0';si=0;nf=0;d=1;
		}
		else
		{	s[si++]=ch;
		}
	}
}

