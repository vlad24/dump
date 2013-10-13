#include <stdio.h>
bool stringsEqual(char* s1, char* s2)
{
	int j = 0;
	bool b = true;
	while((s1[j] != '\0') && (s2[j]!='\0') && b)
	{
		if (!(s1[j] == s2[j]))
			b = false;
		j++;
	}
	return b;
}
int stringLength(char s[])
{
	int j = 0;
	while (s[j] != '\0')
		j++;
	return j - 1;
}
void fillString(char mainString[],char tmpString[], int from,int subLen)
{
	for(int i = 0 ; i < subLen ; i++)
	{
		tmpString[i] = mainString[from + i];
	}
}
int hashFunction(char string[])
{
	int p = 3;
	int pPower = 1;
	int j = 0;
	int sum = 0;
	while((string[j] != '\0') && (string[j] != '\n'))
	{
		int letterOrd = int(string[j]) - int('0');
		int adder = ((letterOrd)%4211 * (pPower)%4211) % 4211;
		sum = (sum + adder) % 4211;
		pPower = (pPower%4211 * p%4211)%4211;
		j++;
	}
	return sum ;
}
int securePower(int p , int power , int mod)
{
	int pPower = p;
	int j = 1;
	while (j < power)
	{
		pPower = (pPower%mod * p%mod) % mod;
		j++;
	}
	return pPower;
}
int rehash(int curIndex,char s1[],int from,int len)
{

	int letterOrdFrom = int(s1[from]) - int('0');
	int letterOrdLast = int(s1[from + len]) - int('0');
	curIndex = curIndex - letterOrdFrom;
	if (curIndex < 0)
		curIndex += 4211;
	while (curIndex % 3 != 0)
		curIndex += 4211;
	
	curIndex /= 3;
	curIndex = (curIndex + (letterOrdLast * securePower(3,len - 1,4211)) % 4211) % 4211;
	return curIndex;
}


int main()
{
	printf("\n");
	char mainString[501] = {};
	char subString[500] = {};
	char tmpString[500] = {};

	//Main String init
	printf("Enter the main string :\n");
	fgets(mainString,501,stdin);
	int mainLen = stringLength(mainString);
	printf("[length = %d]\n",mainLen);
	//Sub string init
	printf("Enter the substring,which you want to find :\n");
	fgets(subString,500,stdin);
	int subLen = stringLength(subString);
	printf("[length = %d]\n",subLen);
	//Tmp string init
	fillString(mainString,tmpString,0,subLen);

	int subIndex = hashFunction(subString);
	int tmpIndex = hashFunction(tmpString);
	int start = 0 ;
	int position = -1;
	
	while((position == -1) && (start <= mainLen - subLen))
	{

		if(subIndex == tmpIndex)
		{
			if(stringsEqual(tmpString,subString))
			{
				position = start;
				break;
			}
		}
		else
		{
			tmpIndex = rehash(tmpIndex,mainString,start,subLen);
			++start;
			fillString(mainString,tmpString,start,subLen);
		}
	}

	if(position != -1)
		printf("\nThe sub-string is from %d symbol in the main string\n",position);
	else
		printf("\nNo such a sub-string");
	getc(stdin);
	return 0;
}