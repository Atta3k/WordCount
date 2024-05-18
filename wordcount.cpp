#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    char *option = argv[1]; // 获取参数
    char *filename = argv[2]; // 获取文件名

    FILE *file = fopen(filename, "r"); // 打开文件
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int count = 0; // 初始化计数器
    int c;
    if (strcmp(option, "-c") == 0) { // 如果是统计字符数
        while ((c = fgetc(file)) != EOF) { // 逐个读取字符，直到文件末尾
            count++; // 每读取一个字符，计数器加一
        }
        printf("字符数：%d\n", count); // 输出字符数
    } else if (strcmp(option, "-w") == 0) { // 如果是统计单词数
        int inWord = 0;
        while ((c = fgetc(file)) != EOF) { // 逐个读取字符，直到文件末尾
            if (c == ' ' || c == '\n' || c == '\t') {
                inWord = 0; // 遇到空格、换行或制表符，表示单词结束
            } else if (!inWord) { // 如果不在一个单词中
                inWord = 1; // 标记处于单词中
                count++; // 单词数加一
            }
        }
        printf("单词数：%d\n", count); // 输出单词数
    } else {
        printf("Invalid option. Please use -c or -w.\n"); // 如果参数不合法，输出错误信息
        return 1;
    }

    fclose(file); // 关闭文件
    return 0;
}

