#include<stdio.h>
#include<stdlib.h>


int main()
{
	printf_s("Program jest emulatorem maszyny Turinga\n");
	printf_s("Postac maszyny Turinga: M=( {q0, q1, q2, q3, q4, q5, q6}, {0,1}, {0,1,B}, delta, q0, B, 0 ) dla:\n\n");
	printf_s("|delta|     0    |     1    |     B    |\n");
	printf_s("|  q0 | (q1,B,P) | (q5,B,P) |     -    |\n");
	printf_s("|  q1 | (q1,0,P) | (q2,1,P) |     -    |\n");
	printf_s("|  q2 | (q3,1,L) | (q2,1,P) | (q4,B,L) |\n");
	printf_s("|  q3 | (q3,0,L) | (q3,1,L) | (q0,B,P) |\n");
	printf_s("|  q4 | (q4,0,L) | (q4,B,L) | (q6,0,P) |\n");
	printf_s("|  q5 | (q5,B,P) | (q5,B,P) | (q6,B,P) |\n");
	printf_s("|  q6 |    -     |    -     |     -    |\n\n");
	printf_s("Program oblicza roznice wlasciwa liczb: \n");
	printf_s("1) dla m>=n: m-n\n");
	printf_s("2) dla m<n: 0\n\n");
	printf_s("Podaj liczby:\n");
	int m, n;
	printf_s("m = ");
	scanf_s("%d", &m);
	printf_s("n = ");
	scanf_s("%d", &n);
	char* v[1000];
	for (int i = 0; i <= m+n; i++)
	{
		if (i == m)
			v[i] = '1';
		else
			v[i] = '0';
	}
	v[m + n + 1] = 'B';
	printf_s("\nTasma wejsciowa zakodowana unarnie : ");
	for (int i = 0; i <= m + n; i++)
		printf_s("%c", v[i]);
	printf("\n");
	printf_s("\nCiag opisow chwilowych MT: \n");
	printf_s("[q0]");
	for (int i=0; i <= m+n; i++)
		printf_s("%c", v[i]);
	printf_s(" |- ");
	int x = 0;
	int i = 0;
	int s;
	s = m + n;
	
	while (x <= 6) {
		switch (x)
		{
		case 0:
			if (v[i] == '0') {
				v[i] = 'B';
				for (int w = 0; w <= i; w++)
					printf_s("%c", v[w]);
				i++;
				printf_s("[q1]");
				for (int z=i; z <= s; z++)
					printf_s("%c", v[z]);
				printf_s(" |- ");
				x = 1;
				break;
			}
			else if (v[i] == '1') {
				v[i] = 'B';
				for (int w = 0; w <= i; w++)
					printf_s("%c", v[w]);
				printf_s("[q5]");
				i++;
				for (int z=i; z <= s; z++)
					printf_s("%c", v[z]);
				printf_s(" |- ");
				x = 5;
				break;
			}
		case 1:
			if (v[i] == '0') {
				v[i] = '0';
				for (int w = 0; w <= i; w++)
					printf_s("%c", v[w]);
				printf_s("[q1]");
				i++;
				for (int z=i; z <= s; z++)
					printf_s("%c", v[z]);
				printf_s(" |- ");
				x = 1;
				break;
			}
			else if (v[i] == '1') {
				v[i] = '1';
				for (int w = 0; w <= i; w++)
					printf_s("%c", v[w]);
				printf_s("[q2]");
				i++;
				for (int z=i; z <= s; z++)
					printf("%c", v[z]);
				printf_s(" |- ");
				x = 2;
				break;
			}
		case 2:
			if (v[i] == '0') {
				v[i] = '1';
				i-=2;
				for (int w = 0; w <= i; w++)
					printf_s("%c", v[w]);
				printf_s("[q3]");
				i++;
				for (int z=i; z <= s; z++)
					printf_s("%c", v[z]);
				printf_s(" |- ");
				x = 3;
				break;
			}
			else if (v[i] == '1') {
				v[i] = '1';
				for (int w = 0; w <= i; w++)
					printf_s("%c", v[w]);
				printf_s("[q2]");
				i++;
				for (int z=i; z <= s; z++)
					printf_s("%c", v[z]);
				printf_s(" |- ");
				x = 2;
				break;
			}
			else {
				v[i] = 'B';
				i-=2;
				for (int w = 0; w <= i; w++)
					printf_s("%c", v[w]);
				printf_s("[q4]");
				i++;
				int z = s;
				for (int y = s; y >= i; y--) {
					if (v[y] != 'B' && v[y + 1] == 'B') {
						for (int w = i; w <= y; w++)
							printf_s("%c", v[w]);
					}
				}
				s = m + n;
				printf_s(" |- ");
				x = 4;
				break;
			}
		case 3:
			if (v[i] == '0') {
				v[i] = '0';
				i-=2;
				for (int w = 0; w <= i; w++)
					printf_s("%c", v[w]);
				printf_s("[q3]");
				i++;
				for (int z=i; z <= s; z++)
					printf_s("%c", v[z]);
				printf_s(" |- ");
				x = 3;
				break;
			}
			else if (v[i] == '1') {
				v[i] = '1';
				i-=2;
				for (int w = 0; w <= i; w++)
					printf_s("%c", v[w]);
				printf_s("[q3]");
				i++;
				for (int z=i; z <= s; z++)
					printf_s("%c", v[z]);
				printf_s(" |- ");
				x = 3;
				break;
			}
			else {
				v[i] = 'B';
				for (int w = 0; w <= i; w++)
					printf_s("%c", v[w]);
				printf_s("[q0]");
				i++;
				for (int z=i; z <= s; z++)
					printf_s("%c", v[z]);
				printf_s(" |- ");
				x = 0;
				break;
			}
		case 4:
			if (v[i] == '0') {
				v[i] = '0';
				i-=2;
				for (int w = 0; w <= i; w++)
					printf_s("%c", v[w]);
				printf_s("[q4]");
				i++;
				int z = s;
				for (int y = s; y >= i; y--) {
					if (v[y] != 'B' && v[y + 1] == 'B') {
						for (int w = i; w <= y; w++)
							printf_s("%c", v[w]);
					}
				}
				s = m + n;				
				printf_s(" |- ");
				x = 4;
				break;
			}
			else if (v[i] == '1') {
				v[i] = 'B';
				i-=2;
				for (int w = 0; w <= i; w++)
					printf_s("%c", v[w]);
				printf_s("[q4]");
				i++;
				int z = s;
				for (int y = s; y >= i; y--) {
					if (v[y] != 'B' && v[y + 1] == 'B') {
						for (int w = i; w <= y; w++)
							printf_s("%c", v[w]);
					}					
				}
				s = m + n;			
				printf_s(" |- ");
				x = 4;
				break;
			}
			else {
				v[i] = '0';
				for (int w = 0; w <= i; w++)
					printf_s("%c", v[w]);
				printf_s("[q6]");
				i++;
				for (int z = i; z <= s; z++) {
					if(v[z]!='B')
					printf_s("%c", v[z]);

				}
				x = 6;
				break;
			}
		case 5:
			if (v[i] == '0') {
				v[i] = 'B';
				for (int w = 0; w <= i; w++)
					printf_s("%c", v[w]);
				printf_s("[q5]");
				i++;
				for (int z=i; z <= s; z++)
					printf_s("%c", v[z]);
				printf_s(" |- ");
				x = 5;
				break;
			}
			else if (v[i] == '1') {
				v[i] = 'B';
				for (int w = 0; w <= i; w++)
					printf_s("%c", v[w]);
				printf_s("[q5]");
				i++;
				for (int z=i; z <= s; z++)
					printf_s("%c", v[z]);
				printf_s(" |- ");
				x = 5;
				break;
			}
			else {
				v[i] = 'B';
				for (int w = 0; w <= i; w++)
					printf_s("%c", v[w]);
				printf_s("[q6]");
				i++;
				for (int z = i; z <= s; z++) {
					if (v[z] != 'B' && v[z + 1]!='B')
						printf_s("%c", v[z]);
				}
				x = 6;
				break;
			}
		case 6:
			x = 7;
		}
	}
	int wynik = 0;
	for (int i = 0; i <= s; i++) {
		if (v[i] == '0')
			wynik++;
	}
	printf_s("\n\nInterpretacja wyniku:\tm - n = %d\n", wynik);
		
	return 0;
	}
