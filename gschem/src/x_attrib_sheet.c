/* gEDA - GPL Electronic Design Automation
 * gschem - gEDA Schematic Capture
 * Copyright (C) 1998-2011 Ales Hvezda
 * Copyright (C) 1998-2011 gEDA Contributors (see ChangeLog for details)
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

/*
 * \file x_attrib_sheet.c
 * \brief gschem-specific GType class and functions to support the
 *        attribute sheet window
 */

#include <config.h>
#include <version.h>

#include "gschem.h"

#ifdef HAVE_LIBDMALLOC
#include <dmalloc.h>
#endif

/*! \brief Open the attribute sheet
 *
 * \par Function Description
 * Open the attribute sheet. This function should actually
 * pull in the libgattrib classes.
 *
 * \param w_current The schematic top level variable
 *
 */
void x_attrib_sheet_open(GSCHEM_TOPLEVEL *w_current)
{
  if (!w_current->aswindow)
    {
      w_current->aswindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
      gtk_window_set_title(GTK_WINDOW(w_current->aswindow), "Attribute Sheet");
      gtk_widget_show(w_current->aswindow);
    }
}
