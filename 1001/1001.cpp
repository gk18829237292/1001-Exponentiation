#include<stdio.h>
#include<math.h>
int main()
{
	char r[7];
	int n;
	while (scanf("%s %d", &r, &n) != EOF)
	{
		int i, j, cntOfDecimal = 0;
		int left, right;

		for (left = 1; left < 6 && r[left] != '.'; left++); //找小数点的位置
		for (right = 5; right >= 0 && r[right] == '0'; right--);
		cntOfDecimal = right - left;
		double R;

		sscanf(r, "%lf", &R);

		if (cntOfDecimal > 0)
			R *= pow(10, cntOfDecimal);
		int result[41] = { 0 };

		result[40] = 1;
		for (j = 0; j < n; j++)
		{
			for (i = 40; i >= 0 ; i--)
			{
				result[i] *= R;
			}
			for (i = 40; i >= 0 ; i--)
			{
				result[i - 1] += (result[i] / 10000);
				result[i] %= 10000;
			}
		}
		if (cntOfDecimal > 0)
		{
			cntOfDecimal *= n;
			int tempLeft = 40 - cntOfDecimal / 4;
			int j = cntOfDecimal % 4;

			for (i = 0; i < tempLeft; i++)
			{
				if (result[i] != 0)
				{
					printf("%d", result[i++]);
					break;
				}
			}
			
			for (; i < tempLeft; i++)
			{
				printf("%04d", result[i]);
			}

			char str[6];
			sprintf(str, "%04d", result[tempLeft]);
			str[5] = '\0';
			for (i = 4; i >= 0 && j != 0; i--, j--)
			{
				str[i] = str[i - 1];
			}
			str[i] = '.';
			for (i = 0; i < 6; i++)
			{
				if (str[i] != '0')
				{
					printf("%s", &(str[i]));
					break;
				}
			}
			//	printf("%s", str);

			for (i = tempLeft + 1; i < 41; i++)
			{
				printf("%04d", result[i]);
			}

		}
		else
		{
			
			for (i = 0; i < 41; i++)
			{
				if (result[i] != 0)
				{
					printf("%d", result[i++]);
					break;
				}
			}
			for (; i < 41; i++)
			{
				printf("%04d", result[i]);
			}
		}
		printf("\n");
	}
	return 1;
}