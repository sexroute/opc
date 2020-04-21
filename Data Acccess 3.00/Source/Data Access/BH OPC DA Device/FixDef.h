#ifndef   __FIXDEF_DEFINE__
#define	  __FIXDEF_DEFINE__
///�ֶ��붨��
#include  "FixDef_Field.h"
///ȫ�ֵ�ö�ٶ���ͺ궨��
#include "DSE_Define.h"



#define    FIELD_CODE             1001     //������
#define    FIELD_MESSAGE          1002     //����˵��


//*********************������****************************//
#define FUNC_MODULE_TESTFUNC      10001	//���Ժ���
//************************ʵʱ���ݶ�ȡ����******************************//
/**��ȡָ�����������񶯲��ĸ������͵�����ֵ��ͨ��ѭ������ȡ�ø�������������������ֵ��
  *ÿѭ�����οɵõ�һ����������ֵ�ṹ��
  *�������ֵ��
  *                 ��˾ID   FIELD_SYSTEM_COMPANY
  *			         �ֳ���   FIELD_SYSTEM_FACTORY
  *                 ����ID   FIELD_SERVICE_PLANTID
  *����ֵ���ֶ��룺
  *                 ���ID         FIELD_SERVICE_CHANN1
  *                 ����ֵ�ṹ��   FIELD_SERVICE_CHARVALUE_S
  *                 ����ֵ         FIELD_SYSTEM_ALARM_LOW
  *                 Σ��ֵ         FIELD_SYSTEM_ALARM_HIGH
  *                 ��λ           FIELD_SERVICE_CHANN1_UNIT
  *                 ָ���������ת��    FIELD_SERVICE_REV
  *                 ʱ��           FIELD_SERVICE_TIME
  */
#define     SERVICE_SERVICE_ON_GETALLFIVECHAR         20000      //��ȡָ�����������񶯲�����������ֵ

/**��ȡָ�����������ĸ������͵�����ֵ��
  *���������
  *          ��˾ID   FIELD_SYSTEM_COMPANY
  *			 �ֳ���   FIELD_SYSTEM_FACTORY
  *          ����ID   FIELD_SERVICE_PLANTID
  *          ���buff       FIELD_SERVICE_CHANN_BUFF
  *          ���buff����   FIELD_SERVICE_CHANN_BUFFSIZE
  *          ������       FIELD_SERVICE_CHANN_NUM
  *����ֵ���ֶ��룺
  *          ����ֵ�ṹ��   FIELD_SERVICE_CHARVALUE_S
  *          ���ID         FIELD_SERVICE_CHANN1
  *          ���λ��       FIELD_SYSTEM_CHANN_ALIAS
  *          ����ֵ         FIELD_SYSTEM_ALARM_LOW
  *          Σ��ֵ         FIELD_SYSTEM_ALARM_HIGH
  *          ��λ           FIELD_SERVICE_CHANN1_UNIT
  *          ָ���������ת��    FIELD_SERVICE_REV
  *          ʱ��           FIELD_SERVICE_TIME
  *          �������       FIELD_SYSTEM_CHANN_TYPE
  */
#define     SERVICE_SERVICE_ON_GETSPECFIVECHAR        20001    //��ȡָ������ָ���񶯲�����������ֵ��

/**��ȡ���и��ֲ�������ֵ��ͨ��ѭ������ȡ�ø�������������������ֵ��
  *��ͨ����ʹ�������͵�����ֵ�ṹ�壻FIELD_SERVICE_CHARVALUE_S
  *������ͨ����ʹ������ֵ�ֶ� FIELD_SERVICE_TREND_VALUE
  *��̬ͨ����ʹ�ö�̬���͵�����ֵ�ṹ�� FIELD_SERVICE_CHARVALUE_S
  *ÿѭ�����οɵõ�һ�����ָ����������ֵ
  *�������ֵ������ID          FIELD_SERVICE_PLANTID
  *            ��˾ID          FIELD_SYSTEM_COMPANY
  *			       �ֳ���          FIELD_SYSTEM_FACTORY
  *            ���buff        FIELD_SERVICE_CHANN_BUFF
  *            ���buff����    FIELD_SERVICE_CHANN_BUFFSIZE
  *            ������        FIELD_SERVICE_CHANN_NUM
  *����ֵ���ֶ��룺
  *            ���ID          FIELD_SERVICE_CHANN1
  *            ����ֵ          FIELD_SERVICE_TREND_VALUE
  *        ����ֵ�ṹ��        FIELD_SERVICE_CHARVALUE_S
  *                 ��λ           FIELD_SERVICE_CHANN1_UNIT
  *            ʱ��            FIELD_SERVICE_TIME
  *          ָ���������ת��    FIELD_SERVICE_REV
  *          �������          FIELD_SYSTEM_CHANN_TYPE
  *          ����������        FIELD_SYSTEM_TYPE
  *          ��������          FIELD_SYSTEM_ALARM_LOW
  *          ����������        FIELD_SYSTEM_ALARM_HIGH
  *          ��������          FIELD_SYSTEM_ALARM_LOW2
  *          ����������        FIELD_SYSTEM_ALARM_HIGH2
  */
#define     SERVICE_SERVICE_ON_GETALLTYPECHAR         20002   //�õ�����ʽ��е�豸����״̬ʵʱ����

/**�õ�ָ���������񶯲���Ƶ�ס������֮�䡰�����ֿ�������������㣬��ѭ����ȡ
  *���������
  *          ��˾ID   FIELD_SYSTEM_COMPANY
  *			     �ֳ���   FIELD_SYSTEM_FACTORY
  *          ����ID           FIELD_SERVICE_PLANTID
  *          ���buff         FIELD_SERVICE_CHANN_BUFF
  *          ���buff����     FIELD_SERVICE_CHANN_BUFFSIZE
  *          ������         FIELD_SERVICE_CHANN_NUM
  *          ��������         FIELD_SERVICE_ZOOM_LINES
  *����ֵ���ֶ��룺
  *          �����                           FIELD_SERVICE_CHANN1
  *          ����Ƶ������                   FIELD_SERVICE_FREQWAVE1
  *          ���ʵ��Ƶ��һ�����ݵĸ���       FIELD_SERVICE_FREQWAVE_NUM
  *          �񶯲��Ƶ��DF                   FIELD_SERVICE_FREQWAVE_DF
  *          ����ֵ�ṹ��                     FIELD_SERVICE_CHARVALUE_S
  *          ָ���������ת��               FIELD_SERVICE_REV
  *          ʱ��                             FIELD_SERVICE_TIME
  */
#define     SERVICE_SERVICE_ON_GETSPECTRUM                20003

/**�õ�ָ���������񶯲���ָ����������ֵ
  *���������
  *          ��˾ID         FIELD_SYSTEM_COMPANY
  *			 �ֳ���         FIELD_SYSTEM_FACTORY
  *          ����ID         FIELD_SERVICE_PLANTID
  *          ����ֵ����     FIELD_SERVICE_TREND_CHARTYPE
  *          ���buff       FIELD_SERVICE_CHANN_BUFF
  *          ���buff����   FIELD_SERVICE_CHANN_BUFFSIZE
  *          ������       FIELD_SERVICE_CHANN_NUM
  *����ֵ���ֶ��룺
  *          �������ֵ         FIELD_SERVICE_TREND_VALUE
  *          ���ID             FIELD_SERVICE_CHANN1
  *          ʱ��           FIELD_SERVICE_TIME
  *          ��λ             FIELD_SERVICE_CHANN1_UNIT
  */
#define     SERVICE_SERVICE_ON_GETFOURSPECCHAR       20004

/**�õ�ָ�������ָ��������������͵����й���������ֵ��ע�⣺�������������񶯲�㣬�򲻷����κ�ֵ��
  *�������������ID         FIELD_SERVICE_PLANTID
  *          ��˾ID         FIELD_SYSTEM_COMPANY
  *			     �ֳ���         FIELD_SYSTEM_FACTORY
  *          �������       FIELD_SERVICE_CHANNTYPE
  *����ֵ���ֶ��룺
  *          ������ֵ       FIELD_SERVICE_TREND_PROCESS
  *          ���ID         FIELD_SERVICE_CHANN1
  *            ʱ��           FIELD_SERVICE_TIME
  *          ��λ             FIELD_SERVICE_CHANN1_UNIT
  */
#define     SERVICE_SERVICE_ON_GETALLPROCVALUE        20005

/**�õ�ָ���������������ֵ��
  *���������
  *          ��˾ID           FIELD_SYSTEM_COMPANY
  *			     �ֳ���           FIELD_SYSTEM_FACTORY
  *          ����ID           FIELD_SERVICE_PLANTID
  *          ���buff         FIELD_SERVICE_CHANN_BUFF
  *          ���buff����     FIELD_SERVICE_CHANN_BUFFSIZE
  *          ������         FIELD_SERVICE_CHANN_NUM
  *����ֵ���ֶ��룺
  *          ���������ֵ     FIELD_SERVICE_TREND_PROCESS
  *          ���ID           FIELD_SERVICE_CHANN1
  *          ʱ��             FIELD_SERVICE_TIME
  *          ��λ             FIELD_SERVICE_CHANN1_UNIT
  */
#define     SERVICE_SERVICE_ON_GETSPECPROCVALUE       20006

/**�õ�ָ���������񶯲���ʵʱ���Ρ�Ƶ�׺���������ֵ�������֮�䡰�����ֿ�������������㣬��ѭ����ȡ
  *���������
  *          ��˾ID   FIELD_SYSTEM_COMPANY
  *			     �ֳ���   FIELD_SYSTEM_FACTORY
  *          ����ID           FIELD_SERVICE_PLANTID
  *          ���buff         FIELD_SERVICE_CHANN_BUFF
  *          ���buff����     FIELD_SERVICE_CHANN_BUFFSIZE
  *          ������         FIELD_SERVICE_CHANN_NUM
  *          ���ε���         FIELD_SERVICE_TIMEWAVE_NUM
  *          ��������         FIELD_SERVICE_ZOOM_LINES
  *����ֵ���ֶ��룺
  *          �����                           FIELD_SERVICE_CHANN1
  *          ���λ��                         FIELD_SYSTEM_CHANN_ALIAS
  *          ���Ĳ�������                   FIELD_SERVICE_TIMEWAVE1
  *          ����Ƶ������                   FIELD_SERVICE_FREQWAVE1
  *          ���ʵʱ������һ�����ݵĸ���     FIELD_SERVICE_TIMEWAVE_NUM
  *          ���ʵ��Ƶ��һ�����ݵĸ���       FIELD_SERVICE_FREQWAVE_NUM
  *          �񶯲��Ƶ��DF                   FIELD_SERVICE_FREQWAVE_DF
  *          ��������ֵ                       FIELD_SERVICE_CHARVALUE_S
  *          ����ֵ                           FIELD_SYSTEM_ALARM_LOW
  *          Σ��ֵ                           FIELD_SYSTEM_ALARM_HIGH
  *          ��λ                             FIELD_SERVICE_CHANN1_UNIT
  *          ָ���������ת��               FIELD_SERVICE_REV
  *          ʱ��                             FIELD_SERVICE_TIME
  *          ������������λ��                      FIELD_SERVICE_ANGLEPARAM1
  *          �������ر���λ��                      FIELD_SERVICE_ANGLEPARAM2
  *          ������������λ��                      FIELD_SERVICE_ANGLEPARAM3
  *          �������ر���λ��                      FIELD_SERVICE_ANGLEPARAM4
  *          ��״���α�������                      FIELD_SERVICE_ALARM_LOW
  *          ��״���α���������                    FIELD_SERVICE_ALARM_HIGH
  *          �����ʼ����                          FIELD_SERVICE_STARTINDEX
  *          ����������                          FIELD_SERVICE_ENDINDEX
  *          �Զ����������BUFF                    FIELD_SERVICE_LEARNPARAM_BUFF
  *          �Զ����������BUFFSIZE                FIELD_SERVICE_CHANN_BUFFSIZE
  */
#define     SERVICE_SERVICE_ON_GETWAVE                20007

/**�õ�ĳһ�����Ĺ켣�Ĳ������ݡ�
  *���������
  *          ��˾ID   FIELD_SYSTEM_COMPANY
  *			 �ֳ���   FIELD_SYSTEM_FACTORY
  *          ����ID   FIELD_SERVICE_PLANTID
  *          ���λ������     FIELD_SYSTEM_AXISLOCATION
  *          ˮƽ�����񶯲��ID   FIELD_SERVICE_CHANNID_HOR
  *          ��ֱ�����񶯲��ID   FIELD_SERVICE_CHANNID_VER
  *          ���ε���         FIELD_SERVICE_TIMEWAVE_NUM
  *����ֵ���ֶ��룺
  *          ���Ĺ켣�Ĵ�ֱ����������       FIELD_SERVICE_AXESTRACK_WAVE_VER
  *          ��ֱ����Ĳ�������ѹ������ֽ��� FIELD_SERVICE_ZIPWAVE_BYTESNUM
  *          ���Ĺ켣��ˮƽ����������       FIELD_SERVICE_AXESTRACK_WAVE_HOR
  *          ˮƽ����Ĳ�������ѹ������ֽ��� FIELD_SERVICE_ZIPWAVE_BYTESNUM1
  *          ���Ĺ켣��һ���Ĳ������ݸ���     FIELD_SERVICE_AXESTRACK_WAVENUM
  *          ָ���������ת��               FIELD_SERVICE_REV
  *          ˮƽ��������ֵ                   FIELD_SERVICE_CHARVALUE_S
  *          ��ֱ��������ֵ                   FIELD_SERVICE_CHARVALUE_S2
  *          ����Ƶ��                         FIELD_SERVICE_SAMPLE_FREQ
  *          ˮƽ����ֵ                       FIELD_SYSTEM_ALARM_LOW
  *          ˮƽΣ��ֵ                       FIELD_SYSTEM_ALARM_HIGH
  *          ��ֱ����ֵ                       FIELD_SYSTEM_ALARM_LOW2
  *          ��ֱΣ��ֵ                       FIELD_SYSTEM_ALARM_HIGH2
  *          ˮƽ������λ��                 FIELD_SYSTEM_CHANN_ALIAS
  *          ��ֱ������λ��                 FIELD_SYSTEM_CHANN2_ALIAS
  *          ��λ                             FIELD_SERVICE_CHANN1_UNIT
  *          ʱ��                             FIELD_SERVICE_TIME
  *          ת������                       FIELD_SYSTEM_TYPE //0:Ϊ��ʱ��,1Ϊ˳ʱ��
  *          ��������                       FIELD_SYSTEM_STATUS//1:Ϊ������,2Ϊ������
  */
#define     SERVICE_SERVICE_ON_GETAXESTRACK           20008

/**�õ�ָ������ָ��һ��������λ��ֵ��
  *���������
  *          ��˾ID               FIELD_SYSTEM_COMPANY
  *			     �ֳ���               FIELD_SYSTEM_FACTORY
  *          ����ID               FIELD_SERVICE_PLANTID
  *          ���λ������         FIELD_SYSTEM_AXISLOCATION
  *          ˮƽ�����񶯲��ID   FIELD_SERVICE_CHANNID_HOR
  *          ��ֱ�����񶯲��ID   FIELD_SERVICE_CHANNID_VER
  *����ֵ���ֶ��룺
  *           X�����񶯲��λ��  FIELD_SERVICE_AXESLOCATION_HOR
  *           Y�����񶯲��λ��  FIELD_SERVICE_AXESLOCATION_VER
  *            ʱ��           FIELD_SERVICE_TIME
  */
#define     SERVICE_SERVICE_ON_GETAXESLOCATION        20009

/**�õ�ָ����˾�ͷֳ�,������ָ�������ת�١����ָ������ֻ��һ��ת�٣���ֻȡFIELD_SERVICE_REV��ֵ
  *���������
  *            ��˾ID   FIELD_SYSTEM_COMPANY
  *    			   �ֳ���   FIELD_SYSTEM_FACTORY
  *            �豸��buff     FIELD_SERVICE_CHANN_BUFF
  *            �豸��buff���� FIELD_SERVICE_CHANN_BUFFSIZE
  *            �豸�Ÿ���     FIELD_SERVICE_CHANN_NUM
  *����ֵ���ֶ��룺
  *          ����ID          FIELD_SERVICE_PLANTID
  *          ָ�������ת��  FIELD_SERVICE_REV
  *          ָ�������ת��2 FIELD_SERVICE_OFF_REV2
  *            ʱ��           FIELD_SERVICE_TIME
  */
#define     SERVICE_SERVICE_ON_GETREV                 20010

/**�õ�ָ��������������λ�Ʋ��ֵ
  *�������ֵ��
  *            ��˾ID   FIELD_SYSTEM_COMPANY
  *			   �ֳ���   FIELD_SYSTEM_FACTORY
  *            ����ID         FIELD_SERVICE_PLANTID
  *            ���buff         FIELD_SERVICE_CHANN_BUFF
  *            ���buff����     FIELD_SERVICE_CHANN_BUFFSIZE
  *            ������         FIELD_SERVICE_CHANN_NUM
  *����ֵ���ֶ��룺
  *            ��λ��ֵ       FIELD_SERVICE_TREND_AXISDISPLACE
  *            ��϶��ѹ       FIELD_SERVICE_TREND_GAP
  *            ֱ����         FIELD_SERVICE_TREND_DC
  *            ���ID         FIELD_SERVICE_CHANN1
  *            ���λ��       FIELD_SYSTEM_CHANN_ALIAS
  *            ����ֵ         FIELD_SYSTEM_ALARM_LOW
  *            Σ��ֵ         FIELD_SYSTEM_ALARM_HIGH
  *            ��λ           FIELD_SERVICE_CHANN1_UNIT
  *            ָ���������ת��    FIELD_SERVICE_REV
  *            ʱ��           FIELD_SERVICE_TIME
  */
#define     SERVICE_SERVICE_ON_GETSPECAXISDISPLACE    20011

/**�õ�ָ������������λ�Ʋ��ֵ��ͨ��ѭ�����εõ�������λ��ֵ
  *�������ֵ��
  *            ��˾ID   FIELD_SYSTEM_COMPANY
  *			   �ֳ���   FIELD_SYSTEM_FACTORY
  *            ����ID   FIELD_SERVICE_PLANTID
  *����ֵ���ֶ��룺
  *            ��λ��ֵ       FIELD_SERVICE_TREND_AXISDISPLACE
  *            ���ID         FIELD_SERVICE_CHANN1
  *            ����ֵ         FIELD_SYSTEM_ALARM_LOW
  *            Σ��ֵ         FIELD_SYSTEM_ALARM_HIGH
  *            ��λ           FIELD_SERVICE_CHANN1_UNIT
  *            �������ת��   FIELD_SERVICE_REV
  *            ʱ��           FIELD_SERVICE_TIME
  */
#define     SERVICE_SERVICE_ON_GETALLAXISDISPLACE     20012

/**�õ��û����۲���鷶Χ�����л���Ĳ������״̬��ͨ��ѭ�����εõ����б����Ĳ��,�������Ҫͨ����Ϣ���FIELD_SERVICE_IFCHANN��Ϊ-1
  *�������ֵ���û�ID         FIELD_SYSTEM_USEID
  *            �Ƿ���Ҫͨ��   FIELD_SERVICE_IFCHANN
  *����ֵ�ֶ��룺
  *            ��˾ID             FIELD_SYSTEM_COMPANY
  *			       �ֳ���             FIELD_SYSTEM_FACTORY
  *            �����Ļ���ID       FIELD_SERVICE_PLANTID
  *            �����Ĳ��ID       FIELD_SERVICE_CHANN1
  *            ����ֵ             FIELD_SERVICE_CHANN1VALUE
  */
#define     SERVICE_SERVICE_ON_GETALLCHANNELSTATE     20013

/**�õ�ָ�����������飨����֮��ͨ���������ֿ������в������ֵ��ͨ��ѭ�����εõ�����ֵ��
  *ע�������񶯲����˵��ָ�������������;͸���һ��������ֻ���񶯲���ж�Ӧ��ת�٣����������û�ж�Ӧת��
  *���״̬�������0��˵��û�б�����1��ʾ����ͱ���2��ʾ����߱���3��ʾ��䱨����4��ʾ���䱨����5��ʾ���Ʊ�����С�����ȼ����
  *�������ֵ��
  *            ��˾ID         FIELD_SYSTEM_COMPANY
  *			   �ֳ���         FIELD_SYSTEM_FACTORY
  *            ����ֵ����     FIELD_SERVICE_TREND_CHARTYPE
  *            �豸��buff     FIELD_SERVICE_CHANN_BUFF
  *            �豸��buff���� FIELD_SERVICE_CHANN_BUFFSIZE
  *            �豸�Ÿ���     FIELD_SERVICE_CHANN_NUM
  *����ֵ���ֶ��룺
  *            �豸ID         FIELD_SERVICE_PLANTID
  *            ���ID         FIELD_SERVICE_CHANN1
  *            ���ֵ         FIELD_SERVICE_CHANN1VALUE
  *            ��㵥λ       FIELD_SERVICE_CHANN1_UNIT
  *            ��������б�   FIELD_SERVICE_CHANN1_LIST
  *            ����״̬     FIELD_SERVICE_CHANN1_STATUS
  *            �������       FIELD_SERVICE_CHANNTYPE
  *            �������ֵ      FIELD_SERVICE_CHARVALUE_S
  *            ת��1          FIELD_SERVICE_REV
  *            ת��2          FIELD_SERVICE_REV2
  *            ת��3          FIELD_SERVICE_REV3
  *            ת��4          FIELD_SERVICE_REV4
  *            ת��5          FIELD_SERVICE_REV5
  *            ʱ��           FIELD_SERVICE_TIME
  */
#define     SERVICE_SERVICE_ON_GETALLCHANNVALUE       20014


/**�õ�ָ���������̬ѹ�����ʾ��ͼ��Ϣ��ѭ���õ�������������
  *�������ֵ��
  *          ��˾ID         FIELD_SYSTEM_COMPANY
  *			 �ֳ���         FIELD_SYSTEM_FACTORY
  *          ����ID         FIELD_SERVICE_PLANTID
  *          ���buff         FIELD_SERVICE_CHANN_BUFF
  *          ���buff����     FIELD_SERVICE_CHANN_BUFFSIZE
  *          ������         FIELD_SERVICE_CHANN_NUM
  *            ʾ��ͼ����     FIELD_SYSTEM_TYPE       P-V,P-a,P-t
  *����ֵ���ֶ��룺
  *          ����           FIELD_SERVICE_CHANN1
  *          ������         FIELD_SYSTEM_CHANN_ALIAS
  *          ��������         FIELD_SERVICE_TIMEWAVE1
  *          X��������        FIELD_SERVICE_TIMEWAVE2
  *          ��������ֵ       FIELD_SERVICE_CHARVALUE_S
  *          ����Ƶ��         FIELD_SERVICE_SAMPLE_FREQ
  *          ��������         FIELD_SERVICE_SAMPLE_NUM
  *          ����ֵ           FIELD_SYSTEM_ALARM_LOW
  *          Σ��ֵ           FIELD_SYSTEM_ALARM_HIGH
  *          ��λ             FIELD_SERVICE_CHANN1_UNIT
  *          ָ������ת��   FIELD_SERVICE_REV
  *          ʱ��             FIELD_SERVICE_TIME
  *          ������������λ��                      FIELD_SERVICE_ANGLEPARAM1
  *          �������ر���λ��                      FIELD_SERVICE_ANGLEPARAM2
  *          ������������λ��                      FIELD_SERVICE_ANGLEPARAM3
  *          �������ر���λ��                      FIELD_SERVICE_ANGLEPARAM4
  */
#define   SERVICE_SERVICE_ON_GETPVDATA               20015

/**�õ�ָ������������������ʵʱ���Ρ�Ƶ�׺���������ֵ�������֮�䡰�����ֿ�������������㣬��ѭ����ȡ
  *���������
  *          ��˾ID   FIELD_SYSTEM_COMPANY
  *			     �ֳ���   FIELD_SYSTEM_FACTORY
  *          ����ID           FIELD_SERVICE_PLANTID
  *          ���buff         FIELD_SERVICE_CHANN_BUFF
  *          ���buff����     FIELD_SERVICE_CHANN_BUFFSIZE
  *          ������         FIELD_SERVICE_CHANN_NUM
  *          ���ε���         FIELD_SERVICE_TIMEWAVE_NUM
  *          ��������         FIELD_SERVICE_ZOOM_LINES
  *����ֵ���ֶ��룺
  *          �����                  FIELD_SERVICE_CHANN1
  *          ������                FIELD_SYSTEM_CHANN_ALIAS
  *          ���Ĳ�������          FIELD_SERVICE_TIMEWAVE1
  *          ����Ƶ������          FIELD_SERVICE_FREQWAVE1
  *          ��㲨�����ݵĵ���      FIELD_SERVICE_TIMEWAVE_NUM
  *          ���Ƶ�����ݵĵ���      FIELD_SERVICE_FREQWAVE_NUM
  *          �񶯲��Ƶ��DF          FIELD_SERVICE_FREQWAVE_DF
  *          ��������ֵ              FIELD_SERVICE_CHARVALUE_S
  *          ����ֵ                  FIELD_SYSTEM_ALARM_LOW
  *          Σ��ֵ                  FIELD_SYSTEM_ALARM_HIGH
  *          ��λ                    FIELD_SERVICE_CHANN1_UNIT
  *          ָ���������ת��      FIELD_SERVICE_REV
  *          ʱ��                    FIELD_SERVICE_TIME
  *          ������������λ��                      FIELD_SERVICE_ANGLEPARAM1
  *          �������ر���λ��                      FIELD_SERVICE_ANGLEPARAM2
  *          ������������λ��                      FIELD_SERVICE_ANGLEPARAM3
  *          �������ر���λ��                      FIELD_SERVICE_ANGLEPARAM4
  *          ��״���α�������                      FIELD_SERVICE_ALARM_LOW
  *          ��״���α���������                    FIELD_SERVICE_ALARM_HIGH
  *          �����ʼ����                          FIELD_SERVICE_STARTINDEX
  *          ����������                          FIELD_SERVICE_ENDINDEX
  *          �Զ����������BUFF                    FIELD_SERVICE_LEARNPARAM_BUFF
  *          �Զ����������BUFFSIZE                FIELD_SERVICE_CHANN_BUFFSIZE
  */
#define     SERVICE_SERVICE_ON_GETRODSINKDATA       20016

/**ͨ���ֳ����õ������豸�ı���״̬,���ҵõ�ָ�������ת��
  *�������ֵ��
  *            ��˾ID   FIELD_SYSTEM_COMPANY
  *			       �ֳ���   FIELD_SYSTEM_FACTORY
  *            ����ID   FIELD_SERVICE_PLANTID
  *����ֵ�ֶ��룺
  *            �����Ļ���ID         FIELD_SERVICE_PLANTID
  *            ָ���豸��ת��       FIELD_SERVICE_REV
  *            ָ�������ת��2      FIELD_SERVICE_OFF_REV2
  */
#define     SERVICE_SERVICE_ON_GETSUBCORPSTATE        20017

/**�õ�ָ��ָ�������ָ����������ͣ���Ĳ��Ĳ���ͼ���ݣ�һ��ֻ�ܵõ�һ�����ݣ����û��ָ����㣬�������в�������
  *���������
  *          ��˾ID           FIELD_SYSTEM_COMPANY
  *		       �ֳ���           FIELD_SYSTEM_FACTORY
  *          ����ID           FIELD_SERVICE_PLANTID
  *          ���buff         FIELD_SERVICE_CHANN_BUFF
  *          ���buff����     FIELD_SERVICE_CHANN_BUFFSIZE
  *          ������         FIELD_SERVICE_CHANN_NUM
  *          ����ֵ����       FIELD_SERVICE_TREND_CHARTYPE
  *����ֵ���ֶ��룺
  *          ����           FIELD_SERVICE_CHANN1
  *          ��λ��           FIELD_SERVICE_TREND_ONECHAR
  *          ��ֵ��           FIELD_SERVICE_TREND_OVERALLCHAR
  *          ת�٣�           FIELD_SERVICE_REV
  *          ʱ��             FIELD_SERVICE_TIME
  *          ��Ӧʱ���΢��   FIELD_SERVICE_MICROSECOND
  *          ��ͣ��״̬       FIELD_SERVICE_SUD_STATUS
  *          ��ͣ������       FIELD_SERVICE_SUD_TYPE
  *          ��ͣ���¼�ID     FIELD_SYSTEM_EVENT_ID
  *          ������ֵ�ṹ��    FIELD_SERVICE_CHARVALUE_S
  */
#define     SERVICE_SERVICE_ON_GETBODE                20018


/**�õ�ָ��ָ�������ָ����������ͣ���Ĳ���ٲ�ͼ��һ��ֻ�ܵõ�һ�鲨��Ƶ��
*���������
*          ��˾ID           FIELD_SYSTEM_COMPANY
*		   �ֳ���           FIELD_SYSTEM_FACTORY
*          ����ID           FIELD_SERVICE_PLANTID
*          ����           FIELD_SERVICE_CHANN1
*          ��������         FIELD_SERVICE_ZOOM_LINES
*          ����ֵ����       FIELD_SERVICE_TREND_CHARTYPE
*����ֵ���ֶ��룺
*          ��λ��           FIELD_SERVICE_TREND_ONECHAR
*          ��ֵ��           FIELD_SERVICE_TREND_OVERALLCHAR
*          ת�٣�           FIELD_SERVICE_REV
*          Ƶ������         FIELD_SERVICE_FREQWAVE1
*          Ƶ�����ݸ���     FIELD_SERVICE_FREQWAVE_NUM
*          Ƶ��DF           FIELD_SERVICE_FREQWAVE_DF
*          ʱ��             FIELD_SERVICE_TIME
*          ��Ӧʱ���΢��   FIELD_SERVICE_MICROSECOND
*          ��ͣ��״̬       FIELD_SERVICE_SUD_STATUS
*          ��ͣ������       FIELD_SERVICE_SUD_TYPE
*          ��ͣ���¼�ID     FIELD_SYSTEM_EVENT_ID
*/
#define     SERVICE_SERVICE_ON_GETWATERFALL            20019

/**�õ�ָ�������񶯲���ϸ��Ƶ�׷����Ͳ��Ρ�
  *���������
  *          ��˾ID   FIELD_SYSTEM_COMPANY
  *			     �ֳ���   FIELD_SYSTEM_FACTORY
  *          ����ID   FIELD_SERVICE_PLANTID
  *          ���             FIELD_SERVICE_CHANN1
  *          ���ε���         FIELD_SERVICE_TIMEWAVE_NUM
  *          ��������         FIELD_SERVICE_ZOOM_LINES
  *          ��ʼƵ��         FIELD_SERVICE_ZOOM_STARTFREQ
  *          ��ֹƵ��         FIELD_SERVICE_ZOOM_STOPFREQ
  *����ֵ���ֶ��룺
  *          ���Ĳ�������   FIELD_SERVICE_TIMEWAVE1
  *          ����Ƶ������   FIELD_SERVICE_ZOOMSPECTRUM
  *          �������ݸ���     FIELD_SERVICE_TIMEWAVE_NUM
  *          ��������         FIELD_SERVICE_ZOOM_LINES
  *          ��ʼƵ��         FIELD_SERVICE_ZOOM_STARTFREQ
  *          �񶯲��Ƶ��DF   FIELD_SERVICE_FREQWAVE_DF
  *          ״̬             FIELD_SYSTEM_STATUS
  *          ״̬����         FIELD_SYSTEM_STATUS_DISCRIPTION
  */
#define     SERVICE_SERVICE_ON_GETZOOMSPEC                20020

/**�õ�ָ��ָ������Ͳ��������Ϣ
  *���������
  *          ��˾ID           FIELD_SYSTEM_COMPANY
  *			  �ֳ���           FIELD_SYSTEM_FACTORY
  *          ����ID           FIELD_SERVICE_PLANTID
  *          ����           FIELD_SERVICE_CHANN1
  *����ֵ���ֶ��룺
  *          �ת�٣�       FIELD_SERVICE_REV
  *          ʵʱת�٣�       FIELD_SERVICE_REV2
  *          ����Ƶ��         FIELD_SERVICE_SAMPLE_FREQ
  *          ����Ƶ��         FIELD_SERVICE_SAMPLE_NUM
  */
#define     SERVICE_SERVICE_ON_GETSPECCHANNINFO           20021

/**��ȡָ���豸�񶯲���ָ����Ƶ������ֵ����λ��
  *���ָ������ˣ���ֻȡָ����������ֵ����λ
  *���û��ָ����㣬�������в��ͨ��ѭ������ȡ�ø������Ķ�Ӧ��Ƶ����ֵ����λ��ÿѭ�����οɵõ�һ�����ָ����������ֵ����λ
  *�������ֵ��
  *            ��˾ID      FIELD_SYSTEM_COMPANY
  *			       �ֳ���      FIELD_SYSTEM_FACTORY
  *            ����ID      FIELD_SERVICE_PLANTID
  *            ���ID      FIELD_SERVICE_CHANN1
  *            ����ֵ����  FIELD_SERVICE_TREND_CHARTYPE
  *����ֵ���ֶ��룺
  *            ���ID      FIELD_SERVICE_CHANN1
  *            ָ������ֵ  FIELD_SERVICE_TREND_VALUE
  *            ��Ӧ����λ  FIELD_SERVICE_TREND_PHASE
  *            ת�٣�      FIELD_SERVICE_REV
  */
#define     SERVICE_SERVICE_ON_GETALLSPECCHARANDPHASE     20022

/**��ȡָ�������̬ѹ����㡢�����˳�������㡢�񶯲�㡣��ȡ�䲨�κ���������
*������Ϊ�վͲ��᷵�ض�Ӧ������
*�������ֵ��
*          ��˾ID                     FIELD_SYSTEM_COMPANY
*	       �ֳ���                     FIELD_SYSTEM_FACTORY
*          ����ID                     FIELD_SERVICE_PLANTID
*          �񶯲��buff               FIELD_SERVICE_CHANN_BUFF
*          �񶯲��buff����           FIELD_SERVICE_CHANN_BUFFSIZE
*          �񶯲�����               FIELD_SERVICE_CHANN_NUM
*          ��̬���buff               FIELD_SERVICE_CHANN_BUFF2
*          ��̬���buff����           FIELD_SERVICE_CHANN_BUFFSIZE2
*          ��̬������               FIELD_SERVICE_CHANN_NUM2
*          �����˳��������buff       FIELD_SERVICE_CHANN_BUFF3
*          �����˳��������buff����   FIELD_SERVICE_CHANN_BUFFSIZE3
*          �����˳�����������       FIELD_SERVICE_CHANN_NUM3
*�����ֶΣ�
*          �������ݵĵ���             FIELD_SERVICE_TIMEWAVE_NUM
*          ����Ƶ��                   FIELD_SERVICE_SAMPLE_FREQ
*          �������                   FIELD_SERVICE_CHANN1
*          ��㲨��                   FIELD_SERVICE_TIMEWAVE1
*          �������ֵ                 FIELD_SERVICE_CHARVALUE_S
*          ������                     FIELD_SERVICE_FREQWAVE2
*          ת��                       FIELD_SERVICE_REV
*          ʱ��                       FIELD_SERVICE_TIME
*          ������������λ��           FIELD_SERVICE_ANGLEPARAM1
*          �������ر���λ��           FIELD_SERVICE_ANGLEPARAM2
*          ������������λ��           FIELD_SERVICE_ANGLEPARAM3
*          �������ر���λ��           FIELD_SERVICE_ANGLEPARAM4
*/
#define   SERVICE_SERVICE_ON_GETRCMULTIPARAMDATA          20023

/**���ż�ʵʱ����ͳ��
  *�������ֵ��  ��˾ID          FIELD_SYSTEM_COMPANY
  *		         �ֳ���          FIELD_SYSTEM_FACTORY
  *����ֵ���ֶ��룺
  *		         �豸��          FIELD_SERVICE_PLANT_NUM
  *		         �����豸��      FIELD_SERVICE_ALARM_PLANTNUM
  *		         �����豸��      FIELD_SERVICE_RUN_PLANTNUM
  *		         ͣ���豸��      FIELD_SERVICE_STOP_PLANTNUM
  */
#define   SERVICE_SERVICE_ON_GROUPALARMSTAT              20024

/**��ȡ��˾��ʵʱ����ͳ��
  *�������ֵ����˾ID          FIELD_SYSTEM_COMPANY
  *		     �ֳ���           FIELD_SYSTEM_FACTORY
  *	         �豸��           FIELD_SERVICE_PLANTID
  *����ֵ���ֶ��룺
  *          ��˾��           FIELD_SYSTEM_COMPANY
  *		     �ֳ���           FIELD_SYSTEM_FACTORY
  *		     �豸��           FIELD_SERVICE_PLANTID
  *		     �����           FIELD_SERVICE_CHANN_NUM
  *		     ����״̬         FIELD_SERVICE_ALARM_STATUS
  *		     ��ͣ��״̬       FIELD_SERVICE_SUD_STATUS (1, ͣ�� 0 ����)
  *		     ת��1            FIELD_SERVICE_REV
  *		     ����ID           FIELD_SERVICE_ALARMID
  */
#define     SERVICE_SERVICE_ON_COMPANYALARMSTAT         20025

/**��ȡ���վ��ʵʱ����ͳ��
  *�������ֵ����˾ID          FIELD_SYSTEM_COMPANY
  *		     �ֳ���           FIELD_SYSTEM_FACTORY
  *	         �豸��           FIELD_SERVICE_PLANTID
  *����ֵ���ֶ��룺
  *		     �����           FIELD_SERVICE_CHANN1
  *		     ���λ��         FIELD_SYSTEM_CHANN_ALIAS
  *		     ����ֵ           FIELD_SERVICE_CHANN1VALUE
  *		     ����״̬         FIELD_SERVICE_CHANN1_STATUS
  *		     ת��1            FIELD_SERVICE_REV
  *		     ����ID           FIELD_SERVICE_ALARMID
   */
#define     SERVICE_SERVICE_ON_MONITORALARMSTAT         20026

/**�õ�ָ������ָ��һ����Ļ���������λ�ù켣
*���������
*          ��˾ID           FIELD_SYSTEM_COMPANY
*		   �ֳ���            FIELD_SYSTEM_FACTORY
*          ����ID           FIELD_SERVICE_PLANTID
*          ���λ������      FIELD_SYSTEM_AXISLOCATION
*          ˮƽ������ID   FIELD_SERVICE_CHANNID_HOR
*          ��ֱ������ID   FIELD_SERVICE_CHANNID_VER
*          ���ε���          FIELD_SERVICE_TIMEWAVE_NUM
*����ֵ���ֶ��룺
*          ˮƽ����������    FIELD_SERVICE_AXESTRACK_WAVE_HOR
*          ��ֱ����������    FIELD_SERVICE_AXESTRACK_WAVE_VER
*          ʵ�ʲ��ε���        FIELD_SERVICE_AXESTRACK_WAVENUM
*          ˮƽ����������ֵ  FIELD_SERVICE_CHARVALUE_S
*          ��ֱ����������ֵ  FIELD_SERVICE_CHARVALUE_S2
*          ʱ��                FIELD_SERVICE_TIME
*		   ת��1               FIELD_SERVICE_REV
*		   ���Ĺ켣Բ��X����   FIELD_SERVICE_AXIS_COORX
*		   ���Ĺ켣Բ��Y����   FIELD_SERVICE_AXIS_COORY
*		   ������Բˮƽ��뾶  FIELD_SERVICE_HOR_RADIUS
*		   ������Բ��ֱ��뾶  FIELD_SERVICE_VER_RADIUS
*/
#define     SERVICE_SERVICE_ON_GETRODSINKAXESLOCATION         20027

/**����ʽϵͳӦ����⣬�õ�ָ������ָ���׺ŵ�Ӧ�����κ��񶯲�㲨��
*���������
*          ��˾ID        ������    FIELD_SYSTEM_COMPANY
*		       �ֳ���          ������  FIELD_SYSTEM_FACTORY
*          ����ID          ������  FIELD_SERVICE_PLANTID
*          ���׺�                  FIELD_SERVICE_CYLINDERNO
*          �����񶯲��            FIELD_SERVICE_CHANN1
*����ֵ���ֶ��룺
*          ����Ӧ���������ݡ�������FIELD_SERVICE_TIMEWAVE1
*          ����Ӧ���������ݡ�������FIELD_SERVICE_TIMEWAVE2
*          ������Ӧ���������ݡ�����FIELD_SERVICE_FREQWAVE1
*          �񶯲�������   �������� FIELD_SERVICE_FREQWAVE2
*          �������ݸ���   �������� FIELD_SERVICE_TIMEWAVE_NUM
*		       ����ֵ�ṹ��		         FIELD_SERVICE_CHARVALUE_S
*		       ����ֵ�ṹ��2		       FIELD_SERVICE_CHARVALUE_S2
*		       �����				   				 FIELD_SYSTEM_CHANN
*		       �����2				   			 FIELD_SYSTEM_CHANN2
*		   		 ���1�ǶȲ���1		   		 FIELD_SERVICE_ANGLEPARAM1
*		       ���1�ǶȲ���2		   		 FIELD_SERVICE_ANGLEPARAM2
*		       ���1�ǶȲ���3		       FIELD_SERVICE_ANGLEPARAM3
*		       ���1�ǶȲ���4		       FIELD_SERVICE_ANGLEPARAM4
*		       ���2�ǶȲ���1		       FIELD_SERVICE_ANGLEPARAM5
*		       ���2�ǶȲ���2		       FIELD_SERVICE_ANGLEPARAM6
*		       ���2�ǶȲ���3		       FIELD_SERVICE_ANGLEPARAM7
*		       ���2�ǶȲ���4		       FIELD_SERVICE_ANGLEPARAM8
*		       ʱ��				   	   			 FIELD_SERVICE_TIME 
*/
#define     SERVICE_SERVICE_ON_GETDYNSTRESSWAVE                20028


/**�õ�ĳһ���ᴿ���Ĺ켣�Ĳ������ݡ�
*���������
*          ��˾ID               FIELD_SYSTEM_COMPANY
*		   �ֳ���               FIELD_SYSTEM_FACTORY
*          ����ID               FIELD_SERVICE_PLANTID
*          ���λ������         FIELD_SYSTEM_AXISLOCATION
*          ˮƽ�����񶯲��ID   FIELD_SERVICE_CHANNID_HOR
*          ��ֱ�����񶯲��ID   FIELD_SERVICE_CHANNID_VER
*          ���ε���             FIELD_SERVICE_TIMEWAVE_NUM
*����ֵ���ֶ��룺
*          ��ֱ���������������Ƶ��       FIELD_SERVICE_VERFREQ
*          ��ֱ��������������ķ�ֵ       FIELD_SERVICE_VERAMP
*          ��ֱ�����������������λ       FIELD_SERVICE_VERPHASE
*          ˮƽ���������������Ƶ��       FIELD_SERVICE_HORFREQ
*          ˮƽ��������������ķ�ֵ       FIELD_SERVICE_HORAMP
*          ˮƽ�����������������λ       FIELD_SERVICE_HORPHASE
*          ָ���������ת��             FIELD_SERVICE_REV
*          ת������                     FIELD_SYSTEM_TYPE //0:Ϊ��ʱ��,1Ϊ˳ʱ��
*          ��������                     FIELD_SYSTEM_STATUS//1:Ϊ������,2Ϊ������
*          ˮƽ��������ֵ�ṹ��           FIELD_SERVICE_CHARVALUE_S
*          ��ֱ��������ֵ�ṹ��           FIELD_SERVICE_CHARVALUE_S2
*/
#define     SERVICE_SERVICE_ON_GETPURIFYAXESTRACK           20029

/**�õ�ָ���񶯲���ʵʱ���κ͵��ס�������񶯲��2�����ò�������ֻ��ȡһ�飩
*���������
*          ��˾ID           FIELD_SYSTEM_COMPANY
*		  �ֳ���           FIELD_SYSTEM_FACTORY
*          ����ID           FIELD_SERVICE_PLANTID
*          ���buff         FIELD_SERVICE_CHANN_BUFF
*          ���buff����     FIELD_SERVICE_CHANN_BUFFSIZE
*          ������         FIELD_SERVICE_CHANN_NUM
*          ���ε���         FIELD_SERVICE_TIMEWAVE_NUM
*����ֵ���ֶ��룺
*          �����                                FIELD_SERVICE_CHANN1
*          ���λ��                              FIELD_SYSTEM_CHANN_ALIAS
*          ���Ĳ�������                        FIELD_SERVICE_TIMEWAVE1
*          ���ĵ�������                        FIELD_SERVICE_FREQWAVE1
*          ���ʵʱ������һ�����ݵĸ���          FIELD_SERVICE_TIMEWAVE_NUM
*          ���ʵ�ʵ���һ�����ݵĸ���            FIELD_SERVICE_FREQWAVE_NUM
*          �񶯲�㵹��DF                        FIELD_SERVICE_FREQWAVE_DF
*          ��������ֵ                            FIELD_SERVICE_CHARVALUE_S
*          ����ֵ                                FIELD_SYSTEM_ALARM_LOW
*          Σ��ֵ                                FIELD_SYSTEM_ALARM_HIGH
*          ��λ                                  FIELD_SERVICE_CHANN1_UNIT
*          ָ���������ת��                    FIELD_SERVICE_REV
*          ʱ��                                  FIELD_SERVICE_TIME
*          ������������λ��                      FIELD_SERVICE_ANGLEPARAM1
*          �������ر���λ��                      FIELD_SERVICE_ANGLEPARAM2
*          ������������λ��                      FIELD_SERVICE_ANGLEPARAM3
*          �������ر���λ��                      FIELD_SERVICE_ANGLEPARAM4
*/
#define     SERVICE_SERVICE_ON_GETCEPSTRUM                   20030

/**�õ�ָ��һ���񶯲���ʵʱȫ�׺�ȫ���ٲ�ͼ��
*���������
*          ��˾ID                           FIELD_SYSTEM_COMPANY
*		   �ֳ���                           FIELD_SYSTEM_FACTORY
*          ����ID                           FIELD_SERVICE_PLANTID
*          ���λ������                     FIELD_SYSTEM_AXISLOCATION
*          ˮƽ�����񶯲��ID               FIELD_SERVICE_CHANNID_HOR
*          ��ֱ�����񶯲��ID               FIELD_SERVICE_CHANNID_VER
*          ���ε���                         FIELD_SERVICE_TIMEWAVE_NUM
*          �Ƿ�Ӧ�����㷨                   FIELD_SERVICE_FUNCTION_TYPE
*����ֵ���ֶ��룺
*          ȫ��Ƶ�ʺͷ�ֵ��Ϣ�ṹ��         FIELD_SERVICE_LEARNPARAM_BUFF
*          ȫ����Ϣ�ṹ���С               FIELD_SERVICE_CHANN_BUFFSIZE
*          ָ���������ת��               FIELD_SERVICE_REV
*          ˮƽ��������ֵ                   FIELD_SERVICE_CHARVALUE_S
*          ��ֱ��������ֵ                   FIELD_SERVICE_CHARVALUE_S2
*          ����Ƶ��                         FIELD_SERVICE_SAMPLE_FREQ
*          ʱ��                             FIELD_SERVICE_TIME
*          ת������                       FIELD_SYSTEM_TYPE //0:Ϊ��ʱ��,1Ϊ˳ʱ��
*/
#define     SERVICE_SERVICE_ON_GETFULLSPECSTRUM          20031

/** ��ȡ�쳣���ݼ����
  *��������ֶ��룺��
  *����ֵ���ֶ��룺(n)
  *            ��˾ID                 FIELD_SYSTEM_COMPANY
  *            �ֳ���                 FIELD_SYSTEM_FACTORY
  *            ����ID                 FIELD_SERVICE_PLANTID
  *            ���                   FIELD_SYSTEM_CHANN
  *            �쳣ʱ��               FIELD_SERVICE_TIME
  *            �쳣���               FIELD_SYSTEM_TYPE
  *            �쳣ԭ��               FIELD_SYSTEM_STATUS_DISCRIPTION
  *\description
               �쳣���(FIELD_SYSTEM_TYPE)�ֶ����ͣ� GE_ABNORMAL_DATA_CATEGORY
                                     ����(Խ�����ݡ����Ʋ�����ת�٣�����������)
  */
#define     SERVICE_SERVICE_ON_GET_ABNORMAL_DATA_RECORD       20032


/***************************��ʷ��ȡ���ݲ���*************************/
/**�õ���ǰʱ��������һ���������͵��������ݣ�ͨ��ѭ�����εõ������������ݺͶ�Ӧʱ�䣬ÿ��ȡ�����ݶ�Ӧʱ�䶼����ͬ��
  *@param��  ��������ֶ���
  *          ��˾ID       FIELD_SYSTEM_COMPANY
  *			 �ֳ���       FIELD_SYSTEM_FACTORY
  *          ����ID       FIELD_SERVICE_PLANTID
  *          ��������     FIELD_SERVICE_OFF_TRENDTYPE
  *          ����ֵ����   FIELD_SERVICE_TREND_CHARTYPE
  *          ������ͣ�   FIELD_SERVICE_OFF_CHANNTYPE
  *          ���buff     FIELD_SERVICE_CHANN_BUFF
  *          ���buff���� FIELD_SERVICE_CHANN_BUFFSIZE
  *          ������     FIELD_SERVICE_CHANN_NUM
  *@return  ����ֵ���ֶ��룺
  *          �����������ֵBuff   FIELD_SERVICE_TREND_VALUE_BUFF
  *          ������             FIELD_SERVICE_CHANN_NUM
  *          ʱ��ֵ               FIELD_SERVICE_OFF_TIME
  */
#define     SERVICE_SERVICE_OFF_GETCURTREND           21001

/**�õ�ָ����˾���ֳ�������Ͳ��ָ��ʱ�̵�Ƶ������
  *���������
  *          ��˾ID       FIELD_SYSTEM_COMPANY
  *	    	 �ֳ���       FIELD_SYSTEM_FACTORY
  *          ����ID       FIELD_SERVICE_PLANTID
  *          ���ID       FIELD_SERVICE_OFF_CHANN1
  *          �������ݸ��� FIELD_SERVICE_OFF_WAVE_NUM
  *          ����������   FIELD_SERVICE_OFF_FREQANALYSIS_LINES
  *          ʱ��         FIELD_SERVICE_OFF_TIME
  *          ��ʼƵ��     FIELD_SERVICE_ZOOM_STARTFREQ
  *          ��ֹƵ��     FIELD_SERVICE_ZOOM_STOPFREQ
  *����ֵ���ֶ��룺
  *          ��������        FIELD_SERVICE_OFF_WAVE
  *          Ƶ������        FIELD_SERVICE_OFF_FREQWAVE
  *          �������ݸ���    FIELD_SERVICE_OFF_WAVE_NUM
  *          ��ʼƵ��         FIELD_SERVICE_ZOOM_STARTFREQ
  *          Ƶ��DF          FIELD_SERVICE_OFF_FREQWAVE_DF
  *          Ƶ�����ݵ���    FIELD_SERVICE_OFF_FREQWAVE_NUM
  *          ����ֵ�ṹ��    FIELD_SERVICE_CHARVALUE_S
  *          ����ֵ          FIELD_SYSTEM_ALARM_LOW
  *          Σ��ֵ          FIELD_SYSTEM_ALARM_HIGH
  *          ��λ            FIELD_SERVICE_CHANN1_UNIT
  *          ������        FIELD_SYSTEM_CHANN_ALIAS
  *          ת��            FIELD_SERVICE_OFF_REV
  *          ������������λ��                      FIELD_SERVICE_ANGLEPARAM1
  *          �������ر���λ��                      FIELD_SERVICE_ANGLEPARAM2
  *          ������������λ��                      FIELD_SERVICE_ANGLEPARAM3
  *          �������ر���λ��                      FIELD_SERVICE_ANGLEPARAM4
  *          ��״���α�������                      FIELD_SERVICE_ALARM_LOW
  *          ��״���α���������                    FIELD_SERVICE_ALARM_HIGH
  *          �����ʼ����                          FIELD_SERVICE_STARTINDEX
  *          ����������                          FIELD_SERVICE_ENDINDEX
  *          �Զ����������BUFF                    FIELD_SERVICE_LEARNPARAM_BUFF
  */
#define     SERVICE_SERVICE_OFF_GETSPECFREQWAVE       21002

/**�õ�ָ��ʱ��Ρ�����ֵ���͡������������������ݣ�ͨ��ѭ�����εõ������������ݺͶ�Ӧʱ�䣬ÿ��ȡ�����ݶ�Ӧʱ�䶼����ͬ��
  *��������ֶ��룺
  *          ����ֵ����   FIELD_SERVICE_TREND_CHARTYPE
  *          ������ͣ�   FIELD_SERVICE_OFF_CHANNTYPE
  *          ��˾ID       FIELD_SYSTEM_COMPANY
  *			 �ֳ���       FIELD_SYSTEM_FACTORY
  *          ����ID       FIELD_SERVICE_PLANTID
  *          ���buff     FIELD_SERVICE_CHANN_BUFF
  *          ���buff���� FIELD_SERVICE_CHANN_BUFFSIZE
  *          ������     FIELD_SERVICE_CHANN_NUM
  *          ��ʼʱ��     FIELD_SERVICE_OFF_TIMESTART
  *          ��ֹʱ��     FIELD_SERVICE_OFF_TIMEEND
  *����ֵ���ֶ��룺
  *          �����������ֵBuff   FIELD_SERVICE_TREND_VALUE_BUFF
  *          ������             FIELD_SERVICE_CHANN_NUM
  *          ʱ��ֵ               FIELD_SERVICE_OFF_TIME
  *          ��㵥λ             FIELD_SERVICE_CHANN1_UNIT
  */
#define     SERVICE_SERVICE_OFF_GETTREND              21003


/**�õ�ָ����˾���ֳ�������š��񶯲��š���ʼʱ��ε���������ֵ��������
  *��������ֶ��룺
  *          ��˾ID      FIELD_SYSTEM_COMPANY
  *	    	 �ֳ���      FIELD_SYSTEM_FACTORY
  *          ����ID      FIELD_SERVICE_PLANTID
  *          ������ͣ�  FIELD_SERVICE_CHANNTYPE
  *          ���ID      FIELD_SERVICE_OFF_CHANN1
  *          ��ʼʱ��    FIELD_SERVICE_OFF_TIMESTART
  *          ��ֹʱ��    FIELD_SERVICE_OFF_TIMEEND
  *����ֵ���ֶ��룺
  *          ����ֵ�ṹ��     FIELD_SERVICE_CHARVALUE_S
  *          ʱ��             FIELD_SERVICE_OFF_TIME
  */
#define    SERVICE_SERVICE_OFF_GETAVIBCHANNTREND      21004

/**�õ�ָ����˾���ֳ���������ID��ʱ��Ρ�ˮƽ���ID�ʹ�ֱ���ID������λ����ʷ���ݣ�ͨ��ѭ�����εõ��������ݺͶ�Ӧʱ�䣬ÿ��ȡ�����ݶ�Ӧ     ʱ�䶼����ͬ��
  *��������ֶ��룺
  *          ��˾ID   FIELD_SYSTEM_COMPANY
  *   	     �ֳ���   FIELD_SYSTEM_FACTORY
  *          ����ID      FIELD_SERVICE_PLANTID
  *          ˮƽ�����񶯲��ID   FIELD_SERVICE_CHANNID_HOR
  *          ��ֱ�����񶯲��ID   FIELD_SERVICE_CHANNID_VER
  *          ���λ������         FIELD_SYSTEM_AXISLOCATION
  *          ��ʼʱ��    FIELD_SERVICE_OFF_TIMESTART
  *          ��ֹʱ��    FIELD_SERVICE_OFF_TIMEEND
  *����ֵ���ֶ��룺
  *          ˮƽ�����񶯲������  FIELD_SERVICE_AXESLOCATION_HOR
  *          ��ֱ�����񶯲������  FIELD_SERVICE_AXESLOCATION_VER
  *          ʱ��ֵ                FIELD_SERVICE_OFF_TIME
  */
#define     SERVICE_SERVICE_OFF_GETAXISLOCATIONTREND  21005


/**�õ�ָ�������񶯲�������ֵ��Ϣ�������޵���Ϣ��ѭ�����εõ������������ݣ�
  *���������
  *          ��˾ID          FIELD_SYSTEM_COMPANY
  *			 �ֳ���          FIELD_SYSTEM_FACTORY
  *          ����ID          FIELD_SERVICE_PLANTID
  *          ���һ          FIELD_SERVICE_OFF_CHANN1
  *          ���һʱ��ֵ    FIELD_SERVICE_OFF_TIME
  *          ��˾ID2         FIELD_SYSTEM_COMPANY2
  *			 �ֳ���2         FIELD_SYSTEM_FACTORY2
  *          ����ID2         FIELD_SERVICE_PLANTID2
  *          ����          FIELD_SERVICE_OFF_CHANN2
  *          ����ʱ��ֵ    FIELD_SERVICE_OFF_TIME2
  *����ֵ���ֶ��룺
  *          ��˾ID          FIELD_SYSTEM_COMPANY
  *			 �ֳ���          FIELD_SYSTEM_FACTORY
  *          ����ID          FIELD_SERVICE_PLANTID
  *          ���ID          FIELD_SERVICE_CHANN1
  *          ������        FIELD_SYSTEM_CHANN_ALIAS
  *          ����ֵ�ṹ��    FIELD_SERVICE_CHARVALUE_S
  *          ת��            FIELD_SERVICE_OFF_REV
  *          ����ֵ          FIELD_SYSTEM_ALARM_LOW
  *          Σ��ֵ          FIELD_SYSTEM_ALARM_HIGH
  *          ��λ            FIELD_SERVICE_CHANN1_UNIT
  */
#define     SERVICE_SERVICE_OFF_GETTWOCHANNDETAILINFO    21006

/**�õ�ָ����ʷʱ�̡������񶯲���ϸ��Ƶ�׷����Ͳ��Ρ�
  *���������
  *          ��˾ID           FIELD_SYSTEM_COMPANY
  *			     �ֳ���           FIELD_SYSTEM_FACTORY
  *          ����ID           FIELD_SERVICE_PLANTID
  *          ���             FIELD_SERVICE_OFF_CHANN1
  *          ��������         FIELD_SERVICE_ZOOM_LINES
  *          ��ʼƵ��         FIELD_SERVICE_ZOOM_STARTFREQ
  *          ��ֹƵ��         FIELD_SERVICE_ZOOM_STOPFREQ
  *          ʱ��             FIELD_SERVICE_OFF_TIME
  *����ֵ���ֶ��룺
  *          ���Ĳ�������   FIELD_SERVICE_OFF_WAVE
  *          �������ݸ���     FIELD_SERVICE_OFF_WAVE_NUM
  *          ����Ƶ������   FIELD_SERVICE_ZOOMSPECTRUM
  *          ��������         FIELD_SERVICE_ZOOM_LINES
  *          ��ʼƵ��         FIELD_SERVICE_ZOOM_STARTFREQ
  *          �񶯲��Ƶ��DF   FIELD_SERVICE_FREQWAVE_DF
  *          ͨƵ����ֵ��     FIELD_SERVICE_TREND_OVERALLCHAR
  *          ״̬             FIELD_SYSTEM_STATUS
  *          ״̬����         FIELD_SYSTEM_STATUS_DISCRIPTION
  */
#define     SERVICE_SERVICE_OFF_GETZOOMSPEC             21007


/**�õ�ָ����˾���ֳ������顢����ʱ���һ�����Ĺ켣�Ĳ������ݡ�
*���������
*          ��˾ID   FIELD_SYSTEM_COMPANY
*			     �ֳ���   FIELD_SYSTEM_FACTORY
*          ����ID               FIELD_SERVICE_PLANTID
*          ˮƽ�����񶯲��ID   FIELD_SERVICE_CHANNID_HOR
*          ��ֱ�����񶯲��ID   FIELD_SERVICE_CHANNID_VER
*          ���λ������         FIELD_SYSTEM_AXISLOCATION
*          �������ݸ���         FIELD_SERVICE_OFF_WAVE_NUM
*          ʱ��                 FIELD_SERVICE_OFF_TIME
*����ֵ���ֶ��룺
*          ��ֱ����������                 FIELD_SERVICE_AXESTRACK_WAVE_VER
*          ��ֱ����Ĳ�������ѹ������ֽ��� FIELD_SERVICE_ZIPWAVE_BYTESNUM
*          ��ֱ��������ֵ�ṹ��             FIELD_SERVICE_CHARVALUE_S2
*          ��ֱ�����㱨��ֵ               FIELD_SYSTEM_ALARM_LOW2
*          ��ֱ������Σ��ֵ               FIELD_SYSTEM_ALARM_HIGH2
*          ��ֱ�����㵥λ                 FIELD_SERVICE_CHANN2_UNIT
*          ��ֱ���������                 FIELD_SYSTEM_CHANN2_ALIAS
*          ˮƽ����������                 FIELD_SERVICE_AXESTRACK_WAVE_HOR
*          ˮƽ����Ĳ�������ѹ������ֽ��� FIELD_SERVICE_ZIPWAVE_BYTESNUM1
*          ˮƽ��������ֵ�ṹ��             FIELD_SERVICE_CHARVALUE_S
*          ˮƽ�����㱨��ֵ               FIELD_SYSTEM_ALARM_LOW
*          ˮƽ������Σ��ֵ               FIELD_SYSTEM_ALARM_HIGH
*          ˮƽ�����㵥λ                 FIELD_SERVICE_CHANN1_UNIT
*          ˮƽ���������                 FIELD_SYSTEM_CHANN_ALIAS
*          ���Ĺ켣��һ���Ĳ������ݸ���     FIELD_SERVICE_AXESTRACK_WAVENUM
*          ָ���������ת��               FIELD_SERVICE_REV
*          ����Ƶ��                         FIELD_SERVICE_SAMPLE_FREQ
*          ת������                       FIELD_SYSTEM_TYPE //0:Ϊ��ʱ��,1Ϊ˳ʱ��
*          ��������                       FIELD_SYSTEM_STATUS//1:Ϊ������,2Ϊ������
*/
#define     SERVICE_SERVICE_OFF_GETAXESTRACK              21008

/**�õ�ָ����˾���ֳ����豸���������񶯲�������ֵ��Ϣ�������޵���Ϣ������ѭ���������ݣ�
  *���������
  *          ��˾ID          FIELD_SYSTEM_COMPANY
  *			     �ֳ���          FIELD_SYSTEM_FACTORY
  *          ����ID          FIELD_SERVICE_PLANTID
  *          ���һʱ��ֵ    FIELD_SERVICE_OFF_TIME
  *          ���buff        FIELD_SERVICE_CHANN_BUFF
  *          ���buff����    FIELD_SERVICE_CHANN_BUFFSIZE
  *          ������        FIELD_SERVICE_CHANN_NUM
  *����ֵ���ֶ��룺
  *          ���ID          FIELD_SERVICE_CHANN1
  *          ������        FIELD_SYSTEM_CHANN_ALIAS
  *          ����ֵ�ṹ��    FIELD_SERVICE_CHARVALUE_S
  *          ת��            FIELD_SERVICE_OFF_REV
  *          ����ֵ          FIELD_SYSTEM_ALARM_LOW
  *          Σ��ֵ          FIELD_SYSTEM_ALARM_HIGH
  *          ��λ            FIELD_SERVICE_CHANN1_UNIT
  */
#define     SERVICE_SERVICE_OFF_GETSPECPLANTCHANNSDETAILINFO  21009

/*!�õ�ָ����㡢ʱ��Ļ���������Ϣ
  *��������ֶ���
  *          ��˾ID          FIELD_SYSTEM_COMPANY
  *			     �ֳ���          FIELD_SYSTEM_FACTORY
  *          ����ID��        FIELD_SERVICE_PLANTID
  *          ������ƣ�      FIELD_SERVICE_OFF_CHANN1
  *          �¼�ID:         FIELD_SYSTEM_EVENT_ID
  *          ����ʱ�䣺      FIELD_SERVICE_OFF_TIME
  *          ��Ӧʱ��ĺ���  FIELD_SERVICE_MICROSECOND
  *����ֵ���ֶ���
  *          ����ֵ��      FIELD_SERVICE_CHARVALUE_S
  *          ��������Buff  FIELD_SERVICE_THRESHOLD_BUFF
  *          ���޵ĸ���    FIELD_SERVICE_CHANN_NUM
  *          ��������      FIELD_SYSTEM_TYPE
  */
#define     SERVICE_SERVICE_OFF_GETSPECVIBCHANNALARMINFO    21010

/*!�õ�ָ����ֹʱ���ָ�������ָ���񶯲�����͵ı�����¼
  *��������ֶ���
  *          ��˾ID   FIELD_SYSTEM_COMPANY
  *    	     �ֳ���   FIELD_SYSTEM_FACTORY
  *          ����ID�� FIELD_SERVICE_PLANTID
  *          ������� FIELD_SERVICE_CHANN1
  *          ��ʼʱ�䣺  FIELD_SERVICE_OFF_TIMESTART
  *          ��ֹʱ�䣺  FIELD_SERVICE_OFF_TIMEEND
  *����ֵ���ֶ��룺
  *          ������ʼʱ��:   FIELD_SERVICE_OFF_TIMESTART
  *          ��������ʱ��:   FIELD_SERVICE_OFF_TIMEEND
  *          �������ͣ�      FIELD_SYSTEM_TYPE
  *          �¼�ID          FIELD_SYSTEM_EVENT_ID
  *          ������������    FIELD_SYSTEM_RESERVE_STRING
  */
#define     SERVICE_OFF_GETVIBCHANNALARMLOG               21011

/**�õ�ָ��ʱ���ָ�����ı�����¼�Ĳ��κ͸�������ֵ�����ڶ������ѭ���õ�
  *��������ֶ���
  *          ��˾ID          FIELD_SYSTEM_COMPANY
  *			 �ֳ���          FIELD_SYSTEM_FACTORY
  *          ����ID��        FIELD_SERVICE_PLANTID
  *          ���buff        FIELD_SERVICE_CHANN_BUFF
  *          ���buff����    FIELD_SERVICE_CHANN_BUFFSIZE
  *          ������        FIELD_SERVICE_CHANN_NUM
  *          �¼�ID:         FIELD_SYSTEM_EVENT_ID
  *          ����ʱ�䣺      FIELD_SERVICE_OFF_TIME
  *          ��Ӧʱ��ĺ���  FIELD_SERVICE_MICROSECOND
  *          �������ݸ���    FIELD_SERVICE_OFF_WAVE_NUM
  *          ����������      FIELD_SERVICE_ZOOM_LINES
  *����ֵ���ֶ��룺
  *          ���ID��        FIELD_SERVICE_OFF_CHANN1
  *          �������ͣ�      FIELD_SYSTEM_TYPE
  *          ����ֵ�ṹ��    FIELD_SERVICE_CHARVALUE_S
  *          ���Σ�          FIELD_SERVICE_OFF_WAVE
  *          Ƶ�ף�          FIELD_SERVICE_OFF_FREQWAVE
  *          Ƶ��DFֵ��      FIELD_SERVICE_OFF_FREQWAVE_DF
  *          ���ε�����      FIELD_SERVICE_OFF_WAVE_NUM
  *          Ƶ�����ݵ���    FIELD_SERVICE_ZOOM_LINES
  *          ת�٣�          FIELD_SERVICE_OFF_REV
  *          �Զ����������BUFF��  FIELD_SERVICE_LEARNPARAM_BUFF
  */
#define    SERVICE_SERVICE_OFF_GETSPECALARMTIMERECORD       21012


/*!�õ�ָ��ʱ�䷶Χ��ָ���������ͣ����¼
  *��������ֶ���
  *          ��˾ID   FIELD_SYSTEM_COMPANY
  *			     �ֳ���   FIELD_SYSTEM_FACTORY
  *          ����ID��    FIELD_SERVICE_PLANTID
  *          ��ʼʱ�䣺  FIELD_SERVICE_OFF_TIMESTART
  *          ��ֹʱ�䣺  FIELD_SERVICE_OFF_TIMEEND
  *����ֵ���ֶ��룺
  *          ��ͣ���¼�ID: FIELD_SYSTEM_EVENT_ID
  *          ��ͣ�����ͣ�  FIELD_SYSTEM_TYPE
  *          ��ʼʱ�䣺    FIELD_SERVICE_OFF_TIMESTART
  *          ��ֹʱ�䣺    FIELD_SERVICE_OFF_TIMEEND
  */
#define    SERVICE_SERVICE_OFF_GETSPECTIMERANGESUD          21013

/*!�õ�ָ����ͣ���¼�ID��ָ����˾���ֳ����顢ָ��������ͣ����ת�١������������ݵ�ʱ�̡���ֵ����λ���С�ͨ��ѭ���õ�����ת�٣�Ȼ�󣬷�   *��ͨ��ת�ٻ򱣴��������ݵ�ʱ�̡�����źͲ���
  *��������ֶ���
  *          ��˾ID      FIELD_SYSTEM_COMPANY
  *			     �ֳ���      FIELD_SYSTEM_FACTORY
  *          ����ID��    FIELD_SERVICE_PLANTID
  *          ���ID��    FIELD_SERVICE_OFF_CHANN1
  *          ��ͣ���¼�ID: FIELD_SYSTEM_EVENT_ID
  *����ֵ���ֶ��룺
  *          ת��:       FIELD_SERVICE_OFF_REV
  *          ʱ��        FIELD_SERVICE_OFF_TIME
  *��Ӧʱ���΢��        FIELD_SERVICE_MICROSECOND
  *          ��λ��      FIELD_SERVICE_OFF_PHASE
  *          ��ֵ��      FIELD_SERVICE_OFF_AMP
  *          ������ֵ�ṹ��    FIELD_SERVICE_CHARVALUE_S
  */
#define    SERVICE_SERVICE_OFF_GETSPECTIMECHANNSUD          21014

/*!�õ�ָ����ͣ���¼�ID��ָ����˾���ֳ������顢ָ������ָ��ת�ٵ���ͣ������ϸ���ݡ�
  *��������ֶ���
  *          ��˾ID        FIELD_SYSTEM_COMPANY
  *			     �ֳ���        FIELD_SYSTEM_FACTORY
  *          ����ID��      FIELD_SERVICE_PLANTID
  *          ���ID��      FIELD_SERVICE_OFF_CHANN1
  *          ��ͣ���¼�ID: FIELD_SYSTEM_EVENT_ID
  *          ת��:         FIELD_SERVICE_OFF_REV
  *          �������ݸ���  FIELD_SERVICE_OFF_WAVE_NUM
  *          ��������      FIELD_SERVICE_ZOOM_LINES
  *����ֵ���ֶ��룺
  *          ��λ��      FIELD_SERVICE_OFF_PHASE
  *          ��ֵ��      FIELD_SERVICE_OFF_AMP
  *          ���Σ�      FIELD_SERVICE_OFF_WAVE
  *          Ƶ�ף�      FIELD_SERVICE_OFF_FREQWAVE
  *          Ƶ��DFֵ��  FIELD_SERVICE_OFF_FREQWAVE_DF
  *          ���ε�����  FIELD_SERVICE_OFF_WAVE_NUM
  *          Ƶ�׵�����  FIELD_SERVICE_ZOOM_LINES
  *          ������ֵ�ṹ��    FIELD_SERVICE_CHARVALUE_S
  */
#define    SERVICE_SERVICE_OFF_GETSPECCHANNREVSUD           21015

/*!�õ�ָ�����顢ָ������ָ��ʱ�䱣����ͣ������ϸ���ݡ�
*��������ֶ���
*          ��˾ID      FIELD_SYSTEM_COMPANY
*			     �ֳ���      FIELD_SYSTEM_FACTORY
*          ����ID��    FIELD_SERVICE_PLANTID
*          ���ID��    FIELD_SERVICE_OFF_CHANN1
*  ��ͣ�����ݱ���ʱ��: FIELD_SERVICE_OFF_TIME
*      ��Ӧʱ���΢��  FIELD_SERVICE_MICROSECOND
*          ��ͣ���¼�ID: FIELD_SYSTEM_EVENT_ID
*          �������ݸ���  FIELD_SERVICE_OFF_WAVE_NUM
*          ��������    FIELD_SERVICE_ZOOM_LINES
*����ֵ���ֶ��룺
*          ��λ��      FIELD_SERVICE_OFF_PHASE
*          ��ֵ��      FIELD_SERVICE_OFF_AMP
*          ���Σ�      FIELD_SERVICE_OFF_WAVE
*          Ƶ�ף�      FIELD_SERVICE_OFF_FREQWAVE
*          Ƶ��DFֵ��  FIELD_SERVICE_OFF_FREQWAVE_DF
*          ���ε�����  FIELD_SERVICE_OFF_WAVE_NUM
*          ת��:       FIELD_SERVICE_OFF_REV
*          Ƶ�׵�����  FIELD_SERVICE_ZOOM_LINES
*          ������ֵ�ṹ��    FIELD_SERVICE_CHARVALUE_S
*/
#define    SERVICE_SERVICE_OFF_GETSPECCHANNSAVETIMESUD      21016

/**�õ�ָ����˾���ֳ������顢ʱ��Ρ��������񶯲�������������ֵ�������ݣ�ͨ��ѭ�����εõ������������ݺͶ�Ӧʱ�䣬ÿ��ȡ�����ݶ�Ӧʱ�䶼����ͬ��
  *��������ֶ��룺
  *          ��˾ID        FIELD_SYSTEM_COMPANY
  *			     �ֳ���        FIELD_SYSTEM_FACTORY
  *          ����ID        FIELD_SERVICE_PLANTID
  *          ������ͣ�    FIELD_SERVICE_CHANNTYPE
  *          ���buff      FIELD_SERVICE_CHANN_BUFF
  *          ���buff����  FIELD_SERVICE_CHANN_BUFFSIZE
  *          ������      FIELD_SERVICE_CHANN_NUM
  *          ��ʼʱ��      FIELD_SERVICE_OFF_TIMESTART
  *          ��ֹʱ��      FIELD_SERVICE_OFF_TIMEEND
  *����ֵ���ֶ��룺
  *          �����������ֵBuff   FIELD_SERVICE_CHARVALUE_SBUFF
  *          ������             FIELD_SERVICE_CHANN_NUM
  *          ʱ��ֵ               FIELD_SERVICE_OFF_TIME
  *          ת��Buff             FIELD_SERVICE_REV_BUFF
  */
#define     SERVICE_SERVICE_OFF_GETVIBCHANNSTREND         21017

/**�õ���ǰʱ�������һ���������͵��������ݡ�ָ����˾���ֳ������顢�������񶯲����߶�̬������������ֵ�������ݣ�
  *ͨ��ѭ�����εõ������������ݺͶ�Ӧʱ�䣬ÿ��ȡ�����ݶ�Ӧʱ�䶼����ͬ��
  *��������ֶ��룺
  *          ��������      FIELD_SERVICE_OFF_TRENDTYPE
  *          ��˾ID        FIELD_SYSTEM_COMPANY
  *			     �ֳ���        FIELD_SYSTEM_FACTORY
  *          ����ID        FIELD_SERVICE_PLANTID
  *          ������ͣ�    FIELD_SERVICE_CHANNTYPE
  *          ���buff      FIELD_SERVICE_CHANN_BUFF
  *          ���buff����  FIELD_SERVICE_CHANN_BUFFSIZE
  *          ������      FIELD_SERVICE_CHANN_NUM
  *����ֵ���ֶ��룺
  *          �����������ֵBuff   FIELD_SERVICE_CHARVALUE_SBUFF
  *          ������             FIELD_SERVICE_CHANN_NUM
  *          ʱ��ֵ               FIELD_SERVICE_OFF_TIME
  *          ת��Buff             FIELD_SERVICE_REV_BUFF
  */
#define     SERVICE_SERVICE_OFF_GETCURRVIBCHANNSTREND      21018

/**�õ�ָ�������񶯲�����ʷ���Σ�ѭ�����εõ������������ݣ�
  *���������
  *          ��˾ID          FIELD_SYSTEM_COMPANY
  *			     �ֳ���          FIELD_SYSTEM_FACTORY
  *          ����ID          FIELD_SERVICE_PLANTID
  *          ���һ          FIELD_SERVICE_OFF_CHANN1
  *          ���һʱ��ֵ    FIELD_SERVICE_OFF_TIME
  *          ��˾ID2         FIELD_SYSTEM_COMPANY2
  *			     �ֳ���2         FIELD_SYSTEM_FACTORY2
  *          ����ID2         FIELD_SERVICE_PLANTID2
  *          ����          FIELD_SERVICE_OFF_CHANN2
  *          ����ʱ��ֵ    FIELD_SERVICE_OFF_TIME2
  *          �������ݸ���    FIELD_SERVICE_OFF_WAVE_NUM
  *          ��������        FIELD_SERVICE_OFF_FREQANALYSIS_LINES
  *����ֵ���ֶ��룺
  *          ��˾ID          FIELD_SYSTEM_COMPANY
  *			     �ֳ���          FIELD_SYSTEM_FACTORY
  *          ����ID          FIELD_SERVICE_PLANTID
  *          ���ID          FIELD_SERVICE_CHANN1
  *          ��������        FIELD_SERVICE_OFF_WAVE
  *          Ƶ������        FIELD_SERVICE_OFF_FREQWAVE
  *          �������ݸ���    FIELD_SERVICE_OFF_WAVE_NUM
  *          Ƶ��DF          FIELD_SERVICE_OFF_FREQWAVE_DF
  *          Ƶ�����ݵ���    FIELD_SERVICE_OFF_FREQWAVE_NUM
  *          ����ֵ�ṹ��    FIELD_SERVICE_CHARVALUE_S
  *          ����ֵ          FIELD_SYSTEM_ALARM_LOW
  *          Σ��ֵ          FIELD_SYSTEM_ALARM_HIGH
  *          ��λ            FIELD_SERVICE_CHANN1_UNIT
  *          ת��            FIELD_SERVICE_OFF_REV
  */
#define     SERVICE_SERVICE_OFF_GETTWOCHANNDATA           21019

/**�õ�ָ����˾���ֳ����豸�����������̲���ֵ��Ϣ�������޵���Ϣ������ѭ���������ݣ�
  *���������
  *          ��˾ID          FIELD_SYSTEM_COMPANY
  *			     �ֳ���          FIELD_SYSTEM_FACTORY
  *          ����ID          FIELD_SERVICE_PLANTID
  *          ���ʱ��ֵ      FIELD_SERVICE_OFF_TIME
  *          ���buff        FIELD_SERVICE_CHANN_BUFF
  *          ���buff����    FIELD_SERVICE_CHANN_BUFFSIZE
  *          ������        FIELD_SERVICE_CHANN_NUM
  *����ֵ���ֶ��룺
  *          ���ID          FIELD_SERVICE_CHANN1
  *          ������        FIELD_SYSTEM_CHANN_ALIAS
  *          ����ֵ          FIELD_SERVICE_TREND_PROCESS
  *          ת��            FIELD_SERVICE_OFF_REV
  *          ������          FIELD_SYSTEM_ALARM_LOW
  *          Σ����          FIELD_SYSTEM_ALARM_HIGH
  *          ��λ            FIELD_SERVICE_CHANN1_UNIT
  */
#define     SERVICE_SERVICE_OFF_GETSPECPLANTPROCCHANNSDETAILINFO   21020

/*!�õ�ָ����˾���ֳ������顢��������ָ����ͣ���¼����������ݡ�
  *��������ֶ���
  *          ��˾ID          FIELD_SYSTEM_COMPANY
  *			     �ֳ���          FIELD_SYSTEM_FACTORY
  *          ����ID��        FIELD_SERVICE_PLANTID
  *          ����ֵ����      FIELD_SERVICE_TREND_CHARTYPE
  *          ���buff        FIELD_SERVICE_CHANN_BUFF
  *          ���buff����    FIELD_SERVICE_CHANN_BUFFSIZE
  *          ������        FIELD_SERVICE_CHANN_NUM
  *          ��ͣ���¼�ID    FIELD_SYSTEM_EVENT_ID
  *����ֵ���ֶ��룺
  *          �����������ֵBuff   FIELD_SERVICE_TREND_VALUE_BUFF
  *          ������             FIELD_SERVICE_CHANN_NUM
  *          ʱ��ֵ               FIELD_SERVICE_OFF_TIME
  *          ��Ӧʱ���΢��       FIELD_SERVICE_MICROSECOND
  *          ת��:                FIELD_SERVICE_OFF_REV
  *          ת��2��              FIELD_SERVICE_OFF_REV2
  */
#define    SERVICE_SERVICE_OFF_GETSPECEVENTCHANNSSUDTREND       21021

/*!�õ�ָ����˾���ֳ������顢�¼���������㡢����ʱ�����ϸ����
  *��������ֶ���
  *          ��˾ID          FIELD_SYSTEM_COMPANY
  *			     �ֳ���          FIELD_SYSTEM_FACTORY
  *          ����ID��        FIELD_SERVICE_PLANTID
  *          ���buff        FIELD_SERVICE_CHANN_BUFF
  *          ���buff����    FIELD_SERVICE_CHANN_BUFFSIZE
  *          ������        FIELD_SERVICE_CHANN_NUM
  *          ��ͣ���¼�ID    FIELD_SYSTEM_EVENT_ID
  *    ��ͣ�����ݱ���ʱ��    FIELD_SERVICE_OFF_TIME
  *          ��Ӧʱ���΢��  FIELD_SERVICE_MICROSECOND
	*����ֵ���ֶ��룺
	*          ���ID               FIELD_SERVICE_CHANN1
	*          ������             FIELD_SYSTEM_CHANN_ALIAS
  *          �������ֵ�ṹ��     FIELD_SERVICE_CHARVALUE_S
  *          ת��:                FIELD_SERVICE_OFF_REV
  *          �ת�٣�           FIELD_SYSTEM_PLANT_REV
  *          ��һ�ٽ�ת��         FIELD_SERVICE_REV
  *          �ڶ��ٽ�ת��         FIELD_SERVICE_REV2
  *          ������               FIELD_SYSTEM_ALARM_LOW
  *          Σ����               FIELD_SYSTEM_ALARM_HIGH
  *          ��λ                 FIELD_SERVICE_CHANN1_UNIT
  */
#define    SERVICE_SERVICE_OFF_GETSPECEVENTTIMECHANNSSUDDETAILINFO    21022

/**�õ�ָ����˾���ֳ����豸���������񶯲��ı����޵���Ϣ������ѭ���������ݣ�
  *���������
  *          ��˾ID          FIELD_SYSTEM_COMPANY
  *			     �ֳ���          FIELD_SYSTEM_FACTORY
  *          ����ID          FIELD_SERVICE_PLANTID
  *          ���buff        FIELD_SERVICE_CHANN_BUFF
  *          ���buff����    FIELD_SERVICE_CHANN_BUFFSIZE
  *          ������        FIELD_SERVICE_CHANN_NUM
  *����ֵ���ֶ��룺
  *          ���ID          FIELD_SERVICE_CHANN1
  *          ������        FIELD_SYSTEM_CHANN_ALIAS
  *          ����ֵ          FIELD_SYSTEM_ALARM_LOW
  *          Σ��ֵ          FIELD_SYSTEM_ALARM_HIGH
  *          ��λ            FIELD_SERVICE_CHANN1_UNIT
  */
#define     SERVICE_SERVICE_OFF_GETSPECPLANTCHANNSINFO      21023

/**�õ�ָ����˾���ֳ����豸���������񶯲��ı����޵���Ϣ������ѭ���������ݣ�
  *���������
  *          ��˾ID          FIELD_SYSTEM_COMPANY
  *			     �ֳ���          FIELD_SYSTEM_FACTORY
  *          ����ID          FIELD_SERVICE_PLANTID
  *          ���buff        FIELD_SERVICE_CHANN_BUFF
  *          ���buff����    FIELD_SERVICE_CHANN_BUFFSIZE
  *          ������        FIELD_SERVICE_CHANN_NUM
  *          �¼�ID:         FIELD_SYSTEM_EVENT_ID
  *����ֵ���ֶ��룺
  *          �����������ֵBuff  FIELD_SERVICE_CHARVALUE_SBUFF
  *          ��Ӧ��������Buff    FIELD_SERVICE_TYPE_BUFF
  *          ������            FIELD_SERVICE_CHANN_NUM
  *          ʱ��ֵ              FIELD_SERVICE_OFF_TIME
  *          ��Ӧʱ���΢��      FIELD_SERVICE_MICROSECOND
  */
#define     SERVICE_SERVICE_OFF_GETVIBCHANNALARMTREND       21024

/**�õ�ָ����˾���ֳ������顢���ͱ����¼�ID������λ�����ơ�
*���������
*          ��˾ID   FIELD_SYSTEM_COMPANY
*			     �ֳ���   FIELD_SYSTEM_FACTORY
*          ����ID               FIELD_SERVICE_PLANTID
*          ˮƽ�����񶯲��ID   FIELD_SERVICE_CHANNID_HOR
*          ��ֱ�����񶯲��ID   FIELD_SERVICE_CHANNID_VER
*          ���λ������         FIELD_SYSTEM_AXISLOCATION
*          �¼�ID:              FIELD_SYSTEM_EVENT_ID
*����ֵ���ֶ��룺
*          ת��:         FIELD_SERVICE_OFF_REV
*          ˮƽ����ֵ      FIELD_SERVICE_AXESLOCATION_HOR
*          ˮƽ����ֱ����  FIELD_SERVICE_TREND_DC
*          ˮƽ�����϶��ѹ FIELD_SERVICE_TREND_GAP
*          ��ֱ����ֵ      FIELD_SERVICE_AXESLOCATION_VER
*          ��ֱ����ֱ����  FIELD_SERVICE_TREND_DC2
*          ��ֱ�����϶��ѹ FIELD_SERVICE_TREND_GAP2
*          ��������      FIELD_SYSTEM_TYPE
*          ʱ��         FIELD_SERVICE_OFF_TIME
*          �������ʾ     FIELD_SYSTEM_STATUS
*/
#define     SERVICE_SERVICE_OFF_GETAXESLOCATIONALARMTREND       21025

/**�õ�ָ�������¼��ı������ݱ���Ŀ�ʼ��ֹʱ��
  *          ��˾ID   FIELD_SYSTEM_COMPANY
  *			     �ֳ���   FIELD_SYSTEM_FACTORY
  *          ����ID               FIELD_SERVICE_PLANTID
  *          �¼�ID:              FIELD_SYSTEM_EVENT_ID
  *����ֵ���ֶ��룺
  *          ��ʼʱ�䣺    FIELD_SERVICE_OFF_TIMESTART
  *          ��ֹʱ�䣺    FIELD_SERVICE_OFF_TIMEEND
  */
#define SERVICE_SERVICE_OFF_GETALARMDATATIMERANGE               21026

/**�õ�ָ�������¼��ı������ݱ���Ŀ�ʼ��ֹʱ��
  *          ��˾ID   FIELD_SYSTEM_COMPANY
  *			     �ֳ���   FIELD_SYSTEM_FACTORY
  *          ����ID               FIELD_SERVICE_PLANTID
  *          ˮƽ�����񶯲��ID   FIELD_SERVICE_CHANNID_HOR
  *          ��ֱ�����񶯲��ID   FIELD_SERVICE_CHANNID_VER
  *          ���λ������         FIELD_SYSTEM_AXISLOCATION
  *          ʱ��                 FIELD_SERVICE_OFF_TIME
  *          �¼�ID:              FIELD_SYSTEM_EVENT_ID
  *����ֵ���ֶ��룺
  *          ת��:         FIELD_SERVICE_OFF_REV
  *          ˮƽ����ֵ      FIELD_SERVICE_AXESLOCATION_HOR
  *          ˮƽ����ֱ����  FIELD_SERVICE_TREND_DC
  *          ˮƽ�����϶��ѹ FIELD_SERVICE_TREND_GAP
  *          ��ֱ����ֵ      FIELD_SERVICE_AXESLOCATION_VER
  *          ��ֱ����ֱ����  FIELD_SERVICE_TREND_DC2
  *          ��ֱ�����϶��ѹ FIELD_SERVICE_TREND_GAP2
  *          ����������      FIELD_SYSTEM_TYPE
  */
#define SERVICE_SERVICE_OFF_GETAXESLOCATIONALARMDATA            21027

/**�õ�ָ����˾���ֳ������顢�񶯲�㡢�����¼�ID������ϸ�������ơ�
*���������
*          ��˾ID   FIELD_SYSTEM_COMPANY
*			     �ֳ���   FIELD_SYSTEM_FACTORY
*          ����ID               FIELD_SERVICE_PLANTID
*          ���ID               FIELD_SERVICE_CHANN1
*          �¼�ID:              FIELD_SYSTEM_EVENT_ID
*����ֵ���ֶ��룺
*          ת��:               FIELD_SERVICE_OFF_REV
*          �������ֵ          FIELD_SERVICE_CHARVALUE_S
*          ʱ��ֵ              FIELD_SERVICE_OFF_TIME
*          ��������            FIELD_SYSTEM_TYPE
*          ��Ӧʱ���΢��      FIELD_SERVICE_MICROSECOND
*          �������Buff        FIELD_SERVICE_THRESHOLD_BUFF
*          ���޸���            FIELD_SERVICE_LEN
*          �¼�����            FIELD_SYSTEM_EVENT_TYPE
*          �������ʾ          FIELD_SYSTEM_STATUS
*/
#define     SERVICE_SERVICE_OFF_GETVIBALARMINFOTREND          21028

/**�õ�ָ����˾���ֳ������顢��λ�Ʋ�㡢�����¼�ID���������ơ�
*���������
*          ��˾ID   FIELD_SYSTEM_COMPANY
*			     �ֳ���   FIELD_SYSTEM_FACTORY
*          ����ID               FIELD_SERVICE_PLANTID
*          ���ID               FIELD_SERVICE_CHANN1
*          �¼�ID:              FIELD_SYSTEM_EVENT_ID
*����ֵ���ֶ��룺
*          ת��:               FIELD_SERVICE_OFF_REV
*          �������ֵ          FIELD_SERVICE_TREND_AXISDISPLACE
*          ʱ��ֵ              FIELD_SERVICE_OFF_TIME
*          �������            FIELD_SERVICE_THRESHOLD
*          ��������            FIELD_SYSTEM_TYPE
*          �������ʾ          FIELD_SYSTEM_STATUS
*/
#define     SERVICE_SERVICE_OFF_GETAXISDISPLACEALARMTREND      21029

/**�õ�ָ����˾���ֳ������顢��������㡢�����¼�ID���������ơ�
*���������
*          ��˾ID   FIELD_SYSTEM_COMPANY
*			     �ֳ���   FIELD_SYSTEM_FACTORY
*          ����ID               FIELD_SERVICE_PLANTID
*          ���ID               FIELD_SERVICE_CHANN1
*          �¼�ID:              FIELD_SYSTEM_EVENT_ID
*����ֵ���ֶ��룺
*          ת��:               FIELD_SERVICE_OFF_REV
*          ���ֵ              FIELD_SERVICE_TREND_PROCESS
*          ʱ��ֵ              FIELD_SERVICE_OFF_TIME
*          �������            FIELD_SERVICE_THRESHOLD
*          �������ʾ          FIELD_SYSTEM_STATUS
*/
#define     SERVICE_SERVICE_OFF_GETPROCALARMTREND           21030

/**�õ�ָ����˾���ֳ������顢��������㡢�����¼�ID��ʱ������ݡ�
*���������
*          ��˾ID   FIELD_SYSTEM_COMPANY
*			     �ֳ���   FIELD_SYSTEM_FACTORY
*          ����ID               FIELD_SERVICE_PLANTID
*          ���ID               FIELD_SERVICE_CHANN1
*          �¼�ID:              FIELD_SYSTEM_EVENT_ID
*          ʱ��ֵ              FIELD_SERVICE_OFF_TIME
*����ֵ���ֶ��룺
*          ת��:               FIELD_SERVICE_OFF_REV
*          ���ֵ              FIELD_SERVICE_TREND_PROCESS
*/
#define     SERVICE_SERVICE_OFF_GETPROCALARMDATA            21031

/**�õ�ָ����˾���ֳ������顢��㡢�����¼�ID�����Ʊ������ݡ�
*���������
*          ��˾ID   FIELD_SYSTEM_COMPANY
*			     �ֳ���   FIELD_SYSTEM_FACTORY
*          ����ID               FIELD_SERVICE_PLANTID
*          ���ID               FIELD_SERVICE_CHANN1
*          �¼�ID:              FIELD_SYSTEM_EVENT_ID
*����ֵ���ֶ��룺
*          ����ֵBuff          FIELD_SERVICE_CHARVALUE_SBUFF
*          ����Buff����        FIELD_SERVICE_TIMEWAVE_NUM
*          �������Buff        FIELD_SERVICE_THRESHOLD_BUFF
*          ���޸���            FIELD_SERVICE_LEN
*          ��������            FIELD_SYSTEM_TYPE
*          ת��:               FIELD_SERVICE_OFF_REV
*/
#define     SERVICE_SERVICE_OFF_GETTRENDALARMDATA        21032

/**�õ�ָ����˾���ֳ������顢��λ�Ʋ�㡢�����¼�ID��ʱ�����ϸ���ݡ�
*���������
*          ��˾ID   FIELD_SYSTEM_COMPANY
*			     �ֳ���   FIELD_SYSTEM_FACTORY
*          ����ID               FIELD_SERVICE_PLANTID
*          ���ID               FIELD_SERVICE_CHANN1
*          �¼�ID:              FIELD_SYSTEM_EVENT_ID
*          ʱ��ֵ              FIELD_SERVICE_OFF_TIME
*����ֵ���ֶ��룺
*          ת��:               FIELD_SERVICE_OFF_REV
*          �������ֵ          FIELD_SERVICE_TREND_AXISDISPLACE
*          ֱ����              FIELD_SERVICE_TREND_DC
*          ��϶��ѹ            FIELD_SERVICE_TREND_GAP
*          ��������            FIELD_SYSTEM_TYPE
*/
#define     SERVICE_SERVICE_OFF_GETAXISDISPLACEALARMDATA    21033

/**�õ�ָ��ʱ���ָ�����ı�����¼�ĸ�������ֵ�����ڶ������ѭ���õ�
  *��������ֶ���
  *          ��˾ID          FIELD_SYSTEM_COMPANY
  *			     �ֳ���          FIELD_SYSTEM_FACTORY
  *          ����ID��        FIELD_SERVICE_PLANTID
  *          ���buff        FIELD_SERVICE_CHANN_BUFF
  *          ���buff����    FIELD_SERVICE_CHANN_BUFFSIZE
  *          ������        FIELD_SERVICE_CHANN_NUM
  *          �¼�ID:         FIELD_SYSTEM_EVENT_ID
  *          ����ʱ�䣺      FIELD_SERVICE_OFF_TIME
  *          ��Ӧʱ��ĺ���  FIELD_SERVICE_MICROSECOND
  *����ֵ���ֶ��룺
  *          ���ID��        FIELD_SERVICE_OFF_CHANN1
  *          ������        FIELD_SYSTEM_CHANN_ALIAS
  *          �������ͣ�      FIELD_SYSTEM_TYPE
  *          ����ֵ�ṹ��    FIELD_SERVICE_CHARVALUE_S
  *          ת�٣�          FIELD_SERVICE_OFF_REV
  *          ������������    FIELD_SYSTEM_RESERVE_STRING
   *         ����ֵ          FIELD_SYSTEM_ALARM_LOW
  *          Σ��ֵ          FIELD_SYSTEM_ALARM_HIGH
  */
#define    SERVICE_SERVICE_OFF_GETSPECALARMTIMERECORDCHARVALUE  21034


/**�õ�ָ����ʷʱ�̡�����ʾ��ͼ���Ĳ��Ρ�
  *�������ֵ����˾ID             FIELD_SYSTEM_COMPANY
  *		     �ֳ���            FIELD_SYSTEM_FACTORY
  *            ����ID             FIELD_SERVICE_PLANTID
  *            ���buff           FIELD_SERVICE_CHANN_BUFF
  *            ���buff����       FIELD_SERVICE_CHANN_BUFFSIZE
  *            ������           FIELD_SERVICE_CHANN_NUM
  *            ʾ��ͼ����         FIELD_SYSTEM_TYPE       P-V, P-a, P-t
  *            ʱ��               FIELD_SERVICE_OFF_TIME
  *            �������ݸ���      FIELD_SERVICE_OFF_WAVE_NUM
  *����ֵ���ֶ��룺
  *          ���Ĳ�������   FIELD_SERVICE_OFF_WAVE
  *          �������ݸ���     FIELD_SERVICE_OFF_WAVE_NUM
  *          ����X������    FIELD_SERVICE_ZOOMSPECTRUM
  *          ����ֵ�ṹ��     FIELD_SERVICE_CHARVALUE_S
  *          ����ֵ           FIELD_SYSTEM_ALARM_LOW
  *          Σ��ֵ           FIELD_SYSTEM_ALARM_HIGH
  *          ����Ƶ��        FIELD_SERVICE_SAMPLE_FREQ
 *          ��λ             FIELD_SERVICE_CHANN1_UNIT
 *          ������         FIELD_SYSTEM_CHANN_ALIAS
  *          ת��             FIELD_SERVICE_REV
  *            ������������λ��                      FIELD_SERVICE_ANGLEPARAM1
  *            �������ر���λ��                      FIELD_SERVICE_ANGLEPARAM2
  *            ������������λ��                      FIELD_SERVICE_ANGLEPARAM3
  *            �������ر���λ��                      FIELD_SERVICE_ANGLEPARAM4
  */
#define     SERVICE_SERVICE_OFF_GETPVDATA                   21035

/**�õ�ָ����ʷʱ�̡���������˳��������Ĳ��κ�Ƶ�ס�
  *���������
  *          ��˾ID           FIELD_SYSTEM_COMPANY
  *			     �ֳ���           FIELD_SYSTEM_FACTORY
  *          ����ID           FIELD_SERVICE_PLANTID
  *          ���             FIELD_SERVICE_OFF_CHANN1
  *          ʱ��             FIELD_SERVICE_OFF_TIME
  *          �������ݸ���    FIELD_SERVICE_OFF_WAVE_NUM
  *����ֵ���ֶ��룺
  *          ���Ĳ�������   FIELD_SERVICE_OFF_WAVE
  *          Ƶ������         FIELD_SERVICE_OFF_FREQWAVE
  *          �������ݸ���     FIELD_SERVICE_OFF_WAVE_NUM
  *          Ƶ��DF           FIELD_SERVICE_OFF_FREQWAVE_DF
  *          Ƶ�����ݵ���     FIELD_SERVICE_OFF_FREQWAVE_NUM
  *          ����ֵ�ṹ��     FIELD_SERVICE_CHARVALUE_S
  *          ����ֵ           FIELD_SYSTEM_ALARM_LOW
  *          Σ��ֵ           FIELD_SYSTEM_ALARM_HIGH
  *          ������         FIELD_SYSTEM_CHANN_ALIAS
  *          ��λ             FIELD_SERVICE_CHANN1_UNIT
  *          ת��             FIELD_SERVICE_REV
  *          ������������λ��                      FIELD_SERVICE_ANGLEPARAM1
  *          �������ر���λ��                      FIELD_SERVICE_ANGLEPARAM2
  *          ������������λ��                      FIELD_SERVICE_ANGLEPARAM3
  *          �������ر���λ��                      FIELD_SERVICE_ANGLEPARAM4
  *          ��״���α�������                      FIELD_SERVICE_ALARM_LOW
  *          ��״���α���������                    FIELD_SERVICE_ALARM_HIGH
  *          �����ʼ����                          FIELD_SERVICE_STARTINDEX
  *          ����������                          FIELD_SERVICE_ENDINDEX
  *          �Զ����������BUFF                    FIELD_SERVICE_LEARNPARAM_BUFF
  */
#define     SERVICE_SERVICE_OFF_GETRODSINKDATA              21036

/**��ȡָ�������̬ѹ����㡢�����˳�������㡢�񶯲�㡣��ȡ��ָ��ʱ�䲨�κ���������
*������Ϊ�վͲ��᷵�ض�Ӧ������
*�������ֵ��
*            ��˾ID                     FIELD_SYSTEM_COMPANY
*			 �ֳ���                     FIELD_SYSTEM_FACTORY
*            ����ID                     FIELD_SERVICE_PLANTID
*            �񶯲��buff               FIELD_SERVICE_CHANN_BUFF
*            �񶯲��buff����           FIELD_SERVICE_CHANN_BUFFSIZE
*            �񶯲�����               FIELD_SERVICE_CHANN_NUM
*            ��̬���buff               FIELD_SERVICE_CHANN_BUFF2
*            ��̬���buff����           FIELD_SERVICE_CHANN_BUFFSIZE2
*            ��̬������               FIELD_SERVICE_CHANN_NUM2
*            �����˳��������buff       FIELD_SERVICE_CHANN_BUFF3
*            �����˳��������buff����   FIELD_SERVICE_CHANN_BUFFSIZE3
*            �����˳�����������       FIELD_SERVICE_CHANN_NUM3
*            ʱ��                       FIELD_SERVICE_OFF_TIME
*            �������ݸ���               FIELD_SERVICE_OFF_WAVE_NUM
*�����ֶΣ�
*            �������ݵĵ���               FIELD_SERVICE_TIMEWAVE_NUM
*            ����Ƶ��                     FIELD_SERVICE_SAMPLE_FREQ
*            �������                     FIELD_SERVICE_CHANN1
*            ��㲨��                     FIELD_SERVICE_TIMEWAVE1
*            �������ֵ                   FIELD_SERVICE_CHARVALUE_S
*            ������                       FIELD_SERVICE_FREQWAVE2
*            ת��                         FIELD_SERVICE_OFF_REV
*            ������������λ��             FIELD_SERVICE_ANGLEPARAM1
*            �������ر���λ��             FIELD_SERVICE_ANGLEPARAM2
*            ������������λ��             FIELD_SERVICE_ANGLEPARAM3
*            �������ر���λ��             FIELD_SERVICE_ANGLEPARAM4
  */
#define   SERVICE_SERVICE_OFF_GETRCMULTIPARAMDATA           21037

/**��ʷ��òͼ���õ�ָ��ʱ�䡢ָ���������в������
*�������ֵ��
*            ��˾ID         FIELD_SYSTEM_COMPANY
*	         �ֳ���         FIELD_SYSTEM_FACTORY
*            ����ֵ����     FIELD_SERVICE_TREND_CHARTYPE
*            �豸��buff     FIELD_SERVICE_CHANN_BUFF
*            �豸��buff���� FIELD_SERVICE_CHANN_BUFFSIZE
*            �豸�Ÿ���     FIELD_SERVICE_CHANN_NUM
*            ʱ��ֵ         FIELD_SERVICE_OFF_TIME
*����ֵ���ֶ��룺
*            �豸ID         FIELD_SERVICE_PLANTID
*            ���ID         FIELD_SERVICE_CHANN1
*            ���ֵ         FIELD_SERVICE_CHANN1VALUE
*            ��㵥λ       FIELD_SERVICE_CHANN1_UNIT
*            ��������б�   FIELD_SERVICE_CHANN1_LIST
*            ����״̬     FIELD_SERVICE_CHANN1_STATUS
*            �������ֵ     FIELD_SERVICE_CHARVALUE_S
*            �������       FIELD_SERVICE_CHANNTYPE
*            ת��1          FIELD_SERVICE_REV
*            ת��2          FIELD_SERVICE_REV2
*            ת��3          FIELD_SERVICE_REV3
*            ת��4          FIELD_SERVICE_REV4
*            ת��5          FIELD_SERVICE_REV5
*/
#define     SERVICE_SERVICE_OFF_GETSPECTIMEALLCHANNVALUE    21038

/**�õ�ָ����˾���ֳ������顢���,ָ����ͣ���¼���ʱ���һ���ᴿ���Ĺ켣�Ĳ������ݡ�
*���������
*          ��˾ID               FIELD_SYSTEM_COMPANY
*          �ֳ���               FIELD_SYSTEM_FACTORY
*          ����ID               FIELD_SERVICE_PLANTID
*          ˮƽ�����񶯲��ID   FIELD_SERVICE_CHANNID_HOR
*          ��ֱ�����񶯲��ID   FIELD_SERVICE_CHANNID_VER
*          ���λ������         FIELD_SYSTEM_AXISLOCATION
*          �������ݸ���         FIELD_SERVICE_OFF_WAVE_NUM
*          ��ͣ���¼�ID         FIELD_SYSTEM_EVENT_ID
*          ת��                 FIELD_SERVICE_OFF_REV
*����ֵ���ֶ��룺
*          ��ֱ���������������Ƶ��       FIELD_SERVICE_VERFREQ
*          ��ֱ��������������ķ�ֵ       FIELD_SERVICE_VERAMP
*          ��ֱ�����������������λ       FIELD_SERVICE_VERPHASE
*          ˮƽ���������������Ƶ��       FIELD_SERVICE_HORFREQ
*          ˮƽ��������������ķ�ֵ       FIELD_SERVICE_HORAMP
*          ˮƽ�����������������λ       FIELD_SERVICE_HORPHASE
*          ת������                     FIELD_SYSTEM_TYPE //0:Ϊ��ʱ��,1Ϊ˳ʱ��
*          ��������                     FIELD_SYSTEM_STATUS//1:Ϊ������,2Ϊ������
*          ת��                           FIELD_SERVICE_OFF_REV
*          ˮƽ��������ֵ�ṹ��           FIELD_SERVICE_CHARVALUE_S
*          ��ֱ��������ֵ�ṹ��           FIELD_SERVICE_CHARVALUE_S2
*/
#define     SERVICE_SERVICE_OFF_GETSUDPURIFYAXESTRACK           21039

/**����ʽϵͳ����Ӧ�����������ܣ��õ�ָ������ָ������ʱ�䡢ָ���׺ŵ�Ӧ�����κ��񶯲�㲨��
*���������
*            ��˾ID        ������    FIELD_SYSTEM_COMPANY
*		     �ֳ���          ������  FIELD_SYSTEM_FACTORY
*            ����ID          ������  FIELD_SERVICE_PLANTID
*            ���׺�                  FIELD_SERVICE_CYLINDERNO
*            �¼�ID                  FIELD_SYSTEM_EVENT_ID
*            ����ʱ��                FIELD_SERVICE_OFF_TIME
*����ֵ���ֶ��룺
*            ����Ӧ���������ݡ�������FIELD_SERVICE_TIMEWAVE1
*            ����Ӧ���������ݡ�������FIELD_SERVICE_TIMEWAVE2
*            ������Ӧ���������ݡ�����FIELD_SERVICE_FREQWAVE1
*            �������ݸ���   �������� FIELD_SERVICE_TIMEWAVE_NUM
*		         ����ֵ�ṹ��		         FIELD_SERVICE_CHARVALUE_S
*		         ����ֵ�ṹ��2		       FIELD_SERVICE_CHARVALUE_S2
*		         �����				   				 FIELD_SYSTEM_CHANN
*		         �����2				   			 FIELD_SYSTEM_CHANN2
*		   		   ���1�ǶȲ���1		   FIELD_SERVICE_ANGLEPARAM1
*		         ���1�ǶȲ���2		   FIELD_SERVICE_ANGLEPARAM2
*		         ���1�ǶȲ���3		   FIELD_SERVICE_ANGLEPARAM3
*		         ���1�ǶȲ���4		   FIELD_SERVICE_ANGLEPARAM4
*		         ���2�ǶȲ���1		   FIELD_SERVICE_ANGLEPARAM5
*		         ���2�ǶȲ���2		   FIELD_SERVICE_ANGLEPARAM6
*		         ���2�ǶȲ���3		   FIELD_SERVICE_ANGLEPARAM7
*		         ���2�ǶȲ���4		   FIELD_SERVICE_ANGLEPARAM8
*			 			 ʱ��				   			 FIELD_SERVICE_TIME 
*/
#define     SERVICE_SERVICE_OFF_GETALARMDYNSTRESSWAVE       21040

/**����ʽϵͳ����������������ܣ���ȡ��ָ������ʱ��Ĳ��κ�������������ȡָ�������̬ѹ����㡢�����˳�������㡢�񶯲�㡣������Ϊ�վͲ��᷵�ض�Ӧ�����ݡ�
*�������ֵ��
*            ��˾ID                     FIELD_SYSTEM_COMPANY
*			 �ֳ���                     FIELD_SYSTEM_FACTORY
*            ����ID                     FIELD_SERVICE_PLANTID
*            �񶯲��buff               FIELD_SERVICE_CHANN_BUFF
*            �񶯲��buff����           FIELD_SERVICE_CHANN_BUFFSIZE
*            �񶯲�����               FIELD_SERVICE_CHANN_NUM
*            ��̬���buff               FIELD_SERVICE_CHANN_BUFF2
*            ��̬���buff����           FIELD_SERVICE_CHANN_BUFFSIZE2
*            ��̬������               FIELD_SERVICE_CHANN_NUM2
*            �¼�ID                     FIELD_SYSTEM_EVENT_ID
*            ����ʱ��ֵ                 FIELD_SERVICE_OFF_TIME
*�����ֶΣ�
*            �������ݵĵ���             FIELD_SERVICE_TIMEWAVE_NUM
*            ����Ƶ��                   FIELD_SERVICE_SAMPLE_FREQ
*            �������                   FIELD_SERVICE_CHANN1
*            ��㲨��                   FIELD_SERVICE_TIMEWAVE1
*            �������ֵ                 FIELD_SERVICE_CHARVALUE_S
*            ������                     FIELD_SERVICE_FREQWAVE2
*/
#define   SERVICE_SERVICE_OFF_GETALARMRCMULTIPARAMDATA      21041

/**�õ�ָ��ʱ����¡���˾���ֳ�������������ĸ�������ֵ���ֵ��Сֵƽ��ֵ���������ֵbuff�����������ֵ����Сֵ��ƽ��ֵ������ֵ����Ӧ����3
  *���������
  *          ��˾ID   FIELD_SYSTEM_COMPANY
  *			 �ֳ���   FIELD_SYSTEM_FACTORY
  *          ����ID               FIELD_SERVICE_PLANTID
  *          ʱ��ֵ               FIELD_SERVICE_OFF_TIME
  *����ֵ���ֶΣ�
  *          �������ֵBuff      FIELD_SERVICE_CHARVALUE_SBUFF
  *          ����ֵ����          FIELD_SERVICE_CHANN_NUM
  *          ���ID              FIELD_SERVICE_CHANN1
  */
#define SERVICE_SERVICE_OFF_GETSPECPLANTMONTHREPORT         21051

/**�õ�ָ����˾���ֳ���ָ��ʱ�䷶Χ�ı�����Ϣ����ͣ����Ϣ��
  *��ͨ������������������ͨ���������ۼ�ͣ���������ۼ�ͣ��ʱ�䡢�ۼ�����ʱ�䣬ʱ�䵥λΪСʱ
  *���������
  *          ��˾ID   FIELD_SYSTEM_COMPANY
  *			 �ֳ���   FIELD_SYSTEM_FACTORY
  *          ��ʼʱ�䣺    FIELD_SERVICE_OFF_TIMESTART
  *          ��ֹʱ�䣺    FIELD_SERVICE_OFF_TIMEEND
  *���ص��ֶΣ�
  *          ����ID               FIELD_SERVICE_PLANTID
  *          ���в�㱨������     FIELD_SERVICE_ON_SEND_VIBCHANNNUM
  *          �ۼ�ͣ������         FIELD_SERVICE_LEN
  *          �ۼ�ͣ��ʱ��(Сʱ)   FIELD_SERVICE_SAMPLE_FREQ
  *          �ۼ�����ʱ��(Сʱ)   FIELD_SERVICE_SAMPLE_NUM
  */
#define SERVICE_SERVICE_OFF_GETSPECTIMERANGEFACTORYRUNINFO  21052

/**������ϡ��������ID�Ŀ�ʼ��ֹʱ�䷶Χ�ڣ����صļ�¼ֻ��һ����0��ʾû�У�1��ʾ�С�
  *���������
  *          ��˾ID   FIELD_SYSTEM_COMPANY
  *			     �ֳ���   FIELD_SYSTEM_FACTORY
  *          ����ID   FIELD_SERVICE_PLANTID
  *          ���ID   FIELD_SERVICE_CHANN1
  *          �¼�ID   FIELD_SYSTEM_EVENT_ID
  *����ֵ���ֶ��룺
  *          ͬת�ٲ���Ƿ񱨾�               FIELD_SERVICE_OFF_REV
  *          ͬת�ٲ���Ƿ����               FIELD_SERVICE_OFF_REV2
  *          ͬת�ٲ���Ƿ���ڲ����ͨƵ���� FIELD_SERVICE_TREND_RESCHAR
  *          ��Ӧ����Ƿ񱨾�          FIELD_SERVICE_REV
  *          ��Ӧ����Ƿ����          FIELD_SERVICE_REV2
  *          ��Ӧ����Ƿ���ڲ����ͨƵ����   FIELD_SERVICE_TREND_DC
  */
#define SERVICE_SERVICE_OFF_CORRDIGN                        21053

/**���ż���ʷ����ͳ��
*�������ֵ����˾ID          FIELD_SYSTEM_COMPANY
*		     �ֳ���           FIELD_SYSTEM_FACTORY
*            ��ʼʱ�䣺       FIELD_SERVICE_OFF_TIMESTART
*            ��ֹʱ�䣺       FIELD_SERVICE_OFF_TIMEEND
*����ֵ���ֶ��룺
*		     �豸��           FIELD_SERVICE_PLANT_NUM
*		     �����豸��       FIELD_SERVICE_ALARM_PLANTNUM
*/
#define    SERVICE_SERVICE_OFF_GROUPALARMSTAT             21054

/**��˾����ʷ����ͳ��
*�������ֵ����˾ID          FIELD_SYSTEM_COMPANY
*		     �ֳ���           FIELD_SYSTEM_FACTORY
*            ��ʼʱ�䣺       FIELD_SERVICE_OFF_TIMESTART
*            ��ֹʱ�䣺       FIELD_SERVICE_OFF_TIMEEND
*����ֵ���ֶ��룺
*            �ֳ���           FIELD_SYSTEM_FACTORY
*		     �豸��           FIELD_SERVICE_PLANTID
*		     ��������         FIELD_SERVICE_ALARM_PLANTNUM
*		     ͣ������         FIELD_SERVICE_STOP_PLANTNUM
*/
#define    SERVICE_SERVICE_OFF_COMPANYALARMSTAT         21055

/**���վ����ʷ����ͳ��
*�������ֵ����˾ID          FIELD_SYSTEM_COMPANY
*		        �ֳ���           FIELD_SYSTEM_FACTORY
*	            �豸��           FIELD_SERVICE_PLANTID
*            ��ʼʱ�䣺       FIELD_SERVICE_OFF_TIMESTART
*            ��ֹʱ�䣺       FIELD_SERVICE_OFF_TIMEEND
*����ֵ���ֶ��룺
*		        ����ID          FIELD_SERVICE_ALARMID
*		        �����         FIELD_SERVICE_CHANN1
*		        ���λ��         FIELD_SYSTEM_CHANN_ALIAS
*		        ����ֵ           FIELD_SERVICE_TREND_VALUE
*		        ת��1            FIELD_SERVICE_REV
*		      ������ʼʱ��      FIELD_SERVICE_OFF_TIMESTART
*		      ��������ʱ��      FIELD_SERVICE_OFF_TIMEEND
*		        ��������          FIELD_SERVICE_ALARM_TYPE
*                �ɹ���ʾ         FIELD_SYSTEM_STATUS
*/
#define     SERVICE_SERVICE_OFF_MONITORALARMSTAT         21056

/**��ͨ��������ֵ������ѯ���õ�ָ���������ĸ�����������ֵ
*�������ֵ����˾ID           FIELD_SYSTEM_COMPANY
*		     �ֳ���           FIELD_SYSTEM_FACTORY
*        ����ID           FIELD_SERVICE_PLANTID
*		     �����         FIELD_SERVICE_CHANN1
*		     ����ID           FIELD_SERVICE_ALARMID
*����ֵ���ֶ��룺
*        ����ֵ�ṹ��     FIELD_SERVICE_CHARVALUE_S
*        ʱ��             FIELD_SERVICE_TIME
*        ��Ӧʱ���΢��   FIELD_SERVICE_MICROSECOND
*/
#define     SERVICE_SERVICE_OFF_GETSPECCHANNALARMMULTCHARVALUES   21057

/**��ͨ��������ֵ������ѯ���õ�ָ�������������ָ����������ֵ
*�������ֵ����˾ID           FIELD_SYSTEM_COMPANY
*		         �ֳ���           FIELD_SYSTEM_FACTORY
*            ����ID           FIELD_SERVICE_PLANTID
*            �������buff     FIELD_SERVICE_CHANN_BUFF
*            �������buff���� FIELD_SERVICE_CHANN_BUFFSIZE
*            ����������     FIELD_SERVICE_CHANN_NUM
*            ����ֵ����       FIELD_SERVICE_TREND_CHARTYPE
*		     ����ID           FIELD_SERVICE_ALARMID
*����ֵ���ֶ��룺
*            �����������ֵBuff   FIELD_SERVICE_TREND_VALUE_BUFF
*            ʱ��                 FIELD_SERVICE_TIME
*            ��Ӧʱ���΢��       FIELD_SERVICE_MICROSECOND
*/
#define     SERVICE_SERVICE_OFF_GETSPECCHANNSALARMSINGLECHARVALUE   21058

/**�õ�ָ������ָ��һ����ָ��ʱ��Ļ���������λ�ù켣
*���������
*          ��˾ID            FIELD_SYSTEM_COMPANY
*		   �ֳ���            FIELD_SYSTEM_FACTORY
*          ����ID            FIELD_SERVICE_PLANTID
*          ���λ������      FIELD_SYSTEM_AXISLOCATION
*          ˮƽ������ID    FIELD_SERVICE_CHANNID_HOR
*          ��ֱ������ID    FIELD_SERVICE_CHANNID_VER
*          �������ݸ���      FIELD_SERVICE_OFF_WAVE_NUM
*          ʱ��ֵ          ��FIELD_SERVICE_OFF_TIME
*����ֵ���ֶ��룺
*         X����������       FIELD_SERVICE_AXESTRACK_WAVE_HOR
*         Y����������       FIELD_SERVICE_AXESTRACK_WAVE_VER
*         ʵ�ʲ��ε���        FIELD_SERVICE_AXESTRACK_WAVENUM
*         X����������ֵ     FIELD_SERVICE_CHARVALUE_S
*         Y����������ֵ     FIELD_SERVICE_CHARVALUE_S2
*         ת��                FIELD_SERVICE_OFF_REV
*		  ���Ĺ켣Բ��X����   FIELD_SERVICE_AXIS_COORX
*		  ���Ĺ켣Բ��Y����   FIELD_SERVICE_AXIS_COORY
*		  ������Բˮƽ��뾶  FIELD_SERVICE_HOR_RADIUS
*		  ������Բ��ֱ��뾶  FIELD_SERVICE_VER_RADIUS
*/
#define     SERVICE_SERVICE_OFF_GETRODSINKAXESLOCATION            21059

/**�õ�����ʽ��е�豸����״̬��ʷ����
*��ȡ���и��ֲ�������ֵ��ͨ��ѭ������ȡ�ø������ĵ�һ������ֵ��
*�������ֵ����˾ID               FIELD_SYSTEM_COMPANY
*		     �ֳ���               FIELD_SYSTEM_FACTORY
*            ����ID               FIELD_SERVICE_PLANTID
*            �񶯲��buff         FIELD_SERVICE_CHANN_BUFF
*            �񶯲��buff����     FIELD_SERVICE_CHANN_BUFFSIZE
*            �񶯲�����         FIELD_SERVICE_CHANN_NUM
*            ��̬���buff         FIELD_SERVICE_CHANN_BUFF2
*            ��̬���buff����     FIELD_SERVICE_CHANN_BUFFSIZE2
*            ��̬������         FIELD_SERVICE_CHANN_NUM2
*            ���������buff       FIELD_SERVICE_CHANN_BUFF3
*            ���������buff����   FIELD_SERVICE_CHANN_BUFFSIZE3
*            ������������       FIELD_SERVICE_CHANN_NUM3
*            ��ʼʱ��             FIELD_SERVICE_OFF_TIMESTART
*            ��ֹʱ��             FIELD_SERVICE_OFF_TIMEEND
*            ������������ֵ���� FIELD_SERVICE_TREND_CHARTYPE
*            ����������ֵ����   FIELD_SERVICE_CHANNTYPE
*            ����������ֵ����   FIELD_SERVICE_OTHER_CHARTYPE
*            ��̬ѹ������ֵ����   FIELD_SYSTEM_EVENT_TYPE
*            �����˳�������ֵ���� FIELD_SERVICE_OFF_TRENDTYPE
*����ֵ���ֶ��룺
*            �������ֵBuff       FIELD_SERVICE_TREND_VALUE_BUFF
*            ָ���������ת��   FIELD_SERVICE_REV_BUFF
*            ʱ��ֵ               FIELD_SERVICE_OFF_TIME
*            ������ͱ�ʶ         FIELD_SYSTEM_TYPE //��:GE_VIBCHANN, ��̬ѹ����GE_DYNPRESSCHANN, ������:GE_ALLPROC
*/
#define     SERVICE_SERVICE_OFF_GETHISRUNSTATUS                   21060

/**�õ�����ʽ��е�豸���в�������ֵ��ʷ���ƱȽϣ�
*�������ֵ����˾ID           FIELD_SYSTEM_COMPANY
*		     �ֳ���           FIELD_SYSTEM_FACTORY
*            ����ID           FIELD_SERVICE_PLANTID
*            ���buff         FIELD_SERVICE_CHANN_BUFF
*            ���buff����     FIELD_SERVICE_CHANN_BUFFSIZE
*            ������         FIELD_SERVICE_CHANN_NUM
*            �������         FIELD_SERVICE_OFF_CHANNTYPE
*            ����ֵ����       FIELD_SERVICE_TREND_CHARTYPE
*            ��ʼʱ��         FIELD_SERVICE_OFF_TIMESTART
*            ��ֹʱ��         FIELD_SERVICE_OFF_TIMEEND
*����ֵ���ֶ��룺
*            �������ֵBuff   FIELD_SERVICE_TREND_VALUE_BUFF
*            ת��             FIELD_SERVICE_REV_BUFF
*            ʱ��ֵ           FIELD_SERVICE_OFF_TIME
*/
#define     SERVICE_SERVICE_OFF_GETHISCOMPARE         21061

/**�õ�����ʽ��е�豸����ͨ��ָ��ʱ�������ֵ�Ͳ������ݱȽ�
*���������
*�������ֵ����˾ID          FIELD_SYSTEM_COMPANY
*		     �ֳ���           FIELD_SYSTEM_FACTORY
*            ����ID          FIELD_SERVICE_PLANTID
*            ���buff         FIELD_SERVICE_CHANN_BUFF
*            ���buff����     FIELD_SERVICE_CHANN_BUFFSIZE
*            ������ͣ�       FIELD_SERVICE_CHANNTYPE
*            ������         FIELD_SERVICE_CHANN_NUM
*            ʱ��             FIELD_SERVICE_OFF_TIME
*            �������ݸ���     FIELD_SERVICE_OFF_WAVE_NUM
*����ֵ���ֶ��룺
*            ���Ĳ�������   FIELD_SERVICE_OFF_WAVE
*            �������ݸ���     FIELD_SERVICE_OFF_WAVE_NUM
*            ����ֵ�ṹ��     FIELD_SERVICE_CHARVALUE_S
*            ת��             FIELD_SERVICE_REV
*/
#define     SERVICE_SERVICE_OFF_GETSPECCHARVALUEWAVE         21062

/**�õ�����ʽ��е�豸��ͨ���Ͷ�̬ͨ��ָ��ʱ�������ֵ
*���������
*�������ֵ����˾ID           FIELD_SYSTEM_COMPANY
*		     �ֳ���           FIELD_SYSTEM_FACTORY
*            ����ID           FIELD_SERVICE_PLANTID
*            �񶯲��buff         FIELD_SERVICE_CHANN_BUFF
*            �񶯲��buff����     FIELD_SERVICE_CHANN_BUFFSIZE
*            �񶯲�����         FIELD_SERVICE_CHANN_NUM
*            ��̬���buff         FIELD_SERVICE_CHANN_BUFF2
*            ��̬���buff����     FIELD_SERVICE_CHANN_BUFFSIZE2
*            ��̬������         FIELD_SERVICE_CHANN_NUM2
*            ������ֵʱ��     FIELD_SERVICE_TIME
*            ��̬����ֵʱ��     FIELD_SERVICE_OFF_TIME
*����ֵ���ֶ��룺
*            ����ֵ�ṹ��     FIELD_SERVICE_CHARVALUE_S
*            ת��             FIELD_SERVICE_OFF_REV
*            ������ͱ�ʶ         FIELD_SYSTEM_TYPE //��:GE_VIBCHANN, ��̬ѹ����GE_DYNPRESSCHANN
*/
#define     SERVICE_SERVICE_OFF_GETSPECCHANNSCHARVALUE         21063

/**�õ�����ʽ��е�豸�����±���
*�������ֵ����˾ID           FIELD_SYSTEM_COMPANY
*		     �ֳ���           FIELD_SYSTEM_FACTORY
*            ����ID           FIELD_SERVICE_PLANTID
*            ʱ��ֵ           FIELD_SERVICE_OFF_TIME
*����ֵ���ֶ��룺
*            �����           FIELD_SERVICE_CHANN1
*            ����ֵ���ֵ     FIELD_SERVICE_CHANN1VALUE
*            ����ֵ��Сֵ     FIELD_SERVICE_CHANN2VALUE
*            ����ֵƽ��ֵ     FIELD_SERVICE_TREND_VALUE
*/
#define     SERVICE_SERVICE_OFF_GETSPECRECIPMONTHREPORT       21064

/**���վ����ʷ����ͳ�ƣ��Ż���ȡ���ݣ���ȡ20����¼�Ժ������ֵ��ת��
*�������ֵ����˾ID           FIELD_SYSTEM_COMPANY
*		     �ֳ���           FIELD_SYSTEM_FACTORY
*	         �豸��           FIELD_SERVICE_PLANTID
*		     �����         FIELD_SERVICE_CHANN1
*		     ����ID           FIELD_SERVICE_ALARMID
*����ֵ���ֶ��룺
*		     ����ֵ           FIELD_SERVICE_TREND_VALUE
*		     ת��1            FIELD_SERVICE_REV
*/
#define     SERVICE_SERVICE_OFF_MONITORALARMSTATCHAR       21065

/**�õ�ָ����˾���ֳ������顢����ʱ���һ���ᴿ���Ĺ켣�Ĳ������ݡ�
*���������
*          ��˾ID                         FIELD_SYSTEM_COMPANY
*		   �ֳ���                         FIELD_SYSTEM_FACTORY
*          ����ID                         FIELD_SERVICE_PLANTID
*          ˮƽ�����񶯲��ID             FIELD_SERVICE_CHANNID_HOR
*          ��ֱ�����񶯲��ID             FIELD_SERVICE_CHANNID_VER
*          ���λ������                   FIELD_SYSTEM_AXISLOCATION
*          �������ݸ���                   FIELD_SERVICE_OFF_WAVE_NUM
*          ʱ��                           FIELD_SERVICE_OFF_TIME
*����ֵ���ֶ��룺
*          ��ֱ���������������Ƶ��       FIELD_SERVICE_VERFREQ
*          ��ֱ��������������ķ�ֵ       FIELD_SERVICE_VERAMP
*          ��ֱ�����������������λ       FIELD_SERVICE_VERPHASE
*          ˮƽ���������������Ƶ��       FIELD_SERVICE_HORFREQ
*          ˮƽ��������������ķ�ֵ       FIELD_SERVICE_HORAMP
*          ˮƽ�����������������λ       FIELD_SERVICE_HORPHASE
*          ˮƽ��������ֵ�ṹ��           FIELD_SERVICE_CHARVALUE_S
*          ��ֱ��������ֵ�ṹ��           FIELD_SERVICE_CHARVALUE_S2
*          ת������                     FIELD_SYSTEM_TYPE //0:Ϊ��ʱ��,1Ϊ˳ʱ��
*          ��������                     FIELD_SYSTEM_STATUS//1:Ϊ������,2Ϊ������
*/
#define     SERVICE_SERVICE_OFF_GETPURIFYAXESTRACK           21066

/**�õ�ָ����˾���ֳ�����Ͳ��ָ��ʱ�̵ĵ�������
*���������
*          ��˾ID       FIELD_SYSTEM_COMPANY
*	       �ֳ���       FIELD_SYSTEM_FACTORY
*          ����ID       FIELD_SERVICE_PLANTID
*          ���ID       FIELD_SERVICE_OFF_CHANN1
*          �������ݸ��� FIELD_SERVICE_OFF_WAVE_NUM
*          ʱ��         FIELD_SERVICE_OFF_TIME
*����ֵ���ֶ��룺
*          ��������        FIELD_SERVICE_OFF_WAVE
*          ��������        FIELD_SERVICE_OFF_FREQWAVE
*          �������ݸ���    FIELD_SERVICE_OFF_WAVE_NUM
*          ����DF          FIELD_SERVICE_OFF_FREQWAVE_DF
*          �������ݵ���    FIELD_SERVICE_OFF_FREQWAVE_NUM
*          ����ֵ�ṹ��    FIELD_SERVICE_CHARVALUE_S
*          ����ֵ          FIELD_SYSTEM_ALARM_LOW
*          Σ��ֵ          FIELD_SYSTEM_ALARM_HIGH
*          ��λ            FIELD_SERVICE_CHANN1_UNIT
*          ������        FIELD_SYSTEM_CHANN_ALIAS
*          ת��            FIELD_SERVICE_OFF_REV
*          ������������λ��     FIELD_SERVICE_ANGLEPARAM1
*          �������ر���λ��     FIELD_SERVICE_ANGLEPARAM2
*          ������������λ��     FIELD_SERVICE_ANGLEPARAM3
*          �������ر���λ��     FIELD_SERVICE_ANGLEPARAM4
*/
#define     SERVICE_SERVICE_OFF_GETSPECCHANNCEPSTRUM         21067



/**������е������ѯ���õ�ָ������ID���ȱ����Ĳ����������ֵ����
*�������ֵ����˾ID           FIELD_SYSTEM_COMPANY
*            �ֳ���           FIELD_SYSTEM_FACTORY
*            ����ID           FIELD_SERVICE_PLANTID
*            ����ID           FIELD_SERVICE_ALARMID
*����ֵ���ֶ��룺
*            ���������              FIELD_SERVICE_CHANN1
*            �������                FIELD_SERVICE_CHANNTYPE
*            ������������ֵ�ṹ��  FIELD_SERVICE_CHARVALUE_S
*            ʱ��                    FIELD_SERVICE_TIME
*            ��Ӧʱ���΢��          FIELD_SERVICE_MICROSECOND
*/
#define     SERVICE_SERVICE_OFF_GETSPECALARMIDCHARVALUES   21068


/**������е������ѯ,�õ�ָ��ʱ���ָ�������˳�����̬ѹ�����ı�����¼
*��������ֶ���
*          ��˾ID          FIELD_SYSTEM_COMPANY
*          �ֳ���          FIELD_SYSTEM_FACTORY
*          ����ID��        FIELD_SERVICE_PLANTID
*          ���            FIELD_SERVICE_OFF_CHANN1
*          �¼�ID:         FIELD_SYSTEM_EVENT_ID
*          ����ʱ�䣺      FIELD_SERVICE_OFF_TIME
*          ��Ӧʱ��ĺ���  FIELD_SERVICE_MICROSECOND
*          �������ݸ���    FIELD_SERVICE_OFF_WAVE_NUM
*����ֵ���ֶ��룺
*          ���Ĳ�������   FIELD_SERVICE_OFF_WAVE
*          Ƶ������         FIELD_SERVICE_OFF_FREQWAVE
*          �������ݸ���     FIELD_SERVICE_OFF_WAVE_NUM
*          Ƶ��DF           FIELD_SERVICE_OFF_FREQWAVE_DF
*          Ƶ�����ݵ���     FIELD_SERVICE_OFF_FREQWAVE_NUM
*          ����X������    FIELD_SERVICE_ZOOMSPECTRUM
*          ����ֵ�ṹ��     FIELD_SERVICE_CHARVALUE_S
*          ת��             FIELD_SERVICE_REV
*          ������������λ��     FIELD_SERVICE_ANGLEPARAM1
*          �������ر���λ��     FIELD_SERVICE_ANGLEPARAM2
*          ������������λ��     FIELD_SERVICE_ANGLEPARAM3
*          �������ر���λ��     FIELD_SERVICE_ANGLEPARAM4
*          �Զ����������BUFF   FIELD_SERVICE_LEARNPARAM_BUFF
*/
#define    SERVICE_SERVICE_OFF_GETSPECALARMTIMEDYNRECORD     21069

/**�õ�ָ����˾���ֳ������һ���񶯲��ָ��ʱ�̵�ȫ������
*���������
*          ��˾ID               			FIELD_SYSTEM_COMPANY
*		   �ֳ���               			FIELD_SYSTEM_FACTORY
*          ����ID               			FIELD_SERVICE_PLANTID
*          ˮƽ�����񶯲��ID  			    FIELD_SERVICE_CHANNID_HOR
*          ��ֱ�����񶯲��ID   		    FIELD_SERVICE_CHANNID_VER
*          ���λ������        			    FIELD_SYSTEM_AXISLOCATION
*          �������ݸ���         			FIELD_SERVICE_OFF_WAVE_NUM
*          ʱ��                             FIELD_SERVICE_OFF_TIME
*          �Ƿ�Ӧ�����㷨                   FIELD_SERVICE_FUNCTION_TYPE
*����ֵ���ֶ��룺
*          ȫ��Ƶ�ʺͷ�ֵ��Ϣ�ṹ��         FIELD_SERVICE_LEARNPARAM_BUFF
*          ȫ����Ϣ�ṹ���С               FIELD_SERVICE_CHANN_BUFFSIZE
*          ָ���������ת��               FIELD_SERVICE_REV
*          ˮƽ��������ֵ                   FIELD_SERVICE_CHARVALUE_S
*          ��ֱ��������ֵ                   FIELD_SERVICE_CHARVALUE_S2
*          ����Ƶ��                         FIELD_SERVICE_SAMPLE_FREQ
*          ת������                       FIELD_SYSTEM_TYPE //0:Ϊ��ʱ��,1Ϊ˳ʱ��
*/
#define     SERVICE_SERVICE_OFF_GETFULLSPECSTRUM          21070

/**������ѯ���ܣ���ѯ����ID��������
*�������ֵ����˾ID           FIELD_SYSTEM_COMPANY
*		     �ֳ���           FIELD_SYSTEM_FACTORY
*	         �豸��           FIELD_SERVICE_PLANTID
*            ��ʼʱ�䣺       FIELD_SERVICE_OFF_TIMESTART
*            ��ֹʱ�䣺       FIELD_SERVICE_OFF_TIMEEND
*����ֵ���ֶ��룺
*		     ����ID            FIELD_SERVICE_ALARMID
*		     ������ʼʱ��      FIELD_SERVICE_OFF_TIMESTART
*		     ��������          FIELD_SERVICE_ALARM_TYPE
*            �ɹ���ʾ          FIELD_SYSTEM_STATUS
*/
#define     SERVICE_SERVICE_OFF_GETALARMLOGINFO         21071

/**����ʽϵͳӦ����⣬�õ�ָ������ָ��ʱ�䡢ָ���׺ŵ�Ӧ�����κ��񶯲�㲨��
*���������
*          ��˾ID        ������    FIELD_SYSTEM_COMPANY
*		   �ֳ���          ������  FIELD_SYSTEM_FACTORY
*          ����ID          ������  FIELD_SERVICE_PLANTID
*          ���׺�                  FIELD_SERVICE_CYLINDERNO
*          �����񶯲��            FIELD_SERVICE_OFF_CHANN1
*          ʱ��                    FIELD_SERVICE_OFF_TIME
*����ֵ���ֶ��룺
*          ����Ӧ���������ݡ�������FIELD_SERVICE_TIMEWAVE1
*          ����Ӧ���������ݡ�������FIELD_SERVICE_TIMEWAVE2
*          ������Ӧ���������ݡ�����FIELD_SERVICE_FREQWAVE1
*          �񶯲�������   ������ ��FIELD_SERVICE_FREQWAVE2
*          �������ݸ���   �������� FIELD_SERVICE_TIMEWAVE_NUM
*		       ����ֵ�ṹ��		         FIELD_SERVICE_CHARVALUE_S
*		       ����ֵ�ṹ��2		       FIELD_SERVICE_CHARVALUE_S2
*		       �����				           FIELD_SYSTEM_CHANN
*		       �����2				         FIELD_SYSTEM_CHANN2
*		   		 ���1�ǶȲ���1		       FIELD_SERVICE_ANGLEPARAM1
*		       ���1�ǶȲ���2		       FIELD_SERVICE_ANGLEPARAM2
*		       ���1�ǶȲ���3		       FIELD_SERVICE_ANGLEPARAM3
*		       ���1�ǶȲ���4		       FIELD_SERVICE_ANGLEPARAM4
*		       ���2�ǶȲ���1		       FIELD_SERVICE_ANGLEPARAM5
*		       ���2�ǶȲ���2		       FIELD_SERVICE_ANGLEPARAM6
*		       ���2�ǶȲ���3		       FIELD_SERVICE_ANGLEPARAM7
*		       ���2�ǶȲ���4		       FIELD_SERVICE_ANGLEPARAM8
*/
#define     SERVICE_SERVICE_OFF_GETDYNSTRESSWAVE              21072

/**�õ�ָ����˾���ֳ������顢ʱ��Ρ������������Զ��������ͨ��ѭ�����εõ������������ݺͶ�Ӧʱ�䣬ÿ��ȡ�����ݶ�Ӧʱ�䶼����ͬ��
*��������ֶ��룺
*          ��˾ID        FIELD_SYSTEM_COMPANY
*		   �ֳ���        FIELD_SYSTEM_FACTORY
*          ����ID        FIELD_SERVICE_PLANTID
*          ������ͣ�    FIELD_SERVICE_CHANNTYPE
*          ���buff      FIELD_SERVICE_CHANN_BUFF
*          ���buff����  FIELD_SERVICE_CHANN_BUFFSIZE
*          ������      FIELD_SERVICE_CHANN_NUM
*          ��ʼʱ��      FIELD_SERVICE_OFF_TIMESTART
*          ��ֹʱ��      FIELD_SERVICE_OFF_TIMEEND
*����ֵ���ֶ��룺
*          �Զ����������BUFF     FIELD_SERVICE_LEARNPARAM_BUFF
*          �Զ����������BUFFSIZE FIELD_SERVICE_CHANN_BUFFSIZE
*          ������               FIELD_SERVICE_CHANN_NUM
*          ʱ��ֵ                 FIELD_SERVICE_OFF_TIME
*/
#define     SERVICE_SERVICE_OFF_GETSEPCCHANNCUSTOMSTREND         21073


/** ��ȡ����Ѳ�����ݣ�
*          ��˾ID        FIELD_SYSTEM_COMPANY
*          �ֳ���        FIELD_SYSTEM_FACTORY
*          ����ID        FIELD_SERVICE_PLANTID
*          ������ͣ�    FIELD_SERVICE_CHANNTYPE
*          ���buff      FIELD_SERVICE_CHANN_BUFF
*          ���buff����  FIELD_SERVICE_CHANN_BUFFSIZE
*          ������      FIELD_SERVICE_CHANN_NUM
*          ��ʼʱ��      FIELD_SERVICE_OFF_TIMESTART
*          ��ֹʱ��      FIELD_SERVICE_OFF_TIMEEND
*����ֵ���ֶ��룺
*          ���ID       FIELD_SERVICE_OFF_CHANN1
*          ʱ��         FIELD_SERVICE_OFF_TIME
*          ����ֵ       FIELD_SERVICE_OFF_DATA
*          ת��         FIELD_SERVICE_OFF_REV
*/
#define     SERVICE_SERVICE_OFF_GET_OFFLINE_DATA         21074

/**���ݱ���ID�б���վ����ʷ����ͳ������
*�������ֵ����˾ID           FIELD_SYSTEM_COMPANY
*		     �ֳ���           FIELD_SYSTEM_FACTORY
*	         �豸��           FIELD_SERVICE_PLANTID
*			 ����ID�б�	      FIELD_SERVICE_ALARMIDS
*			 ����ID����	      FIELD_SERVICE_ALARMID_NUM
*			 ����ID��������С FIELD_SERVICE_ALARMID_BUFFSIZE
*����ֵ���ֶ��룺
*		     ����ID           FIELD_SERVICE_ ALARM ID
*		     �����         FIELD_SERVICE_CHANN1
*		     ���λ��         FIELD_SYSTEM_CHANN_ALIAS
*		     ����ֵ           FIELD_SERVICE_TREND_VALUE
*		     ת��1            FIELD_SERVICE_REV
*		     ������ʼʱ��     FIELD_SERVICE_OFF_TIMESTART
*		     ��������ʱ��     FIELD_SERVICE_OFF_TIMEEND
*		     ��������         FIELD_SERVICE_ALARM_TYPE
*            �ɹ���ʾ         FIELD_SYSTEM_STATUS
			 �ӿ���������	  FIELD_SERVICE_DATALIMIT
*/

#define     SERVICE_SERVICE_OFF_GETALARMDATA    21075



/**���վ����ʷ����ID�б�
*�������ֵ����˾ID           FIELD_SYSTEM_COMPANY
*		     �ֳ���           FIELD_SYSTEM_FACTORY
*	         �豸��           FIELD_SERVICE_PLANTID
*            ��ʼʱ�䣺       FIELD_SERVICE_OFF_TIMESTART
*            ��ֹʱ�䣺       FIELD_SERVICE_OFF_TIMEEND
			 

*����ֵ���ֶ��룺
			 ����ID		      FIELD_SERVICE_ALARMID
			 ����ID����       FIELD_SERVICE_ALARMID_NUM
			 ����ID��Ӧ�ı���ͨ����		FIELD_SERVICE_ALARMID_CHANN_NUM


*/
#define     SERVICE_SERVICE_OFF_GETALARMIDS    21076

/***************************ϵͳ������*******************************/

/**ͨ����˾�����ֳ���������ŵõ���������ͣ���Ĳ������Ӧ�Ķת��
  *���������
  *          ��˾��     FIELD_SYSTEM_COMPANY
  *          �ֳ���     FIELD_SYSTEM_FACTORY
  *          �����     FIELD_SYSTEM_PLANT
  *����ֵ���ֶ��룺
  *          ����    FIELD_SYSTEM_CHANN
  *          �ת��  FIELD_SERVICE_REV
  */
#define    SERVICE_SYSTEM_GETPLANTSUDCHANN           25000

/**�õ�ָ���ֳ������л���λ�ţ�ͨ��ѭ�����εõ����л���λ��
  *�����������˾��     FIELD_SYSTEM_COMPANY
  *          �ֳ���     FIELD_SYSTEM_FACTORY
  *          װ����ID   FIELD_SYSTEM_SET
  *����ֵ���ֶ��룺
  *          �����     FIELD_SYSTEM_PLANT
  *          װ����ID     FIELD_SYSTEM_SET
  *          ��òͼ���� FIELD_SYSTEM_PLANT_GRAPHTYPE
  *          �豸����   FIELD_SYSTEM_TYPE
  *          ����Դ       FIELD_SYSTEM_DATASOURCE
  */
#define     SERVICE_SYSTEM_GETPLANTOFSUBCORP          25001

/**�õ�ָ����˾�����ֳ���������λ�ŵ����в�����Ͷ�Ӧ�Ĳ�����ͣ�ͨ��ѭ�����εõ�
  *���������
  *          ��˾��     FIELD_SYSTEM_COMPANY
  *          �ֳ���     FIELD_SYSTEM_FACTORY
  *          �����     FIELD_SYSTEM_PLANT
  *����ֵ���ֶ��룺
  *          ����      FIELD_SYSTEM_CHANN
  *          �������    FIELD_SYSTEM_CHANN_TYPE
  *          ����������  FIELD_SYSTEM_SENSOR_TYPE
  */
#define     SERVICE_SYSTEM_GETALLCHANN                25002

/**�õ�ָ����˾�����ֳ���������ָ��������͵����в������ͨ��ѭ�����εõ�
  *���������   ��˾��    FIELD_SYSTEM_COMPANY
  *             �ֳ���     FIELD_SYSTEM_FACTORY
  *             �����     FIELD_SYSTEM_PLANT
  *             �������   FIELD_SYSTEM_CHANN_TYPE
  *����ֵ���ֶ��룺
  *             �����     FIELD_SYSTEM_CHANN
  *             ����     FIELD_SERVICE_CHANN1
  *             ���λ��   FIELD_SYSTEM_CHANN_ALIAS
  *             ��㵥λ   FIELD_SERVICE_CHANN1_UNIT
  *             �������    FIELD_SYSTEM_CHANN_TYPE
  *             ���������� FIELD_SYSTEM_SENSOR_TYPE
  *             �������׺� FIELD_SERVICE_CYLINDERNO
  *             ��Ϣ����   FIELD_SYSTEM_TYPE
  *             ����������        FIELD_SYSTEM_EVENT_TYPE
  *             ��������          FIELD_SYSTEM_ALARM_LOW
  *             ����������        FIELD_SYSTEM_ALARM_HIGH
  *             ��������          FIELD_SYSTEM_ALARM_LOW2
  *             ����������        FIELD_SYSTEM_ALARM_HIGH2
  *             �Զ������ģ��ID          FIELD_SYSTEM_TEMPID
  *             �Զ��屨������ģ��ID      FIELD_SYSTEM_ALARM_TEMPID
  *             ����Դ                    FIELD_SYSTEM_DATASOURCE
  *             ��λ����          FIELD_SERVICE_SEC_NAME
  *             ��λ����          FIELD_SERVICE_SEC_IDX
  *             λ������          FIELD_SERVICE_LOC_NAME
  *             λ������          FIELD_SERVICE_LOC_IDX
  *             ��������б�      FIELD_SERVICE_CHANN1_LIST
  */
#define     SERVICE_SYSTEM_GETSPECTYPECHANN           25003

/**ͨ���û���������õ��û����𡢼���������˾��������û������Ǽ��ż�������Ҫѭ���õ�������˾�ͳ�
  *����������û���   FIELD_SYSTEM_USEID
  *          ����     FIELD_SYSTEM_PASSWORD
  *����ֵ���ֶ��룺
  *          �û����� FIELD_SYSTEM_USER_LEVEL
  *          ������   FIELD_SYSTEM_GROUP
  *          ��˾��   FIELD_SYSTEM_COMPANY
  *          �ֳ���   FIELD_SYSTEM_FACTORY
  *          ״̬     FIELD_SYSTEM_STATUS
  *          ״̬���� FIELD_SYSTEM_STATUS_DISCRIPTION
  */
#define     SERVICE_SYSTEM_GETCOMPANYTOFUSER          25004


/**�õ�ָ����˾�����ֳ���������λ�ŵ����������Ĺ켣��Ӧ�Ĳ��ԣ�ͨ��ѭ�����εõ������û��ָ���豸�ţ����Ƿ������������Ĺ켣��
  *���������   ��˾��    FIELD_SYSTEM_COMPANY
  *             �ֳ���    FIELD_SYSTEM_FACTORY
  *             �����    FIELD_SYSTEM_PLANT
  *����ֵ���ֶ��룺
   *            ����λ��λ������   FIELD_SYSTEM_AXISLOCATION
  *             ��ֱ������    FIELD_SYSTEM_CHANN_VER
  *             ˮƽ������    FIELD_SYSTEM_CHANN_HOR
  *             ����λ����Ϣ�ṹ�� FIELD_SYSTEM_SETSVR_PLANTINFO
  */
#define     SERVICE_SYSTEM_GETALLAXISCHANN            25005


/**�õ�ָ������λ�ŵ�����Ӧ����߷���������Ӧ�ĺ궨��
  *���������   ��˾��    FIELD_SYSTEM_COMPANY
  *             �ֳ���    FIELD_SYSTEM_FACTORY
  *             �����    FIELD_SYSTEM_PLANT
  *����ֵ���ֶ��룺
  *             �����        FIELD_SYSTEM_PLANT
  *             ��߷�������  FIELD_SYSTEM_ANALYSISLINES
  *             ���ղ�����Ϣ����ķ�������    FIELD_SERVICE_ZOOM_LINES
  */
#define     SERVICE_SYSTEM_GETPLANTANALYSISLINES      25006

/**�õ�ָ����˾���ֳ����豸���豸��ϸ��Ϣ
  *���������   ��˾��    FIELD_SYSTEM_COMPANY
  *             �ֳ���    FIELD_SYSTEM_FACTORY
  *             �����    FIELD_SYSTEM_PLANT
  *����ֵ���ֶ��룺
  *             �豸��Ϣ  FIELD_SYSTEM_SETSVR_PLANTINFO
  */
#define     SERVICE_SYSTEM_GETPLANTINFO      25007


/**�õ�ָ����˾�����зֳ�����ͨ��ѭ�����εõ����зֳ��������û��ָ����˾�����͵õ����зֳ���
	*���������
	*                ��˾��    FIELD_SYSTEM_COMPANY
	*����ֵ���ֶ��룺
	*                ��˾��    FIELD_SYSTEM_COMPANY
  *                �ֳ���    FIELD_SYSTEM_FACTORY
	*                �ֳ�����  FIELD_SYSTEM_SUBCORP_ALIAS
	*/
#define     SERVICE_SYSTEM_GETALLFACTORY        25008

/**�õ�ָ�����й�˾��Ϣ
	*����ֵ���ֶ��룺
	*                ��˾��    FIELD_SYSTEM_COMPANY
  *                ��˾����  FIELD_SYSTEM_COMPANY2
  *                ������    FIELD_SYSTEM_GROUP
	*/
#define     SERVICE_SYSTEM_GETALLCOMPANY        25009


/**�õ�ָ���ֳ������л���λ�ź����IP��Ϣ��ͨ��ѭ�����εõ����л���λ�š����ֱ�����ӷ��ʵĹ�˾������������˾��IP��PortΪ�գ����ֱ�����ӷ��ʵ���װ�ü�����˾��װ�ü�IP��Port��Ϊ��
  *�����������˾��     FIELD_SYSTEM_COMPANY
  *          �ֳ���     FIELD_SYSTEM_FACTORY
  *����ֵ���ֶ��룺
  *          ��˾��     FIELD_SYSTEM_COMPANY
  *          �ֳ���     FIELD_SYSTEM_FACTORY
  *          �����     FIELD_SYSTEM_PLANT
  *          ��òͼ���� FIELD_SYSTEM_PLANT_GRAPHTYPE
  *          ���ż�IP   FIELD_SYSTEM_GROUP_MW_IP
  *          ���ż�Port FIELD_SYSTEM_GROUP_MW_PORT
  *          ��˾��IP   FIELD_SYSTEM_COMPANY_MW_IP
  *          ��˾��Port FIELD_SYSTEM_COMPANY_MW_PORT
  *          װ�ü�IP   FIELD_SYSTEM_MW_IP
  *          װ�ü�Port FIELD_SYSTEM_MW_PORT
  *          װ�ü��м��ID   FIELD_SYSTEM_SET
  *          �豸����   FIELD_SYSTEM_TYPE
  *          ����Դ     FIELD_SYSTEM_DATASOURCE
  */
#define     SERVICE_SYSTEM_GETPLANTIPOFSUBCORP        25010


/**ͨ���û���������,�޸�����
  *����������û���   FIELD_SYSTEM_USEID
  *          ����     FIELD_SYSTEM_PASSWORD
  *          ������   FIELD_SYSTEM_RESERVE_STRING
  *����ֵ���ֶ��룺
  *          ״̬     FIELD_SYSTEM_STATUS
  *                 ���Ϊ-1����ʾû���޸ĳɹ���Ϊ1��ʾ�޸ĳɹ�
  */
#define     SERVICE_SYSTEM_MODIFYPWD                  25011

/**ͨ��������ͺʹ��������͵õ�����ֵ����
  *���������
  *             �豸����    FIELD_SYSTEM_TYPE
  *             �������    FIELD_SYSTEM_CHANN_TYPE
  *             ����������  FIELD_SYSTEM_SENSOR_TYPE
  *����ֵ���ֶ��룺
  *             ˳��        FIELD_SYSTEM_STATUS
  *             ��Ӧ����    FIELD_SYSTEM_STATUS_DISCRIPTION
  *             ����ֵ��λ  FIELD_SERVICE_CHANN1_UNIT
  */
#define     SERVICE_SYSTEM_GETCHARTYPEDESC            25012

/**ͨ���û����õ��ͻ���ҳ��ĸ���ʱ��
  *����������û���   FIELD_SYSTEM_USEID
  *����ֵ���ֶ��룺
  *          ˢ��ʱ�� FIELD_SYSTEM_REFRESHTIME
  */
#define     SERVICE_SYSTEM_GET_REFRESHTIME            25013

/**�õ�ָ������ָ��������͵����в�����Ͷ�Ӧ�ı��������ޣ�ͨ��ѭ�����εõ�
  *���������
  *             ��˾��    FIELD_SYSTEM_COMPANY
  *             �ֳ���    FIELD_SYSTEM_FACTORY
  *             �����    FIELD_SYSTEM_PLANT
  *             �������  FIELD_SYSTEM_CHANN_TYPE
  *����ֵ���ֶ��룺
  *             ����    FIELD_SYSTEM_CHANN
  *             ��������  FIELD_SYSTEM_ALARM_HIGH
  *             ��������  FIELD_SYSTEM_ALARM_LOW
  */
#define     SERVICE_SYSTEM_GETALARMTHRESHOLD          25014

/**ͨ���û����������½�������½�ɹ�������û���¼�ɹ�����״̬Ϊ1���������û������ˢ��ʱ�䣻����Ϊ-1�����Ҳ������û������ˢ��ʱ�䡣
  *
  *����������û���   FIELD_SYSTEM_USEID
  *          ����     FIELD_SYSTEM_PASSWORD
  *����ֵ���ֶ��룺
  *          ״̬     FIELD_SYSTEM_STATUS
  *          ״̬���� FIELD_SYSTEM_STATUS_DISCRIPTION
  *          �û����� FIELD_SYSTEM_USER_LEVEL
  *          ˢ��ʱ�� FIELD_SYSTEM_REFRESHTIME
  */
#define     SERVICE_SYSTEM_LOGIN                      25015

/**�޸��û���������ɹ����򷵻�״̬Ϊ1������Ϊ-1����˵��ԭ��
  *ע�⣺ֻ�й���Ա����Ȩ���޸��û����𣬲�������Ƿֳ�����Աֻ���޸����ڷֳ����û�����
  *input param���û���         FIELD_SYSTEM_USEID
  *             ����           FIELD_SYSTEM_PASSWORD
  *             ���޸ĵ��û��� FIELD_SYSTEM_MODIFY_USER
  *             �û�����       FIELD_SYSTEM_USER_LEVEL
  *return field code��
  *          ״̬     FIELD_SYSTEM_STATUS
  *          ״̬���� FIELD_SYSTEM_STATUS_DISCRIPTION
  */
#define    SERVICE_SYSTEM_MODIFY_USERLEVEL            25016

/**@brief Add new user.����ɹ����򷵻�״̬Ϊ1������Ϊ-1����˵��ԭ��
  *ע�⣺ֻ�й���Ա����Ȩ������û������ң�����Ƿֳ�����Աֻ�����Ϊ���ڷֳ����û���
  *input param:�û���         FIELD_SYSTEM_USEID
  *            ����           FIELD_SYSTEM_PASSWORD
  *            ���û���       FIELD_SYSTEM_MODIFY_USER
  *            �û�����       FIELD_SYSTEM_USER_LEVEL
  *            ���ڷֳ�       FIELD_SYSTEM_SUBCORP
  *return field code��
  *            ״̬     FIELD_SYSTEM_STATUS
  *            ״̬���� FIELD_SYSTEM_STATUS_DISCRIPTION
  */
#define    SERVICE_SYSTEM_ADD_NEWUSER                 25017

/**����ָ������Ͳ����Ƿ���б�����飬���״̬�ֶ�����Ϊ1�����鱨����Ϊ0���򲻼�鱨��
  *����ֵ˵����״̬���Ϊ1��˵���޸ĳɹ���������Դ�״̬�����еõ�����ԭ��
  *���������   �����    FIELD_SYSTEM_PLANT
  *             ����    FIELD_SYSTEM_CHANN
  *             ״̬     FIELD_SYSTEM_STATUS
  *����ֵ���ֶ��룺
  *            ״̬     FIELD_SYSTEM_STATUS
  *            ״̬���� FIELD_SYSTEM_STATUS_DISCRIPTION
  */
#define     SERVICE_SYSTEM_SETCHECKALARMFLAG               25018

/**�õ�ָ������λ�ŵ�ͼ�ṹ������Ϣ
  *���������
  *             ��˾��    FIELD_SYSTEM_COMPANY
  *             �ֳ���    FIELD_SYSTEM_FACTORY
  *             �����    FIELD_SYSTEM_PLANT
  *����ֵ���ֶ��룺
  *					    �����          FIELD_SYSTEM_PLANT
  *			        ��òͼ����      FIELD_SYSTEM_PLANT_GRAPHTYPE
  *             ��òͼBUFF      FIELD_SYSTEM_PLANT_GRAPHTYPE_BUFF
  *             ��òͼBUFF�ߴ�  FIELD_SYSTEM_PLANT_GRAPHTYPE_BUFFSIZE
  */
#define     SERVICE_SYSTEM_GETGRAPHTYPE_BY_DEVICEID        25019


/**�޸ļ�������м��IP��Port��������ӵ��м���Ǽ�����ĵ��м������ָ���ֳ���װ���������޸�ָ��װ�ü��м��IP�Ͷ˿�
  *���������
   *           ��˾ID        FIELD_SYSTEM_COMPANY
  *          ���ڷֳ�       FIELD_SYSTEM_FACTORY
  *          װ����ID        FIELD_SYSTEM_SET
  *          �м��IP    FIELD_SYSTEM_MW_IP
  *          �м��PORT  FIELD_SYSTEM_MW_PORT
  *����ֵ���ֶ��룺
  *          ״̬     FIELD_SYSTEM_STATUS
  *          ״̬���� FIELD_SYSTEM_STATUS_DISCRIPTION
  */
#define     SERVICE_SYSTEM_MOIDFY_MWINFO                   25020

/**�õ���������м��IP��Port��������Ӽ�����ĵ��м������ָ���ֳ���װ�������͵õ�ָ��װ�ü��м��IP�Ͷ˿�
   *           ��˾ID        FIELD_SYSTEM_COMPANY
  *           ���ڷֳ�       FIELD_SYSTEM_FACTORY
  *           װ����ID        FIELD_SYSTEM_SET
  *����ֵ���ֶ��룺
  *          �м��IP    FIELD_SYSTEM_MW_IP
  *          �м��PORT  FIELD_SYSTEM_MW_PORT
  */
#define     SERVICE_SYSTEM_GET_MWINFO                      25021

/**�޸ķ��͵�������ĵ�ʱ�������Ƿ���״̬,�����û�����÷ֳ���װ�úţ�Ҳ����
  *           ��˾ID             FIELD_SYSTEM_COMPANY
  *           ���ڷֳ�           FIELD_SYSTEM_FACTORY
  *           װ����ID           FIELD_SYSTEM_SET
  *          ����ʱ����        FIELD_SYSTEM_SENDC_INTERVAL
  *          �Ƿ���״̬        FIELD_SYSTEM_SENDC_IF
  *          ������ͣ�����ݼ��  FIELD_SYSTEM_SUD_SENDC_INTERVAL
  *          ���ͱ������ݼ��    FIELD_SYSTEM_ALARM_SENDC_INTERVAL
  *����ֵ���ֶ��룺
  *          ״̬     FIELD_SYSTEM_STATUS
  *          ״̬���� FIELD_SYSTEM_STATUS_DISCRIPTION
  */
#define     SERVICE_SYSTEM_MODIFY_SENDINFO                 25022

/**�õ����͵�������ĵ�ʱ�������Ƿ���,�����û�����÷ֳ���װ�úţ�Ҳ����
  *           ��˾ID        FIELD_SYSTEM_COMPANY
  *           ���ڷֳ�       FIELD_SYSTEM_FACTORY
  *           װ����ID        FIELD_SYSTEM_SET
  *����ֵ���ֶ��룺
  *          ����ʱ����    FIELD_SYSTEM_SENDC_INTERVAL
  *          �Ƿ���״̬    FIELD_SYSTEM_SENDC_IF
  *          ������ͣ�����ݼ��  FIELD_SYSTEM_SUD_SENDC_INTERVAL
  *          ���ͱ������ݼ��    FIELD_SYSTEM_ALARM_SENDC_INTERVAL
  */
#define     SERVICE_SYSTEM_GET_SENDINFO                    25023

/**�õ�װ�ü��м����Ϣ
  *���ص��ֶ��룺
  *         ��˾ID        FIELD_SYSTEM_COMPANY
  *         �ֳ�����      FIELD_SYSTEM_FACTORY
  *         װ����ID      FIELD_SYSTEM_SET
  *         ��Ϣ�ṹ��    FIELD_SYSTEM_SETSVR_SETINFO
  *         �ṹ�峤��    FIELD_SERVICE_LEN
  */
#define    SERVICE_SYSTEM_GET_SETSVRINFO                25024

/**�õ�װ�ü��м�����������豸��ϸ��Ϣ
  *���ص��ֶ��룺
  *        �豸��Ϣ  FIELD_SYSTEM_SETSVR_PLANTINFO
  */
#define    SERVICE_SYSTEM_GET_SETSVRPLANTINFO           25025

/**�õ�װ�ü��м��������ָ���豸�Ĳ����ϸ��Ϣ
  * �����ֶ��룺
  *        ��˾ID        FIELD_SYSTEM_COMPANY
  *	       �ֳ���        FIELD_SYSTEM_FACTORY
  *        �豸�ţ�      FIELD_SYSTEM_PLANT
  *���ص��ֶ��룺
  *        �����Ϣ      FIELD_SYSTEM_SETSVR_CHANNINFO
  *        �����Ϣ����  FIELD_SERVICE_LEN
  */
#define    SERVICE_SYSTEM_GET_SETSVRSPECPLANTCHANN      25026

/**�õ������û���Ϣ
  *�����ֶ��룺
  *�����ֶ��룺
  *            �û���         FIELD_SYSTEM_USEID
  *            ����           FIELD_SYSTEM_PASSWORD
  *            �û�����       FIELD_SYSTEM_USER_LEVEL
  *            ���ڷֳ�       FIELD_SYSTEM_SUBCORP
  *            װ����ID       FIELD_SYSTEM_SET
  *            �Ƿ����װ��   FIELD_SYSTEM_BROWSE_SET
  *            ˢ��ʱ�� FIELD_SYSTEM_REFRESHTIME
  */
#define    SERVICE_SYSTEM_GET_ALLUSERINFO               25027

/**�õ������м��������IP,�˿ں�������Ϣ.
  �м���������ļ���
  GE_SRV_TYPE_SET,          ///װ�ü��м��������
  GE_SRV_TYPE_COMPANY,      ///��˾���м��������
  GE_SRV_TYPE_GROUP         ///���ż��м��������
  *�����ֶ�:
  *        ��˾ID        FIELD_SYSTEM_COMPANY
  *�����ֶΣ�
  *        �м��ID         FIELD_SYSTEM_SET
  *        �м��IP         FIELD_SYSTEM_MW_IP
  *        �м��Port       FIELD_SYSTEM_MW_PORT
  *        �м������       FIELD_SYSTEM_USER_LEVEL
  */
#define  SERVICE_SYSTEM_GET_MW_INFO                   25028

/** ��ȡ���������·���Ͱ汾��
  *��������ֶ��룺��
  *����ֵ���ֶ��룺(n)
  *            ������                 FIELD_SERVICE_MODULE_NAME
  *            �ļ���                 FIELD_SERVICE_FILE_NAME
  *            ·��                   FIELD_SERVICE_FILE_PATH
  *            �汾��                 FIELD_SERVICE_FILE_VERSION
  *\instance ��:
      [JSON]
      "MiddleWare" : {
         "POSITION" : "E:\\Project\\lib\\S_SystemSvr.dll",
         "POSITION1" : "E:\\Project\\lib\\S_OnlineSvr.dll",
         "POSITION2" : "E:\\Project\\lib\\S_OfflineSvr.dll",
         "S_OfflineSvr.dll" : "3.5.0",
         "S_OnlineSvr.dll" : "3.5.0",
         "S_SystemSvr.dll" : "3.5.0"
      },

      [�м��ͨ�����ݸ�ʽ]
      "MiddleWare"
      "S_OfflineSvr.dll"
      "E:\\Project\\lib\\S_OfflineSvr.dll"
      "3.5.0"
     $
      "MiddleWare"
      "S_OnlineSvr.dll"
      "E:\\Project\\lib\\S_OnlineSvr.dll"
      "3.5.0"
     $
      "MiddleWare"
      "S_SystemSvr.dll"
      "E:\\Project\\lib\\S_SystemSvr.dll"
      "3.5.0"
  */
#define     SERVICE_SYSTEM_GET_MODULE_VERSION                 25029

/** ��ȡ�������ݿ�״̬
  *��������ֶ��룺��
  *����ֵ���ֶ��룺(n)
  *     ��������Ԥ�Ʊ���ʱ��,��λ ��(AlarmDataSavingTime)     FIELD_SERVICE_ALARM_DATA_ESTIMATE_SVAE_TIME
  *     ��������Ԥ�Ʊ���ʱ��(DataSavingTime)                  FIELD_SERVICE_ALARM_TREND_ESTIMATE_SVAE_TIME
  *     ��������������Ԥ�Ʊ���ʱ��(TrendDataSavingTime)       FIELD_SERVICE_ALARM_DATA_TREND_ESTIMATE_SVAE_TIME
  *     ���ݿ���Ŀ(DBNum)                                     FIELD_SERVICE_DB_NUM
  *     ���ݿ��ļ����,��0, �����ݿ��ļ��� 1�������ļ�1, ...  FIELD_SERVICE_DB_INDEX
  *     �����ļ���(DBDataFileName)                            FIELD_SERVICE_DB_DATA_FILE_NAME
  *     �����ļ���С����λ GB(DBDataFileSize)                 FIELD_SERVICE_DB_DATA_FILE_SIZE
  *     ��־�ļ���(DBLogFileName)                             FIELD_SERVICE_DB_LOG_FILE_NAME
  *     ��־�ļ���С����λ GB(DBLogFileSize)                  FIELD_SERVICE_DB_LOG_FILE_SIZE
  *     ���ݿ���(DBName)                                      FIELD_SERVICE_DB_NAME
  *     ���ݿ����ͣ�0��ʾ���⣬1��ʾ�ֿ�(DBType)              FIELD_SERVICE_DB_TYPE
  *     ���ݿ����ڴ���ʣ��ռ䣬��λΪGB(LeftDiskSpace)       FIELD_SERVICE_FREE_DISK_SPACE
  *     ���ݿ����ڴ���ʣ��ռ��(LeftDiskSpaceRate)           FIELD_SERVICE_FREE_DISK_SPACE_RATIO
  *     ǰһ���������ı�CSV��ʽ(TheFastIncTableName)      FIELD_SERVICE_FAST_INC_TABLE
  *     ���ݿ����ڴ����ܿռ䣬��λΪGB(TotalDiskSpace)        FIELD_SERVICE_TOTAL_DISK_SPACE
  */
#define     SERVICE_SYSTEM_GET_DB_STATUS                      25030

/** ��ȡ�м������״̬
  *��������ֶ��룺��
  *����ֵ���ֶ��룺(1)
  *            ���ݿ�״̬             FIELD_SERVICE_DB_STATUS
  *            �������ݵĹ�˾��       FIELD_SYSTEM_COMPANY
  *            �������ݵķֳ���       FIELD_SYSTEM_FACTORY
  *            �������ݵ��豸��Ŀ     FIELD_SERVICE_DATA_RCV_PLANT_NUM
  *            �������ݵ��豸״̬     FIELD_SERVICE_DATA_RCV_STATUS
  *            �������ݵ��豸��Ŀ     FIELD_SERVICE_DATA_SAVE_PLANT_NUM
  *            �������ݵ��豸״̬     FIELD_SERVICE_DATA_SAVE_STATUS
  *            ͬ�����ݵ��豸��Ŀ     FIELD_SERVICE_DATA_SYNC_PLANT_NUM
  *            ͬ�����ݵ��豸״̬     FIELD_SERVICE_DATA_SYNC_STATUS
  *
  *\description ����˵����
  *            ���ݿ�״̬,     ���� GE_DB_STATUS
  *            �������ݵ��豸״̬������ BUFFER, BHMWDataRcvStatus[]
  *            �������ݵ��豸״̬������ BUFFER, BHMWDataSaveStatus[]
  *            ͬ�����ݵ��豸״̬������ BUFFER, BHMWDataSyncStatus[]
  */
#define     SERVICE_SYSTEM_GET_SERVER_STATUS                  25031


/** ��ȡ����Ӳ��״̬
  *�������ֵ����
  *����ֵ���ֶ��룺(n)
  *            ���ɿ�����             FIELD_SERVICE_DAQ_CARD_INDEX
  *            ���ɿ�����             FIELD_SERVICE_DAQ_CARD_NUM
  *            ���ɿ��߼�����         FIELD_SERVICE_DAQ_CARD_NAME
  *            ʹ��AIͨ��(CSV)        FIELD_SERVICE_DAQ_USED_AI_CHANNEL
  *            ʹ��CIͨ��(CSV)        FIELD_SERVICE_DAQ_USED_CI_CHANNEL
  *            ����״��(�ַ�������)   FIELD_SERVICE_DAQ_CARD_STATUS
  *            ��ȡ����Ӳ��״̬ʱ��   FIELD_SERVICE_OFF_TIME
  */
  #define     SERVICE_SYSTEM_GET_DAQ_HW_STATUS                  25032

/** ��ȡ�������״̬
  *�������ֵ����
  *����ֵ���ֶ��룺(1)
  *            �汾��                                   FIELD_SERVICE_DAQ_SW_VERSION
  *            �ɼ�ģʽ                                 FIELD_SERVICE_DAQ_ACQUIRE_TYPE
  *            ����ʱ��                                 FIELD_SERVICE_TIME
  *            ���һ�������ݷ���ʱ��                 FIELD_SERVICE_DAQ_VIB_TIME
  *            ���һ�ζ�̬���ݷ���ʱ��                 FIELD_SERVICE_DAQ_DYN_TIME
  *            ���һ�ι��������ݷ���ʱ��               FIELD_SERVICE_DAQ_PROC_TIME
  *            ���ռ�϶��ѹ״̬                         FIELD_SERVICE_DAQ_GAP_RCV_STATUS
  *            ���һ�ζ������ݷ��Ϳ�ʼʱ��             FIELD_SERVICE_DAQ_OFFLINE_SAVE_BEGIN_TIME
  *            ���һ�ζ������ݷ��ͽ���ʱ��             FIELD_SERVICE_DAQ_OFFLINE_SAVE_END_TIME
  *            ��ȡ�������״̬ʱ��                     FIELD_SERVICE_OFF_TIME
  */
#define     SERVICE_SYSTEM_GET_DAQ_SW_STATUS                  25033


/** ��ȡ��������̬Ϣ
  * �������ֵ����
  * ����ֵ���ֶ��룺(1)
  *          ��������(������0��ʾδ����)                FIELD_SERVICE_CONFIG_ALARM
  *          ���ӵ����ݿ�                               FIELD_SERVICE_CONFIG_CONNECTED_DB
  *          ������������(������0��ʾδ����)            FIELD_SERVICE_CONFIG_DATA_SAVING
  *          ͬ����������(������0��ʾδ����)            FIELD_SERVICE_CONFIG_DATA_SYNC
  *          �м����������(0��ʾװ�ü���1��ʾ���ļ�)   FIELD_SERVICE_CONFIG_SERVER_TYPE
  *          ͳ����Ϣ��˾��Ŀ                           FIELD_SERVICE_COMPANY_NUM
  *          ͳ����Ϣ�豸��Ŀ                           FIELD_SERVICE_PLANT_NUM
  *          ͳ����Ϣ�����Ŀ                           FIELD_SERVICE_CHANN_NUM
*/
#define     SERVICE_SYSTEM_GET_BASIC_CONFIG_INFO              25034


/**��֤�Ƿ��м���Ƿ���ͨ�������ͨ�򷵻�ֵΪ1��
  *�����ֶ��룺
  *�����ֶ��룺
  *          ״̬     FIELD_SYSTEM_STATUS
  */
#define    SERVICE_SYSTEM_CONN_STATUS                   25100


/**�õ�ָ����������в����Ϣ��
  *input param�������� FIELD_SYSTEM_PLANT
  *return field code��
  *             ������ FIELD_SYSTEM_CHANN_ALIAS
  *             �����   FIELD_SYSTEM_CHANN
  *             ������� FIELD_SYSTEM_CHANN_TYPE
  *             �������� FIELD_SYSTEM_ALARM_HIGH
  *             �������� FIELD_SYSTEM_ALARM_LOW
  *             ״̬     FIELD_SYSTEM_STATUS
  *             ״̬���� FIELD_SYSTEM_STATUS_DISCRIPTION
  */
#define    SERVICE_SYSTEM_GET_CHANNINFO                25108

/**�õ�ָ���ֳ������л�����Ϣ��
  *input param: �ֳ���  FIELD_SYSTEM_SUBCORP
  *return field code��
  *          ������   FIELD_SYSTEM_PLANT
  *          �������� FIELD_SYSTEM_SAMPLE_NUM
  *          ����Ƶ�� FIELD_SYSTEM_SAMPLE_FREQ
  *          ���ݲɼ�����IP  FIELD_SYSTEM_DAQIP
  *          ״̬     FIELD_SYSTEM_STATUS
  *          ״̬���� FIELD_SYSTEM_STATUS_DISCRIPTION
  */
#define    SERVICE_SYSTEM_GET_PLANTINFO                25109

/**�õ�ָ�������ָ���������Ϣ
  *input param�������� FIELD_SYSTEM_PLANT
  *             ����� FIELD_SYSTEM_CHANN
  *return field code��
  *             ������ FIELD_SYSTEM_CHANN_ALIAS
  *             ������� FIELD_SYSTEM_CHANN_TYPE
  *             �������� FIELD_SYSTEM_ALARM_HIGH
  *             �������� FIELD_SYSTEM_ALARM_LOW
  *             ״̬     FIELD_SYSTEM_STATUS
  *             ״̬���� FIELD_SYSTEM_STATUS_DISCRIPTION
  */
#define    SERVICE_SYSTEM_GET_SPEC_CHANNINFO           25110

/**�õ�ָ���ֳ������л�����Ϣ��
  *input param: �ֳ���  FIELD_SYSTEM_SUBCORP
  *             ������   FIELD_SYSTEM_PLANT
  *return field code��
  *          �������� FIELD_SYSTEM_SAMPLE_NUM
  *          ����Ƶ�� FIELD_SYSTEM_SAMPLE_FREQ
  *          ���ݲɼ�����IP  FIELD_SYSTEM_DAQIP
  *          ת��     FIELD_SYSTEM_PLANT_REV
  *          ״̬     FIELD_SYSTEM_STATUS
  *          ״̬���� FIELD_SYSTEM_STATUS_DISCRIPTION
  */
#define    SERVICE_SYSTEM_GET_SPECPLANTINFO            25111

/**�õ�������ĵ��豸��Ϣ��
*���������   ��˾��    FIELD_SYSTEM_COMPANY
*             �ֳ���     FIELD_SYSTEM_FACTORY
*             �����     FIELD_SYSTEM_PLANT
*             ����     FIELD_SYSTEM_CHANN
*���ص��ֶ��룺
*             ����       FIELD_SYSTEM_STATUS
*             ��Ӧ����   FIELD_SYSTEM_STATUS_DISCRIPTION
*             ��λ       FIELD_SERVICE_CHANN1_UNIT
  */
#define    SERVICE_SYSTEM_GET_SETSVRMACHINEINFOTYPE      25112

/**�õ�������ĵ���Ϣ������
* �����ֶ��룺
*���ص��ֶ��룺
*        ��Ϣ����      FIELD_SYSTEM_TYPE
*        ��Ӧ����      FIELD_SYSTEM_STATUS_DISCRIPTION
*/
#define    SERVICE_SYSTEM_GET_SETSVRINFOTYPEDETAIL     25113

/**���ݲ����Ϣ����,�õ�������ĵ���Ϣ������
* �����ֶ��룺
*        ��Ϣ����   FIELD_SYSTEM_TYPE
*���ص��ֶ��룺
*        ����       FIELD_SYSTEM_STATUS
*        ��Ӧ����   FIELD_SYSTEM_STATUS_DISCRIPTION
*        ��λ       FIELD_SERVICE_CHANN1_UNIT
*/
#define    SERVICE_SYSTEM_GET_INFOTYPEDETAILBASETYPE     25114

/**�޸�ָ���豸ָ�����ı�����Ϣ�����Ϊ-1����ʾû���޸ĳɹ���Ϊ1��ʾ�޸ĳɹ�
*���������   ��˾��         FIELD_SYSTEM_COMPANY
*             �ֳ���         FIELD_SYSTEM_FACTORY
*             ������         FIELD_SYSTEM_PLANT
*             �����         FIELD_SYSTEM_CHANN
*             �Ƿ񳣹汨��   FIELD_SYSTEM_STATUS //1Ϊ�жϱ�����0Ϊ���жϱ���
*             ����������     FIELD_SYSTEM_EVENT_TYPE
*             ��������       FIELD_SYSTEM_ALARM_LOW
*             ����������     FIELD_SYSTEM_ALARM_HIGH
*             ��������       FIELD_SYSTEM_ALARM_LOW2
*             ����������     FIELD_SYSTEM_ALARM_HIGH2
*����ֵ���ֶ��룺
*             ����״̬       FIELD_SYSTEM_STATUS
*/
#define     SERVICE_SYSTEM_MODIFY_SPECCHANNALARMINFO       25115

/**�õ�������ĵ��Զ������ģ���
* �����ֶ��룺
*���ص��ֶ��룺
*         ��˾��                 FIELD_SYSTEM_COMPANY
*         �ֳ���                 FIELD_SYSTEM_FACTORY
*         װ����ID               FIELD_SYSTEM_SET
*         �豸��                 FIELD_SYSTEM_PLANT
*         �Զ������ģ��ID       FIELD_SYSTEM_TEMPID
*         �Զ�����Ϣ����         FIELD_SYSTEM_STATUS_DISCRIPTION
*/
#define    SERVICE_SYSTEM_GET_SETSVRTEMPLET      25116

/**�õ�������ĵ��Զ��������Ϣ��
*�������ֵ��
*���ز���ֵ��
*         ����ID                 FIELD_SYSTEM_STATUS
*         ��˾��                 FIELD_SYSTEM_COMPANY
*         �ֳ���                 FIELD_SYSTEM_FACTORY
*         װ����ID               FIELD_SYSTEM_SET
*         �豸��                 FIELD_SYSTEM_PLANT
*         �߼�����ģ��ID         FIELD_SYSTEM_TEMPID
*         ��������               FIELD_SYSTEM_DATA
*         ��λ����               FIELD_SYSTEM_UNIT
*         �źŷ�����ʽ           FIELD_SYSTEM_SIGNAL_TYPE
*         ����ʼ��               FIELD_SYSTEM_SEG_STARTNO
*         ����                   FIELD_SYSTEM_SEG_NUM
*         ����                   FIELD_SYSTEM_SEG_NAME
*         ������ʼֵ             FIELD_SYSTEM_START_VALUE
*         ���ݽ���ֵ             FIELD_SYSTEM_END_VALUE
*         ����ֵ����             FIELD_SYSTEM_CHAR_TYPE
*         Ԥ��������             FIELD_SYSTEM_TYPE
*         ����Ƶ����ʼֵ         FIELD_SYSTEM_BAND_STARTVALUE
*         ����Ƶ������ֵ         FIELD_SYSTEM_BAND_ENDVALUE
*         Ԥ�������K             FIELD_SERVICE_PREPROC_K
*         Ԥ�������B             FIELD_SERVICE_PREPROC_B
*         ��λ                   FIELD_SERVICE_UNIT
*/
#define    SERVICE_SYSTEM_GET_SETSVRCUSTOMPARAM      25117

/**�õ�������ĵ��Զ��������������ģ���
*�������ֵ��
*���ز���ֵ��
*         ��˾��                 FIELD_SYSTEM_COMPANY
*         �ֳ���                 FIELD_SYSTEM_FACTORY
*         װ����ID               FIELD_SYSTEM_SET
*         �豸��                 FIELD_SYSTEM_PLANT
*         �Զ������ģ��ID         FIELD_SYSTEM_TEMPID
*         �Զ��屨��ģ��ID         FIELD_SYSTEM_ALARM_TEMPID
*         �Զ��屨������           FIELD_SERVICE_ALARM_DISCRIPTION
*/
#define    SERVICE_SYSTEM_GET_SETSVRALARMTEMPLET      25118

/**�õ�������ĵ��Զ����������������Ϣ��
*�������ֵ��
*���ز���ֵ��
*         ����ID                 FIELD_SYSTEM_STATUS
*         ��˾��                 FIELD_SYSTEM_COMPANY
*         �ֳ���                 FIELD_SYSTEM_FACTORY
*         װ����ID               FIELD_SYSTEM_SET
*         �Զ��屨������ģ��ID   FIELD_SYSTEM_ALARM_TEMPID
*         �жϷ�ʽ               FIELD_SYSTEM_TYPE
*         ������ʽ               FIELD_SERVICE_ALARM_TYPE
*         ��������ʼ��           FIELD_SYSTEM_SEG_STARTNO
*         ����                   FIELD_SYSTEM_SEG_NUM
*         ����                   FIELD_SYSTEM_SEG_NAME
*         �Ƿ񱨾�               FIELD_SYSTEM_IF_ALARM
*         ��������               FIELD_SERVICE_ALARM_LOW
*         ��������               FIELD_SERVICE_ALARM_HIGH
*         ������                 FIELD_SYSTEM_ALARM_GROUP
*/
#define    SERVICE_SYSTEM_GET_SETSVRALARMPARAM      25119

/**�õ�������ĵ�ͨ���Զ����������������Ϣ��
*�������ֵ��
*���ز���ֵ��
*         ����ID                 FIELD_SYSTEM_STATUS
*         ��˾��                 FIELD_SYSTEM_COMPANY
*         װ����ID               FIELD_SYSTEM_SET
*         �豸��                 FIELD_SYSTEM_PLANT
*         ����                 FIELD_SYSTEM_CHANN
*         �жϷ�ʽ               FIELD_SYSTEM_TYPE
*         ������ʽ               FIELD_SERVICE_ALARM_TYPE
*         ��������ʼ��           FIELD_SYSTEM_SEG_STARTNO
*         ����                   FIELD_SYSTEM_SEG_NUM
*         ����                   FIELD_SYSTEM_SEG_NAME
*         �Ƿ񱨾�               FIELD_SYSTEM_IF_ALARM
*         ��������               FIELD_SERVICE_ALARM_LOW
*         ��������               FIELD_SERVICE_ALARM_HIGH
*         ������                 FIELD_SYSTEM_ALARM_GROUP
*/
#define    SERVICE_SYSTEM_GET_SETSVRCHANNELALARMPARAM     25120

/**�õ�ָ����˾���ֳ���װ��ID���Զ��������Ϣ
*�������ֵ��
*         ��˾��                 FIELD_SYSTEM_COMPANY
*         �ֳ���                 FIELD_SYSTEM_FACTORY
*         װ����ID               FIELD_SYSTEM_SET
*         �豸��                FIELD_SERVICE_PLANTID
*���ز���ֵ��
*         ��˾��                 FIELD_SYSTEM_COMPANY
*         �ֳ���                 FIELD_SYSTEM_FACTORY
*         װ����ID               FIELD_SYSTEM_SET
*         �豸��                 FIELD_SYSTEM_PLANT
*         ����ID                 FIELD_SYSTEM_STATUS
*         �߼�����ģ��ID         FIELD_SYSTEM_TEMPID
*         ��������               FIELD_SYSTEM_DATA
*         ��λ����               FIELD_SYSTEM_UNIT
*         �źŷ�����ʽ           FIELD_SYSTEM_SIGNAL_TYPE
*         ����ʼ��               FIELD_SYSTEM_SEG_STARTNO
*         ����                   FIELD_SYSTEM_SEG_NUM
*         ����                   FIELD_SYSTEM_SEG_NAME
*         ������ʼֵ             FIELD_SYSTEM_START_VALUE
*         ���ݽ���ֵ             FIELD_SYSTEM_END_VALUE
*         ����ֵ����             FIELD_SYSTEM_CHAR_TYPE
*/
#define    SERVICE_SYSTEM_GET_SPECSETSVRCUSTOMPARAM       25121

/**�õ�ָ����˾���ֳ���װ��ID���Զ����������������Ϣ
*�������ֵ��
*         ��˾��                 FIELD_SYSTEM_COMPANY
*         �ֳ���                 FIELD_SYSTEM_FACTORY
*         װ����ID               FIELD_SYSTEM_SET
*���ز���ֵ��
*         ����ID                 FIELD_SYSTEM_STATUS
*         �Զ��屨������ģ��ID   FIELD_SYSTEM_ALARM_TEMPID
*         �жϷ�ʽ               FIELD_SYSTEM_TYPE
*         ������ʽ               FIELD_SERVICE_ALARM_TYPE
*         ��������ʼ��           FIELD_SYSTEM_SEG_STARTNO
*         ����                   FIELD_SYSTEM_SEG_NUM
*         �Ƿ񱨾�               FIELD_SYSTEM_IF_ALARM
*         ��������               FIELD_SERVICE_ALARM_LOW
*         ��������               FIELD_SERVICE_ALARM_HIGH
*         ������                 FIELD_SYSTEM_ALARM_GROUP
*/
#define    SERVICE_SYSTEM_GET_SPECSETSVRALARMPARAM       25122

/**�õ�����������õ��Զ�����в�����
* �����ֶ��룺
*���ص��ֶ��룺
*         ��˾��                 FIELD_SYSTEM_COMPANY
*         �ֳ���                 FIELD_SYSTEM_FACTORY
*         װ����ID               FIELD_SYSTEM_SET
*         �豸��                 FIELD_SYSTEM_PLANT
*         �������ID             FIELD_SYSTEM_STATUS
*         �������               FIELD_SYSTEM_SEG_NAME
*         �������               FIELD_SYSTEM_TYPE
*         ������Ŀ               FIELD_SYSTEM_SEG_NUM
*         ����ֱ��               FIELD_SYSTEM_START_VALUE
*         �ھ�                   FIELD_SYSTEM_END_VALUE
*         ѹ����                 FIELD_SERVICE_ANGLEPARAM1
*         ���ֱ��               FIELD_SYSTEM_BAND_STARTVALUE
*         �ھ�                   FIELD_SYSTEM_BAND_ENDVALUE
*         ��������               FIELD_SYSTEM_AXISCHANN_NUM
*         ��д���               FIELD_SYSTEM_CHAR_TYPE
*         ͬ��״̬��ʶ           FIELD_SYSTEM_SENDC_IF
*         ��ע                   FIELD_SYSTEM_STATUS_DISCRIPTION
*/
#define    SERVICE_SYSTEM_GET_SETSVRCUSTOMBEARINGTBL     25123

/**�õ�������ĵĳ����������
*�������ֵ��
*���ز���ֵ��
*         ��˾��                 FIELD_SYSTEM_COMPANY
*         �ֳ���                 FIELD_SYSTEM_FACTORY
*         װ����ID               FIELD_SYSTEM_SET
*         �豸��                 FIELD_SYSTEM_PLANT
*         ����������ID           FIELD_SYSTEM_STATUS
*         ���������             FIELD_SYSTEM_TYPE
*         ����������             FIELD_SYSTEM_SEG_NAME
*         ���ǳ���������ʽ       FIELD_SYSTEM_CHAR_TYPE
*         ̫���ֳ���             FIELD_SERVICE_PLANT_NUM
*         �����ָ���             FIELD_SERVICE_ALARM_PLANTNUM
*         �����ֳ���             FIELD_SERVICE_RUN_PLANTNUM
*         ����ϵ����             FIELD_SERVICE_STOP_PLANTNUM
*         ���ּ���               FIELD_SYSTEM_USER_LEVEL
*         ����Z12                FIELD_SYSTEM_GEARNUMZ12
*         ����Z21                FIELD_SYSTEM_GEARNUMZ21
*         ����Z22                FIELD_SYSTEM_GEARNUMZ22
*         ����Z31                FIELD_SYSTEM_GEARNUMZ31
*         ����Z32                FIELD_SYSTEM_GEARNUMZ32
*         ����Z41                FIELD_SYSTEM_GEARNUMZ41
*         ����Z42                FIELD_SYSTEM_GEARNUMZ42
*         ����Z51                FIELD_SYSTEM_GEARNUMZ51
*         ����Z52                FIELD_SYSTEM_GEARNUMZ52
*         ����Z61                FIELD_SYSTEM_GEARNUMZ61
*         ͬ��״̬��ʶ           FIELD_SYSTEM_SENDC_IF
*         ��ע                   FIELD_SYSTEM_STATUS_DISCRIPTION
*/
#define    SERVICE_SYSTEM_GET_SETSVRGEARBOXTBL     25124

/**�õ�������ĵ�λ�ò�����
*�������ֵ��
*���ز���ֵ��
*         ��˾��                 FIELD_SYSTEM_COMPANY
*         �ֳ���                 FIELD_SYSTEM_FACTORY
*         װ����ID               FIELD_SYSTEM_SET
*         �豸��                 FIELD_SYSTEM_PLANT
*         λ������ID             FIELD_SYSTEM_STATUS
*         λ������               FIELD_SYSTEM_SEG_NAME
*         ��λ����ID             FIELD_SYSTEM_CHANN_TYPE
*         �������ID             FIELD_SYSTEM_TYPE
*         ��б�����             FIELD_SYSTEM_CHAR_TYPE
*         ���                   FIELD_SYSTEM_SEG_NUM
*         ��ע                   FIELD_SYSTEM_STATUS_DISCRIPTION
*         λ�ú�                 FIELD_SERVICE_LOCATION_NO
*/
#define    SERVICE_SYSTEM_GET_SETSVRLOCATIONTBL      25125

/**�õ�������ĵĲ�λ������
*�������ֵ��
*���ز���ֵ��
*         ��˾��                 FIELD_SYSTEM_COMPANY
*         �ֳ���                 FIELD_SYSTEM_FACTORY
*         װ����ID               FIELD_SYSTEM_SET
*         �豸��                 FIELD_SYSTEM_PLANT
*         ��λ����ID             FIELD_SYSTEM_STATUS
*         ��λ����               FIELD_SYSTEM_SEG_NAME
*         ����������ID           FIELD_SYSTEM_TYPE
*         ��ע                   FIELD_SYSTEM_STATUS_DISCRIPTION
*         ��������               FIELD_SERVICE_FUNCTION_TYPE
*         ��λ����               FIELD_SERVICE_SECTION_TYPE
*         ��ǰλ��               FIELD_SERVICE_LOC_IDX
*         ǰһ��λ               FIELD_SERVICE_PREV_SEC_IDX
*         ǰһλ��               FIELD_SERVICE_PREV_LOC_IDX
*         ��λͼƬ               FIELD_SERVICE_PREV_SECTION_PIC
*/
#define    SERVICE_SYSTEM_GET_SETSVRSECTIONTBL      25126

/**�õ��м���İ汾��
*�������ֵ��
*���ز���ֵ��
*         �汾��                 FIELD_SERVICE_FILE_VERSION
		  �м����ǰʱ��         FIELD_SERVICE_TIME
*/

#define   SERVICE_SYSTEM_GET_MILLDLEWARE_VERSION     25127


/***************************ר��ϵͳ���ܲ���*******************************/

/**�õ�ָ������IDʱ,ר�����ϵͳ������ȡ��֪ʶ
*���������   ��˾��     FIELD_SYSTEM_COMPANY
*             �ֳ���     FIELD_SYSTEM_FACTORY
*             �����     FIELD_SERVICE_PLANTID
*             ����ID     FIELD_SERVICE_ALARMID
*             ���ID     FIELD_SERVICE_CHANN1
*             ʱ��       FIELD_SERVICE_OFF_TIME
*���ص��ֶ��룺
*             ����ͨ��   FIELD_SERVICE_OFF_CHANN1
*             ����ת��   FIELD_SERVICE_OFF_REV
*             ��ʵID     FIELD_SERVICE_EX_RULEID     //��ӦΪ�ַ���
*             ��Ӧ��ֵ   FIELD_SERVICE_EX_IDVALUE    //��ӦΪint��
*/
#define    SERVICE_EXPERTSYS_GET_REGALARMFEATUREEXTRACT      30001

/**�õ�ָ���񶯲�㡢ѡ��ʱ���ʱ,ר�����ϵͳ������ȡ��֪ʶ
*���������   ��˾��     FIELD_SYSTEM_COMPANY
*             �ֳ���     FIELD_SYSTEM_FACTORY
*             �����     FIELD_SERVICE_PLANTID
*             ���ID     FIELD_SERVICE_CHANN1
*             ��ʼʱ��   FIELD_SERVICE_OFF_TIMESTART
*             ��ֹʱ��   FIELD_SERVICE_OFF_TIMEEND
*���ص��ֶ��룺
*             ��ʵID     FIELD_SERVICE_EX_RULEID     //��ӦΪ�ַ���
*             ��Ӧ��ֵ   FIELD_SERVICE_EX_IDVALUE    //��ӦΪint��
*/
#define    SERVICE_EXPERTSYS_GET_SPECCHANNFEATUREEXTRACT      30002


/**�õ�ָ���񶯲�㡢ѡ��ʱ���ʱ,ר�����ϵͳ������ȡ��֪ʶ
*���������   ��˾��     FIELD_SYSTEM_COMPANY
*             �ֳ���     FIELD_SYSTEM_FACTORY
*             �����     FIELD_SERVICE_PLANTID
*             ���ID     FIELD_SERVICE_CHANN1
*             ��ʼʱ��   FIELD_SERVICE_OFF_TIMESTART
*             ��ֹʱ��   FIELD_SERVICE_OFF_TIMEEND
*���ص��ֶ��룺
*             ��ʵID     FIELD_SERVICE_EX_RULEID     //��ӦΪ�ַ���
*             ��Ӧ��ֵ   FIELD_SERVICE_EX_IDVALUE    //��ӦΪint��
*/
#define    SERVICE_EXPERTSYS_GET_SPECCHANNFEATUREEXTRACT_RC      30003

/** һ�εõ�ȫ�����豸��Ϣ
*��������� ��ʼ����     FIELD_SERVICE_STARTINDEX
*����ֵ���ֶ��룺
*          ��˾��     FIELD_SYSTEM_COMPANY
*          �ֳ���     FIELD_SYSTEM_FACTORY
*          �����     FIELD_SYSTEM_PLANT
*          ��òͼ���� FIELD_SYSTEM_PLANT_GRAPHTYPE
*          ���ż�IP   FIELD_SYSTEM_GROUP_MW_IP
*          ���ż�Port FIELD_SYSTEM_GROUP_MW_PORT
*          ��˾��IP   FIELD_SYSTEM_COMPANY_MW_IP
*          ��˾��Port FIELD_SYSTEM_COMPANY_MW_PORT
*          װ�ü�IP   FIELD_SYSTEM_MW_IP
*          װ�ü�Port FIELD_SYSTEM_MW_PORT
*          װ�ü��м��ID   FIELD_SYSTEM_SET
*          �豸����   FIELD_SYSTEM_TYPE
*          ����Դ     FIELD_SYSTEM_DATASOURCE
*		   ���������� FIELD_SERVICE_ENDINDEX
*/
#define    SERVICE_SYSTEM_GETPLANTIPOFSUBCORP_EX      25210 


/**���ض�ƽ������
*  ��������ֶ��룺
*                ��˾��         FIELD_SYSTEM_COMPANY
*                �ֳ���         FIELD_SYSTEM_FACTORY
*                �豸��         FIELD_SERVICE_PLANTID  
				 ��¼ʱ�俪ʼ   FIELD_SERVICE_OFF_TIME
				 ��¼ʱ�����   FIELD_SERVICE_OFF_TIMEEND
				 BALANCE_TYPE   FIELD_SERVICE_OFF_BALANCE_TYPE       0���� 1˫��
*   ����ֵ���ֶ��룺
*               ��¼ʱ��       FIELD_SERVICE_OFF_TIME
*               �����         FIELD_SYSTEM_CHANN
*				�����2        FIELD_SYSTEM_CHANN2
*               BUFFER1        FIELD_SERVICE_OFF_DATA_CHANN_1 
*				BUFFER2        FIELD_SERVICE_OFF_DATA_CHANN_2 
*				BUFFER1����    FIELD_SERVICE_OFF_DATA_CHANN_1_LEN   �ֽ�
*				BUFFER2����    FIELD_SERVICE_OFF_DATA_CHANN_2_LEN   �ֽ�                     
*/
#define     SERVICE_SERVICE_OFF_GET_BALANCE_DATA 24063


/**���ն�ƽ������
*��������ֶ��룺
*                ��˾��         FIELD_SYSTEM_COMPANY
*                �ֳ���         FIELD_SYSTEM_FACTORY
*                �豸��         FIELD_SERVICE_PLANTID  
*                ��¼ʱ��       FIELD_SERVICE_OFF_TIME
*                �����         FIELD_SYSTEM_CHANN
				 �����2        FIELD_SYSTEM_CHANN2
*                BUFFER1        FIELD_SERVICE_OFF_DATA_CHANN_1 
				 BUFFER2        FIELD_SERVICE_OFF_DATA_CHANN_2 
				 BUFFER1����    FIELD_SERVICE_OFF_DATA_CHANN_1_LEN   �ֽ�
				 BUFFER2����    FIELD_SERVICE_OFF_DATA_CHANN_2_LEN   �ֽ�
				 BALANCE_TYPE   FIELD_SERVICE_OFF_BALANCE_TYPE       0���� 1˫��
*����ֵ���ֶ��룺
*                ͬ��״̬      FIELD_SYSTEM_STATUS               1,����ɹ� 0������ʧ��                 
*/
#define     SERVICE_SERVICE_OFF_SET_BALANCE_DATA 24062    



/**������Ϣȷ��
*��������ֶ��룺
*                ��˾��         FIELD_SYSTEM_COMPANY
*                �ֳ���         FIELD_SYSTEM_FACTORY
*                �豸��         FIELD_SERVICE_PLANTID  
*                ��¼ʱ��       FIELD_SERVICE_OFF_TIME
*                �����         FIELD_SYSTEM_CHANN
				 �����2        FIELD_SYSTEM_CHANN2
*                BUFFER1        FIELD_SERVICE_OFF_DATA_CHANN_1 
				 BUFFER2        FIELD_SERVICE_OFF_DATA_CHANN_2 
				 BUFFER1����    FIELD_SERVICE_OFF_DATA_CHANN_1_LEN   �ֽ�
				 BUFFER2����    FIELD_SERVICE_OFF_DATA_CHANN_2_LEN   �ֽ�
				 BALANCE_TYPE   FIELD_SERVICE_OFF_BALANCE_TYPE       0���� 1˫��
*����ֵ���ֶ��룺
*                ͬ��״̬      FIELD_SYSTEM_STATUS               1,����ɹ� 0������ʧ��                 
*/
#define     SERVICE_SERVICE_OFF_SET_ALARM_CONFIRM_DATA 24066  

/////////////
#endif

