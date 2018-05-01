#include <stdio.h>
#include "partition_types.h"
#include "porting_partition_access_interface.h"
#include "hi_flash.h"
#include "hi_type.h"
#include <android/log.h>


/*****************	����flash���ͼ��������ƴ�flash*********************/
/* [in]FlashType:��������												*/
/* [in]pPartitionName:��������									        */
/* [in]addr:������ƫ��													*/
/* [in]length:�򿪳���													*/
/* [out] �ɹ���flash handle��ʧ�ܣ�INVALID_FLASH_HANDLE                 */
/************************************************************************/
FLASH_HANDLE Porting_Flash_Open(FLASH_TYPE_E flashType, UINT_8 *pPartitionName,
		UINT_64 addr, UINT_64 length)
{
	FLASH_HANDLE ret = INVALID_FLASH_HANDLE;
	ret = HI_Flash_Open( flashType, pPartitionName, addr,length);
	if(ret == INVALID_FD)
	{
		return -1;
	}

	return ret;
}

/*****************		���ݷ������ƴ�flash		*********************/
/* [in]pPartitionName:��������									        */
/* [out] �ɹ���flash handle��ʧ�ܣ�INVALID_FLASH_HANDLE                 */
/************************************************************************/
FLASH_HANDLE	Porting_Flash_OpenByName(UINT_8 *pPartitionName)
{
	FLASH_HANDLE ret = INVALID_FLASH_HANDLE;
	
	if(!pPartitionName)
	{
		printf("Porting_Flash_OpenByName param error\n");
		return -1;
	}
	ret = HI_Flash_OpenByName((HI_CHAR*)pPartitionName);
	if(ret == INVALID_FD)
	{
		return -1;
	}
	return ret;
}

/*****************���ݷ������ͼ�ƫ�Ƶ�ַ��flash	*********************/
/* [in]FlashType:��������												*/
/* [in]addr:������ƫ��													*/
/* [in]length:�򿪳���													*/
/* [out] �ɹ���flash handle��ʧ�ܣ�INVALID_FLASH_HANDLE                 */
/************************************************************************/
FLASH_HANDLE Porting_Flash_OpenByTypeAndAddr(FLASH_TYPE_E FlashType,
		UINT_64 addr, UINT_64 length)
{
	FLASH_HANDLE ret = INVALID_FLASH_HANDLE;
	ret = HI_Flash_OpenByTypeAndAddr( FlashType, addr, length);
	if(ret == INVALID_FD)
	{
		return -1;
	}

	return ret;
}

/*****************		����ָ������				*********************/
/* [in]handle:flash handle												*/
/* [in]addr:������ƫ��													*/
/* [in]length:��������													*/
/* [out] �ɹ���OPERATION_SUCCESS��ʧ�ܣ�OPERATION_FAILURE               */
/************************************************************************/
INT_32 Porting_Flash_Erase(FLASH_HANDLE handle, UINT_64 addr, UINT_64 length)
{

	int ret;
	if((addr < 0) || (length < 0))
	{
		printf("Porting_Flash_Erase param error:handle=%0x,addr=%0x,length=%0x\n",handle,addr,length);
		return -1;
	}
	ret = HI_Flash_Erase(handle, addr, length);
	if(ret == HI_FAILURE)
	{
		return -1;
	}

	return ret;
}

/*****************		��ȡ��������				*********************/
/* [in]handle:flash handle												*/
/* [in]addr:������ƫ��													*/
/* [out]pBuf:���ݻ���													*/
/* [in]length:��ȡ����													*/
/* [in]rwFlags����д��ʽ(�����泣�����壺FLASH_RW_FLAG_XXX)				*/
/* [out] �ɹ���ʵ�����ݳ��ȣ�ʧ�ܣ�-1               */
/************************************************************************/
INT_32 Porting_Flash_Read(FLASH_HANDLE handle, UINT_64 addr, UINT_8 *pBuf,
		UINT_64 length, UINT_32 rwFlags)
{
	int ret;
	
	printf("Porting_Flash_Read...in length:%d\n",length);
	if((addr < 0) || (pBuf == NULL) || (length < 0))
	{
		printf("Porting_Flash_Read param error:\n");
		return -1;
	}

	ret = HI_Flash_Read(handle, addr, pBuf, length, rwFlags);

	if(ret == HI_FAILURE)
	{
		return -1;
	}

	printf("Porting_Flash_Read...out pBuf:%s length:%d ret:%d\n",pBuf,length,ret);
	return ret;
	
}


/*****************		��д����					*********************/
/* [in]handle:flash handle												*/
/* [in]addr:������ƫ��													*/
/* [in]pBuf:���ݻ���													*/
/* [in]length:д����													*/
/* [in]rwFlags����д��ʽ(�����泣�����壺FLASH_RW_FLAG_XXX)				*/
/* [out] �ɹ���OPERATION_SUCCESS��ʧ�ܣ�OPERATION_FAILURE               */
/************************************************************************/
INT_32 Porting_Flash_Write(FLASH_HANDLE handle, UINT_64 addr, UINT_8 *pBuf,
		UINT_64 length, UINT_32 rwFlags)
{
	int ret;
	printf("Porting_Flash_Write...in pBuf:%s length:%d\n",pBuf,length);
	ret = HI_Flash_Write(handle, addr, pBuf, length, rwFlags);
	printf("Porting_Flash_Write...out ret:%d\n",ret);
	if(ret == HI_FAILURE)
	{
		return -1;
	}else{
		return OPERATION_SUCCESS;
	}
	return ret;
}

/*****************		��ȡ������Ϣ				*********************/
/* [in]handle:flash handle												*/
/* [out]info:������Ϣ													*/
/* [out] �ɹ���OPERATION_SUCCESS��ʧ�ܣ�OPERATION_FAILURE               */
/************************************************************************/
INT_32 Porting_Flash_GetInfo(FLASH_HANDLE handle, FlashInfo* info)
{
	int ret;
	HI_Flash_InterInfo_S  getInfo[1];
	if(!info)
	{
		printf("Porting_Flash_GetInfo param error:\n");
		return -1;
	}

	ret = HI_Flash_GetInfo(handle, getInfo);
	if(ret == HI_FAILURE)
	{
		return -1;
	}else{
		ret = OPERATION_SUCCESS;
	}

	info->TotalSize = getInfo->TotalSize;
	info->PartSize  = getInfo->PartSize;
	info->BlockSize = getInfo->BlockSize;
	info->PageSize  = getInfo->PageSize;
	info->OobSize   = getInfo->OobSize;
	info->fd        = getInfo->fd;
	info->OpenAddr  = getInfo->OpenAddr;
	info->OpenLeng  = getInfo->OpenLeng;
	info->FlashType = getInfo->FlashType;

	return ret;
}

/*****************		�رշ���					*********************/
/* [in]handle:flash handle												*/
/* [out] �ɹ���OPERATION_SUCCESS��ʧ�ܣ�OPERATION_FAILURE               */
/************************************************************************/
INT_32 Porting_Flash_Close(FLASH_HANDLE handle)
{
	int ret= 0;
	ret = HI_Flash_Close(handle);
	if(ret == HI_FAILURE)
	{
		return -1;
	}
	
	return ret ;
}



/*
int main()
{
		char* name ="misc";
		char miscbuf[1024] = { 0 };

		int handle;
		strcpy(miscbuf, "boot-recovery");
		printf("miscbuf %s\n",miscbuf);
		handle = Porting_Flash_OpenByName(name);
		if(handle == -1)
		{
			printf("handle == -1\n");
			return -1;
		}
		int ret	= Porting_Flash_Write(handle,0,	miscbuf,sizeof(miscbuf),0);
		if(ret == -1)
		{
				printf("write failed\n");
		}
		return 0;
}
*/