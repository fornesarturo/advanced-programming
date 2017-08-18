int last_word_len(char * string, int n) {
    int count = 0;
    for(int i = n - 1; i > 0; i--) {
        if(string[i] == ' ') {
            return count;
        }
        else {
            count++;
        }
    }
    return 0;
}
