/*---------------------------------------
**  copyright (c) 2013-3-2 DeltaYang
**  E-mail: DeltaYang89@gmail.com
**  getch.c:模拟实现getch()
**--------------------------------------*/
#ifndef MYGETCH_H
#define MYGETCH_H
#include <stdio.h>
#include <termios.h> //操作终端
#include <unistd.h>
#include <assert.h>
#include <string.h>

char my_getch() 
{
        int c=0;
        struct termios org_opts, new_opts;
        int res=0;
        //保留终端原来设置
        res=tcgetattr(STDIN_FILENO, &org_opts);
        assert(res==0);
        //从新设置终端参数
        memcpy(&new_opts, &org_opts, sizeof(new_opts));
        new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
        tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
        c=getchar();
        //恢复中断设置
        res=tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);assert(res==0);
        return c;
}

#endif
