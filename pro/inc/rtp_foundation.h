#if !defined(____RTP_FOUNDATION_H____)
#define ____RTP_FOUNDATION_H____

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

#if defined(RTP_FOUNDATION_LIB)
#define RTP_FOUNDATION_API
#elif defined(RTP_FOUNDATION_EXPORTS)
#if defined(_MSC_VER)
#define RTP_FOUNDATION_API //// .def
#else
#define RTP_FOUNDATION_API PRO_EXPORT
#endif
#else
#define RTP_FOUNDATION_API PRO_IMPORT
#endif

#if !defined(____RTP_FRAMEWORK_H____)
#define RTP_MM_TYPE      unsigned char
#define RTP_SESSION_TYPE unsigned char
#endif

class  IProReactor;
class  IRtpAcceptorObserver;
class  IRtpBucket;
class  IRtpPacket;
class  IRtpSession;
class  IRtpSessionObserver;
class  IRtpTunnelClient;
class  IRtpTunnelServer;
struct RTP_SESSION_INFO;

////
//// �Ự��ʼ������
////
//// ���bucketΪNULL,ϵͳ���Զ�����һ��rtpͰ
////
struct RTP_INIT_UDPCLIENT
{
    IRtpSessionObserver* observer;
    IProReactor*         reactor;
    bool                 antiNat;
    char                 localIp[64];      /* = "" */
    unsigned short       localPort;        /* = 0 */
    IRtpBucket*          bucket;           /* = NULL */
};

////
//// �Ự��ʼ������
////
//// ���bucketΪNULL,ϵͳ���Զ�����һ��rtpͰ
////
struct RTP_INIT_UDPSERVER
{
    IRtpSessionObserver* observer;
    IProReactor*         reactor;
    bool                 antiNat;
    char                 localIp[64];      /* = "" */
    unsigned short       localPort;        /* = 0 */
    IRtpBucket*          bucket;           /* = NULL */
};

////
//// �Ự��ʼ������
////
//// ���bucketΪNULL,ϵͳ���Զ�����һ��rtpͰ
////
struct RTP_INIT_TCPCLIENT
{
    IRtpSessionObserver* observer;
    IProReactor*         reactor;
    char                 remoteIp[64];
    unsigned short       remotePort;
    char                 localIp[64];      /* = "" */
    unsigned long        timeoutInSeconds; /* = 0 */
    IRtpBucket*          bucket;           /* = NULL */
};

////
//// �Ự��ʼ������
////
//// ���bucketΪNULL,ϵͳ���Զ�����һ��rtpͰ
////
struct RTP_INIT_TCPSERVER
{
    IRtpSessionObserver* observer;
    IProReactor*         reactor;
    char                 localIp[64];      /* = "" */
    unsigned short       localPort;        /* = 0 */
    unsigned long        timeoutInSeconds; /* = 0 */
    IRtpBucket*          bucket;           /* = NULL */
};

////
//// �Ự��ʼ������
////
//// ���bucketΪNULL,ϵͳ���Զ�����һ��rtpͰ
////
struct RTP_INIT_UDPCLIENT_EX
{
    IRtpSessionObserver* observer;
    IProReactor*         reactor;
    char                 remoteIp[64];
    unsigned short       remotePort;
    char                 localIp[64];      /* = "" */
    unsigned long        timeoutInSeconds; /* = 0 */
    IRtpBucket*          bucket;           /* = NULL */
};

////
//// �Ự��ʼ������
////
//// ���bucketΪNULL,ϵͳ���Զ�����һ��rtpͰ
////
struct RTP_INIT_UDPSERVER_EX
{
    IRtpSessionObserver* observer;
    IProReactor*         reactor;
    char                 localIp[64];      /* = "" */
    unsigned short       localPort;        /* = 0 */
    unsigned long        timeoutInSeconds; /* = 0 */
    IRtpBucket*          bucket;           /* = NULL */
};

////
//// �Ự��ʼ������
////
//// ���bucketΪNULL,ϵͳ���Զ�����һ��rtpͰ
////
struct RTP_INIT_TCPCLIENT_EX
{
    IRtpSessionObserver* observer;
    IProReactor*         reactor;
    char                 remoteIp[64];
    unsigned short       remotePort;
    char                 localIp[64];      /* = "" */
    char                 password[256];    /* = "" */
    unsigned long        timeoutInSeconds; /* = 0 */
    IRtpBucket*          bucket;           /* = NULL */
};

////
//// �Ự��ʼ������
////
//// ���bucketΪNULL,ϵͳ���Զ�����һ��rtpͰ
////
struct RTP_INIT_TCPSERVER_EX
{
    IRtpSessionObserver* observer;
    IProReactor*         reactor;
    long                 sockId;
    IRtpBucket*          bucket;           /* = NULL */
};

////
//// �Ự��ʼ������
////
//// ���bucketΪNULL,ϵͳ���Զ�����һ��rtpͰ
////
struct RTP_INIT_SSLCLIENT_EX
{
    IRtpSessionObserver* observer;
    IProReactor*         reactor;
    char                 remoteIp[64];
    unsigned short       remotePort;
    char                 localIp[64];      /* = "" */
    char                 password[256];    /* = "" */
    unsigned long        timeoutInSeconds; /* = 0 */
    IRtpBucket*          bucket;           /* = NULL */
};

////
//// �Ự��ʼ������
////
//// ���bucketΪNULL,ϵͳ���Զ�����һ��rtpͰ
////
struct RTP_INIT_SSLSERVER_EX
{
    IRtpSessionObserver* observer;
    IProReactor*         reactor;
    long                 sockId;
    bool                 xorOnly;
    unsigned char        sessionKeyBytes;  /* = 0 */
    IRtpBucket*          bucket;           /* = NULL */
};

////
//// �Ự��ʼ������
////
//// ���bucketΪNULL,ϵͳ���Զ�����һ��rtpͰ
////
struct RTP_INIT_MCASTCLIENT
{
    IRtpSessionObserver* observer;
    IProReactor*         reactor;
    char                 mcastIp[64];
    unsigned short       mcastPort;        /* = 0 */
    char                 localIp[64];      /* = "" */
    IRtpBucket*          bucket;           /* = NULL */
};

////
//// �Ự��ʼ������
////
//// ���bucketΪNULL,ϵͳ���Զ�����һ��rtpͰ
////
struct RTP_INIT_MCASTSERVER
{
    IRtpSessionObserver* observer;
    IProReactor*         reactor;
    char                 mcastIp[64];
    unsigned short       mcastPort;        /* = 0 */
    char                 localIp[64];      /* = "" */
    IRtpBucket*          bucket;           /* = NULL */
};

////
//// �Ự��ʼ������
////
//// ���bucketΪNULL,ϵͳ���Զ�����һ��rtpͰ
////
struct RTP_INIT_MCASTCLIENT_EX
{
    IRtpSessionObserver* observer;
    IProReactor*         reactor;
    char                 mcastIp[64];
    unsigned short       mcastPort;        /* = 0 */
    char                 localIp[64];      /* = "" */
    IRtpBucket*          bucket;           /* = NULL */
};

////
//// �Ự��ʼ������
////
//// ���bucketΪNULL,ϵͳ���Զ�����һ��rtpͰ
////
struct RTP_INIT_MCASTSERVER_EX
{
    IRtpSessionObserver* observer;
    IProReactor*         reactor;
    char                 mcastIp[64];
    unsigned short       mcastPort;        /* = 0 */
    char                 localIp[64];      /* = "" */
    IRtpBucket*          bucket;           /* = NULL */
};

////
//// �Ự��ʼ������
////
struct RTP_INIT_COMMON
{
    IRtpSessionObserver* observer_r;       //// [ֻ��]
    IProReactor*         reactor_r;        //// [ֻ��]
};

////
//// �Ự��ʼ����������
////
struct RTP_INIT_ARGS
{
    union
    {
        RTP_INIT_UDPCLIENT      udpclient;
        RTP_INIT_UDPSERVER      udpserver;
        RTP_INIT_TCPCLIENT      tcpclient;
        RTP_INIT_TCPSERVER      tcpserver;
        RTP_INIT_UDPCLIENT_EX   udpclientEx;
        RTP_INIT_UDPSERVER_EX   udpserverEx;
        RTP_INIT_TCPCLIENT_EX   tcpclientEx;
        RTP_INIT_TCPSERVER_EX   tcpserverEx;
        RTP_INIT_SSLCLIENT_EX   sslclientEx;
        RTP_INIT_SSLSERVER_EX   sslserverEx;
        RTP_INIT_MCASTCLIENT    mcastclient;
        RTP_INIT_MCASTSERVER    mcastserver;
        RTP_INIT_MCASTCLIENT_EX mcastclientEx;
        RTP_INIT_MCASTSERVER_EX mcastserverEx;
        RTP_INIT_COMMON         comm;
    };
};

#pragma pack(push, 1) //// [[[[----------------------------------------------
#pragma pack(pop)     //// ]]]]

////
//// ��Ϣ�û�
////
//// classId : ���ֶ����ڱ�ʶ�û����,�Ա���Ӧ�ó������.
////           0��Ч,1�������ڵ�,2~c�ͻ��˽ڵ�
////
//// userId  : ���ֶ����ڱ�ʶ�û�id.
////           0��̬����,��̬���䷶ΧΪ(2000000001 ~ u);����̬����,
////           ��̬���䷶ΧΪ(1 ~ 2000000000)
////
//// ˵��    : classId-userId ֮ 1-1 ����,�ڲ�ʹ��
////
struct RTP_MSG_USER
{
    RTP_MSG_USER()
    {
        classId = 0;
        userId  = 0;
    }
    
    bool operator<(const RTP_MSG_USER& user) const
    {
        if (classId < user.classId)
        {
            return (true);
        }
        
        if (classId > user.classId)
        {
            return (false);
        }
        
        if (userId < user.userId)
        {
            return (true);
        }
        
        return (false);
    }
    
    PRO_UINT32 classId;
    PRO_UINT32 userId;
};

#pragma pack(push, 1) //// [[[[
#pragma pack(pop)     //// ]]]]----------------------------------------------

/////////////////////////////////////////////////////////////////////////////
////

////
//// rtpͰ
////
//// ����ʹ����strategyģʽ.��ͬ�����ཫʵ�ֲ�ͬ�����ز���
////
class IRtpBucket
{
public:
    
    virtual void PRO_STDCALL Destroy() = 0; //// !!!
    
    virtual unsigned long PRO_STDCALL GetTotalBytes() const = 0;
    
    virtual IRtpPacket* PRO_STDCALL GetFront() = 0;
    
    virtual bool PRO_STDCALL PushBackAddRef(IRtpPacket* packet) = 0;
    
    virtual void PRO_STDCALL PopFrontRelease() = 0;
    
    virtual void PRO_STDCALL Reset() = 0;
    
    virtual void PRO_STDCALL SetRedlineBytes(unsigned long redlineBytes) = 0;
    
    virtual void PRO_STDCALL SetRedlineFrames(unsigned long redlineFrames) = 0;
};

/////////////////////////////////////////////////////////////////////////////
////

////
//// ��Ϣ�ͻ���
////
class IRtpMsgClient
{
public:
    
    ////
    //// ��ȡ�û���Ϣ
    ////
    virtual const RTP_MSG_USER PRO_STDCALL GetUserInfo() const = 0;
    
    ////
    //// ������Ϣ
    ////
    //// ϵͳ�ڲ�����Ϣ���Ͷ���
    ////
    virtual bool PRO_STDCALL SendMsg(
        const void*         buf,         //// ��Ϣ����
        PRO_UINT16          size,        //// ���(1024 * 60)�ֽ�
        const RTP_MSG_USER* dstUsers,    //// ��Ϣ������
        unsigned char       dstUserCount //// ���255��Ŀ��
        ) = 0;
};

////
//// ��Ϣ�ͻ��˻ص�Ŀ��
////
//// ʹ������Ҫʵ�ָýӿ�
////
class IRtpMsgClientObserver
{
public:
    
    virtual unsigned long PRO_STDCALL AddRef() = 0;
    
    virtual unsigned long PRO_STDCALL Release() = 0;
    
    ////
    //// ״̬����ʱ,�ú��������ص�
    ////
    virtual void PRO_STDCALL OnOkMsg(
        IRtpMsgClient* msgClient,
        const char*    myPublicIp
        ) = 0;
    
    ////
    //// ��Ϣ�ִ�ʱ,�ú��������ص�
    ////
    virtual void PRO_STDCALL OnRecvMsg(
        IRtpMsgClient*      msgClient,
        const void*         buf,
        PRO_UINT16          size,
        const RTP_MSG_USER* srcUser
        ) = 0;
    
    ////
    //// ���ִ���ʱ,�ú��������ص�
    ////
    //// errorCodeΪϵͳ������
    ////
    virtual void PRO_STDCALL OnCloseMsg(
        IRtpMsgClient* msgClient,
        long           errorCode
        ) = 0;
};

/////////////////////////////////////////////////////////////////////////////
////

////
//// ��Ϣ������
////
class IRtpMsgServer
{
public:
    
    ////
    //// ��ȡ�û���
    ////
    virtual void PRO_STDCALL GetUserCount(
        unsigned long* pendingUserCount,
        unsigned long* baseUserCount,
        unsigned long* subUserCount
        ) const = 0;
};

////
//// ��Ϣ�������ص�Ŀ��
////
//// ʹ������Ҫʵ�ָýӿ�
////
class IRtpMsgServerObserver
{
public:
    
    virtual unsigned long PRO_STDCALL AddRef() = 0;
    
    virtual unsigned long PRO_STDCALL Release() = 0;
    
    ////
    //// �û������¼ʱ,�ú��������ص�
    ////
    //// ����ֵ��ʾ�Ƿ�������û���¼
    ////
    virtual bool PRO_STDCALL OnCheckUser(
        IRtpMsgServer*      msgServer,
        const RTP_MSG_USER* userInfo,
        PRO_UINT32          userToken,
        const char          passwordHash[20],
        const char*         userPublicIp
        ) = 0;
    
    ////
    //// �û�״̬����ʱ,�ú��������ص�
    ////
    virtual void PRO_STDCALL OnOkUser(
        IRtpMsgServer*      msgServer,
        const RTP_MSG_USER* userInfo,
        const char*         userPublicIp
        ) = 0;
    
    ////
    //// �û����ִ���ʱ,�ú��������ص�
    ////
    //// errorCodeΪϵͳ������
    ////
    virtual void PRO_STDCALL OnCloseUser(
        IRtpMsgServer*      msgServer,
        const RTP_MSG_USER* userInfo,
        long                errorCode
        ) = 0;
};

/////////////////////////////////////////////////////////////////////////////
////

////
//// ��Ϣc2s
////
class IRtpMsgC2s
{
public:
    
    ////
    //// ��ȡc2s��Ϣ
    ////
    virtual const RTP_MSG_USER PRO_STDCALL GetC2sInfo() const = 0;
    
    ////
    //// ��ȡ�û���
    ////
    virtual void PRO_STDCALL GetUserCount(
        unsigned long* pendingUserCount,
        unsigned long* userCount
        ) const = 0;
};

////
//// ��Ϣc2s�ص�Ŀ��
////
//// ʹ������Ҫʵ�ָýӿ�
////
class IRtpMsgC2sObserver
{
public:
    
    virtual unsigned long PRO_STDCALL AddRef() = 0;
    
    virtual unsigned long PRO_STDCALL Release() = 0;
    
    ////
    //// c2s״̬����ʱ,�ú��������ص�
    ////
    virtual void PRO_STDCALL OnOkC2s(
        IRtpMsgC2s* msgC2s,
        const char* c2sPublicIp
        ) = 0;
    
    ////
    //// c2s���ִ���ʱ,�ú��������ص�
    ////
    //// errorCodeΪϵͳ������
    ////
    virtual void PRO_STDCALL OnCloseC2s(
        IRtpMsgC2s* msgC2s,
        long        errorCode
        ) = 0;
    
    ////
    //// �û�״̬����ʱ,�ú��������ص�
    ////
    virtual void PRO_STDCALL OnOkUser(
        IRtpMsgC2s*         msgC2s,
        const RTP_MSG_USER* userInfo,
        const char*         userPublicIp
        ) = 0;
    
    ////
    //// �û����ִ���ʱ,�ú��������ص�
    ////
    //// errorCodeΪϵͳ������
    ////
    virtual void PRO_STDCALL OnCloseUser(
        IRtpMsgC2s*         msgC2s,
        const RTP_MSG_USER* userInfo,
        long                errorCode
        ) = 0;
};

/////////////////////////////////////////////////////////////////////////////
////

////
//// ����: ��ʼ��rtp��
////
//// ����: ��
////
//// ����ֵ: ��
////
//// ˵��: ��
////
RTP_FOUNDATION_API
void
PRO_STDCALL
InitRtpFoundation();

////
//// ����: ����һ���Ự��װ
////
//// ����:
//// sessionType : �Ự����
//// initArgs    : �Ự��ʼ����������
//// localInfo   : �Ự��Ϣ
////
//// ����ֵ: �Ự��װ������
////
//// ˵��: �Ự��װ����������ز���
////
RTP_FOUNDATION_API
IRtpSession*
PRO_STDCALL
CreateRtpSessionWrapper(RTP_SESSION_TYPE        sessionType,
                        const RTP_INIT_ARGS*    initArgs,
                        const RTP_SESSION_INFO* localInfo);

////
//// ����: ɾ��һ���Ự��װ
////
//// ����:
//// sessionWrapper : �Ự��װ����
////
//// ����ֵ: ��
////
//// ˵��: ��
////
RTP_FOUNDATION_API
void
PRO_STDCALL
DeleteRtpSessionWrapper(IRtpSession* sessionWrapper);

////
//// ����: ����һ��tunnel�ͻ���
////
//// ����:
//// observer   : �ص�Ŀ��
//// reactor    : ��Ӧ��
//// tunnelPort : tunnel�������Ķ˿ں�
//// mmType     : ý������
////
//// ����ֵ: tunnel�ͻ��˶�����
////
//// ˵��: tunnel���������Խ���ͬý�����͵����������ɷ�����Ӧ��tunnel�ͻ���,
////       �������Խ���̱߽�(Ŀǰ������Windows)
////
RTP_FOUNDATION_API
IRtpTunnelClient*
PRO_STDCALL
CreateRtpTunnelClient(IRtpAcceptorObserver* observer,
                      IProReactor*          reactor,
                      unsigned short        tunnelPort,
                      RTP_MM_TYPE           mmType);

////
//// ����: ɾ��һ��tunnel�ͻ���
////
//// ����:
//// tunnelClient : tunnel�ͻ��˶���
////
//// ����ֵ: ��
////
//// ˵��: ��
////
RTP_FOUNDATION_API
void
PRO_STDCALL
DeleteRtpTunnelClient(IRtpTunnelClient* tunnelClient);

////
//// ����: ����һ��tunnel������
////
//// ����:
//// reactor          : ��Ӧ��
//// tunnelPort       : tunnel�������Ķ˿ں�
//// timeoutInSeconds : ���ֳ�ʱ.Ĭ��60��
////
//// ����ֵ: tunnel������������
////
//// ˵��: tunnel���������Խ���ͬý�����͵����������ɷ�����Ӧ��tunnel�ͻ���,
////       �������Խ���̱߽�(Ŀǰ������Windows)
////
RTP_FOUNDATION_API
IRtpTunnelServer*
PRO_STDCALL
CreateRtpTunnelServer(IProReactor*   reactor,
                      unsigned short tunnelPort,
                      unsigned long  timeoutInSeconds = 0);

////
//// ����: ɾ��һ��tunnel������
////
//// ����:
//// tunnelServer : tunnel����������
////
//// ����ֵ: ��
////
//// ˵��: ��
////
RTP_FOUNDATION_API
void
PRO_STDCALL
DeleteRtpTunnelServer(IRtpTunnelServer* tunnelServer);

////
//// ����: ����һ����Ϣ�ͻ���
////
//// ����:
//// observer         : �ص�Ŀ��
//// reactor          : ��Ӧ��
//// remoteIp         : Զ�˵�ip��ַ������
//// remotePort       : Զ�˵Ķ˿ں�
//// encryptMsg       : �Ƿ����
//// userInfo         : �û���Ϣ.
////                    ���userIdΪ0,����������̬����һ��userId,
////                    ��̬���䷶ΧΪ(2000000001 ~ u);����̬����,
////                    ��̬���䷶ΧΪ(1 ~ 2000000000)
//// password         : �û�����
//// localIp          : Ҫ�󶨵ı���ip��ַ.���ΪNULL,ϵͳ��ʹ��0.0.0.0
//// timeoutInSeconds : ���ֳ�ʱ.Ĭ��60��
////
//// ����ֵ: ��Ϣ�ͻ��˶�����
////
//// ˵��: ��
////
RTP_FOUNDATION_API
IRtpMsgClient*
PRO_STDCALL
CreateRtpMsgClient(IRtpMsgClientObserver* observer,
                   IProReactor*           reactor,
                   const char*            remoteIp,
                   unsigned short         remotePort,
                   bool                   encryptMsg,
                   const RTP_MSG_USER*    userInfo,
                   const char*            password         = NULL,
                   const char*            localIp          = NULL,
                   unsigned long          timeoutInSeconds = 0);

////
//// ����: ɾ��һ����Ϣ�ͻ���
////
//// ����:
//// msgClient : ��Ϣ�ͻ��˶���
////
//// ����ֵ: ��
////
//// ˵��: ��
////
RTP_FOUNDATION_API
void
PRO_STDCALL
DeleteRtpMsgClient(IRtpMsgClient* msgClient);

////
//// ����: ����һ����Ϣ������
////
//// ����:
//// observer        : �ص�Ŀ��
//// reactor         : ��Ӧ��
//// tunnelPort      : tunnel�������Ķ˿ں�
//// xorOnly         : �ͻ���ϣ������ʱ,�Ƿ��ʹ���������
//// sessionKeyBytes : �ͻ���ϣ������ʱ,�Ự��Կ���ֽ���(16/32/64).Ĭ��16�ֽ�(128λ)
////
//// ����ֵ: ��Ϣ������������
////
//// ˵��: ��
////
RTP_FOUNDATION_API
IRtpMsgServer*
PRO_STDCALL
CreateRtpMsgServer(IRtpMsgServerObserver* observer,
                   IProReactor*           reactor,
                   unsigned short         tunnelPort,
                   bool                   xorOnly,
                   unsigned char          sessionKeyBytes = 0);

////
//// ����: ɾ��һ����Ϣ������
////
//// ����:
//// msgServer : ��Ϣ����������
////
//// ����ֵ: ��
////
//// ˵��: ��
////
RTP_FOUNDATION_API
void
PRO_STDCALL
DeleteRtpMsgServer(IRtpMsgServer* msgServer);

////
//// ����: ����һ����Ϣc2s
////
//// ����:
//// observer               : �ص�Ŀ��
//// reactor                : ��Ӧ��
//// uplinkIp               : ����ʱԶ�˵�ip��ַ������
//// uplinkPort             : ����ʱԶ�˵Ķ˿ں�
//// uplinkEncryptMsg       : ����ʱ�Ƿ����
//// uplinkUserInfo         : �������û���Ϣ.
////                          ���userIdΪ0,����������̬����һ��userId,
////                          ��̬���䷶ΧΪ(2000000001 ~ u);����̬����,
////                          ��̬���䷶ΧΪ(1 ~ 2000000000)
//// uplinkPassword         : �������û�����
//// uplinkLocalIp          : ����ʱҪ�󶨵ı���ip��ַ.���ΪNULL,ϵͳ��ʹ��0.0.0.0
//// uplinkTimeoutInSeconds : ����ʱ�����ֳ�ʱ.Ĭ��60��
//// tunnelPort             : ���˵�tunnel�������Ķ˿ں�
//// xorOnly                : ���˵Ŀͻ���ϣ������ʱ,�Ƿ��ʹ���������
//// sessionKeyBytes        : ���˵Ŀͻ���ϣ������ʱ,�Ự��Կ���ֽ���(16/32/64).Ĭ��16�ֽ�(128λ)
//// timeoutInSeconds       : ���˵����ֳ�ʱ.Ĭ��60��
////
//// ����ֵ: ��Ϣc2s������
////
//// ˵��: ��
////
RTP_FOUNDATION_API
IRtpMsgC2s*
PRO_STDCALL
CreateRtpMsgC2s(IRtpMsgC2sObserver* observer,
                IProReactor*        reactor,
                const char*         uplinkIp,
                unsigned short      uplinkPort,
                bool                uplinkEncryptMsg,
                const RTP_MSG_USER* uplinkUserInfo,
                const char*         uplinkPassword,
                const char*         uplinkLocalIp,          /* = NULL */
                unsigned long       uplinkTimeoutInSeconds, /* = 0 */
                unsigned short      tunnelPort,
                bool                xorOnly,
                unsigned char       sessionKeyBytes,        /* = 0 */
                unsigned long       timeoutInSeconds);      /* = 0 */

////
//// ����: ɾ��һ����Ϣc2s
////
//// ����:
//// msgC2s : ��Ϣc2s����
////
//// ����ֵ: ��
////
//// ˵��: ��
////
RTP_FOUNDATION_API
void
PRO_STDCALL
DeleteRtpMsgC2s(IRtpMsgC2s* msgC2s);

////
//// ����: ����һ���ڲ�ʵ�ֵĻ������͵�rtpͰ
////
//// ����: ��
////
//// ����ֵ: rtpͰ������
////
//// ˵��: rtpͰ���̰߳�ȫ���ɵ����߱�֤
////
RTP_FOUNDATION_API
IRtpBucket*
PRO_STDCALL
CreateRtpBaseBucket();

////
//// ����: ����һ���ڲ�ʵ�ֵ���Ƶ���͵�rtpͰ
////
//// ����: ��
////
//// ����ֵ: rtpͰ������
////
//// ˵��: rtpͰ���̰߳�ȫ���ɵ����߱�֤
////
RTP_FOUNDATION_API
IRtpBucket*
PRO_STDCALL
CreateRtpAudioBucket();

////
//// ����: ����һ���ڲ�ʵ�ֵ���Ƶ���͵�rtpͰ
////
//// ����: ��
////
//// ����ֵ: rtpͰ������
////
//// ˵��: rtpͰ���̰߳�ȫ���ɵ����߱�֤
////
RTP_FOUNDATION_API
IRtpBucket*
PRO_STDCALL
CreateRtpVideoBucket();

/////////////////////////////////////////////////////////////////////////////
////

#if !defined(____RTP_FRAMEWORK_H____)
#undef RTP_MM_TYPE
#undef RTP_SESSION_TYPE
#endif

PRO_EXTERN_C2

#endif //// ____RTP_FOUNDATION_H____
