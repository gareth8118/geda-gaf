/* gEDA - GPL Electronic Design Automation
 * gnetlist - gEDA Netlist
 * Copyright (C) 1998-2010 Ales Hvezda
 * Copyright (C) 1998-2010 gEDA Contributors (see ChangeLog for details)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <config.h>

#include <stdio.h>

#include <liblepton/liblepton.h>

#include "../include/globals.h"
#include "../include/prototype.h"

char *rc_filename = NULL;

int logfile_fd=-1;
int logging_dest=LOG_WINDOW;

/* netlist specific variables */
NETLIST *netlist_head=NULL;

char *guile_proc=NULL;


/* command line arguments */
int list_backends=FALSE;
int verbose_mode=FALSE;
int interactive_mode=FALSE;
int quiet_mode=FALSE;

char *output_filename=NULL;

/* scheme expression to evaluate before loading of rc files */
SCM pre_rc_list = SCM_EOL;

/* scheme expression to evaluate before loading of the backend */
SCM pre_backend_list = SCM_EOL;

/* scheme expression to evaluate after loading of the backend but
 * before the execution of the backend procedure */
SCM post_backend_list = SCM_EOL;

/* Parameters passed to the backend from the command line */
GSList *backend_params = NULL;

/* Config settings */
gboolean refdes_order = APPEND;
gchar *refdes_separator = NULL;
gboolean netname_order = APPEND;
gboolean mangle_netname = TRUE;
gchar *netname_separator = NULL;
gboolean net_order = APPEND;
gboolean mangle_net = TRUE;
gchar *net_separator = NULL;
gint net_naming_priority = NETATTRIB_ATTRIBUTE;
gboolean is_hierarchy = TRUE;
gchar *default_net_name = NULL;
gchar *default_bus_name = NULL;

