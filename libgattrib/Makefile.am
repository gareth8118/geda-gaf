SUBDIRS = include src

pkgconfigdir 	= $(libdir)/pkgconfig
pkgconfig_DATA 	= libgattrib.pc

libgattrib-pc-install: libgattrib.pc
	$(mkinstalldirs) $(DESTDIR)$(pkgconfigdir)
	$(INSTALL_DATA) libgattrib.pc $(DESTDIR)$(pkgconfigdir)

MOSTLYCLEANFILES = *.log core FILE *~
CLEANFILES = *.log core FILE *~
DISTCLEANFILES = *.log core FILE *~ libgeda.pc po/domain.mak
MAINTAINERCLEANFILES = *.log core FILE *~ Makefile.in libgeda.pc ChangeLog
