#include <stdio.h>
#include <stdlib.h>


/*
# 4.通话时长(Phone) 描述
某人总是花很多时间给父母打电话。有一次他记录了打电话的起止时间 t1 和
t2,请帮他算算此 次通话总共持续了多少秒。

### 输入
共计一行, 包含t1和t2,用一个空格分隔。 时间格式为:

HH:MM:SS

其中 HH、MM 和 SS 均为两位数字,比如 0:1:2 应统一写作 00:01:02。

请注意,这里省略了日期信息。

### 输出
共计一行,即通话时长。

输入样例1
00:00:03 00:00:06

输出样例1
3

输入样例2
01:02:03 04:05:06

输出样例2
10983

限制
* 0 ≤ HH < 24
* 0 ≤ {MM, SS} < 60
* 通话时长不超过 12 个小时(43,200 秒)

 */


int main(int argc, const char * argv[])
{
    int hour1, minute1, second1, hour2, minute2, second2;
    scanf("%d:%d:%d %d:%d:%d", &hour1, &minute1, &second1, &hour2, &minute2, &second2);

    int interval = (hour2 * 3600 + minute2 * 60 + second2) - (hour1 * 3600 + minute1 * 60 + second1);
    if (interval < 0) {
        interval += 24 * 3600;
    }

    printf("%d\n", interval);

    return 0;
}
