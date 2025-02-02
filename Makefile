# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: Makefile $
#
# OpenPOWER HCODE Project
#
# COPYRIGHT 2017,2018
# [+] International Business Machines Corp.
#
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
# implied. See the License for the specific language governing
# permissions and limitations under the License.
#
# IBM_PROLOG_END_TAG
export BASEPATH=../..
BUILD_DIR = tools/build
.PHONY: install all clean

install: all

TOOLS = ppetracepp

# ppetrace.exe is a dependancy for several independent
# targets, build it first to eliminate concurrancy
# issues
all: $(TOOLS)
	@$(MAKE) -C $(BUILD_DIR) all --no-print-directory

clean:
	@$(MAKE) -C $(BUILD_DIR) clean  --no-print-directory

%:
	@$(MAKE) -C $(BUILD_DIR) $@  --no-print-directory

