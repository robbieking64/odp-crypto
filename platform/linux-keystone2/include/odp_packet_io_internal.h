/* Copyright (c) 2013, Linaro Limited
 * All rights reserved.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 */


/**
 * @file
 *
 * ODP packet IO - implementation internal
 */

#ifndef ODP_PACKET_IO_INTERNAL_H_
#define ODP_PACKET_IO_INTERNAL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <odp_spinlock.h>
#include <odp_packet_socket.h>
#ifdef ODP_HAVE_NETMAP
#include <odp_packet_netmap.h>
#endif

#define PKTIO_DEV_MAX_NAME_LEN	10
struct pktio_device {
	const char     name[PKTIO_DEV_MAX_NAME_LEN];
	uint32_t tx_hw_queue;
	uint32_t rx_channel;
	uint32_t rx_flow;
	uint32_t port_id;
};

struct pktio_entry {
	odp_spinlock_t lock;		/**< entry spinlock */
	int taken;			/**< is entry taken(1) or free(0) */
	odp_queue_t inq_default;	/**< default input queue, if set */
	odp_queue_t outq_default;	/**< default out queue */
	odp_buffer_pool_t in_pool;
	struct pktio_device *dev;
};

typedef union {
	struct pktio_entry s;
	uint8_t pad[ODP_CACHE_LINE_SIZE_ROUNDUP(sizeof(struct pktio_entry))];
} pktio_entry_t;

#ifdef __cplusplus
}
#endif

#endif
