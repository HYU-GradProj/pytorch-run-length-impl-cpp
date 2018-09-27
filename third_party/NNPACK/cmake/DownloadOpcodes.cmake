CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12 FATAL_ERROR)

PROJECT(opcodes-download NONE)

INCLUDE(ExternalProject)
ExternalProject_Add(opcodes
	URL https://pypi.python.org/packages/e8/59/8c2e293c9c8d60f206fd5d0f6c8236a2e0a97832379ac319077441552c6a/opcodes-0.3.13.tar.gz
	URL_HASH SHA256=1859c23143fe20daa4110be87a947cbf3eefa048da71dde642290213f251590c
	SOURCE_DIR "${CONFU_DEPENDENCIES_SOURCE_DIR}/opcodes"
	BINARY_DIR "${CONFU_DEPENDENCIES_BINARY_DIR}/opcodes"
	CONFIGURE_COMMAND ""
	BUILD_COMMAND ""
	INSTALL_COMMAND ""
	TEST_COMMAND ""
)
