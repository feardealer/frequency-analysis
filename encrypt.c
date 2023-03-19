#include <stdio.h>
#include <string.h>

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

		while ((c = fgetc(fptr1)) != EOF) {
			fprintf(fptr2, "%d ", c);
		}

		fclose(fptr1);
		fclose(fptr2);

		printf("Done!");

	} else {
		printf("Error.");
		return 1;
	}
	return 0;
}
