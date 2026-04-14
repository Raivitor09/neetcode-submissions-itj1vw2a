class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0; // índice para escrever no array

        int i = 0; // índice para ler o array
        while (i < n) {
            char current = chars[i];
            int count = 0;

            // conta quantos caracteres consecutivos iguais
            while (i < n && chars[i] == current) {
                i++;
                count++;
            }

            // escreve o caractere atual
            chars[write] = current;
            write++;

            // se tiver mais de 1 repetição, escreve cada dígito do número
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[write] = c;
                    write++;
                }
            }
        }

        return write;
    }
};