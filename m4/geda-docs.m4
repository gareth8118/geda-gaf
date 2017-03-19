# geda-docs.m4                            -*-Autoconf-*-
# serial 1

dnl Optional user documentation support
dnl Copyright (C) 2017 Gareth Edwards <gareth@edwardsfamily.org.uk>
dnl
dnl This program is free software; you can redistribute it and/or modify
dnl it under the terms of the GNU General Public License as published by
dnl the Free Software Foundation; either version 2 of the License, or
dnl (at your option) any later version.
dnl
dnl This program is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl GNU General Public License for more details.
dnl
dnl You should have received a copy of the GNU General Public License
dnl along with this program; if not, write to the Free Software
dnl Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

# Check if the user manual is requested, and if so, find the Sphinx program
AC_DEFUN([AX_OPTION_DOCS],
[
  AC_PREREQ([2.60])dnl

  # Check if the user manual build is requested
  AC_MSG_CHECKING([whether to enable generation of the user manual])
  AC_ARG_ENABLE([docs],
    [AS_HELP_STRING([--enable-docs], [enable generation of the user manual])])

  # If the user enabled the manual build, find the path to the sphinx
  # executables. Also check for pdflatex for the PDF output.
  if test "X$enable_docs" = "Xyes"; then
    AC_MSG_RESULT([yes])
    AC_CHECK_PROG([SPHINX_BUILD], [sphinx-build], [sphinx-build], [no])
    if test "X$SPHINX_BUILD" = "Xno"; then
      AC_MSG_ERROR([User manual generation was requested, but sphinx was not
found. Ensure it is installed and in your path, or configure without
--enable-docs.])
    fi

    # We need pdflatex to create PDF format User Guide
    AC_CHECK_PROG([PDFLATEX], [pdflatex], [pdflatex], [no])
    if test "X$PDFLATEX" = "Xno"; then
      AC_MSG_ERROR([User manual generation was requested, but pdflatex was not
found.  Ensure it is installed and in your path, or configure without
--enable-docs.])
    fi

  else
    AC_MSG_RESULT([no])
  fi

  AM_CONDITIONAL([ENABLE_DOCS],
                 test "X$enable_docs" = "Xyes")
  AC_SUBST([SPHINX_BUILD])
])dnl AX_OPTION_DOCS
