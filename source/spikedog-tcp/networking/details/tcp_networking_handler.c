#include <spikedog/tcp/details/networking/tcp_networking_handler.h>
#include <spikedog/tcp/details/connman/tcp_connman.h>

void
__spikedog_tcp_handler_recv_from
	(synapse_networking_tcp pTcp, size_t pIoSize)
{
	__spikedog_tcp* ptr_net		   
		= synapse_networking_tcp_retrieve_additional_data
			(pTcp);
	  spikedog_tcp  ptr_net_opaque 
		  = { .opaque = ptr_net };

	ptr_net->ptr_net_recv_handler
		(ptr_net_opaque,
			synapse_networking_tcp_retrieve_additional_data
				(ptr_net->hnd_net), pIoSize);
}

void
__spikedog_tcp_handler_send_to
	(synapse_networking_tcp pTcp, size_t pIoSize)
{
	__spikedog_tcp* ptr_net
		= pTcp.opaque_additional;
	spikedog_tcp    ptr_net_opaque
		= { .opaque = ptr_net };

	ptr_net->ptr_net_send_handler
		(ptr_net_opaque,
			synapse_networking_tcp_retrieve_additional_data
				(ptr_net->hnd_net), pIoSize);
}

void
__spikedog_tcp_handler_connected
	(synapse_networking_tcp pTcp)
{
	__spikedog_tcp* ptr_net
		= pTcp.opaque_additional;
	spikedog_tcp    ptr_net_opaque
		= { .opaque = ptr_net };

	ptr_net->ptr_net_conn_handler
		(ptr_net_opaque,
			synapse_networking_tcp_retrieve_additional_data
				(ptr_net->hnd_net));
	ptr_net->hnd_net_connman_node
		= __spikedog_tcp_connman_create_connection
				(ptr_net);
}

void
__spikedog_tcp_handler_disconnected
	(synapse_networking_tcp pTcp)
{
	__spikedog_tcp* ptr_net
		= pTcp.opaque_additional;
	spikedog_tcp    ptr_net_opaque
		= { .opaque = ptr_net };

	ptr_net->ptr_net_disconn_handler
		(ptr_net_opaque,
			synapse_networking_tcp_retrieve_additional_data
				(ptr_net->hnd_net));
	__spikedog_tcp_connman_delete_connection
		(ptr_net->hnd_net_connman_node);
	

	synapse_networking_tcp_cleanup
		(pTcp);
}