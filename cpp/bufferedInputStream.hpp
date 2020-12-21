#ifndef BUFFERED_INPUT_STREAM_HPP
#define BUFFERED_INPUT_STREAM_HPP

#include <stdio.h>

#define BUFFER_LEN 256

// 该类的目的是未来方便读写文件。
class BufferedInputStream {
private:
    // FILE在头文件 stdio.h 中定义。
    // 流式文件操作，实现了文件的读写等操作。
    FILE* fp;
    char szBuffer[BUFFER_LEN];
    unsigned short index;

public:
    // 读取文件，构造函数
    BufferedInputStream(char const* filename) {
        // fopen 表示打开流，
        // 第一个参数是文件名，
        // 第二个参数是读取类型，rb+ 读写打开一个二进制文件，只允许读写数据。
        fp = fopen(filename, "rb");
        // 从流中读指定个数的字符
        // 保存读取数据至 szBuffer中。
        // BUFFER_LEN * sizeof(char) 表示每一块的字节数。
        // 1 表示读取的块数，fp 表示输入。
        fread(szBuffer, BUFFER_LEN * sizeof(char), 1, fp);
        index = 0;
    }

    // 以 ~ 开头的函数表示析构函数
    // 析构函数和成员函数是一一对应的，实现了成员函数的扫尾善后工作。
    // 也就是成员函数只负责干活，活干完后则有析构函数负责收尾（垃圾回收，占用内存删除等操作）。
    ~BufferedInputStream() {
        // 关闭流
        close();
    }

    char read() {
        if (index < BUFFER_LEN)
            return szBuffer[index++];
        else {
            index = 0;
            fread(szBuffer, BUFFER_LEN * sizeof(char));
        }
    }

    int read_int() {
        int b1 = read() & 0xff;
        int b2 = read() & 0xff;
        int b3 = read() & 0xff;
        int b4 = read() & 0xff;

        return b4 << 24 | b3 << 16 | b2 << 8 | b1;
    }

    double read_double() {
        char t[8];
        for (int i = 0; i < 8; i++) {
            t[i] = read();
        }
        return *(double *)t;
    }
    
    void unread() {
        index--;
    }

    void close() {
        if (fp != NULL) {
            fclose(fp);
            fp = NULL;
        }
    }
};

#endif