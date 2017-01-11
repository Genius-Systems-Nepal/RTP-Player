#if !defined(____RTP_FRAMEWORK_H____)
#define ____RTP_FRAMEWORK_H____

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

////
//// RFC-1889/1890, RFC-3550/3551, RFC-4571
////

/////////////////////////////////////////////////////////////////////////////
////

#if defined(RTP_FRAMEWORK_LIB)
#define RTP_FRAMEWORK_API
#elif defined(RTP_FRAMEWORK_EXPORTS)
#if defined(_MSC_VER)
#define RTP_FRAMEWORK_API //// .def
#else
#define RTP_FRAMEWORK_API PRO_EXPORT
#endif
#else
#define RTP_FRAMEWORK_API PRO_IMPORT
#endif

class IProReactor;  //// ��Ӧ��.�μ�pro_net.h
class IRtpAcceptor; //// rtp������

////
//// [[[[ rtpý������.0~127����,128~255�Զ���
////
typedef unsigned char RTP_MM_TYPE;

static const RTP_MM_TYPE RTP_MMT_IPC     = 0; //// ���̼�ͨ��.[�ڲ�ʹ��]
static const RTP_MM_TYPE RTP_MMT_MSG     = 1; //// ��Ϣ
static const RTP_MM_TYPE RTP_MMT_CTRL    = 2; //// ����
static const RTP_MM_TYPE RTP_MMT_AUDIO   = 3; //// ��Ƶ
static const RTP_MM_TYPE RTP_MMT_VIDEO   = 4; //// ��Ƶ
static const RTP_MM_TYPE RTP_MMT_VIDEOII = 5; //// ��ƵII
////
//// ]]]]
////

////
//// [[[[ rtp�Ự����
////
typedef unsigned char RTP_SESSION_TYPE;

static const RTP_SESSION_TYPE RTP_ST_UDPCLIENT      = 1;  //// udp-��׼rtpЭ��ͻ���
static const RTP_SESSION_TYPE RTP_ST_UDPSERVER      = 2;  //// udp-��׼rtpЭ������
static const RTP_SESSION_TYPE RTP_ST_TCPCLIENT      = 3;  //// tcp-��׼rtpЭ��ͻ���
static const RTP_SESSION_TYPE RTP_ST_TCPSERVER      = 4;  //// tcp-��׼rtpЭ������
static const RTP_SESSION_TYPE RTP_ST_UDPCLIENT_EX   = 5;  //// udp-��չЭ��ͻ���
static const RTP_SESSION_TYPE RTP_ST_UDPSERVER_EX   = 6;  //// udp-��չЭ������
static const RTP_SESSION_TYPE RTP_ST_TCPCLIENT_EX   = 7;  //// tcp-��չЭ��ͻ���
static const RTP_SESSION_TYPE RTP_ST_TCPSERVER_EX   = 8;  //// tcp-��չЭ������
static const RTP_SESSION_TYPE RTP_ST_SSLCLIENT_EX   = 9;  //// ssl-��չЭ��ͻ���
static const RTP_SESSION_TYPE RTP_ST_SSLSERVER_EX   = 10; //// ssl-��չЭ������
static const RTP_SESSION_TYPE RTP_ST_MCASTCLIENT    = 11; //// mcast-��׼rtpЭ��ͻ���
static const RTP_SESSION_TYPE RTP_ST_MCASTSERVER    = 12; //// mcast-��׼rtpЭ������
static const RTP_SESSION_TYPE RTP_ST_MCASTCLIENT_EX = 13; //// mcast-��չЭ��ͻ���
static const RTP_SESSION_TYPE RTP_ST_MCASTSERVER_EX = 14; //// mcast-��չЭ������
////
//// ]]]]
////

////
//// rtp�Ự��Ϣ
////
#pragma pack(push, 1) //// [[[[----------------------------------------------
#pragma pack(pop)     //// ]]]]
struct RTP_SESSION_INFO
{
    PRO_UINT32       roomId;             //// ������id
    PRO_UINT32       localMmId;          //// ���ؽڵ�id
    PRO_UINT32       remoteMmId;         //// Զ�˽ڵ�id
    
    struct
    {
        bool         enable;             //// �Ƿ��������뷽���ý����
        char         __padding__[3];
        PRO_UINT32   srcMmId;            //// ���뷽���ý������Դ�ڵ�id.���Ϊ0,������id
    }                in;
    
    struct
    {
        bool         enable;             //// �Ƿ�������������ý����
        char         __padding__[3];
        PRO_UINT32   srcMmId;            //// ��������ý������Դ�ڵ�id.���Ϊ0,������id
    }                out;
    
    RTP_MM_TYPE      mmType;             //// ý������
    RTP_SESSION_TYPE sessionType_r;      //// �Ự����.        [ֻ��]
    char             __padding__[2];
    char             passwordHash_r[20]; //// �Ự�����hashֵ.[ֻ��]
    char             userData[64];       //// �û��Զ�������
};
#pragma pack(push, 1) //// [[[[
#pragma pack(pop)     //// ]]]]----------------------------------------------

/////////////////////////////////////////////////////////////////////////////
////

////
//// rtp��
////
#if !defined(____IRtpPacket____)
#define ____IRtpPacket____
class IRtpPacket
{
public:
    
    virtual unsigned long PRO_STDCALL AddRef() = 0;
    
    virtual unsigned long PRO_STDCALL Release() = 0;
    
    virtual void PRO_STDCALL SetMarker(bool m) = 0;
    
    virtual bool PRO_STDCALL GetMarker() const = 0;
    
    virtual void PRO_STDCALL SetPayloadType(char pt) = 0;
    
    virtual char PRO_STDCALL GetPayloadType() const = 0;
    
    virtual void PRO_STDCALL SetSequence(PRO_UINT16 seq) = 0;
    
    virtual PRO_UINT16 PRO_STDCALL GetSequence() const = 0;
    
    virtual void PRO_STDCALL SetTimeStamp(PRO_UINT32 ts) = 0;
    
    virtual PRO_UINT32 PRO_STDCALL GetTimeStamp() const = 0;
    
    virtual void PRO_STDCALL SetSsrc(PRO_UINT32 ssrc) = 0;
    
    virtual PRO_UINT32 PRO_STDCALL GetSsrc() const = 0;
    
    virtual void PRO_STDCALL SetMmId(PRO_UINT32 mmId) = 0;
    
    virtual PRO_UINT32 PRO_STDCALL GetMmId() const = 0;
    
    virtual void PRO_STDCALL SetMmType(RTP_MM_TYPE mmType) = 0;
    
    virtual RTP_MM_TYPE PRO_STDCALL GetMmType() const = 0;
    
    virtual void PRO_STDCALL SetKeyFrame(bool keyFrame) = 0;
    
    virtual bool PRO_STDCALL GetKeyFrame() const = 0;
    
    virtual void PRO_STDCALL SetFirstPacketOfFrame(bool firstPacket) = 0;
    
    virtual bool PRO_STDCALL GetFirstPacketOfFrame() const = 0;
    
    virtual const void* PRO_STDCALL GetPayloadBuffer() const = 0;
    
    virtual void* PRO_STDCALL GetPayloadBuffer() = 0;
    
    virtual PRO_UINT16 PRO_STDCALL GetPayloadSize() const = 0;
    
    virtual void PRO_STDCALL SetTick_i(PRO_INT64 tick) = 0;
    
    virtual PRO_INT64 PRO_STDCALL GetTick_i() const = 0;
};
#endif //// ____IRtpPacket____

/////////////////////////////////////////////////////////////////////////////
////

////
//// rtp�Ự
////
class IRtpSession
{
public:
    
    ////
    //// ��ȡ�Ự��Ϣ
    ////
    virtual const RTP_SESSION_INFO PRO_STDCALL GetInfo() const = 0;
    
    ////
    //// ��ȡ�Ự���׽���id
    ////
    //// ��Ǳ���,��ò�Ҫֱ�Ӳ����ײ���׽���
    ////
    virtual long PRO_STDCALL GetSockId() const = 0;
    
    ////
    //// ��ȡ�Ự�ı���ip��ַ
    ////
    virtual const char* PRO_STDCALL GetLocalIp(char localIp[64]) const = 0;
    
    ////
    //// ��ȡ�Ự�ı��ض˿ں�
    ////
    virtual unsigned short PRO_STDCALL GetLocalPort() const = 0;
    
    ////
    //// ��ȡ�Ự��Զ��ip��ַ
    ////
    virtual const char* PRO_STDCALL GetRemoteIp(char remoteIp[64]) const = 0;
    
    ////
    //// ��ȡ�Ự��Զ�˶˿ں�
    ////
    virtual unsigned short PRO_STDCALL GetRemotePort() const = 0;
    
    ////
    //// ���ûỰ��Զ��ip��ַ�Ͷ˿ں�
    ////
    //// ������RTP_ST_UDPCLIENT,RTP_ST_UDPSERVER���͵ĻỰ
    ////
    virtual void PRO_STDCALL SetRemoteIpAndPort(
        const char*    remoteIp,
        unsigned short remotePort
        ) = 0;
    
    ////
    //// ���Ự�Ƿ����
    ////
    virtual bool PRO_STDCALL IsReady() const = 0;
    
    ////
    //// ֱ�ӷ���rtp��
    ////
    //// �������false,��ʾ���ͳ�����,�ϲ㸺�𻺳��Լ����·���
    ////
    virtual bool PRO_STDCALL SendPacket(IRtpPacket* packet) = 0;
    
    ////
    //// ͨ����ʱ������rtp��(for CRtpSessionWrapper only)
    ////
    //// �������false,��ʾ���ͳ�����,�ϲ㸺�𻺳��Լ����·���
    ////
    virtual bool PRO_STDCALL SendPacketByTimer(
        IRtpPacket*   packet,
        unsigned long sendDurationMs /* = 1 */
        ) = 0;
    
    ////
    //// ����Ự�ص�һ��OnSend�¼�
    ////
    virtual void PRO_STDCALL RequestOnSend() = 0;
    
    ////
    //// rtp����ͳ��(for CRtpSessionWrapper only)----------------------------
    ////
    
    virtual float PRO_STDCALL GetInputBitRate() const = 0;
    
    virtual float PRO_STDCALL GetOutputBitRate() const = 0;
    
    virtual float PRO_STDCALL GetInputFrameRate() const = 0;
    
    virtual float PRO_STDCALL GetOutputFrameRate() const = 0;
    
    virtual float PRO_STDCALL GetInputLossRate() const = 0;
    
    virtual float PRO_STDCALL GetOutputLossRate() const = 0;
    
    virtual float PRO_STDCALL GetInputLossCount() const = 0;
    
    virtual float PRO_STDCALL GetOutputLossCount() const = 0;
    
    virtual void PRO_STDCALL ResetInputStat() = 0;
    
    virtual void PRO_STDCALL ResetOutputStat() = 0;
    
    ////
    //// rtp��·ʹ��(for CRtpSessionWrapper only)----------------------------
    ////
    
    virtual void PRO_STDCALL EnableInput(bool enable) = 0;
    
    virtual void PRO_STDCALL EnableOutput(bool enable) = 0;
    
    ////
    //// rtp��������(for CRtpSessionWrapper only)----------------------------
    ////
    
    virtual void PRO_STDCALL SetRedlineBytes(unsigned long redlineBytes) = 0;
    
    virtual void PRO_STDCALL SetRedlineFrames(unsigned long redlineFrames) = 0;
};

////
//// rtp�Ự�ص�Ŀ��
////
//// ʹ������Ҫʵ�ָýӿ�
////
class IRtpSessionObserver
{
public:
    
    virtual unsigned long PRO_STDCALL AddRef() = 0;
    
    virtual unsigned long PRO_STDCALL Release() = 0;
    
    ////
    //// ״̬����ʱ,�ú��������ص�
    ////
    virtual void PRO_STDCALL OnOkSession(IRtpSession* session) = 0;
    
    ////
    //// rtp���ִ�ʱ,�ú��������ص�
    ////
    virtual void PRO_STDCALL OnRecvSession(
        IRtpSession* session,
        IRtpPacket*  packet
        ) = 0;
    
    ////
    //// ������������ʱ,�ú��������ص�
    ////
    virtual void PRO_STDCALL OnSendSession(
        IRtpSession* session,
        bool         packetErased
        ) = 0;
    
    ////
    //// ���ִ���ʱ,�ú��������ص�
    ////
    //// errorCodeΪϵͳ������
    ////
    virtual void PRO_STDCALL OnCloseSession(
        IRtpSession* session,
        long         errorCode
        ) = 0;
};

/////////////////////////////////////////////////////////////////////////////
////

////
//// rtp�������ص�Ŀ��
////
//// ʹ������Ҫʵ�ָýӿ�
////
class IRtpAcceptorObserver
{
public:
    
    virtual unsigned long PRO_STDCALL AddRef() = 0;
    
    virtual unsigned long PRO_STDCALL Release() = 0;
    
    ////
    //// �лỰ����ʱ,�ú��������ص�
    ////
    //// ʹ���߶�remoteInfo���н���У���,Ӧ�ø���remoteInfo�ĻỰ���Ͱ�sockId��װ��
    //// RTP_ST_TCPSERVER_EX��RTP_ST_SSLSERVER_EX���͵�(IRtpSession*),
    //// ���ͷ�sockId��Ӧ���׽�����Դ
    ////
    //// ע��!!! remoteInfo��Զ�˷�������Զ���Լ��ĻỰ��Ϣ
    ////
    virtual void PRO_STDCALL OnAcceptSession(
        IRtpAcceptor*           acceptor,
        long                    sockId, //// -1��Ч,����ʧ��
        const RTP_SESSION_INFO* remoteInfo,
        PRO_UINT32              token
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
RTP_FRAMEWORK_API
void
PRO_STDCALL
InitRtpFramework();

////
//// ����: ����һ��rtp��
////
//// ����:
//// payloadBuffer : ý������ָ��
//// payloadSize   : ý�����ݳ���.���(1024 * 60)�ֽ�
////
//// ����ֵ: rtp��������
////
//// ˵��: ʹ����Ӧ�ü�����ʼ��rtp����ͷ���ֶ�
////
RTP_FRAMEWORK_API
IRtpPacket*
PRO_STDCALL
CreateRtpPacket(const void* payloadBuffer,
                PRO_UINT16  payloadSize);

////
//// ����: ����һ��rtp��
////
//// ����:
//// payloadSize : ý�����ݳ���.���(1024 * 60)�ֽ�
////
//// ����ֵ: rtp��������
////
//// ˵��: �ð汾��Ҫ���ڼ����ڴ濽������.
////       ����,����������ͨ��IRtpPacket::GetPayloadBuffer(...)�õ�ý������ָ��,
////       Ȼ��ֱ�ӽ���ý�����ݵĳ�ʼ���Ȳ���
////
RTP_FRAMEWORK_API
IRtpPacket*
PRO_STDCALL
CreateRtpPacketSpace(PRO_UINT16 payloadSize);

////
//// ����: ��¡һ��rtp��
////
//// ����:
//// packet : ԭʼ��rtp������
////
//// ����ֵ: ��¡��rtp��������
////
//// ˵��: ��
////
RTP_FRAMEWORK_API
IRtpPacket*
PRO_STDCALL
CloneRtpPacket(const IRtpPacket* packet);

////
//// ����: ����һ�α�׼��rtp��
////
//// ����:
//// streamBuffer : ��ָ��
//// streamSize   : ������
////
//// ����ֵ: rtp��������
////
//// ˵��: �������̻����IRtpPacket��֧�ֵ��ֶ�
////
RTP_FRAMEWORK_API
IRtpPacket*
PRO_STDCALL
ParseRtpStreamToPacket(const void* streamBuffer,
                       PRO_UINT16  streamSize);

////
//// ����: ����һ�α�׼��rtp��
////
//// ����:
//// packet     : rtp������
//// streamSize : ������
////
//// ����ֵ: ��ָ����
////
//// ˵��: ����ʱ,(*streamSize)ָʾ�˸�rtp���ĳ���
////
RTP_FRAMEWORK_API
const void*
PRO_STDCALL
FindRtpStreamFromPacket(const IRtpPacket* packet,
                        PRO_UINT16*       streamSize);

////
//// ����: ����rtp�˿ںŵķ��䷶Χ
////
//// ����:
//// minUdpPort : ��Сudp�˿ں�
//// maxUdpPort : ���udp�˿ں�
//// minTcpPort : ��Сtcp�˿ں�
//// maxTcpPort : ���tcp�˿ں�
////
//// ����ֵ: ��
////
//// ˵��: Ĭ�ϵĶ˿ںŷ��䷶ΧΪ(3000 ~ 3999).ż����ʼ,��������
////
RTP_FRAMEWORK_API
void
PRO_STDCALL
SetRtpPortRange(unsigned short minUdpPort,
                unsigned short maxUdpPort,
                unsigned short minTcpPort,
                unsigned short maxTcpPort);

////
//// ����: ��ȡrtp�˿ںŵķ��䷶Χ
////
//// ����:
//// minUdpPort : ���ڽ�����Сudp�˿ں�.����ΪNULL
//// maxUdpPort : ���ڽ������udp�˿ں�.����ΪNULL
//// minTcpPort : ���ڽ�����Сtcp�˿ں�.����ΪNULL
//// maxTcpPort : ���ڽ������tcp�˿ں�.����ΪNULL
////
//// ����ֵ: ��
////
//// ˵��: Ĭ�ϵĶ˿ںŷ��䷶ΧΪ(3000 ~ 3999).ż����ʼ,��������
////
RTP_FRAMEWORK_API
void
PRO_STDCALL
GetRtpPortRange(unsigned short* minUdpPort,
                unsigned short* maxUdpPort,
                unsigned short* minTcpPort,
                unsigned short* maxTcpPort);

////
//// ����: �Զ�����һ��udp�˿ں�
////
//// ����: ��
////
//// ����ֵ: udp�˿ں�.[ż��]
////
//// ˵��: ���صĶ˿ںŲ�һ������,Ӧ�ö�η��䳢��
////
RTP_FRAMEWORK_API
unsigned short
PRO_STDCALL
AllocRtpUdpPort();

////
//// ����: �Զ�����һ��tcp�˿ں�
////
//// ����: ��
////
//// ����ֵ: tcp�˿ں�.[ż��]
////
//// ˵��: ���صĶ˿ںŲ�һ������,Ӧ�ö�η��䳢��
////
RTP_FRAMEWORK_API
unsigned short
PRO_STDCALL
AllocRtpTcpPort();

////
//// ����: ���ûỰ����������
////
//// ����:
//// heartbeatInSeconds : ��������.Ĭ��10��
////
//// ����ֵ: ��
////
//// ˵��: ��
////
RTP_FRAMEWORK_API
void
PRO_STDCALL
SetRtpHeartbeatInterval(unsigned long heartbeatInSeconds = 0);

////
//// ����: ��ȡ�Ự����������
////
//// ����: ��
////
//// ����ֵ: ��������
////
//// ˵��: ��
////
RTP_FRAMEWORK_API
unsigned long
PRO_STDCALL
GetRtpHeartbeatInterval();

////
//// ����: ���ûỰ�ı�������
////
//// ����:
//// keepaliveInSeconds : ��������.Ĭ��180��
////
//// ����ֵ: ��
////
//// ˵��: ��
////
RTP_FRAMEWORK_API
void
PRO_STDCALL
SetRtpKeepaliveInterval(unsigned long keepaliveInSeconds = 0);

////
//// ����: ��ȡ�Ự�ı�������
////
//// ����: ��
////
//// ����ֵ: ��������
////
//// ˵��: ��
////
RTP_FRAMEWORK_API
unsigned long
PRO_STDCALL
GetRtpKeepaliveInterval();

////
//// ����: ���ûỰ��ͳ��ʱ�䴰
////
//// ����:
//// statInSeconds : ͳ��ʱ�䴰.Ĭ��5��
////
//// ����ֵ: ��
////
//// ˵��: ��
////
RTP_FRAMEWORK_API
void
PRO_STDCALL
SetRtpStatTimeSpan(unsigned long statInSeconds = 0);

////
//// ����: ��ȡ�Ự��ͳ��ʱ�䴰
////
//// ����: ��
////
//// ����ֵ: ͳ��ʱ�䴰
////
//// ˵��: ��
////
RTP_FRAMEWORK_API
unsigned long
PRO_STDCALL
GetRtpStatTimeSpan();

////
//// ����: ����һ��RTP_ST_UDPCLIENT���͵ĻỰ
////
//// ����:
//// observer  : �ص�Ŀ��
//// reactor   : ��Ӧ��
//// localInfo : �Ự��Ϣ
//// antiNat   : �Ƿ���NAT�ڲ�������������
//// localIp   : Ҫ�󶨵ı���ip��ַ.���ΪNULL,ϵͳ��ʹ��0.0.0.0
//// localPort : Ҫ�󶨵Ķ˿ں�.[ż��].���Ϊ0,ϵͳ���������һ���˿ں�
////
//// ����ֵ: �Ự������
////
//// ˵��: ����ʹ��IRtpSession::GetLocalPort(...)��ȡ���صĶ˿ں�
////
RTP_FRAMEWORK_API
IRtpSession*
PRO_STDCALL
CreateRtpSessionUdpclient(IRtpSessionObserver*    observer,
                          IProReactor*            reactor,
                          const RTP_SESSION_INFO* localInfo,
                          bool                    antiNat,
                          const char*             localIp   = NULL,
                          unsigned short          localPort = 0);

////
//// ����: ����һ��RTP_ST_UDPSERVER���͵ĻỰ
////
//// ����:
//// observer  : �ص�Ŀ��
//// reactor   : ��Ӧ��
//// localInfo : �Ự��Ϣ
//// antiNat   : �Ƿ���NAT�ڲ�������������
//// localIp   : Ҫ�󶨵ı���ip��ַ.���ΪNULL,ϵͳ��ʹ��0.0.0.0
//// localPort : Ҫ�󶨵Ķ˿ں�.[ż��].���Ϊ0,ϵͳ���������һ���˿ں�
////
//// ����ֵ: �Ự������
////
//// ˵��: ����ʹ��IRtpSession::GetLocalPort(...)��ȡ���صĶ˿ں�
////
RTP_FRAMEWORK_API
IRtpSession*
PRO_STDCALL
CreateRtpSessionUdpserver(IRtpSessionObserver*    observer,
                          IProReactor*            reactor,
                          const RTP_SESSION_INFO* localInfo,
                          bool                    antiNat,
                          const char*             localIp   = NULL,
                          unsigned short          localPort = 0);

////
//// ����: ����һ��RTP_ST_TCPCLIENT���͵ĻỰ
////
//// ����:
//// observer         : �ص�Ŀ��
//// reactor          : ��Ӧ��
//// localInfo        : �Ự��Ϣ
//// remoteIp         : Զ�˵�ip��ַ������
//// remotePort       : Զ�˵Ķ˿ں�
//// localIp          : Ҫ�󶨵ı���ip��ַ.���ΪNULL,ϵͳ��ʹ��0.0.0.0
//// timeoutInSeconds : ���ֳ�ʱ.Ĭ��60��
////
//// ����ֵ: �Ự������
////
//// ˵��: ��
////
RTP_FRAMEWORK_API
IRtpSession*
PRO_STDCALL
CreateRtpSessionTcpclient(IRtpSessionObserver*    observer,
                          IProReactor*            reactor,
                          const RTP_SESSION_INFO* localInfo,
                          const char*             remoteIp,
                          unsigned short          remotePort,
                          const char*             localIp          = NULL,
                          unsigned long           timeoutInSeconds = 0);

////
//// ����: ����һ��RTP_ST_TCPSERVER���͵ĻỰ
////
//// ����:
//// observer         : �ص�Ŀ��
//// reactor          : ��Ӧ��
//// localInfo        : �Ự��Ϣ
//// localIp          : Ҫ�󶨵ı���ip��ַ.���ΪNULL,ϵͳ��ʹ��0.0.0.0
//// localPort        : Ҫ�󶨵Ķ˿ں�.[ż��].���Ϊ0,ϵͳ���������һ���˿ں�
//// timeoutInSeconds : ���ֳ�ʱ.Ĭ��60��
////
//// ����ֵ: �Ự������
////
//// ˵��: ����ʹ��IRtpSession::GetLocalPort(...)��ȡ���صĶ˿ں�
////
RTP_FRAMEWORK_API
IRtpSession*
PRO_STDCALL
CreateRtpSessionTcpserver(IRtpSessionObserver*    observer,
                          IProReactor*            reactor,
                          const RTP_SESSION_INFO* localInfo,
                          const char*             localIp          = NULL,
                          unsigned short          localPort        = 0,
                          unsigned long           timeoutInSeconds = 0);

////
//// ����: ����һ��RTP_ST_UDPCLIENT_EX���͵ĻỰ
////
//// ����:
//// observer         : �ص�Ŀ��
//// reactor          : ��Ӧ��
//// localInfo        : �Ự��Ϣ
//// remoteIp         : Զ�˵�ip��ַ������
//// remotePort       : Զ�˵Ķ˿ں�
//// localIp          : Ҫ�󶨵ı���ip��ַ.���ΪNULL,ϵͳ��ʹ��0.0.0.0
//// timeoutInSeconds : ���ֳ�ʱ.Ĭ��60��
////
//// ����ֵ: �Ự������
////
//// ˵��: ��
////
RTP_FRAMEWORK_API
IRtpSession*
PRO_STDCALL
CreateRtpSessionUdpclientEx(IRtpSessionObserver*    observer,
                            IProReactor*            reactor,
                            const RTP_SESSION_INFO* localInfo,
                            const char*             remoteIp,
                            unsigned short          remotePort,
                            const char*             localIp          = NULL,
                            unsigned long           timeoutInSeconds = 0);

////
//// ����: ����һ��RTP_ST_UDPSERVER_EX���͵ĻỰ
////
//// ����:
//// observer         : �ص�Ŀ��
//// reactor          : ��Ӧ��
//// localInfo        : �Ự��Ϣ
//// localIp          : Ҫ�󶨵ı���ip��ַ.���ΪNULL,ϵͳ��ʹ��0.0.0.0
//// localPort        : Ҫ�󶨵Ķ˿ں�.[ż��].���Ϊ0,ϵͳ���������һ���˿ں�
//// timeoutInSeconds : ���ֳ�ʱ.Ĭ��60��
////
//// ����ֵ: �Ự������
////
//// ˵��: ����ʹ��IRtpSession::GetLocalPort(...)��ȡ���صĶ˿ں�
////
RTP_FRAMEWORK_API
IRtpSession*
PRO_STDCALL
CreateRtpSessionUdpserverEx(IRtpSessionObserver*    observer,
                            IProReactor*            reactor,
                            const RTP_SESSION_INFO* localInfo,
                            const char*             localIp          = NULL,
                            unsigned short          localPort        = 0,
                            unsigned long           timeoutInSeconds = 0);

////
//// ����: ����һ��RTP_ST_TCPCLIENT_EX���͵ĻỰ
////
//// ����:
//// observer         : �ص�Ŀ��
//// reactor          : ��Ӧ��
//// localInfo        : �Ự��Ϣ
//// remoteIp         : Զ�˵�ip��ַ������
//// remotePort       : Զ�˵Ķ˿ں�
//// localIp          : Ҫ�󶨵ı���ip��ַ.���ΪNULL,ϵͳ��ʹ��0.0.0.0
//// password         : �Ự����
//// timeoutInSeconds : ���ֳ�ʱ.Ĭ��60��
////
//// ����ֵ: �Ự������
////
//// ˵��: ��
////
RTP_FRAMEWORK_API
IRtpSession*
PRO_STDCALL
CreateRtpSessionTcpclientEx(IRtpSessionObserver*    observer,
                            IProReactor*            reactor,
                            const RTP_SESSION_INFO* localInfo,
                            const char*             remoteIp,
                            unsigned short          remotePort,
                            const char*             localIp          = NULL,
                            const char*             password         = NULL,
                            unsigned long           timeoutInSeconds = 0);

////
//// ����: ����һ��RTP_ST_TCPSERVER_EX���͵ĻỰ
////
//// ����:
//// observer  : �ص�Ŀ��
//// reactor   : ��Ӧ��
//// localInfo : �Ự��Ϣ.����IRtpAcceptorObserver::OnAcceptSession(...)��remoteInfo��������
//// sockId    : �׽���id.������IRtpAcceptorObserver::OnAcceptSession(...)
////
//// ����ֵ: �Ự������
////
//// ˵��: ��
////
RTP_FRAMEWORK_API
IRtpSession*
PRO_STDCALL
CreateRtpSessionTcpserverEx(IRtpSessionObserver*    observer,
                            IProReactor*            reactor,
                            const RTP_SESSION_INFO* localInfo,
                            long                    sockId);

////
//// ����: ����һ��RTP_ST_SSLCLIENT_EX���͵ĻỰ
////
//// ����:
//// observer         : �ص�Ŀ��
//// reactor          : ��Ӧ��
//// localInfo        : �Ự��Ϣ
//// remoteIp         : Զ�˵�ip��ַ������
//// remotePort       : Զ�˵Ķ˿ں�
//// localIp          : Ҫ�󶨵ı���ip��ַ.���ΪNULL,ϵͳ��ʹ��0.0.0.0
//// password         : �Ự����
//// timeoutInSeconds : ���ֳ�ʱ.Ĭ��60��
////
//// ����ֵ: �Ự������
////
//// ˵��: ��
////
RTP_FRAMEWORK_API
IRtpSession*
PRO_STDCALL
CreateRtpSessionSslclientEx(IRtpSessionObserver*    observer,
                            IProReactor*            reactor,
                            const RTP_SESSION_INFO* localInfo,
                            const char*             remoteIp,
                            unsigned short          remotePort,
                            const char*             localIp          = NULL,
                            const char*             password         = NULL,
                            unsigned long           timeoutInSeconds = 0);

////
//// ����: ����һ��RTP_ST_SSLSERVER_EX���͵ĻỰ
////
//// ����:
//// observer        : �ص�Ŀ��
//// reactor         : ��Ӧ��
//// localInfo       : �Ự��Ϣ.����IRtpAcceptorObserver::OnAcceptSession(...)��remoteInfo��������
//// sockId          : �׽���id.������IRtpAcceptorObserver::OnAcceptSession(...)
//// xorOnly         : �Ƿ��ʹ���������
//// sessionKeyBytes : �Ự��Կ���ֽ���(16/32/64).Ĭ��16�ֽ�(128λ)
////
//// ����ֵ: �Ự������
////
//// ˵��: ��
////
RTP_FRAMEWORK_API
IRtpSession*
PRO_STDCALL
CreateRtpSessionSslserverEx(IRtpSessionObserver*    observer,
                            IProReactor*            reactor,
                            const RTP_SESSION_INFO* localInfo,
                            long                    sockId,
                            bool                    xorOnly,
                            unsigned char           sessionKeyBytes = 0);

////
//// ����: ����һ��RTP_ST_MCASTCLIENT���͵ĻỰ
////
//// ����:
//// observer  : �ص�Ŀ��
//// reactor   : ��Ӧ��
//// localInfo : �Ự��Ϣ
//// mcastIp   : Ҫ�󶨵Ķಥ��ַ
//// mcastPort : Ҫ�󶨵Ķಥ�˿ں�.[ż��].���Ϊ0,ϵͳ���������һ���˿ں�
//// localIp   : Ҫ�󶨵ı���ip��ַ.���ΪNULL,ϵͳ��ʹ��0.0.0.0
////
//// ����ֵ: �Ự������
////
//// ˵��: �Ϸ��Ķಥ��ַΪ(224.0.0.0 ~ 239.255.255.255),
////       �Ƽ��Ķಥ��ַΪ(224.0.1.0 ~ 238.255.255.255),
////       RFC-1112(IGMPv1), RFC-2236(IGMPv2), RFC-3376(IGMPv3)
////
////       ����ʹ��IRtpSession::GetLocalPort(...)��ȡ���صĶ˿ں�
////
RTP_FRAMEWORK_API
IRtpSession*
PRO_STDCALL
CreateRtpSessionMcastclient(IRtpSessionObserver*    observer,
                            IProReactor*            reactor,
                            const RTP_SESSION_INFO* localInfo,
                            const char*             mcastIp,
                            unsigned short          mcastPort = 0,
                            const char*             localIp   = NULL);

////
//// ����: ����һ��RTP_ST_MCASTSERVER���͵ĻỰ
////
//// ����:
//// observer  : �ص�Ŀ��
//// reactor   : ��Ӧ��
//// localInfo : �Ự��Ϣ
//// mcastIp   : Ҫ�󶨵Ķಥ��ַ
//// mcastPort : Ҫ�󶨵Ķಥ�˿ں�.[ż��].���Ϊ0,ϵͳ���������һ���˿ں�
//// localIp   : Ҫ�󶨵ı���ip��ַ.���ΪNULL,ϵͳ��ʹ��0.0.0.0
////
//// ����ֵ: �Ự������
////
//// ˵��: �Ϸ��Ķಥ��ַΪ(224.0.0.0 ~ 239.255.255.255),
////       �Ƽ��Ķಥ��ַΪ(224.0.1.0 ~ 238.255.255.255),
////       RFC-1112(IGMPv1), RFC-2236(IGMPv2), RFC-3376(IGMPv3)
////
////       ����ʹ��IRtpSession::GetLocalPort(...)��ȡ���صĶ˿ں�
////
RTP_FRAMEWORK_API
IRtpSession*
PRO_STDCALL
CreateRtpSessionMcastserver(IRtpSessionObserver*    observer,
                            IProReactor*            reactor,
                            const RTP_SESSION_INFO* localInfo,
                            const char*             mcastIp,
                            unsigned short          mcastPort = 0,
                            const char*             localIp   = NULL);

////
//// ����: ����һ��RTP_ST_MCASTCLIENT_EX���͵ĻỰ
////
//// ����:
//// observer  : �ص�Ŀ��
//// reactor   : ��Ӧ��
//// localInfo : �Ự��Ϣ
//// mcastIp   : Ҫ�󶨵Ķಥ��ַ
//// mcastPort : Ҫ�󶨵Ķಥ�˿ں�.[ż��].���Ϊ0,ϵͳ���������һ���˿ں�
//// localIp   : Ҫ�󶨵ı���ip��ַ.���ΪNULL,ϵͳ��ʹ��0.0.0.0
////
//// ����ֵ: �Ự������
////
//// ˵��: �Ϸ��Ķಥ��ַΪ(224.0.0.0 ~ 239.255.255.255),
////       �Ƽ��Ķಥ��ַΪ(224.0.1.0 ~ 238.255.255.255),
////       RFC-1112(IGMPv1), RFC-2236(IGMPv2), RFC-3376(IGMPv3)
////
////       ����ʹ��IRtpSession::GetLocalPort(...)��ȡ���صĶ˿ں�
////
RTP_FRAMEWORK_API
IRtpSession*
PRO_STDCALL
CreateRtpSessionMcastclientEx(IRtpSessionObserver*    observer,
                              IProReactor*            reactor,
                              const RTP_SESSION_INFO* localInfo,
                              const char*             mcastIp,
                              unsigned short          mcastPort = 0,
                              const char*             localIp   = NULL);

////
//// ����: ����һ��RTP_ST_MCASTSERVER_EX���͵ĻỰ
////
//// ����:
//// observer  : �ص�Ŀ��
//// reactor   : ��Ӧ��
//// localInfo : �Ự��Ϣ
//// mcastIp   : Ҫ�󶨵Ķಥ��ַ
//// mcastPort : Ҫ�󶨵Ķಥ�˿ں�.[ż��].���Ϊ0,ϵͳ���������һ���˿ں�
//// localIp   : Ҫ�󶨵ı���ip��ַ.���ΪNULL,ϵͳ��ʹ��0.0.0.0
////
//// ����ֵ: �Ự������
////
//// ˵��: �Ϸ��Ķಥ��ַΪ(224.0.0.0 ~ 239.255.255.255),
////       �Ƽ��Ķಥ��ַΪ(224.0.1.0 ~ 238.255.255.255),
////       RFC-1112(IGMPv1), RFC-2236(IGMPv2), RFC-3376(IGMPv3)
////
////       ����ʹ��IRtpSession::GetLocalPort(...)��ȡ���صĶ˿ں�
////
RTP_FRAMEWORK_API
IRtpSession*
PRO_STDCALL
CreateRtpSessionMcastserverEx(IRtpSessionObserver*    observer,
                              IProReactor*            reactor,
                              const RTP_SESSION_INFO* localInfo,
                              const char*             mcastIp,
                              unsigned short          mcastPort = 0,
                              const char*             localIp   = NULL);

////
//// ����: ɾ��һ���Ự
////
//// ����:
//// session : �Ự����
////
//// ����ֵ: ��
////
//// ˵��: ��
////
RTP_FRAMEWORK_API
void
PRO_STDCALL
DeleteRtpSession(IRtpSession* session);

////
//// ����: ����һ��rtp������
////
//// ����:
//// observer         : �ص�Ŀ��
//// reactor          : ��Ӧ��
//// localIp          : Ҫ�����ı���ip��ַ.���ΪNULL,ϵͳ��ʹ��0.0.0.0
//// localPort        : Ҫ�����Ķ˿ں�.���Ϊ0,ϵͳ���������һ���˿ں�
//// timeoutInSeconds : ���ֳ�ʱ.Ĭ��60��
////
//// ����ֵ: rtp������������
////
//// ˵��: ����ʹ��GetRtpAcceptorPort(...)��ȡʵ�ʵĶ˿ں�
////
RTP_FRAMEWORK_API
IRtpAcceptor*
PRO_STDCALL
CreateRtpAcceptor(IRtpAcceptorObserver* observer,
                  IProReactor*          reactor,
                  const char*           localIp          = NULL,
                  unsigned short        localPort        = 0,
                  unsigned long         timeoutInSeconds = 0);

////
//// ����: ��ȡrtp�����������Ķ˿ں�
////
//// ����:
//// acceptor : rtp����������
////
//// ����ֵ: �˿ں�
////
//// ˵��: ��Ҫ������������Ķ˿ںŵĻ�ȡ
////
RTP_FRAMEWORK_API
unsigned short
PRO_STDCALL
GetRtpAcceptorPort(IRtpAcceptor* acceptor);

////
//// ����: ɾ��һ��rtp������
////
//// ����:
//// acceptor : rtp����������
////
//// ����ֵ: ��
////
//// ˵��: ��
////
RTP_FRAMEWORK_API
void
PRO_STDCALL
DeleteRtpAcceptor(IRtpAcceptor* acceptor);

////
//// ����: ��������hash-20ֵ
////
//// ����:
//// password     : ����
//// token        : �������
//// passwordHash : �����hash-20���
////
//// ����ֵ: ��
////
//// ˵��: ����׼��Ϊ passwordHash = hash(password + token)
////
RTP_FRAMEWORK_API
void
PRO_STDCALL
CalcRtpPasswordHash20(const char* password,
                      PRO_UINT32  token,
                      char        passwordHash[20]);

////
//// ����: ��������hash-40ֵ
////
//// ����:
//// password     : ����
//// token        : �������
//// passwordHash : �����hash-40���
////
//// ����ֵ: ��
////
//// ˵��: ����׼��Ϊ passwordHash = hash(password + token) ---> "%02x"
////
RTP_FRAMEWORK_API
void
PRO_STDCALL
CalcRtpPasswordHash40(const char* password,
                      PRO_UINT32  token,
                      char        passwordHash[40]);

////
//// ����: У������hash-20ֵ
////
//// ����:
//// password     : ����
//// token        : �������
//// passwordHash : �����hash-20ֵ
////
//// ����ֵ: trueƥ��,false��ƥ��
////
//// ˵��: IRtpAcceptorObserver::OnAcceptSession(...)���õ��ú���.
////       У��׼��Ϊ hash(password + token) == passwordHash
////
RTP_FRAMEWORK_API
bool
PRO_STDCALL
CheckRtpPasswordHash20(const char* password,
                       PRO_UINT32  token,
                       const char  passwordHash[20]);

////
//// ����: У������hash-40ֵ
////
//// ����:
//// password     : ����
//// token        : �������
//// passwordHash : �����hash-40ֵ
////
//// ����ֵ: trueƥ��,false��ƥ��
////
//// ˵��: IRtpAcceptorObserver::OnAcceptSession(...)���õ��ú���.
////       У��׼��Ϊ hash(password + token) ---> "%02x" == passwordHash
////
RTP_FRAMEWORK_API
bool
PRO_STDCALL
CheckRtpPasswordHash40(const char* password,
                       PRO_UINT32  token,
                       const char  passwordHash[40]);

/////////////////////////////////////////////////////////////////////////////
////

PRO_EXTERN_C2

#endif //// ____RTP_FRAMEWORK_H____
