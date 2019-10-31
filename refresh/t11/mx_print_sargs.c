void mx_printstr(const char *s);
void mx_printchar(char s);
int mx_strcmp(const char *s1, const char *s2);

int main(int argc,char *argv[]) {

    for (int i = 1; i < argc; i++) {
        for (int k = 1; k < argc; k++) {
            if (mx_strcmp(argv[i], argv[k]) < 1) {
                char *s = argv[i];
                argv[i] = argv[k];
                argv[k] = s;
            }
        }
    }
	for (int i = 1; i < argc; i++) {
		mx_printstr(argv[i]);
		mx_printchar('\n');
	}
	return 0;
}
