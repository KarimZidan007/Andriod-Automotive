SUMMARY = "JAVAFX22- Recipe"
DESCRIPTION = "A recipe for JAVAFX22 from GitHub."
LICENSE = "CLOSED"

SRC_URI = "git://github.com/KarimZidan007/JAVAFX.git;protocol=https;branch=main"

SRCREV = "ce8b71579c612e5c1909ad6fb3ef3eebbc224fc0"

RDEPENDS:${PN} += "glibc libgcc glibc-utils glibc-thread-db glibc-gconv "

DEPENDS+="ffmpeg libcamera gtk+3 pango mesa freetype  xserver-xorg"

do_install () {
    install -d ${D}/usr/lib/JAVAFX
    install -m 0755 ${WORKDIR}/git/JFX22/lib/* ${D}/usr/lib/JAVAFX
}
PN = "JAVAFX"
INSANE_SKIP:${PN} += "already-stripped" 
INSANE_SKIP:${PN} += "file-rdeps ldflags dev-so build-deps"

FILES:${PN} += "/usr/lib"

do_package_qa[noexec] = "1"

