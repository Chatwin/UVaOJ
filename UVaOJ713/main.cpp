#include<stdio.h>
#include<string.h>
char a[300],b[300];
int a1[300],b1[300];
int main() {
	int T,len1,len2,len,i,j;
	scanf("%d",&T);
	while(T--) {
		scanf("%s%s",a,b);
		len1=strlen(a),len2=strlen(b);
		memset(a1,0,sizeof(a1));
		memset(b1,0,sizeof(b1));
		for(i=0;i<len1;i++)a1[i]=a[i]-'0';
		for(j=0;j<len2;j++)b1[j]=b[j]-'0';
		len=len1>len2?len1:len2;
		for(i=0;i<=len;i++) {
			a1[i]+=b1[i];
			if(a1[i]>=10) a1[i+1]+=a1[i]/10, a1[i]%=10;
		}
		if(a1[len]==0) len--;
		for(i=0;a1[i]==0;i++);
		for(;i<=len;i++) printf("%d",a1[i]);
		printf("\n");
	}
	return 0;
}
