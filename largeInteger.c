#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10000
char *add(char num1[], char num2[]);
char *minus(char num1[], char num2[]);
char *multiply(char num1[], char num2[]);
char *divide(char num1[], char num2[]);
char *divideImprove(char num1[], char num2[], int num[]);
void printOut(char *result);
void reverseOrder(char *str, int end);
void reverseOrderInt(int *str, int end);
void plus_one(char a[]);
void printRemainder(int *remainder);
int isSame(char *a, char *b);
int compare(int*num1, int*num2, int n1, int n2);
int main()
{
	int selection = 0;
	int stop = 0;
	char num1[10000] = { 0 };
	char num2[10000] = { 0 };
	int remainder[MAX] = { 0 };
	char *result = NULL;
	while (!stop)
	{
		printf("Select the thing you want to do: \n");
		printf("1. +   2. -  3. *  4. /(loop, it is slow)  5. /(it is faster) 6. stop\n");
		scanf("%d", &selection);
		if (selection == 6) break;
		printf("Please enter the first large num(it must be bigger than the second one):\n");
		scanf("%s", num1);
		printf("Please enter the second large num:\n");
		scanf("%s", num2);
		switch (selection)
		{
		case 1:
			result = add(num1, num2);
			printOut(result);
			free(result);
			break;
		case 2:
			result = minus(num1, num2);
			printOut(result);
			free(result);
			break;
		case 3:
			result = multiply(num1, num2);
			printOut(result);
			free(result);
			break;
		case 4:
			result = divide(num1, num2);
			printOut(result);
			free(result);
			break;
		case 5:
			result = divideImprove(num1, num2, remainder);
			printOut(result);
			printRemainder(remainder);
			free(result);
			break;
		case 6: 
			stop = 1; 
			break;
		default: break;
		}
	}
	return 0;
}
/*char *add(char num1[], char num2[])
{
	char *pnum1 = NULL;
	char *pnum2 = NULL;
	int digital1 = 0;//the length of num1
	int digital2 = 0;//the length of num2
	char *currentResult = NULL;
	char result[10001] = { 0 };
	int carry = 0;
	for (pnum1 = num1; *pnum1 != '\0'; pnum1++)//count the length of num1
		digital1++;
	for (pnum2 = num2; *pnum2 != '\0'; pnum2++)//count the length of num2
		digital2++;
	pnum1--;
	pnum2--;
	currentResult = &result[(digital1 > digital2 ? digital1 : digital2) + 1];
	while (pnum1 != num1 - 1 || pnum2 != num2 - 1 || carry == 1)
	{
		if (pnum1 != num1 - 1 && pnum2 != num2 - 1)
		{
			*currentResult = (*pnum1 - '0' + *pnum2 - '0' + carry) % 10 + '0';
			carry = (*pnum1 - '0' + *pnum2 - '0' + carry - (*pnum1 - '0' + *pnum2 - '0' + carry) % 10) / 10;//flash the carry
			currentResult--;
			pnum1--;
			pnum2--;
		}
		else if (pnum1 == num1 - 1 && pnum2 != num2 - 1)
		{
			*currentResult = (*pnum2 - '0' + carry) % 10 + '0';
			carry = (*pnum2 - '0' + carry - (*pnum2 - '0' + carry) % 10) / 10;
			currentResult--;
			pnum2--;
		}
		else if (pnum1 != num1 - 1 && pnum2 == num2 - 1)
		{
			*currentResult = (*pnum1 - '0' + carry) % 10 + '0';
			carry = (*pnum1 - '0' + carry - (*pnum1 - '0' + carry) % 10) / 10;
			currentResult--;
			pnum1--;
		}
		else if (carry == 1)
		{
			*currentResult = '1';
			currentResult--;
			carry = 0;
		}
	}
	return result;
}
char *minus(char num1[], char num2[])
{
	char *pnum1 = NULL;
	char *pnum2 = NULL;
	char *temp = NULL;
	int digital1 = 0;//the length of num1
	int digital2 = 0;//the length of num2
	char *currentResult = NULL;
	char result[10001] = { 0 };
	int carry = 0;
	for (pnum1 = num1; *pnum1 != '\0'; pnum1++)//count the length of num1
		digital1++;
	for (pnum2 = num2; *pnum2 != '\0'; pnum2++)//count the length of num2
		digital2++;
	pnum1--;
	pnum2--;
	currentResult = &result[(digital1 > digital2 ? digital1 : digital2) + 1];
	while (pnum1 != num1 - 1 || pnum2 != num2 - 1 || carry == 1)
	{
		if (pnum1 != num1 - 1 && pnum2 != num2 - 1)
		{
			*currentResult = (10 + (*pnum1 - '0' ) - (*pnum2 - '0') - carry) % 10 + '0';
			carry = ((*pnum1 - '0') - (*pnum2 - '0') - carry) < 0 ? 1 : 0;//flash the carry
			currentResult--;
			pnum1--;
			pnum2--;
		}
		else if (pnum1 == num1 - 1 && pnum2 != num2 - 1)
		{
			*currentResult = (10 + *pnum2 - '0' - carry) % 10 + '0';
			carry = ((*pnum2 - '0') - carry) < 0 ? 1 : 0;//flash the carry
			currentResult--;
			pnum2--;
		}
		else if (pnum1 != num1 - 1 && pnum2 == num2 - 1)
		{
			*currentResult = (10 + *pnum1 - '0' - carry) % 10 + '0';
			if (*currentResult == '0')*currentResult = '\0';
			carry = ((*pnum1 - '0') - carry) < 0 ? 1 : 0;//flash the carry
			currentResult--;
			pnum1--;
		}
		else if (carry == 1)
		{
			*currentResult = '-';
			currentResult--;
			carry = 0;
		}
	}
	return result;
}*/
int compare(int *num1, int *num2, int n1, int n2) 
{
	int i = n2>n1 ? n2 - 1 : n1 - 1;
	for (; i >= 0; i--)
		if (num2[i]>num1[i])
			return 0;
		else if (num2[i]<num1[i])
			return 1;
	return 1;
}
int isSame(char *a, char *b)
{
	int alen, blen;
	int i = 0;
	char *num1 = a, *num2 = b;
	for (; *num1 == '0'; num1++);
	for (; *num2 == '0'; num2++);
	alen = strlen(num1);
	blen = strlen(num2);
	if (alen>blen)
		return 1;
	else if (alen<blen)
		return -1;
	else //length is equal
	{
		while (num1[i] == num2[i] && i < alen)
			i++;
		if (i == alen)
			return 0;
		else if (num1[i]>num2[i])//num1 > num2
			return 1;
		else
			return -1;
	}
}
char *add(char num1[], char num2[])
{
	int i = 0;
	int num1L = 0;
	int num2L = 0;
	int carry = 0;
	char *result;
	result = malloc(sizeof(char) * 10000);
	memset(result, '0', 10000);
	num1L = strlen(num1);
	num2L = strlen(num2);
	result[num1L + 1] = '\0';
	reverseOrder(num1, num1L - 1);
	reverseOrder(num2, num2L - 1);
	for (i = 0; i <= num1L; i++)//digital in num2
	{
		if (num2[i] != '\0' && num1[i] != '\0')
		{
			result[i] = ((num1[i] - '0') + (num2[i] - '0') + carry) % 10 + '0';
			carry = ((num1[i] - '0') + (num2[i] - '0') + carry) >= 10 ? 1 : 0;//flash the carry
		}
		else if (num1[i] != '\0')
		{
			result[i] = ((num1[i] - '0') + carry) % 10 + '0';
			carry = ((num1[i] - '0') + carry) >= 10 ? 1 : 0;
		}
		else
			result[i] = carry + '0';
	}
	for (i = num1L; result[i] == '0'; i--);
	i++;
	result[i] = '\0';
	reverseOrder(num1, num1L - 1);
	reverseOrder(num2, num2L - 1);
	reverseOrder(result, i - 1);
	return result;
}
char *minus(char num1[], char num2[])
{
	int i = 0;
	int num1L = 0;
	int num2L = 0;
	int carry = 0;
	char *result;
	result = malloc(sizeof(char) * 10000);
	memset(result, '0', 10000);
	num1L = strlen(num1);
	num2L = strlen(num2);
	result[num1L] = '\0';
	reverseOrder(num1, num1L - 1);
	reverseOrder(num2, num2L - 1);
	for (i = 0; i < num1L; i++)//digital in num2
	{
		if (num2[i] != '\0')
		{
			result[i] = (10 + (num1[i] - '0') - (num2[i] - '0') - carry) % 10 + '0';
			carry = ((num1[i] - '0') - (num2[i] - '0') - carry) < 0 ? 1 : 0;//flash the carry
		}
		else
		{
			result[i] = (10 + (num1[i] - '0') - carry) % 10 + '0';
		}
	}
	for (i = num1L - 1; result[i] == '0'; i--);
	i++;
	result[i] = '\0';
	reverseOrder(num1, num1L - 1);
	reverseOrder(num2, num2L - 1);
	reverseOrder(result, i - 1);
	return result;
}
char *multiply(char num1[], char num2[])//imitate the process of human in calculating two large number
{
		int num1L = 0;
		int num2L = 0;
		int multiCarry = 0;
		int addCarry = 0;
		int multiTemp = 0;
		int addTemp = 0;
		char *result;
		result = malloc(sizeof(char) * 20000);
		memset(result, '0', 20000);
		num1L = strlen(num1);
		num2L = strlen(num2);
		result[num1L + num2L] = '\0';
		reverseOrder(num1, num1L - 1);
		reverseOrder(num2, num2L - 1);

		for (int i = 0; i < num2L; i++)//digital in num2
		{
			multiCarry = 0;
			addCarry = 0;
			for (int j = 0; j < num1L; j++)//digital in num1
			{
				multiTemp = (num1[j] - '0') * (num2[i] - '0') + multiCarry;//multiply first
				multiCarry = multiTemp / 10;//calculate the multiply carry
				multiTemp %= 10;//  11
											//* 12
											//-------
											//   22           2 is the multiply temp
											// 11
											//-------
											// 132           3 is the add temp

				addTemp = (result[i + j] - '0') + multiTemp + addCarry;
				addCarry = addTemp / 10;
				result[i + j] = addTemp % 10 + '0';
				multiTemp = 0;
				addTemp = 0;
			}
			result[i + num1L] += multiCarry + addCarry;
		}
		if (result[num1L + num2L - 1] == '0')
		{
			reverseOrder(result, num1L + num2L - 2);
			result[num1L + num2L - 1] = 0;
		}
		else
			reverseOrder(result, num1L + num2L - 1);
		reverseOrder(num1, num1L - 1);
		reverseOrder(num2, num2L - 1);
		return result;
}
char *divide(char num1[], char num2[])
{
	char *result = NULL;
	char *currentNum = NULL;
	char *temp = NULL;
	result = malloc(sizeof(char) * 10000);
	memset(result, '0', 10000);
	result[1] = 0;
	currentNum = malloc(sizeof(char) * 10000);
	memset(currentNum, '0', 10000);
	currentNum[1] = 0;
	do
	{
		plus_one(result);
		if (strlen(currentNum) >= strlen(num2))
		{
			temp = currentNum;
			currentNum = add(currentNum, num2);
			free(temp);
		}
		else
		{
			temp = currentNum;
			currentNum = add(num2, currentNum);
			free(temp);
		}
	} while (isSame(currentNum, num1));
	return result;
}
char *divideImprove(char num1[], char num2[], int num[])
{
	int num1Len = 0;
	int ask[10][MAX + 10] = { 0 };//[length[1]+100];
	int length[10] = { 0 };
	char *ans = NULL;
	int flag = 0;
	ans = malloc(sizeof(char) * MAX);
	memset(ans, '0', MAX);
	//count the highest digital and record in num1Len length[1] 
	for (; '0' <= num1[num1Len] && num1[num1Len] <= '9'; ++num1Len);
	for (; '0' <= num2[length[1]] && num1[length[1]] <= '9'; ++length[1]);

	//translate to int array
	int i, j;
	for (i = 0; i<num1Len; ++i)
		num[i] = num1[num1Len - i - 1] - '0';
	for (i = 0; i<length[1]; ++i)
		ask[1][i] = num2[length[1] - i - 1] - '0';

	//for example num2 = 20
	//ask[1]  0 2 0000
	//ask[2]  0 4 0000
	//ask[3]  0 6 0000
	//precalculate the result of num2 * i, and store them into the array
	for (i = 2; i <= 9; ++i) {
		for (j = 0; j<length[i - 1]; ++j) {
			ask[i][j] += ask[1][j] + ask[i - 1][j];
			if (ask[i][j] >= 10)
				ask[i][j] %= 10, ask[i][j + 1] = 1;
		}
		if (ask[i][j])
			length[i] = length[i - 1] + 1;
		else
			length[i] = length[i - 1];
	}

	//ans is the answer, and flag count the ans's bit
	
	for (i = num1Len - length[1]; i >= 0; --i) 
	{
		int l = 0, r = 10, mid = 5;
		do 
		{
			if (compare(num + i, ask[mid], num1Len - i, length[mid]))
			{
				ans[i] = mid;
				l = mid;
			}
			else
				r = mid;
			mid = l + r >> 1;
		} while (l != mid);
		if (ans[i]) //minus
		{
			if (!flag)
				flag = i;
			int t = ans[i];
			for (j = 0; j < length[t]; j++)
				if (num[j + i]<ask[t][j])
					num[j + i + 1]--, num[i + j] += 10 - ask[t][j];
				else
					num[i + j] -= ask[t][j];
		}
	}
	for (i = flag; i >= 0; i--)
	{
		if(ans[i] != '0')
			ans[i] += '0';
	}
	i = flag;
	for (; ans[i] == '0'; i--);
	ans[i + 1] = 0;
	for (j = length[1]; num[j] == 0; j--);
	num[j + 1] = -1;
	reverseOrderInt(num, j);
	reverseOrder(ans, i);
	return ans;
}
void printOut(char *result)
{
	for (; *result == '\0'; result++);
	if (*(result - 1) == '0' && *result == '\0')result--;
	printf("The result is:\n");
	if (*result == '0')
	{
		printf("0");
		printf("\n");
		return;
	}
	else
		for (; *result != '\0'; result++)
		{
			printf("%c", *result);
		}
	printf("\n");
	return;
}
void reverseOrderInt(int *str, int end)
{
	int temp;
	int current = 0;
	while (current < end)
	{
		temp = str[current];
		str[current] = str[end];
		str[end] = temp;
		current++;
		end--;
	}
	return;
}
void reverseOrder(char *str, int end)
{
	char temp;
	int current = 0;
	while (current < end)
	{
		temp = str[current];
		str[current] = str[end];
		str[end] = temp;
		current++;
		end--;
	}
	return;
}
void plus_one(char a[]) 
{
	int carry = 1;
	int alen = strlen(a);
	int i;
	char temp;
	reverseOrder(a, alen - 1);
	for (i = 0; i<alen; i++) 
	{
		temp = a[i] + carry;
		if (temp >= 10 + '0') 
		{
			temp = '0';
			carry = 1;
		}
		else
			carry = 0;
		a[i] = temp;
	}
	if (carry == 1)
		a[i++] = '1';
	a[i] = '\0';
	if (carry == 1)
		reverseOrder(a, alen);
	else
		reverseOrder(a, alen - 1);
}
void printRemainder(int *remainder)
{
	printf("The reminder is:\n");
	for (; *remainder != -1; remainder++)
	{
		printf("%d", *remainder);
	}
	printf("\n");
	return;
}