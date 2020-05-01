#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char lookahead = '\0';
int i = 0;
char *str = NULL;
 
void match(char current) {
	printf("\n---- %d ---- %c ----", i, str[i]);
	if (lookahead == current) {
		i += 1;
		lookahead = str[i];
	}
	else { puts("syntax error"); return; }
}

void stmt() {
	switch(lookahead) {
		case 'a':
			match('a');
			break;
		case '+':
			match('+');
			stmt();
			stmt();
			break;
		default:
			printf("\n----incorrect syntax----");
			return;
	}
}

int main(void) {
	size_t len = 0;
	ssize_t read;
	
	do {
		read = getline(&str, &len, stdin);		
		lookahead = str[0];
		printf("Examining %s", str);
		sleep(1);
		
		stmt();
		puts("\n________________________");
		i = 0;
	} while(read != -1);

	free(str);

	return 0;
}
