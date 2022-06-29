#pragma once
#include <stdint.h>

typedef struct spikedog_tcp
{
	void* opaque;
} spikedog_tcp;

typedef void(*spikedog_tcp_io_handler)
				(spikedog_tcp, void*, size_t);
typedef void(*spikedog_tcp_connect_handler)
				(spikedog_tcp, void*);
typedef void(*spikedog_tcp_disconnect_handler)
				(spikedog_tcp, void*);