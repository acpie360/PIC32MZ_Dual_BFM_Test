#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PIC32MZ_Dual_BFM_Test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PIC32MZ_Dual_BFM_Test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../configs_words.c ../core_timer.c ../flash_operation.c ../main.c ../sys_devcon_cache_pic32mz.S ../sys_devcon_pic32mz.c ../debug_port.c ../ports.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/configs_words.o ${OBJECTDIR}/_ext/1472/core_timer.o ${OBJECTDIR}/_ext/1472/flash_operation.o ${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/1472/sys_devcon_cache_pic32mz.o ${OBJECTDIR}/_ext/1472/sys_devcon_pic32mz.o ${OBJECTDIR}/_ext/1472/debug_port.o ${OBJECTDIR}/_ext/1472/ports.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/configs_words.o.d ${OBJECTDIR}/_ext/1472/core_timer.o.d ${OBJECTDIR}/_ext/1472/flash_operation.o.d ${OBJECTDIR}/_ext/1472/main.o.d ${OBJECTDIR}/_ext/1472/sys_devcon_cache_pic32mz.o.d ${OBJECTDIR}/_ext/1472/sys_devcon_pic32mz.o.d ${OBJECTDIR}/_ext/1472/debug_port.o.d ${OBJECTDIR}/_ext/1472/ports.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/configs_words.o ${OBJECTDIR}/_ext/1472/core_timer.o ${OBJECTDIR}/_ext/1472/flash_operation.o ${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/1472/sys_devcon_cache_pic32mz.o ${OBJECTDIR}/_ext/1472/sys_devcon_pic32mz.o ${OBJECTDIR}/_ext/1472/debug_port.o ${OBJECTDIR}/_ext/1472/ports.o

# Source Files
SOURCEFILES=../configs_words.c ../core_timer.c ../flash_operation.c ../main.c ../sys_devcon_cache_pic32mz.S ../sys_devcon_pic32mz.c ../debug_port.c ../ports.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/PIC32MZ_Dual_BFM_Test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MZ2048EFG100
MP_LINKER_FILE_OPTION=,--script="..\p32MZ2048EFG100.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/sys_devcon_cache_pic32mz.o: ../sys_devcon_cache_pic32mz.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/sys_devcon_cache_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/sys_devcon_cache_pic32mz.o 
	@${RM} ${OBJECTDIR}/_ext/1472/sys_devcon_cache_pic32mz.o.ok ${OBJECTDIR}/_ext/1472/sys_devcon_cache_pic32mz.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/sys_devcon_cache_pic32mz.o.d" "${OBJECTDIR}/_ext/1472/sys_devcon_cache_pic32mz.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -DICD4Tool=1 -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/sys_devcon_cache_pic32mz.o.d"  -o ${OBJECTDIR}/_ext/1472/sys_devcon_cache_pic32mz.o ../sys_devcon_cache_pic32mz.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/1472/sys_devcon_cache_pic32mz.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=ICD4Tool=1
	
else
${OBJECTDIR}/_ext/1472/sys_devcon_cache_pic32mz.o: ../sys_devcon_cache_pic32mz.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/sys_devcon_cache_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/sys_devcon_cache_pic32mz.o 
	@${RM} ${OBJECTDIR}/_ext/1472/sys_devcon_cache_pic32mz.o.ok ${OBJECTDIR}/_ext/1472/sys_devcon_cache_pic32mz.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/sys_devcon_cache_pic32mz.o.d" "${OBJECTDIR}/_ext/1472/sys_devcon_cache_pic32mz.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/sys_devcon_cache_pic32mz.o.d"  -o ${OBJECTDIR}/_ext/1472/sys_devcon_cache_pic32mz.o ../sys_devcon_cache_pic32mz.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/1472/sys_devcon_cache_pic32mz.o.asm.d",--gdwarf-2
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/configs_words.o: ../configs_words.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/configs_words.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/configs_words.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/configs_words.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DICD4Tool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/configs_words.o.d" -o ${OBJECTDIR}/_ext/1472/configs_words.o ../configs_words.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-format
	
${OBJECTDIR}/_ext/1472/core_timer.o: ../core_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/core_timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/core_timer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/core_timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DICD4Tool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/core_timer.o.d" -o ${OBJECTDIR}/_ext/1472/core_timer.o ../core_timer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-format
	
${OBJECTDIR}/_ext/1472/flash_operation.o: ../flash_operation.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/flash_operation.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/flash_operation.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/flash_operation.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DICD4Tool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/flash_operation.o.d" -o ${OBJECTDIR}/_ext/1472/flash_operation.o ../flash_operation.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-format
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DICD4Tool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/main.o.d" -o ${OBJECTDIR}/_ext/1472/main.o ../main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-format
	
${OBJECTDIR}/_ext/1472/sys_devcon_pic32mz.o: ../sys_devcon_pic32mz.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/sys_devcon_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/sys_devcon_pic32mz.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/sys_devcon_pic32mz.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DICD4Tool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/sys_devcon_pic32mz.o.d" -o ${OBJECTDIR}/_ext/1472/sys_devcon_pic32mz.o ../sys_devcon_pic32mz.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-format
	
${OBJECTDIR}/_ext/1472/debug_port.o: ../debug_port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/debug_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/debug_port.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/debug_port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DICD4Tool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/debug_port.o.d" -o ${OBJECTDIR}/_ext/1472/debug_port.o ../debug_port.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-format
	
${OBJECTDIR}/_ext/1472/ports.o: ../ports.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ports.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ports.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ports.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DICD4Tool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/ports.o.d" -o ${OBJECTDIR}/_ext/1472/ports.o ../ports.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-format
	
else
${OBJECTDIR}/_ext/1472/configs_words.o: ../configs_words.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/configs_words.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/configs_words.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/configs_words.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/configs_words.o.d" -o ${OBJECTDIR}/_ext/1472/configs_words.o ../configs_words.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-format
	
${OBJECTDIR}/_ext/1472/core_timer.o: ../core_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/core_timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/core_timer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/core_timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/core_timer.o.d" -o ${OBJECTDIR}/_ext/1472/core_timer.o ../core_timer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-format
	
${OBJECTDIR}/_ext/1472/flash_operation.o: ../flash_operation.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/flash_operation.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/flash_operation.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/flash_operation.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/flash_operation.o.d" -o ${OBJECTDIR}/_ext/1472/flash_operation.o ../flash_operation.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-format
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/main.o.d" -o ${OBJECTDIR}/_ext/1472/main.o ../main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-format
	
${OBJECTDIR}/_ext/1472/sys_devcon_pic32mz.o: ../sys_devcon_pic32mz.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/sys_devcon_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/sys_devcon_pic32mz.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/sys_devcon_pic32mz.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/sys_devcon_pic32mz.o.d" -o ${OBJECTDIR}/_ext/1472/sys_devcon_pic32mz.o ../sys_devcon_pic32mz.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-format
	
${OBJECTDIR}/_ext/1472/debug_port.o: ../debug_port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/debug_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/debug_port.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/debug_port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/debug_port.o.d" -o ${OBJECTDIR}/_ext/1472/debug_port.o ../debug_port.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-format
	
${OBJECTDIR}/_ext/1472/ports.o: ../ports.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ports.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ports.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ports.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/ports.o.d" -o ${OBJECTDIR}/_ext/1472/ports.o ../ports.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-format
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/PIC32MZ_Dual_BFM_Test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../p32MZ2048EFG100.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -DICD4Tool=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/PIC32MZ_Dual_BFM_Test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x37F   -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=ICD4Tool=1,--defsym=_min_heap_size=8192,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/PIC32MZ_Dual_BFM_Test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../p32MZ2048EFG100.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/PIC32MZ_Dual_BFM_Test.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=8192,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/PIC32MZ_Dual_BFM_Test.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
