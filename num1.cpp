#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int num1[200000];//数字一 
int num2[200000];//数字二 
char sign;//符号
int len1;//数字一长度 
int len2;//数字二长度
int flag=0;//输入标记正常
int flag1,flag2;//标记数字一数字二正负 
int stop;//停止标记 
int wrongg;//出错标志
int ans[1000000];//计算结果 
int len;//结果长度
int ansflag;


int init(){//输入 
    char s[200000],l;
    char si; 
	int i,j,k; 
	
	if(gets(s)==NULL)stop=1;
	//printf("%s\n",s);
	len1=strlen(s);
	//字符串首字母是0`9 或者+- 或者乱码判别 
	num1[0]=0;
	if(s[0]>='0'&&s[0]<='9'){
	    num1[0]=s[0]-'0';
	    flag1=1;
	}
	else if(s[0]=='+'){
		flag1=1;
	}
	else if(s[0]=='-'){
	    flag1=-1;
	}
	else {
		flag=1;
	}
	//字符串转换为数字 
	for(i=1;i<len1;i++)
	{
		if(s[i]<'0'||s[i]>'9'){
		    flag=1;break;
		}	
		num1[i]=s[i]-'0';
	}
		
	gets(s);
	len2=strlen(s);
	//字符串首字母是0`9 或者+- 或者乱码判别 
	num2[0]=0;
	if(s[0]>='0'&&s[0]<='9'){
	    num2[0]=s[0]-'0';
	    flag2=1;
	}
	else if(s[0]=='+'){
		flag2=1;
	}
	else if(s[0]=='-'){
	    flag2=-1;
	}
	else {
		flag=1;
	}
	//字符串转换为数字 
	for(i=1;i<len2;i++)
	{
		if(s[i]<'0'||s[i]>'9'){
		    flag=1;
			break;
		}		
		num2[i]=s[i]-'0';
	}
		 
    gets(s);
	l=strlen(s);
	if(l>1){
		flag=1;
	}
	si=s[0];
	if(si=='+'){
		sign=1;
    }
	else if(si=='-'){
		sign=2;
    }
	else if(si=='*'){
		sign=3;
    }
	else if(si=='/'){
		sign=4;
    }
    else {
    	flag=1;
	}
    
    return 1;
}

int wrong(){
	int i,j,k;
	//printf("%d %d\n",len1,len2);
	//输入错误 
	if(flag==1){
		wrongg=1;
		printf("Error input\n");
		return 0;
	}
	//除法除数为负数 
	if(sign==4&&flag2==-1){
		wrongg=1;
		printf("Error input\n");
		return 0;
	}
	//除法被除数为0 
	if(sign==4){
		j=0;
		for(i=0;i<len2;i++)
		   if(num2[i]!=0){
		   	j=1;break;
		   }
		if(j==0){
			wrongg=1;
		    printf("Error input\n");
	    	return 0;
		}
	}
	return 0;
}
int max(int a,int b){
    return a>b?a:b;
}
int jia(){
	int i,j,k;
	len=max(len1,len2);
	for(i=0;i<len;i++){
		if(len1-i-1>=0)
		ans[i]+=num1[len1-i-1];
		if(len2-i-1>=0)
		ans[i]+=num2[len2-i-1];
		ans[i+1]=ans[i]/10;
		ans[i]%=10; 
	}
	while(ans[len]>0)len++;
	while(len>=0&&ans[len]==0)len--;
	ansflag=flag1;
	return 0;
}
int panduan(){//num1>num2
	int i,j,k;
	i=0;
	while(num1[i]==0)i++;
	j=0;
	while(num2[j]==0)j++;
	//printf("%d %d\n",i,j);
	if(len1-i>len2-j)return 1;
	else if(len1-i<len2-j)return 0;
	for(k=0;k<len1-i;k++)
	if(num1[i+k]>num2[j+k])return 1;
	else if(num1[i+k]<num2[j+k])return 0;
	return 1;
}
int jian(){
	int i,j,k;
	int ff=-1;
	len=max(len1,len2);
	ff=panduan();
	
	//printf("%d\n",ff);
	
	if(ff==1){
	    for(i=0;i<len;i++){
		    if(len1-i-1>=0)
			ans[i]=ans[i]+num1[len1-i-1];
			if(len2-i-1>=0)
			ans[i]=ans[i]-num2[len2-i-1];
			if(ans[i]<0){			
			    ans[i]+=10;
				ans[i+1]=-1;
			}
	    }
	    if(flag1==1)ansflag=1;
	    else ansflag=-1;
	}
	else {
	    for(i=0;i<len;i++){
		    if(len2-i-1>=0)
			ans[i]=ans[i]+num2[len2-i-1];
			if(len1-i-1>=0)
			ans[i]=ans[i]-num1[len1-i-1];
			if(ans[i]<0){			
			    ans[i]+=10;
				ans[i+1]=-1;
			}
	    }
	    if(flag2==1)ansflag=-1;
	    else ansflag=1;
	}
	while(len>=0&&ans[len]==0)len--;
//	printf("%d\n",len);
	return 0;
}
int cheng(){
	int l1[100000],l2[100000],l3[100000];
	int i,j,k,p,q;
	memset(l1,0,sizeof(l1)); 
	memset(l2,0,sizeof(l2));
	memset(l3,0,sizeof(l3));
	for(i=0;i<=len1/4;i++)
	{
	    if(len1-4-i*4>=0)l1[i]=l1[i]*10+num1[len1-4-i*4];
	    if(len1-3-i*4>=0)l1[i]=l1[i]*10+num1[len1-3-i*4];
	    if(len1-2-i*4>=0)l1[i]=l1[i]*10+num1[len1-2-i*4];
	    if(len1-1-i*4>=0)l1[i]=l1[i]*10+num1[len1-1-i*4];
	}
	//for(i=0;i<=len1/4;i++)
	//printf("%d ",l1[i]);
	for(i=0;i<=len2/4;i++)
	{
	    if(len2-4-i*4>=0)l2[i]=l2[i]*10+num2[len2-4-i*4];
	    if(len2-3-i*4>=0)l2[i]=l2[i]*10+num2[len2-3-i*4];
	    if(len2-2-i*4>=0)l2[i]=l2[i]*10+num2[len2-2-i*4];
	    if(len2-1-i*4>=0)l2[i]=l2[i]*10+num2[len2-1-i*4];
	}
	//for(i=0;i<=len2/4;i++)
	//printf("%d ",l2[i]);
	
	for(i=0;i<=len1/4;i++){
		for(j=0;j<=len2/4;j++)
		{
		    l3[i+j]+=l1[i]*l2[j];
	    }
		for(j=0;j<=len2/4+i;j++)
		{
		    l3[j+1]+=l3[j]/10000;
			l3[j]%=10000; 
		} 
		while(l3[j]>=10000){
		     l3[j+1]+=l3[j]/10000;
			 l3[j]%=10000; 
		     j++;	
		}
		len=j;
	}
	for(i=0;i<=len;i++)
	{
		ans[i*4+3]=l3[i]/1000%10;
		ans[i*4+2]=l3[i]/100%10;
		ans[i*4+1]=l3[i]/10%10;
		ans[i*4]=l3[i]%10;
	}
	len=(len+1)*4; 
	while(len>=0&&ans[len]==0)len--;
	if(flag1==flag2)ansflag=1;
	else ansflag=-1;
	return 0;
}
int pand(int x){
	int i,j,k;
	for(i=0;i<len2;i++)
	if(num1[x+i]>num2[i])return 1;
	else if(num1[x+i]<num2[i])return 0;
	return 1;
}
int chu(){
	int i,j,k;
	j=0;
	while(panduan()==1){
		if(pand(j))
		{
		for(i=0;i<len2;i++)
		{
			num1[i+j]-=num2[i]; 
		}
		for(i=len2-1;i>=0;i--)
		if(num1[i+j]<0){
			num1[i+j-1]--;
			num1[i+j]+=10;
		}
		ans[j]++; 
		}
		else
		{
			num1[j+1]+=num1[j]*10;
			num1[j]=0;
			j++;
		}
	}
	len=j;
	int fff;
	fff=0;
	for(j=0;j<=len;j++)
	if(ans[j]!=0)fff=1;
	
	if(flag1==-1){
	if(fff==0){
		printf("0");
	}
	else{
	printf("-");
	i=0;while(ans[i]==0)i++;
	for(;i<=len;i++)
	printf("%d",ans[i]);
	}
	i=0;while(num1[i]==0&&i<=len1)i++;
	if(i>=len1)printf(" 0\n");
	else{ 
	printf(" -");
	for(;i<len1;i++)
	printf("%d",num1[i]);
	printf("\n");
	}
	} 
	else{
	if(fff==0){
		printf("0");
	}
	else{
	i=0;while(ans[i]==0)i++;
	for(;i<=len;i++)
	printf("%d",ans[i]);
	}
	
	i=0;while(num1[i]==0&&i<=len1)i++;
	if(i>=len1)printf(" 0\n");
	else{
	printf(" "); 
	for(;i<len1;i++)
	printf("%d",num1[i]);
	printf("\n");
	}
	}
}
int work(){
	if(sign==1){
		if(flag1==flag2) 
		{	
		    jia();
	    }
		else jian();
	}
	else if(sign==2){
		if(flag1==flag2){
		jian();
		}
		else jia();
	}
	else if(sign==3){
	    cheng();
	}
	else if(sign==4){
		chu();
	}
	return 0;
}
int print(){
	if(sign<4){
	if(len<0)printf("0\n");
	else{
	if(ansflag==-1)printf("-");
	for(int i=len;i>=0;i--)
	printf("%d",ans[i]);
	printf("\n");
	}
	}
	return 0;
}
int main(){
	//freopen("num1.in","r",stdin);
	//freopen("num1.out","w",stdout);
	
	stop=0;
	while(1){
		wrongg=0;
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		memset(ans,0,sizeof(ans));
		len1=0;
		len2=0;
		flag=0;
		len=0;
		flag1=0;
		flag2=0;
		ansflag=0;
		init();
		//printf("%d\n",flag);
	
		if(stop==1){
			return 0;
		}
		wrong();
		if(wrongg==0&&stop==0){
		    work();
		    print();
		}
	//	stop=1;
	}
	return 0;
}
