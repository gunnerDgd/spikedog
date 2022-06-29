#pragma once
#include <spikedog/tcp/details/connman/tcp_connman_type.h>
#include <spikedog/tcp/details/networking/tcp_networking_type.h>

void
__spikedog_tcp_connman_initialize
	();

void
__spikedog_tcp_connman_cleanup
	();

__spikedog_connman_connection
__spikedog_tcp_connman_create_connection
	(__spikedog_tcp*);

void
__spikedog_tcp_connman_delete_connection
	(__spikedog_connman_connection);