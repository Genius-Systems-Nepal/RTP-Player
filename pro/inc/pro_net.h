#if !defined(____PRO_NET_H____)
#define ____PRO_NET_H____

#include <cstddef>

#if !defined(____PRO_A_H____)
#define ____PRO_A_H____
#define PRO_INT16_VC    short
#define PRO_INT32_VC    int
#define PRO_INT64_VC    __int64
#define PRO_UINT16_VC   unsigned short
#define PRO_UINT32_VC   unsigned int
#define PRO_UINT64_VC   unsigned __int64
#define PRO_CDECL_VC    __cdecl
#define PRO_STDCALL_VC  __stdcall
#define PRO_EXPORT_VC   __declspec(dllexport)
#define PRO_IMPORT_VC   __declspec(dllimport)
#define PRO_INT16_GCC   short
#define PRO_INT32_GCC   int
#define PRO_INT64_GCC   long long
#define PRO_UINT16_GCC  unsigned short
#define PRO_UINT32_GCC  unsigned int
#define PRO_UINT64_GCC  unsigned long long
#define PRO_CDECL_GCC   __attribute__((__cdecl__))
#define PRO_STDCALL_GCC __attribute__((__stdcall__))
#define PRO_EXPORT_GCC  __attribute__((visibility("default")))
#define PRO_IMPORT_GCC
#if defined(_MSC_VER)
#if !defined(PRO_INT16)
#define PRO_INT16   PRO_INT16_VC
#endif
#if !defined(PRO_INT32)
#define PRO_INT32   PRO_INT32_VC
#endif
#if !defined(PRO_INT64)
#define PRO_INT64   PRO_INT64_VC
#endif
#if !defined(PRO_UINT16)
#define PRO_UINT16  PRO_UINT16_VC
#endif
#if !defined(PRO_UINT32)
#define PRO_UINT32  PRO_UINT32_VC
#endif
#if !defined(PRO_UINT64)
#define PRO_UINT64  PRO_UINT64_VC
#endif
#if !defined(PRO_CDECL)
#define PRO_CDECL   PRO_CDECL_VC
#endif
#if !defined(PRO_STDCALL)
#define PRO_STDCALL PRO_STDCALL_VC
#endif
#if !defined(PRO_EXPORT)
#define PRO_EXPORT  PRO_EXPORT_VC
#endif
#if !defined(PRO_IMPORT)
#define PRO_IMPORT  PRO_IMPORT_VC
#endif
#else //// _MSC_VER
#if !defined(PRO_INT16)
#define PRO_INT16   PRO_INT16_GCC
#endif
#if !defined(PRO_INT32)
#define PRO_INT32   PRO_INT32_GCC
#endif
#if !defined(PRO_INT64)
#define PRO_INT64   PRO_INT64_GCC
#endif
#if !defined(PRO_UINT16)
#define PRO_UINT16  PRO_UINT16_GCC
#endif
#if !defined(PRO_UINT32)
#define PRO_UINT32  PRO_UINT32_GCC
#endif
#if !defined(PRO_UINT64)
#define PRO_UINT64  PRO_UINT64_GCC
#endif
#if !defined(PRO_CDECL)
#define PRO_CDECL
#endif
#if !defined(PRO_STDCALL)
#define PRO_STDCALL
#endif
#if !defined(PRO_EXPORT)
#define PRO_EXPORT  PRO_EXPORT_GCC
#endif
#if !defined(PRO_IMPORT)
#define PRO_IMPORT  PRO_IMPORT_GCC
#endif
#endif //// _MSC_VER
#endif //// ____PRO_A_H____

#if !defined(____PRO_EXTERN_C_H____)
#define ____PRO_EXTERN_C_H____
#if defined(__cplusplus)
#define PRO_EXTERN_C1 extern "C" {
#define PRO_EXTERN_C2 }
#else //// __cplusplus
#define PRO_EXTERN_C1
#define PRO_EXTERN_C2
#endif //// __cplusplus
#endif //// ____PRO_EXTERN_C_H____

PRO_EXTERN_C1

/////////////////////////////////////////////////////////////////////////////
////

#if defined(PRO_NET_LIB)
#define PRO_NET_API
#elif defined(PRO_NET_EXPORTS)
#if defined(_MSC_VER)
#define PRO_NET_API //// .def
#else
#define PRO_NET_API PRO_EXPORT
#endif
#else
#define PRO_NET_API PRO_IMPORT
#endif

class IProAcceptor;      //// ������
class IProConnector;     //// ������
class IProOnTimer;       //// ��ʱ�¼�������
class IProTcpHandshaker; //// tcp������

////
//// [[[[ ��������
////
typedef unsigned char PRO_TRANS_TYPE;

static const PRO_TRANS_TYPE PRO_TRANS_TCP   = 1;
static const PRO_TRANS_TYPE PRO_TRANS_UDP   = 2;
static const PRO_TRANS_TYPE PRO_TRANS_MCAST = 3;
////
//// ]]]]
////

/////////////////////////////////////////////////////////////////////////////
////

////
//// ��Ӧ��
////
//// ����ֻ��¶�˶�ʱ���ӿ�,Ŀ����Ϊ����ʹ�÷�Ӧ����ʱ��,���Է����
//// ʹ�����ڲ��Ķ�ʱ������,��û�Ҫ���������CProTimerFactory����
////
class IProReactor
{
public:
    
    ////
    //// ����һ����ͨ��ʱ��
    ////
    //// ����ֵΪ��ʱ��id,0��Ч
    ////
    virtual unsigned long PRO_STDCALL ScheduleTimer(
        IProOnTimer* onTimer,
        PRO_UINT64   timeSpan, //// ��ʱ����(ms)
        bool         recurring //// �Ƿ��ظ�
        ) = 0;
    
    ////
    //// ɾ��һ����ͨ��ʱ��
    ////
    virtual void PRO_STDCALL CancelTimer(unsigned long timerId) = 0;
    
    ////
    //// ����һ����ý�嶨ʱ��
    ////
    //// ����ֵΪ��ʱ��id,0��Ч
    ////
    virtual unsigned long PRO_STDCALL ScheduleMmTimer(
        IProOnTimer* onTimer,
        PRO_UINT64   timeSpan, //// ��ʱ����(ms)
        bool         recurring //// �Ƿ��ظ�
        ) = 0;
    
    ////
    //// ɾ��һ����ý�嶨ʱ��
    ////
    virtual void PRO_STDCALL CancelMmTimer(unsigned long timerId) = 0;
};

/////////////////////////////////////////////////////////////////////////////
////

////
//// �������ص�Ŀ��
////
//// ʹ������Ҫʵ�ָýӿ�
////
class IProAcceptorObserver
{
public:
    
    virtual unsigned long PRO_STDCALL AddRef() = 0;
    
    virtual unsigned long PRO_STDCALL Release() = 0;
    
    ////
    //// �����ӽ���ʱ,�ú��������ص�
    ////
    virtual void PRO_STDCALL OnAccept(
        IProAcceptor*  acceptor,
        long           sockId, //// -1��Ч,����ʧ��
        const char*    remoteIp,
        unsigned short remotePort
        ) = 0;
};

/////////////////////////////////////////////////////////////////////////////
////

////
//// �������ص�Ŀ��
////
//// ʹ������Ҫʵ�ָýӿ�
////
class IProConnectorObserver
{
public:
    
    virtual unsigned long PRO_STDCALL AddRef() = 0;
    
    virtual unsigned long PRO_STDCALL Release() = 0;
    
    ////
    //// ���ӳɹ�������ʧ��ʱ,�ú��������ص�
    ////
    virtual void PRO_STDCALL OnConnect(
        IProConnector* connector,
        long           sockId, //// -1��Ч,����ʧ��
        const char*    remoteIp,
        unsigned short remotePort
        ) = 0;
};

/////////////////////////////////////////////////////////////////////////////
////

////
//// tcp�������ص�Ŀ��
////
//// ʹ������Ҫʵ�ָýӿ�
////
class IProTcpHandshakerObserver
{
public:
    
    virtual unsigned long PRO_STDCALL AddRef() = 0;
    
    virtual unsigned long PRO_STDCALL Release() = 0;
    
    ////
    //// �������ݵִ�ʱ,�ú��������ص�
    ////
    //// ������ɺ�,ʹ����Ӧ�ð�sockId��װ��(IProTransport*),
    //// ���ͷ�sockId��Ӧ���׽�����Դ
    ////
    virtual void PRO_STDCALL OnHandshake(
        IProTcpHandshaker* handshaker,
        long               sockId, //// -1��Ч,����ʧ��
        const void*        buf,
        unsigned long      size
        ) = 0;
};

/////////////////////////////////////////////////////////////////////////////
////

////
//// ���ճ�
////
//// ������IProTransportObserver::OnRecv(...)���߳���������ʹ��,���򲻰�ȫ
////
//// ����tcp,ʹ�û��ͽ��ճ�.
//// ����tcp����ʽ������,�ն˶����뷢�˶�����һ����ͬ,����,��OnRecv(...)����뾡���ܵ�
//// ����ȫ������,�����߼������ݻ�������;����,�����ճ����˲��ҵײ��׽��������ݵִ�ʱ,
//// ��Ӧ����һֱ���������ݵִ�(���ǹ����������),����cpu����
////
//// ����udp,ʹ�����Խ��ճ�.
//// Ϊ��ֹEMSGSIZE����,��OnRecv(...)���������ȫ������
////
class IProRecvPool
{
public:
    
    ////
    //// ��ѯ�յ����ֽ���
    ////
    virtual unsigned long PRO_STDCALL PeekDataSize() const = 0;
    
    ////
    //// �����յ�������
    ////
    virtual void PRO_STDCALL PeekData(void* buf, unsigned long size) const = 0;
    
    ////
    //// ˢ���Ѿ����Ƶ�����
    ////
    //// �ڳ��ռ�,�Ա�����µ�����
    ////
    virtual void PRO_STDCALL Flush(unsigned long size) = 0;
};

////
//// ������
////
class IProTransport
{
public:
    
    ////
    //// ��ȡ��������
    ////
    virtual PRO_TRANS_TYPE PRO_STDCALL GetType() const = 0;
    
    ////
    //// ��ȡ�ײ���׽���id
    ////
    //// ��Ǳ���,��ò�Ҫֱ�Ӳ����ײ���׽���
    ////
    virtual long PRO_STDCALL GetSockId() const = 0;
    
    ////
    //// ��ȡ�׽��ֵı���ip��ַ
    ////
    virtual const char* PRO_STDCALL GetLocalIp(char localIp[64]) const = 0;
    
    ////
    //// ��ȡ�׽��ֵı��ض˿ں�
    ////
    virtual unsigned short PRO_STDCALL GetLocalPort() const = 0;
    
    ////
    //// ��ȡ�׽��ֵ�Զ��ip��ַ
    ////
    //// ����tcp,�������ӶԶ˵�ip��ַ;
    //// ����udp,����Ĭ�ϵ�Զ��ip��ַ
    ////
    virtual const char* PRO_STDCALL GetRemoteIp(char remoteIp[64]) const = 0;
    
    ////
    //// ��ȡ�׽��ֵ�Զ�˶˿ں�
    ////
    //// ����tcp,�������ӶԶ˵Ķ˿ں�;
    //// ����udp,����Ĭ�ϵ�Զ�˶˿ں�
    ////
    virtual unsigned short PRO_STDCALL GetRemotePort() const = 0;
    
    ////
    //// ��ȡ���ճ�
    ////
    //// �μ�IProRecvPool��ע��
    ////
    virtual IProRecvPool* PRO_STDCALL GetRecvPool() = 0;
    
    ////
    //// ��������
    ////
    //// ����tcp,���ݽ��ŵ����ͳ���,����remoteAddr��remoteAddrLen����;
    //// ����udp,���ݽ�ֱ�ӷ���,���remoteAddr��remoteAddrLen������Ч,
    //// ��ʹ��Ĭ�ϵ�Զ�˵�ַ
    ////
    //// �������false,��ʾ���ͳ�����,�ϲ㸺�𻺳������Լ����·���
    ////
    virtual bool PRO_STDCALL SendData(
        const void*               buf,
        unsigned long             size,
        const struct sockaddr_in* remoteAddr    = NULL, //// for udp
        unsigned long             remoteAddrLen = 0     //// for udp
        ) = 0;
    
    ////
    //// ����ص�һ��OnSend�¼�
    ////
    virtual void PRO_STDCALL RequestOnSend() = 0;
    
    ////
    //// �����������
    ////
    virtual void PRO_STDCALL SuspendRecv() = 0;
    
    ////
    //// �ָ���������
    ////
    virtual void PRO_STDCALL ResumeRecv() = 0;
    
    ////
    //// ���������¼�
    ////
    //// �����¼�����ʱ,IProTransportObserver::OnHeartbeat(...)�����ص�.
    //// Ĭ�ϵ���������Ϊ10��
    ////
    virtual void PRO_STDCALL StartHeartbeat(
        unsigned long heartbeatInSeconds = 0
        ) = 0;
    
    ////
    //// ֹͣ�����¼�
    ////
    virtual void PRO_STDCALL StopHeartbeat() = 0;
};

////
//// �������ص�Ŀ��
////
//// ʹ������Ҫʵ�ָýӿ�
////
class IProTransportObserver
{
public:
    
    virtual unsigned long PRO_STDCALL AddRef() = 0;
    
    virtual unsigned long PRO_STDCALL Release() = 0;
    
    ////
    //// ���ݵִ��׽��ֵ�ϵͳ������ʱ,�ú��������ص�
    ////
    virtual void PRO_STDCALL OnRecv(
        IProTransport*            trans,
        const struct sockaddr_in* remoteAddr,
        unsigned long             remoteAddrLen
        ) = 0;
    
    ////
    //// ���ݱ��ɹ������׽��ֵ�ϵͳ������ʱ,�ú��������ص�
    ////
    virtual void PRO_STDCALL OnSend(IProTransport* trans) = 0;
    
    ////
    //// �׽��ֳ��ִ���ʱ,�ú��������ص�
    ////
    //// errorCodeΪϵͳ������
    ////
    virtual void PRO_STDCALL OnClose(
        IProTransport* trans,
        long           errorCode
        ) = 0;
    
    ////
    //// �����¼�����ʱ,�ú��������ص�
    ////
    virtual void PRO_STDCALL OnHeartbeat(IProTransport* trans) = 0;
};

/////////////////////////////////////////////////////////////////////////////
////

////
//// ����: ��ʼ�������
////
//// ����: ��
////
//// ����ֵ: ��
////
//// ˵��: ��
////
PRO_NET_API
void
PRO_STDCALL
ProInit();

////
//// ����: ����һ����Ӧ��
////
//// ����:
//// threadCountWr : �������¼����߳���.�ͻ����Ƽ�2,�������Ƽ�15
//// threadCountRd : ��������¼����߳���.�ͻ����Ƽ�2,�������Ƽ�15
////
//// ����ֵ: ��Ӧ��������
////
//// ˵��: ��Ӧ������������,�ڲ������̳߳�.Ҫȷ��ɾ������������ִ��,�����������
////
PRO_NET_API
IProReactor*
PRO_STDCALL
ProCreateReactor(unsigned long threadCountWr = 0,
                 unsigned long threadCountRd = 0);

////
//// ����: ɾ��һ����Ӧ��
////
//// ����:
//// reactor : ��Ӧ������
////
//// ����ֵ: ��
////
//// ˵��: ��Ӧ������������,�ڲ������̳߳�.Ҫȷ��ɾ������������ִ��,�����������
////
PRO_NET_API
void
PRO_STDCALL
ProDeleteReactor(IProReactor* reactor);

////
//// ����: ����һ��������
////
//// ����:
//// observer        : �ص�Ŀ��
//// reactor         : ��Ӧ��
//// localIp         : Ҫ�����ı���ip��ַ.���ΪNULL,ϵͳ��ʹ��0.0.0.0
//// localPort       : Ҫ�����Ķ˿ں�.���Ϊ0,ϵͳ���������һ���˿ں�
//// sockBufSizeRecv : �׽��ֵ�ϵͳ���ջ������ֽ���.Ĭ��(1024 * 56)
//// sockBufSizeSend : �׽��ֵ�ϵͳ���ͻ������ֽ���.Ĭ��(1024 * 8)
////
//// ����ֵ: ������������
////
//// ˵��: ����ʹ��ProGetAcceptorPort(...)��ȡʵ�ʵĶ˿ں�
////
PRO_NET_API
IProAcceptor*
PRO_STDCALL
ProCreateAcceptor(IProAcceptorObserver* observer,
                  IProReactor*          reactor,
                  const char*           localIp         = NULL,
                  unsigned short        localPort       = 0,
                  unsigned long         sockBufSizeRecv = 0,
                  unsigned long         sockBufSizeSend = 0);

////
//// ����: ��ȡ�����������Ķ˿ں�
////
//// ����:
//// acceptor : ����������
////
//// ����ֵ: �˿ں�
////
//// ˵��: ��Ҫ������������Ķ˿ںŵĻ�ȡ
////
PRO_NET_API
unsigned short
PRO_STDCALL
ProGetAcceptorPort(IProAcceptor* acceptor);

////
//// ����: ɾ��һ��������
////
//// ����:
//// acceptor : ����������
////
//// ����ֵ: ��
////
//// ˵��: ��
////
PRO_NET_API
void
PRO_STDCALL
ProDeleteAcceptor(IProAcceptor* acceptor);

////
//// ����: ����һ��������
////
//// ����:
//// observer         : �ص�Ŀ��
//// reactor          : ��Ӧ��
//// remoteIp         : Զ�˵�ip��ַ������
//// remotePort       : Զ�˵Ķ˿ں�
//// sockBufSizeRecv  : �׽��ֵ�ϵͳ���ջ������ֽ���.Ĭ��(1024 * 56)
//// sockBufSizeSend  : �׽��ֵ�ϵͳ���ͻ������ֽ���.Ĭ��(1024 * 8)
//// timeoutInSeconds : ���ӳ�ʱ.Ĭ��60��
//// localBindIp      : Ҫ�󶨵ı���ip��ַ.���ΪNULL,ϵͳ��ʹ��0.0.0.0
////
//// ����ֵ: ������������
////
//// ˵��: ��
////
PRO_NET_API
IProConnector*
PRO_STDCALL
ProCreateConnector(IProConnectorObserver* observer,
                   IProReactor*           reactor,
                   const char*            remoteIp,
                   unsigned short         remotePort,
                   unsigned long          sockBufSizeRecv  = 0,
                   unsigned long          sockBufSizeSend  = 0,
                   unsigned long          timeoutInSeconds = 0,
                   const char*            localBindIp      = NULL);

////
//// ����: ɾ��һ��������
////
//// ����:
//// connector : ����������
////
//// ����ֵ: ��
////
//// ˵��: ��
////
PRO_NET_API
void
PRO_STDCALL
ProDeleteConnector(IProConnector* connector);

////
//// ����: ����һ��tcp������
////
//// ����:
//// observer         : �ص�Ŀ��
//// reactor          : ��Ӧ��
//// sockId           : �׽���id.������OnAccept(...)��OnConnect(...)
//// recvDataSize     : ϣ�����յ��ֽ���
//// timeoutInSeconds : ���ֳ�ʱ.Ĭ��60��
////
//// ����ֵ: tcp������������
////
//// ˵��: ��
////
PRO_NET_API
IProTcpHandshaker*
PRO_STDCALL
ProCreateTcpHandshaker(IProTcpHandshakerObserver* observer,
                       IProReactor*               reactor,
                       long                       sockId,
                       unsigned long              recvDataSize,
                       unsigned long              timeoutInSeconds = 0);

////
//// ����: ɾ��һ��tcp������
////
//// ����:
//// handshaker : tcp����������
////
//// ����ֵ: ��
////
//// ˵��: ��
////
PRO_NET_API
void
PRO_STDCALL
ProDeleteTcpHandshaker(IProTcpHandshaker* handshaker);

////
//// ����: ����һ��tcp������
////
//// ����:
//// observer     : �ص�Ŀ��
//// reactor      : ��Ӧ��
//// sockId       : �׽���id.������OnAccept(...)��OnConnect(...)
//// recvPoolSize : ���ճص��ֽ���.Ĭ��(1024 * 65)
////
//// ����ֵ: ������������
////
//// ˵��: Ҫ��ֹ�߼���۷���,�����˲�Ӧ�÷��ʹ����ն˽��ճسߴ������,
////       ����,�ն���Զ�ò���ϣ��������
////
PRO_NET_API
IProTransport*
PRO_STDCALL
ProCreateTcpTransport(IProTransportObserver* observer,
                      IProReactor*           reactor,
                      long                   sockId,
                      unsigned long          recvPoolSize = 0);

////
//// ����: ����һ��udp������
////
//// ����:
//// observer        : �ص�Ŀ��
//// reactor         : ��Ӧ��
//// localIp         : Ҫ�󶨵ı���ip��ַ.���ΪNULL,ϵͳ��ʹ��0.0.0.0
//// localPort       : Ҫ�󶨵Ķ˿ں�.���Ϊ0,ϵͳ���������һ���˿ں�
//// remoteIp        : Ĭ�ϵ�Զ��ip��ַ������
//// remotePort      : Ĭ�ϵ�Զ�˶˿ں�
//// sockBufSizeRecv : �׽��ֵ�ϵͳ���ջ������ֽ���.Ĭ��(1024 * 56)
//// sockBufSizeSend : �׽��ֵ�ϵͳ���ͻ������ֽ���.Ĭ��(1024 * 56)
////
//// ����ֵ: ������������
////
//// ˵��: ����ʹ��IProTransport::GetLocalPort(...)��ȡʵ�ʵĶ˿ں�
////
PRO_NET_API
IProTransport*
PRO_STDCALL
ProCreateUdpTransport(IProTransportObserver* observer,
                      IProReactor*           reactor,
                      const char*            localIp           = NULL,
                      unsigned short         localPort         = 0,
                      const char*            defaultRemoteIp   = NULL,
                      unsigned short         defaultRemotePort = 0,
                      unsigned long          sockBufSizeRecv   = 0,
                      unsigned long          sockBufSizeSend   = 0);

////
//// ����: ����һ���ಥ������
////
//// ����:
//// observer        : �ص�Ŀ��
//// reactor         : ��Ӧ��
//// mcastIp         : Ҫ�󶨵Ķಥ��ַ
//// mcastPort       : Ҫ�󶨵Ķಥ�˿ں�.���Ϊ0,ϵͳ���������һ���˿ں�
//// sockBufSizeRecv : �׽��ֵ�ϵͳ���ջ������ֽ���.Ĭ��(1024 * 56)
//// sockBufSizeSend : �׽��ֵ�ϵͳ���ͻ������ֽ���.Ĭ��(1024 * 56)
//// localBindIp     : Ҫ�󶨵ı���ip��ַ.���ΪNULL,ϵͳ��ʹ��0.0.0.0
////
//// ����ֵ: ������������
////
//// ˵��: �Ϸ��Ķಥ��ַΪ(224.0.0.0 ~ 239.255.255.255),
////       �Ƽ��Ķಥ��ַΪ(224.0.1.0 ~ 238.255.255.255),
////       RFC-1112(IGMPv1), RFC-2236(IGMPv2), RFC-3376(IGMPv3)
////
////       ����ʹ��IProTransport::GetLocalPort(...)��ȡʵ�ʵĶ˿ں�
////
PRO_NET_API
IProTransport*
PRO_STDCALL
ProCreateMcastTransport(IProTransportObserver* observer,
                        IProReactor*           reactor,
                        const char*            mcastIp,
                        unsigned short         mcastPort       = 0,
                        unsigned long          sockBufSizeRecv = 0,
                        unsigned long          sockBufSizeSend = 0,
                        const char*            localBindIp     = NULL);

////
//// ����: ɾ��һ��������
////
//// ����:
//// trans : ����������
////
//// ����ֵ: ��
////
//// ˵��: ��
////
PRO_NET_API
void
PRO_STDCALL
ProDeleteTransport(IProTransport* trans);

////
//// ����: ��һ��tcp�׽���
////
//// ����:
//// localIp   : Ҫ�󶨵ı���ip��ַ.���ΪNULL,ϵͳ��ʹ��0.0.0.0
//// localPort : Ҫ�󶨵Ķ˿ں�
////
//// ����ֵ: �׽���id��-1
////
//// ˵��: ��Ҫ���ڱ���rtcp�˿�
////
PRO_NET_API
long
PRO_STDCALL
ProOpenTcpSockId(const char*    localIp, /* = NULL */
                 unsigned short localPort);

////
//// ����: ��һ��udp/mcast�׽���
////
//// ����:
//// localIp   : Ҫ�󶨵ı���ip��ַ.���ΪNULL,ϵͳ��ʹ��0.0.0.0
//// localPort : Ҫ�󶨵Ķ˿ں�
////
//// ����ֵ: �׽���id��-1
////
//// ˵��: ��Ҫ���ڱ���rtcp�˿�
////
PRO_NET_API
long
PRO_STDCALL
ProOpenUdpSockId(const char*    localIp, /* = NULL */
                 unsigned short localPort);

////
//// ����: �ر�һ���׽���
////
//// ����:
//// sockId : �׽���id
////
//// ����ֵ: ��
////
//// ˵��: OnAccept(...)��OnConnect(...)������׽���,���������׽���û�гɹ���װ��
////       (IProTransport*)ʱ,Ӧ��ʹ�øú����ͷ�sockId��Ӧ���׽�����Դ
////
PRO_NET_API
void
PRO_STDCALL
ProCloseSockId(long sockId);

/////////////////////////////////////////////////////////////////////////////
////

PRO_EXTERN_C2

#endif //// ____PRO_NET_H____
