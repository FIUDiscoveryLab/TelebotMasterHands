/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)transport_tcp_tcpv4.h    generated by: makeheader    Sat Nov 23 02:44:42 2013
 *
 *		built from:	tcpv4.ifc
 */

#ifndef transport_tcp_tcpv4_h
#define transport_tcp_tcpv4_h


  #ifndef dds_c_infrastructure_impl_h
    #include "dds_c/dds_c_infrastructure_impl.h"
  #endif
  #ifndef transport_tcp_dll_h
    #include "transport_tcp/transport_tcp_dll.h"
  #endif
  #ifndef transport_interface_h
    #include "transport/transport_interface.h"
  #endif
  #ifndef rtitls_connection_h
    #include "rtitls/rtitls_connection.h"
  #endif

  #ifndef reda_fastBuffer_h
    #include "reda/reda_fastBuffer.h"
  #endif

  struct DDS_PropertyQosPolicy;

#ifdef __cplusplus
    extern "C" {
#endif


#define NDDS_TRANSPORT_CLASSNAME_TCPV4_LAN      "tcpv4_lan"


#define NDDS_TRANSPORT_CLASSNAME_TCPV4_WAN      "tcpv4_wan"


#define NDDS_TRANSPORT_CLASSNAME_TLSV4_LAN      "tlsv4_lan"


#define NDDS_TRANSPORT_CLASSNAME_TLSV4_WAN      "tlsv4_wan"


#define NDDS_TRANSPORT_TCPV4_DEFAULT_PORT_NUMBER        7400


#define NDDS_TRANSPORT_TCPV4_TRANSPORT_MODE_SYMMETRIC   0


#define NDDS_TRANSPORT_TCPV4_TRANSPORT_MODE_CLIENT      1


#define NDDS_TRANSPORT_TCPV4_TRANSPORT_MODE_SERVER      2


#define NDDS_TRANSPORT_TCPV4_MESSAGE_SIZE_MAX_DEFAULT (65536)


#define NDDS_TRANSPORT_TCPV4_SOCKET_BUFFER_SIZE_OS_DEFAULT (-1)


#define NDDS_TRANSPORT_TCPV4_SEND_SOCKET_BUFFER_SIZE_DEFAULT (131072)


#define NDDS_TRANSPORT_TCPV4_RECV_SOCKET_BUFFER_SIZE_DEFAULT (131072)


#define NDDS_TRANSPORT_TCPV4_SERVER_SOCKET_BACKLOG_DEFAULT (5)


#define NDDS_TRANSPORT_TCPV4_ADDRESS_BIT_COUNT (64)


#define NDDS_TRANSPORT_TCPV4_READ_BUFFER_POOL_GROWTH_POLICY_DEFAULT NDDS_TRANSPORT_ALLOCATION_SETTINGS_DEFAULT


#define NDDS_TRANSPORT_TCPV4_WRITE_BUFFER_POOL_GROWTH_POLICY_DEFAULT { 4L, 1000L, 10L}


#define NDDS_TRANSPORT_TCPV4_CONTROL_BUFFER_POOL_GROWTH_POLICY_DEFAULT NDDS_TRANSPORT_ALLOCATION_SETTINGS_DEFAULT


#define NDDS_TRANSPORT_TCPV4_CONTROL_MESSAGE_FACTORY_GROWTH_POLICY_DEFAULT \
                NDDS_TRANSPORT_ALLOCATION_SETTINGS_DEFAULT


#define NDDS_TRANSPORT_TCPV4_CONTROL_MESSAGE_ATTRIBUTE_FACTORY_GROWTH_POLICY_DEFAULT \
                NDDS_TRANSPORT_ALLOCATION_SETTINGS_DEFAULT


typedef void (*NDDS_Transport_TCPv4_OnConnectionEstablishedCallback)(
                        RTI_UINT32 remote_peer_addresss,
                        RTI_UINT16 remote_peer_port
);

typedef enum {
    /*e \ingroup NDDS_Transport_TCPv4_Plugin
     *  The reason why the connection was closed is not known
     */
    NDDS_TRANSPORT_TCPV4_ON_CONNECTION_LOST_REASON_UNKNOWN = 0,

    /*e \ingroup NDDS_Transport_TCPv4_Plugin
     *  Server side: connection closed by remote client. 
     *  Client side: the internal send resource was destroyed.
     */
    NDDS_TRANSPORT_TCPV4_ON_CONNECTION_LOST_REASON_CODE_FINALIZED,

    /*e \ingroup NDDS_Transport_TCPv4_Plugin
     *  Describes a condition where the remote peer has ungracefully
     *  closed the connection (app was crashed or suddenly interrupted)
     */
    NDDS_TRANSPORT_TCPV4_ON_CONNECTION_LOST_REASON_CODE_BROKEN_PIPE,

    /*e \ingroup NDDS_Transport_TCPv4_Plugin
     *  Describes a condition where the current node has decided to
     *  close the connection.
     */
    NDDS_TRANSPORT_TCPV4_ON_CONNECTION_LOST_REASON_DESTROYED
} NDDS_Transport_TCPv4_OnConnectionLost_ReasonCode_t;


typedef enum  {
    NDDS_TRANSPORT_TCPV4_SOCKET_MONITORING_KIND_WINDOWS_WAITFORMULTIPLEOBJECTS = 0,
    NDDS_TRANSPORT_TCPV4_SOCKET_MONITORING_KIND_SELECT = 1,
    NDDS_TRANSPORT_TCPV4_SOCKET_MONITORING_KIND_WINDOWS_IOCP = 2,
} NDDS_Transport_TCPv4_SocketMonitoringKind_t;


struct NDDS_Transport_TCPv4_WindowsIOCPSettings_t {

    /*e \brief Defines the concurrency value (number of concurrent running
     * threads) used by I/O Completion Ports.

        This parameter affect only Windows applications using I/O Completion
        Ports as socket handle monitoring strategy.
        \default 1
    */
    RTI_UINT32 concurrency_value;

    /*e \brief Defines the thread pool size used by I/O Completion Ports.

        This parameter affect only Windows applications using I/O Completion
        Ports as socket handle monitoring strategy.
        \default 2
    */
    RTI_UINT32 thread_pool_size;

    /*i \brief Defines the priority for the I/O Completion Ports threads.

        This parameter affect only Windows applications using I/O Completion
        Ports as socket handle monitoring strategy.
        \default RTI_OSAPI_THREAD_PRIORITY_DEFAULT
    */
    RTI_UINT32 thread_priority;

    /*i \brief Defines the priority for the I/O Completion Ports threads.

        This parameter affect only Windows applications using I/O Completion
        Ports as socket handle monitoring strategy.
        \default RTI_OSAPI_THREAD_STACK_SIZE_DEFAULT
    */
    RTI_UINT32 thread_stack_size;
};


#define NDDS_TRANSPORT_TCPV4_WINDOWS_IOCP_SETTINGS_DEFAULT { \
 1, /* windows_iocp_concurrency_value */ \
 2, /* windows_iocp_thread_pool_size */ \
 RTI_OSAPI_THREAD_PRIORITY_DEFAULT,   /* windows_iocp_thread_priority */ \
 RTI_OSAPI_THREAD_STACK_SIZE_DEFAULT, /* windows_iocp_thread_stack_size */ \
}


typedef void (*NDDS_Transport_TCPv4_OnConnectionLostCallback)(
                        RTI_UINT32 remote_peer_addresss,
                        RTI_UINT16 remote_peer_port,
                        NDDS_Transport_TCPv4_OnConnectionLost_ReasonCode_t reason
);


struct NDDS_Transport_TCPv4_Property_t {
    /*e \brief Generic properties of all transport plugins.

         \default Refer to the property default NDDS_Transport_TCPv4_Plugin#NDDS_TRANSPORT_TCPV4_PROPERTY_DEFAULT_LAN
    */
    struct NDDS_Transport_Property_t parent;


    /*e \brief Size in bytes of the send buffer of a socket used for sending.

        On most operating systems, setsockopt() will be called to set the SENDBUF to 
        the value of this parameter.
    
        This value must be greater than or equal to NDDS_Transport_Property_t#message_size_max or 
        \ref NDDS_TRANSPORT_TCPV4_SOCKET_BUFFER_SIZE_OS_DEFAULT.
    
        The maximum value is operating system-dependent.
    
        \default \ref NDDS_TRANSPORT_TCPV4_SOCKET_BUFFER_SIZE_OS_DEFAULT
    */
    RTI_INT32 send_socket_buffer_size;


    /*e \brief Size in bytes of the receive buffer of a socket used for receiving.

        On most operating systems, setsockopt() will be called to set the RECVBUF to the 
        value of this parameter.
    
        This value must be greater than or equal to parent.message_size_max or 
        \ref NDDS_TRANSPORT_TCPV4_SOCKET_BUFFER_SIZE_OS_DEFAULT.
         
        The maximum value is operating-system dependent.
    
        \default \ref NDDS_TRANSPORT_TCPV4_SOCKET_BUFFER_SIZE_OS_DEFAULT
    */
    RTI_INT32 recv_socket_buffer_size;


    /*e \brief Prevents the transport plugin from using the IP loopback interface.

        This property is ignored when parent.classid is equal to \ref NDDS_TRANSPORT_CLASSID_TCPV4_WAN.
    
        Two values are allowed:
        <ul>
            <li>0: Enable local traffic via this plugin. The plugin will only use and
                   report the IP loopback interface only if there are no other network
                   interfaces (NICs) up on the system.
            <li>1: Disable local traffic via this plugin. This means "do not use the
                   IP loopback interface, even if no NICs are discovered." This setting
                   is useful when you want applications running on the same
                   node to use a more efficient plugin like shared memory instead of
                   the IP loopback.
        </ul>
        \default 1
    */
    RTI_INT32 ignore_loopback_interface;


    /*e \brief Prevents the transport plugin from using a network interface that is not reported 
        as RUNNING by the operating system.

        The transport checks the flags reported by the operating system for each
        network interface upon initialization. An interface which is not reported
        as UP will not be used. This property allows the same check to be
        extended to the IFF_RUNNING flag implemented by some operating
        systems. The RUNNING flag is defined to mean that "all resources are
        allocated" and may be off if no link is detected (e.g., the network cable is
        unplugged).

        Two values are allowed:
        <ul>
            <li>0: Do not check the RUNNING flag when enumerating interfaces,
            just make sure the interface is UP.
            <li>1: Check the flag when enumerating interfaces, and ignore those
            that are not reported as RUNNING. This can be used on some
            operating systems to cause the transport to ignore interfaces that
            are enabled but not connected to the network.
        </ul>

        \default 1
    */
    RTI_INT32 ignore_nonrunning_interfaces;


    /*e \brief Mask for the transport priority field.

        This is used in conjunction with
        \ref transport_priority_mapping_low and \ref transport_priority_mapping_high
        to define the mapping from DDS transport priority (see
        \ref DDSTransportPriorityQosModule) to the
        IPv4 TOS field.  Defines a contiguous region of bits in the
        32-bit transport priority value that is used to generate values for the 
        IPv4 TOS field on an outgoing socket.

        For example, the value 0x0000ff00 causes bits 9-16
        (8 bits) to be used in the mapping.  The value will be
        scaled from the mask range (0x0000 - 0xff00 in this case) to
        the range specified by low and high.

        If the mask is set to zero, then the transport will not
        set IPv4 TOS for send sockets.

        \default 0
    */
    RTI_INT32 transport_priority_mask;

    /*e \brief Sets the low value of the output range to IPv4 TOS.

        This is used in conjunction with
        \ref transport_priority_mask and \ref transport_priority_mapping_high
        to define the mapping from DDS transport priority to the
        IPv4 TOS field.  Defines the low value of the
        output range for scaling.

        Note that IPv4 TOS is generally an 8-bit value.

        \see transport_priority_mask

        \default 0
     */ 
    RTI_INT32 transport_priority_mapping_low;

    /*e \brief Sets the high value of the output range to IPv4 TOS.

        This is used in conjunction with
        \ref transport_priority_mask and \ref transport_priority_mapping_low
        to define the mapping from DDS transport priority to the
        IPv4 TOS field.  Defines the high value of the
        output range for scaling.

        Note that IPv4 TOS is generally an 8-bit value.

        \see transport_priority_mask

        \default 0xFF
     */ 
    RTI_INT32 transport_priority_mapping_high;
    
    /*  \brief Sets the transport mode.

        Must set to one of the following values:
        <ul>
            <li>\ref NDDS_TRANSPORT_TCPV4_TRANSPORT_MODE_CLIENT (Currently not supported)
            <li>\ref NDDS_TRANSPORT_TCPV4_TRANSPORT_MODE_SERVER (Currently not supported)
            <li>\ref NDDS_TRANSPORT_TCPV4_TRANSPORT_MODE_SYMMETRIC
        </ul>

        The first two modes must be used in scenarios where connections can be
        established only in one direction. For example, we may have two peers,
        A and B, with a firewall that does not allow incoming connections to A.
        In this case, the transport in peer A should be configured as CLIENT
        and the transport in peer B as SERVER.

        When communication can be established in both directions, the transport
        can be configured in SYMMETRIC mode.

       \default \ref NDDS_TRANSPORT_TCPV4_TRANSPORT_MODE_SYMMETRIC
     */
    RTI_INT32 transport_mode;


    /*e \brief Determines what is the maximum length of the queue of pending connections

        \default \ref NDDS_TRANSPORT_TCPV4_SERVER_SOCKET_BACKLOG_DEFAULT
     */
    RTI_INT32 server_socket_backlog;


    /*e \brief Public locator (IP address and port) of the transport instantiation.

        Use the function \ref NDDS_Transport_TCPv4_Plugin_stringToTransportAddress
        to compose the transport locator from a string form.

        This field is used and required 
        only when NDDS_Transport_Property_t#classid is set to 
        \ref NDDS_TRANSPORT_CLASSID_TCPV4_WAN.

        The public IP address and port are necessary to support communication
        over WAN that involves Network Address Translators (NATs).

        Typically, the address is the public address of the IP router that provides
        access to the WAN. The port is the IP router port that is used to reach the
        private \ref server_bind_port inside the LAN from the outside.

        \see NDDS_Transport_TCPv4_Property_t#server_bind_port

        \default \ref NDDS_TRANSPORT_ADDRESS_INVALID
     */
    NDDS_Transport_Address_t public_address;

    /*e \brief Interface IP address for the transport sockets.

      The TCP transport can be configured to bind all sockets to a specified interface.  

      If the value is NULL, the sockets will be bound to the special IP 
      address INADDR_ANY. This address allows the sockets to receive
      packets destined to any of the interfaces.

      This field should be set in multi-homed systems communicating across NAT routers.

      \default NULL
    */
    char * bind_interface_address;

    /*e \brief Private IP port (inside the LAN) used by the transport to accept TCP connections.

        If this property is set to zero, the transport will disable the internal 
        server socket, making it impossible for external peers to connect to this node.
        In this case, the node is considered unreachable and will only communicate  
        using the asymmetric mode with other (reachable) peers.

        For WAN communication, this port must be forwarded to a public port in the 
        NAT-enabled router that connects to the outer network.

The server_bind_port cannot be shared among multiple participants on a common host. On most operating systems, attempting to reuse the same server_bind_port for multiple participants on a common host will result in a "port already in use" error. However, Windows systems will not recognize if the server_bind_port is already in use, and thus care must be taken to properly configure Windows systems.

        \see NDDS_Transport_TCPv4_Property_t#public_address

        \default \ref NDDS_TRANSPORT_TCPV4_DEFAULT_PORT_NUMBER
    */
    RTI_INT32 server_bind_port;

    /*e \brief Allocation settings applied to read buffers.

         These settings configure the initial number of buffers, the maximum
         number of buffers and the buffers to be allocated when more buffers are
         needed.

         \default \ref NDDS_TRANSPORT_TCPV4_READ_BUFFER_POOL_GROWTH_POLICY_DEFAULT
     */
    struct TransportAllocationSettings_t read_buffer_allocation;

    /*e \brief Allocation settings applied to buffers used for asynchronous (nonblocking) write.

        These settings configure the initial number of buffers, the maximum
        number of buffers and the buffers to be allocated when more buffers are
        needed. 

        Note that for the write buffer pool, the default max_count is not set to unlimited.
        This is to avoid having a fast writer quickly exhaust all the available
        system memory, in case of a temporary network slowdown. When
        this write buffer pool reaches the maximum, the low-level send command
        of the transport will fail; at that point \ndds
        will take the appropriate action (retry to send or drop it), according to
        the application�s QoS (if the transport is used for reliable communication,
        the data will still be sent eventually).

        \default \ref NDDS_TRANSPORT_TCPV4_WRITE_BUFFER_POOL_GROWTH_POLICY_DEFAULT
    */
    struct TransportAllocationSettings_t write_buffer_allocation;

    /*e \brief Allocation settings applied to buffers used to serialize and send control messages.

        These settings configure the initial number of buffers, the maximum
        number of buffers and the buffers to be allocated when more buffers are
        needed.

        \default \ref NDDS_TRANSPORT_TCPV4_CONTROL_BUFFER_POOL_GROWTH_POLICY_DEFAULT
    */
    struct TransportAllocationSettings_t control_buffer_allocation;

    /*e \brief Allocation settings applied to control messages.

        These settings configure the initial number of buffers, the maximum
        number of buffers and the buffers to be allocated when more buffers are
        needed.

        \default \ref NDDS_TRANSPORT_TCPV4_CONTROL_MESSAGE_FACTORY_GROWTH_POLICY_DEFAULT
    */
    struct TransportAllocationSettings_t control_message_allocation;

    /*e \brief Allocation settings applied to control messages attributes.

        These settings configure the initial number of attributes, the maximum
        number of attributes and the attributes to be allocated when more attributes
        are needed.

        \default \ref NDDS_TRANSPORT_TCPV4_CONTROL_MESSAGE_ATTRIBUTE_FACTORY_GROWTH_POLICY_DEFAULT
     */
    struct TransportAllocationSettings_t control_attribute_allocation;

    /*e \brief Controls whether the plugin will send data synchronously or asynchronously.

        When this parameter is set to 0, the TCP
        transport will attempt to send data as soon as the internal send() function
        is called. When it is set to 1, the transport will make a copy of the
        data to send and enqueue it in an internal send buffer. Data will be sent
        as soon as the low-level socket buffer has space.

        Normally setting it to 1 delivers better throughput in a fast network, but
        will result in a longer time to recover from various TCP error conditions.
        Setting it to 0 may cause the low-level send() function to block until the
        data is physically delivered to the lower socket buffer. For an application
        writing data at a very fast rate, it may cause the caller thread to
        block if the send socket buffer is full. This could produce lower throughput
        in those conditions (the caller thread could prepare the next packet
        while waiting for the send socket buffer to become available).

        \default 0 (synchronous send)
     */
    RTI_INT32 force_asynchronous_send;

    /*e 
     * Pointer to a function that is called whenever the plugin establish a
     * connection with a remote peer.
     *
     * For plugins configured to behave as servers, this function is called every
     * time a remote client successfully establish a data communication.
     *
     * For plugins configured to behave as clients, this function is called 
     * for every successful connection to a remote server.
     *
     * It can be set to NULL (no notification callbacks are performed)
     *
     * IMPORTANT: 
     *       This function is called from the receive thread (both client/server side).
     *       if you don't return the control fast enough, the control protocol may
     *       be affected causing disconnections and/or delays in establishing
     *       connections with remote peers.
     *
     * \default NULL
     */
    NDDS_Transport_TCPv4_OnConnectionEstablishedCallback on_connection_established;


    /*e
     * Pointer to a function that is called when a previously established connection
     * with a remote peer gets closed.
     *
     * It can be set to NULL (no notification callbacks are performed)
     *
     * IMPORTANT: 
     *       This function is called from the receive thread (both client/server side).
     *       if you don't return the control fast enough, the control protocol may
     *       be affected causing disconnections and/or delays in establishing
     *       connections with remote peers.
     *
     * \default NULL
     *
     */
    NDDS_Transport_TCPv4_OnConnectionLostCallback on_connection_lost;


    /*e \brief The maximum size of a TCP segment.

        This parameter is only supported on Linux architectures.

        By default, the maximum size of a TCP segment is based on the network
        MTU for destinations on a local network, or on a default 576 for destinations
        on non-local networks. This behavior can be changed by setting
        this parameter to a value between 1 and 65535.

        \default -1 (use OS default)
     */
    RTI_INT32 max_packet_size;


    /*e \brief Configures the sending of KEEP_ALIVE messages in TCP.

        Setting this value to 1, causes a KEEP_ALIVE packet to be sent to the
        remote peer if a long time passes with no other data sent or received.

        This feature is implemented only on architectures that provide a lowlevel
        implementation of the TCP keep-alive feature.

        On Windows systems, the TCP keep-alive feature can be globally
        enabled through the system's registry:
        <b>\\HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Tcpip\\Parameters</b>.


        Refer to MSDN documentation for more details.

        On Solaris systems, most of the TCP keep-alive parameters can be
        changed though the kernel properties.

        \default 0 (disabled)
     */
    RTI_INT32 enable_keep_alive;

    /*e \brief Specifies the interval of inactivity in seconds that causes TCP to generate a KEEP_ALIVE message.
     
        This parameter is only supported on Linux architectures.
      
        \default -1 (OS default value)
     */
    RTI_INT32 keep_alive_time;

    /*e \brief Specifies the interval in seconds between KEEP_ALIVE retries.

        This parameter is only supported on Linux architectures.

        \default -1 (OS default value)
     */
    RTI_INT32 keep_alive_interval;

    /*e \brief The maximum number of KEEP_ALIVE retries before dropping the connection.

        This parameter is only supported on Linux architectures.

        \default -1 (use system's default).
     */
    RTI_INT32 keep_alive_retry_count;

    /*e \brief Disables the TCP nagle algorithm.

        When this property is set to 1, TCP segments are always sent as soon as
        possible, which may result in poor network utilization.

        \default 0 (disabled)
     */
    RTI_INT32 disable_nagle;
    

    /*e \brief Bitmap that specifies the verbosity of log messages from the transport.
     
        Logging values:
        <ul>
            <li>-1 (0xffffffff): do not change the current verbosity
            <li>0x00: silence
            <li>0x01: errors
            <li>0x02: warnings
            <li>0x04: local
            <li>0x08: remote
            <li>0x10: period
            <li>0x80: other (used for control protocol tracing)
        </ul>

        Note: the logging verbosity is a global property shared across multiple
        instances of the TCP transport. If you create a new TCP Transport
        instance with logging_verbosity_bitmap different than -1, the change
        will affect all the other instances as well.

        The default TCP transport verbosity is errors and warnings.

        Note: The option of 0x80 (other) is used only for tracing the internal control
        protocol. Since the output is very verbose, this feature is enabled
        only in the debug version of the TCP Transport library.
            
        \default -1 (do not change default verbosity).
     */
    RTI_INT32 logging_verbosity_bitmap;


    /*i \brief Tells the plugin to use winsock's select() function or WaitForMultipleObjects().

        This parameter affect only Windows applications.

        \default 1
     */
    RTI_INT32 use_windows_select;

    /*e \brief Tells the plugin what socket handle monitoring kind
        to use. Possible values:
            NDDS_TRANSPORT_TCPV4_SOCKET_MONITORING_KIND_WINDOWS_WAITFORMULTIPLEOBJECTS: WaitForMultipleObjects() function (only for Windows).
            NDDS_TRANSPORT_TCPV4_SOCKET_MONITORING_KIND_SELECT: select() function.
            NDDS_TRANSPORT_TCPV4_SOCKET_MONITORING_KIND_WINDOWS_IOCP: I/O Completion Ports (only for Windows).

        \default NDDS_TRANSPORT_TCPV4_SOCKET_MONITORING_KIND_SELECT
     */
    NDDS_Transport_TCPv4_SocketMonitoringKind_t socket_monitoring_kind;

    /*e \brief Defines the settings when using Windows IOCP.

          This parameter affect only Windows applications.

          \default NDDS_TRANSPORT_TCPV4_WINDOWS_IOCP_SETTINGS_DEFAULT
     */
    struct NDDS_Transport_TCPv4_WindowsIOCPSettings_t windows_iocp_settings;

    /*e \brief Maximum number of outstanding connection cookies allowed by the transport when acting as server.

        A connection cookie is a token provided by a server to a client; it is used
        to establish a data connection. Until the data connection is established,
        the cookie cannot be reused by the server.

        To avoid wasting memory, it is good practice to set a cap to the maximum
        number of connection cookies (pending connections).

        When the maximum value is reached, a client will not be able to connect
        to the server until new cookies become available.

        \default 100
    */
    RTI_INT32    outstanding_connection_cookies;


    /*e \brief Maximum lifespan (in seconds) of the cookies associated with 
        pending connections.

        If a client does not connect to the server before the lifespan of its 
        cookie expires, it will have to request a new cookie.

        Range: 1 second or higher, or -1.

        \default -1, which means an unlimited amount of time (effectively disabling
        the feature).
     */
    RTI_INT32 outstanding_connection_cookies_life_span;

    /*e \brief Maximum number of seconds a low-level TCP sendto() function is allowed
               to block
      
        This property controls the maximum time (in seconds) the low level sendto() is
        allowed to block the caller thread when the TCP send buffer becomes full.

        If the bandwidth used by the transport is limited, and the sender thread try to 
        push data faster than the OS can handle, the low level sendto() function will 
        block the caller until there is some room available on the queue.

        By limiting this delay we eliminate possibility of deadlock and increase the
        response time of the internal DDS thread.

        This property affects both CONTROL and DATA stream, and affect only SYNCHRONOUS
        send operations. Asynchronous send never blocks a send operation.

        For synchronous send() this property limit the time the DDS sender thread can
        block for a send buffer full. If is too large, DDS not only won't be able to 
        send more data, but it won't be able to receive any more data because of an
        internal resource mutex.

        Setting this property to 0 cause the low level function to report an immediate failure
        if the TCP send buffer is full.

        Setting this property to -1 cause the low level function to block forever until
        space becomes available in the TCP buffer

        \default 3 seconds.
    */
    RTI_INT32 send_max_wait_sec;


    /*e \brief OpenSSL TLS parameters
     *
     * \default RTITLS_OpenSSL#RTITLS_OPENSSL_CONFIGURATION_DEFAULT
     */
    struct RTITLS_OpenSSL_Configuration tls;

    /*i \brief If this variable is set, we use the provided function for
     * creating the TLS transport. If the variable is not set, we load the
     * function from the proper DLL.
     *
     * (For internal usage only)
     *
     * \default NULL
     *
     */
    NDDS_Transport_ConnectionEndpointFactory_create connection_endpoint_factory_create_fcn;

    /*i \brief If this variable is set, we use the provided function for
     * deleting the TLS transport. If the variable is not set, we load the
     * function from the proper DLL.
     *
     * (For internal usage only)
     *
     * \default NULL
     *
     */
    NDDS_Transport_ConnectionEndpointFactory_delete connection_endpoint_factory_delete_fcn;

    /*i \brief
     *
     * (For internal usage only)
     *
     * \default NULL
     *
     */
    char * reserved;
};


#define NDDS_TRANSPORT_TCPV4_PROPERTY_DEFAULT_LAN { \
 { /* parent */ \
   NDDS_TRANSPORT_CLASSID_TCPV4_LAN, /* classid */ \
   NDDS_TRANSPORT_TCPV4_ADDRESS_BIT_COUNT, /* address_bit_count */ \
   NDDS_TRANSPORT_PROPERTY_BIT_BUFFER_ALWAYS_LOANED, /* properties_bitmap */ \
   128, /* gather_send_buffer_count_max */ \
   NDDS_TRANSPORT_TCPV4_MESSAGE_SIZE_MAX_DEFAULT, /* message_size_max */ \
   NULL, /* allow_interfaces_list */ \
   0,    /* allow_interfaces_list_length */ \
   NULL, /* deny_interfaces_list */ \
   0,    /* deny_interfaces_list_length;*/ \
   NULL, /* allow_multicast_interfaces_list */ \
   0,    /* allow_multicast_interfaces_list_length */ \
   NULL, /* deny_multicast_interfaces_list */ \
   0     /* deny_multicast_interfaces_list_length */ \
 }, \
 NDDS_TRANSPORT_TCPV4_SEND_SOCKET_BUFFER_SIZE_DEFAULT, /* send_socket_buffer_size */ \
 NDDS_TRANSPORT_TCPV4_RECV_SOCKET_BUFFER_SIZE_DEFAULT, /* recv_socket_buffer_size */ \
 1, /* ignore_loopback_interface */ \
 1, /* ignore_nonrunning_interfaces */ \
 0, 0, 0xffL,    /* transport priority mapping */ \
 NDDS_TRANSPORT_TCPV4_TRANSPORT_MODE_SYMMETRIC, /* transport_mode (deprecated) */ \
 NDDS_TRANSPORT_TCPV4_SERVER_SOCKET_BACKLOG_DEFAULT, /* server_socket_backlog */   \
 NDDS_TRANSPORT_ADDRESS_INVALID, /* public_address */ \
 NULL, /* bind_interface_address */ \
 NDDS_TRANSPORT_TCPV4_DEFAULT_PORT_NUMBER, /*server_bind_port */ \
 NDDS_TRANSPORT_TCPV4_READ_BUFFER_POOL_GROWTH_POLICY_DEFAULT, /* read_buffer_allocation */          \
 NDDS_TRANSPORT_TCPV4_WRITE_BUFFER_POOL_GROWTH_POLICY_DEFAULT, /* write_buffer_allocation */ \
 NDDS_TRANSPORT_TCPV4_CONTROL_BUFFER_POOL_GROWTH_POLICY_DEFAULT, /* control_buffer_allocation */      \
 NDDS_TRANSPORT_TCPV4_CONTROL_MESSAGE_FACTORY_GROWTH_POLICY_DEFAULT, /* control_message_allocation */ \
 NDDS_TRANSPORT_TCPV4_CONTROL_MESSAGE_ATTRIBUTE_FACTORY_GROWTH_POLICY_DEFAULT, /* control_attribute_allocation */ \
 0, /* force_asynchronous_send */ \
 NULL,  /* on_connection_established */ \
 NULL,  /* on_connection_lost */ \
 -1L, /* max_packet_size */ \
 0, /* enable_keep_alive */ \
 -1L, /* keep_alive_time */ \
 -1L, /* keep_alive_internal */ \
 -1L, /* keep_alive_retry_count */ \
 0, /* disable_nagle */ \
 -1L, /* logging_verbosity_bitmap */ \
 -1L, /* use_windows_select */ \
 NDDS_TRANSPORT_TCPV4_SOCKET_MONITORING_KIND_SELECT, /* socket_monitoring_kind */ \
 NDDS_TRANSPORT_TCPV4_WINDOWS_IOCP_SETTINGS_DEFAULT, /* windows_iocp_settings */ \
 100, /* outstanding_connection_cookies */ \
 -1L, /* outstanding_connection_cookies_life_span */ \
 3,   /* send_max_wait_sec */ \
 RTITLS_OPENSSL_CONFIGURATION_DEFAULT, /* tls */ \
 NULL, /* connection_endpoint_factory_create_fcn */ \
 NULL, /* connection_endpoint_factory_delete_fcn */ \
 NULL  /* reserved */ \
}


#define NDDS_TRANSPORT_TCPV4_PROPERTY_DEFAULT \
        NDDS_TRANSPORT_TCPV4_PROPERTY_DEFAULT_LAN


#define NDDS_TRANSPORT_TCPV4_ADDRESS_LOCALHOST {{0,0,0,0, 0,0,0,0, 0xff,0xff, 0x1c, 0xe8, 127,0,0,1}}

extern NDDS_Transport_TCP_DllExport 
NDDS_Transport_Plugin*
NDDS_Transport_TCPv4_new(
    const struct NDDS_Transport_TCPv4_Property_t *property_in);

extern NDDS_Transport_TCP_DllExport 
NDDS_Transport_Plugin *NDDS_Transport_TCPv4_create(
    NDDS_Transport_Address_t* default_network_address_out,
    const struct DDS_PropertyQosPolicy *property_in);

extern NDDS_Transport_TCP_DllExport 
RTIBool NDDS_Transport_TCPv4_Plugin_stringToTransportAddress(
    NDDS_Transport_Address_t *address_out,
    const char               *address_in,
    RTIBool                   acceptHostName_in);


#ifdef __cplusplus
    }   /* extern "C" */
#endif

#endif /* transport_tcp_tcpv4_h */
