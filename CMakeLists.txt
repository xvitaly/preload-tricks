#
# SPDX-FileCopyrightText: 2021 EasyCoding Team and contributors
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

# ==============================
# === Project initialization ===
# ==============================

cmake_minimum_required(VERSION 3.12)

project(preload-tricks
    VERSION 0.1.0
    DESCRIPTION "LD_PRELOAD tricks library and a simple example"
    HOMEPAGE_URL "https://github.com/xvitaly/preload-tricks"
    LANGUAGES C
)

# =======================
# === Project options ===
# =======================

option(ENABLE_TESTS "Build and run unit tests" OFF)

# =============================
# === Tricks library target ===
# =============================

set(TRICKS_LIBRARY_NAME "tricks")

set(TRICKS_LIBRARY_SOURCES
    src/tricks.c
)

add_library(${TRICKS_LIBRARY_NAME} SHARED
    ${TRICKS_LIBRARY_SOURCES}
)

set_property(TARGET ${TRICKS_LIBRARY_NAME} PROPERTY VERSION ${CMAKE_PROJECT_VERSION})
set_property(TARGET ${TRICKS_LIBRARY_NAME} PROPERTY SOVERSION 0)

# =================================
# === Root check example target ===
# =================================

set(TRICKS_EXAMPLE_ROOT_NAME "example-root")

set(TRICKS_EXAMPLE_ROOT_SOURCES
    src/example-root.c
)

add_executable(${TRICKS_EXAMPLE_ROOT_NAME}
    ${TRICKS_EXAMPLE_ROOT_SOURCES}
)

# ===============================
# === Root check tests target ===
# ===============================

set(TRICKS_EXAMPLE_ROOT_TEST "${TRICKS_EXAMPLE_ROOT_NAME}-test")

add_test(NAME ${TRICKS_EXAMPLE_ROOT_TEST}
    COMMAND ${TRICKS_EXAMPLE_ROOT_NAME}
)

set_property(TEST ${TRICKS_EXAMPLE_ROOT_TEST}
    APPEND PROPERTY ENVIRONMENT "LD_PRELOAD=${CMAKE_CURRENT_BINARY_DIR}/$<TARGET_FILE_NAME:${TRICKS_LIBRARY_NAME}>"
)

# ====================
# === Tests export ===
# ====================

if (ENABLE_TESTS)
    enable_testing()
endif()
