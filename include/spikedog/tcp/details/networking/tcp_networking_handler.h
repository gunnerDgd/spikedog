#pragma once
#include <networking/protocol/tcp/tcp.h>
#include <spikedog/tcp/details/networking/tcp_networking_type.h>

void
__spikedog_tcp_handler_recv_from
	(synapse_networking_tcp, size_t);

void
__spikedog_tcp_handler_send_to
	(synapse_networking_tcp, size_t);

void
__spikedog_tcp_handler_connected
	(synapse_networking_tcp);

void
__spikedog_tcp_handler_disconnected
	(synapse_networking_tcp);