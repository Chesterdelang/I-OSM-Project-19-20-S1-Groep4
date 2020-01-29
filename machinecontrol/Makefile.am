bin_PROGRAMS =	machinecontrol

machinecontrol_SOURCES =	MachineControl.cpp	\
				Session.hpp	\
				Busy.cpp \
				InitMachine.cpp \
				Idle.cpp \
				Event.cpp \
				IEventHandler.hpp \
				IState.hpp \
				StopMachine.cpp \
				Repair.cpp \
				Main.cpp



machinecontrol_CPPFLAGS =	$(AM_CPPFLAGS) $(PROJECTTEMPLATE_CPPFLAGS) $(WX_CPPFLAGS) \
				-DPROJECTTEMPLATEEXE=1	\
				-I $(top_srcdir)/libraries/lib_machine	\
				-I $(top_srcdir)/Config	

machinecontrol_CFLAGS = 	$(AM_CFLAGS) $(PROJECTTEMPLATE_CFLAGS) $(WX_CFLAGS)

machinecontrol_CXXFLAGS = $(AM_CXXFLAGS) $(PROJECTTEMPLATE_CXXFLAGS) $(BOOST_CPPFLAGS) $(WX_CXXFLAGS)

machinecontrol_LDFLAGS = 	$(AM_LDFLAGS) $(PROJECTTEMPLATE_LDFLAGS) $(BOOST_LDFLAGS) $(WX_LDFLAGS)

machinecontrol_LDADD =		$(top_builddir)/libraries/lib_machine/lib_machine.la \
				$(BOOST_LIBS)	\
				$(SOCKET_LIBS)	\
				$(WX_LIBS)
