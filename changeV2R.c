#define _FILE_OFFSET_BITS 64
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "changeV2R.h"
#define OE_DEV		"/dev/os-easy"
#define OE_MAGIC	'k'
#define   OE_VDI_V2R		(((OE_MAGIC)<<8)|6)

#define RET_OPER_OK                          0    //操作成功
#define RET_NO_SET_VDI                     1  //底层没有开启虚实双系统
#define RET_WRITE_DISK_ERROR         2   //写数据失败
#define RET_NO_FIND                           3   //没有找到实系统

#ifndef BOOL
#define BOOL  int//4 BYTE
#endif  


int ChangeVirtual2Real(BOOL bvdi_io)
{
   int fd;
   struct _oe_io_vdi
   {
	BOOL bvdi_cmd;
	int  ret ;
    } oe_io_vdi;
    fd = open(OE_DEV, O_RDONLY);
    if (fd < 0)
    {
	     printf("open oe_dev failed!\n");
            return -1;
    }

    oe_io_vdi.bvdi_cmd = bvdi_io;
    oe_io_vdi.ret  = -1;

    if (-1 == ioctl(fd, OE_VDI_V2R, &oe_io_vdi))
    {
            close(fd);
	     printf("oe_dev OE_VDI_V2R failed!\n");
            return -1;
    }
    close(fd);
    printf("oe_io_vdi.ret = %d\n",oe_io_vdi.ret);
    switch (oe_io_vdi.ret)
    {
         case RET_OPER_OK:
		return 0;
		break;
	  case RET_NO_SET_VDI:
	  	return -1;
		break;
	  case RET_WRITE_DISK_ERROR:
	  	return -1;
		break;
	  case RET_NO_FIND:
	  	return -1;
		break;
	  default:
	  	return -1;
		break;
			
    }
    
    return -1;
}

int main(int argc, char *argv[])
{
     BOOL bvdi_io ;
     if (strcmp(argv[1], "true") == 0)
     {
           bvdi_io = 1;//虚系统切换到实系统
          printf("BOOL bvdi_io = 1\n");
      }
      else
      {
           bvdi_io = 0;//不切换
	    printf("BOOL bvdi_io = 0\n"); 
       }


       
       ChangeVirtual2Real(bvdi_io);
       return 0;
}

