bin_PROGRAMS =	productioncontrol

productioncontrol_SOURCES = 	Main.cpp

productioncontrol_CPPFLAGS =	$(AM_CPPFLAGS) $(PROJECTTEMPLATE_CPPFLAGS) $(WX_CPPFLAGS)	\
				-DPROJECTTEMPLATEEXE=1 \
				-I $(top_srcdir)/Config

productioncontrol_CFLAGS = 	$(AM_CFLAGS) $(PROJECTTEMPLATE_CFLAGS) $(WX_CFLAGS)

productioncontrol_CXXFLAGS = $(AM_CXXFLAGS) $(PROJECTTEMPLATE_CXXFLAGS) $(BOOST_CPPFLAGS) $(WX_CXXFLAGS)

productioncontrol_LDFLAGS = 	$(AM_LDFLAGS) $(PROJECTTEMPLATE_LDFLAGS) $(BOOST_LDFLAGS) $(WX_LDFLAGS)

productioncontrol_LDADD =			$(BOOST_LIBS)	\
				$(SOCKET_LIBS)	\
				$(WX_LIBS)
