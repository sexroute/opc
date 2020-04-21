#if !defined(AFX_FIXCODE_H_INCLUDED_)
#define AFX_FIXCODE_H_INCLUDED_
//-----------------------------------------------------------------------------
//            FIX ��׼��ͷ���� 
//-----------------------------------------------------------------------------
#define FIXCODE_BEGINSTRING               8  // ��ʼ�ַ���          δ���ܣ���Ϊ��һ����   
#define FIXCODE_BODYLENGTH                9  // ���ĳ���            δ���ܣ���Ϊ�ڶ�����   
#define FIXCODE_MSGTYPE                  35  // ��Ϣ����            δ���ܣ���Ϊ��������     
#define FIXCODE_SENDERCOMPID             49  // �����˱�ʶ��        δ����       
#define FIXCODE_RECIVERCOMPID            56  // �����˱�ʶ��        δ����   
#define FIXCODE_SECUREDATALEN            90  // ���ĳ���            δ����
#define FIXCODE_SECUREDATA               91  // ����                �������ĳ�����
#define FIXCODE_MSGSEQNUM                34  // ��Ϣ���            �ɼ���    (δ����)
#define FIXCODE_POSSDUPFLAG              43  // �ظ���־            �ɼ���    (δ����)
#define FIXCODE_POSSRESEND               97  // �ط���־            �ɼ���    (δ����)
#define FIXCODE_SENDINGTIME              52  // ����ʱ��            �ɼ���    (δ����)
#define FIXCODE_LASTMSGSEQNUMPROCESSED  369  // �Ѵ���������Ϣ    �ɼ������(δ����)
#define FIXCODE_ORIGINALSIZE            101  // ����ԭ����      
#define FIXCODE_COMPRESSSIZE            102  // ����ѹ���󳤶�      
//-----------------------------------------------------------------------------
//˵��:
//    ��ʼ�ַ������������:
//    �汾��|����Ա����|ί����Դ|���������ַ|Ӫҵ�����|Ŀ��Ӫҵ��
//-----------------------------------------------------------------------------
#define FIXCODE_RECNO                     55  // �ظ���Ϣ��ǰ���
#define FIXCODE_RETCODE                 5001  // 
#define FIXCODE_RETNOTE                 5002  //   

#endif