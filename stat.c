#include <stdio.h>
#define MAX_FILE_NAME 100
#define NLOWER 26

int main(int argc, char *argv[])
{

	if (argc == 2) {
		FILE *fp;
		char filename[MAX_FILE_NAME];
		char c;
  		int digits, spaces, tabs, nl, all_chars, charfreq[NLOWER] = { 0 }, charfreqUpper[NLOWER] = { 0 }, charfreq_all_letters = { 0 }, spec;
		long double letters = 0, charfreq_sum = 0;
		// alphabet a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, x, y, z;

		fp = fopen(argv[1], "r");
  
    		if (fp == NULL) {
        		printf("%s: cannot access '%s': No such file or directory", argv[0], argv[1]);
			return 1;
    		}
  
    		for (c = getc(fp); c != EOF; c = getc(fp)) {
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
				letters++;			
			}
			
			else if (c >= '0' && c <= '9') {
				digits++;
			}

			else if (c == ' ')
				spaces++;

			else if (c == '\t')
				tabs++;
			
			else if (c == '\n')
				nl++;

			else
				spec++;

			if ('a' <= c && c <= 'z')
				charfreq[c - 'a']++;

			if ('A' <= c && c <= 'Z')
				charfreqUpper[c - 'A']++;

			
			all_chars++;
		}


    		fclose(fp);

		printf("Size of %s: %d chars.\n\n", argv[1], all_chars);
		printf("Letters: %0.Lf\n", letters);
		printf("Digits: %d\n", digits);
		printf("Lines: %d\n", nl);
		printf("Spaces: %d\n", spaces);
		printf("Tabs: %d\n\n", tabs);
		printf("Special: %d\n\n", spec);
		
		printf("Lowercase chars: \n");

		for (int i = 0; i < NLOWER; i++)
        		if (charfreq[i])
            			printf ("%c:%2d\n", 'a' + i, charfreq[i]);

		printf("\n");
		printf("Uppercase chars: \n");

		for (int i = 0; i < NLOWER; i++)
        		if (charfreqUpper[i])
            			printf ("%c:%2d\n", 'A' + i, charfreqUpper[i]);
	
		printf("\n");

		for (int i = 0; i < NLOWER; i++)
			if (charfreq[i]) {
				printf("%c:%2.10Lf%\n", 'a' + i, charfreq[i] / letters * 100);
			}
		
		printf("\n");

		for (int i = 0; i < NLOWER; i++)
			if (charfreqUpper[i]) {
				printf("%c:%2.10Lf%\n", 'A' + i, charfreqUpper[i] / letters * 100);
			}
		printf("\n");

		for (int i = 0; i < NLOWER; i++)
			if (charfreq[i], charfreqUpper[i]) {
				printf("%c-%c:%2.10Lf%\n", 'A' + i, 'a' + i, ((charfreq[i] + charfreqUpper[i]) / letters) * 100);
			}
		
		
		FILE *stats = fopen("stats.txt", "w+");
			

		for (int i = 0; i < NLOWER; i++)
			if (charfreq[i], charfreqUpper[i]) {
				fprintf(stats, "%c %.25Lf\n", 'a' + i, (charfreq[i] + charfreqUpper[i]) / letters);
			}
		fclose(stats);
		
	} else {
		printf("Error!\n");
		return 1;
	}

  
    return 0;
}

// TODO: частотный анализ, шифровка и расшифровка текста
