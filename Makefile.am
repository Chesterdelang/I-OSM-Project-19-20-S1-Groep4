
ACLOCAL_AMFLAGS = -I ./m4

noinst_HEADERS		=	Config/ProjectTemplateConfig.h	\
						Config/ProjectTemplateLinuxConfig.h	\
						Config/ProjectTemplateMinGWConfig.h

SUBDIRS =	Lib1	\
			Lib2	\
			Exe1	\
			Exe2	\
			TestExe1	\
			TestExe2

if HAVE_CPPCHECK
cppcheck:
		$(CPPCHECK) --quiet --template="{file};{line};{severity};{id};{message}" --enable=all --inconclusive --force --inline-suppr --std=c11 --std=c++14 -I Config --suppress=missingIncludeSystem ..
endif		