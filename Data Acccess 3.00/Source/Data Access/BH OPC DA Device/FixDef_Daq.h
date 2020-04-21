#pragma once

///�ֶ��붨��
#include  "FixDef_Field.h"

///ȫ�ֵ�ö�ٶ���ͺ궨��
#include "DSE_Define.h"

/**����ʵʱ���ݵ��м�ģ��---------------------------------------------------*/

/**����ָ��������񶯲��ʵʱ��������ֵ����λ�����ݵ��м��ģ��,���ҷ��ش��͵���ͨ����Ӧ�Ŀ�䱨������ѧϰ����
  *��������ֶ��룺
  *            ��˾ID                 FIELD_SYSTEM_COMPANY
  *			   �ֳ���                 FIELD_SYSTEM_FACTORY
  *            ����ID                 FIELD_SERVICE_PLANTID
  *            �񶯲������ֵ����     FIELD_SERVICE_ON_SEND_ALLCHARVALUE
  *            ��ʼ����               FIELD_SERVICE_ON_SEND_STARTID
  *            �񶯲�����           FIELD_SERVICE_ON_SEND_VIBCHANNNUM
  *            ��������               FIELD_SERVICE_ON_SEND_VIBWAVE
  *            һ�鲨�ε���           FIELD_SERVICE_ON_SEND_WAVEPOINTNUM //����4ϵ���м��Ϊ�ܵĲ��ε���
  *            �Զ����������BUFF     FIELD_SERVICE_LEARNPARAM_BUF
  *            �Զ����������BUFFSIZE FIELD_SERVICE_CHANN_BUFFSIZE
  *            ����Ƶ��               FIELD_SERVICE_SAMPLE_FREQ
  *            ��������               FIELD_SERVICE_SAMPLE_NUM
  *            ѹ������ֽ���         FIELD_SERVICE_ZIPWAVE_BYTESNUM
  *            �����ת��             FIELD_SERVICE_REV
  *            �����ת��2            FIELD_SERVICE_REV2
  *            �����ת��3            FIELD_SERVICE_REV3
  *            �����ת��4            FIELD_SERVICE_REV4
  *            �����ת��5            FIELD_SERVICE_REV5
  *            ������ʼͨ������       FIELD_SERVICE_STARTINDEX
  *            ���ڽ���ͨ������       FIELD_SERVICE_ENDINDEX
  *            �Ƿ���θ����������   FIELD_SERVICE_SEND_END
  *����ֵ���ֶ��룺
  *            ������                FIELD_SYSTEM_STATUS
  *            ����                    FIELD_SERVICE_ON_SEND_STARTID
  *            ��䱨��ѧϰ����BUFF    FIELD_SERVICE_LEARNPARAM_BUFF
  *            ��Ӧ�ļ�϶��ѹ          FIELD_SERVICE_TREND_GAP
  *            ���ͨ���Ƿ��жϿ��    FIELD_SYSTEM_SENDC_IF
  *            ѧϰ�����ṹ��ĳ���    FIELD_SERVICE_LEN
  *            ѹ����ʽ(0 ��ѹ��)      FIELD_SERVICE_DATA_COMPRESSION
  */
#define     SERVICE_SERVICE_ON_RECEIVEALLVALUE        24000

/**����ָ������Ķ�̬���ʵʱ��������ֵ�������ݵ��м��ģ��
  *��������ֶ��룺
  *            ��˾ID                 FIELD_SYSTEM_COMPANY
  *			   �ֳ���                 FIELD_SYSTEM_FACTORY
  *            ����ID                 FIELD_SERVICE_PLANTID
  *            ��̬�������ֵ����     FIELD_SERVICE_ON_SEND_ALLCHARVALUE
  *            ��ʼ����               FIELD_SERVICE_ON_SEND_STARTID
  *            ��̬������           FIELD_SERVICE_ON_SEND_VIBCHANNNUM
  *            ��������               FIELD_SERVICE_ON_SEND_VIBWAVE
  *            һ�鲨�ε���           FIELD_SERVICE_ON_SEND_WAVEPOINTNUM //����4ϵ���м��Ϊ�ܵĲ��ε���
  *            �Զ����������BUFF     FIELD_SERVICE_LEARNPARAM_BUF
  *            �Զ����������BUFFSIZE FIELD_SERVICE_CHANN_BUFFSIZE  
  *            ����Ƶ��               FIELD_SERVICE_SAMPLE_FREQ
  *            ��������               FIELD_SERVICE_SAMPLE_NUM
  *            ѹ������ֽ���         FIELD_SERVICE_ZIPWAVE_BYTESNUM
  *            �����ת��             FIELD_SERVICE_REV
  *            �����ת��2            FIELD_SERVICE_REV2
  *            �����ת��3            FIELD_SERVICE_REV3
  *            �����ת��4            FIELD_SERVICE_REV4
  *            �����ת��5            FIELD_SERVICE_REV5
  *            ������ʼͨ������       FIELD_SERVICE_STARTINDEX
  *            ���ڽ���ͨ������       FIELD_SERVICE_ENDINDEX
  *            �Ƿ���θ����������   FIELD_SERVICE_SEND_END
  *            ѹ����ʽ(0 ��ѹ��)     FIELD_SERVICE_DATA_COMPRESSION��
  *����ֵ���ֶ��룺
  *            ������                FIELD_SYSTEM_STATUS
  */
#define     SERVICE_SERVICE_ON_RECEIVEDYNVALUE        24001


/**����ת�ٵ��м��ģ��
  *��������ֶ��룺
  *                ��˾ID      FIELD_SYSTEM_COMPANY
  *	    		       �ֳ���      FIELD_SYSTEM_FACTORY
  *                ����ID      FIELD_SERVICE_PLANTID
  *                �����ת��  FIELD_SERVICE_REV
  *                �����ת��2 FIELD_SERVICE_REV2
  *            �����ת��3     FIELD_SERVICE_REV3
  *            �����ת��4     FIELD_SERVICE_REV4
  *            �����ת��5     FIELD_SERVICE_REV5
  *����ֵ���ֶ��룺��
  */
#define     SERVICE_SERVICE_ON_RECEIVEREV             24002

/**����ALLPROC����������λ�����ݵ��м��ģ�飬���õ�ָ�����͵�����
  *��������ֶ��룺
  *                ��˾ID   FIELD_SYSTEM_COMPANY
  *			           �ֳ���   FIELD_SYSTEM_FACTORY
  *                ����ID      FIELD_SERVICE_PLANTID
  *                ��ʼ����          FIELD_SERVICE_ON_SEND_STARTID
  *                �������          FIELD_SERVICE_CHANNTYPE
  *                ��Ҫ���ݲ������  FIELD_SERVICE_ON_SEND_CHANNTYPE
  *                ����������        FIELD_SERVICE_ON_SEND_ALLPROCVALUE
  *                ����������        FIELD_SERVICE_ON_SEND_PROCCHANNNUM
  *����ֵ���ֶ��룺���FIELD_SERVICE_ON_SEND_CHANNTYPE�ֶβ���Ϊ0��2���Ͳ���������
  *                ����              FIELD_SERVICE_ON_SEND_AXISCHANNNUM
  *                ����              FIELD_SERVICE_ON_SEND_AXISDISPLACE
  */
#define     SERVICE_SERVICE_ON_RECEIVEPROC            24003

/**���ͻ�������״̬���ݵ��м��ģ�顣������������ݵı���״̬
  *��������ֶ��룺
  *            ��˾ID   FIELD_SYSTEM_COMPANY
  *			       �ֳ���   FIELD_SYSTEM_FACTORY
  *            ����ID                          FIELD_SERVICE_PLANTID
	*            ����λ��״̬                    FIELD_SERVICE_ON_SEND_AXISLOCATIONSTATE
	*            ����λ�ø���                    FIELD_SERVICE_ON_SEND_AXISCHANNNUM
	*            ������״̬                      FIELD_SERVICE_ON_SEND_ALLPROCSTATE
	*            ����������                      FIELD_SERVICE_ON_SEND_PROCCHANNNUM
	*            �񶯲��״̬                    FIELD_SERVICE_ON_SEND_ALLVIBSTATE
	*            �񶯲�����                    FIELD_SERVICE_ON_SEND_VIBCHANNNUM
	*            ��̬���״̬                    FIELD_SERVICE_ON_SEND_ALLDYNSTATE
	*            ��̬������                    FIELD_SERVICE_ON_SEND_DYNCHANNNUM
  *����ֵ���ֶ��룺��
  */
#define     SERVICE_SERVICE_ON_RECEIVECHANNSTATE      24004

/**����ָ��ָ���豸����ͣ�����ݵ�ʵʱ�м��
  *��������ֶ��룺
  *             ��˾ID          FIELD_SYSTEM_COMPANY
  *			    �ֳ���          FIELD_SYSTEM_FACTORY
  *             ����ID��        FIELD_SERVICE_PLANTID
  *             ��ʼ����        FIELD_SERVICE_ON_SEND_STARTID
  *             ��ͣ����־λ    FIELD_SERVICE_SUD_STATUS
  *             ��ͣ���¼�ID:   FIELD_SYSTEM_EVENT_ID
  *             ָ�������ת��  FIELD_SERVICE_REV
  *             ָ�������ת��2 FIELD_SERVICE_REV2
  *             ����ֵ����      FIELD_SERVICE_ON_SEND_ALLCHARVALUE
  *             ͨ������        FIELD_SERVICE_ON_SEND_VIBCHANNNUM
  *             ��������        FIELD_SERVICE_ON_SEND_VIBWAVE
  *             һ�鲨�ε���     FIELD_SERVICE_ON_SEND_WAVEPOINTNUM //����4ϵ���м��Ϊ�ܵĲ��ε���
  *             ����Ƶ��        FIELD_SERVICE_SAMPLE_FREQ
  *             ��������        FIELD_SERVICE_SAMPLE_NUM
  *             ��Ӧ��ʱ��       FIELD_SERVICE_TIME
  *             ��Ӧʱ���΢��   FIELD_SERVICE_MICROSECOND
  *             ��ͣ������      FIELD_SERVICE_SUD_TYPE
  *            �Ƿ���θ����������   FIELD_SERVICE_SEND_END
  *����ֵ���ֶ��룺
  *             �ɹ���ʶ      FIELD_SYSTEM_STATUS
  */
#define     SERVICE_SERVICE_ON_REVSUDDATA            24005

/**֪ͨ�м������������Ҫ��������
  *��������ֶ��룺
  *            ��˾ID   FIELD_SYSTEM_COMPANY
  *			       �ֳ���   FIELD_SYSTEM_FACTORY
  *����ֵ�ֶ��룺��
  */
#define     SERVICE_SERVICE_ON_SAVEDATA              24006

/**֪ͨ�м������������Ҫ�жϱ���
  *��������ֶ��룺
  *        ��˾ID   FIELD_SYSTEM_COMPANY
  *			   �ֳ���   FIELD_SYSTEM_FACTORY
  *����ֵ�ֶ��룺��
  */
#define     SERVICE_SERVICE_ON_JUDGEALARM            24007


/**����ָ����˾���ֳ����豸����ͣ���¼�ID
  *��������ֶ��룺
  *             ��˾ID         FIELD_SYSTEM_COMPANY
  *			        �ֳ���         FIELD_SYSTEM_FACTORY
  *             ����ID��       FIELD_SERVICE_PLANTID
  *             ��ʼʱ��       FIELD_SERVICE_OFF_TIMESTART
  *����ֵ���ֶ��룺
  *             ��ͣ���¼�ID:   FIELD_SYSTEM_EVENT_ID
  */
#define     SERVICE_SERVICE_OFF_REQSUDEVENTID        24008

/**ָ֪ͨ����ͣ���¼�����ͣ�����̽���������ɹ�����1��ʧ�ܷ���-1
  *��������ֶ��룺
  *             ��˾ID         FIELD_SYSTEM_COMPANY
  *			        �ֳ���         FIELD_SYSTEM_FACTORY
  *             ����ID��       FIELD_SERVICE_PLANTID
  *             ��ͣ������     FIELD_SERVICE_SUD_TYPE
  *             ��ͣ���¼�ID:  FIELD_SYSTEM_EVENT_ID
  *             ����ʱ��       FIELD_SERVICE_OFF_TIMEEND
  *����ֵ���ֶ��룺
  *             �ɹ���ʶ      FIELD_SYSTEM_STATUS
  */
#define     SERVICE_SERVICE_OFF_NOTICESUDSTOP        24009

/**��ͣ�������󣬷���ָ�����������ͣ�����ݵ��м��
  *��������ֶ��룺
	*             ��˾ID          FIELD_SYSTEM_COMPANY
	*			  �ֳ���          FIELD_SYSTEM_FACTORY
	*             ����ID��        FIELD_SERVICE_PLANTID
	*             ��ʼ����        FIELD_SERVICE_ON_SEND_STARTID
	*             ��ͣ����־λ    FIELD_SERVICE_SUD_STATUS
	*             ��ͣ���¼�ID:   FIELD_SYSTEM_EVENT_ID
	*             ָ�������ת��  FIELD_SERVICE_REV
	*             ָ�������ת��2 FIELD_SERVICE_REV2
	*             ָ�������ת��3  FIELD_SERVICE_REV3
    *             ָ�������ת��4  FIELD_SERVICE_REV4
    *             ָ�������ת��5  FIELD_SERVICE_REV5
	*             ����ֵ����      FIELD_SERVICE_ON_SEND_ALLCHARVALUE
	*             ͨ������        FIELD_SERVICE_ON_SEND_VIBCHANNNUM
	*             ��������        FIELD_SERVICE_ON_SEND_VIBWAVE
	*            һ�鲨�ε���     FIELD_SERVICE_ON_SEND_WAVEPOINTNUM //����4ϵ���м��Ϊ�ܵĲ��ε���
	*             ����Ƶ��        FIELD_SERVICE_SAMPLE_FREQ
	*             ��������        FIELD_SERVICE_SAMPLE_NUM
	*             �Զ����������BUFF  FIELD_SERVICE_LEARNPARAM_BUFF ///��ͬ�����ֽ��������ֶ�
	*             �Զ������ģ��ID    FIELD_SYSTEM_TEMPID           ///��ͬ�����ֽ��������ֶ�
	*            ��Ӧ��ʱ��       FIELD_SERVICE_TIME
	*            ��Ӧʱ���΢��   FIELD_SERVICE_MICROSECOND
	*             ��ͣ������      FIELD_SERVICE_SUD_TYPE
	*            �Ƿ���θ����������   FIELD_SERVICE_SEND_END
	*            ѹ����ʽ(0 ��ѹ��)     FIELD_SERVICE_DATA_COMPRESSION
	*����ֵ���ֶ��룺
	*             �ɹ���ʶ      FIELD_SYSTEM_STATUS
  */
#define     SERVICE_SERVICE_OFF_RECSUDDATA        24010


///��䱨����صĽӿ�

/**������ֵID��������鳤��С��1��ʾʧ��
  *��������ֶ���
    *           ��˾ID          FIELD_SYSTEM_COMPANY
	*			�ֳ���          FIELD_SYSTEM_FACTORY
	*           ����ID��        FIELD_SERVICE_PLANTID
	*           ͨ������        FIELD_SERVICE_CHANN_NUM
	*����ֵ���ֶ��룺
	*           ��ֵID����      FIELD_SERVICE_THRESHOLD_ID
	*           ���鳤�ȣ�ͨ�������� FIELD_SERVICE_CHANN_NUM
  */
#define     SERVICE_SERVICE_ON_REQTHESHOLDID       24011

/**����ָ����˾���ֳ����豸�Ŀ�䱨���¼�ID
  *��������ֶ��룺
  *             ��˾ID         FIELD_SYSTEM_COMPANY
  *			    �ֳ���         FIELD_SYSTEM_FACTORY
  *             ����ID��       FIELD_SERVICE_PLANTID
	*����ֵ���ֶ��룺
  *             ��䱨���¼�ID:   FIELD_SYSTEM_EVENT_ID
  */
#define     SERVICE_SERVICE_ON_REQFASTALARMEVENTID        24012

/**����ָ����˾���ֳ����豸���񶯲���䱨��״̬
  *��������ֶ��룺
  *             ��˾ID            FIELD_SYSTEM_COMPANY
  *			    �ֳ���            FIELD_SYSTEM_FACTORY
  *             ����ID��          FIELD_SERVICE_PLANTID
  *             ͨ������          FIELD_SERVICE_ON_SEND_STARTID
  *             �񶯵ı���״̬    FIELD_SERVICE_ON_SEND_ALLVIBSTATE
  *             ��ͨ������      FIELD_SERVICE_ON_SEND_VIBCHANNNUM
  *����ֵ���ֶ��룺
  *             �ɹ���ʶ            FIELD_SYSTEM_STATUS
  */
#define     SERVICE_SERVICE_ON_UPDATEFASTALARMSTATUS     24013


/**@brief ������ֵ����Ϣ��ѧϰ������ѧϰ���ݣ�6������ֵһ�𷢡�����-1��ʾʧ�ܣ����ش���0��ʾ�ɹ�
  *��������ֶ���
    *           ��˾ID          FIELD_SYSTEM_COMPANY
	*			�ֳ���          FIELD_SYSTEM_FACTORY
	*           ����ID��        FIELD_SERVICE_PLANTID
	*           ͨ������        FIELD_SERVICE_CHANNTYPE
	*           ͨ������        FIELD_SERVICE_ON_SEND_STARTID
	*           ��ֵID          FIELD_SERVICE_THRESHOLD_ID
	*           ѧϰ���ݵ�BUFF  FIELD_SERVICE_ON_SEND_VIBWAVE    //��������Ϊ��ͬ����ֵ������������.���鳤��=FIELD_SERVICE_LEN
	*           ѧϰ���ݵĳ���  FIELD_SERVICE_LEN
	*           ��ֵ��BUFF      FIELD_SERVICE_THRESHOLD_BUFF     //�ṹ�峤��ΪFIELD_SERVICE_CHANN_NUM
	*           ѧϰ������BUFF  FIELD_SERVICE_LEARNPARAM_BUFF    //�ṹ�峤��ΪFIELD_SERVICE_CHANN_NUM
	*           ��������        FIELD_SERVICE_ALARM_TYPE
	*           ѧϰ���ݵĿ�ʼʱ��  FIELD_SERVICE_OFF_TIMESTART
	*           ѧϰ���ݵĽ���ʱ��  FIELD_SERVICE_OFF_TIMEEND
	*           ��������ѧϰ������  FIELD_SYSTEM_TYPE
  *����ֵ���ֶ���
  *           �ɹ���ʶ            FIELD_SYSTEM_STATUS
  */
#define    SERVICE_SERVICE_OFF_SAVETHINFO         24014


/**ָ֪ͨ����䱨���¼��ı������̽���������ɹ�����1��ʧ�ܷ���-1
  *��������ֶ��룺
  *             ��˾ID          FIELD_SYSTEM_COMPANY
  *			    �ֳ���          FIELD_SYSTEM_FACTORY
  *             ����ID��        FIELD_SERVICE_PLANTID
  *             ͨ������        FIELD_SERVICE_CHANNTYPE
  *           ͨ������        FIELD_SERVICE_ON_SEND_STARTID
  *             ��䱨���¼�ID  FIELD_SYSTEM_EVENT_ID
  *             ����ʱ��        FIELD_SERVICE_OFF_TIMEEND
  *             ����ֵID        FIELD_SERVICE_THRESHOLD_ID
  *����ֵ���ֶ��룺
  *             �ɹ���ʶ      FIELD_SYSTEM_STATUS
  */
#define     SERVICE_SERVICE_OFF_NOTICEFASTALARMSTOP        24015

/**���Ϳ�䱨�����ݵ��м������
  *��������ֶ��룺
	*             ��˾ID           FIELD_SYSTEM_COMPANY
	*			  �ֳ���           FIELD_SYSTEM_FACTORY
	*             ����ID��         FIELD_SERVICE_PLANTID
	*             ��ʼ����         FIELD_SERVICE_ON_SEND_STARTID
	*             ������������     FIELD_SERVICE_ALARM_TYPE        ///���ȣ�FIELD_SERVICE_ON_SEND_VIBCHANNNUM
	*             ��䱨���¼�ID   FIELD_SYSTEM_EVENT_ID
	*             ָ�������ת��   FIELD_SERVICE_REV
	*             ָ�������ת��2  FIELD_SERVICE_REV2
	*             ָ�������ת��3  FIELD_SERVICE_REV3
	*             ָ�������ת��4  FIELD_SERVICE_REV4
	*             ָ�������ת��5  FIELD_SERVICE_REV5
	*             ����ֵ����       FIELD_SERVICE_ON_SEND_ALLCHARVALUE
	*             ͨ������         FIELD_SERVICE_ON_SEND_VIBCHANNNUM
	*             ��������         FIELD_SERVICE_ON_SEND_VIBWAVE
	*            һ�鲨�ε���      FIELD_SERVICE_ON_SEND_WAVEPOINTNUM //����4ϵ���м��Ϊ�ܵĲ��ε���
	*             ����Ƶ��         FIELD_SERVICE_SAMPLE_FREQ
	*             ��������         FIELD_SERVICE_SAMPLE_NUM
	*            �Զ����������BUFF  FIELD_SERVICE_LEARNPARAM_BUFF ///��ͬ�����ֽ��������ֶ�
	*            �Զ������ģ��ID    FIELD_SYSTEM_TEMPID           ///��ͬ�����ֽ��������ֶ�
	*            ��Ӧ��ʱ��        FIELD_SERVICE_TIME
	*            ��Ӧʱ���΢��    FIELD_SERVICE_MICROSECOND
	*            �Ƿ���θ����������   FIELD_SERVICE_SEND_END
	*            ѹ����ʽ(0 ��ѹ��)     FIELD_SERVICE_DATA_COMPRESSION
	*����ֵ���ֶ��룺
	*             �ɹ���ʶ      FIELD_SYSTEM_STATUS
  */
#define     SERVICE_SERVICE_OFF_RECFASTALARMDATA        24016

/**���汨������ѧϰ����ֵID��������鳤��С��1��ʾʧ��
  *��������ֶ���
    *           ��˾ID          FIELD_SYSTEM_COMPANY
	*			�ֳ���          FIELD_SYSTEM_FACTORY
	*           ����ID��        FIELD_SERVICE_PLANTID
	*           ͨ������        FIELD_SERVICE_CHANN_NUM
	*           ��ֵID����      FIELD_SERVICE_THRESHOLD_ID
	*����ֵ���ֶ��룺
  *           �ɹ���ʶ      FIELD_SYSTEM_STATUS
  */
#define     SERVICE_SERVICE_OFF_SAVEALAMREDNEWTHESHOLDID   24017


/**���һ�������ı�����־��ʧ�ܷ���ֵС��0���ɹ�Ϊ0
  *��������ֶ���
  *           ��˾ID          FIELD_SYSTEM_COMPANY
	*		  �ֳ���          FIELD_SYSTEM_FACTORY
	*         ����ID��        FIELD_SERVICE_PLANTID
	*         ͨ��ID          FIELD_SERVICE_CHANN1
	*         ��־ID          FIELD_SYSTEM_ID
  *           ��䱨���¼�ID  FIELD_SYSTEM_EVENT_ID
  *           ͨ������        FIELD_SERVICE_CHANNTYPE
  *           ��������        FIELD_SERVICE_ALARM_TYPE
  *           ��ʼʱ��        FIELD_SERVICE_OFF_TIMESTART
  *           ����ʱ��        FIELD_SERVICE_OFF_TIMEEND
	*           ��ֵID          FIELD_SERVICE_THRESHOLD_ID
	*           ����ֵID        FIELD_SERVICE_ON_SEND_STARTID
	*����ֵ���ֶ��룺
  *           �ɹ���ʶ      FIELD_SYSTEM_STATUS
  */
#define     SERVICE_SERVICE_OFF_ADDALARMLOG                24018

/**����������־��������ʼ��ӡ�����ɹ�����1��ʧ�ܷ���-1
  *��������ֶ��룺
  *             ��˾ID          FIELD_SYSTEM_COMPANY
  *			    �ֳ���          FIELD_SYSTEM_FACTORY
  *             ����ID��        FIELD_SERVICE_PLANTID
  *             ͨ������        FIELD_SERVICE_CHANNTYPE
	*           ͨ������        FIELD_SERVICE_ON_SEND_STARTID
  *             ��䱨���¼�ID  FIELD_SYSTEM_EVENT_ID
  *             ��ʼʱ��        FIELD_SERVICE_OFF_TIMESTART
  *             ��������        FIELD_SERVICE_ALARM_TYPE
  *             ��ֵID          FIELD_SERVICE_THRESHOLD_ID
  *����ֵ���ֶ��룺
  *             �ɹ���ʶ      FIELD_SYSTEM_STATUS
  */
#define     SERVICE_SERVICE_OFF_ADDFASTALARMSTARTLOG        24019

/**����ָ��������񶯲������󱣴����������ֵ����λ�����ݵ��м��ģ��
*��������ֶ��룺
*            ��˾ID                          FIELD_SYSTEM_COMPANY
*			 �ֳ���                          FIELD_SYSTEM_FACTORY
*            ����ID                          FIELD_SERVICE_PLANTID
*            �񶯲������ֵ����              FIELD_SERVICE_ON_SEND_ALLCHARVALUE
*            ��ʼ����                        FIELD_SERVICE_ON_SEND_STARTID
*            �񶯲�����                    FIELD_SERVICE_ON_SEND_VIBCHANNNUM
*            ��������                        FIELD_SERVICE_ON_SEND_VIBWAVE
*            �ܵĲ��ε���                    FIELD_SERVICE_ON_SEND_WAVEPOINTNUM
*            ѹ������ֽ���                  FIELD_SERVICE_ZIPWAVE_BYTESNUM
*            ʱ��ֵ                          FIELD_SERVICE_TIME
*            �Ƿ���θ����������            FIELD_SERVICE_SEND_END
*����ֵ���ֶ��룺
*            ������                 FIELD_SYSTEM_STATUS
*/
#define     SERVICE_SERVICE_ON_NETOFFRECEIVEALLVALUE         24021

/**����ָ������Ķ�̬�������󱣴����������ֵ�������ݵ��м��ģ��
*��������ֶ��룺
*            ��˾ID                 FIELD_SYSTEM_COMPANY
*			 �ֳ���                 FIELD_SYSTEM_FACTORY
*            ����ID                 FIELD_SERVICE_PLANTID
*            ��̬�������ֵ����     FIELD_SERVICE_ON_SEND_ALLCHARVALUE
*            ��ʼ����               FIELD_SERVICE_ON_SEND_STARTID
*            ��̬������           FIELD_SERVICE_ON_SEND_VIBCHANNNUM
*            ��������               FIELD_SERVICE_ON_SEND_VIBWAVE
*            �ܵĲ��ε���           FIELD_SERVICE_ON_SEND_WAVEPOINTNUM
*            ѹ������ֽ���         FIELD_SERVICE_ZIPWAVE_BYTESNUM
*            ʱ��ֵ                 FIELD_SERVICE_TIME
*            �Ƿ���θ����������   FIELD_SERVICE_SEND_END
*����ֵ���ֶ��룺
*            ������               FIELD_SYSTEM_STATUS
*/
#define     SERVICE_SERVICE_ON_NETOFFRECEIVEDYNVALUE         24022

/**���Ͷ����󱣴��ALLPROC����������λ�����ݵ��м��ģ�飬���õ�ָ�����͵�����
*��������ֶ��룺
*            ��˾ID            FIELD_SYSTEM_COMPANY
*            �ֳ���            FIELD_SYSTEM_FACTORY
*            ����ID            FIELD_SERVICE_PLANTID
*            ��ʼ����          FIELD_SERVICE_ON_SEND_STARTID
*            �������          FIELD_SERVICE_CHANNTYPE
*            ����������        FIELD_SERVICE_ON_SEND_ALLPROCVALUE
*            ����������        FIELD_SERVICE_ON_SEND_PROCCHANNNUM
*            ʱ��ֵ            FIELD_SERVICE_TIME
*����ֵ���ֶ��룺
*            ������          FIELD_SYSTEM_STATUS
*/
#define     SERVICE_SERVICE_ON_NETOFFRECEIVEPROC            24023

/** ������Ӳ��״̬
  *��������ֶ��룺(n)
  *            ���ɿ�����             FIELD_SERVICE_DAQ_CARD_INDEX
  *            ���ɿ�����             FIELD_SERVICE_DAQ_CARD_NUM
  *            ���ɿ��߼�����         FIELD_SERVICE_DAQ_CARD_NAME
  *            ʹ��AIͨ��(CSV)        FIELD_SERVICE_DAQ_USED_AI_CHANNEL
  *            ʹ��AIͨ����           FIELD_SERVICE_AI_CHANN_NUM
  *            ʹ��CIͨ��(CSV)        FIELD_SERVICE_DAQ_USED_CI_CHANNEL
  *            ʹ��CIͨ����           FIELD_SERVICE_CI_CHANN_NUM
  *            ����״��(CSV)          FIELD_SERVICE_DAQ_CARD_STATUS
  *����ֵ���ֶ��룺
  *            ����״̬      FIELD_SYSTEM_STATUS   (0������ ���� �쳣)

  */
#define     SERVICE_SERVICE_ON_RCV_DAQ_HW_STATUS              24030

/** �����������״̬(n)
  *��������ֶ��룺
  *            �汾��                                  FIELD_SERVICE_DAQ_SW_VERSION
  *            �ɼ�ģʽ                                FIELD_SERVICE_DAQ_ACQUIRE_TYPE
  *            ����ʱ��                                FIELD_SERVICE_TIME
  *            ���ռ�϶��ѹ״��                        FIELD_SERVICE_DAQ_GAP_RCV_STATUS
  *            ���һ�ζ������ݷ��Ϳ�ʼʱ��            FIELD_SERVICE_DAQ_OFFLINE_SAVE_BEGIN_TIME
  *            ���һ�ζ������ݷ��ͽ���ʱ��            FIELD_SERVICE_DAQ_OFFLINE_SAVE_END_TIME
  *����ֵ���ֶ��룺
  *            ����״̬       FIELD_SYSTEM_STATUS    (0������ ���� �쳣)

  */
#define     SERVICE_SERVICE_ON_RCV_DAQ_SW_STATUS              24031


///��Ӧ4ϵ���м����ͬ��������ؽӿڣ��������ݵ�������ĵ��м��

/**����ָ���豸�õ�ָ�������ͳ��ȵ��񶯲�������
*�������ֵ��
*            ��˾ID   FIELD_SYSTEM_COMPANY
*			 �ֳ���   FIELD_SYSTEM_FACTORY
*            ����ID    FIELD_SERVICE_PLANTID
*            ��ʼ����  FIELD_SERVICE_ON_SEND_STARTID
*            ����      FIELD_SERVICE_ON_SEND_VIBCHANNNUM
*            Ŀǰ���ݵ�ʱ�� FIELD_SERVICE_TIME
*���ز���ֵ��
*            �񶯲������ֵ����      FIELD_SERVICE_ON_SEND_ALLCHARVALUE
*            ��ʼ����                FIELD_SERVICE_ON_SEND_STARTID
*            �񶯲�����            FIELD_SERVICE_ON_SEND_VIBCHANNNUM
*            ��������                FIELD_SERVICE_ON_SEND_VIBWAVE
*            �ܵĲ��ε���            FIELD_SERVICE_ON_SEND_WAVEPOINTNUM
*            �Զ����������BUFF      FIELD_SERVICE_LEARNPARAM_BUFF
*            �Զ����������BUFFSIZE  FIELD_SERVICE_CHANN_BUFFSIZE
*            ���ݵ�ʱ��              FIELD_SERVICE_TIME
*/
#define     SERVICE_SERVICE_ON_GETSPECPLANTLENVIBDATA     24050

/**����ָ���豸ָ�������ͳ��ȵĶ�̬����
*�������ֵ��
*            ��˾ID   FIELD_SYSTEM_COMPANY
*		     �ֳ���   FIELD_SYSTEM_FACTORY
*            ����ID    FIELD_SERVICE_PLANTID
*            ��ʼ����  FIELD_SERVICE_ON_SEND_STARTID
*            ����      FIELD_SERVICE_ON_SEND_VIBCHANNNUM
*            Ŀǰ���ݵ�ʱ�� FIELD_SERVICE_TIME
*���ز���ֵ��
*            ��̬�������ֵ����     FIELD_SERVICE_ON_SEND_ALLCHARVALUE
*            ��ʼ����               FIELD_SERVICE_ON_SEND_STARTID
*            ��̬������           FIELD_SERVICE_ON_SEND_VIBCHANNNUM
*            ��������               FIELD_SERVICE_ON_SEND_VIBWAVE
*            �ܵĲ��ε���           FIELD_SERVICE_ON_SEND_WAVEPOINTNUM
*            ѹ������ֽ���         FIELD_SERVICE_ZIPWAVE_BYTESNUM
*            �Զ����������BUFF      FIELD_SERVICE_LEARNPARAM_BUFF
*            �Զ����������BUFFSIZE  FIELD_SERVICE_CHANN_BUFFSIZE
*/
#define     SERVICE_SERVICE_ON_GETSPECPLANTLENDYNDATA     24054

/**���Ͷ�̬�������ݵ��м������
*��������ֶ��룺
*             ��˾ID              FIELD_SYSTEM_COMPANY
*			  �ֳ���              FIELD_SYSTEM_FACTORY
*             ����ID��            FIELD_SERVICE_PLANTID
*             ��ʼ����            FIELD_SERVICE_ON_SEND_STARTID
*             ������������        FIELD_SERVICE_ALARM_TYPE
*             ��̬�����¼�ID      FIELD_SYSTEM_EVENT_ID
*             ����ֵ����		  FIELD_SERVICE_ON_SEND_ALLCHARVALUE
*             ͨ������			  FIELD_SERVICE_ON_SEND_VIBCHANNNUM
*             ��������            FIELD_SERVICE_ON_SEND_VIBWAVE
*             �ܵĲ��ε���        FIELD_SERVICE_ON_SEND_WAVEPOINTNUM
*             �Զ����������BUFF  FIELD_SERVICE_LEARNPARAM_BUFF
*             �Զ������ģ��ID    FIELD_SYSTEM_TEMPID
*             ��Ӧ��ʱ��          FIELD_SERVICE_TIME
*             ��Ӧʱ���΢��      FIELD_SERVICE_MICROSECOND
*             �Ƿ���θ����������   FIELD_SERVICE_SEND_END
*             ѹ����ʽ(0 ��ѹ��)     FIELD_SERVICE_DATA_COMPRESSION
*����ֵ���ֶ��룺
*             �ɹ���ʶ      FIELD_SYSTEM_STATUS
*/
#define     SERVICE_SERVICE_OFF_RECDYNALARMDATA          24055


/**����ALLPROC���������м��ģ�飬���õ�ָ�����͵�����
  *��������ֶ��룺
  *                ��˾ID   FIELD_SYSTEM_COMPANY
  *			       �ֳ���   FIELD_SYSTEM_FACTORY
  *                ����ID            FIELD_SERVICE_PLANTID
  *                �������ݵ�ʱ��              FIELD_SERVICE_TIME
  *����ֵ���ֶ��룺
  *                ����������        FIELD_SERVICE_ON_SEND_ALLPROCVALUE
  *                ����������        FIELD_SERVICE_ON_SEND_PROCCHANNNUM
   *               ���ݵ�ʱ��              FIELD_SERVICE_TIME
  */
#define     SERVICE_SERVICE_ON_GETSPECPLANTPROCDATA       24051

/**����ָ������ı���״̬��Ϊ����״̬�Ľṹ��
  *��������ֶ��룺
  *                ��˾ID   FIELD_SYSTEM_COMPANY
  *			       �ֳ���   FIELD_SYSTEM_FACTORY
  *                ����ID   FIELD_SERVICE_PLANTID
  *����ֵ���ֶ��룺
 *              ����λ��״̬                    FIELD_SERVICE_ON_SEND_AXISLOCATIONSTATE
	*            ����λ�ø���                    FIELD_SERVICE_ON_SEND_AXISCHANNNUM
	*            ������״̬                      FIELD_SERVICE_ON_SEND_ALLPROCSTATE
	*            ����������                      FIELD_SERVICE_ON_SEND_PROCCHANNNUM
	*            �񶯲��״̬                    FIELD_SERVICE_ON_SEND_ALLVIBSTATE
	*            �񶯲�����                    FIELD_SERVICE_ON_SEND_VIBCHANNNUM
	*            ��̬���״̬                    FIELD_SERVICE_ON_SEND_ALLDYNSTATE
	*            ��̬������                    FIELD_SERVICE_ON_SEND_DYNCHANNNUM
  */
#define     SERVICE_SERVICE_ON_GETSPECPLANTALLSTATE       24052

/**���һ����������ͣ����־������ɹ�������ͣ���¼�ID��ʧ�ܷ���-1
  *��������ֶ��룺
  *             ��˾ID        FIELD_SYSTEM_COMPANY
  *			    �ֳ���        FIELD_SYSTEM_FACTORY
  *             ����ID��      FIELD_SERVICE_PLANTID
  *             ��ͣ������    FIELD_SERVICE_SUD_TYPE
  *             ��ʼʱ��      FIELD_SERVICE_OFF_TIMESTART
  *             ����ʱ��      FIELD_SERVICE_OFF_TIMEEND
  *����ֵ���ֶ��룺
  *             ��ͣ���¼�ID: FIELD_SYSTEM_EVENT_ID
  */
#define     SERVICE_SERVICE_OFF_ADDWHOLESUDLOG             24053


/** ��������Ѳ������ͬ�����������߲�������͸�������ͬ��ʱ��
  *��������ֶ��룺
  *                ��˾          FIELD_SYSTEM_COMPANY
  *			       �ֳ���        FIELD_SYSTEM_FACTORY
  *                ����ID��      FIELD_SERVICE_PLANTID
  *����ֵ���ֶ��룺
  *                �ϴ�ͬ��ʱ��      FIELD_SERVICE_TIME
  *                ���߲����ʼ����  FIELD_SERVICE_ON_SEND_STARTID
  *                ���߲�����      FIELD_SERVICE_CHANN_NUM
  *                ͬ����Ӧ          FIELD_SYSTEM_STATUS
                                    ��FIELD_SYSTEM_SUCCESS ����ͬ��/ FIELD_SYSTEM_FAILURE �쳣���޷�ͬ����
  *
  */
#define     SERVICE_SERVICE_OFF_REQUESTOFFLINESYNC            24060

/**��������Ѳ������
  *��������ֶ��룺
  *                ��˾��        FIELD_SYSTEM_COMPANY
  *                �ֳ���        FIELD_SYSTEM_FACTORY
  *                �豸��        FIELD_SERVICE_PLANTID  (��1T1, 1T2)
  *                �ɼ�ʱ��      FIELD_SERVICE_TIME
  *                �����        FIELD_SYSTEM_CHANN
  *                ת��          FIELD_SERVICE_REV
  *                ����ֵ        FIELD_SERVICE_OFF_DATA( float)
  *����ֵ���ֶ��룺
  *                ͬ��״̬      FIELD_SYSTEM_STATUS
                                    ��FIELD_SYSTEM_SUCCESS/ FIELD_SYSTEM_FAILURE��
  *
  */
#define     SERVICE_SERVICE_OFF_SYNC_OFFLINE_DATA            24061




/**���ָ���������ͨ������̬��Ϣ
  *��������ֶ��룺
  *            ��˾ID                 FIELD_SYSTEM_COMPANY
  *			   �ֳ���                 FIELD_SYSTEM_FACTORY
  *            ����ID                 FIELD_SERVICE_PLANTID
  *            ������ʼͨ������       FIELD_SERVICE_STARTINDEX
  *            ���ڽ���ͨ������       FIELD_SERVICE_ENDINDEX
  *            �Ƿ���θ����������   FIELD_SERVICE_SEND_END
			   �񶯲�����           FIELD_SERVICE_ON_SEND_VIBCHANNNUM
  *����ֵ���ֶ��룺
  *            ��Ӧ�ļ�϶��ѹ          FIELD_SERVICE_TREND_GAP
  */
#define     SERVICE_SERVICE_ON_GET_VIBINFO        24066

/**���ָ������Ķ�̬ͨ������̬��Ϣ
  *��������ֶ��룺
  *            ��˾ID                 FIELD_SYSTEM_COMPANY
  *			   �ֳ���                 FIELD_SYSTEM_FACTORY
  *            ����ID                 FIELD_SERVICE_PLANTID
  *            ������ʼͨ������       FIELD_SERVICE_STARTINDEX
  *            ���ڽ���ͨ������       FIELD_SERVICE_ENDINDEX
  *            �Ƿ���θ����������   FIELD_SERVICE_SEND_END
			   �񶯲�����           FIELD_SERVICE_ON_SEND_VIBCHANNNUM
  *����ֵ���ֶ��룺
  *            ��Ӧ�ļ�϶��ѹ          FIELD_SERVICE_TREND_GAP

  */
#define     SERVICE_SERVICE_ON_GET_DYNINFO        24067


/**֪ͨ�м�����ݿ���
  *��������ֶ��룺
  */
#define     SERVICE_SERVICE_ON_SET_DISK_FULL       24068


/**ȷ��ָ�����ı�����Ϣ
  *��������ֶ��룺
  *���������  ��˾��     FIELD_SYSTEM_COMPANY
  *            �ֳ���     FIELD_SYSTEM_FACTORY
  *			   װ����	  FIELD_SYSTEM_SET
  *            �����     FIELD_SYSTEM_PLANT
  *            ����     FIELD_SYSTEM_CHANN
  *			   ȷ������	  FIELD_SERVICE_ALARM_CONFIRM_TYPE
  *            ȷ����ʼʱ��   FIELD_SERVICE_OFF_TIMESTART
  *	           ȷ�Ͻ���ʱ��   FIELD_SERVICE_OFF_TIMEEND
  *			   ȷ�ϵ�ǰʱ��	  FIELD_SERVICE_TIME
  *			   �û���		  FIELD_SYSTEM_USEID
  *			   ����ԭ�����   FIELD_SERVICE_DATA_CODE
  *			   ��ע			  FIELD_SERVICE_REMARK
  *			   �ͻ���IP		  FIELD_SYSTEM_CLIENT_IP
  *����ֵ���ֶ��룺
  *            �����ɹ����          FIELD_SERVICE_DATA_CODE 0ʧ�� 1�ɹ�
  *				#define     SERVICE_SERVICE_ON_ALARM_CONFIRM        24069
  */
#define     SERVICE_SERVICE_ON_ALARM_CONFIRM      24069

