#ifndef	__KEYLED__RE__
#define	__KEYLED__RE__

#ifdef __cplusplus
extern "C" {               // ���߱��������д���Ҫ��C����Լ����ģʽ��������
#endif

typedef enum
{
	ON_GREEN_LEVEL,
	ON_RED_LEVEL,
	OFF_LEVEL,
}LEVEL_TYPE;

int fpanel_ledcontrol_init(void);

int fpanel_ledcontrol(LEVEL_TYPE value);	/*low_level will lighting led*/

#ifdef __cplusplus
}
#endif

#endif
