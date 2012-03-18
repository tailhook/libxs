/*
    Copyright (c) 2012 250bpm s.r.o.
    Copyright (c) 2012 Other contributors as noted in the AUTHORS file

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

#include "../include/xs_filter.h"

#include "core.hpp"
#include "err.hpp"

xs::core_t::core_t ()
{
}

xs::core_t::~core_t ()
{
}

int xs::core_t::filter_subscribed (const unsigned char *data_, size_t size_)
{
    errno = ENOTSUP;
    return -1;
}

int xs::core_t::filter_unsubscribed (const unsigned char *data_, size_t size_)
{
    errno = ENOTSUP;
    return -1;
}

int xs::core_t::filter_matching (void *subscriber_)
{
    errno = ENOTSUP;
    return -1;
}

int xs_filter_subscribed (void *core_,
    const unsigned char *data_, size_t size_)
{
    return ((xs::core_t*) core_)->filter_subscribed (data_, size_);
}

int xs_filter_unsubscribed (void *core_,
    const unsigned char *data_, size_t size_)
{
    return ((xs::core_t*) core_)->filter_unsubscribed (data_, size_);
}

int xs_filter_matching (void *core_, void *subscriber_)
{
    return ((xs::core_t*) core_)->filter_matching (subscriber_);
}

