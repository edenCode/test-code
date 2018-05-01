#ifndef __PORTING_PARTITION_ACCESS_INTERFACE__
#define __PORTING_PARTITION_ACCESS_INTERFACE__

#include "partition_types.h"

#ifdef __cplusplus
extern "C" {
#endif


/*****************	����flash���ͼ��������ƴ�flash*********************/
/* [in]FlashType:��������												*/
/* [in]pPartitionName:��������									        */
/* [in]addr:������ƫ��													*/
/* [in]length:�򿪳���													*/
/* [out] �ɹ���flash handle��ʧ�ܣ�INVALID_FLASH_HANDLE                 */
/************************************************************************/
FLASH_HANDLE Porting_Flash_Open(FLASH_TYPE_E flashType, UINT_8 *pPartitionName,
		UINT_64 addr, UINT_64 length);

/*****************		���ݷ������ƴ�flash		*********************/
/* [in]pPartitionName:��������									        */
/* [out] �ɹ���flash handle��ʧ�ܣ�INVALID_FLASH_HANDLE                 */
/************************************************************************/
FLASH_HANDLE	Porting_Flash_OpenByName(UINT_8 *pPartitionName);

/*****************���ݷ������ͼ�ƫ�Ƶ�ַ��flash	*********************/
/* [in]FlashType:��������												*/
/* [in]addr:������ƫ��													*/
/* [in]length:�򿪳���													*/
/* [out] �ɹ���flash handle��ʧ�ܣ�INVALID_FLASH_HANDLE                 */
/************************************************************************/
FLASH_HANDLE Porting_Flash_OpenByTypeAndAddr(FLASH_TYPE_E FlashType,
		UINT_64 addr, UINT_64 length);

/*****************		����ָ������				*********************/
/* [in]handle:flash handle												*/
/* [in]addr:������ƫ��													*/
/* [in]length:��������													*/
/* [out] �ɹ���OPERATION_SUCCESS��ʧ�ܣ�OPERATION_FAILURE               */
/************************************************************************/
INT_32 Porting_Flash_Erase(FLASH_HANDLE handle, UINT_64 addr, UINT_64 length);

/*****************		��ȡ��������				*********************/
/* [in]handle:flash handle												*/
/* [in]addr:������ƫ��													*/
/* [out]pBuf:���ݻ���													*/
/* [in]length:��ȡ����													*/
/* [in]rwFlags����д��ʽ(�����泣�����壺FLASH_RW_FLAG_XXX)				*/
/* [out] �ɹ���ʵ�����ݳ��ȣ�ʧ�ܣ�-1               */
/************************************************************************/
INT_32 Porting_Flash_Read(FLASH_HANDLE handle, UINT_64 addr, UINT_8 *pBuf,
		UINT_64 length, UINT_32 rwFlags);

/*****************		��д����					*********************/
/* [in]handle:flash handle												*/
/* [in]addr:������ƫ��													*/
/* [in]pBuf:���ݻ���													*/
/* [in]length:д����													*/
/* [in]rwFlags����д��ʽ(�����泣�����壺FLASH_RW_FLAG_XXX)				*/
/* [out] �ɹ���OPERATION_SUCCESS��ʧ�ܣ�OPERATION_FAILURE               */
/************************************************************************/
INT_32 Porting_Flash_Write(FLASH_HANDLE handle, UINT_64 addr, UINT_8 *pBuf,
		UINT_64 length, UINT_32 rwFlags);

/*****************		��ȡ������Ϣ				*********************/
/* [in]handle:flash handle												*/
/* [out]info:������Ϣ													*/
/* [out] �ɹ���OPERATION_SUCCESS��ʧ�ܣ�OPERATION_FAILURE               */
/************************************************************************/
INT_32 Porting_Flash_GetInfo(FLASH_HANDLE handle, FlashInfo* info);

/*****************		�رշ���					*********************/
/* [in]handle:flash handle												*/
/* [out] �ɹ���OPERATION_SUCCESS��ʧ�ܣ�OPERATION_FAILURE               */
/************************************************************************/
INT_32 Porting_Flash_Close(FLASH_HANDLE handle);

#ifdef __cplusplus
}
#endif

#endif/*__PORTING_PARTITION_ACCESS_INTERFACE__*/
