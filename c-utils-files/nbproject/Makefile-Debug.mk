#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/genericArrayList.o \
	${OBJECTDIR}/genericLinkedList.o \
	${OBJECTDIR}/genericMap.o \
	${OBJECTDIR}/genericStack.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f3

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/cunit_generic-array-list.o \
	${TESTDIR}/tests/cunit_generic-linked-list.o \
	${TESTDIR}/tests/cunit_generic-map.o \
	${TESTDIR}/tests/cunit_generic-stack.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libc-utils-files.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libc-utils-files.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libc-utils-files.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libc-utils-files.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libc-utils-files.a

${OBJECTDIR}/genericArrayList.o: genericArrayList.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/genericArrayList.o genericArrayList.c

${OBJECTDIR}/genericLinkedList.o: genericLinkedList.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/genericLinkedList.o genericLinkedList.c

${OBJECTDIR}/genericMap.o: genericMap.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/genericMap.o genericMap.c

${OBJECTDIR}/genericStack.o: genericStack.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/genericStack.o genericStack.c

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/cunit_generic-map.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c} -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS}   -lcunit 

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/cunit_generic-stack.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   -lcunit 

${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/cunit_generic-array-list.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c} -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS}   -lcunit 

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/cunit_generic-linked-list.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c} -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS}   -lcunit 


${TESTDIR}/tests/cunit_generic-map.o: tests/cunit_generic-map.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/cunit_generic-map.o tests/cunit_generic-map.c


${TESTDIR}/tests/cunit_generic-stack.o: tests/cunit_generic-stack.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/cunit_generic-stack.o tests/cunit_generic-stack.c


${TESTDIR}/tests/cunit_generic-array-list.o: tests/cunit_generic-array-list.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/cunit_generic-array-list.o tests/cunit_generic-array-list.c


${TESTDIR}/tests/cunit_generic-linked-list.o: tests/cunit_generic-linked-list.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/cunit_generic-linked-list.o tests/cunit_generic-linked-list.c


${OBJECTDIR}/genericArrayList_nomain.o: ${OBJECTDIR}/genericArrayList.o genericArrayList.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/genericArrayList.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/genericArrayList_nomain.o genericArrayList.c;\
	else  \
	    ${CP} ${OBJECTDIR}/genericArrayList.o ${OBJECTDIR}/genericArrayList_nomain.o;\
	fi

${OBJECTDIR}/genericLinkedList_nomain.o: ${OBJECTDIR}/genericLinkedList.o genericLinkedList.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/genericLinkedList.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/genericLinkedList_nomain.o genericLinkedList.c;\
	else  \
	    ${CP} ${OBJECTDIR}/genericLinkedList.o ${OBJECTDIR}/genericLinkedList_nomain.o;\
	fi

${OBJECTDIR}/genericMap_nomain.o: ${OBJECTDIR}/genericMap.o genericMap.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/genericMap.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/genericMap_nomain.o genericMap.c;\
	else  \
	    ${CP} ${OBJECTDIR}/genericMap.o ${OBJECTDIR}/genericMap_nomain.o;\
	fi

${OBJECTDIR}/genericStack_nomain.o: ${OBJECTDIR}/genericStack.o genericStack.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/genericStack.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/genericStack_nomain.o genericStack.c;\
	else  \
	    ${CP} ${OBJECTDIR}/genericStack.o ${OBJECTDIR}/genericStack_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
	    ${TESTDIR}/TestFiles/f3 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
