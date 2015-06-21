/*
 * The process in the flask.
 *
 * Copyright (c) 2013, Alessandro Ghedini
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <unistd.h>

#include <dbus/dbus.h>

#include "printf.h"
#include "util.h"

void register_machine(pid_t pid, const char *dest) {
	int rc;

	DBusError err;
	DBusConnection *conn;

	DBusMessage *msg;
	DBusMessageIter args;
	DBusPendingCall *pending;

	DBusMessageIter uuid_iter, scope_iter;

	_free_ char *name = NULL;

	char *app = "pflask";
	unsigned char uuid[16];
	char *type = "container";

	dbus_error_init(&err);

	rc = asprintf(&name, "pflask-%d", pid);
	if (rc < 0) fail_printf("OOM");

	conn = dbus_bus_get_private(DBUS_BUS_SYSTEM, &err);
	if (dbus_error_is_set(&err)) {
		err_printf("DBus connection error: %s", err.message);
		return;
	}

	dbus_bus_request_name(conn, "org.freedesktop.machine1", 0, &err);
	if (dbus_error_is_set(&err))
		fail_printf("DBus name error: %s", err.message);


	msg = dbus_message_new_method_call(
		"org.freedesktop.machine1",
		"/org/freedesktop/machine1",
		"org.freedesktop.machine1.Manager",
		"CreateMachine"
	);

	dbus_message_iter_init_append(msg, &args);


	/* name */
	if (!dbus_message_iter_append_basic(&args, DBUS_TYPE_STRING, &name))
		fail_printf("OOM");

	/* id */
	if (!dbus_message_iter_open_container(&args, DBUS_TYPE_ARRAY, "y",
	                                      &uuid_iter))
		fail_printf("OOM");

	if (!dbus_message_iter_append_fixed_array(&uuid_iter, DBUS_TYPE_BYTE,
	                                          uuid, 0))
		fail_printf("OOM");

	if (!dbus_message_iter_close_container(&args, &uuid_iter))
		fail_printf("OOM");

	/* service */
	if (!dbus_message_iter_append_basic(&args, DBUS_TYPE_STRING, &app))
		fail_printf("OOM");

	/* type */
	if (!dbus_message_iter_append_basic(&args, DBUS_TYPE_STRING, &type))
		fail_printf("OOM");

	/* leader */
	if (!dbus_message_iter_append_basic(&args, DBUS_TYPE_UINT32, &pid))
		fail_printf("OOM");

	/* root */
	if (!dbus_message_iter_append_basic(&args, DBUS_TYPE_STRING, &dest))
		fail_printf("OOM");

	/* scope properties */
	if (!dbus_message_iter_open_container(&args, DBUS_TYPE_ARRAY, "(sv)",
	                                      &scope_iter))
		fail_printf("OOM");

	if (!dbus_message_iter_close_container(&args, &scope_iter))
		fail_printf("OOM");

	if (!dbus_connection_send_with_reply(conn, msg, &pending, -1))
		fail_printf("Could not send DBus message");

	dbus_pending_call_block(pending);

	msg = dbus_pending_call_steal_reply(pending);
	if (!msg)
		fail_printf("OOM");

	dbus_pending_call_unref(pending);

	if (dbus_message_get_type(msg) == DBUS_MESSAGE_TYPE_ERROR)
		err_printf("%s", dbus_message_get_error_name(msg));

	dbus_connection_close(conn);
	dbus_error_free(&err);
}
