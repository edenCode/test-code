#ifndef __DEMUX_H__
#define __DEMUX_H__


#ifdef __cplusplus
extern "C"
{
#endif

typedef int int32_t;
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;


/* TS����������ص����� */
typedef void (*PTsFilterCallback)( void *handle, void* filter, unsigned char *buf, int32_t size, uint32_t lParam );

/* SI-SECTION�Ľ⸴���� */
typedef struct tagFilterNode
{
	/* TS�������� */
	unsigned char continuity_counter;
	/* TS���ݰ��Ƿ����� */
	int discontinuity;
	/* SECTION��ȱ��������(byte) */
	int need;
	/* �Ƿ�����ͷ����3���ֽ� */
	int complete_header;

	/* SECTION���ݻ����� */
	unsigned char *buf;
	/* SECTION���ݻ�������С */
	int bufsize;
	/* SECTION���ݻ���������������С */
	int datsize;

	/* �������� */
	uint16_t pid;
	unsigned char pattern[16];
	unsigned char mask[16];
	int len;

	/* SECTION������� */
	PTsFilterCallback pOutputProc;
	/* SECTION��������������û����� */
	uint32_t lParam;

	/* ��һ��FILTER */
	struct tagFilterNode *next;
}SFilterNode;

typedef struct
{
	/* ���������� */
	SFilterNode *list;
	/* �����ϴβ���TS���ݵĻ����� */
	unsigned char tsbuf[188];
	/* �����ϴβ���TS���ݴ�С */
	int tssize;
}SDemux;



/* �����⸴���� */
void *Demux_Create();

/* ���ٽ⸴���� */
void Demux_Destroy( void *handle );

/* ����һ�������� */
void* Demux_CreateFilter( void *handle, uint16_t pid, unsigned char *pattern, unsigned char *mask, int32_t len, 
							int32_t qsize, PTsFilterCallback pProc, uint32_t lParam  );

/* ������һ�ַ�ʽ����һ�������� */
void* Demux_CreateFilterEx( void *handle, uint16_t pid, unsigned char tid, unsigned char tid_mask,
							uint16_t tid_ext, uint16_t tid_ext_mask,
							int32_t qsize, PTsFilterCallback pProc, uint32_t lParam  );
/* ����һ�������� */
void Demux_DestroyFilter( void *handle, void* filter );

/* ����TS������ */
void Demux_OnData( void *handle, unsigned char *buf, int32_t size );


#ifdef __cplusplus
}
#endif

#endif /* __DEMUX_H__ */
