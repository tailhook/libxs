/*
    Copyright (c) 2009-2012 250bpm s.r.o.
    Copyright (c) 2007-2009 iMatix Corporation
    Copyright (c) 2011 VMware, Inc.
    Copyright (c) 2007-2011 Other contributors as noted in the AUTHORS file

    This file is part of Crossroads I/O project.

    Crossroads I/O is free software; you can redistribute it and/or modify it
    under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    Crossroads is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __XS_OPTIONS_HPP_INCLUDED__
#define __XS_OPTIONS_HPP_INCLUDED__

#include "stddef.h"
#include "stdint.hpp"

namespace xs
{

    struct options_t
    {
        options_t ();

        int setsockopt (int option_, const void *optval_, size_t optvallen_);
        int getsockopt (int option_, void *optval_, size_t *optvallen_);

        //  High-water marks for message pipes.
        int sndhwm;
        int rcvhwm;

        //  I/O thread affinity.
        uint64_t affinity;

        //  Socket identity
        unsigned char identity_size;
        unsigned char identity [256];

        //  Maximum tranfer rate [kb/s]. Default 100kb/s.
        int rate;

        //  Reliability time interval [ms]. Default 10 seconds.
        int recovery_ivl;

        // Sets the time-to-live field in every multicast packet sent.
        int multicast_hops;

        // SO_SNDBUF and SO_RCVBUF to be passed to underlying transport sockets.
        int sndbuf;
        int rcvbuf;

        //  Socket type.
        int type;

        //  Linger time, in milliseconds.
        int linger;

        //  Minimum interval between attempts to reconnect, in milliseconds.
        //  Default 100ms
        int reconnect_ivl;

        //  Maximum interval between attempts to reconnect, in milliseconds.
        //  Default 0 (unused)
        int reconnect_ivl_max;

        //  Maximum backlog for pending connections.
        int backlog;

        //  Maximal size of message to handle.
        uint64_t maxmsgsize;

        // The timeout for send/recv operations for this socket.
        int rcvtimeo;
        int sndtimeo;

        //  If 1, indicates the use of IPv4 sockets only, it will not be
        //  possible to communicate with IPv6-only hosts. If 0, the socket can
        //  connect to and accept connections from both IPv4 and IPv6 hosts.
        int ipv4only;

        //  Filter ID to be used with subscriptions and unsubscriptions.
        int filter_id;

        //  If true, session reads all the pending messages from the pipe and
        //  sends them to the network when socket is closed.
        bool delay_on_close;

        //  If true, socket reads all the messages from the pipe and delivers
        //  them to the user when the peer terminates.
        bool delay_on_disconnect;

        //  If 1, (X)SUB socket should filter the messages. If 0, it should not.
        bool filter;

        //  Sends identity to all new connections.
        bool send_identity;

        //  Receivers identity from all new connections.
        bool recv_identity;

        //  ID of the socket.
        int socket_id;
    };

}

#endif
