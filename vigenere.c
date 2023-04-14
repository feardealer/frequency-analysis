#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	if (argc == 2) {
		FILE *fptr1 = NULL, *fptr2 = NULL;
		fptr1 = fopen(argv[1], "r");

		if (fptr1 == NULL) {
			printf("%s: cannot access '%s': No such file or directory", argv[0], argv[1]);
			return 1;
		}

		fptr2 = fopen("encrypted.txt", "w+");
		printf("%s", "1 - Caesar\n2 - Vigenere\n");

		int ch;
		scanf("%d", &ch);
		
		if (ch == 1) {
			char c;
			int key;
			
			printf("%s", "Key: ");
			scanf("%d", &key);
			
			while ((c = fgetc(fptr1)) != EOF) {		
				if (isalpha(c))
					fprintf(fptr2, "%c", (toupper(c) - 'A' + key) % 26 + 'A');
				else
					fprintf(fptr2, "%c", c);
			}
		}
		if (ch == 2) {
			char c, *message = malloc(0), *keyword = malloc(0);
			int i = 0, key, typechar, keysize = 0, messagesize = 0;

			printf("Key: ");
			while((c = getchar()) != '\n'){	
				if(c >= 65 && c <= 90 || c >= 97 && c <= 122){
					keyword = realloc(keyword, (keysize + 1) * sizeof(char));
					keyword[keysize] = c;
					keysize++;
				}
					
			}

			while ((c = fgetc(fptr1)) != EOF) {
				message = realloc(message, (messagesize + 1) * sizeof(char));
				message[messagesize] = c;
				messagesize++;
			}

			for(int j = 0; j < messagesize; j++){
				c = message[j];

				if(isalpha(c)){
					typechar = (c < 95) ? 65 : 97;
					c -= typechar;
					key = (int) keyword[i];
					typechar = (key < 95) ? 65 : 97;
					key -= typechar;
					c = (c + key) % 26;
					fprintf(fptr2, "%c", c + 65);
					i = (i + 1) % keysize;
				}else fprintf(fptr2, "%c",c);
			}
		}
		if (ch != 1 && ch != 2) {
			printf("Wrong cipher\n");
			return 1;
		}

		fclose(fptr1);
		fclose(fptr2);

		printf("Done!\n");
	} else {
		printf("Error. Usage: ./encrypt <SOURCE TEXT FILE>");
		return 1;
	}
	return 0;
}
