/***�ַ���ƥ���㷨***/
#include<cstring>
#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
#define MAXSTRLEN 255   		//�û�����255���ڶ��������
typedef struct {		//0�ŵ�Ԫ��Ŵ��ĳ���
 char ch[MAXSTRLEN+1];
 int length;
  }SString;
Status StrAssign(SString &T, char *chars) { //����һ����ֵ����chars�Ĵ�T
	int i;
	if (strlen(chars) > MAXSTRLEN)
		return ERROR;
	else {
		T.length = strlen(chars);
		for (i = 1; i <= T.length; i++)
			T.ch[i] = *(chars + i - 1);
		return OK;
	}
}

//��д4.1��BF�㷨 �����Ӽ���Ƚϴ��� 
int Index_BF(SString S, SString T, int pos)
{
	//����ģʽT������S�е�pos���ַ�֮���sһ�γ��ֵ�λ�á��������ڣ��򷵻�ֵΪ0
	//���У�T�ǿգ�1��pos��StrLength(S)
	int i = pos, j = 1,sum = 0;
	while (i <= S.length && j <= T.length)
	{	
	if (j == 0 || S.ch[i] == T.ch[j]) // �����ȽϺ����
		{
			++i;
			++j;
			++sum;
		}
		else
		{ 	
			i=i-j+2;
			j = 1; 
			sum++;
		}// ģʽ�������ƶ�
	}
	cout<<"�Ƚϴ���Ϊ:"<<sum<<endl;
	if (j > T.length) // ƥ��ɹ�
		return i - T.length;
	else
		return 0;
	 
}
//}//Index
//�㷨4.3������next����ֵ
void get_next(SString T, int next[])
{ 
//��ģʽ��T��next����ֵ����������next
	int i = 1, j = 0;
	next[1] = 0;
	while (i < T.length)
	{
	
		if (j == 0 || T.ch[i] == T.ch[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
		{	
			j = next[j];
		}
	}
}//get_next

//�㷨4.2��KMP�㷨,���Ӽ���Ƚϴ���
int Index_KMP(SString S, SString T, int pos, int next[])
{ 	// ����ģʽ��T��next������T������S�е�pos���ַ�֮���λ�õ�KMP�㷨
	//���У�T�ǿգ�1��pos��StrLength(S)
	int i = pos, j = 1;
	int sum = 0;
	while (i <= S.length && j <= T.length)
	{	
	if (j == 0 || S.ch[i] == T.ch[j]) // �����ȽϺ����
		{
			++i;
			++j;
			sum++;
		}
		else
		{
			j = next[j]; 
			sum++;
		}
	}// ģʽ�������ƶ�
	cout<<"�Ƚϴ���Ϊ:"<<sum<<endl;
	if (j > T.length) // ƥ��ɹ�
		return i - T.length;
	else
		return 0;
	 
}//Index_KMP
int main()
{
	SString S;
	StrAssign(S,"bbabababababba") ;
	SString T;
	StrAssign(T,"bab") ;	
	cout<<"����BF�㷨:"<<endl; 
	cout<<"�������Ӵ��ڵ�"<<Index_BF(S,T,1)<<"���ַ����״�ƥ��\n";
	int *p = new int[T.length+1]; // ����T��next����
	get_next(T,p);
	cout<<"����KMP�㷨:"<<endl;
	cout<<"�������Ӵ��ڵ�"<<Index_KMP(S,T,1,p)<<"���ַ����״�ƥ��\n";
	return 0;
}
