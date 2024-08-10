SUMMARY = "DemoApp Recipe"
DESCRIPTION = "A recipe for DemoApp from GitHub."
LICENSE = "CLOSED"

inherit logging

DEPENDS = "cmake"

inherit cmake

SRC_URI = "git://github.com/FadyKhalil/DemoApp.git;protocol=https;branch=main"

SRCREV = "720c663c5fd7246b4b42c5205d74db7d9784b5b2"

WORKDIR = "/home/karimzidantech/yocto/poky/build/tmp/work/core2-64-poky-linux/task/1.0-r0"

S = "${WORKDIR}/git"

B = "${WORKDIR}/git/build"

D ="${WORKDIR}/images"

do_configure() {
        cmake -S ${S} -B ${B}

}
do_compile(){

cmake --build ${B}

}
do_install() {

    install -d ${D}/usr/bin
    install -m 0755 ${B}/calculator ${D}/usr/bin/

}

