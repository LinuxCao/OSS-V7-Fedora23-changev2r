/*
changeVirtual2Real  返回值：
                           -1    //操作失败
                            0    //操作成功
                            1  //底层没有开启虚实双系统
                            2   //写数据失败
                            3   //没有找到实系统
*/
#include "changeV2R.h"

#define RET_OPER_FAIL                       -1    //操作成功
#define RET_OPER_OK                          0    //操作成功
#define RET_NO_SET_VDI                     1  //底层没有开启虚实双系统
#define RET_WRITE_DISK_ERROR         2   //写数据失败
#define RET_NO_FIND                           3   //没有找到实系统

int main(int argc, char *argv[])
{
	int ChangeVirtual2Real_ret=0;
	if (strcmp(argv[1], "true") == 0)
	{
		printf("ChangeVirtual2Real true\n");
		ChangeVirtual2Real_ret=ChangeVirtual2Real(1);
	}
	if (strcmp(argv[1], "false") == 0)
	{
		printf("ChangeVirtual2Real false\n");
		ChangeVirtual2Real_ret=ChangeVirtual2Real(0);
	}
	
	//printf("ChangeVirtual2Real_ret = %d\n",ChangeVirtual2Real_ret);
    switch (ChangeVirtual2Real_ret)
    {
		case RET_OPER_FAIL:
			printf("ChangeVirtual2Real_ret = %d RET_OPER_FAIL\n",ChangeVirtual2Real_ret);
			return 0;
		break;
		case RET_OPER_OK:
			printf("ChangeVirtual2Real_ret = %d RET_OPER_OK\n",ChangeVirtual2Real_ret);
			return -1;
		break;
		case RET_NO_SET_VDI:
			printf("ChangeVirtual2Real_ret = %d RET_NO_SET_VDI\n",ChangeVirtual2Real_ret);
			return -1;
		break;
		case RET_WRITE_DISK_ERROR:
			printf("ChangeVirtual2Real_ret = %d RET_WRITE_DISK_ERROR\n",ChangeVirtual2Real_ret);
			return -1;
		break;
		case RET_NO_FIND:
			printf("ChangeVirtual2Real_ret = %d RET_NO_FIND\n",ChangeVirtual2Real_ret);
			return -1;
		break;
		default:
			return -1;
		break;
			
    }
	
	return 0;
}


