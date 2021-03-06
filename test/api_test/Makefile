# Copyright (c) 2013, Linaro Limited
# All rights reserved.
#
# SPDX-License-Identifier:     BSD-3-Clause

ODP_ROOT = ../..

#
# API testing stuffs
#
ODP_ATOMIC    = odp_atomic
ODP_SHM       = odp_shm
ODP_RING      = odp_ring
ODP_TIM       = odp_timer

include $(ODP_ROOT)/Makefile.inc
include ../Makefile.inc

.PHONY: default
default: all

EXTRA_CFLAGS  += -I.

ATOMIC_OBJS  =
ATOMIC_OBJS += $(OBJ_DIR)/odp_common.o
ATOMIC_OBJS += $(OBJ_DIR)/odp_atomic_test.o

SHM_OBJS  =
SHM_OBJS += $(OBJ_DIR)/odp_common.o
SHM_OBJS += $(OBJ_DIR)/odp_shm_test.o

RING_OBJS  =
RING_OBJS += $(OBJ_DIR)/odp_common.o
RING_OBJS += $(OBJ_DIR)/odp_ring_test.o

TIM_OBJS   =
TIM_OBJS  += $(OBJ_DIR)/odp_common.o
TIM_OBJS  += $(OBJ_DIR)/odp_timer_ping.o

DEPS     = $(ATOMIC_OBJS:.o=.d) $(SHM_OBJS:.o=.d) $(RING_OBJS:.o=.d) $(TIM_OBJS:.o=.d)

.PHONY: all
all: $(OBJ_DIR) $(ODP_ATOMIC) $(ODP_SHM) $(ODP_RING) $(ODP_TIM)
atomic: $(OBJ_DIR) $(ODP_ATOMIC)
shm: $(OBJ_DIR) $(ODP_SHM)
ring: $(OBJ_DIR) $(ODP_RING)
timer: $(OBJ_DIR) $(ODP_TIM)

-include $(DEPS)

#
# Compile rules
#
$(OBJ_DIR)/%.o: %.c
	$(QUIET_CC)$(CC) -c -MD $(EXTRA_CFLAGS) $(CFLAGS) -o $@ $<

#
# Link rule
#
$(ODP_ATOMIC): $(ODP_LIB) $(ATOMIC_OBJS)
	$(QUIET_LD)$(CC) $(LDFLAGS) $(ATOMIC_OBJS) $(ODP_LIB) $(STD_LIBS) -o $@

$(ODP_SHM): $(ODP_LIB) $(SHM_OBJS)
	$(QUIET_LD)$(CC) $(LDFLAGS) $(SHM_OBJS) $(ODP_LIB) $(STD_LIBS) -o $@

$(ODP_RING): $(ODP_LIB) $(RING_OBJS)
	$(QUIET_LD)$(CC) $(LDFLAGS) $(RING_OBJS) $(ODP_LIB) $(STD_LIBS) -o $@

$(ODP_TIM): $(ODP_LIB) $(TIM_OBJS)
	$(QUIET_LD)$(CC) $(LDFLAGS) $(TIM_OBJS) $(ODP_LIB) $(STD_LIBS) -o $@

.PHONY: clean
clean:
	$(Q)$(RMDIR) $(OBJ_DIR)
	$(Q)$(RM) $(ODP_ATOMIC)
	$(Q)$(RM) $(ODP_SHM)
	$(Q)$(RM) $(ODP_RING)
	$(Q)$(RM) $(ODP_TIM)
	$(MAKE) -C $(ODP_DIR) clean

.PHONY: install
install:
	install -d $(DESTDIR)/share/odp
	install -m 0755 $(ODP_ATOMIC) $(DESTDIR)/share/odp/
	install -m 0755 $(ODP_SHM) $(DESTDIR)/share/odp/
	install -m 0755 $(ODP_RING) $(DESTDIR)/share/odp/
	install -m 0755 $(ODP_TIM) $(DESTDIR)/share/odp/
