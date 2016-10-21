/*
changeVirtual2Real  返回值：
                           -1    //操作失败
                            0    //操作成功
                            1  //底层没有开启虚实双系统
                            2   //写数据失败
                            3   //没有找到实系统
*/
#include "changeV2R.h"
int main(int argc, char *argv[])
{
	if (strcmp(argv[1], "true") == 0)
	{
		printf("ChangeVirtual2Real true\n");
		ChangeVirtual2Real(1);
	}
	if (strcmp(argv[1], "false") == 0)
	{
		printf("ChangeVirtual2Real false\n");
		ChangeVirtual2Real(0);
	}
	
	return 0;
}


