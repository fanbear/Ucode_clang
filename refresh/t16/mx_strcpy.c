char *mx_strcpy(char *dst, const char *src) {
	int i = 0;
	if (src) {
		while(src[i]) {
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		return dst;
	}
	return 0;
}
