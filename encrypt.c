#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	if (argc == 2) {
		FILE *fptr1 = NULL, *fptr2 = NULL;
		char c;
		fptr1 = fopen(argv[1], "r");

		if (fptr1 == NULL) {
                	printf("%s: cannot access '%s': No such file or directory", argv[0], argv[1]);
                        return 1;
                }
		
		fptr2 = fopen("encrypted.txt", "w+");
		
    printf("[1] - ASCII code\n");
		printf("[2] - Caesar\n");
		printf("[3] - Vigenere\n");
    printf("Choice: ");
		
		int choice;
		scanf("%d", &choice);

    if (choice == 1) {
			while ((c = fgetc(fptr1)) != EOF) {		
        if (isalpha(c))
          fprintf(fptr2, "%d ", c);
        else
          fprintf(fptr2, "%c", c);
      }
    }
		if (choice == 2) {
			int key;
			printf("%s", "Key: ");
			scanf("%d", &key);
			
			while ((c = fgetc(fptr1)) != EOF) {		
				if (isalpha(c))
					fprintf(fptr2, "%c", (tolower(c) - 'a' + key) % 26 + 'a');
				else
					fprintf(fptr2, "%c", c);
			}
		}
    if (choice == 3) {
      
    }
		if (choice != 1 && choice != 2 && choice != 3) {
			printf("Wrong cipher\n");
			return 1;
		}

		fclose(fptr1);
		fclose(fptr2);

		printf("Done!\n");

	} else {
		printf("Error.");
		return 1;
	}
	return 0;
}
