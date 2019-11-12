bin_PROGRAMS =	exe1

exe1_SOURCES = 	Main.cpp
				
exe1_CPPFLAGS =	$(AM_CPPFLAGS) $(PROJECTTEMPLATE_CPPFLAGS) $(WX_CPPFLAGS)	\
				-DPROJECTTEMPLATEEXE=1	\
				-I $(top_srcdir)/Config	\
				-I $(top_srcdir)/Lib1	\
				-I $(top_srcdir)/Lib2

exe1_CFLAGS = 	$(AM_CFLAGS) $(PROJECTTEMPLATE_CFLAGS) $(WX_CFLAGS)

exe1_CXXFLAGS = $(AM_CXXFLAGS) $(PROJECTTEMPLATE_CXXFLAGS) $(BOOST_CPPFLAGS) $(WX_CXXFLAGS)

exe1_LDFLAGS = 	$(AM_LDFLAGS) $(PROJECTTEMPLATE_LDFLAGS) $(BOOST_LDFLAGS) $(WX_LDFLAGS)

exe1_LDADD =	$(top_builddir)/Lib1/liblib1.la	\
				$(top_builddir)/Lib2/liblib2.la	\
				$(BOOST_LIBS)	\
				$(SOCKET_LIBS)	\
				$(WX_LIBS)
