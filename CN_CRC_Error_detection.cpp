#include<iostream>
using namespace std;
int length;
void rev(int num[],int len)
{
     int temp;
     for(int i1=0,i2=len-1;i1<len/2;i1++,i2--)
     {
             temp=num[i2];
             num[i2]=num[i1];
             num[i1]=temp;
     }
     return;
}
void dec_to_bin(int dec,int bin_ary[])
{
       int tmp,i=0;
       tmp=dec;
       while(tmp!=0)
       {
                    bin_ary[i]=tmp%2;
                    tmp=tmp/2;
                    i++;
       }
       rev(bin_ary,i);
       length=i;
       for(int a=0;a<i;a++)
               cout<<bin_ary[a];
       cout<<endl;
       return;
}
 int sub_xor_bin(int divt[],int divr[],int len_div,int len)
 {
      int j=0,k;

      while(divt[j]!=1)
              j++;
      if((len-j)<len_div)
                        return 0;
      for(int i=j,k=0;i<(len_div+j);i++,k++)
      {
              if(divt[i]==divr[k])
                                  divt[i]=0;
              else
                  divt[i]=1;
      }
      return 1;
 }

 void app_end(int num[],int app,int &norm)
 {
      length=(norm+app)-1;
      for(int i=norm-1;i<length;i++)
              num[i]=0;
      cout<<"The number after appending is:\n";
      for(int i=0;i<length;i++)
              cout<<num[i]<<" ";
      cout<<endl;

      norm=length;
 }


 void division(int msg[],int &len_msg,int gn[],int len_gn)
 {
      int flag;
      app_end(msg,len_gn,len_msg);
      for(int i=0;i<len_msg-2;i++)
      {
              flag=sub_xor_bin(msg,gn,len_gn,len_msg);
              if(flag==0)
              break;
      }
      cout<<"The msg now after dividing:\n";
      for(int i=0;i<len_msg;i++)
              cout<<msg[i]<<" ";
      cout<<endl;
 }
