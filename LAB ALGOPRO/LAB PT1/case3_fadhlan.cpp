#include <stdio.h>

int main() {
	
	char word[100];
	
	scanf("%[^\n]s", word);
	
	printf("#include <stdio.h>\n");
	printf("int main()\n");
	printf("{\n");
	printf("    printf(\"%%s\\n\",\"%s\");\n", word);
	printf("    return 0;\n");
	printf("}\n");
	
	return 0;
}
