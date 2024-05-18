#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    char *option = argv[1]; // ��ȡ����
    char *filename = argv[2]; // ��ȡ�ļ���

    FILE *file = fopen(filename, "r"); // ���ļ�
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int count = 0; // ��ʼ��������
    int c;
    if (strcmp(option, "-c") == 0) { // �����ͳ���ַ���
        while ((c = fgetc(file)) != EOF) { // �����ȡ�ַ���ֱ���ļ�ĩβ
            count++; // ÿ��ȡһ���ַ�����������һ
        }
        printf("�ַ�����%d\n", count); // ����ַ���
    } else if (strcmp(option, "-w") == 0) { // �����ͳ�Ƶ�����
        int inWord = 0;
        while ((c = fgetc(file)) != EOF) { // �����ȡ�ַ���ֱ���ļ�ĩβ
            if (c == ' ' || c == '\n' || c == '\t') {
                inWord = 0; // �����ո񡢻��л��Ʊ������ʾ���ʽ���
            } else if (!inWord) { // �������һ��������
                inWord = 1; // ��Ǵ��ڵ�����
                count++; // ��������һ
            }
        }
        printf("��������%d\n", count); // ���������
    } else {
        printf("Invalid option. Please use -c or -w.\n"); // ����������Ϸ������������Ϣ
        return 1;
    }

    fclose(file); // �ر��ļ�
    return 0;
}

